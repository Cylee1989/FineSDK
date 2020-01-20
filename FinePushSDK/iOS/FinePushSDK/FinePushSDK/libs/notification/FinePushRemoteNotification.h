//
//  FinePushRemoteNotification.h
//  FinePushSDK
//
//  Created by Cylee on 17/12/5.
//  Copyright © 2017年 Cylee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FinePushRemoteNotification : NSObject

+ (instancetype) getInstance;

- (void) addNotification:(nullable NSMutableDictionary *)dictionary;

- (void) didFailToRegisterForRemoteNotificationsWithError:(nullable NSError *)error;

- (void) didRegisterForRemoteNotificationsWithDeviceToken:(nullable NSData *)deviceToken;

- (void) didReceiveRemoteNotification:(nonnull NSDictionary *)userInfo;

- (void) didReceiveRemoteNotification:(nonnull NSDictionary *)userInfo fetchCompletionHandler:(nonnull void (^)(UIBackgroundFetchResult))completionHandler;

@end

NS_ASSUME_NONNULL_END
