//
//  FineCrashUtils.h
//  FineCrashUtils
//
//  Created by 李晨阳 on 2020/4/2.
//  Copyright © 2020 李晨阳. All rights reserved.
//

#ifndef FineCrashUtils_h
#define FineCrashUtils_h

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FineCrashUtils : NSObject

+ (NSString *)dictionaryToJson:(NSDictionary *)dict;

+ (BOOL)isBlankString:(NSString *)str;

+ (NSString *)getTimeStamp;

+ (NSString *)readFileWithBase64:(NSString *)filePath;

+ (NSString *)getBreakpadDirectory;

+ (NSString *)getBundleID;

+ (NSString *)getBundleDisplayName;

+ (NSString *)getVersionName;

+ (NSString *)getVersionCode;

+ (NSString *)getDeviceModel;

+ (NSString *)getSystemVersion;

+ (NSString *)getOrientation;

+ (NSString *)getFileCreateTime:(NSString *)path;

+ (NSNumber *)getTotalRom;

+ (NSNumber *)getAvailableRom;

+ (NSNumber *)getTotalRam;

+ (NSNumber *)getAvailableRam;

+ (NSNumber *)getAppRam;

+ (NSString *)getCpuType;

+ (NSString *)getLanguage;

+ (NSString *)getCarrierName;

+ (NSString *)getIDFA;

+ (NSString*)getNetworkStatus;

@end

#endif /* FineCrashUtils_h */

NS_ASSUME_NONNULL_END
