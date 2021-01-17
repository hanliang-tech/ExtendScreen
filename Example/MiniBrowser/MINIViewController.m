//
//  MINIViewController.m
//  MiniBrowser
//
//  Created by BrikerMan on 12/24/2020.
//  Copyright (c) 2020 BrikerMan. All rights reserved.
//

#import "MINIViewController.h"
#import <MiniBrowser/MiniBrowser.h>

@interface MINIViewController () <MiniClientManagerDelegate>

@end

@implementation MINIViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // 查找设备
    [[MiniClientManager shared] search];
    // 设置回调
    [MiniClientManager shared].delegate = self;
	// Do any additional setup after loading the view, typically from a nib.
}

/// 设备更新接口
- (void)OnDeviceUpdate: (MiniRemoteDevice*) device {
    MiniAction *action = [[MiniAction alloc] init];
    action.params = @{
        @"key": @"value"
    };
    
    [[MiniClientManager shared] sendEvent:device action:action];
}

/// 接收设备事
- (void)onReceiveEvent: (MiniAction*) action {
    
}

@end
