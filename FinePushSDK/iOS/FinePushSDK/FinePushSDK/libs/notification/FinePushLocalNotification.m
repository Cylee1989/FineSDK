//
//  FinePushLocalNotification.m
//  FinePushSDK
//
//  Created by Cylee on 17/12/5.
//  Copyright © 2017年 Cylee. All rights reserved.
//

#import "FinePushLocalNotification.h"
#import "FinePushTools.h"

@implementation FinePushLocalNotification

static NSString* _timeZone = @"Asia/Shanghai";
static NSString* _soundName;

+ (instancetype) getInstance {
    static FinePushLocalNotification *_instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [[self alloc] init];
    });
    return _instance;
}

// 时区获取网址 https://www.zeitverschiebung.net/cn/
- (void) setTimeZone:(NSString *)timeZone {
    _timeZone = timeZone;
    NSLog(@"设置时区: %@", _timeZone);
}

- (void) setNotificationSound:(NSString *)soundName {
    _soundName = soundName;
    NSLog(@"设置推送声音: %@", _soundName);
}


- (void) didFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions {
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    BOOL isRegist = [defaults boolForKey:@"FinePushLocalPushRegister"];
    if (!isRegist) {
        [self clearAllNotification];
        [defaults setBool:true forKey:@"FinePushLocalPushRegister"];
        [defaults synchronize];
        NSLog(@"首次启动，已清除全部本地推送设置。");
    }
}

- (void) addNotification:(NSMutableDictionary *)dictionary {
    if(dictionary == nil) {
        NSLog(@"本地推送 [数据空]");
        return;
    }
    NSLog(@"添加本地推送: %@", dictionary);
    
    UIApplication *application = [UIApplication sharedApplication];
    if ([UIApplication instancesRespondToSelector:@selector(registerUserNotificationSettings:)]) {
        [application registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert|UIUserNotificationTypeBadge|UIUserNotificationTypeSound categories:nil]];
    }
    
    NSString *bundleID = [FinePushTools getBundleID];
    NSString *gameKey = dictionary[@"PushKey"];
    
    NSString* key = [bundleID stringByAppendingString:gameKey];
    NSString* time = dictionary[@"Time"];
    NSString* message = dictionary[@"Message"];
    NSString* repeatInterval = dictionary[@"RepeatInterval"];
    
    NSArray *localArray = [application scheduledLocalNotifications];
    for ( UILocalNotification *notification in localArray) {
        NSDictionary *dict = notification.userInfo;
        if (dict) {
            NSString *inKey = [dict objectForKey:@"key"];
            if ([inKey isEqualToString: key ]) {
                [application cancelLocalNotification:notification];
            }
        }
    }
    
    UILocalNotification *localNotification = [[UILocalNotification alloc] init];
    localNotification.fireDate = [NSDate dateWithTimeIntervalSince1970:time.doubleValue];
    localNotification.timeZone = [NSTimeZone timeZoneWithName:_timeZone];
    if (repeatInterval.intValue < 2) {
        localNotification.repeatInterval = 0;
    } else {
        localNotification.repeatInterval = (1UL << repeatInterval.intValue);
    }
    localNotification.soundName = UILocalNotificationDefaultSoundName;
    if (_soundName != nil ) {
        localNotification.soundName = _soundName;
    }
    localNotification.alertBody = message;
    localNotification.userInfo = [NSDictionary dictionaryWithObject:key forKey:@"key"];;
    [application scheduleLocalNotification:localNotification];
}

- (void) clearNotificationByKey:(NSString *)key {
    NSLog(@"清除本地推送: %@", key);
    NSString *bundleID = [FinePushTools getBundleID];
    
    NSString* notifyKey = [bundleID stringByAppendingString:key];
    UIApplication *application = [UIApplication sharedApplication];
    NSArray *localArray = [application scheduledLocalNotifications];
    for ( UILocalNotification *notification in localArray) {
        NSDictionary *dict = notification.userInfo;
        if (dict) {
            NSString *inKey = [dict objectForKey:@"key"];
            if ([inKey isEqualToString: notifyKey ]) {
                [application cancelLocalNotification:notification];
            }
        }
    }
}

- (void) clearAllNotification {
    NSLog(@"清除全部本地推送");
    [[UIApplication sharedApplication] cancelAllLocalNotifications];
}

@end
