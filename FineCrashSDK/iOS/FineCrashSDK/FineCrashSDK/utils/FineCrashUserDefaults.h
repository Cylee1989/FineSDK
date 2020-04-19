//
//  FineCrashUserDefaults.h
//  FineCrashUserDefaults
//
//  Created by 李晨阳 on 2020/4/2.
//  Copyright © 2020 李晨阳. All rights reserved.
//

#ifndef FineCrashUserDefaults_h
#define FineCrashUserDefaults_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

static NSString *FINE_CRASH_SDK_UESR_KEY = @"fine_crash_sdk_user_key";

@interface FineCrashUserDefaults : NSObject

+ (void)save:(NSString *)key value:(NSMutableDictionary *)value;

+ (NSMutableDictionary *)read:(NSString *)key;

+ (void)dele:(NSString *)key;

@end

#endif /* FineCrashUserDefaults_h */

NS_ASSUME_NONNULL_END
