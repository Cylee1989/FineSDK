package com.fine.sdk.device.notch.manufacturer;

import com.fine.sdk.device.info.FineDeviceInfo;

import android.app.Activity;
import android.graphics.Point;

public abstract class FineManufacturerFather {

    protected String TAG = "FineDeviceScreen";
    protected Activity activity;
    protected FineDisplayCutout fineDisplayCutout;

    /**
     * 初始化
     *
     * @param activity
     */
    public void init(Activity activity) {
        this.activity = activity;
        this.fineDisplayCutout = new FineDisplayCutout(activity);
    }

    /**
     * 是否支持刘海
     *
     * @return
     */
    public boolean isSupportNotch() {
        return false;
    }

    /**
     * 是否隐藏刘海
     *
     * @return
     */
    public boolean isHideNotch() {
        return false;
    }

    /**
     * 刘海宽度
     *
     * @return
     */
    public int getNotchWidth() {
        return 0;
    }

    /**
     * 刘海高度
     *
     * @return
     */
    public int getNotchHeigth() {
        return 0;
    }

    /**
     * 获取设备物理分辨率(Physical Size)
     *
     * @return
     */
    public Point getPhysicalResolution() {
        return FineDeviceInfo.getRealScreenSize(activity);
    }

}
