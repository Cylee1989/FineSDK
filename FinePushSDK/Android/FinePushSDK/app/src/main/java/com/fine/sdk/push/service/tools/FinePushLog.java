package com.fine.sdk.push.service.tools;

import android.util.Log;

public class FinePushLog {

	private static String TAG = "FinePush";
	private static boolean isDebug = true;

	public static void setDebug(boolean isDebug) {
		FinePushLog.isDebug = isDebug;
	}

	public static void d(String msg) {
		if (isDebug) {
			Log.d(TAG, msg);
		}
	}

}
