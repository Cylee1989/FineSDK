//
//  FinePushLocalNotification.h
//  FinePushSDK
//
//  Created by Cylee on 17/12/5.
//  Copyright © 2017年 Cylee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FinePushLocalNotification : NSObject

+ (instancetype) getInstance;

- (void) setTimeZone:(NSString *)timeZone;

- (void) setNotificationSound:(NSString *)soundName;

- (void) didFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions;

- (void) addNotification:(nullable NSMutableDictionary *)dictionary;

- (void) clearNotificationByKey:(NSString *)key;

- (void) clearAllNotification;

@end

NS_ASSUME_NONNULL_END

