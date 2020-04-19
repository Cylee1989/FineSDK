//
//  FineCrashConfig.h
//  FineCrashConfig
//
//  Created by 李晨阳 on 2020/4/2.
//  Copyright © 2020 李晨阳. All rights reserved.
//

#ifndef FineCrashConfig_h
#define FineCrashConfig_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 版本号
static NSString *FINE_CRASH_VERSION = @"1.0.0";

// 异常和崩溃类型
static NSString *FINE_CRASH_ENV_TYPE_CPP = @"cpp";
static NSString *FINE_CRASH_ENV_TYPE_C_SHARP = @"c#";

// 上报地址
static NSString *FINE_CRASH_REPORT_URL = @"http://192.168.199.114:7777/report";

// 上报时间(时间戳(秒))
static NSString *FINE_CRASH_PARAMS_REPORT_TIME = @"report_time";
// 发生时间(时间戳(秒))
static NSString *FINE_CRASH_PARAMS_TIME = @"time";
// 使用时间(分钟）
static NSString *FINE_CRASH_PARAMS_USE_TIME = @"use_time";
// 是否需要通过字符表解码(true:需要, false:不需要)
static NSString *FINE_CRASH_PARAMS_IS_DECODE = @"is_decode";
// 出错信息
static NSString *FINE_CRASH_PARAMS_MSG = @"msg";
// 异常进程#线程
static NSString *FINE_CRASH_PARAMS_THREAD = @"thread";

// 应用信息
static NSString *FINE_CRASH_PARAMS_APP = @"app";
// 应用包名
static NSString *FINE_CRASH_PARAMS_APP_BUNDLE = @"bundle";
// 开发者平台中的应用编号
static NSString *FINE_CRASH_PARAMS_APP_ID = @"id";
// APP名称
static NSString *FINE_CRASH_PARAMS_APP_NAME = @"name";
// SDK的版本
static NSString *FINE_CRASH_PARAMS_APP_SDKVER = @"sdkver";
// APP的版本
static NSString *FINE_CRASH_PARAMS_APP_VER = @"ver";
// 屏幕方向(1:竖屏, 2:横屏)
static NSString *FINE_CRASH_PARAMS_APP_SCREEN_TYPE = @"screen_type";

// 设备信息
static NSString *FINE_CRASH_PARAMS_DEVICE = @"device";
// 设备型号
static NSString *FINE_CRASH_PARAMS_DEVICE_MODEL = @"model";
// 设备品牌
static NSString *FINE_CRASH_PARAMS_DEVICE_MAKE = @"make";
// CPU架构
static NSString *FINE_CRASH_PARAMS_DEVICE_CPU_TYPE = @"cpu_type";
// 可用RAM(MB)
static NSString *FINE_CRASH_PARAMS_DEVICE_AVAILABLE_RAM = @"available_ram";
// 可用磁盘(GB)
static NSString *FINE_CRASH_PARAMS_DEVICE_AVAILABLE_DISK = @"available_disk";
// 连接类型,值域 {-1,2G,3G,4G,WIFI} -1表示未知。
static NSString *FINE_CRASH_PARAMS_DEVICE_NW = @"nw";
// 运营商
static NSString *FINE_CRASH_PARAMS_DEVICE_CARRIER = @"carrier";
// 操作系统 0:Android 1:iOS
static NSString *FINE_CRASH_PARAMS_DEVICE_OS = @"os";
// 操作系统版本
static NSString *FINE_CRASH_PARAMS_DEVICE_OSV = @"osv";
/**
* 设备类型
* 0：phone
* 1：tablet
* -1: 未知
*/
static NSString *FINE_CRASH_PARAMS_DEVICE_TYPE = @"type";
// 操作系统语言。例如：“zh”
static NSString *FINE_CRASH_PARAMS_DEVICE_LNG = @"lng";
// iOS系统的IDFA (iOS系统时必须)
static NSString *FINE_CRASH_PARAMS_DEVICE_IDFA = @"idfa";

// 扩展信息
static NSString *FINE_CRASH_PARAMS_EXT = @"ext";
// 存放自定义Key, Value的字符串
static NSString *FINE_CRASH_PARAMS_EXT_CUSTOM = @"custom";

#endif /* FineCrashConfig_h */

NS_ASSUME_NONNULL_END
