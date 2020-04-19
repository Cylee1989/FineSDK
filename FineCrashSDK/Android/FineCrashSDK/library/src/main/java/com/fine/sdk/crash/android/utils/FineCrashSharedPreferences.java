package com.fine.sdk.crash.android.utils;

import android.content.Context;
import android.content.SharedPreferences;

/**
 * 缓存类
 *
 * @author Cylee
 */
public class FineCrashSharedPreferences {

    public static String KEY_UES_TIME = "key_use_time";
    public static String KEY_APP_RAM = "key_app_ram";

    private static String fileName = "FineCrashSharedPreferences";

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

    public synchronized static void saveInt(Context context, String key, int value) {
        SharedPreferences.Editor editor = getSharedPreferences(context).edit();
        editor.putInt(key, value);
        editor.apply();
    }

    public static int readInt(Context context, String key) {
        SharedPreferences sp = getSharedPreferences(context);
        int value = sp.getInt(key, 0);
        return value;
    }

    public synchronized static void delete(Context context, String key) {
        SharedPreferences.Editor editor = getSharedPreferences(context).edit();
        editor.remove(key);
        editor.apply();
    }

}
