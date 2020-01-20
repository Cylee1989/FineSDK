package com.fine.sdk.push.service.tools;

import com.fine.sdk.push.FinePushSDK;

import android.annotation.SuppressLint;
import android.app.AlarmManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;

public class FinePushKeepAlive {

    private Context mContext;

    public FinePushKeepAlive(Context context) {
        this.mContext = context;
        keepAliveByAlarm();
    }

    @SuppressLint("WrongConstant")
    private void keepAliveByAlarm() {
        Intent pushServiceIntent = new Intent();
        pushServiceIntent.setPackage(mContext.getPackageName());
        pushServiceIntent.setAction(FinePushSDK.PUSH_ACTION);
        AlarmManager mAlarmManager = (AlarmManager) mContext.getSystemService(Context.ALARM_SERVICE);
        PendingIntent mPendingIntent = PendingIntent.getService(mContext, 0, pushServiceIntent, Intent.FLAG_ACTIVITY_NEW_TASK);
        long now = System.currentTimeMillis();
        mAlarmManager.setInexactRepeating(AlarmManager.RTC, now, 30000, mPendingIntent);
    }

}
