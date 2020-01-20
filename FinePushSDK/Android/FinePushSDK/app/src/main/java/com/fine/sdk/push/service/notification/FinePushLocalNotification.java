package com.fine.sdk.push.service.notification;

import java.lang.ref.WeakReference;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

import com.fine.sdk.push.service.db.FinePushDBHelper;
import com.fine.sdk.push.service.db.FinePushLocalData;
import com.fine.sdk.push.service.tools.FinePushLog;

import android.annotation.SuppressLint;
import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Build;
import android.os.Handler;
import android.os.Message;
import android.text.TextUtils;

public class FinePushLocalNotification {

    private Context mContext;
    private NotificationManager mNotificationManager;
    private String mPackageName;
    private int mNotifyID = 1000;
    private String mUriPath;

    private FinePushDBHelper mLocalPushDBHelper;
    private Map<String, FinePushLocalData> mPushDataMap = new HashMap<String, FinePushLocalData>();
    private PushHandler mHandler = new PushHandler(this);

    public FinePushLocalNotification(Context context) {
        this.mContext = context;
        mLocalPushDBHelper = new FinePushDBHelper(mContext);
        mPackageName = mContext.getPackageName();
        mNotificationManager = (NotificationManager) mContext.getSystemService(Context.NOTIFICATION_SERVICE);
        mUriPath = "android.resource://" + mContext.getPackageName() + "/raw/";
        readAllLocalNotification();
    }

    private void readAllLocalNotification() {
        ArrayList<FinePushLocalData> list = mLocalPushDBHelper.queryAllData();
        for (int i = 0; i < list.size(); i++) {
            addNotification(list.get(i));
        }
    }

    public void addNotification(final FinePushLocalData data) {
        if (data == null || TextUtils.isEmpty(data.getKey()) || data.getTime() <= 0) {
            FinePushLog.d("FinePushLocalNotification addPush: data is null or empty");
            return;
        }

        long curTime = System.currentTimeMillis();
        if (data.getTime() < curTime) {
            FinePushLog.d("FinePushLocalNotification addPush: 时间戳过期");
            long repeatTime = getRepeatIntervalTime(data.getRepeatInterval());
            if (repeatTime <= 0) {
                return;
            }
            // 时间戳过期处理
            int repeatCount = (int) ((curTime - data.getTime()) / repeatTime) + 1;
            long time = data.getTime() + repeatCount * repeatTime;
            data.setTime(time);
        }

        clearNotificationByKey(data.getKey());

        mLocalPushDBHelper.insertData(data);
        mPushDataMap.put(data.getKey(), data);
        data.setRunnable(new Runnable() {

            @Override
            public void run() {
                Message msg = Message.obtain();
                msg.what = PushHandler.PUSH_LOCAL_NOTIFICATION;
                msg.obj = data;
                mHandler.sendMessage(msg);
            }
        });
        long delayTime = data.getTime() - System.currentTimeMillis();
        mHandler.postDelayed(data.getRunnable(), delayTime);
        FinePushLog.d("FinePushLocalNotification addPush:" + data.toString());
    }

    public void clearNotificationByKey(String key) {
        FinePushLocalData data = mPushDataMap.get(key);
        if (data != null && data.getRunnable() != null) {
            mHandler.removeCallbacks(data.getRunnable());
            mPushDataMap.remove(key);
            mLocalPushDBHelper.deleteData(key);
            FinePushLog.d("FinePushLocalNotification clearByKey:" + key);
        }
    }

    public void clearAllNotification() {
        ArrayList<FinePushLocalData> list = mLocalPushDBHelper.queryAllData();
        for (int i = 0; i < list.size(); i++) {
            clearNotificationByKey(list.get(i).getKey());
        }
        FinePushLog.d("FinePushLocalNotification clearAll");
    }

    @SuppressLint("WrongConstant")
    private void pushNotification(String message, String soundName) {
        try {
            PackageManager packageManager = mContext.getPackageManager();
            // 获取应用信息
            ApplicationInfo applicationInfo = packageManager.getApplicationInfo(mPackageName, PackageManager.MATCH_DEFAULT_ONLY);
            // 获取APP名称
            String appName = (String) packageManager.getApplicationLabel(mContext.getApplicationInfo());
            // 获取大图标对象
            Bitmap largeIcon = BitmapFactory.decodeResource(mContext.getResources(), applicationInfo.icon);
            // 设定跳转Intent
            Intent intent = packageManager.getLaunchIntentForPackage(mPackageName);
            PendingIntent pendIntent = PendingIntent.getActivity(mContext.getApplicationContext(), 0, intent, 0);

            Notification.Builder builder = new Notification.Builder(mContext);
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
                FinePushLog.d("FinePushLocalNotification New NotificationChannel. (Android8.0+)");
                String channelID = "FinePush_Local_" + mPackageName;
                NotificationChannel channel = new NotificationChannel(channelID, "本地通知", NotificationManager.IMPORTANCE_DEFAULT);
                if (isExistRaw(soundName)) {
                    channel.setSound(Uri.parse(mUriPath + soundName), Notification.AUDIO_ATTRIBUTES_DEFAULT);
                }
                mNotificationManager.createNotificationChannel(channel);
                builder = new Notification.Builder(mContext, channelID);
            }

            // 设置标题
            builder.setContentTitle(appName);
            // 设置内容
            builder.setContentText(message);
            // 设置小图标
            builder.setSmallIcon(applicationInfo.icon);
            // 设置大图标
            builder.setLargeIcon(largeIcon);
            // 设置跳转
            builder.setContentIntent(pendIntent);
            // 设置自动取消
            builder.setAutoCancel(true);
            // 设置是否只提示一次
            builder.setOnlyAlertOnce(true);
            if (isExistRaw(soundName)) {
                builder.setSound(Uri.parse(mUriPath + soundName));
            } else {
                // 设置指示灯、声音、震动默认
                builder.setDefaults(Notification.DEFAULT_ALL);
            }

            Notification notification = builder.build();
            mNotificationManager.notify(mNotifyID, notification);
            mNotifyID++;
            FinePushLog.d("FinePushLocalNotification pushNotification:" + mPackageName + "|" + message);
        } catch (NameNotFoundException e) {
            e.printStackTrace();
        }
    }

    /**
     * 是否存在音频文件
     *
     * @param soundName
     * @return
     */
    private boolean isExistRaw(String soundName) {
        if (TextUtils.isEmpty(soundName)) {
            return false;
        }
        Resources localResources = mContext.getResources();
        int i = localResources.getIdentifier(soundName, "raw", mContext.getPackageName());
        if (i == 0) {
            return false;
        }
        return true;
    }

    private long getRepeatIntervalTime(int repeatInterval) {
        long time = 0;
        switch (repeatInterval) {
            case FinePushLocalNotificationType.OPCalendarUnitEra:
                time = 100 * 365 * 24 * 60 * 60 * 1000;
                break;
            case FinePushLocalNotificationType.OPCalendarUnitYear:
                time = 365 * 24 * 60 * 60 * 1000;
                break;
            case FinePushLocalNotificationType.OPCalendarUnitMonth:
                time = 30 * 24 * 60 * 60 * 1000;
                break;
            case FinePushLocalNotificationType.OPCalendarUnitDay:
                time = 24 * 60 * 60 * 1000;
                break;
            case FinePushLocalNotificationType.OPCalendarUnitHour:
                time = 60 * 60 * 1000;
                break;
            case FinePushLocalNotificationType.OPCalendarUnitMinute:
                time = 60 * 1000;
                break;
            case FinePushLocalNotificationType.OPCalendarUnitSecond:
                time = 1 * 1000;
                break;
            case FinePushLocalNotificationType.OPCalendarUnitWeekday:
                time = 7 * 24 * 60 * 60 * 1000;
                break;
            case FinePushLocalNotificationType.OPCalendarUnitWeekdayOrdinal:
                break;
        }
        return time;
    }

    private static class PushHandler extends Handler {
        private final WeakReference<FinePushLocalNotification> contextWeakReference;

        public PushHandler(FinePushLocalNotification context) {
            contextWeakReference = new WeakReference<>(context);
        }

        protected static final int PUSH_LOCAL_NOTIFICATION = 1;

        @Override
        public void handleMessage(Message msg) {
            FinePushLocalNotification notification = contextWeakReference.get();
            if (notification != null) {
                switch (msg.what) {
                    case PUSH_LOCAL_NOTIFICATION:
                        FinePushLocalData data = (FinePushLocalData) msg.obj;
                        data.setTime(data.getTime() + notification.getRepeatIntervalTime(data.getRepeatInterval()));
                        notification.addNotification(data);
                        notification.pushNotification(data.getMessage(), data.getSoundName());
                        break;
                }
            }
        }

    }

}
