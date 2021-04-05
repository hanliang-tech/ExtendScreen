//
//  MiniRemoteDevice.h
//  MiniBrowser
//
//  Created by Eliyar Eziz on 2020/12/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MiniRemoteDevice : NSObject

@property (nonatomic, copy)   NSString *friendlyName;
// 0 渲染， 1 不渲染
@property (nonatomic, copy) NSString *usn;

@property (copy, nonatomic) NSString *descriptorURL;



@end

NS_ASSUME_NONNULL_END
