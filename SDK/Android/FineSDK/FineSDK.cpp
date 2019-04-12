//
//  FineSDK.cpp
//  FineSDK
//
//  Created by Cylee on 2019/2/19.
//  Copyright © 2019年 Cylee. All rights reserved.
//

#include "FineSDK.h"
#include "NDKHelper.h"

#include <android/log.h>
#define  LOG_TAG    "FineSDK_C++"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

static FineSDK* _protocol;
FineSDK* FineSDK::getInstance() {
    if (_protocol == NULL) {
        _protocol = new FineSDK();
    }
    return _protocol;
}

void FineSDK::registerListener(CallBackListener* listener){
    LOGD("registerListener");
    ProtocolFather::registerListener(listener);
}

void FineSDK::receiveCallBack(const char* params){
    LOGD("receiveCallBack: %s", params);
    ProtocolFather::receiveCallBack(params);
}

void FineSDK::callFunctionWithParams(const char* funcName, const char* params) {
    LOGD("callFunctionWithParams: funcName: %s | params: %s", funcName, params);
    SendMessageWithParams(string(funcName), params);
}

