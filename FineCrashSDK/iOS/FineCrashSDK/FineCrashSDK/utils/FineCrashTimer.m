//
//  FineCrashTimer.m
//  FineCrashTimer
//
//  Created by 李晨阳 on 2020/4/2.
//  Copyright © 2020 李晨阳. All rights reserved.
//

#import "FineCrashTimer.h"
#import "FineCrashUtils.h"
#import "FineCrashUserDefaults.h"

@implementation FineCrashTimer

NSTimer *timer;
int useTime = 0;
NSMutableDictionary *saveInfo;

+ (instancetype)getInstance {
    static FineCrashTimer *_instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [[self alloc] init];
    });
    return _instance;
}

- (BOOL)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    saveInfo = [[NSMutableDictionary alloc] init];
    timer= [NSTimer scheduledTimerWithTimeInterval:1 target:self selector:@selector(time) userInfo:nil repeats:YES];
    [self setLastCrashInfo];
    return true;
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    [timer setFireDate:[NSDate distantPast]];
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    [timer setFireDate:[NSDate distantFuture]];
}

- (void)applicationWillTerminate:(UIApplication *)application {
    if (timer.isValid) {
        [timer invalidate];
    }
    timer = nil;
}

- (void)time {
    useTime += 1;
    NSNumber *nsUseTime = [NSNumber numberWithInt:useTime];
    [saveInfo setValue:nsUseTime forKey:@"useTime"];
    [FineCrashUserDefaults save:FINE_CRASH_SDK_UESR_KEY value:saveInfo];
}

// 遍历崩溃文件
- (void)setLastCrashInfo {
    NSMutableDictionary *lastSaveInfo = [FineCrashUserDefaults read:FINE_CRASH_SDK_UESR_KEY];
    if (lastSaveInfo != nil) {
        NSNumber *lastUseTime = [lastSaveInfo valueForKey:@"useTime"];
        if (lastUseTime.intValue > 0) {
            NSString *breakpadPath = [FineCrashUtils getBreakpadDirectory];
            NSFileManager *fm = [NSFileManager defaultManager];
            NSDirectoryEnumerator *dict = [fm enumeratorAtPath:breakpadPath];
            for (NSString *dumpFile in dict.allObjects) {
                if([dumpFile containsString:@".dmp"]){
                    NSString *keySaveInfo = [NSString stringWithFormat:@"%@_%@", FINE_CRASH_SDK_UESR_KEY, dumpFile];
                    NSMutableDictionary *saveDict = [FineCrashUserDefaults read:keySaveInfo];
                    if (saveDict == nil) {
                        saveDict = [[NSMutableDictionary alloc] init];
                        [saveDict setValue:lastUseTime forKey:@"useTime"];
                        [FineCrashUserDefaults save:keySaveInfo value:saveDict];
                    }
                }
            }
        }
    }
    [FineCrashUserDefaults dele:FINE_CRASH_SDK_UESR_KEY];
}

@end
