//
//  FineCrashTimer.h
//  FineCrashTimer
//
//  Created by 李晨阳 on 2020/4/2.
//  Copyright © 2020 李晨阳. All rights reserved.
//

#ifndef FineCrashTimer_h
#define FineCrashTimer_h

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FineCrashTimer : NSObject

+ (instancetype)getInstance;

- (BOOL)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

- (void)applicationWillEnterForeground:(UIApplication *)application;

- (void)applicationDidEnterBackground:(UIApplication *)application;

- (void)applicationWillTerminate:(UIApplication *)application;

@end

#endif /* FineCrashTimer_h */

NS_ASSUME_NONNULL_END
