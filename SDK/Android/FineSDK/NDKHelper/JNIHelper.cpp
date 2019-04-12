/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#include "JNIHelper.h"
#include <android/log.h>
#include <string.h>

#define  LOG_TAG    "JNIHelper_C++"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

using namespace std;

#define JAVAVM  JNIHelper::getJavaVM()

extern "C"
{

    //////////////////////////////////////////////////////////////////////////
    // java vm helper function
    //////////////////////////////////////////////////////////////////////////
    jint JNI_OnLoad(JavaVM *vm, void *reserved) {
        JNIHelper::setJavaVM(vm);
        return JNI_VERSION_1_6;
    }
    
    static pthread_key_t s_threadKey;

    static void detach_current_thread (void *env) {
        JAVAVM->DetachCurrentThread();
    }
    
    static bool getEnv(JNIEnv **env) {
        bool bRet = false;

        switch(JAVAVM->GetEnv((void**)env, JNI_VERSION_1_4)) {
        case JNI_OK:
            bRet = true;
            break;
        case JNI_EDETACHED:
            pthread_key_create (&s_threadKey, detach_current_thread);
            if (JAVAVM->AttachCurrentThread(env, 0) < 0) {
                LOGD("%s", "Failed to get the environment using AttachCurrentThread()");
                break;
            }
            if (pthread_getspecific(s_threadKey) == NULL)
                pthread_setspecific(s_threadKey, env); 
            bRet = true;
            break;
        default:
            LOGD("%s", "Failed to get the environment using GetEnv()");
            break;
        }      

        return bRet;
    }

    static jclass getClassID_(const char *className, JNIEnv *env) {
        JNIEnv *pEnv = env;
        jclass ret = 0;

        do {
            if (! pEnv) {
                if (! getEnv(&pEnv)) {
                    break;
                }
            }
            
            ret = pEnv->FindClass(className);
            if(pEnv->ExceptionCheck()) pEnv->ExceptionClear();
            if (! ret) {
                if(pEnv->ExceptionCheck()) {
                    // pEnv->ThrowNew(ret, "JNI getClassID_ thrown from C code");
                    pEnv->ExceptionDescribe();
                    pEnv->ExceptionClear();
                }
                LOGD("Failed to find class of %s", className);
                break;
            }
        } while (0);

        return ret;
    }

    static bool getStaticMethodInfo_(JNIMethodInfo &methodinfo, const char *className, const char *methodName, const char *paramCode) {
        jmethodID methodID = 0;
        JNIEnv *pEnv = 0;
        bool bRet = false;

        do {
            if (! getEnv(&pEnv)) {
                break;
            }

            jclass classID = getClassID_(className, pEnv);

            if(pEnv->ExceptionCheck()) pEnv->ExceptionClear();
            methodID = pEnv->GetStaticMethodID(classID, methodName, paramCode);
            if (! methodID) {
                if(pEnv->ExceptionCheck()) {
                    pEnv->ExceptionDescribe();
                    pEnv->ExceptionClear();
                }
                LOGD("Failed to find static method id of %s", methodName);
                break;
            }

            methodinfo.classID = classID;
            methodinfo.env = pEnv;
            methodinfo.methodID = methodID;

            bRet = true;
        } while (0);

        return bRet;
    }

    static bool getMethodInfo_(JNIMethodInfo &methodinfo, const char *className, const char *methodName, const char *paramCode) {
        jmethodID methodID = 0;
        JNIEnv *pEnv = 0;
        bool bRet = false;

        do {
            if (! getEnv(&pEnv)) {
                break;
            }

            jclass classID = getClassID_(className, pEnv);
            if(pEnv->ExceptionCheck()) pEnv->ExceptionClear();
            methodID = pEnv->GetMethodID(classID, methodName, paramCode);
            if (! methodID) {
                if(pEnv->ExceptionCheck()) {
                    pEnv->ExceptionDescribe();
                    pEnv->ExceptionClear();
                }
                LOGD("Failed to find method id of %s", methodName);
                break;
            }

            methodinfo.classID = classID;
            methodinfo.env = pEnv;
            methodinfo.methodID = methodID;

            bRet = true;
        } while (0);

        return bRet;
    }

    static string jstring2string_(jstring jstr) {
        if (jstr == NULL) {
            return "";
        }
        
        JNIEnv *env = 0;

        if (! getEnv(&env)) {
            return 0;
        }

        const char* chars = env->GetStringUTFChars(jstr, NULL);
        string ret(chars);
        env->ReleaseStringUTFChars(jstr, chars);

        return ret;
    }
}

JavaVM* JNIHelper::m_psJavaVM = NULL;

JavaVM* JNIHelper::getJavaVM() {
    return m_psJavaVM;
}

void JNIHelper::setJavaVM(JavaVM *javaVM) {
    m_psJavaVM = javaVM;
}

jclass JNIHelper::getClassID(const char *className, JNIEnv *env) {
    return getClassID_(className, env);
}

bool JNIHelper::getStaticMethodInfo(JNIMethodInfo &methodinfo, const char *className, const char *methodName, const char *paramCode) {
    return getStaticMethodInfo_(methodinfo, className, methodName, paramCode);
}

bool JNIHelper::getMethodInfo(JNIMethodInfo &methodinfo, const char *className, const char *methodName, const char *paramCode) {
    return getMethodInfo_(methodinfo, className, methodName, paramCode);
}

string JNIHelper::jstring2string(jstring str) {
    return jstring2string_(str);
}

