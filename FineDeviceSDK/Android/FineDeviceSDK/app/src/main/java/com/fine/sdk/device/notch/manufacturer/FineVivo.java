package com.fine.sdk.device.notch.manufacturer;

import java.lang.reflect.Method;

import com.fine.sdk.device.info.FineDeviceInfo;

import android.content.res.Configuration;
import android.graphics.Point;
import android.os.Build;

/**
 * 在AndroidManifest.xml中配置
 * <p>
 * <meta-data android:name="android.vendor.home_indicator"android:value="hide"/>
 * 隐藏导航栏
 * <p>
 * <meta-data android:name="android.vendor.full_screen" android:value="true" />
 * 全屏显示
 * <p>
 * 在对应的Activity中添加下面的meta用于隐藏导航条 <meta-data
 * android:name="android.vendor.home_indicator" android:value="hide" />
 *
 * @author Cylee
 */
public class FineVivo extends FineManufacturerFather {


    /**
     * 0x00000020表示是否有凹槽
     * 0x00000008表示是否有圆角
     *
     * @return
     */
    @Override
    public boolean isSupportNotch() {
        try {
            Class<?> mClass = Class.forName("android.util.FtFeature");
            Method[] methods = mClass.getDeclaredMethods();
            Method method = null;
            for (Method m : methods) {
                if (m.getName().equalsIgnoreCase("isFeatureSupport")) {
                    method = m;
                    break;
                }
            }

            return (Boolean) method.invoke(null, 0x00000020);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return false;
    }

    @Override
    public boolean isHideNotch() {
        Point pReal = getPhysicalResolution();
        Point pShot = FineDeviceInfo.getShotScreenSize(activity);
        int realSize = pReal.x > pReal.y ? pReal.x : pReal.y;
        int shotSize = pShot.x > pShot.y ? pShot.x : pShot.y;
        int statusBarHeigth = FineDeviceInfo.getStatusBarHeight(activity);
        // 设备分辨率-截图分辨率=状态栏，则代表隐藏刘海
        int off = realSize - shotSize;
        if (off == statusBarHeigth || off == statusBarHeigth + 1
                || off == statusBarHeigth - 1) {
            return true;
        }
        // 如果是横屏游戏
        if (activity.getResources().getConfiguration().orientation == Configuration.ORIENTATION_LANDSCAPE) {
            // 如果设备是IQOO，设备分辨率-截图分辨率=73，则代表隐藏刘海
            String model = Build.MODEL;
            if (model.contains("V1824") && realSize - shotSize == 73) {
                return true;
            }
        }
        return false;
    }

    @Override
    public int getNotchWidth() {
        if (isSupportNotch()) {
            int statusBarHeight = FineDeviceInfo.getStatusBarHeight(activity);
            return statusBarHeight * 100 / 32;
        }
        return 0;
    }

    @Override
    public int getNotchHeigth() {
        if (isSupportNotch()) {
            int statusBarHeight = FineDeviceInfo.getStatusBarHeight(activity);
            return statusBarHeight * 27 / 32;
        }
        return 0;
    }

    @Override
    public Point getPhysicalResolution() {
        int statusBarHeight = FineDeviceInfo.getStatusBarHeight(activity);
        int navigationBarHeight = FineDeviceInfo
                .getNavigationBarHeight(activity);
        Point pReal = FineDeviceInfo.getRealScreenSize(activity);
        Point pShot = FineDeviceInfo.getShotScreenSize(activity);
        int realSize = pReal.x > pReal.y ? pReal.x : pReal.y;
        int shotSize = pShot.x > pShot.y ? pShot.x : pShot.y;
        // 由于vivo系统的问题，如果获取的真实分辨率-截图分辨率=状态栏+导航条的高度，则使用显示分辨率
        if (realSize - shotSize == statusBarHeight + navigationBarHeight) {
            return FineDeviceInfo.getDisplayScreenSize(activity);
        }
        return pReal;
    }

}
