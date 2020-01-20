package com.fine.sdk.push.service.notification;

import java.lang.reflect.Field;
import java.lang.reflect.Method;

import com.fine.sdk.push.service.tools.FinePushLog;

import android.annotation.SuppressLint;
import android.app.Notification;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;

public class FinePushBadgeSetting {

	/**
	 * 设置推播角标
	 * 
	 * @param context
	 * @param notification
	 * @param count
	 */
	@SuppressLint("DefaultLocale")
	public static void setBadgeCount(Context context, Notification notification, int count) {
		if (context == null) {
			return;
		}
		String manufacturer = Build.MANUFACTURER.toLowerCase();
		FinePushLog.d("设备厂商:" + manufacturer);
		if (manufacturer.contains("xiaomi")) {
			setXiaomiBadge(context, notification, count);
		} else if (manufacturer.contains("huawei")) {
			setHuaweiBadge(context, count);
		} else if (manufacturer.contains("vivo")) {
			setVivoBadge(context, count);
		} else if (manufacturer.contains("oppo")) {
			setOppoBadge(context, count);
		} else if (manufacturer.contains("samsung")) {
			setSamsungBadge(context, count);
		} else if (manufacturer.contains("sony")) {
			setSonyBadge(context, count);
		}
	}

	/**
	 * 设置小米推播角标数字
	 * 
	 * @param context
	 * @param notification
	 * @param count
	 */
	private static void setXiaomiBadge(Context context, Notification notification, int count) {
		try {
			Field field = notification.getClass().getDeclaredField("extraNotification");
			Object extraNotification = field.get(notification);
			Method method = extraNotification.getClass().getDeclaredMethod("setMessageCount", int.class);
			method.invoke(extraNotification, count);
		} catch (Exception e) {
			// miui 6之前的版本
			Intent localIntent = new Intent("android.intent.action.APPLICATION_MESSAGE_UPDATE");
			localIntent.putExtra("android.intent.extra.update_application_component_name", context.getPackageName() + "/" + getLauncherClassName(context));
			localIntent.putExtra("android.intent.extra.update_application_message_text", String.valueOf(count == 0 ? "" : count));
			context.sendBroadcast(localIntent);
		}
	}

	/**
	 * 设置华为推播角标数字
	 * 
	 * @param context
	 * @param count
	 */
	private static void setHuaweiBadge(Context context, int count) {
		String launcherClassName = getLauncherClassName(context);
		if (launcherClassName != null) {
			Bundle extra = new Bundle();
			extra.putString("package", context.getPackageName());
			extra.putString("class", launcherClassName);
			extra.putInt("badgenumber", count);
			context.getContentResolver().call(Uri.parse("content://com.huawei.android.launcher.settings/badge/"), "change_badge", null, extra);
		}
	}

	/**
	 * 设置VIVO推播角标数字
	 * 
	 * @param context
	 * @param count
	 */
	private static void setVivoBadge(Context context, int count) {
		String launcherclassname = getLauncherClassName(context);
		if (launcherclassname != null) {
			Intent intent = new Intent("launcher.action.CHANGE_APPLICATION_NOTIFICATION_NUM");
			intent.putExtra("packageName", context.getPackageName());
			intent.putExtra("className", launcherclassname);
			intent.putExtra("notificationNum", count);
			context.sendBroadcast(intent);
		}
	}

	/**
	 * 设置OPPO推播角标数字
	 * 
	 * @param context
	 * @param count
	 */
	private static void setOppoBadge(Context context, int count) {
		try {
			Bundle extras = new Bundle();
			extras.putInt("app_badge_count", count);
			context.getContentResolver().call(Uri.parse("content://com.android.badge/badge"), "setAppBadgeCount", String.valueOf(count), extras);
		} catch (Throwable th) {
		}
	}

	/**
	 * 设置三星推播角标数字
	 * 
	 * @param context
	 * @param count
	 */
	private static void setSamsungBadge(Context context, int count) {
		String launcherClassName = getLauncherClassName(context);
		Intent intent = new Intent("android.intent.action.BADGE_COUNT_UPDATE");
		intent.putExtra("badge_count", count);
		intent.putExtra("badge_count_package_name", context.getPackageName());
		intent.putExtra("badge_count_class_name", launcherClassName);
		context.sendBroadcast(intent);
	}

	/**
	 * 设置索尼推播角标数字
	 * 
	 * @param context
	 * @param count
	 */
	private static void setSonyBadge(Context context, int count) {
		Intent intent = new Intent();
		String launcherclassname = getLauncherClassName(context);
		intent.setAction("com.sonyericsson.home.action.UPDATE_BADGE");
		intent.putExtra("com.sonyericsson.home.intent.extra.badge.SHOW_MESSAGE", count > 0);
		intent.putExtra("com.sonyericsson.home.intent.extra.badge.ACTIVITY_NAME", launcherclassname);
		intent.putExtra("com.sonyericsson.home.intent.extra.badge.MESSAGE", count < 1 ? "" : count);
		intent.putExtra("com.sonyericsson.home.intent.extra.badge.PACKAGE_NAME", context.getPackageName());
		context.sendBroadcast(intent);
	}

	/**
	 * 重置、清除Badge未读显示数
	 * 
	 * @param context
	 */
	public static void resetBadgeCount(Context context) {
		setBadgeCount(context, new Notification(), 0);
		FinePushLog.d("resetBadgeCount");
	}

	/**
	 * 获取启动类名
	 * 
	 * @param context
	 * @return
	 */
	private static String getLauncherClassName(Context context) {
		PackageManager pm = context.getPackageManager();
		Intent intent = new Intent("android.intent.action.MAIN");
		intent.addCategory("android.intent.category.LAUNCHER");
		try {
			for (ResolveInfo resolveInfo : pm.queryIntentActivities(intent, 0)) {
				if (resolveInfo.activityInfo.applicationInfo.packageName.equalsIgnoreCase(context.getPackageName())) {
					return resolveInfo.activityInfo.name;
				}
			}
			return null;
		} catch (Exception e) {
			return null;
		}
	}

}
