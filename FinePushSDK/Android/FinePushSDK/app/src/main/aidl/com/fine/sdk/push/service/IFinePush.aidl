package com.fine.sdk.push.service;

import com.fine.sdk.push.service.db.FinePushLocalData;
import com.fine.sdk.push.service.db.FinePushRemoteData;

interface IFinePush {

    void addLocalPush(in FinePushLocalData data);

    void clearLocalPushByKey(String key);

    void clearAllLocalPush();

    void registerRemotePush(in FinePushRemoteData data);

}
