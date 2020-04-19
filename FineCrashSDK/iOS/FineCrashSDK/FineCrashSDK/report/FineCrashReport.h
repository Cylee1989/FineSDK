//
//  FineCrashReport.h
//  FineCrashReport
//
//  Created by 李晨阳 on 2020/4/2.
//  Copyright © 2020 李晨阳. All rights reserved.
//

#ifndef FineCrashReport_h
#define FineCrashReport_h

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#import "FineCrashConfig.h"
#import "FineCrashUtils.h"
#import "FineCrashUserDefaults.h"

NS_ASSUME_NONNULL_BEGIN

@interface FineCrashReport : NSObject

+ (instancetype)getInstance;

- (void)loopDumpFile;

- (void)report:(NSMutableDictionary *)dict;

@end

#endif /* FineCrashReport_h */

NS_ASSUME_NONNULL_END
