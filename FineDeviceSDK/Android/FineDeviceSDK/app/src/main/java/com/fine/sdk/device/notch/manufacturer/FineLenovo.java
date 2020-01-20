package com.fine.sdk.device.notch.manufacturer;

import com.fine.sdk.device.info.FineDeviceInfo;

import android.graphics.Point;

public class FineLenovo extends FineManufacturerFather {

    @Override
    public boolean isSupportNotch() {
        int resourceId = activity.getResources().getIdentifier(
                "config_screen_has_notch", "bool", "android");
        if (resourceId > 0) {
            return activity.getResources().getBoolean(resourceId);
        }
        return false;
    }

    @Override
    public boolean isHideNotch() {
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

    @Override
    public int getNotchWidth() {
        int result = 0;
        int resourceId = activity.getResources().getIdentifier("notch_w",
                "integer", "android");
        if (resourceId > 0) {
            result = activity.getResources().getInteger(resourceId);
        }
        return result;
    }

    @Override
    public int getNotchHeigth() {
        int result = 0;
        int resourceId = activity.getResources().getIdentifier("notch_h",
                "integer", "android");
        if (resourceId > 0) {
            result = activity.getResources().getInteger(resourceId);
        }
        return result;
    }

}
