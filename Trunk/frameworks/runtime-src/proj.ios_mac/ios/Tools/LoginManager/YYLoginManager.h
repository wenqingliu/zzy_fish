//
//  YYLoginManager.h
//  YYLibrary
//
//  Created by yorkyous on 15/3/1.
//  Copyright (c) 2015年 YY. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YYLoginUserEntity.h"

/// 登录类型
typedef enum
{
    YYLoginTypeUnknown = 0,
    YYLoginTypeTourist,
    YYLoginTypeSinaWeibo,
    YYLoginTypeTencent,
    YYLoginTypeWeChat,
} YYLoginType;

/// 响应的操作类型
static const int YYLoginEngineResponseLogin = 0;
static const int YYLoginEngineResponseLogout = 1;

/// 响应的结果
static const int YYLoginEngineResponseFaild = 0;
static const int YYLoginEngineResponseSucceed = 1;

/// 登录响应Block
typedef void (^YYLoginStyleResponse)(int operationType,
                                     int loginType,
                                     int result,
                                     YYLoginUserEntity *userEntity);

@interface YYLoginManager : NSObject

/// 新浪微博SDK的URI
@property (nonatomic, copy) NSString *sinaWeiboRedirectURI;

/// 腾讯SDK的URI
@property (nonatomic, copy) NSString *tencentRedirectURI;

/// 微信密钥
@property (nonatomic, copy) NSString *weChatSecret;

/**
 *  @brief 获取单例
 */
+ (id)shareSingleton;

/**
 *  @brief 用户登录，传入登录类型与响应代码
 */
- (void)startRequestLoginWithLoginType:(YYLoginType)loginType
                            completion:(YYLoginStyleResponse)response;

/**
 *  @brief 用户注销，传入登录类型与响应代码
 */
- (void)startRequestLogoutWithLogoutType:(YYLoginType)loginType
                              completion:(YYLoginStyleResponse)response;

/**
 *  @brief 在AppDelegate中的方法调用
 - (BOOL)application:(UIApplication *)application
             openURL:(NSURL *)url
   sourceApplication:(NSString *)sourceApplication
          annotation:(id)annotation
 */
- (BOOL)handleReturn:(NSURL *)url;

/**
 *  @brief 微信是否可用
 */
- (BOOL)isWeChatEnable;

/**
 *  @brief QQ是否可用
 */
- (BOOL)isQQEnable;

@end