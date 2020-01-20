package com.fine.sdk.push.service.db;

import android.os.Parcel;
import android.os.Parcelable;

public class FinePushLocalData implements Parcelable {

    public FinePushLocalData() {
    }

    private String key;
    private String message;
    private long time;
    private int repeatInterval;
    private String soundName;
    private Runnable runnable;

    public String getKey() {
        return key;
    }

    public void setKey(String key) {
        this.key = key;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public long getTime() {
        return time;
    }

    public void setTime(long time) {
        this.time = time;
    }

    public int getRepeatInterval() {
        return repeatInterval;
    }

    public void setRepeatInterval(int repeatInterval) {
        this.repeatInterval = repeatInterval;
    }

    public String getSoundName() {
        return soundName;
    }

    public void setSoundName(String soundName) {
        this.soundName = soundName;
    }

    public Runnable getRunnable() {
        return runnable;
    }

    public void setRunnable(Runnable runnable) {
        this.runnable = runnable;
    }

    public String toString() {
        String info = "FinePushLocalData:";
        info += "\n标识符: " + getKey();
        info += "\n推送内容: " + getMessage();
        info += "\n推送时间: " + getTime();
        info += "\n推荐间隔: " + getRepeatInterval();
        info += "\n声音名称: " + getSoundName();
        return info;
    }

    public static final Creator<FinePushLocalData> CREATOR = new Creator<FinePushLocalData>() {
        @Override
        public FinePushLocalData createFromParcel(Parcel in) {
            return new FinePushLocalData(in);
        }

        @Override
        public FinePushLocalData[] newArray(int size) {
            return new FinePushLocalData[size];
        }
    };

    protected FinePushLocalData(Parcel in) {
        key = in.readString();
        message = in.readString();
        time = in.readLong();
        repeatInterval = in.readInt();
        soundName = in.readString();
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeString(key);
        dest.writeString(message);
        dest.writeLong(time);
        dest.writeInt(repeatInterval);
        dest.writeString(soundName);
    }

    @Override
    public int describeContents() {
        return 0;
    }

}
