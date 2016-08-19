//
//  CCHelp.h
//  NiuOxCC
//
//  Created by yorkyous on 15/9/22.
//
//

#import <Foundation/Foundation.h>
#import "YYLoginManager.h"
#include <iostream>
#include <string>
#include "cocos2d.h"

#define kGetCachePath                               1   // 获取缓存路径
#define kGetNetworkStatus                           2   // 获取网络状态
#define kGetVersionCode                             3   // 获取内部版本号
#define kGetVersion                                 4   // 获取版本号
#define kGetDeviceID                                5   // 获取设备码
#define kGetWechatEnable                            6   // 获取微信是否可用
#define kGetQQEnable                                7   // 获取QQ是否可用

@interface OCHelp : NSObject

/// 第三方登录管理器
@property (nonatomic, strong) YYLoginManager *loginManager;

/// 唯一标识
@property (nonatomic, copy) NSString *ifda;

/// 记录屏幕方向
@property (nonatomic, assign) BOOL isPortrait;

/// viewController
@property (nonatomic, strong) UIViewController *viewController;

/**
 *  @brief 获取该单例
 */
+ (id)shareOCHelp;

/**
 *  @brief 获取MD5字符串
 */
+ (NSString *)getMd5String:(NSString *)string;

@end

USING_NS_CC;

using namespace std;

class CCHelp : public cocos2d::Layer
{
public:
    CCHelp();
    ~CCHelp();
    static CCHelp* shareHelp();
    
    /// 初始化
    void initHelp();
    
    /// 响应通知总方法
    void CCHelpWithNotify(cocos2d::Ref *ref);
    
    /// 获取缓存路径
    void CCGetCachePath(cocos2d::Ref *ref);
    
    /// 获取网络状态
    void CCGetNetworkStatus(cocos2d::Ref *ref);
    
    /// 获取内部版本号
    void CCGetVersionCode(cocos2d::Ref *ref);
    
    /// 获取版本号
    void CCGetVersion(cocos2d::Ref *ref);
    
    /// 获取设备码
    void CCGetDeviceID(cocos2d::Ref *ref);
    
    /// 获取微信是否可用
    void CCGetWechatEnable(cocos2d::Ref *ref);
    
    /// 获取QQ是否可用
    void CCGetQQEnable(cocos2d::Ref *ref);
};