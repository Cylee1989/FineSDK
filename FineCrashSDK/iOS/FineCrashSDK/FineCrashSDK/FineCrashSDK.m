//
//  FineCrashSDK.mm
//  FineCrashSDK
//
//  Created by 李晨阳 on 2020/4/2.
//  Copyright © 2020 李晨阳. All rights reserved.
//

#import "client/ios/BreakpadController.h"

#import "FineCrashSDK.h"
#import "FineCrashReport.h"
#import "FineCrashTimer.h"

@implementation FineCrashSDK

+ (instancetype)getInstance {
    static FineCrashSDK *_instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [[self alloc] init];
    });
    return _instance;
}

- (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    NSLog(@"开启服务");
    [[BreakpadController sharedInstance] start: YES withCallback:&breakpadCallback];
    [[BreakpadController sharedInstance] setUploadingEnabled:NO];
    [[FineCrashReport getInstance] loopDumpFile];
    [[FineCrashTimer getInstance] didFinishLaunchingWithOptions:launchOptions];
}

- (void)applicationWillTerminate:(UIApplication *)application {
    NSLog(@"关闭服务");
    [[BreakpadController sharedInstance] stop];
    [[FineCrashTimer getInstance] applicationWillTerminate:application];
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    [[FineCrashTimer getInstance] applicationWillEnterForeground:application];
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    [[FineCrashTimer getInstance] applicationDidEnterBackground:application];
}

void breakpadCallback(const char *dumpFilePath) {
    NSLog(@"崩溃路径:%s", dumpFilePath);
}

@end
