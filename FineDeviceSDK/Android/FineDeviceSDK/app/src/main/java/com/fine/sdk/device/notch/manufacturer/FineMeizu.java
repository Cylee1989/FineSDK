package com.fine.sdk.device.notch.manufacturer;

import java.lang.reflect.Field;

import android.provider.Settings;

public class FineMeizu extends FineManufacturerFather {

    @Override
    public boolean isSupportNotch() {
        boolean fringeDevice = false;
        try {
            Class<?> clazz = Class.forName("flyme.config.FlymeFeature");
            Field field = clazz.getDeclaredField("IS_FRINGE_DEVICE");
            fringeDevice = (Boolean) field.get(null);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return fringeDevice;
    }

    @Override
    public boolean isHideNotch() {
        // 判断隐藏刘海开关(默认关)
        return Settings.Global.getInt(activity.getContentResolver(),
                "mz_fringe_hide", 0) == 1;
    }

    @Override
    public int getNotchWidth() {
        int fringeWidth = 0;
        int fhid = activity.getResources().getIdentifier("fringe_width",
                "dimen", "android");
        if (fhid > 0) {
            fringeWidth = activity.getResources().getDimensionPixelSize(fhid);
        }
        return fringeWidth;
    }

    @Override
    public int getNotchHeigth() {
        int fringeHeight = 0;
        int fhid = activity.getResources().getIdentifier("fringe_height",
                "dimen", "android");
        if (fhid > 0) {
            fringeHeight = activity.getResources().getDimensionPixelSize(fhid);
        }
        return fringeHeight;
    }

}
