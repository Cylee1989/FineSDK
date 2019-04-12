package com.fine.sdk.tools;

import android.util.Log;

public class FineLog {

	private static String TAG = "FineSDK_Java";
	private static boolean isDebug = false;

	public static void setDebug(boolean isDebug) {
		FineLog.isDebug = isDebug;
	}

	public static void i(String className, String msg) {
		if (isDebug) {
			Log.i(TAG, className + "." + msg);
		}
	}

	public static void d(String className, String msg) {
		if (isDebug) {
			Log.d(TAG, className + "." + msg);
		}
	}

	public static void v(String className, String msg) {
		if (isDebug) {
			Log.v(TAG, className + "." + msg);
		}
	}

	public static void w(String className, String msg) {
		if (isDebug) {
			Log.w(TAG, className + "." + msg);
		}
	}

	public static void e(String className, String msg) {
		if (isDebug) {
			Log.e(TAG, className + "." + msg);
		}
	}

}
