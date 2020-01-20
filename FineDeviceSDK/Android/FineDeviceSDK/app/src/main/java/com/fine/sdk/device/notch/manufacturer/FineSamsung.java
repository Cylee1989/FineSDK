package com.fine.sdk.device.notch.manufacturer;

import android.content.res.Configuration;
import android.content.res.Resources;
import android.text.TextUtils;

public class FineSamsung extends FineManufacturerFather {

    @Override
    public boolean isSupportNotch() {
        try {
            final Resources res = activity.getResources();
            final int resId = res.getIdentifier(
                    "config_mainBuiltInDisplayCutout", "string", "android");
            final String spec = resId > 0 ? res.getString(resId) : null;
            return spec != null && !TextUtils.isEmpty(spec);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return false;
    }

    @Override
    public boolean isHideNotch() {
        int orientation = activity.getResources().getConfiguration().orientation;
        if (orientation == Configuration.ORIENTATION_PORTRAIT) {
            int top = fineDisplayCutout.getSafeInsetTop();
            int bottom = fineDisplayCutout.getSafeInsetBottom();
            return top > 0 || bottom > 0 ? false : true;
        }

        int left = fineDisplayCutout.getSafeInsetLeft();
        int right = fineDisplayCutout.getSafeInsetRight();
        return left > 0 || right > 0 ? false : true;
    }

    @Override
    public int getNotchHeigth() {
        if (isSupportNotch()) {
            int orientation = activity.getResources().getConfiguration().orientation;
            if (orientation == Configuration.ORIENTATION_PORTRAIT) {
                int top = fineDisplayCutout.getSafeInsetTop();
                int bottom = fineDisplayCutout.getSafeInsetBottom();
                return top > bottom ? top : bottom;
            }

            int left = fineDisplayCutout.getSafeInsetLeft();
            int right = fineDisplayCutout.getSafeInsetRight();
            return left > right ? left : right;
        }
        return 0;
    }

}
