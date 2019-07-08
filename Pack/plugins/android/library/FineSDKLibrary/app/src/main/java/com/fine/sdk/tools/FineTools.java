package com.fine.sdk.tools;

import android.content.Context;
import android.content.res.AssetManager;

import java.io.IOException;

/**
 * Created by Cylee on 2019/4/24.
 */

public class FineTools {

    /**
     * 根据手机的分辨率从 dp 的单位 转成为 px(像素)
     */
    public static int dip2px(Context context, float dpValue) {
        final float scale = context.getResources().getDisplayMetrics().density;
        return (int) (dpValue * scale + 0.5f);
    }

    /**
     * 根据手机的分辨率从 px(像素) 的单位 转成为 dp
     */
    public static int px2dip(Context context, float pxValue) {
        final float scale = context.getResources().getDisplayMetrics().density;
        return (int) (pxValue / scale + 0.5f);
    }

    /**
     * 判断是否有文件存在在Assets目录下
     *
     * @param context
     * @param path
     * @return
     */
    public static boolean isFileExistInAssets(Context context, String path, String file) {
        AssetManager am = context.getAssets();
        try {
            String[] name = am.list(path);
            for (int i = 0; i < name.length; i++) {
                if (name[i].equals(file)) {
                    return true;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return false;
    }

}
