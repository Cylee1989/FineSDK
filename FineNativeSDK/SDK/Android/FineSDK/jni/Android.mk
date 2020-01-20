LOCAL_PATH := $(call my-dir)/../../../

include $(CLEAR_VARS)

LOCAL_MODULE := FineSDK
LOCAL_MODULE_FILENAME :=libFineSDK
LOCAL_ARM_MODE := arm

define all-cpp-files
$(patsubst $(LOCAL_PATH)/%,%, $(shell find $(LOCAL_PATH)/Android/FineSDK/ $(LOCAL_PATH)/Classes -name  "*.c*" ! -path "$(LOCAL_PATH)/Classes/cocos2d-x/*" | grep -v '.svn'))
endef

LOCAL_SRC_FILES := $(call all-cpp-files) 

LOCAL_C_INCLUDES := $(LOCAL_PATH)/Classes/ \
					$(LOCAL_PATH)/Android/FineSDK/ \
                    $(LOCAL_PATH)/Android/FineSDK/json/ \
                    $(LOCAL_PATH)/Android/FineSDK/jansson/ \
					$(LOCAL_PATH)/Android/FineSDK/NDKHelper/ \
                           
LOCAL_LDLIBS := -llog -lz
LOCAL_LDLIBS += -landroid

include $(BUILD_SHARED_LIBRARY)

# Done.
