//
//  FineCrashUtils.m
//  FineCrashUtils
//
//  Created by 李晨阳 on 2020/4/2.
//  Copyright © 2020 李晨阳. All rights reserved.
//

#import "FineCrashUtils.h"
#import "sys/utsname.h"
#import <mach/mach.h>
#import <CoreTelephony/CTCarrier.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <AdSupport/AdSupport.h>
#include "FineCrashReachability.h"

@implementation FineCrashUtils

+ (NSString*)dictionaryToJson:(NSDictionary *)dict {
    if (![dict isKindOfClass:[NSDictionary class]]) {
        return @"";
    }
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:dict options:NSJSONWritingPrettyPrinted error:&error];
    NSString *jsonString;
    if (error) {
        NSLog(@"%@",error);
        jsonString = @"";
    } else {
        jsonString = [[NSString alloc]initWithData:jsonData encoding:NSUTF8StringEncoding];
    }
    return jsonString;
}

+ (BOOL)isBlankString:(NSString *)str {
    NSString *string = str;
    if (string == nil || string == NULL) {
        return YES;
    }
    if ([string isKindOfClass:[NSNull class]]) {
        return YES;
    }
    if ([[string stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] length]==0) {
        return YES;
    }
    
    return NO;
}

+ (NSString *)getTimeStamp {
    NSDate* date = [NSDate dateWithTimeIntervalSinceNow:0];
    NSTimeInterval interval = [date timeIntervalSince1970];
    NSString *timeString = [NSString stringWithFormat:@"%0.f", interval];
    return timeString;
}

+ (NSString *)readFileWithBase64:(NSString *)filePath {
    NSData *fileData = [[NSData alloc] initWithContentsOfFile:filePath];
    NSString *encoded = [fileData base64EncodedStringWithOptions:0];
    return encoded;
}

+ (NSString *)getBreakpadDirectory {
    NSString *cachePath = [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0];
    NSString *breakpadPath = [NSString stringWithFormat:@"%@/Breakpad/", cachePath];
    return breakpadPath;
}

+ (NSString *)getBundleID {
    return [[NSBundle mainBundle] bundleIdentifier];
}

+ (NSString *)getBundleDisplayName {
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    NSString *name = [infoDictionary objectForKey:@"CFBundleDisplayName"];
    if ([self isBlankString:name]) {
        name = [infoDictionary objectForKey:@"CFBundleName"];
    }
    return name;
}

+ (NSString *)getVersionName {
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    return [infoDictionary objectForKey:@"CFBundleShortVersionString"];
}

+ (NSString *)getVersionCode {
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    return [infoDictionary objectForKey:@"CFBundleVersion"];
}

+ (NSString *)getDeviceModel {
    struct utsname systemInfo;
    uname(&systemInfo);
    NSString *deviceModel = [NSString stringWithCString:systemInfo.machine encoding:NSUTF8StringEncoding];
    return deviceModel;
}

+ (NSString *)getSystemVersion {
    return [[UIDevice currentDevice] systemVersion];
}

+ (NSString *)getOrientation {
    UIInterfaceOrientation orientation = [UIApplication sharedApplication].statusBarOrientation;
    if (orientation == UIInterfaceOrientationPortrait || orientation == UIInterfaceOrientationPortraitUpsideDown) {
        return @"1";
    }
    if (orientation == UIDeviceOrientationLandscapeLeft || orientation == UIDeviceOrientationLandscapeRight) {
        return @"2";
    }
    return @"0";
}

+ (NSString *)getFileCreateTime:(NSString *)path {
    NSString *createTime;
    NSDictionary *fileAttributes = [[NSFileManager defaultManager] attributesOfItemAtPath:path error:nil];
    if (fileAttributes) {
        NSDate *createData = [fileAttributes objectForKey:NSFileCreationDate];
        NSTimeInterval interval = [createData timeIntervalSince1970];
        createTime = [NSString stringWithFormat:@"%0.f", interval];
    }
    return createTime;
}

+ (NSNumber *)getTotalRom {
    NSDictionary *fattributes = [[NSFileManager defaultManager] attributesOfFileSystemForPath:NSHomeDirectory() error:nil];
    return [fattributes objectForKey:NSFileSystemSize];
}

+ (NSNumber *)getAvailableRom {
    NSDictionary *fattributes = [[NSFileManager defaultManager] attributesOfFileSystemForPath:NSHomeDirectory() error:nil];
    return [fattributes objectForKey:NSFileSystemFreeSize];
}

+ (NSNumber*)getTotalRam {
    return [NSNumber numberWithLongLong:[NSProcessInfo processInfo].physicalMemory/1024.0];
}

+ (NSNumber*)getAvailableRam {
    vm_statistics_data_t vmStats;
    mach_msg_type_number_t infoCount = HOST_VM_INFO_COUNT;
    kern_return_t kernReturn = host_statistics(mach_host_self(), HOST_VM_INFO, (host_info_t)&vmStats, &infoCount);
    if (kernReturn != KERN_SUCCESS) {
        return 0;
    }
    NSNumber *n = [NSNumber numberWithLongLong:((vm_page_size * vmStats.free_count + vm_page_size * vmStats.inactive_count))/ 1024.0];
    return n;
}

+ (NSNumber*)getAppRam {
    task_basic_info_data_t taskInfo;
    mach_msg_type_number_t infoCount = TASK_BASIC_INFO_COUNT;
    kern_return_t kernReturn = task_info(mach_task_self(), TASK_BASIC_INFO, (task_info_t)&taskInfo, &infoCount);
    if (kernReturn != KERN_SUCCESS) {
        return 0;
    }
    NSNumber *n = [NSNumber numberWithLongLong:taskInfo.resident_size / 1024.0];
    return n;
}

+ (NSString *)getCpuType {
    NSString *cpuType = @"";
    host_basic_info_data_t hostInfo;
    mach_msg_type_number_t infoCount;
    infoCount = HOST_BASIC_INFO_COUNT;
    host_info(mach_host_self(), HOST_BASIC_INFO, (host_info_t)&hostInfo, &infoCount);
    switch (hostInfo.cpu_type) {
        case CPU_TYPE_I386:
            NSLog(@"CPU_TYPE_I386");
            cpuType = @"i386";
            break;
        case CPU_TYPE_X86_64:
            NSLog(@"CPU_TYPE_X86_64");
            cpuType = @"x86_64";
            break;
        case CPU_TYPE_ARM:
            NSLog(@"CPU_TYPE_ARM");
            cpuType = @"arm";
            break;
        case CPU_TYPE_ARM64:
            NSLog(@"CPU_TYPE_ARM64");
            cpuType = @"arm64";
            break;
        case CPU_TYPE_ARM64_32:
            NSLog(@"CPU_TYPE_ARM64_32");
            cpuType = @"arm64_32";
            break;
        default:
            NSLog(@"CPU_TYPE_OTHER");
            break;
    }
    
    return cpuType;
}

+ (NSString *)getLanguage {
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSArray *allLanguages = [defaults objectForKey:@"AppleLanguages"];
    NSString *lng = [allLanguages objectAtIndex:0];
    return lng;
}

+ (NSString*)getCarrierName {
    CTTelephonyNetworkInfo *info = [[CTTelephonyNetworkInfo alloc] init];
    CTCarrier *carrier = [info subscriberCellularProvider];
    NSString *name = [carrier carrierName]; // 运营商名称，中国联通
    if (name == NULL) {
        name = @"";
    }
    return name;
}

+ (NSString *)getIDFA {
    if ([[ASIdentifierManager sharedManager] isAdvertisingTrackingEnabled]) {
        return [[[ASIdentifierManager sharedManager] advertisingIdentifier] UUIDString];
    }
    return @"";
}

+ (NSString*)getNetworkStatus {
    NSString *strStatus = @"-1";
    FineCrashReachability *r = [FineCrashReachability reachabilityForInternetConnection];
    switch ([r currentReachabilityStatus]) {
        case NotReachable:
            strStatus = @"-1";
            break;
        case ReachableViaWWAN:{
            strStatus = @"3G";
            CTTelephonyNetworkInfo *info = [[CTTelephonyNetworkInfo alloc] init];
            NSString *currentStatus = info.currentRadioAccessTechnology;
            if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyGPRS"]) {
                strStatus = @"2G";
            } else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyEdge"]) {
                strStatus = @"2G";
            } else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyCDMA1x"]) {
                strStatus = @"2G";
            } else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyWCDMA"]) {
                strStatus = @"3G";
            } else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyHSDPA"]) {
                strStatus = @"3G";
            } else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyHSUPA"]) {
                strStatus = @"3G";
            } else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyCDMAEVDORev0"]) {
                strStatus = @"3G";
            } else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyCDMAEVDORevA"]) {
                strStatus = @"3G";
            } else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyCDMAEVDORevB"]) {
                strStatus = @"3G";
            } else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyeHRPD"]) {
                strStatus = @"4G";
            } else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyLTE"]) {
                strStatus = @"4G";
            }
            break;
        }
        case ReachableViaWiFi:
            strStatus = @"WIFI";
            break;
    }
    return strStatus;
}

@end
