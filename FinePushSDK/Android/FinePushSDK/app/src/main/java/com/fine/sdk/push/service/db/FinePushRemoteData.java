package com.fine.sdk.push.service.db;

import org.json.JSONObject;

import com.fine.sdk.push.FinePushSDK;
import com.fine.sdk.push.service.tools.FinePushTools;

import android.content.Context;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.os.Parcel;
import android.os.Parcelable;
import android.text.TextUtils;

public class FinePushRemoteData implements Parcelable {

    public FinePushRemoteData() {
    }

    private String appID;
    private String appKey;
    private String uuid;
    private String host;
    private int port;

    private String receivedID;
    private int pushState;

    public String getAppID() {
        return appID;
    }

    public void setAppID(String appID) {
        this.appID = appID;
    }

    public String getAppKey() {
        return appKey;
    }

    public void setAppKey(String appKey) {
        this.appKey = appKey;
    }

    public String getUuid() {
        return uuid;
    }

    public void setUuid(String uuid) {
        this.uuid = uuid;
    }

    public String getHost() {
        return host;
    }

    public void setHost(String host) {
        this.host = host;
    }

    public int getPort() {
        return port;
    }

    public void setPort(int port) {
        this.port = port;
    }

    public String getReceivedID() {
        return receivedID;
    }

    public void setReceivedID(String receivedID) {
        this.receivedID = receivedID;
    }

    public int getPushState() {
        return pushState;
    }

    public void setPushState(int pushState) {
        this.pushState = pushState;
    }

    public synchronized String toString() {
        String curTime = "" + System.currentTimeMillis() / 1000;
        JSONObject json = new JSONObject();
        try {
            json.put("Version", FinePushSDK.VERSION);
            json.put("Type", "1");
            json.put("OS", "android");
            json.put("AppID", getAppID());
            json.put("UUID", getUuid());
            json.put("TimeStamp", curTime);
            json.put("Signature", FinePushTools.getMD5(getAppID() + "#" + getAppKey() + curTime));

            json.put("DeviceBrand", FinePushTools.getDeviceBrand());
            json.put("DeviceModel", FinePushTools.getSystemModel());
            json.put("SystemVersion", FinePushTools.getSystemVersion());

            if (!TextUtils.isEmpty(getReceivedID())) {
                json.put("ReceivedId", getReceivedID());
                setReceivedID("");
            }

            if (getPushState() > 0) {
                json.put("PushState", getPushState());
                setPushState(0);
            }

//			info = FinePushRSA.encrypt(json.toString(), FinePushRSA.PUBLIC_KEY_STR_GO);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return json.toString();
    }

    public void update(FinePushRemoteData data) {
        setAppID(data.getAppID());
        setAppKey(data.getAppKey());
        setUuid(data.getUuid());
        setHost(data.getHost());
        setPort(data.getPort());
    }

    public void write(Context context) {
        SharedPreferences sp = context.getSharedPreferences("FinePush", Context.MODE_PRIVATE);
        Editor editor = sp.edit();
        editor.putString("AppID", getAppID());
        editor.putString("AppKey", getAppKey());
        editor.putString("UUID", getUuid());
        editor.putString("Host", getHost());
        editor.putInt("Port", getPort());
        editor.apply();
    }

    public void read(Context context) {
        SharedPreferences sp = context.getSharedPreferences("FinePush", Context.MODE_PRIVATE);
        setAppID(sp.getString("AppID", ""));
        setAppKey(sp.getString("AppKey", ""));
        setUuid(sp.getString("UUID", ""));
        setHost(sp.getString("Host", ""));
        setPort(sp.getInt("Port", 0));
    }

    public static final Creator<FinePushRemoteData> CREATOR = new Creator<FinePushRemoteData>() {
        @Override
        public FinePushRemoteData createFromParcel(Parcel in) {
            return new FinePushRemoteData(in);
        }

        @Override
        public FinePushRemoteData[] newArray(int size) {
            return new FinePushRemoteData[size];
        }
    };

    protected FinePushRemoteData(Parcel in) {
        appID = in.readString();
        appKey = in.readString();
        uuid = in.readString();
        host = in.readString();
        port = in.readInt();
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeString(appID);
        dest.writeString(appKey);
        dest.writeString(uuid);
        dest.writeString(host);
        dest.writeInt(port);
    }

    @Override
    public int describeContents() {
        return 0;
    }

}
