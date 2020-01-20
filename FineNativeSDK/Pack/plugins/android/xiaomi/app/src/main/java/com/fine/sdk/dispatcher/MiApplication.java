package com.fine.sdk.dispatcher;

import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;

import com.xiaomi.gamecenter.sdk.MiCommplatform;
import com.xiaomi.gamecenter.sdk.entry.MiAppInfo;
import com.xiaomi.gamecenter.sdk.entry.MiAppType;


/**
 * Created by Cylee on 2019/4/24.
 */

public class MiApplication extends FineApplication {

    @Override
    public void onCreate() {
        super.onCreate();

        MiAppInfo appInfo = new MiAppInfo();
        String packageName = getPackageName();
        try {
            ApplicationInfo info = this.getPackageManager().getApplicationInfo(
                    packageName, PackageManager.GET_META_DATA);
            String appId = info.metaData.getString("AppID");
            appId = appId.substring(6);
            String appKey = info.metaData.getString("AppKey");
            appKey = appKey.substring(7);
            appInfo.setAppId(appId);
            appInfo.setAppKey(appKey);
            appInfo.setAppType(MiAppType.online);
            MiCommplatform.Init(MiApplication.this, appInfo);
        } catch (NameNotFoundException e) {
            e.printStackTrace();
        }
    }
}
