//
//  FineCrashUnityCallBack.mm
//  FineCrashUnityCallBack
//
//  Created by Cylee on 2020/3/27.
//

#include "FineCrashUnityCallBack.h"
#include "FineCrashReport.h"

void callBackExceptionFromUnity(char* logString, char* stackString) {
    NSString *exceptionName = [NSString stringWithCString:logString encoding:NSUTF8StringEncoding];
    NSString *exceptionDetail = [NSString stringWithCString:stackString encoding:NSUTF8StringEncoding];
    NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
    [dict setValue:FINE_CRASH_ENV_TYPE_C_SHARP forKey:@"env"];
    [dict setValue:exceptionName forKey:@"exceptionName"];
    [dict setValue:exceptionDetail forKey:@"exceptionDetail"];
    [[FineCrashReport getInstance] report:dict];
}

