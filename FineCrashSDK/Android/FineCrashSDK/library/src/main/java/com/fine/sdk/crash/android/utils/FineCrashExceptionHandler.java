package com.fine.sdk.crash.android.utils;

import android.content.Context;
import android.util.Log;

import com.fine.sdk.crash.android.FineCrashSDK;
import com.fine.sdk.crash.android.config.FineCrashConfig;

import org.json.JSONException;
import org.json.JSONObject;

/**
 * Java异常收集器
 *
 * @author Cylee
 */
public class FineCrashExceptionHandler implements Thread.UncaughtExceptionHandler {

    private Context mContext;
    Thread.UncaughtExceptionHandler mOldHandler;
    private String tag = "FineCrashExceptionHandler";

    public FineCrashExceptionHandler(Context context, Thread.UncaughtExceptionHandler handler) {
        this.mContext = context;
        this.mOldHandler = handler;
    }

    @Override
    public void uncaughtException(Thread thread, Throwable ex) {
        if (ex != null) {
            try {
                handleException(ex);
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                Log.e(tag, e.getMessage());
            }
        }
        // 如果存在多个UncaughtExceptionHandler，则交给其他SDK处理，没有则退出。
        if (mOldHandler != null) {
            mOldHandler.uncaughtException(thread, ex);
        } else {
            android.os.Process.killProcess(android.os.Process.myPid());
            System.exit(1);
        }
    }

    private void handleException(final Throwable ex) {
        StringBuffer exceptionStr = new StringBuffer();
        Throwable tempEx = ex;
        for (int j = 0; j < 10; j++) {
            exceptionStr.append(tempEx.getClass().getName() + " " + (tempEx.getLocalizedMessage() != null ? tempEx.getLocalizedMessage() : "") + "\n");
            StackTraceElement[] elements = tempEx.getStackTrace();

            for (int i = 0; i < elements.length; i++) {
                exceptionStr.append("\t at " + elements[i].toString() + "\n");
            }

            tempEx = tempEx.getCause();
            if (tempEx == null) {
                break;
            }
        }

        // 上报服务器
        String exceptionName = ex.getClass().getName() + " " + ex.getLocalizedMessage();
        JSONObject json = new JSONObject();
        try {
            json.putOpt("env", FineCrashConfig.ENV_TYPE_JAVA);
            json.putOpt("exceptionName", exceptionName);
            json.putOpt("exceptionDetail", exceptionStr.toString());
            FineCrashSDK.getInstance().report(json);
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }

}