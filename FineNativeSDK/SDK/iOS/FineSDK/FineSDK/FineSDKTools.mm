//
//  FineSDKTools.m
//  FineSDK
//
//  Created by Cylee on 2019/4/2.
//  Copyright © 2019年 cylee. All rights reserved.
//

#import "FineSDKTools.h"

@implementation FineSDKTools

+ (NSDictionary *)jsonStringToDictionary:(NSString *)jsonString
{
    if (jsonString == nil || jsonString == NULL) {
        return nil;
    }
    
    if ([jsonString isKindOfClass:[NSNull class]]) {
        return nil;
    }
    
    if ([[jsonString stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] length]==0) {
        return nil;
    }
    
    NSData *jsonData = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
    NSError *err;
    NSDictionary *dic = [NSJSONSerialization JSONObjectWithData:jsonData
                                                        options:NSJSONReadingMutableContainers
                                                          error:&err];
    if (err) {
        NSLog(@"FineSDKTools jsonStringToDictionary 解析失败: %@",err);
        return nil;
    }
    
    return dic;
}


+ (NSString *)dictionaryToJsonString:(NSDictionary *)dict {
    NSError *err;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:dict options:NSJSONWritingPrettyPrinted error:&err];
    NSString *jsonString;
    
    if (!jsonData) {
        NSLog(@"FineSDKTools jsonStringToDictionary 解析失败: %@", err);
    } else {
        jsonString = [[NSString alloc]initWithData:jsonData encoding:NSUTF8StringEncoding];
    }
    
    NSMutableString *mutStr = [NSMutableString stringWithString:jsonString];
    NSRange range = {0,jsonString.length};
    
    //去掉字符串中的空格
    [mutStr replaceOccurrencesOfString:@" " withString:@"" options:NSLiteralSearch range:range];
    NSRange range2 = {0,mutStr.length};
    
    //去掉字符串中的换行符
    [mutStr replaceOccurrencesOfString:@"\n" withString:@"" options:NSLiteralSearch range:range2];
    
    return mutStr;
}

@end
