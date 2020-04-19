//
//  FineCrashSDK.h
//  FineCrashSDK
//
//  Created by 李晨阳 on 2020/4/2.
//  Copyright © 2020 李晨阳. All rights reserved.
//

#ifndef FineCrashSDK_h
#define FineCrashSDK_h

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FineCrashSDK : NSObject

+ (instancetype)getInstance;

- (void)didFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions;

- (void)applicationWillTerminate:(UIApplication *)application;

- (void)applicationWillEnterForeground:(UIApplication *)application;

- (void)applicationDidEnterBackground:(UIApplication *)application;

@end

#endif /* FineCrashSDK_h */

NS_ASSUME_NONNULL_END
