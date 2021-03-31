# ExtendScreen

## 安装

我们可以使用 Cocoapods 安装 MiniBrowser，Podfile 添加下面的代码，然后进行 `pod install`

```ruby
pod 'ExtendScreen'
```

## 初始化 SDK

```objc
#import <ExtendScreen/MiniBrowser.h>

@implementation MINIAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // App 启动时初始化 SDK
    [[MiniClientManager shared] startWithAppId:@"AppId" channel: @"browser"];
    return YES;
}

...

@end
```

设置用户 IEMI 和 OAID
```objc
/// 设置用户的 IEMI
- (void)setIMEI:(NSString *)IEMI;

/// 设置当前用户的 OAID
- (void)setOAID:(NSString *)OAID;
```

### 搜素设备

```objc
// 开始搜索
[[MiniClientManager shared] search];

// 停止搜索
[[MiniClientManager shared] stopSearch];
```

### 搜索回调

搜索设备后，可以通过 `MiniClientManagerDelegate` 来订阅到设备搜索回调和设备端消息回调。

```objc
@protocol MiniClientManagerDelegate <NSObject>
/// 设备更新接口
@optional
- (void)OnDeviceUpdate: (MiniRemoteDevice*) device;

/// 接收设备事件
@optional
- (void)onReceiveEvent: (MiniAction*) action;
 
@end
```

### 发送 Event 到设备

```objc
// 创建一个 action
MiniAction *action = [[MiniAction alloc] init];
// 自定义 Action 名字
action.name = @"Custom Action";
action.esId = @"123564q4";
action.esPkg = @"com.baidu.xxx";
// 设置 action 的 params，params 需要是一个可以转换为 json 的基础数据类型
action.params = @{
    @"key": @"value"
};

// 给选定的设备发送该 action
[[MiniClientManager shared] sendEvent:device action:action];
```
