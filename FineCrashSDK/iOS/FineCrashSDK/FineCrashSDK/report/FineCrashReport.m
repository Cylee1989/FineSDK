//
//  FineCrashReport.m
//  FineCrashReport
//
//  Created by 李晨阳 on 2020/4/2.
//  Copyright © 2020 李晨阳. All rights reserved.
//

#import "FineCrashReport.h"

@implementation FineCrashReport

NSString *breakpadPath;

+ (instancetype)getInstance {
    static FineCrashReport *_instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [[self alloc] init];
        breakpadPath = [FineCrashUtils getBreakpadDirectory];
        NSLog(@"崩溃目录:%@", breakpadPath);
    });
    return _instance;
}

// 遍历崩溃文件
- (void)loopDumpFile {
    NSFileManager *fm = [NSFileManager defaultManager];
    NSDirectoryEnumerator *dict = [fm enumeratorAtPath:breakpadPath];
    for (NSString *dumpFile in dict.allObjects) {
        if([dumpFile containsString:@".dmp"]){
            NSString *dumpPath = [NSString stringWithFormat:@"%@%@", breakpadPath, dumpFile];
            NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
            [dict setValue:FINE_CRASH_ENV_TYPE_CPP forKey:@"env"];
            [dict setValue:dumpFile forKey:@"dumpFile"];
            [dict setValue:dumpPath forKey:@"dumpPath"];
            [self report:dict];
            return;
        }
    }
}

// 删除崩溃文件
- (void)deleteDumpFile:(NSString *)dumpPath {
    NSFileManager *fm = [NSFileManager defaultManager];
    BOOL ret = [fm removeItemAtPath:dumpPath error:nil];
    if (ret) {
        [self loopDumpFile];
    }
}

// 上报崩溃文件
- (void)report:(NSMutableDictionary *)dict {
    NSMutableDictionary *requestDict = [[NSMutableDictionary alloc] init];
    NSMutableDictionary *appDict = [[NSMutableDictionary alloc] init];
    NSMutableDictionary *deviceDict = [[NSMutableDictionary alloc] init];
    NSMutableDictionary *extDict = [[NSMutableDictionary alloc] init];

    NSString *env = [dict valueForKey:@"env"];
    // 处理不同平台参数
    if ([env isEqualToString:FINE_CRASH_ENV_TYPE_CPP]) {
        NSString *dumpFile = [dict valueForKey:@"dumpFile"];
        NSString *dumpPath = [dict valueForKey:@"dumpPath"];
        NSString *keySaveInfo = [NSString stringWithFormat:@"%@_%@", FINE_CRASH_SDK_UESR_KEY, dumpFile];
        NSMutableDictionary *saveInfo = [FineCrashUserDefaults read:keySaveInfo];
        NSNumber *useTime = [saveInfo valueForKey:@"useTime"];
        
        [requestDict setValue:[FineCrashUtils getFileCreateTime:dumpPath] forKey:FINE_CRASH_PARAMS_TIME];
        [requestDict setValue:useTime forKey:FINE_CRASH_PARAMS_USE_TIME];
        [requestDict setValue:@YES forKey:FINE_CRASH_PARAMS_IS_DECODE];
        [requestDict setValue:[FineCrashUtils readFileWithBase64:dumpPath] forKey:FINE_CRASH_PARAMS_MSG];
        [requestDict setValue:@"" forKey:FINE_CRASH_PARAMS_THREAD];
    } else if ([env isEqualToString:FINE_CRASH_ENV_TYPE_C_SHARP]) {
        NSString *exceptionName = [dict valueForKey:@"exceptionName"];
        NSString *exceptionDetail = [dict valueForKey:@"exceptionDetail"];
        NSMutableDictionary *saveInfo = [FineCrashUserDefaults read:FINE_CRASH_SDK_UESR_KEY];
        NSNumber *useTime = [saveInfo valueForKey:@"useTime"];

        [requestDict setValue:[FineCrashUtils getTimeStamp] forKey:FINE_CRASH_PARAMS_TIME];
        [requestDict setValue:useTime forKey:FINE_CRASH_PARAMS_USE_TIME];
        [requestDict setValue:@NO forKey:FINE_CRASH_PARAMS_IS_DECODE];
        [requestDict setValue:exceptionName forKey:FINE_CRASH_PARAMS_MSG];
        [requestDict setValue:exceptionDetail forKey:FINE_CRASH_PARAMS_THREAD];
    }
    
    // 设置APP信息
    [appDict setValue:FINE_CRASH_VERSION forKey:FINE_CRASH_PARAMS_APP_SDKVER];
    [appDict setValue:@"" forKey:FINE_CRASH_PARAMS_APP_ID];
    [appDict setValue:[FineCrashUtils getBundleID] forKey:FINE_CRASH_PARAMS_APP_BUNDLE];
    [appDict setValue:[FineCrashUtils getBundleDisplayName] forKey:FINE_CRASH_PARAMS_APP_NAME];
    [appDict setValue:[FineCrashUtils getVersionName] forKey:FINE_CRASH_PARAMS_APP_VER];
    [appDict setValue:[FineCrashUtils getOrientation] forKey:FINE_CRASH_PARAMS_APP_SCREEN_TYPE];

    // 设置Device信息
    [deviceDict setValue:[FineCrashUtils getDeviceModel] forKey:FINE_CRASH_PARAMS_DEVICE_MODEL];
    [deviceDict setValue:@"Apple" forKey:FINE_CRASH_PARAMS_DEVICE_MAKE];
    [deviceDict setValue:[FineCrashUtils getCpuType] forKey:FINE_CRASH_PARAMS_DEVICE_CPU_TYPE];
    [deviceDict setValue:[FineCrashUtils getAvailableRam] forKey:FINE_CRASH_PARAMS_DEVICE_AVAILABLE_RAM];
    [deviceDict setValue:[FineCrashUtils getAvailableRom] forKey:FINE_CRASH_PARAMS_DEVICE_AVAILABLE_DISK];
    [deviceDict setValue:[FineCrashUtils getNetworkStatus] forKey:FINE_CRASH_PARAMS_DEVICE_NW];
    [deviceDict setValue:[FineCrashUtils getCarrierName] forKey:FINE_CRASH_PARAMS_DEVICE_CARRIER];
    [deviceDict setValue:@"1" forKey:FINE_CRASH_PARAMS_DEVICE_OS];
    [deviceDict setValue:[FineCrashUtils getSystemVersion] forKey:FINE_CRASH_PARAMS_DEVICE_OSV];
    [deviceDict setValue:[FineCrashUtils getLanguage] forKey:FINE_CRASH_PARAMS_DEVICE_LNG];
    [deviceDict setValue:@"" forKey:FINE_CRASH_PARAMS_DEVICE_TYPE];
    [deviceDict setValue:[FineCrashUtils getIDFA] forKey:FINE_CRASH_PARAMS_DEVICE_IDFA];
    
    // 设置EXT信息
    NSMutableDictionary *extCustom = [[NSMutableDictionary alloc] init];
    [extDict setValue:extCustom forKey:FINE_CRASH_PARAMS_EXT_CUSTOM];
    
    [requestDict setValue:[FineCrashUtils getTimeStamp] forKey:FINE_CRASH_PARAMS_REPORT_TIME];
    [requestDict setValue:[FineCrashUtils dictionaryToJson:appDict] forKey:FINE_CRASH_PARAMS_APP];
    [requestDict setValue:[FineCrashUtils dictionaryToJson:deviceDict] forKey:FINE_CRASH_PARAMS_DEVICE];
    [requestDict setValue:[FineCrashUtils dictionaryToJson:extDict] forKey:FINE_CRASH_PARAMS_EXT];
    
    // 创建请求
    NSString *jsonString = [FineCrashUtils dictionaryToJson:requestDict];
    NSURL *url = [NSURL URLWithString:FINE_CRASH_REPORT_URL];
    NSMutableURLRequest *request =[NSMutableURLRequest requestWithURL:url];
    request.HTTPMethod = @"POST";
    request.HTTPBody = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
    [request setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    
    NSURLSession *session = [NSURLSession sharedSession];
    NSURLSessionDataTask *sessionDataTask = [session dataTaskWithRequest:request completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        if (error) {
            NSLog(@"上报错误:%@", [error debugDescription]);
            return;
        }
        NSHTTPURLResponse *res = (NSHTTPURLResponse *)response;
        if (res.statusCode == 200) {
            NSString * jsonStr  =[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            NSLog(@"上报成功:%@", jsonStr);
            NSData *data = [jsonStr dataUsingEncoding:NSUTF8StringEncoding];
            NSDictionary *resultDict = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
            if (resultDict != nil) {
                NSNumber *code = [resultDict valueForKey:@"code"];
                if (code.intValue == 0) {
                    NSString *dumpPath = [dict valueForKey:@"dumpPath"];
                    [self deleteDumpFile:dumpPath];
                }
            }
        } else if (res.statusCode != 200) {
            NSLog(@"上报失败");
        }
    }];
    [sessionDataTask resume];
}

@end
