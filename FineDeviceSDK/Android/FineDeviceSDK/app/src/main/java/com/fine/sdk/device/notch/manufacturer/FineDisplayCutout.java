package com.fine.sdk.device.notch.manufacturer;

import java.lang.reflect.Method;

import android.app.Activity;
import android.os.Build;
import android.util.Log;
import android.view.View;
import android.view.WindowInsets;
import android.view.WindowManager;

public class FineDisplayCutout {

    private Activity mActivity;
    private View mView;

    public FineDisplayCutout(Activity activity) {
        this.mActivity = activity;
        this.mView = activity.getWindow().getDecorView();
        openDisplayCutoutMode();
    }

    /**
     * 处理Android9.0挖孔屏问题
     */
    public void openDisplayCutoutMode() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
            WindowManager.LayoutParams lp = mActivity.getWindow()
                    .getAttributes();
            lp.layoutInDisplayCutoutMode = WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;
            mActivity.getWindow().setAttributes(lp);
            mActivity.getWindow().setFlags(
                    WindowManager.LayoutParams.FLAG_FULLSCREEN,
                    WindowManager.LayoutParams.FLAG_FULLSCREEN);
            mActivity.getWindow().addFlags(
                    WindowManager.LayoutParams.FLAG_TRANSLUCENT_NAVIGATION);
        }
    }

    private Object getDisplayCutout(View view) {
        if (view != null) {
            Log.d("DisplayCutOutTools", "Build.VERSION.SDK_INT:"
                    + android.os.Build.VERSION.SDK_INT);
            if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.O) {
                try {
                    WindowInsets windowInsets = view.getRootWindowInsets();
                    if (windowInsets != null) {
                        Method method = windowInsets.getClass()
                                .getDeclaredMethod("getDisplayCutout");
                        return method.invoke(windowInsets);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
        Log.d("DisplayCutOutTools", "getDisplayCutout is null.");
        return null;
    }

    /**
     * 获取顶部安全区域高度
     *
     * @return
     */
    public int getSafeInsetTop() {
        try {
            Object displayCutoutInstance = getDisplayCutout(mView);
            if (displayCutoutInstance != null) {
                Class<?> cls = displayCutoutInstance.getClass();
                return (Integer) cls.getDeclaredMethod("getSafeInsetTop")
                        .invoke(displayCutoutInstance);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return 0;
    }

    /**
     * 获取底部安全区域高度
     *
     * @return
     */
    public int getSafeInsetBottom() {
        try {
            Object displayCutoutInstance = getDisplayCutout(mView);
            if (displayCutoutInstance != null) {
                Class<?> cls = displayCutoutInstance.getClass();
                return (Integer) cls.getDeclaredMethod("getSafeInsetBottom")
                        .invoke(displayCutoutInstance);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return 0;
    }

    /**
     * 获取左部安全区域高度
     *
     * @return
     */
    public int getSafeInsetLeft() {
        try {
            Object displayCutoutInstance = getDisplayCutout(mView);
            if (displayCutoutInstance != null) {
                Class<?> cls = displayCutoutInstance.getClass();
                return (Integer) cls.getDeclaredMethod("getSafeInsetLeft")
                        .invoke(displayCutoutInstance);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return 0;
    }

    /**
     * 获取右部安全区域高度
     *
     * @return
     */
    public int getSafeInsetRight() {
        try {
            Object displayCutoutInstance = getDisplayCutout(mView);
            if (displayCutoutInstance != null) {
                Class<?> cls = displayCutoutInstance.getClass();
                return (Integer) cls.getDeclaredMethod("getSafeInsetRight")
                        .invoke(displayCutoutInstance);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return 0;
    }

}
