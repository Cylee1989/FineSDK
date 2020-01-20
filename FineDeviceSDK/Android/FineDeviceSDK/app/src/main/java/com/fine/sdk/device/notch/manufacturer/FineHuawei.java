package com.fine.sdk.device.notch.manufacturer;

import java.lang.reflect.Method;

import com.fine.sdk.device.info.FineDeviceInfo;

import android.graphics.Point;
import android.provider.Settings;

/**
 * 需要再AndroidManifest.xml中配置
 * <p>
 * <meta-data android:name="android.notch_support" android:value="true"/>
 *
 * @author Cylee
 */
public class FineHuawei extends FineManufacturerFather {

    @Override
    public boolean isSupportNotch() {
        try {
            ClassLoader cl = activity.getClassLoader();
            Class<?> HwNotchSizeUtil = cl
                    .loadClass("com.huawei.android.util.HwNotchSizeUtil");
            Method get = HwNotchSizeUtil.getMethod("hasNotchInScreen");
            return (Boolean) get.invoke(HwNotchSizeUtil);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return false;
    }

    @Override
    public boolean isHideNotch() {
        boolean isHide = Settings.Secure.getInt(activity.getContentResolver(),
                "display_notch_status", 0) == 1;
        if (!isHide) {
            Point pReal = FineDeviceInfo.getRealScreenSize(activity);
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
            return false;
        }
        return true;
    }

    @Override
    public int getNotchWidth() {
        return getNotchSize()[0];
    }

    @Override
    public int getNotchHeigth() {
        return getNotchSize()[1];
    }

    private int[] getNotchSize() {
        int[] ret = new int[]{0, 0};
        try {
            ClassLoader cl = activity.getClassLoader();
            Class<?> HwNotchSizeUtil = cl
                    .loadClass("com.huawei.android.util.HwNotchSizeUtil");
            Method get = HwNotchSizeUtil.getMethod("getNotchSize");
            ret = (int[]) get.invoke(HwNotchSizeUtil);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return ret;
    }
}
