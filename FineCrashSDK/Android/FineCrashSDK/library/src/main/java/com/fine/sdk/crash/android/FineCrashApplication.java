package com.fine.sdk.crash.android;

import android.app.Application;

/**
 * FineCrashApplication
 *
 * @author Cylee
 */
public class FineCrashApplication extends Application {

    @Override
    public void onCreate() {
        super.onCreate();
        FineCrashSDK.getInstance().init(this);
    }

}
