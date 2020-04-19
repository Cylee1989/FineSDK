package com.fine.sdk.crash.android.http;

import android.os.Handler;
import android.os.HandlerThread;

import com.fine.sdk.crash.android.http.impl.FineCrashHttpCallBack;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;

/**
 * 日志上报
 *
 * @author Cylee
 */
public class FineCrashHttpRequest implements Runnable {

    private static FineCrashHttpRequest instance;

    public static FineCrashHttpRequest getInstance() {
        if (instance == null) {
            synchronized (FineCrashHttpRequest.class) {
                if (instance == null) {
                    instance = new FineCrashHttpRequest();
                    instance.init();
                }
            }
        }
        return instance;
    }

    private HandlerThread mSendThread = null;
    private Handler mSendThreadHandler = null;
    private String mReportUrl;
    private String mReportData;
    private FineCrashHttpCallBack mReportCallBack;

    private void init() {
        mSendThread = new HandlerThread("FineCrashSDK-Thread");
        mSendThread.start();
        mSendThreadHandler = new Handler(mSendThread.getLooper());
    }

    @Override
    public void run() {
        reportData(mReportUrl, mReportData, mReportCallBack);
    }

    public void report(String reportUrl, String reportData, FineCrashHttpCallBack callBack) {
        this.mReportUrl = reportUrl;
        this.mReportData = reportData;
        this.mReportCallBack = callBack;
        mSendThreadHandler.post(this);
    }

    /**
     * 上报日志
     *
     * @param reportUrl
     * @param reportData
     * @param callBack
     */
    private void reportData(String reportUrl, String reportData, FineCrashHttpCallBack callBack) {
        HttpURLConnection conn = null;
        try {
            // 新建一个URL对象
            URL url = new URL(reportUrl);
            // 打开一个HttpURLConnection连接
            conn = (HttpURLConnection) url.openConnection();
            // 设置连接超时时间
            conn.setConnectTimeout(5 * 1000);
            //设置从主机读取数据超时
            conn.setReadTimeout(5 * 1000);
            // Post请求必须设置允许输出 默认false
            conn.setDoOutput(true);
            //设置请求允许输入 默认是true
            conn.setDoInput(true);
            // Post请求不能使用缓存
            conn.setUseCaches(false);
            //设置本次连接是否自动处理重定向
            conn.setInstanceFollowRedirects(true);
            // 设置为Post请求
            conn.setRequestMethod("POST");
            // 配置请求Content-Type
            conn.setRequestProperty("Content-Type", "application/json");
            // 开始连接
            conn.connect();
            // 发送请求参数
            DataOutputStream dos = new DataOutputStream(conn.getOutputStream());
            dos.write(reportData.getBytes());
            dos.flush();
            dos.close();
            // 判断请求是否成功
            if (conn.getResponseCode() == HttpURLConnection.HTTP_OK) {
                String result = streamToString(conn.getInputStream());
                callBack.onSuccess(result);
            } else {
                callBack.onFailure();
            }
        } catch (IOException e) {
            callBack.onFailure();
        } finally {
            if (conn != null) {
                conn.disconnect();
            }
        }
    }

    /**
     * 将输入流转换成字符串
     *
     * @param is 从网络获取的输入流
     * @return
     */
    private String streamToString(InputStream is) {
        String result = "";
        try {
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            byte[] buffer = new byte[1024];
            int len = 0;
            while ((len = is.read(buffer)) != -1) {
                baos.write(buffer, 0, len);
            }
            baos.close();
            is.close();
            byte[] byteArray = baos.toByteArray();
            result = new String(byteArray);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return result;
    }


}
