#include <stdio.h>
#include <jni.h>
#include <android/log.h>

#include "client/linux/handler/exception_handler.h"
#include "client/linux/handler/minidump_descriptor.h"

#define LOG_TAG "FineCrashSDK_Cpp"
#define ALOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    return JNI_VERSION_1_6;
}

bool DumpCallback(const google_breakpad::MinidumpDescriptor &descriptor,
                  void *context,
                  bool succeeded) {
    ALOGD("DumpFile: %s\n", descriptor.path());
    return succeeded;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_fine_sdk_crash_android_FineCrashSDK_initNative(JNIEnv *env, jclass clazz, jstring dir_) {
    const char *dir = env->GetStringUTFChars(dir_, 0);
    ALOGD("DumpDir: %s\n", dir);

    google_breakpad::MinidumpDescriptor descriptor(dir);
    static google_breakpad::ExceptionHandler eh(descriptor, NULL, DumpCallback, NULL, true, -1);
    env->ReleaseStringUTFChars(dir_, dir);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_fine_sdk_crash_android_FineCrashSDK_crash(JNIEnv *env, jclass clazz) {
    volatile int *a = (int *) (NULL);
    *a = 1;
}