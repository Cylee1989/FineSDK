//
//  FinePushSDK.h
//  FinePushSDK
//
//  Created by Cylee on 2020/1/17.
//  Copyright © 2020年 Fine. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FinePushSDK : NSObject

+ (instancetype) getInstance;

+ (NSString *) getVersion;

- (void) setTimeZone:(NSString *)timeZone;

- (void) setNotificationSound:(NSString *)soundName;

- (void) didFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions;

- (void) applicationDidBecomeActive;

- (void) didFailToRegisterForRemoteNotificationsWithError:(nullable NSError *)error;

- (void) didRegisterForRemoteNotificationsWithDeviceToken:(nullable NSData *)deviceToken;

- (void) didReceiveRemoteNotification:(nonnull NSDictionary *)userInfo;

- (void) didReceiveRemoteNotification:(nonnull NSDictionary *)userInfo fetchCompletionHandler:(nonnull void (^)(UIBackgroundFetchResult))completionHandler;

- (void) addRemoteNotification:(nullable NSMutableDictionary *)dictionary;

- (void) addLocalNotification:(nullable NSMutableDictionary *)dictionary;

- (void) clearLocalNotificationByKey:(NSString *)key;

- (void) clearAllLocalNotification;

@end

NS_ASSUME_NONNULL_END

