package com.fine.sdk.push.service.receiver;

import com.fine.sdk.push.FinePushSDK;
import com.fine.sdk.push.service.tools.FinePushLog;
import com.fine.sdk.push.service.notification.FinePushNotificationEvent;
import com.fine.sdk.push.service.udp.UDPClient;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

public class FinePushReceiver extends BroadcastReceiver {

	@Override
	public void onReceive(final Context context, Intent intent) {
		String action = intent.getAction();
		FinePushLog.d("FinePushReceiver onReceive:" + action);
		if (action.equals(FinePushNotificationEvent.CLICKED)) {
			Intent startIntent = context.getPackageManager().getLaunchIntentForPackage(context.getPackageName());
			startIntent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
			context.startActivity(startIntent);
			String receivedId = intent.getStringExtra("ReceivedID");
			UDPClient.getInstance().sendEvent(receivedId, 2);
		} else {
			Intent pushServiceIntent = new Intent();
			pushServiceIntent.setPackage(context.getPackageName());
			pushServiceIntent.setAction(FinePushSDK.PUSH_ACTION);
			context.startService(pushServiceIntent);
		}
	}
}
