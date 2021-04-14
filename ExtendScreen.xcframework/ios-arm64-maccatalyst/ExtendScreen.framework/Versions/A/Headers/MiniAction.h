//
//  MiniAction.h
//  MiniBrowser
//
//  Created by Eliyar Eziz on 2020/12/1.
//

#import <Foundation/Foundation.h>

static NSString * _Nonnull const MiniAction_AC_MAIN = @"__AC_MAIN__";
static NSString * _Nonnull const MiniAction_AC_START_APP = @"__AC_APP__";

NS_ASSUME_NONNULL_BEGIN

@interface MiniAction : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) id params;
@property (nonatomic, copy) NSMutableDictionary *exp;
@property (nonatomic, copy) NSString *esId;
@property (nonatomic, copy) NSString *esPkg;


/// 启动拓展屏应用
/// @param esId 扩展屏应用的ID
/// @param esPkg 扩展屏应用的包名
+ (instancetype)esAppActionWithEsId: (nonnull NSString *)esId esPkg: (nonnull NSString *) esPkg params: (nullable id)params;

/// 启动原生应用
/// @param params 业务params，字符串或者字典
+ (instancetype)nativeAppActionWithParams: (nonnull id)params;


/// 互发消息
/// @param name 消息事件名称
/// @param params 消息参数，字符串或者字典
/// @param esPkg 扩展屏应用的包名
+ (instancetype)customActionWithName: (NSString*)name params: (id)params esPkg: (NSString*) esPkg;

@end

NS_ASSUME_NONNULL_END
