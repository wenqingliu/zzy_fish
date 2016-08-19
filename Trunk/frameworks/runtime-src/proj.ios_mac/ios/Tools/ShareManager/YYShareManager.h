//
//  YYShareManager.h
//  zhajinhua
//
//  Created by yorkyous on 16/5/10.
//  Copyright © 2016年 yorkyous. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 分享回应
typedef void (^YYShareResponse)(BOOL isSucceed, NSString *msg);

// 分享类型
typedef enum
{
    YYShareTypeQQUser               = 0,    // QQ好友分享
    YYShareTypeQQZone,                      // QQ空间分享
    YYShareTypeSinaWeibo,                   // 新浪微博分享
    YYShareTypeWechatUser,                  // 微信好友分享
    YYShareTypeWechatCircle,                // 微信朋友圈分享
    YYShareTypeEmail,                       // 邮件分享
    YYShareTypeSMS,                         // 短信分享
} YYShareType;

@interface YYShareManager : NSObject

/// 新浪RedirectURI
@property (nonatomic, copy) NSString *sinaRedirectURI;

/**
 *  @brief  获取单例
 */
+ (id)shareSingleton;

/**
 *  @brief 是否安装了QQ
 */
+ (BOOL)iphoneQQInstalled;

/**
 *  @brief 是否安装了微信
 */
+ (BOOL)isWechatInstalled;

/**
 *  @brief 分享
 *
 *  @param shareType 需要分享的类型
 *  @param userInfo  分享内容，可以调用makeDataWithLink方法生成
 *  @param response  分享结果回调
 */
- (void)shareWithUserType:(YYShareType)shareType userInfo:(NSDictionary *)userInfo response:(YYShareResponse)response;

/**
 *  @brief 在AppDelegate中的方法调用
 */
- (BOOL)handleReturn:(NSURL *)url;

/**
 *  @brief 创建分享内容
 *
 *  @param link      分享链接
 *  @param imageLink 分享显示的网络图片
 *  @param title     分享标题
 *  @param content   分享内容
 */
+ (NSDictionary *)makeDataWithLink:(NSString *)link
                         imageLink:(NSString *)imageLink
                             title:(NSString *)title
                           content:(NSString *)content;

@end
