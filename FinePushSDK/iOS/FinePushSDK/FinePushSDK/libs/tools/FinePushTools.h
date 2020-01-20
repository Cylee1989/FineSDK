//
//  FinePushTools.h
//  FinePushSDK
//
//  Created by Cylee on 17/12/8.
//  Copyright © 2017年 Cylee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Security/Security.h>

NS_ASSUME_NONNULL_BEGIN

@interface FinePushTools : NSObject

+ (NSString *) getBundleID;

+ (NSString *) getUUID;

+ (NSString *) getDeviceModel;

+ (NSString *) getSystemVersion;

+ (NSString *) getRSAPublicKey;

+ (NSString *) getRSAPrivateKey;

+ (NSString *) getRSAPublicKeyByGo;

+ (NSString *) getMD5:(NSString *)str;

@end

NS_ASSUME_NONNULL_END
