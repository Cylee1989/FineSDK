//
//  ViewController.m
//  FineSDKDemo
//
//  Created by Cylee on 2019/3/27.
//  Copyright © 2019年 Cylee. All rights reserved.
//

#import "ViewController.h"
#import "Platform.h"

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

- (IBAction)initSDK:(id)sender {
    Platform::getInstance()->initSDK("{\"key\":\"123\"}", SDKCallBack);
}

- (IBAction)callFunction:(id)sender {
    Platform::getInstance()->callUniversalFunction("login", "{}");
}

void SDKCallBack(const char* str) {
    NSLog(@"SDKCallBack:%s", str);
}

@end
