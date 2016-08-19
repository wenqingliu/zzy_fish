//
//  AlixPayEngine.h
//  GameProject
//
//  Created by moonypaladin on 13-11-21.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/// 支付后响应回调的block
typedef void (^AlixPayResponse)(BOOL isSucceed);

@interface AlixPayEngine : NSObject

/// 回调地址
@property (nonatomic, copy) NSString *notifyURL;

/// 合作商户ID。用签约支付宝账号登录ms.alipay.com后，在账户信息页面获取。
@property (nonatomic, copy) NSString *partnerID;

/// 账户ID。用签约支付宝账号登录www.alipay.com后，在商家服务页面中获取。
@property (nonatomic, copy) NSString *sellerID;

/// 商户私钥，自助生成
@property (nonatomic, copy) NSString *privateKey;

/// 支付宝在URL types数组中的字典里的URL Schemes键值中数组第一个内容的值和游戏的BundleID一致
@property (nonatomic, copy, readonly) NSString *appScheme;

/**
 *  @brief 获取单例
 */
+ (id)shareEngine;

/**
 *  @brief 此方法由AppDelegate调用
 */
- (BOOL)handleReturn:(NSURL *)url;

/**
 *  @brief 调用支付功能，专递支付参数
 */
- (void)payWithShopID:(NSString *)shopID
             shopName:(NSString *)shopName
               gameID:(NSString *)gameID
            shopPrice:(CGFloat)shopPrice
             response:(AlixPayResponse)response;

/**
 *  @brief 取消交易
 */
- (void)cancelPay;

@end