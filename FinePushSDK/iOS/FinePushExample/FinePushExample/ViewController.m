//
//  ViewController.m
//  FinePushExample
//
//  Created by Cylee on 2020/1/17.
//  Copyright © 2020年 Fine. All rights reserved.
//

#import "ViewController.h"
#import <FinePushSDK/FinePushSDK.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (IBAction)addLocalNotificaiton:(id)sender {
    NSDate* dat = [NSDate dateWithTimeIntervalSinceNow:0];
    NSTimeInterval time = [dat timeIntervalSince1970];    
    [[FinePushSDK getInstance] setTimeZone:@"Asia/Shanghai"];
    [[FinePushSDK getInstance] setNotificationSound:@"sound/notification.mp3"];
    
    NSMutableDictionary *dictionary = [[NSMutableDictionary alloc] init];
    [dictionary setValue:@"KEY001" forKey:@"PushKey"];
    [dictionary setValue:@(time+10) forKey:@"Time"];
    [dictionary setValue:@"IOS LocalNotification" forKey:@"Message"];
    [dictionary setValue:@(6) forKey:@"RepeatInterval"];
    [[FinePushSDK getInstance] addLocalNotification:dictionary];
}


- (IBAction)clearLocalNotificationByKey:(id)sender {
    NSString *key = @"KEY001";
    [[FinePushSDK getInstance] clearLocalNotificationByKey:key];
}


- (IBAction)clearAllLocalNotification:(id)sender {
    [[FinePushSDK getInstance] clearAllLocalNotification];
}


- (IBAction)addRemoteNotification:(id)sender {
    NSMutableDictionary *dictionary = [[NSMutableDictionary alloc] init];
    [dictionary setValue:@"test" forKey:@"AppID"];
    [dictionary setValue:@"test" forKey:@"AppKey"];
    [dictionary setValue:@"127.0.0.1" forKey:@"Host"];
    [dictionary setValue:@"8001" forKey:@"Port"];
    [[FinePushSDK getInstance] addRemoteNotification:dictionary];
}


@end
