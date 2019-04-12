//
//  FineSDK.mm
//  FineSDK
//
//  Created by Cylee on 2019/2/12.
//  Copyright © 2019年 Cylee. All rights reserved.
//

#include "FineSDK.h"
#include "FineSDKTools.h"

static FineSDK* _protocol;
FineSDK* FineSDK::getInstance() {
    if (_protocol == NULL) {
        _protocol = new FineSDK();
    }
    return _protocol;
}

static id <FineSDKInterface> _interface;
id <FineSDKInterface> FineSDK::getInterface() {
    if (_interface == NULL && NSClassFromString(@"FineDispatcher") != nil) {
        _interface = [NSClassFromString(@"FineDispatcher") getInstance];
    }
    return _interface;
}

void FineSDK::callFunctionWithParams(const char* funcName, const char* params) {
    return_if_fails(funcName != NULL && strlen(funcName) > 0);
    NSString* strFuncName = [NSString stringWithUTF8String:funcName];
    strFuncName = [strFuncName stringByAppendingString:@":"];
    SEL selector = NSSelectorFromString(strFuncName);
    if ([_interface respondsToSelector:selector]) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
        NSString* obj = [NSString stringWithUTF8String:params];
        NSDictionary* dict = [FineSDKTools jsonStringToDictionary:obj];
        NSLog(@"FineSDK callFunctionWithParams %@:", dict);
        ([_interface performSelector:selector withObject:dict]);
#pragma clang diagnostic pop
    } else {
        NSLog(@"FineSDK Warn Can't find function %@",strFuncName);
    }
}

const char* FineSDK::convertToChar(NSMutableDictionary* dict) {
    if (dict == NULL) {
        return NULL;
    }
    
    NSError *error;
    NSData *data = [NSJSONSerialization dataWithJSONObject:dict options:NSJSONWritingPrettyPrinted error:&error];
    if (!data) {
        NSLog(@"FineSDK convertToChar error: %@", error);
        return NULL;
    }
    
    NSString *str = [[NSString alloc]initWithData:data encoding:NSUTF8StringEncoding];
    return str.UTF8String;
}
