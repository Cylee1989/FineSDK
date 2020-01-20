package com.fine.sdk.push.test;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

import com.fine.sdk.push.FinePushListener;
import com.fine.sdk.push.FinePushSDK;
import com.fine.sdk.push.R;
import com.fine.sdk.push.service.db.FinePushLocalData;
import com.fine.sdk.push.service.db.FinePushRemoteData;
import com.fine.sdk.push.service.notification.FinePushLocalNotificationType;
import com.fine.sdk.push.service.tools.FinePushLog;

public class MainActivity extends Activity implements View.OnClickListener {

    private FinePushSDK mFinePushSDK;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        FinePushLog.setDebug(true);
        mFinePushSDK = new FinePushSDK(this, new FinePushListener() {

            @Override
            public void onServiceDisconnected() {
            }

            @Override
            public void onServiceConnected() {

            }
        });

        findViewById(R.id.button_local_notification).setOnClickListener(this);
        findViewById(R.id.button_local_notification_clear).setOnClickListener(this);
        findViewById(R.id.button_local_notification_clearAll).setOnClickListener(this);
        findViewById(R.id.button_remote_notification_register).setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.button_local_notification:
                FinePushLocalData localData = new FinePushLocalData();
                localData.setKey("KEY001");
                localData.setMessage("测试本地推送");
                localData.setTime(System.currentTimeMillis() + 10 * 1000);
                localData.setRepeatInterval(FinePushLocalNotificationType.OPCalendarUnitDay);
                localData.setSoundName("notification");
                mFinePushSDK.addLocalPush(localData);
                break;
            case R.id.button_local_notification_clear:
                mFinePushSDK.clearLocalNotificationByKey("KEY001");
                break;
            case R.id.button_local_notification_clearAll:
                mFinePushSDK.clearAllLocalNotification();
                break;
            case R.id.button_remote_notification_register:
                FinePushRemoteData remoteData = new FinePushRemoteData();
                remoteData.setAppID("test");
                remoteData.setAppKey("test");
                remoteData.setHost("127.0.0.1");
                remoteData.setPort(8001);
                mFinePushSDK.registerRemotePush(remoteData);
                break;
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        mFinePushSDK.onResume();
    }

    @Override
    protected void onDestroy() {
        mFinePushSDK.onDestroy();
        super.onDestroy();
    }
}
