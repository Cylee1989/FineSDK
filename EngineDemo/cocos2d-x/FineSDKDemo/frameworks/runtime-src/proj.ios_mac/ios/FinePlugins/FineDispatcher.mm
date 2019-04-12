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

-(void) initSDK:(NSMutableDictionary*)param {
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    [dict setObject:@"0" forKey:@"ActionType"];
    [dict setObject:@"0" forKey:@"errornu"];
    [dict setObject:@"初始化成功" forKey:@"message"];
    FineSDK::getInstance()->receiveCallBack(FineSDK::convertToChar(dict));
}

-(void) login:(NSMutableDictionary*)param {
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    [dict setObject:@"1" forKey:@"ActionType"];
    [dict setObject:@"0" forKey:@"errornu"];
    [dict setObject:@"登录成功" forKey:@"message"];
    FineSDK::getInstance()->receiveCallBack(FineSDK::convertToChar(dict));
}

-(void) pay:(NSMutableDictionary*)param {
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    [dict setObject:@"2" forKey:@"ActionType"];
    [dict setObject:@"0" forKey:@"errornu"];
    [dict setObject:@"充值成功" forKey:@"message"];
    FineSDK::getInstance()->receiveCallBack(FineSDK::convertToChar(dict));
}

-(void) logout:(NSMutableDictionary*)param {
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    [dict setObject:@"3" forKey:@"ActionType"];
    [dict setObject:@"0" forKey:@"errornu"];
    [dict setObject:@"注销成功" forKey:@"message"];
    FineSDK::getInstance()->receiveCallBack(FineSDK::convertToChar(dict));
}

-(void) exit:(NSMutableDictionary*)param {
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    [dict setObject:@"4" forKey:@"ActionType"];
    [dict setObject:@"0" forKey:@"errornu"];
    [dict setObject:@"退出" forKey:@"message"];
    FineSDK::getInstance()->receiveCallBack(FineSDK::convertToChar(dict));
}

@end
