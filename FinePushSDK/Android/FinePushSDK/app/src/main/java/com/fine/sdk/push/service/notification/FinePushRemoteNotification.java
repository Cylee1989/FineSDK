package com.fine.sdk.push.service.notification;

import com.fine.sdk.push.service.tools.FinePushLog;
import com.fine.sdk.push.service.receiver.FinePushReceiver;
import com.fine.sdk.push.service.tools.FinePushTools;

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
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Build;

public class FinePushRemoteNotification {

	private Context mContext;
	private NotificationManager mNotificationManager;
	private String mPackageName;
	private int mNotifyID;

	public FinePushRemoteNotification(Context context) {
		this.mContext = context;
		mPackageName = mContext.getPackageName();
		mNotificationManager = (NotificationManager) mContext.getSystemService(Context.NOTIFICATION_SERVICE);
	}

	@SuppressLint("WrongConstant")
	public void show(String receivedID, String alert, int badge) {
		if (FinePushTools.isApplicationOnFront(mContext)) {
			FinePushLog.d("FinePushRemoteNotification show(前台):" + mPackageName + "|" + alert);
			return;
		}
		try {
			PackageManager packageManager = mContext.getPackageManager();
			// 获取应用信息
			ApplicationInfo applicationInfo = packageManager.getApplicationInfo(mPackageName, PackageManager.MATCH_DEFAULT_ONLY);
			// 获取APP名称
			String appName = (String) packageManager.getApplicationLabel(mContext.getApplicationInfo());
			// 获取大图标对象
			Bitmap largeIcon = BitmapFactory.decodeResource(mContext.getResources(), applicationInfo.icon);
			// 设定跳转Intent
			Intent intent = new Intent(mContext, FinePushReceiver.class);
			intent.setAction(FinePushNotificationEvent.CLICKED);
			intent.putExtra("ReceivedID", receivedID);
			PendingIntent pendIntent = PendingIntent.getBroadcast(mContext.getApplicationContext(), 0, intent, 0);

			Notification.Builder builder = new Notification.Builder(mContext);
			if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
				FinePushLog.d("FinePushRemoteNotification New NotificationChannel. (Android8.0+)");
				String channelID = "FinePush_Remote_" + mPackageName;
				NotificationChannel channel = new NotificationChannel(channelID, "远程通知", NotificationManager.IMPORTANCE_DEFAULT);
				mNotificationManager.createNotificationChannel(channel);
				builder = new Notification.Builder(mContext, channelID);
			}

			// 设置标题
			builder.setContentTitle(appName);
			// 设置内容
			builder.setContentText(alert);
			// 设置小图标
			builder.setSmallIcon(applicationInfo.icon);
			// 设置大图标
			builder.setLargeIcon(largeIcon);
			// 设置跳转
			builder.setContentIntent(pendIntent);
			// 设置指示灯、声音、震动默认
			builder.setDefaults(Notification.DEFAULT_ALL);
			// 设置自动取消
			builder.setAutoCancel(true);
			// 设置是否只提示一次
			builder.setOnlyAlertOnce(true);

			Notification notification = builder.build();
			mNotificationManager.notify(mNotifyID, notification);
			mNotifyID++;
			// FinePushBadgeSetting.setBadgeCount(mContext, notification, badge);
			FinePushLog.d("FinePushRemoteNotification show(后台):" + mPackageName + "|" + alert);
		} catch (NameNotFoundException e) {
			e.printStackTrace();
		}
	}

	public void clearAll() {
		mNotificationManager.cancelAll();
	}

}
