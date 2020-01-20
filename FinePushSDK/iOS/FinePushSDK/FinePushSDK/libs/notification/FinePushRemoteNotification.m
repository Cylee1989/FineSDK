//
//  FinePushRemoteNotification.m
//  FinePushSDK
//
//  Created by Cylee on 17/12/5.
//  Copyright © 2017年 Cylee. All rights reserved.
//

#import "FinePushRemoteNotification.h"
#import "GCDAsyncUdpSocket.h"
#import "FinePushSDK.h"
#import "FinePushTools.h"
#import "FinePushRSA.h"

@interface FinePushRemoteNotification ()<GCDAsyncUdpSocketDelegate>

@end

@implementation FinePushRemoteNotification

+ (instancetype) getInstance {
    static FinePushRemoteNotification *_instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [[self alloc] init];
    });
    return _instance;
}

- (void) addNotification:(NSMutableDictionary *)dictionary {
    if (dictionary == nil) {
        NSLog(@"远程推送 [数据空]");
        return;
    }
    
    NSData *deviceToken = [[NSUserDefaults standardUserDefaults] objectForKey:@"FinePushDeviceToken"];
    if (deviceToken == nil) {
        NSLog(@"远程推送 [DeviceToken空]");
        return;
    }
    
    [dictionary setValue:[FinePushSDK getVersion] forKey:@"Version"];
    [dictionary setValue:@"ios" forKey:@"OS"];
    [dictionary setValue:@"1" forKey:@"Type"];
    [dictionary setValue:[FinePushTools getUUID] forKey:@"UUID"];
    [dictionary setValue:deviceToken forKey:@"DeviceToken"];
    [dictionary setValue:@"Apple" forKey:@"DeviceBrand"];
    [dictionary setValue:[FinePushTools getDeviceModel] forKey:@"DeviceModel"];
    [dictionary setValue:[FinePushTools getSystemVersion] forKey:@"SystemVersion"];
    
    [[NSUserDefaults standardUserDefaults] setObject:[NSKeyedArchiver archivedDataWithRootObject:dictionary] forKey:@"FinePushUserInfo"];
    [[NSUserDefaults standardUserDefaults] synchronize];
    
    NSString *host = [dictionary valueForKey:@"Host"];
    NSString *port = [dictionary valueForKey:@"Port"];

    dispatch_queue_t delegateQueue = dispatch_queue_create("socket.com", DISPATCH_QUEUE_CONCURRENT);
    GCDAsyncUdpSocket *socket = [[GCDAsyncUdpSocket alloc] initWithDelegate:self delegateQueue:delegateQueue];
    
    NSError *error = nil;
    // 端口绑定
    if (![socket bindToPort:0 error:&error]) {
        NSLog(@"远程推送 bindToPort: %@", error);
        return;
    }
    // 开始监听
    if (![socket beginReceiving:&error]) {
        NSLog(@"远程推送 beginReceiving: %@", error);
        return;
    }

    // 增加时间戳
    NSDate* dat = [NSDate dateWithTimeIntervalSinceNow:0];
    NSTimeInterval time = [dat timeIntervalSince1970];
    NSString *timeStamp = [NSString stringWithFormat:@"%0.f", time];//转为字符型
    [dictionary setValue:timeStamp forKey:@"TimeStamp"];
    
    // 增加签名
    NSString *appId = [dictionary valueForKey:@"AppID"];
    NSString *appKey = [dictionary valueForKey:@"AppKey"];
    NSString *signature = [NSString stringWithFormat:@"%@#%@#%@", appId, appKey, timeStamp];
    [dictionary setValue:[FinePushTools getMD5:signature] forKey:@"Signature"];
    
    // 移除没用的参数
    [dictionary removeObjectForKey:@"Host"];
    [dictionary removeObjectForKey:@"Port"];
    [dictionary removeObjectForKey:@"AppKey"];
    NSLog(@"注册远程推送: %@", dictionary);

    // Pass 0 if you don't care about the readability of the generated string
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:dictionary options:NSJSONWritingPrettyPrinted error:&error];
    if (!jsonData) {
        NSLog(@"远程推送 JSON数据异常: %@", error);
        return;
    }
    
    // 将NSData进行RSA加密
//    jsonData = [FinePushRSA encryptData:jsonData publicKey:[FinePushTools getRSAPublicKeyByGo]];
    
    [socket sendData:jsonData toHost:host port:[port intValue] withTimeout:-1 tag:0];
}

- (void) didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
}

- (void) didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    NSString *_deviceToken = [[[[deviceToken description]
                                stringByReplacingOccurrencesOfString: @"<" withString: @""]
                                stringByReplacingOccurrencesOfString: @">" withString: @""]
                                stringByReplacingOccurrencesOfString: @" " withString: @""];
    [[NSUserDefaults standardUserDefaults] setObject:_deviceToken forKey:@"FinePushDeviceToken"];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (void) didReceiveRemoteNotification:(nonnull NSDictionary *)userInfo {
    [self replyRemoteNotification:userInfo];
}

- (void) didReceiveRemoteNotification:(nonnull NSDictionary *)userInfo fetchCompletionHandler:(nonnull void (^)(UIBackgroundFetchResult))completionHandler {
    [self replyRemoteNotification:userInfo];
}

- (void) replyRemoteNotification:(nonnull NSDictionary *)userInfo {
    NSLog(@"接收信息%@", userInfo);
    if (userInfo != nil && [userInfo objectForKey:@"ext"]) {
        NSString *receivedid = [userInfo objectForKey:@"ext"][@"id"];
        
        NSData *data = [[NSUserDefaults standardUserDefaults] objectForKey:@"FinePushUserInfo"];
        NSMutableDictionary *dictionary = [NSKeyedUnarchiver unarchiveObjectWithData:data];
        [dictionary setValue:receivedid forKey:@"receivedid"];
        [dictionary setValue:@2 forKey:@"pushstate"];
        [self addNotification:dictionary];
    }
}

- (void) udpSocket:(GCDAsyncUdpSocket *)sock didNotConnect:(NSError *)error {
    NSLog(@"连接失败");
}

- (void) udpSocket:(GCDAsyncUdpSocket *)sock didConnectToAddress:(NSData *)address {
    NSLog(@"成功连接%@", address);
}

- (void) udpSocketDidClose:(GCDAsyncUdpSocket *)sock withError:(NSError *)error {
    NSLog(@"连接关闭");
}

- (void) udpSocket:(GCDAsyncUdpSocket *)sock didSendDataWithTag:(long)tag {
    NSLog(@"发送信息成功");
}

- (void) udpSocket:(GCDAsyncUdpSocket *)sock didNotSendDataWithTag:(long)tag dueToError:(NSError *)error {
    NSLog(@"发送信息失败");
}

- (void) udpSocket:(GCDAsyncUdpSocket *)sock didReceiveData:(NSData *)data fromAddress:(NSData *)address withFilterContext:(id)filterContext {
    NSLog(@"接收到%@的消息:%@", address, data);
}

@end
