package com.fine.sdk.device.notch;

import android.app.Activity;
import android.graphics.Point;
import android.os.Build;
import android.view.View;

import com.fine.sdk.device.notch.manufacturer.FineHuawei;
import com.fine.sdk.device.notch.manufacturer.FineLenovo;
import com.fine.sdk.device.notch.manufacturer.FineManufacturerFather;
import com.fine.sdk.device.notch.manufacturer.FineMeizu;
import com.fine.sdk.device.notch.manufacturer.FineNubia;
import com.fine.sdk.device.notch.manufacturer.FineOnePlus;
import com.fine.sdk.device.notch.manufacturer.FineOppo;
import com.fine.sdk.device.notch.manufacturer.FineSamsung;
import com.fine.sdk.device.notch.manufacturer.FineVivo;
import com.fine.sdk.device.notch.manufacturer.FineXiaomi;

public class FineDeviceNotch {

    public static final String VERSION = "1.0.0";

    private static FineDeviceNotch instance = null;

    public static FineDeviceNotch getInstance() {
        if (instance == null) {
            synchronized (FineDeviceNotch.class) {
                if (instance == null) {
                    instance = new FineDeviceNotch();
                }
            }
        }
        return instance;
    }

    private Activity mActivity;
    private View mView;
    private FineManufacturerFather mManufacturerFather;

    /**
     * 初始化
     *
     * @param activity
     */
    public void init(Activity activity) {
        this.mActivity = activity;
        this.mView = activity.getWindow().getDecorView();
        initDeviceFather();
    }

    /**
     * 初始化设备厂商对象
     */
    private void initDeviceFather() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {
            String manufacturer = Build.MANUFACTURER.toLowerCase();
            if (manufacturer.contains("vivo")) {
                mManufacturerFather = new FineVivo();
            } else if (manufacturer.contains("oppo")) {
                mManufacturerFather = new FineOppo();
            } else if (manufacturer.contains("oneplus")) {
                mManufacturerFather = new FineOnePlus();
            } else if (manufacturer.contains("huawei")) {
                mManufacturerFather = new FineHuawei();
            } else if (manufacturer.contains("xiaomi")) {
                mManufacturerFather = new FineXiaomi();
            } else if (manufacturer.contains("lenovo")
                    || manufacturer.contains("moto")) {
                mManufacturerFather = new FineLenovo();
            } else if (manufacturer.contains("meizu")) {
                mManufacturerFather = new FineMeizu();
            } else if (manufacturer.contains("nubia")) {
                mManufacturerFather = new FineNubia();
            } else if (manufacturer.contains("samsung")) {
                mManufacturerFather = new FineSamsung();
            }
        }

        if (mManufacturerFather == null) {
            mManufacturerFather = new FineManufacturerFather() {
            };
        }
        mManufacturerFather.init(mActivity);
    }

    /**
     * 是否支持刘海屏
     *
     * @return
     */
    public boolean isSupportNotch() {
        return mManufacturerFather.isSupportNotch();
    }

    /**
     * 是否隐藏刘海
     *
     * @return
     */
    public boolean isHideNotch() {
        return mManufacturerFather.isHideNotch();
    }

    /**
     * 刘海宽度
     *
     * @return
     */
    public int getNotchWidth() {
        return mManufacturerFather.getNotchWidth();
    }

    /**
     * 刘海高度
     *
     * @return
     */
    public int getNotchHeigth() {
        return mManufacturerFather.getNotchHeigth();
    }

    public Point getPhysicalResolution() {
        return mManufacturerFather.getPhysicalResolution();
    }

    /**
     * 屏幕发生变化生命周期
     *
     * @param hasFocus
     */
    public void onWindowFocusChanged(boolean hasFocus) {
        if (hasFocus) {
            int uiOptions = View.SYSTEM_UI_FLAG_LAYOUT_STABLE
                    | View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
                    | View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN
                    | View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
                    | View.SYSTEM_UI_FLAG_FULLSCREEN;
            if (Build.VERSION.SDK_INT >= 19) {
                uiOptions |= View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY;
            }
            if (mView.getSystemUiVisibility() != uiOptions) {
                mView.setSystemUiVisibility(uiOptions);
            }
        }
    }

}
