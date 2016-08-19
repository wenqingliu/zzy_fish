//
//  YYInApp.h
//  YYLibrary
//
//  Created by yorkyous on 15/3/1.
//  Copyright (c) 2015年 YY. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

/// 请求产品信息回调
typedef void (^GetProductsResponse)(NSArray *products, NSError *error);

/// 商品购买回调
typedef void (^BuyProductResponse)(NSDictionary *buyInfo, NSError *error);

/// 重新验证回调
typedef void (^ReVerifyResponse)(NSArray *buyInfoArray, NSError *error);

@interface YYInApp : NSObject

/// 获取订单号地址
@property (nonatomic, copy) NSString *orderAddress;

/// 二次验证地址
@property (nonatomic, copy) NSString *reverifyAddress;

/// 商品ID列表
@property (nonatomic, strong) NSMutableArray *productIds;

/// 游戏类型
@property (nonatomic, assign) NSUInteger appType;

/**
 *  @brief 获取单例
 */
+ (id)shareSingleton;

/**
 *  @brief 获取商品信息
 */
- (void)getProducts:(GetProductsResponse)getProductsResponse;

/**
 *  @brief 购买商品
 *  @param userIdentified:用户ID,用来在二次验证的时候交给服务器更新用户信息
 *  @param buyProductResponse:购买回调，error不为空则说明请求验证的服务器不通，否则则根据服务器返回的字典获取验证是否通过和更新后的用户资料等各种信息
 */
- (void)buyProduct:(SKProduct *)product
    userIdentified:(NSString *)userIdentified
          response:(BuyProductResponse)buyProductResponse;

/**
 *  @brief 购买商品,与上面的方法类似，传入的商品参数为商品的ID
 */
- (void)buyProductWithIdentified:(NSString *)productIdentified
                  userIdentified:(NSString *)userIdentified
                        response:(BuyProductResponse)buyProductResponse;

/**
 *  @brief 取消所有请求
 */
- (void)cancelAllRequest;

@end
