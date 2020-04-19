//
//  FineCrashUnityCallBack.h
//  FineCrashUnityCallBack
//
//  Created by 李晨阳 on 2020/4/2.
//  Copyright © 2020 李晨阳. All rights reserved.
//

#ifndef FineCrashUnityCallBack_h
#define FineCrashUnityCallBack_h

#include <string>

extern "C" {
    
    void callBackExceptionFromUnity(char* logString, char* stackString);

}

#endif /* FineCrashUnityCallBack_h */
