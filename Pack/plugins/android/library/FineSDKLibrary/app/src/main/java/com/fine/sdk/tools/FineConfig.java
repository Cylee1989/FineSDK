package com.fine.sdk.tools;

import android.content.Context;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

/**
 * Created by Cylee on 2019/7/2.
 */

public class FineConfig {

    private static FineConfig instance = new FineConfig();

    public static FineConfig getInstance() {
        return instance;
    }

    private JSONObject jsonObject_app = new JSONObject();
    private JSONObject jsonObject_platform = new JSONObject();

    /**
     * 读取FineSDK文件夹下fine_app.json和fine_platform.json文件
     *
     * @param context
     */
    public void load(Context context) {
        jsonObject_app = loadJsonFile(context, "FineSDK/fine_app.json");
        jsonObject_platform = loadJsonFile(context, "FineSDK/fine_platform.json");
    }

    public JSONObject getAppJsonObject() {
        return jsonObject_app;
    }

    public JSONObject getPlatformJsonObject() {
        return jsonObject_platform;
    }

    private JSONObject loadJsonFile(Context context, String filePath) {
        JSONObject jsonObject = new JSONObject();
        try {
            StringBuilder stringBuilder = new StringBuilder();
            InputStream inputStream = context.getResources().getAssets().open(filePath);
            InputStreamReader isr = new InputStreamReader(inputStream);
            BufferedReader reader = new BufferedReader(isr);
            String jsonLine;
            while ((jsonLine = reader.readLine()) != null) {
                stringBuilder.append(jsonLine);
            }
            reader.close();
            isr.close();
            inputStream.close();
            String json = String.valueOf(stringBuilder);

            jsonObject = new JSONObject(json);
            FineLog.d("FineConfig", "Load " + filePath + " Success:\n" + jsonObject.toString());
        } catch (Exception e) {
            FineLog.d("FineConfig", "Load " + filePath + " Failed:\n" + e.toString());
        }

        return jsonObject;
    }

}
