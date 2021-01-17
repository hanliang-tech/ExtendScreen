//
//  MiniClientManager.h
//  MiniBrowser
//
//  Created by Eliyar Eziz on 2020/12/1.
//

#import <Foundation/Foundation.h>
#import "MiniRemoteDevice.h"
#import "MiniAction.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MiniClientManagerDelegate <NSObject>
/// 设备更新接口
@optional
- (void)OnDeviceUpdate: (MiniRemoteDevice*) device;

/// 接收设备事件
@optional
- (void)onReceiveEvent: (MiniAction*) action;
 
@end


@interface MiniClientManager : NSObject

@property(nonatomic, weak)id <MiniClientManagerDelegate> delegate;

@property (nonatomic, readonly) NSString *AppId;
@property (nonatomic, readonly) NSString *IMEI;
@property (nonatomic, readonly) NSString *OAID;

+ (instancetype)shared;
- (instancetype)init NS_UNAVAILABLE; // Force deny initialization
+ (instancetype)new NS_UNAVAILABLE;

-(void) startWithAppId: (NSString *)appId;

/// 设置用户的 IEMI
/// @param IEMI IEMI
- (void)setIMEI:(NSString *)IEMI;

/// 设置当前用户的 OAID
/// @param OAID OAID
- (void)setOAID:(NSString *)OAID;

-(void) search;
-(void) stopSearch;
-(void) sendEvent: (MiniRemoteDevice*) device action: (MiniAction*) action;

@end

NS_ASSUME_NONNULL_END
