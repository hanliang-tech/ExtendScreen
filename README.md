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



### 与扩展屏交互

与扩展屏的交互包括**启动扩展屏应用**、**启动原生应用** 和 **互发消息**。

**1、启动拓展屏应用**

```objective-c
MiniAction *action = [MiniAction esAppActionWithEsId:@"扩展屏应用的ID" esPkg:@"扩展屏应用的包名"];
[[MiniClientManager shared] sendEvent:device action: action];
```

```swift
let action = MiniAction.esAppAction(withEsId: "扩展屏应用的ID", esPkg: "扩展屏应用的包名")
MiniClientManager.shared().sendEvent(device, action: action)
```



**2、启动原生应用**

```java
// 命令示例
NSString *cmd = @"adb shell am start -a com.tencent.qqlivetv.open -d tenvideo2:\\/\\/?action=7&cover_id=rjae621myqca41h&stay_flag=0&episode_idx=0&cover_pulltype=1&pullfrom=1024051";

MiniAction *action = [MiniAction nativeAppActionWithParams:cmd];
[[MiniClientManager shared] sendEvent:device action: action];
```

```swift
let cmd = "adb shell am start -a com.tencent.qqlivetv.open -d tenvideo2:\\/\\/?action=7&cover_id=rjae621myqca41h&stay_flag=0&episode_idx=0&cover_pulltype=1&pullfrom=1024051"
        
let action = MiniAction.nativeAppAction(withParams: cmd)
MiniClientManager.shared().sendEvent(device, action: action)
```



▫ 请注意，启动原生应用的命名目前仅支持**am**指令！

**3、互发消息**

这里模拟一条业务逻辑，假如扩展屏应用展示的商品在点击之后需要手机端弹出对应的购买窗口。交互逻辑如下：

- 扩展屏应用给手机端发送`onGoodsClick`事件，并携带`goodsId`和`userToken`。
- 手机端展示之后，给扩展屏应用回复一条成功信息。

```java
// 接收消息
MiniAction *action = [MiniAction customActionWithName:@"onGoodsClickCallback" params:@"sucess" esPkg:@"扩展屏应用的包名"];
[[MiniClientManager shared] sendEvent:device action: action];
```

```swift
func onReceiveEvent(_ action: MiniAction) {
        print("==== onReceiveEvent ===  name:\(action.name)  p:\(action.params)")
        
        if action.name == "onGoodsClick" {
            let action = MiniAction.customAction(withName: "onGoodsClickCallback", params: "sucess", esPkg: "扩展屏应用的包名")
            MiniClientManager.shared().sendEvent(self.device, action: action)
        }
  }
```



▫ 请注意，互发消息仅支持手机端跟扩展屏应用之间，不支持手机端跟原生应用。

**MiniAction常用方法及说明：** mkEsAppAction 生成用于启动拓展屏应用的Action mkNativeAppAction 生成用于启动原生应用的Action mkCustomAction 生成用于发送到拓展屏应用的Action