package com.fine.sdk.crash.android;

import android.content.Context;
import android.os.Handler;
import android.os.Message;
import android.text.TextUtils;
import android.util.Log;

import com.fine.sdk.crash.android.config.FineCrashConfig;
import com.fine.sdk.crash.android.utils.FineCrashTimeExecutor;
import com.fine.sdk.crash.android.http.FineCrashHttpRequest;
import com.fine.sdk.crash.android.http.impl.FineCrashHttpCallBack;
import com.fine.sdk.crash.android.utils.FineCrashExceptionHandler;
import com.fine.sdk.crash.android.utils.FineCrashSharedPreferences;
import com.fine.sdk.crash.android.utils.FineCrashUtils;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.File;
import java.lang.ref.WeakReference;
import java.util.HashMap;
import java.util.Map;

/**
 * FineCrashSDK
 *
 * @author Cylee
 */
public class FineCrashSDK {

    static {
        System.loadLibrary("fine_breakpad");
    }

    private static native void initNative(String path);

    public static native void crash();

    private static FineCrashSDK instance;

    public static FineCrashSDK getInstance() {
        if (instance == null) {
            synchronized (FineCrashSDK.class) {
                if (instance == null) {
                    instance = new FineCrashSDK();
                }
            }
        }
        return instance;
    }

    private String tag = "FineCrashSDK";
    private Context mContext;
    private String mCrashDir;
    private FineCrashTimeExecutor mFineCrashTimeExecutor;
    private FineCrashSDKHandler mFineCrashSDKHandler;

    public void init(Context context) {
        Log.d(tag, "Init");
        this.mContext = context;
        mCrashDir = FineCrashUtils.getCrashDir(mContext, "finecrash");
        mFineCrashTimeExecutor = new FineCrashTimeExecutor();
        mFineCrashTimeExecutor.init(mContext, mCrashDir);

        // 初始化Breakpad
        initNative(mCrashDir);
        // 初始化Java异常收集器
        Thread.UncaughtExceptionHandler handler = Thread.getDefaultUncaughtExceptionHandler();
        Thread.setDefaultUncaughtExceptionHandler(new FineCrashExceptionHandler(mContext, handler));

        mFineCrashSDKHandler = new FineCrashSDKHandler(this);
        loopDmpFiles();
    }

    public void onStart() {
        if (mFineCrashTimeExecutor != null) {
            mFineCrashTimeExecutor.onStart();
        }
    }

    public void onStop() {
        if (mFineCrashTimeExecutor != null) {
            mFineCrashTimeExecutor.onStop();
        }
    }

    /**
     * 上报服务器
     *
     * @param obj
     */
    public void report(final JSONObject obj) {
        JSONObject request = new JSONObject();
        try {
            String env = obj.optString("env");
            // 不同平台参数
            if (env.equalsIgnoreCase(FineCrashConfig.ENV_TYPE_CPP)) {
                String dumpfile = obj.optString("dumpFile");
                String dumpData = obj.optString("dumpData");
                String crashTime = obj.optString("crashTime");
                int useTime = FineCrashSharedPreferences.readInt(mContext, FineCrashSharedPreferences.KEY_UES_TIME + "_" + dumpfile);
                String lastAppMemory = FineCrashSharedPreferences.readString(mContext, FineCrashSharedPreferences.KEY_APP_RAM + "_" + dumpfile);

                request.putOpt(FineCrashConfig.CRASH_PARAMS_TIME, crashTime);
                request.putOpt(FineCrashConfig.CRASH_PARAMS_USE_TIME, useTime);
                request.putOpt(FineCrashConfig.CRASH_PARAMS_IS_DECODE, true);
                request.putOpt(FineCrashConfig.CRASH_PARAMS_MSG, dumpData);
                request.putOpt(FineCrashConfig.CRASH_PARAMS_THREAD, "");
            } else if (env.equalsIgnoreCase(FineCrashConfig.ENV_TYPE_JAVA) || env.equalsIgnoreCase(FineCrashConfig.ENV_TYPE_C_SHARP)) {
                String exceptionName = obj.optString("exceptionName");
                String exceptionDetail = obj.optString("exceptionDetail");
                String crashTime = "" + (System.currentTimeMillis() / 1000);
                int useTime = FineCrashSharedPreferences.readInt(mContext, FineCrashSharedPreferences.KEY_UES_TIME);
                String appMemory = "" + FineCrashUtils.getAppRam();

                request.putOpt(FineCrashConfig.CRASH_PARAMS_TIME, crashTime);
                request.putOpt(FineCrashConfig.CRASH_PARAMS_USE_TIME, useTime);
                request.putOpt(FineCrashConfig.CRASH_PARAMS_IS_DECODE, false);
                request.putOpt(FineCrashConfig.CRASH_PARAMS_MSG, exceptionName);
                request.putOpt(FineCrashConfig.CRASH_PARAMS_THREAD, exceptionDetail);
            }
            // 设置Request信息
            request.putOpt(FineCrashConfig.CRASH_PARAMS_REPORT_TIME, "" + (System.currentTimeMillis() / 1000));
            request.putOpt(FineCrashConfig.CRASH_PARAMS_APP, getAppJsonString());
            request.putOpt(FineCrashConfig.CRASH_PARAMS_DEVICE, getDeviceJsonString());
            request.putOpt(FineCrashConfig.CRASH_PARAMS_EXT, getExtJsonString());

            FineCrashHttpRequest.getInstance().report(FineCrashConfig.CRASH_REPORT_URL, request.toString(), new FineCrashHttpCallBack() {
                @Override
                public void onSuccess(String jsonString) {
                    Log.d(tag, "Report Success:" + jsonString);
                    try {
                        JSONObject result = new JSONObject(jsonString);
                        int code = result.optInt("code");
                        if (code == 0) {
                            Message message = new Message();
                            message.what = FineCrashSDKHandler.HANDLER_WHAT_LOOP;
                            message.obj = obj.optString("dumpFile");
                            mFineCrashSDKHandler.sendMessage(message);
                        }
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                }

                @Override
                public void onFailure() {
                    Log.d(tag, "Report Failed");
                }
            });
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }

    /**
     * 遍历dmp文件
     */
    private void loopDmpFiles() {
        File[] files = new File(mCrashDir).listFiles();
        for (File f : files) {
            if (!f.isDirectory()) {
                if (f.getName().endsWith(".dmp")) {
                    long crashTime = f.lastModified();
                    String dumpName = f.getName();
                    String dumpData = FineCrashUtils.readFileWithBase64(f.getAbsolutePath());
                    JSONObject json = new JSONObject();
                    try {
                        json.putOpt("env", FineCrashConfig.ENV_TYPE_CPP);
                        json.putOpt("dumpFile", dumpName);
                        json.putOpt("dumpData", dumpData);
                        json.putOpt("crashTime", crashTime / 1000);
                        report(json);
                        return;
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                }
            }
        }
    }

    /**
     * Handler静态内部类
     */
    private static class FineCrashSDKHandler extends Handler {

        private WeakReference<FineCrashSDK> mWeakReference;
        public static final int HANDLER_WHAT_LOOP = 1000;

        public FineCrashSDKHandler(FineCrashSDK sdk) {
            mWeakReference = new WeakReference<>(sdk);
        }

        @Override
        public void handleMessage(Message msg) {
            super.handleMessage(msg);
            FineCrashSDK sdk = mWeakReference.get();
            switch (msg.what) {
                case HANDLER_WHAT_LOOP:
                    String dumpFile = (String) msg.obj;
                    if (!TextUtils.isEmpty(dumpFile)) {
                        File f = new File(sdk.mCrashDir + "/" + dumpFile);
                        if (f.exists()) {
                            f.delete();
                        }
                        FineCrashSharedPreferences.delete(sdk.mContext, FineCrashSharedPreferences.KEY_UES_TIME + "_" + dumpFile);
                        FineCrashSharedPreferences.delete(sdk.mContext, FineCrashSharedPreferences.KEY_APP_RAM + "_" + dumpFile);
                    }
                    sdk.loopDmpFiles();
                    break;
                default:
                    break;
            }
        }

    }

    /**
     * 接收C#异常信息
     *
     * @param logString
     * @param stackTrace
     */
    public void callBackExceptionFromUnity(String logString, String stackTrace) {
        Log.d(tag, "C#异常:" + logString);
        Log.d(tag, "C#堆栈:" + stackTrace);
        JSONObject json = new JSONObject();
        try {
            json.putOpt("env", FineCrashConfig.ENV_TYPE_C_SHARP);
            json.putOpt("exceptionName", logString);
            json.putOpt("exceptionDetail", stackTrace);
            FineCrashSDK.getInstance().report(json);
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }

    /**
     * 获取App信息
     *
     * @return
     */
    private String getAppJsonString() {
        JSONObject json = new JSONObject();
        try {
            json.putOpt(FineCrashConfig.CRASH_PARAMS_APP_SDKVER, FineCrashConfig.VERSION);
            json.putOpt(FineCrashConfig.CRASH_PARAMS_APP_ID, "");
            json.putOpt(FineCrashConfig.CRASH_PARAMS_APP_BUNDLE, FineCrashUtils.getPackageName(mContext));
            json.putOpt(FineCrashConfig.CRASH_PARAMS_APP_NAME, FineCrashUtils.getAppName(mContext));
            json.putOpt(FineCrashConfig.CRASH_PARAMS_APP_VER, FineCrashUtils.getVersionName(mContext));
            json.putOpt(FineCrashConfig.CRASH_PARAMS_APP_RUN_FLAG, FineCrashUtils.getAppOnForeground(mContext));
            json.putOpt(FineCrashConfig.CRASH_PARAMS_APP_SCREEN_TYPE, FineCrashUtils.getOrientation(mContext));
        } catch (JSONException e) {
            e.printStackTrace();
        }
        return json.toString();
    }

    /**
     * 获取设备信息
     *
     * @return
     */
    private String getDeviceJsonString() {
        JSONObject json = new JSONObject();
        try {
            json.putOpt(FineCrashConfig.CRASH_PARAMS_DEVICE_MODEL, FineCrashUtils.getDeviceModel());
            json.putOpt(FineCrashConfig.CRASH_PARAMS_DEVICE_MAKE, FineCrashUtils.getDeviceManufacturer());
            json.putOpt(FineCrashConfig.CRASH_PARAMS_DEVICE_CPU_TYPE, FineCrashUtils.getCpuAbi());
            json.putOpt(FineCrashConfig.CRASH_PARAMS_DEVICE_AVAILABLE_RAM, FineCrashUtils.getAvailableRam(mContext));
            json.putOpt(FineCrashConfig.CRASH_PARAMS_DEVICE_AVAILABLE_DISK, FineCrashUtils.getAvailableRom(mContext));
            json.putOpt(FineCrashConfig.CRASH_PARAMS_DEVICE_NW, FineCrashUtils.getNetwork(mContext));
            json.putOpt(FineCrashConfig.CRASH_PARAMS_DEVICE_CARRIER, FineCrashUtils.getCarrierName(mContext));
            json.putOpt(FineCrashConfig.CRASH_PARAMS_DEVICE_OS, "0");
            json.putOpt(FineCrashConfig.CRASH_PARAMS_DEVICE_OSV, FineCrashUtils.getSystemVersion());
            json.putOpt(FineCrashConfig.CRASH_PARAMS_DEVICE_LNG, FineCrashUtils.getLanguage());
            json.putOpt(FineCrashConfig.CRASH_PARAMS_DEVICE_TYPE, "");
            json.putOpt(FineCrashConfig.CRASH_PARAMS_DEVICE_GAID, "");
        } catch (JSONException e) {
            e.printStackTrace();
        }
        return json.toString();
    }

    /**
     * 获取额外信息
     *
     * @return
     */
    private String getExtJsonString() {
        Map<String, String> extCustom = new HashMap<>(8);
        JSONObject json = new JSONObject();
        try {
            json.putOpt(FineCrashConfig.CRASH_PARAMS_EXT_CUSTOM, extCustom.toString());
        } catch (JSONException e) {
            e.printStackTrace();
        }
        return json.toString();
    }

}
