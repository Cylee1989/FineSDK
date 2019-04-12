//
//  FineDispatcher.mm
//  proj.ios
//
//  Created by Cylee on 2019/2/13.
//  Copyright © 2019年 Cylee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FineDispatcher.h"

@implementation FineDispatcher

-(void)initSDK:(NSMutableDictionary*)param {
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    [dict setObject:@"0" forKey:@"ActionType"];
    [dict setObject:@"0" forKey:@"errornu"];
    [dict setObject:@"初始化成功" forKey:@"message"];
    FineSDK::getInstance()->receiveCallBack(FineSDK::convertToChar(dict));
}

-(void)login:(NSMutableDictionary*)param {
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    [dict setObject:@"1" forKey:@"ActionType"];
    [dict setObject:@"0" forKey:@"errornu"];
    [dict setObject:@"登录成功" forKey:@"message"];
    FineSDK::getInstance()->receiveCallBack(FineSDK::convertToChar(dict));
}

@end
