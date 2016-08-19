//
//  YYLoginUserEntity.h
//  YYLibrary
//
//  Created by yorkyous on 15/3/1.
//  Copyright (c) 2015年 YY. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface YYLoginUserEntity : NSObject

/**
 *  @brief 创建对象
 */
+ (id)createEntity;

/// UUID
@property (nonatomic, copy) NSString *userUUID;

/// Token
@property (nonatomic, copy) NSString *userToken;

/// refresh token 微信用
@property (nonatomic, copy) NSString *refreshToken;

/// 用户名
@property (nonatomic, copy) NSString *userName;

/// 用户性别，女：0，男：1
@property (nonatomic, assign) int userGender;

/// 用户头像地址
@property (nonatomic, copy) NSString *userAvatarUrl;

/// 用户授权过期时间
@property (nonatomic, strong) NSDate *userExpirationDate;

@end
