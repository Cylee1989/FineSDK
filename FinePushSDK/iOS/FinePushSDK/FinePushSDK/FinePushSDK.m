//
//  FinePushSDK.m
//  FinePushSDK
//
//  Created by Cylee on 17/11/28.
//  Copyright © 2017年 Cylee. All rights reserved.
//

#import "FinePushSDK.h"
#import "FinePushLocalNotification.h"
#import "FinePushRemoteNotification.h"

#define SDK_VERSION "1.0.0"

@implementation FinePushSDK

+ (instancetype) getInstance {
    static FinePushSDK *_instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [[self alloc] init];
    });
    return _instance;
}

+ (NSString *) getVersion {
    return @SDK_VERSION;
}

- (void) setTimeZone:(NSString *)timeZone {
    [[FinePushLocalNotification getInstance] setTimeZone:timeZone];
}

- (void) setNotificationSound:(NSString *)soundName {
    [[FinePushLocalNotification getInstance] setNotificationSound:soundName];
}

- (void) didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0) {
        UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:(UIRemoteNotificationTypeBadge| UIRemoteNotificationTypeSound| UIRemoteNotificationTypeAlert) categories:nil];
        [[UIApplication sharedApplication] registerUserNotificationSettings:settings];
        [[UIApplication sharedApplication] registerForRemoteNotifications];
    } else {
        [[UIApplication sharedApplication] registerForRemoteNotificationTypes:(UIUserNotificationTypeBadge | UIUserNotificationTypeSound | UIUserNotificationTypeAlert)];
    }
    [[FinePushLocalNotification getInstance] didFinishLaunchingWithOptions:launchOptions];
}

- (void) applicationDidBecomeActive {
    [UIApplication sharedApplication].applicationIconBadgeNumber = 0;
}

- (void) didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
    [[FinePushRemoteNotification getInstance] didFailToRegisterForRemoteNotificationsWithError:error];
}

- (void) didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    [[FinePushRemoteNotification getInstance] didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
}

- (void) didReceiveRemoteNotification:(nonnull NSDictionary *)userInfo {
    [[FinePushRemoteNotification getInstance] didReceiveRemoteNotification:userInfo];
}

- (void) didReceiveRemoteNotification:(nonnull NSDictionary *)userInfo fetchCompletionHandler:(nonnull void (^)(UIBackgroundFetchResult))completionHandler {
    [[FinePushRemoteNotification getInstance] didReceiveRemoteNotification:userInfo fetchCompletionHandler:completionHandler];
}

- (void) addRemoteNotification:(NSMutableDictionary *)dictionary {
    [[FinePushRemoteNotification getInstance] addNotification:dictionary];
}

- (void) addLocalNotification:(NSMutableDictionary *)dictionary {
    [[FinePushLocalNotification getInstance] addNotification:dictionary];
}

- (void) clearLocalNotificationByKey:(NSString *)key {
    [[FinePushLocalNotification getInstance] clearNotificationByKey:key];
}

- (void) clearAllLocalNotification {
    [[FinePushLocalNotification getInstance] clearAllNotification];
}

@end
