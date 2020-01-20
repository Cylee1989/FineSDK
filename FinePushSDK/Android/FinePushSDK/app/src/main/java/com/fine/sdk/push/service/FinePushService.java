package com.fine.sdk.push.service;

import com.fine.sdk.push.service.db.FinePushLocalData;
import com.fine.sdk.push.service.db.FinePushRemoteData;
import com.fine.sdk.push.service.notification.FinePushLocalNotification;
import com.fine.sdk.push.service.notification.FinePushRemoteNotification;
import com.fine.sdk.push.service.tools.FinePushKeepAlive;
import com.fine.sdk.push.service.tools.FinePushLog;
import com.fine.sdk.push.service.tools.FinePushTools;
import com.fine.sdk.push.service.udp.UDPClient;

import android.app.Notification;
import android.app.Service;
import android.content.Intent;
import android.os.Build;
import android.os.IBinder;

public class FinePushService extends Service {

    private FinePushLocalNotification mFinePushLocalNotification;
    private FinePushRemoteNotification mFinePushRemoteNotification;
    private String mUUID = "";

    @Override
    public void onCreate() {
        super.onCreate();
        mUUID = FinePushTools.getUUID(this).toString();
        new FinePushKeepAlive(this);
        mFinePushLocalNotification = new FinePushLocalNotification(this);
        mFinePushRemoteNotification = new FinePushRemoteNotification(this);
        UDPClient.getInstance().init(this, mFinePushRemoteNotification);
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            FinePushLog.d("FinePushService onCreate startForeground. (Android8.0+)");
            startForeground(1, new Notification());
        }
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        return Service.START_STICKY;
    }

    @Override
    public void onDestroy() {
        UDPClient.getInstance().close();
        super.onDestroy();
    }

    @Override
    public IBinder onBind(Intent intent) {
        return binder;
    }

    private IFinePush.Stub binder = new IFinePush.Stub() {

        @Override
        public void addLocalPush(FinePushLocalData data) {
            mFinePushLocalNotification.addNotification(data);
        }

        @Override
        public void clearLocalPushByKey(String key) {
            mFinePushLocalNotification.clearNotificationByKey(key);
        }

        @Override
        public void clearAllLocalPush() {
            mFinePushLocalNotification.clearAllNotification();
        }

        @Override
        public void registerRemotePush(FinePushRemoteData data) {
            data.setUuid(mUUID);
            UDPClient.getInstance().updateRemoteData(data);
        }

    };

}
