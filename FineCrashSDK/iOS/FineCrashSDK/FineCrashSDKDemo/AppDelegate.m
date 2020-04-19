//
//  AppDelegate.m
//  FineCrashSDKDemo
//
//  Created by Cylee on 2020/4/19.
//  Copyright © 2020 Cylee. All rights reserved.
//

#import "AppDelegate.h"
#import "FineCrashSDK.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [[FineCrashSDK getInstance] didFinishLaunchingWithOptions:launchOptions];
    return YES;
}

- (void)applicationWillTerminate:(UIApplication *)application {
    [[FineCrashSDK getInstance] applicationWillTerminate:application];
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    [[FineCrashSDK getInstance] applicationWillEnterForeground:application];
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    [[FineCrashSDK getInstance] applicationDidEnterBackground:application];
}


#pragma mark - UISceneSession lifecycle

@synthesize window = _window;

- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options {
    // Called when a new scene session is being created.
    // Use this method to select a configuration to create the new scene with.
    return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
}


- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions {
    // Called when the user discards a scene session.
    // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
    // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
}


@end
