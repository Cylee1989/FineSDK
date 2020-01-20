package com.fine.sdk.device.notch.manufacturer;

import java.lang.ref.WeakReference;
import java.lang.reflect.Method;

import android.app.Activity;
import android.os.Build;
import android.os.Handler;
import android.os.Message;
import android.provider.Settings;
import android.view.Window;

/**
 * 在AndroidManifest.xml中配置
 * <p>
 * <meta-data android:name="notch.config" android:value="portrait|landscape"/>
 * 横竖屏都绘制到耳朵区
 * <p>
 * <meta-data android:name="notch.config" android:value="none"/> 不绘制到耳朵区
 *
 * @author Cylee
 */
public class FineXiaomi extends FineManufacturerFather {

    private FineXiaoMiHandler mHandler;

    @Override
    public void init(Activity activity) {
        super.init(activity);
        mHandler = new FineXiaoMiHandler(this, activity);
    }

    @Override
    public boolean isSupportNotch() {
        try {
            Class<?> mClassType = Class.forName("android.os.SystemProperties");
            Method mGetIntMethod = mClassType.getDeclaredMethod("getInt",
                    String.class, int.class);
            Integer v = (Integer) mGetIntMethod.invoke(mClassType,
                    "ro.miui.notch", 0);
            return v.intValue() == 1;
        } catch (Exception e) {
            e.printStackTrace();
        }
        return false;
    }

    @Override
    public boolean isHideNotch() {
        return Settings.Global.getInt(activity.getContentResolver(),
                "force_black", 0) == 1;
    }

    @Override
    public int getNotchWidth() {
        // 如果不具备特性，则返回0
        if (!isSupportNotch()) {
            return 0;
        }

        // 如果隐藏了刘海，则设置不使用耳朵区
        if (isHideNotch()) {
            Message msg = new Message();
            msg.obj = "clearExtraFlags";
            mHandler.sendMessage(msg);
            return 0;
        }

        // 如果显示刘海，则设置使用耳朵区
        Message msg = new Message();
        msg.obj = "addExtraFlags";
        mHandler.sendMessage(msg);

        String model = Build.MODEL;
        if (model.contains("MI8Lite")) {
            return 296;
        }
        if (model.contains("Redmi 6 Pro")) {
            return 352;
        }
        if (model.contains("MI 8 SE")) {
            return 540;
        }
        if (model.contains("MI 8") || model.contains("MI 8 Explorer Edition")
                || model.contains("MI 8 UD")) {
            return 560;
        }
        if (model.contains("POCO F1")) {
            return 588;
        }

        int result = 0;
        int resourceId = activity.getResources().getIdentifier("notch_width",
                "dimen", "android");
        if (resourceId > 0) {
            result = activity.getResources().getDimensionPixelSize(resourceId);
        }
        return result;
    }

    @Override
    public int getNotchHeigth() {
        // 如果不具备特性，则返回0
        if (!isSupportNotch()) {
            return 0;
        }

        // 如果隐藏了刘海，则设置不使用耳朵区
        if (isHideNotch()) {
            Message msg = new Message();
            msg.obj = "clearExtraFlags";
            mHandler.sendMessage(msg);
            return 0;
        }

        // 如果显示刘海，则设置使用耳朵区
        Message msg = new Message();
        msg.obj = "addExtraFlags";
        mHandler.sendMessage(msg);

        String model = Build.MODEL;
        if (model.contains("MI8Lite")) {
            return 82;
        }
        if (model.contains("MI 8 SE")) {
            return 85;
        }
        if (model.contains("POCO F1")) {
            return 86;
        }
        if (model.contains("MI 8") || model.contains("MI 8 Explorer Edition")
                || model.contains("MI 8 UD") || model.contains("Redmi 6 Pro")) {
            return 89;
        }
        if (model.contains("MI 9")) {
            return 89;
        }

        int result = 0;
        int resourceId = activity.getResources().getIdentifier("notch_height",
                "dimen", "android");
        if (resourceId > 0) {
            result = activity.getResources().getDimensionPixelSize(resourceId);
        }
        return result;
    }

    private static class FineXiaoMiHandler extends Handler {
        private final WeakReference<FineXiaomi> contextWeakReference;
        private Activity activity;

        public FineXiaoMiHandler(FineXiaomi context, Activity act) {
            contextWeakReference = new WeakReference<FineXiaomi>(context);
            activity = act;
        }

        @Override
        public void handleMessage(Message msg) {
            FineXiaomi fineXiaomi = contextWeakReference.get();
            if (fineXiaomi != null) {
                String cmd = (String) msg.obj;
                try {
                    // 此方法需要在主线程上调用，否则会崩溃。
                    Method method = Window.class.getMethod(cmd, int.class);
                    method.invoke(activity.getWindow(),
                            0x00000100 | 0x00000200 | 0x00000400);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }

    }

}
