//
//  FineSDKTools.h
//  FineSDK
//
//  Created by Cylee on 2019/4/2.
//  Copyright © 2019年 cylee. All rights reserved.
//

#ifndef FineSDKTools_h
#define FineSDKTools_h

#import <Foundation/Foundation.h>

@interface FineSDKTools : NSObject

+ (NSDictionary *)jsonStringToDictionary:(NSString *)jsonString;

+ (NSString *)dictionaryToJsonString:(NSDictionary *)dict;

@end

#endif /* FineSDKTools_h */
