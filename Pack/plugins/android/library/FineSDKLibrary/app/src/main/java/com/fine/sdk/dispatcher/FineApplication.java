package com.fine.sdk.dispatcher;

import android.app.Application;
import android.content.Context;
import android.support.multidex.MultiDex;

import com.fine.sdk.tools.FineConfig;
import com.fine.sdk.tools.FineLog;

/**
 * Created by Cylee on 2019/7/1.
 */

public class FineApplication extends Application {

    @Override
    protected void attachBaseContext(Context base) {
        // TODO Auto-generated method stub
        super.attachBaseContext(base);
        MultiDex.install(this);
        FineLog.setDebug(true);
        FineConfig.getInstance().load(this);
    }

}
