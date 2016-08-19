//
//  CCHelp.m
//  NiuOxCC
//
//  Created by yorkyous on 15/9/22.
//
//

#import "OCHelp.h"
#import <AdSupport/AdSupport.h>
#import "IOSNDKHelper-C-Interface.h"
#import "IOSNDKHelper.h"
#import "YYLoginManager.h"
#import "YYInApp.h"
#import "WXApi.h"
#import "AlixPayEngine.h"
#import "WeChatPay.h"
#import "JPUSHService.h"
#import "YYShareManager.h"
#import <CommonCrypto/CommonDigest.h>
#include "NDKHelper.h"
#include "FrameData.h"
#include "protocol.h"
#include "SpriteDefine.h"
#include "Reachability.h"
#include <sys/socket.h>
#include <sys/sysctl.h>
#include <net/if.h>
#include <net/if_dl.h>

/// 接收调用的方法名
#define kCCGameLogin                        "CCGameLogin"                           // 登录
#define kCCGameLogout                       "CCGameLogout"                          // 注销
#define kCCPay                              "CCPay"                                 // 支付
#define kCCOpenApp                          "CCOpenApp"                             // 打开应用
#define kCCSendWanpu                        "CCSendWanpu"                           // 发送万普
#define kCCSetRequestedOrientation          "CCSetRequestedOrientation"             // 临时旋转
#define kCCBundleVerision                   "CCBundleVerision"                      // 获取内部版本号
#define kCCSetJPushTag                      "CCSetJPushTag"                         // 设置推送的TAG
#define kCCShare                            "kCCShare"                              // 分享

/// 发送响应的方法名
#define ccNd_PlatForm_LogonType             @"ccNd_PlatForm_LogonType"              // 平台可登录类型
#define ccNd_Platform_LogonResult           @"ccNd_Platform_LogonResult"            // 登录结果
#define ccNd_Platform_LogonLoading          @"ccNd_Platform_LogonLoading"           // 加载资料
#define ccNd_Shop_AppStore_Buy_Info_Result  @"ccNd_Shop_AppStore_Buy_Info_Result"   //支付结果
#define ccNd_Bundle_Verision                @"ccNd_Bundle_Verision"                 // 获取内部版本号
#define ccNd_Share                          @"ccNd_Share"                           // 分享结果回调

static OCHelp *_ocHelp = nil;
@property (nonatomic, strong) NSDictionary *_userEntity;

@interface OCHelp ()

@end

@implementation OCHelp {}

#pragma mark - 初始化

+ (id)shareOCHelp
{
    if (_ocHelp == nil) {
        _ocHelp = [[OCHelp alloc] init];
    }
    return _ocHelp;
}

- (id)init
{
    self = [super init];
    if (self) {
        // 第三方登录管理设置
        self.loginManager = [YYLoginManager shareSingleton];
        [_loginManager setTencentRedirectURI:@"http://www.hj663.com"];
        [_loginManager setWeChatSecret:@"20a8589bb7d92c8cec15c13ff1e358a2"];
        
		//属性
        self._userEntity = nil;
		
        // NDKHelper设置
        [IOSNDKHelper setNDKReceiver:self];
        
        // 分享设置
        [[YYShareManager shareSingleton] setSinaRedirectURI:@"http://www.hj663.com"];
        
        // Appstore设置
        NSMutableArray *productsIds = [NSMutableArray array];
        for (NSUInteger index = 0; index < 6; index ++) {
            [productsIds addObject:[NSString stringWithFormat:@"com.royal.game.box_%ld", (long)index]];
        }
        [[YYInApp shareSingleton] setProductIds:productsIds];
        
        // 支付宝设置
        [[AlixPayEngine shareEngine] setPartnerID:@"2088011663161722"];
        [[AlixPayEngine shareEngine] setSellerID:@"2088011663161722"];
        [[AlixPayEngine shareEngine] setPrivateKey:@"MIICdgIBADANBgkqhkiG9w0BAQEFAASCAmAwggJcAgEAAoGBAMaTB8PqxPQcSRkVGvIyJUTCsRPu0g1jg8rutA1gycEDPFzO2eP8uu/6i+fbcA9C4YHbq4kLoAmxiRkww22dpi49f5mkrPzQgd2oCejVv3lJdeMkEQeMjfttpTzpeHsLvRV/50RdCI7cdd7FbUrzEWhSrackI+XKzdcqwrN0GnYZAgMBAAECgYBNPujoZ61SIKa24SToTmV9CBeGX4LKvomIKa9U/O++65lRqQ3NyISX0ekWuqAu7591upRR7XnGC4//gp6jR45bAguprrKoRwTXfNjnK0sthZ1B1EvKrddrwuVFkeRg685WZsMGGeyrYyP9YB6wHjVqq07SY56EigpKByJYUsUGeQJBAPuknwe7eupx+oIXf6BYFL1tqvtXtYxc+xmGWBa4/rdPW/xci8yFzPvu85UPkeVN8RkIAiLqjDdwuFs+sDuk+acCQQDKAzAr1OYyfMDE3Gt0uPuBDxLEyz6qEuaPCMcRgiS+y+R7EpMo/pOwDXNaBJdnzQ6BG6f+JGbOCdW2tZAsS4o/AkAn3SZMRUjthuzWWv6e2hU/BPaHJpfeCoTEwGGIB/ph87JwwgBrf+6/IlV4EaVdHAHLo1cjTOC1j6fE3KNyb2oVAkEAk0ANrfWLMoQDE7xDy5pHIcT1/mLUM66BRwOz74w48qa2zgs1H62pw6uaSKSOJIixKOUa6EJqeYdrs7nW9KK/iwJAOAJcJuEfXcrE7BS9IufQsqTo4A0JH6v0z9wZ1yDMi2d3laVHII+PJtif8wwDW8EWgQRTRu/USTNFsYlGGlE87A=="];
        
        // 唯一标识设置
        self.ifda = [ASIdentifierManager sharedManager].advertisingIdentifier.UUIDString;
#if TARGET_IPHONE_SIMULATOR
        self.ifda = @"79A3F580-D1F4-4910-B59A-BMNG3279F975";
#endif
        
        CCHelp::shareHelp();
    }
    return self;
}

#pragma mark - 公开方法

+ (NSString *)getMd5String:(NSString *)string
{
    const char *cStr = [string UTF8String];
    u_char result[16];
    CC_MD5(cStr, (CC_LONG)strlen(cStr), result);
    
    NSString *digest = [NSString stringWithFormat:@"%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
                        result[0], result[1], result[2], result[3],
                        result[4], result[5], result[6], result[7],
                        result[8], result[9], result[10],result[11],
                        result[12], result[13], result[14], result[15]];
    return digest;
}

#pragma mark - 通知方法

- (void)CCGameLogin:(NSObject *)parametersObject
{
    NSDictionary *parameters = (NSDictionary *)parametersObject;
    LogonType_Enum loginType = (LogonType_Enum)[parameters[@"loginType"] intValue];
    YYLoginType newLoginType = YYLoginTypeUnknown;
    switch (loginType) {
        case LogonType_WeChat: {
            newLoginType = YYLoginTypeWeChat;
            break;
        }
        case LogonType_Tourist: {
            newLoginType = YYLoginTypeTourist;
            break;
        }
        case LogonType_QQ: {
            newLoginType = YYLoginTypeTencent;
            break;
        }
        default:
            break;
    }
    if (newLoginType == YYLoginTypeUnknown) {
        return;
    }
    NSMutableDictionary *param = [NSMutableDictionary dictionary];
    [param setObject:ccNd_Platform_LogonResult forKey:@"methodToCall"];
    [param setObject:@(loginType).stringValue forKey:@"accountType"];
    [param setObject:_ifda forKey:@"szMachineID"];
    if (newLoginType == YYLoginTypeTourist) {
        [param setObject:_ifda forKey:@"uuid"];
        [param setObject:[[UIDevice currentDevice] name] forKey:@"acccount"];
        [param setObject:@"0" forKey:@"gender"];
        [param setObject:@"" forKey:@"bigFace"];
        [param setObject:@1 forKey:@"result"];
        [IOSNDKHelper sendMessage:ccNd_Platform_LogonResult withParameters:param];
    } else {
        [_loginManager startRequestLoginWithLoginType:newLoginType completion:^(int operationType, int loginType, int result, YYLoginUserEntity *userEntity) {
            if (userEntity != nil) {
                [param setObject:userEntity.userUUID forKey:@"uuid"];
                [param setObject:userEntity.userName forKey:@"acccount"];
                [param setObject:@(userEntity.userGender).stringValue forKey:@"gender"];
                [param setObject:userEntity.userAvatarUrl forKey:@"bigFace"];
            }
            [param setObject:@(result) forKey:@"result"];
            [IOSNDKHelper sendMessage:ccNd_Platform_LogonResult withParameters:param];
        }];
    }
}

- (void)CCGameLogout:(NSObject *)parametersObject
{
    NSDictionary *parameters = (NSDictionary *)parametersObject;
    LogonType_Enum loginType = (LogonType_Enum)[parameters[@"loginType"] intValue];
    YYLoginType newLoginType = YYLoginTypeUnknown;
    switch (loginType) {
        case LogonType_WeChat: {
            newLoginType = YYLoginTypeWeChat;
            break;
        }
        case LogonType_Tourist: {
            newLoginType = YYLoginTypeTourist;
            break;
        }
        case LogonType_QQ: {
            newLoginType = YYLoginTypeTencent;
            break;
        }
        default:
            break;
    }
    if (newLoginType == YYLoginTypeUnknown || newLoginType == YYLoginTypeTourist) {
        return;
    }
    [_loginManager startRequestLogoutWithLogoutType:newLoginType
                                         completion:nil];
}

- (void)CCPay:(NSObject *)parametersObject
{
    NSDictionary *parameters = (NSDictionary *)parametersObject;
    if (parameters == nil) {
        return;
    }
    
    BYTE type = [parameters[@"type"] intValue];
    
    if (type == 0) {
        NSString *productID = [parameters[@"ProductID"] description];
        NSString *userID = [parameters[@"userID"] description];
        NSString *requestapi = [parameters[@"NotifyURL"] description];
        NSString *orderapi = [parameters[@"OrderURL"] description];
        NSUInteger appID = [parameters[@"appid"] integerValue];
        if (productID.length == 0 || productID.length == 0) {
            NSMutableDictionary *param = [NSMutableDictionary dictionary];
            [param setObject:ccNd_Shop_AppStore_Buy_Info_Result forKey:@"methodToCall"];
            [param setObject:parameters[@"type"] forKey:@"type"];
            [param setObject:@(0) forKey:@"result"];
            [IOSNDKHelper sendMessage:ccNd_Shop_AppStore_Buy_Info_Result withParameters:param];
            return;
        }
        
        [[YYInApp shareSingleton] setReverifyAddress:requestapi];
        [[YYInApp shareSingleton] setOrderAddress:orderapi];
        [[YYInApp shareSingleton] setAppType:appID];
        [[YYInApp shareSingleton] buyProductWithIdentified:productID
                                            userIdentified:userID
                                                  response:^(NSDictionary *buyInfo, NSError *error) {
            NSMutableDictionary *param = [NSMutableDictionary dictionaryWithDictionary:buyInfo];
            [param setObject:ccNd_Shop_AppStore_Buy_Info_Result forKey:@"methodToCall"];
            [param setObject:parameters[@"type"] forKey:@"type"];
            [param setObject:buyInfo == nil ? @(0) : @(1) forKey:@"result"];
            [IOSNDKHelper sendMessage:ccNd_Shop_AppStore_Buy_Info_Result withParameters:param];
        }];
        return;
    }
    
    if (type == 1) {
        NSString *productID = [parameters[@"ProductID"] description];
        NSString *productName = [parameters[@"ProductName"] description];
        NSString *gameID = [parameters[@"gameID"] description];
        CGFloat price = [parameters[@"Price"] floatValue];
        NSString *requestapi = [parameters[@"NotifyURL"] description];
        if (productID.length == 0 || productID.length == 0) {
            NSMutableDictionary *param = [NSMutableDictionary dictionary];
            [param setObject:ccNd_Shop_AppStore_Buy_Info_Result forKey:@"methodToCall"];
            [param setObject:parameters[@"type"] forKey:@"type"];
            [param setObject:@(0) forKey:@"result"];
            [IOSNDKHelper sendMessage:ccNd_Shop_AppStore_Buy_Info_Result withParameters:param];
            return;
        }
        
        [[AlixPayEngine shareEngine] setNotifyURL:requestapi];
        [[AlixPayEngine shareEngine] payWithShopID:productID shopName:productName gameID:gameID shopPrice:price response:^(BOOL isSucceed) {
            NSMutableDictionary *param = [NSMutableDictionary dictionary];
            [param setObject:ccNd_Shop_AppStore_Buy_Info_Result forKey:@"methodToCall"];
            [param setObject:parameters[@"type"] forKey:@"type"];
            [param setObject:@(isSucceed ? 1 : 0) forKey:@"result"];
            [param setObject:productID forKey:@"productid"];
            [param setObject:productName forKey:@"productname"];
            [param setObject:gameID forKey:@"gameid"];
            [param setObject:@(price).stringValue forKey:@"price"];
            [IOSNDKHelper sendMessage:ccNd_Shop_AppStore_Buy_Info_Result withParameters:param];
        }];
        return;
    }
    
    if (type == 5) {
        NSString *productID = [parameters[@"ProductID"] description];
        NSString *userID = [parameters[@"userID"] description];
        NSString *gameID = [parameters[@"gameID"] description];
        NSMutableString *requestapi = [NSMutableString stringWithString:parameters[@"domainURL"]];
        [requestapi appendString:@"/wxpay.aspx?appid=%@&detail=%@&userid=%@&gameid=%@"];
        if (productID.length == 0 || userID.length == 0 || gameID.length == 0) {
            NSMutableDictionary *param = [NSMutableDictionary dictionary];
            [param setObject:ccNd_Shop_AppStore_Buy_Info_Result forKey:@"methodToCall"];
            [param setObject:parameters[@"type"] forKey:@"type"];
            [param setObject:@"0" forKey:@"result"];
            [IOSNDKHelper sendMessage:ccNd_Shop_AppStore_Buy_Info_Result withParameters:param];
            return;
        }
        [[WeChatPay shareSingleton] setUrlIdentifier:@"com.wechat"];
        [[WeChatPay shareSingleton] setRequestUrl:requestapi];
        [[WeChatPay shareSingleton] sendPayWithProductID:productID userIdentifiers:@[userID, gameID] price:0 response:^(BOOL isSucceed, NSString *msg) {
            NSMutableDictionary *param = [NSMutableDictionary dictionary];
            [param setObject:ccNd_Shop_AppStore_Buy_Info_Result forKey:@"methodToCall"];
            [param setObject:parameters[@"type"] forKey:@"type"];
            [param setObject:@(isSucceed == YES ? 1 : 0) forKey:@"result"];
            [param setObject:productID forKey:@"productid"];
            [param setObject:gameID forKey:@"gameid"];
            [IOSNDKHelper sendMessage:ccNd_Shop_AppStore_Buy_Info_Result withParameters:param];
        }];
    }
}

- (void)CCOpenApp:(NSObject *)parametersObject
{
    NSDictionary *parameters = (NSDictionary *)parametersObject;
    if (parameters == nil) {
        return;
    }
    
    WORD kindid = [parameters[@"kindid"] intValue];
    NSString *openUrl = nil;
    switch (kindid) {
        case 9:
            break;
        case 27:
            openUrl = @"itms-apps://itunes.apple.com/us/app/huang-jia-you-xi/id1034181507?mt=8";
            break;
        case 2010:
            openUrl = @"itms-apps://itunes.apple.com/us/app/hai-dao-bu-yu/id940367140?mt=8";
            break;
        default:
            break;
    }
    if (openUrl.length > 0) {
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:openUrl]];
    }
}

- (void)CCSendWanpu:(NSObject *)parametersObject
{
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    BOOL isRun = [defaults boolForKey:@"kWanpuMessage"];
    if (isRun == NO) {
        int kindID = GetFrameData()->getKindID();
        NSString *URL = [NSString stringWithFormat:@"http://61.147.113.16:2020/wpad.aspx?appid=%d&idfa=%@&os=0&callbackurl=0", kindID, _ifda];
        NSLog(@"发送万普请求:%@", URL);
        NSURL *url = [NSURL URLWithString:URL];
        NSMutableURLRequest *request = [[NSMutableURLRequest alloc] initWithURL:url];
        [request setHTTPMethod:@"GET"];
        [NSURLConnection sendAsynchronousRequest:request
                                           queue:[NSOperationQueue mainQueue]
                               completionHandler:^(NSURLResponse * _Nullable response, NSData * _Nullable data, NSError * _Nullable connectionError) {
                                   if (connectionError != nil || data == nil) {
                                       return;
                                   }
                                   NSString *str = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];

                                   NSLog(@"发送万普后响应字符串:%@", str);
                                   NSDictionary *results = [NSJSONSerialization JSONObjectWithData:data
                                                                                           options:NSJSONReadingMutableLeaves
                                                                                             error:&connectionError];
                                   NSLog(@"发送万普响应解析结果:%@ \n错误信息:%@", results, connectionError);
                                   if (connectionError == nil && [@"success" isEqualToString:[results[@"result"] description]]) {
                                       [defaults setBool:YES forKey:@"kWanpuMessage"];
                                       [defaults synchronize];
                                   }
                               }];
    }
}

- (void)CCSetRequestedOrientation:(NSObject *)parametersObject
{
    NSDictionary *parameters = (NSDictionary *)parametersObject;
    if (parameters == nil) {
        return;
    }
    BOOL isPotrit = [parameters[@"requestedOrientation"] boolValue];
    if(_isPortrait == isPotrit) {
        return;
    }
    _isPortrait = isPotrit;
    if ([[UIDevice currentDevice] respondsToSelector:@selector(setOrientation:)]) {
        id deviceOrientation;
        if (_isPortrait == YES) {
            deviceOrientation = @(UIDeviceOrientationPortrait);
        } else {
            deviceOrientation = @(UIDeviceOrientationLandscapeRight);
        }
        [[UIDevice currentDevice] performSelector:@selector(setOrientation:)
                                       withObject:deviceOrientation];
        [UIViewController attemptRotationToDeviceOrientation];
    }
}

- (void)CCBundleVerision:(NSObject *)parametersObject
{
    NSMutableDictionary *param = [NSMutableDictionary dictionary];
    [param setObject:[[NSBundle mainBundle] infoDictionary][@"CFBundleVersion"] forKey:@"version"];
    [param setObject:ccNd_Bundle_Verision forKey:@"methodToCall"];
    [IOSNDKHelper sendMessage:ccNd_Bundle_Verision withParameters:param];
}

- (void)CCSetJPushTag:(NSObject *)parametersObject
{
    NSDictionary *parameters = (NSDictionary *)parametersObject;
    NSArray *tags = parameters[@"tags"];
    NSMutableSet *set = [NSMutableSet set];
    for (NSString *tag in tags) {
        [set addObject:tag];
    }
    [JPUSHService setTags:set alias:nil fetchCompletionHandle:nil];
}

- (void)CCShare:(NSObject *)parametersObject
{
    NSDictionary *parameters = (NSDictionary *)parametersObject;
    
    // 获取需要分享的数据
    BYTE type = [parameters[@"type"] intValue];
    NSString *title = parameters[@"title"];
    NSString *content = parameters[@"content"];
    NSString *link = parameters[@"link"];
    NSString *imagePath = @"share_icon";
    NSDictionary *userInfo = [YYShareManager makeDataWithLink:link imageLink:imagePath title:title content:content];
    
    // 分享结果回调
    YYShareResponse response = ^(BOOL isSucceed, NSString *msg){
        NSMutableDictionary *param = [NSMutableDictionary dictionary];
        [param setObject:ccNd_Share forKey:@"methodToCall"];
        [param setObject:@(isSucceed == YES ? 1 : 0) forKey:@"result"];
        [param setObject:msg forKey:@"message"];
        [param setObject:@(type) forKey:@"platform"];
        [IOSNDKHelper sendMessage:ccNd_Share withParameters:param];
    };
    
    [[YYShareManager shareSingleton] shareWithUserType:(YYShareType)type userInfo:userInfo response:response];
}


//上传头像
- (void)CCUploadHead:(NSObject *)parametersObject
{
    self._userEntity = [(NSDictionary *)parametersObject copy];
    UIActionSheet *actionSheet = [[UIActionSheet alloc] initWithTitle:@"请选择头像来源"
                                                             delegate:self
                                                    cancelButtonTitle:@"取消"
                                               destructiveButtonTitle:nil
                                                    otherButtonTitles:@"相机", @"相册", nil];
    [actionSheet showInView:self.viewController.view];
    
}

//头像来源选取
- (void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if (buttonIndex > 1) {
        return;
    }
    
    UIImagePickerController *imagePicker = [[UIImagePickerController alloc] init];
    [imagePicker setDelegate:self];
    [imagePicker setModalTransitionStyle:UIModalTransitionStyleFlipHorizontal];
    [imagePicker setAllowsEditing:YES];
    if (buttonIndex == 0) {
        [imagePicker setSourceType:UIImagePickerControllerSourceTypeCamera];
    } else {
        [imagePicker setSourceType:UIImagePickerControllerSourceTypePhotoLibrary];
    }
    
    [self.viewController presentViewController:imagePicker animated:YES completion:nil];
}


//完成选取
- (void)imagePickerController:(UIImagePickerController *)picker
        didFinishPickingImage:(UIImage *)image
                  editingInfo:(NSDictionary *)editingInfo
{
    // 关闭视图
    [picker dismissViewControllerAnimated:YES completion:nil];
    
    // 重新隐藏状态栏
//    if ([[self.viewController controller]
//         respondsToSelector:@selector(setNeedsStatusBarAppearanceUpdate)]) {
//        [[UIApplication sharedApplication] setStatusBarHidden:YES];
//    }
    
    // 检测头像
    if (image == nil) {
        return;
    }
    
    //image为选中图片
    [[picker parentViewController] dismissModalViewControllerAnimated:YES];
    
    NSString *userID = [self._userEntity[@"userID"] description];
    NSString *domainURL = [self._userEntity[@"domainURL"] description];
    NSLog(@"userID:%@,url:%@",userID,domainURL);
    NSString *appUploadApi =  [NSString stringWithFormat:@"%@%@",domainURL, @"/UploadFace.aspx"];
    NSMutableDictionary *param = [NSMutableDictionary dictionary];
    
    
    
    
    [param setObject:userID
              forKey:@"userid"];
    NSData *imageData = UIImageJPEGRepresentation(image, 1.0);
    [param setObject:    [imageData base64EncodedStringWithOptions:NSDataBase64EncodingEndLineWithLineFeed]
              forKey:@"pic"];
    
    // 创建请求
    NSURL *url = [NSURL URLWithString:appUploadApi];
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc]initWithURL:url
                                                               cachePolicy:NSURLRequestUseProtocolCachePolicy
                                                           timeoutInterval:60];
    [request setHTTPMethod:@"POST"];
    
    // 设置请求头
    [request setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    
    // 设置json主体
    NSError *error = nil;
    NSData *data = [NSJSONSerialization dataWithJSONObject:param
                                                   options:NSJSONWritingPrettyPrinted
                                                     error:&error];
    
    [request setHTTPBody:data];
    
    
    [NSURLConnection sendAsynchronousRequest:request queue:[NSOperationQueue mainQueue] completionHandler:^(NSURLResponse * _Nullable response, NSData * _Nullable data, NSError * _Nullable connectionError) {
        if (connectionError == nil) {
            // 上传成功， 获取头像地址
            NSString *avatarURL = [[NSString alloc] initWithData:data
                                                        encoding:NSUTF8StringEncoding];
            NSLog(@"avatarURL:%@",avatarURL);
            NSMutableDictionary *param = [NSMutableDictionary dictionary];
            [param setObject:avatarURL forKey:@"url"];
            [param setObject:@1 forKey:@"result"];
            [param setObject:ccNd_Notify forKey:@"methodToCall"];
            [IOSNDKHelper sendMessage:ccNd_Notify withParameters:param];
        }
    }];
    
}
// 取消选取
- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker
{
    [picker dismissModalViewControllerAnimated:YES];
}


@end

static CCHelp *_ccHelp = NULL;

CCHelp *CCHelp::shareHelp()
{
    if (_ccHelp == NULL) {
        _ccHelp = new CCHelp();
    }
    return _ccHelp;
}

CCHelp::CCHelp()
{
    CCHelp::initHelp();
}

CCHelp::~CCHelp()
{

}

void CCHelp::initHelp()
{
    GetNotificationCenter()->addObserver(this,
                                         callfuncO_selector(CCHelp::CCHelpWithNotify),
                                         ccNd_PlatFormNotify,
                                         NULL);
}

void CCHelp::CCHelpWithNotify(cocos2d::Ref *ref)
{
    CNotify *pNotify = dynamic_cast<CNotify *>(ref);
    int mainType = pNotify->getMainType();
    switch (mainType) {
        case kGetCachePath: {
            // 获取缓存路径
            CCGetCachePath(pNotify);
            break;
        }
        case kGetNetworkStatus: {
            // 获取网络状态
            CCGetNetworkStatus(pNotify);
            break;
        }
        case kGetVersionCode: {
            // 获取内部版本号
            CCGetVersionCode(pNotify);
            break;
        }
        case kGetVersion: {
            // 获取版本号
            CCGetVersion(pNotify);
            break;
        }
        case kGetDeviceID: {
            // 获取设备码
            CCGetDeviceID(pNotify);
            break;
        }
        case kGetWechatEnable: {
            // 获取微信是否可用
            CCGetWechatEnable(pNotify);
            break;
        }
        case kGetQQEnable: {
            // 获取QQ是否可用
            CCGetQQEnable(pNotify);
            break;
        }
        default:
            break;
    }
}

void CCHelp::CCGetCachePath(cocos2d::Ref *ref)
{
    CNotify *pNotify = (CNotify *)ref;
    NSString *path = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES)[0];
    pNotify->m_MainString = [path cStringUsingEncoding:NSUTF8StringEncoding];
    pNotify->m_MainString = pNotify->m_MainString + "/NetworkCache/";
}

void CCHelp::CCGetNetworkStatus(cocos2d::Ref *ref)
{
    CNotify *pNotify = (CNotify *)ref;
    NetworkStatus status = [[Reachability reachabilityForInternetConnection] currentReachabilityStatus];
    pNotify->setMainType(status);
}

void CCHelp::CCGetVersionCode(cocos2d::Ref *ref)
{
    NSString *version = [[NSBundle mainBundle] infoDictionary][@"CFBundleVersion"];
    CNotify *pNotify = (CNotify *)ref;
    pNotify->setMainType([version intValue]);
}

void CCHelp::CCGetVersion(cocos2d::Ref *ref)
{
    NSString *version = [[NSBundle mainBundle] infoDictionary][@"CFBundleShortVersionString"];
    CNotify *pNotify = (CNotify *)ref;
    pNotify->m_MainString = [version cStringUsingEncoding:NSUTF8StringEncoding];
}

void CCHelp::CCGetDeviceID(cocos2d::Ref *ref)
{
    NSString *machineID = [OCHelp getMd5String:[[OCHelp shareOCHelp] ifda]];
    CNotify *pNotify = (CNotify *)ref;
    pNotify->m_MainString = [machineID cStringUsingEncoding:NSUTF8StringEncoding];
}

void CCHelp::CCGetWechatEnable(cocos2d::Ref *ref)
{
    CNotify *pNotify = (CNotify *)ref;
    pNotify->setMainType([[YYLoginManager shareSingleton] isWeChatEnable] == YES ? 1 : 0);
}

void CCHelp::CCGetQQEnable(cocos2d::Ref *ref)
{
    CNotify *pNotify = (CNotify *)ref;
    pNotify->setMainType([[YYLoginManager shareSingleton] isQQEnable] == YES ? 1 : 0);
}