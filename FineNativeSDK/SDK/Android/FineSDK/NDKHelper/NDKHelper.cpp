//
//  NDKHelper.cpp
//  FineSDK
//
//  Created by Cylee on 2019/2/21.
//  Copyright © 2019年 Cylee. All rights reserved.
//

#include "NDKHelper.h"
#include "JNIHelper.h"
#include "FineSDK.h"
#include "jansson.h"
#include "json/json.h"
#include <android/log.h>

#define __NDK_CLASS_NAME__          "com/fine/ndk/NDKHelper"
#define __CALLED_METHOD__           "calling_method_name"
#define __CALLED_METHOD_PARAMS__    "calling_method_params"

#define  LOG_TAG    "NDKHelper_C++"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

extern "C" {
    // Method for receiving NDK messages from Java, Android
    void Java_com_fine_ndk_NDKHelper_NativeCallHandler(JNIEnv* env, jobject thiz, jstring json) {
        string jsonString = JNIHelper::jstring2string(json);
        const char *jsonCharArray = jsonString.c_str();
        LOGD("NativeCallHandler %s", jsonCharArray);
        
        json_error_t error;
        json_t *root;
        root = json_loads(jsonCharArray, 0, &error);
        
        if (!root) {
            fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);
            return;
        }
        
        json_t *jsonMethodName, *jsonMethodParams;
        jsonMethodName = json_object_get(root, __CALLED_METHOD__);
        jsonMethodParams = json_object_get(root, __CALLED_METHOD_PARAMS__);
        
        const char *methodNameStr = json_string_value(jsonMethodName);
        const char *methodParamsStr = json_string_value(jsonMethodParams);

        FineSDK::getInstance()->receiveCallBack(methodParamsStr);
    }
    
    void SendMessageWithParams(string methodName, string methodParams) {
        json_t *transformJson = json_object();
        json_object_set_new(transformJson, __CALLED_METHOD__, json_string(methodName.c_str()));
        json_object_set_new(transformJson, __CALLED_METHOD_PARAMS__, json_string(methodParams.c_str()));
        
        std::string ret;
        JNIMethodInfo t;

        if (JNIHelper::getStaticMethodInfo(t, __NDK_CLASS_NAME__, "receiveFromNative", "(Ljava/lang/String;)V")) {
            char* jsonStrLocal = json_dumps(transformJson, JSON_COMPACT | JSON_ENSURE_ASCII);
            string jsonStr(jsonStrLocal);
            free(jsonStrLocal);
            
            jstring stringArg = t.env->NewStringUTF(jsonStr.c_str());
            t.env->CallStaticVoidMethod(t.classID, t.methodID, stringArg);
            t.env->DeleteLocalRef(stringArg);
            t.env->DeleteLocalRef(t.classID);
        } else {
            LOGD("SendMessageWithParams not found methodName %s", methodName.c_str());
        }
    }
    
}
