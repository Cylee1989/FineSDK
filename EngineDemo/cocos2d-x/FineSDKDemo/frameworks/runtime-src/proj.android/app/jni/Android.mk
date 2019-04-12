LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE:=FineSDK
LOCAL_SRC_FILES := ../../../Classes/FineSDK/android/libFineSDK.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dlua_shared

LOCAL_MODULE_FILENAME := libcocos2dlua

LOCAL_SRC_FILES :=  hellolua/main.cpp \
                    ../../../Classes/AppDelegate.cpp \
                    ../../../Classes/FineSDK/tolua/FineLuaLoader.cpp \
                    ../../../Classes/FineSDK/tolua/LuaPlatform.cpp \

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes \
                    $(LOCAL_PATH)/../../../Classes/FineSDK/android/include \
                    $(LOCAL_PATH)/../../../Classes/FineSDK/tolua \

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END

LOCAL_STATIC_LIBRARIES := cclua_static
LOCAL_STATIC_LIBRARIES += FineSDK

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module, cocos/scripting/lua-bindings/proj.android)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
