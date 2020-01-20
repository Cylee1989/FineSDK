package com.fine.sdk.device.info;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.lang.reflect.Method;
import java.util.Currency;
import java.util.Locale;
import java.util.TimeZone;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.ConfigurationInfo;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.Point;
import android.os.Build;
import android.util.DisplayMetrics;
import android.view.Display;
import android.view.View;
import android.view.WindowManager;

public class FineDeviceInfo {

    /**
     * 获取状态栏高度
     *
     * @param activity
     * @return
     */
    public static int getStatusBarHeight(Activity activity) {
        int result = 0;
        int resourceId = activity.getResources().getIdentifier(
                "status_bar_height", "dimen", "android");
        if (resourceId > 0) {
            result = activity.getResources().getDimensionPixelSize(resourceId);
        }
        return result;
    }

    /**
     * 获取导航栏高度
     *
     * @param activity
     * @return
     */
    public static int getNavigationBarHeight(Activity activity) {
        int resourceId = 0;
        int rid = activity.getResources().getIdentifier(
                "config_showNavigationBar", "bool", "android");
        if (rid != 0) {
            resourceId = activity.getResources().getIdentifier(
                    "navigation_bar_height", "dimen", "android");
            return activity.getResources().getDimensionPixelSize(resourceId);
        }
        return 0;
    }

    /**
     * 获取屏幕真实分辨率(除vivo系统)
     *
     * @param activity
     * @return
     */
    public static Point getRealScreenSize(Activity activity) {
        Point screenSize = null;
        try {
            screenSize = new Point();
            WindowManager windowManager = (WindowManager) activity
                    .getSystemService(Context.WINDOW_SERVICE);
            Display defaultDisplay = windowManager.getDefaultDisplay();
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.JELLY_BEAN_MR1) {
                defaultDisplay.getRealSize(screenSize);
            } else {
                try {
                    Method mGetRawW = Display.class.getMethod("getRawWidth");
                    Method mGetRawH = Display.class.getMethod("getRawHeight");
                    screenSize.set((Integer) mGetRawW.invoke(defaultDisplay),
                            (Integer) mGetRawH.invoke(defaultDisplay));
                } catch (Exception e) {
                    screenSize.set(defaultDisplay.getWidth(),
                            defaultDisplay.getHeight());
                    e.printStackTrace();
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        return screenSize;
    }

    /**
     * 获取显示分辨率
     *
     * @param activity
     * @return
     */
    public static Point getDisplayScreenSize(Activity activity) {
        DisplayMetrics dm = activity.getResources().getDisplayMetrics();
        Point screenSize = new Point();
        screenSize.set(dm.widthPixels, dm.heightPixels);
        return screenSize;
    }

    /**
     * 获取截图分辨率
     *
     * @param activity
     * @return
     */
    public static Point getShotScreenSize(Activity activity) {
        View view = activity.getWindow().getDecorView();
        view.setDrawingCacheEnabled(true);
        view.buildDrawingCache();
        Bitmap bmp = view.getDrawingCache();
        Point screenSize = new Point();
        if (bmp != null) {
            screenSize.set(bmp.getWidth(), bmp.getHeight());
        }
        return screenSize;
    }

    /**
     * 获取应用包名
     *
     * @param activity
     * @return
     */
    public static String getPackageName(Activity activity) {
        return activity.getApplicationContext().getPackageName();
    }

    /**
     * 获取版本名称
     *
     * @param activity
     * @return
     */
    public static String getVersionName(Activity activity) {

        String pkName = getPackageName(activity);
        String versionName = "";
        try {
            versionName = activity.getPackageManager().getPackageInfo(pkName, 0).versionName;
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }

        return versionName;
    }

    /**
     * 获取版本号
     *
     * @param activity
     * @return
     */
    public static String getVersionCode(Activity activity) {

        String pkName = getPackageName(activity);
        String versionCode = "";
        try {
            versionCode = String.valueOf(activity.getPackageManager().getPackageInfo(pkName, 0).versionCode);
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }

        return versionCode;
    }

    /**
     * 获取OpenGL版本号
     * <p>
     * OpenGLES 1.1 info.reqGlEsVersion=0x00010001
     * OpenGLES 2.0 info.reqGlEsVersion= 0x00020000
     *
     * @param activity
     * @return
     */
    public static String getGLVersion(Activity activity) {
        ActivityManager am = (ActivityManager) activity.getSystemService(Context.ACTIVITY_SERVICE);
        ConfigurationInfo info = am.getDeviceConfigurationInfo();
        return info.getGlEsVersion();
    }

    /**
     * 获取系统总内存(KB)
     *
     * @return
     */
    public static String getTotalMemory() {
        try {
            FileReader fr = new FileReader("/proc/meminfo");
            BufferedReader br = new BufferedReader(fr, 2048);
            String memoryLine = br.readLine();
            String subMemoryLine = memoryLine.substring(memoryLine.indexOf("MemTotal:"));
            br.close();
            return subMemoryLine.replaceAll("\\D+", "");
        } catch (IOException e) {
            e.printStackTrace();
        }
        return "";
    }

    /**
     * 获取当前可用内存(KB)
     *
     * @param activity
     * @return
     */
    public static String getAvailableMemory(Activity activity) {
        ActivityManager am = (ActivityManager) activity.getSystemService(Context.ACTIVITY_SERVICE);
        ActivityManager.MemoryInfo memoryInfo = new ActivityManager.MemoryInfo();
        am.getMemoryInfo(memoryInfo);
        return String.valueOf((int) (memoryInfo.availMem / 1024));
    }

    /**
     * 获取当前应用可用内存(KB)
     *
     * @param activity
     * @return
     */
    public static String getAppMemory(Activity activity) {
        long totalMemory = Runtime.getRuntime().totalMemory() / 1024;
        return String.valueOf(totalMemory);
    }

    /**
     * 判断设备是否为模拟器
     *
     * @return
     */
    public static boolean isEmulator() {
        return Build.FINGERPRINT.startsWith("generic") || Build.FINGERPRINT.toLowerCase().contains("vbox") || Build.FINGERPRINT.toLowerCase().contains("test-keys")
                || Build.MODEL.contains("google_sdk") || Build.MODEL.contains("Emulator") || Build.SERIAL.equalsIgnoreCase("unknown") || Build.SERIAL.equalsIgnoreCase("android")
                || Build.MODEL.contains("Android SDK built for x86") || Build.MANUFACTURER.contains("Genymotion")
                || (Build.BRAND.startsWith("generic") && Build.DEVICE.startsWith("generic")) || "google_sdk".equals(Build.PRODUCT);
    }

    /**
     * 获取国家码
     *
     * @return
     */
    public static String getCountryCode() {
        return Locale.getDefault().getCountry();
    }

    /**
     * 获取国家名称
     *
     * @return
     */
    public static String getDisplayCountry() {
        return Locale.getDefault().getDisplayCountry();
    }

    /**
     * 获取语言
     *
     * @return
     */
    public static String getLanguage() {
        return Locale.getDefault().getLanguage();
    }

    /**
     * 获取地区时区
     *
     * @return
     */
    public static String getTimeZoneID() {
        return TimeZone.getDefault().getID();
    }

    /**
     * 获取货币码
     *
     * @return
     */
    public static String getCurrencyCode() {
        Locale lc = Locale.getDefault();
        Currency currency = Currency.getInstance(lc);
        return currency.getCurrencyCode();
    }

    /**
     * 获取货币符号
     *
     * @return
     */
    public static String getCurrencySymbol() {
        Locale lc = Locale.getDefault();
        Currency currency = Currency.getInstance(lc);
        return currency.getSymbol();
    }

}
