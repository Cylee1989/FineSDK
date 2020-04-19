package com.fine.sdk.crash.android.http.impl;

/**
 * 日志上报回调接口
 *
 * @author Cylee
 */
public interface FineCrashHttpCallBack {

    /**
     * 回调成功
     *
     * @param jsonString
     */
    void onSuccess(String jsonString);

    /**
     * 回调失败
     */
    void onFailure();

}
