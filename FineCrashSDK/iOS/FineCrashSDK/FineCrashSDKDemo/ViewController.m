//
//  ViewController.m
//  FineCrashSDKDemo
//
//  Created by Cylee on 2020/4/19.
//  Copyright © 2020 Cylee. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (IBAction)arrayOutSide:(id)sender {
    NSLog(@"数组越界异常");
    NSMutableArray *array = [NSMutableArray array];
    NSLog(@"%@",array[1]);
}

- (IBAction)dictNull:(id)sender {
    NSLog(@"空指针异常");
    NSString *str = nil;
    NSDictionary *dic = @{@"key":str};
}

- (IBAction)divideZero:(id)sender {
    NSLog(@"除零异常");
    volatile int *a = (int *) (NULL);
    *a = 1;
}


@end
