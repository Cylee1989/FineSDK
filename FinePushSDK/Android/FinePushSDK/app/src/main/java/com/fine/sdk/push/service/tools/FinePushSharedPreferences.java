package com.fine.sdk.push.service.tools;

import android.content.Context;
import android.content.SharedPreferences;

public class FinePushSharedPreferences {

	private static String fileName = "FinePushSharedPreferences";

	private static SharedPreferences getSharedPreferences(Context context) {
		SharedPreferences sp = context.getSharedPreferences(fileName, Context.MODE_PRIVATE);
		return sp;
	}

	public synchronized static void saveString(Context context, String key, String value) {
		SharedPreferences.Editor editor = getSharedPreferences(context).edit();
		editor.putString(key, value);
		editor.apply();
	}

	public static String readString(Context context, String key) {
		SharedPreferences sp = getSharedPreferences(context);
		String value = sp.getString(key, "");
		return value;
	}

	public synchronized static void saveBoolean(Context context, String key, boolean value) {
		SharedPreferences.Editor editor = getSharedPreferences(context).edit();
		editor.putBoolean(key, value);
		editor.apply();
	}

	public static boolean readBoolean(Context context, String key) {
		SharedPreferences sp = getSharedPreferences(context);
		boolean value = sp.getBoolean(key, false);
		return value;
	}
}
