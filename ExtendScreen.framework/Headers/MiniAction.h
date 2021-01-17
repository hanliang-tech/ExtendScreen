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
@property (nonatomic, copy) NSDictionary *exp;
//
//
//- (NSString *)getJosnStr;

@end

NS_ASSUME_NONNULL_END
