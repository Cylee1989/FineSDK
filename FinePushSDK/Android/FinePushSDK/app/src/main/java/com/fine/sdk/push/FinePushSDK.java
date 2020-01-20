package com.fine.sdk.push;

import com.fine.sdk.push.service.IFinePush;
import com.fine.sdk.push.service.db.FinePushRemoteData;
import com.fine.sdk.push.service.tools.FinePushLog;
import com.fine.sdk.push.service.db.FinePushLocalData;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Build;
import android.os.IBinder;
import android.os.RemoteException;

public class FinePushSDK implements ServiceConnection {

    public static final String VERSION = "1.0.0";

    private Context mContext;
    private IFinePush iFinePush;
    private FinePushListener mFinePushListener;
    public static final String PUSH_ACTION = "com.fine.sdk.push.service";

    public FinePushSDK(Context context, FinePushListener finePushListener) {
        FinePushLog.d("FinePushSDK init");
        this.mContext = context;
        this.mFinePushListener = finePushListener;
        Intent bindService = new Intent();
        bindService.setPackage(mContext.getPackageName());
        bindService.setAction(PUSH_ACTION);
        if (Build.VERSION.SDK_INT < Build.VERSION_CODES.O) {
            mContext.startService(bindService);
        } else {
            mContext.startForegroundService(bindService);
        }
        mContext.bindService(bindService, this, Context.BIND_AUTO_CREATE);
    }

    /**
     * 添加本地推送
     *
     * @param data
     */
    public void addLocalPush(FinePushLocalData data) {
        if (iFinePush == null || data == null)
            return;

        try {
            iFinePush.addLocalPush(data);
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

    /**
     * 按Key清除本地推送
     *
     * @param key
     */
    public void clearLocalNotificationByKey(String key) {
        if (iFinePush == null)
            return;

        try {
            iFinePush.clearLocalPushByKey(key);
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

    /**
     * 清除所有本地推送
     */
    public void clearAllLocalNotification() {
        if (iFinePush == null)
            return;

        try {
            iFinePush.clearAllLocalPush();
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

    /**
     * 添加远程推送
     *
     * @param data
     */
    public void registerRemotePush(FinePushRemoteData data) {
        if (iFinePush == null || data == null)
            return;

        try {
            iFinePush.registerRemotePush(data);
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

    public void onResume() {
        // FinePushBadgeSetting.resetBadgeCount(mContext);
    }

    public void onDestroy() {
        mContext.unbindService(this);
    }

    @Override
    public void onServiceConnected(ComponentName name, IBinder service) {
        FinePushLog.d("FinePushSDK onServiceConnected");
        iFinePush = IFinePush.Stub.asInterface(service);
        mFinePushListener.onServiceConnected();
    }

    @Override
    public void onServiceDisconnected(ComponentName name) {
        FinePushLog.d("FinePushSDK onServiceDisconnected");
        iFinePush = null;
        mFinePushListener.onServiceDisconnected();
    }

}
