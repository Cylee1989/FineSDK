package com.fine.sdk.crash.android.utils;

import android.content.Context;
import android.text.TextUtils;

import java.io.File;
import java.util.concurrent.ScheduledThreadPoolExecutor;
import java.util.concurrent.ThreadFactory;
import java.util.concurrent.TimeUnit;

/**
 * 系统信息计时器
 *
 * @author Cylee
 */
public class FineCrashTimeExecutor implements Runnable {

    private Context mContext;
    private final int mPeriod = 60;
    private int useTime = 0;
    private boolean isAppOnForeground;

    public void init(Context context, String crashDir) {
        this.mContext = context;
        setLastCrashInfo(crashDir);
        ScheduledThreadPoolExecutor scheduled = new ScheduledThreadPoolExecutor(1, new ThreadFactory() {
            @Override
            public Thread newThread(Runnable r) {
                return new Thread(r);
            }
        });
        scheduled.scheduleAtFixedRate(this, 0, mPeriod, TimeUnit.SECONDS);
    }

    /**
     * 设置上次崩溃系统信息
     *
     * @param crashDir
     */
    private void setLastCrashInfo(String crashDir) {
        int lastTime = FineCrashSharedPreferences.readInt(mContext, FineCrashSharedPreferences.KEY_UES_TIME);
        String lastAppRam = FineCrashSharedPreferences.readString(mContext, FineCrashSharedPreferences.KEY_APP_RAM);
        File[] files = new File(crashDir).listFiles();
        for (File f : files) {
            if (!f.isDirectory()) {
                String fileName = f.getName();
                if (fileName.endsWith(".dmp")) {
                    String keyUseTime = FineCrashSharedPreferences.KEY_UES_TIME + "_" + fileName;
                    String fileUseTime = FineCrashSharedPreferences.readString(mContext, keyUseTime);
                    if (TextUtils.isEmpty(fileUseTime)) {
                        FineCrashSharedPreferences.saveInt(mContext, keyUseTime, lastTime);
                        FineCrashSharedPreferences.saveString(mContext, FineCrashSharedPreferences.KEY_APP_RAM + "_" + fileName, lastAppRam);
                    }
                }
            }
        }

        // 清除标志位
        FineCrashSharedPreferences.saveInt(mContext, FineCrashSharedPreferences.KEY_UES_TIME, 0);
        FineCrashSharedPreferences.saveString(mContext, FineCrashSharedPreferences.KEY_APP_RAM, "0");
    }

    @Override
    public void run() {
        if (isAppOnForeground) {
            useTime += 1;
            long appRam = FineCrashUtils.getAppRam();
            FineCrashSharedPreferences.saveInt(mContext, FineCrashSharedPreferences.KEY_UES_TIME, useTime);
            FineCrashSharedPreferences.saveString(mContext, FineCrashSharedPreferences.KEY_APP_RAM, "" + appRam);
        }
    }

    public void onStart() {
        isAppOnForeground = true;
    }

    public void onStop() {
        isAppOnForeground = false;
    }

}
