/*!
 @header WGPlatform.h
 @abstract 向外界开放的接口
 @author haywoodfu
 @version 1.00 2013/11/20 Creation
 */
#ifndef __WGPLATFORM_H__
#define __WGPLATFORM_H__

#include <string>
#include "WGCommon.h"
#include "WGPlatformObserver.h"


/**  
 * WeGame接口函数
 *
 * 该类封装了WeGame的外部接口
 */
class WGPlatform {
	friend JNIEXPORT void JNICALL ::Java_com_tencent_msdk_api_WGPlatformObserverForSO_OnWakeupNotify(JNIEnv *, jclass,
                                                                                                     jobject);
    friend JNIEXPORT void JNICALL ::Java_com_tencent_msdk_api_WGPlatformObserverForSO_OnLoginNotify(JNIEnv *, jclass,
                                                                                                    jobject);
private:
	static WGPlatform * m_pInst;
    unsigned int m_nPermissions;
    WGPlatformObserver* m_pObserver;
    
	JavaVM* m_pVM;
	WakeupRet m_lastWakeup;
	LoginRet m_lastLoginRet;
	bool needDelayWakeupNotify;
	bool needDelayLoginNotify;

    WGPlatform();
    virtual ~WGPlatform();

public:
    static WGPlatform* GetInstance();
    std::string registerChannelId;
    
	void init(JavaVM* pVM);
    void setVM(JavaVM* pVM);
    JavaVM* getVm();

	/**
     * 获取pf, 用于支付, 和pfKey配对使用
     * @param cGameCustomInfo 默认可以填空, 部分游戏经分有特殊需求可以通过此自定义字段传入特殊需求数据
     * @return pf
     */
	const std::string WGGetPf(unsigned char * cGameCustomInfo);

	/**
	 * @return 接口的支持情况
	 * @param
	 * eApiName_WGSendToQQWithPhoto = 0,
	 * eApiName_WGJoinQQGroup = 1,
	 * eApiName_WGAddGameFriendToQQ = 2,
	 * eApiName_WGBindQQGroup = 3
	 */
	bool WGCheckApiSupport(eApiName);

	WGPlatformObserver* GetObserver() const;
 
	/**
	 *   OnLoginNotify: 登陆回调
	 *   OnShareNotify: 分享回调
	 *   OnWakeupNotify: 被唤起回调
	 *   OnRelationNotify: 关系链查询回调
	 * @param pObserver 游戏传入的全局回调对象
	 */
	void WGSetObserver(WGPlatformObserver* pObserver);

	/**
	 * @param loginRet 返回的记录
	 * @return 返回值为平台id, 类型为ePlatform, 返回ePlatform_None表示没有登陆记录
	 *   loginRet.platform(类型为ePlatform)表示平台id, 可能值为ePlatform_QQ, ePlatform_Weixin, ePlatform_None.
	 *   loginRet.flag(类型为eFlag)表示当前本地票据的状态, 可能值及说明如下:
	 *     eFlag_Succ: 授权票据有效
	 *     eFlag_QQ_AccessTokenExpired: 手Q accessToken已经过期, 显示授权界面, 引导用户重新授权
	 *     eFlag_WX_AccessTokenExpired: 微信accessToken票据过期，需要调用WGRefreshWXToken刷新
	 *     eFlag_WX_RefreshTokenExpired: 微信refreshToken, 显示授权界面, 引导用户重新授权
	 *   ret.token是一个Vector<TokenRet>, 其中存放的TokenRet有type和value, 通过遍历Vector判断type来读取需要的票据. type类型定义如下:
	 *   	eToken_QQ_Access = 1,
			eToken_QQ_Pay,
        	eToken_WX_Access,
    		eToken_WX_Refresh,
     *
     * 注意: 游戏通过此接口获取到的票据以后必须传到游戏Server, 通过游戏Server调用MSDK后端验证票据接口验证票据有效以后才能让用户进入游戏.
	 */
	int WGGetLoginRecord(LoginRet& loginRet);

	/**
	 * @param platform 游戏传入的平台类型, 可能值为: ePlatform_QQ, ePlatform_Weixin
	 * @return void
	 *   通过游戏设置的全局回调的OnLoginNotify(LoginRet& loginRet)方法返回数据给游戏
	 *     loginRet.platform表示当前的授权平台, 值类型为ePlatform, 可能值为ePlatform_QQ, ePlatform_Weixin
	 *     loginRet.flag值表示返回状态, 可能值(eFlag枚举)如下：
	 *       eFlag_Succ: 返回成功, 游戏接收到此flag以后直接读取LoginRet结构体中的票据进行游戏授权流程.
	 *       eFlag_QQ_NoAcessToken: 手Q授权失败, 游戏接收到此flag以后引导用户去重新授权(重试)即可.
	 *       eFlag_QQ_UserCancel: 用户在授权过程中
	 *       eFlag_QQ_LoginFail: 手Q授权失败, 游戏接收到此flag以后引导用户去重新授权(重试)即可.
	 *       eFlag_QQ_NetworkErr: 手Q授权过程中出现网络错误, 游戏接收到此flag以后引导用户去重新授权(重试)即可.
	 *     loginRet.token是一个Vector<TokenRet>, 其中存放的TokenRet有type和value, 通过遍历Vector判断type来读取需要的票据. type(TokenType)类型定义如下:
	 *       eToken_QQ_Access,
	 *       eToken_QQ_Pay,
	 *       eToken_WX_Access,
	 *       eToken_WX_Refresh
	 */
	void WGLogin(ePlatform platform);

	/**
	 * @return bool 返回值已弃用, 全都返回true
	 */
	bool WGLogout();

	/**
	 * 获取自己的QQ资料
	 * @return void
	 *   此接口的调用结果通过OnRelationNotify(RelationRet& relationRet) 回调返回数据给游戏,
	 *   RelationRet对象的persons属性是一个Vector<PersonInfo>, 取第0个即是用户的个人信息.
	 *   手Q授权的用户可以获取到的个人信息包含:
	 *   nickname, openId, gender, pictureSmall, pictureMiddle, pictureLarge, gpsCity, 其他字段为空.
	 *   其中gpsCity字段为玩家所在城市信息，只有游戏调用过 WGGetNearbyPersonInfo 或者 WGGetLocationInfo
	 *   接口后，这个字段才有相应信息。
	 */
	bool WGQueryQQMyInfo();

	/**
	 *   回调在OnRelationNotify中,其中RelationRet.persons为一个Vector, Vector的第一项即为自己的资料
	 *   个人信息包括nickname, openId, gender, pictureSmall, pictureMiddle, pictureLarge, provice, city, gpsCity
	 *   其中gpsCity字段为玩家所在城市信息，只有游戏调用过 WGGetNearbyPersonInfo 或者 WGGetLocationInfo
	 *   接口后，这个字段才有相应信息。
	 */
	bool WGQueryWXMyInfo();

	/**
	 * @param permissions ePermission枚举值 或 运算的结果, 表示需要的授权项目
	 * @return void
	 */
	void WGSetPermission(int permissions);

	/**
	 * @param bRDMEnable 是否开启RDM的crash异常捕获上报
	 * @param bMTAEnable 是否开启MTA的crash异常捕获上报
	 */
	void WGEnableCrashReport(bool bRDMEnable, bool bMTAEnable);

	/**
     * 返回MSDK版本号
	 * @return MSDK版本号
	 */
    const std::string WGGetVersion();
	
    /**
	 * 如果没有再读assets/channel.ini中的渠道号, 故游戏测试阶段可以自己写入渠道号到assets/channel.ini用于测试.
	 * IOS返回plist中的CHANNEL_DENGTA字段
     * @return 安装渠道
     */
	const std::string WGGetChannelId();

	/**
	 * @return APP版本号
	 */
	const std::string WGGetPlatformAPPVersion(ePlatform platform);

	/**
	 * @return 注册渠道
	 */
	const std::string WGGetRegisterChannelId();

	/**
	 * 此接口用于刷新微信的accessToken
	 * refreshToken的用途就是刷新accessToken, 只要refreshToken不过期就可以通过refreshToken刷新accessToken。
	 * 有两种情况需要刷新accessToken,
	 * @return void
	 *   通过游戏设置的全局回调的OnLoginNotify(LoginRet& loginRet)方法返回数据给游戏
	 *     因为只有微信平台有refreshToken, loginRet.platform的值只会是ePlatform_Weixin
	 *     loginRet.flag值表示返回状态, 可能值(eFlag枚举)如下：
	 *       eFlag_WX_RefreshTokenSucc: 刷新票据成功, 游戏接收到此flag以后直接读取LoginRet结构体中的票据进行游戏授权流程.
	 *       eFlag_WX_RefreshTokenFail: WGRefreshWXToken调用过程中网络出错, 刷新失败, 游戏自己决定是否需要重试 WGRefreshWXToken
	 */
	void WGRefreshWXToken();

	/**
	 * @param platformType 游戏传入的平台类型, 可能值为: ePlatform_QQ, ePlatform_Weixin
	 * @return 平台的支持情况, false表示平台不支持授权, true则表示支持
	 */
	bool WGIsPlatformInstalled(ePlatform platformType);

	/**
	 * 检查平台是否支持SDK API接口
	 * @param platformType 游戏传入的平台类型, 可能值为: ePlatform_QQ, ePlatform_Weixin
	 * @return 平台的支持情况, false表示平台不支持授权, true则表示支持
	 */
    bool WGIsPlatformSupportApi(ePlatform platformType);

	/**
     * 获取pfkey，pfKey由msdk 服务器加密生成，支付过程校验
	 * @return 返回当前pf加密后对应fpKey字符串
	 */
	const std::string WGGetPfKey();
    
    /**
     *  输出msdk依赖平台版本号
     */
    void WGLogPlatformSDKVersion();//log出msdk用到的各sdk版本号

    /**
     *  @since 2.0.0
     *  此接口用于已经登录过的游戏, 在用户再次进入游戏时使用, 游戏启动时先调用此接口, 此接口会尝试到后台验证票据
     *  此接口会通过OnLoginNotify将结果回调给游戏, 本接口只会返回两种flag, eFlag_Local_Invalid和eFlag_Succ,
     *  如果本地没有票据或者本地票据验证失败返回的flag为eFlag_Local_Invalid, 游戏接到此flag则引导用户到授权页面授权即可.
     *  如果本地有票据并且验证成功, 则flag为eFlag_Succ, 游戏接到此flag则可以直接使用sdk提供的票据, 无需再次验证.
     *  @return void
     *   Callback: 验证结果通过我OnLoginNotify返回
     */
    void WGLoginWithLocalInfo();

    /**
	 *  通过外部拉起的URL登陆。该接口用于异帐号场景发生时，用户选择使用外部拉起帐号时调用。
	 *  登陆成功后通过onLoginNotify回调
	 *
	 *  @param flag 为YES时表示用户需要切换到外部帐号，此时该接口会使用上一次保存的异帐号登陆数据登陆。登陆成功后通过onLoginNotify回调；如果没有票据，或票据无效函数将会返回NO，不会发生onLoginNotify回调。
	 *              为NO时表示用户继续使用原帐号，此时删除保存的异帐号数据，避免产生混淆。
	 *
	 *  @return 如果没有票据，或票据无效将会返回NO；其它情况返回YES
	 */
    bool WGSwitchUser(bool flag);

protected:
	void setWakeup(WakeupRet& wakeup);
	WakeupRet& getWakeup();

	void setLoginRet(LoginRet& lr);
	LoginRet& getLoginRet();
};
#endif

