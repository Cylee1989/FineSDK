//
//  BaseSDK.mm
//  FineSDK
//
//  Created by Cylee on 2019/3/29.
//  Copyright © 2019年 cylee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseSDK.h"

@implementation BaseSDK

+ (BaseSDK*) getInstance {
    static BaseSDK* _instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [[self alloc] init];
    });
    return _instance;
}

-(void)initSDK:(NSMutableDictionary*)param {
    NSLog(@"BaseSDK: %s", "initSDK");
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    NSLog(@"BaseSDK: %s", "didFinishLaunchingWithOptions");
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    NSLog(@"BaseSDK: %s", "applicationWillResignActive");
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    NSLog(@"BaseSDK: %s", "applicationDidEnterBackground");
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    NSLog(@"BaseSDK: %s", "applicationWillEnterForeground");
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    NSLog(@"BaseSDK: %s", "applicationDidBecomeActive");
}


- (void)applicationWillTerminate:(UIApplication *)application {
    NSLog(@"BaseSDK: %s", "applicationWillTerminate");
}

@end
