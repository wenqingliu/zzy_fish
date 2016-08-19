//
//  WeChatPay.h
//  NiuOxCC
//
//  Created by yorkyous on 15/11/4.
//
//

#import <Foundation/Foundation.h>

/// 支付回调
typedef void (^WeChatPayResponse)(BOOL isSucceed, NSString *msg);

@interface WeChatPay : NSObject

/// 微信在URL types数组中的字典里的URL identifier键的值
@property (nonatomic, copy) NSString *urlIdentifier;

/// 请求地址
@property (nonatomic, copy) NSString *requestUrl;

/**
 *  @brief 获取单例
 */
+ (id)shareSingleton;

/**
 *  @brief 发送支付
 *
 *  @param productID       产品ID
 *  @param userIdentifiers 用户标识
 *  @param price           价格
 *  @param response        回调BLOCK
 */
- (void)sendPayWithProductID:(NSString *)productID
             userIdentifiers:(NSArray *)userIdentifiers
                       price:(NSUInteger)price
                    response:(WeChatPayResponse)response;

@end
