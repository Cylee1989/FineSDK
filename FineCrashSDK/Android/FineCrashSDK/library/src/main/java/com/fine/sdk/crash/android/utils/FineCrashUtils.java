package com.fine.sdk.crash.android.utils;

import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.Build;
import android.os.Environment;
import android.os.StatFs;
import android.telephony.TelephonyManager;
import android.text.format.Formatter;
import android.util.Base64;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;
import java.util.Currency;
import java.util.List;
import java.util.Locale;
import java.util.TimeZone;

/**
 * 工具类
 *
 * @author Cylee
 */
public class FineCrashUtils {

    /**
     * 获取崩溃日志目录
     *
     * @param context
     * @param crashDirName
     * @return
     */
    public static String getCrashDir(Context context, String crashDirName) {
        String cachePath;
        if (Environment.MEDIA_MOUNTED.equals(Environment.getExternalStorageState()) || !Environment.isExternalStorageRemovable()) {
            cachePath = context.getExternalCacheDir().getAbsolutePath();
        } else {
            cachePath = context.getCacheDir().getAbsolutePath();
        }
        File dump = new File(cachePath + File.separator + crashDirName);
        if (!dump.exists()) {
            dump.mkdir();
        }
        return dump.getAbsolutePath();
    }

    /**
     * 获取设备CPU架构
     *
     * @return
     */
    public static String getCpuAbi() {
        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.LOLLIPOP) {
            String[] abi = Build.SUPPORTED_ABIS;
            if (abi != null && abi.length > 0) {
                return abi[0];
            }
        }
        return "";
    }

    /**
     * 读取文件内容，并Base64转码
     *
     * @param fileName
     * @return
     */
    public static String readFileWithBase64(String fileName) {
        String res = "";
        try {
            FileInputStream fin = new FileInputStream(fileName);
            int length = fin.available();
            byte[] buffer = new byte[length];
            fin.read(buffer);
            res = android.util.Base64.encodeToString(buffer, Base64.DEFAULT);
            buffer.clone();
            fin.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return res;
    }

    /**
     * 获取安卓系统版本
     *
     * @return
     */
    public static String getSystemVersion() {
        return android.os.Build.VERSION.RELEASE;
    }

    /**
     * 获取应用程序名称
     *
     * @param context
     * @return
     */
    public static String getAppName(Context context) {
        try {
            PackageManager packageManager = context.getPackageManager();
            PackageInfo packageInfo = packageManager.getPackageInfo(
                    context.getPackageName(), 0);
            int labelRes = packageInfo.applicationInfo.labelRes;
            return context.getResources().getString(labelRes);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return "";
    }

    /**
     * 获取应用包名
     *
     * @param context
     * @return
     */
    public static String getPackageName(Context context) {
        return context.getApplicationContext().getPackageName();
    }

    /**
     * 获取版本名称
     *
     * @param context
     * @return
     */
    public static String getVersionName(Context context) {
        String pkName = getPackageName(context);
        String versionName = "";
        try {
            PackageInfo info = context.getPackageManager().getPackageInfo(pkName, 0);
            versionName = info.versionName;
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        return versionName;
    }

    /**
     * 获取版本号
     *
     * @param context
     * @return
     */
    public static String getVersionCode(Context context) {
        String pkName = getPackageName(context);
        String versionCode = "";
        try {
            PackageInfo info = context.getPackageManager().getPackageInfo(pkName, 0);
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
                versionCode = String.valueOf(info.getLongVersionCode());
            } else {
                versionCode = String.valueOf(info.versionCode);
            }
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        return versionCode;
    }

    /**
     * 获取设备厂商
     *
     * @return
     */
    public static String getDeviceManufacturer() {
        return Build.MANUFACTURER.toLowerCase();
    }

    /**
     * 获取设备型号
     *
     * @return
     */
    public static String getDeviceModel() {
        return Build.MODEL;
    }

    /**
     * 获取总共ROM大小(GB)
     *
     * @param context
     * @return
     */
    public static long getTotalRom(Context context) {
        File path = Environment.getDataDirectory();
        StatFs stat = new StatFs(path.getPath());
        long blockSize = 0;
        long totalBlocks = 0;
        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.JELLY_BEAN_MR2) {
            blockSize = stat.getBlockSizeLong();
            totalBlocks = stat.getBlockCountLong();
        }
        String totalSize = Formatter.formatFileSize(context, totalBlocks * blockSize);
        return totalBlocks * blockSize / 1024 / 1024 / 1024;
    }

    /**
     * 获取剩余可用ROM大小(GB)
     *
     * @param context
     * @return
     */
    public static double getAvailableRom(Context context) {
        File path = Environment.getDataDirectory();
        StatFs stat = new StatFs(path.getPath());
        long blockSize = 0;
        long availableBlocks = 0;
        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.JELLY_BEAN_MR2) {
            blockSize = stat.getBlockSizeLong();
            availableBlocks = stat.getAvailableBlocksLong();
        }
        String availableSize = Formatter.formatFileSize(context, availableBlocks * blockSize);
        return availableBlocks * blockSize / 1024 / 1024 / 1024;
    }

    /**
     * 获取系统总内存(KB)
     *
     * @return
     */
    public static String getTotalRam() {
        try {
            FileReader fr = new FileReader("/proc/meminfo");
            BufferedReader br = new BufferedReader(fr, 2048);
            String memoryLine = br.readLine();
            String subMemoryLine = memoryLine.substring(memoryLine.indexOf("MemTotal:"));
            br.close();
            return subMemoryLine.replaceAll("\\D+", "") + " KB";
        } catch (IOException e) {
            e.printStackTrace();
        }
        return "";
    }

    /**
     * 获取当前可用内存(MB)
     *
     * @param context
     * @return
     */
    public static long getAvailableRam(Context context) {
        ActivityManager am = (ActivityManager) context.getSystemService(Context.ACTIVITY_SERVICE);
        ActivityManager.MemoryInfo memoryInfo = new ActivityManager.MemoryInfo();
        am.getMemoryInfo(memoryInfo);
        return memoryInfo.availMem / 1024 / 1024;
    }

    /**
     * 获取当前应用可用内存(MB)
     *
     * @return
     */
    public static long getAppRam() {
        long totalMemory = Runtime.getRuntime().totalMemory() / 1024 / 1024;
        return totalMemory;
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
    public static String getTimeZoneId() {
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

    /**
     * 获取APP是否在前台运行
     * 1: 前台
     * 2: 后台
     *
     * @param context
     * @return
     */
    public static String getAppOnForeground(Context context) {
        if (context != null) {
            ActivityManager activityManager = (ActivityManager) context.getSystemService(Context.ACTIVITY_SERVICE);
            List<ActivityManager.RunningAppProcessInfo> processes = activityManager.getRunningAppProcesses();
            for (ActivityManager.RunningAppProcessInfo processInfo : processes) {
                if (processInfo.processName.equals(context.getPackageName())) {
                    if (processInfo.importance == ActivityManager.RunningAppProcessInfo.IMPORTANCE_FOREGROUND) {
                        return "1";
                    }
                }
            }
        }
        return "2";
    }

    /**
     * 获取屏幕方向
     * 1: 竖屏
     * 2: 横屏
     *
     * @param context
     * @return
     */
    public static String getOrientation(Context context) {
        return "" + context.getResources().getConfiguration().orientation;
    }

    /**
     * 获取运营商
     *
     * @param context
     * @return
     */
    public static String getCarrierName(Context context) {
        TelephonyManager telephonyManager = (TelephonyManager) context.getSystemService(Context.TELEPHONY_SERVICE);
        return telephonyManager.getSimOperatorName();
    }

    /**
     * 获取网络状态
     *
     * @param context
     * @return
     */
    public static String getNetwork(Context context) {
        String network = "-1";
        try {
            ConnectivityManager cm = (ConnectivityManager) context.getSystemService(Context.CONNECTIVITY_SERVICE);
            NetworkInfo info = cm.getActiveNetworkInfo();
            if (info != null && info.isAvailable() && info.isConnected()) {
                if (info.getState() == NetworkInfo.State.CONNECTED) {
                    if (info.getTypeName().equals("WIFI")) {
                        network = "WIFI";
                    } else {
                        String strSubTypeName = info.getSubtypeName();
                        switch (info.getSubtype()) {
                            // 2G类型
                            case TelephonyManager.NETWORK_TYPE_GPRS:
                            case TelephonyManager.NETWORK_TYPE_CDMA:
                            case TelephonyManager.NETWORK_TYPE_EDGE:
                            case TelephonyManager.NETWORK_TYPE_1xRTT:
                            case TelephonyManager.NETWORK_TYPE_IDEN:
                                network = "2G";
                                break;
                            // 3G类型
                            case TelephonyManager.NETWORK_TYPE_EVDO_A:
                            case TelephonyManager.NETWORK_TYPE_UMTS:
                            case TelephonyManager.NETWORK_TYPE_EVDO_0:
                            case TelephonyManager.NETWORK_TYPE_HSDPA:
                            case TelephonyManager.NETWORK_TYPE_HSUPA:
                            case TelephonyManager.NETWORK_TYPE_HSPA:
                            case TelephonyManager.NETWORK_TYPE_EVDO_B:
                            case TelephonyManager.NETWORK_TYPE_EHRPD:
                            case TelephonyManager.NETWORK_TYPE_HSPAP:
                                network = "3G";
                                break;
                            // 4G类型
                            case TelephonyManager.NETWORK_TYPE_LTE:
                                network = "4G";
                                break;
                            default:
                                // 中国移动 联通 电信 三种3G制式
                                if (strSubTypeName.equalsIgnoreCase("TD-SCDMA") || strSubTypeName.equalsIgnoreCase("WCDMA") || strSubTypeName.equalsIgnoreCase("CDMA2000")) {
                                    network = "3G";
                                }
                                break;
                        }
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return network;
    }

}
