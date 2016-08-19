
#ifndef AGSDK_DEFINE_H
#define AGSDK_DEFINE_H


#define DEPRECATED(_version) __attribute__((deprecated))

typedef enum {
    ePlatform_None = 0,
    ePlatform_Weixin =2,
    ePlatform_QQ = 1
}ePlatform;

typedef struct
{
    std::string key;
    std::string value;

}KVPair;

typedef struct {
    int type;
    std::string value;
    long long expiration;
}TokenRet;

typedef struct {
    int ret;
    int flag;               //返回标记，标识成功和失败类型
    std::string msg;       //返回描述
    int platform;           //当前登录的平台
    std::string open_id;
    std::string user_id;
    int user_type;
    std::vector<TokenRet> token;
    std::string pf;
    std::string pfKey;
}UserLoginRet;


typedef struct
{
    int flag;               //返回标记，标识成功和失败类型
    std::string msg;       //返回描述
    int platform;           //当前登录的平台
    std::string media_tag_name; //wx回传得meidaTagName
    std::string open_id;        //qq传递的openid
    std::string desc;           //描述
    std::string lang;          //语言     目前只有微信5.1以上用，手Q不用
    std::string country;       //国家     目前只有微信5.1以上用，手Q不用
    std::string messageExt;    //游戏分享传入自定义字符串，平台拉起游戏不做任何处理返回         目前只有微信5.1以上用，手Q不用
    std::vector<KVPair> extInfo;  //游戏－平台携带的自定义参数手Q专用
}WakeupRet;


typedef struct {
    std::string nickName;         //昵称
    std::string openId;           //帐号唯一标示
    std::string userId;           //当应用有多个appid时，返回同一应用用户的标示
    std::string gender;           //性别
    std::string pictureSmall;     //小头像
    std::string pictureMiddle;    //中头像
    std::string pictureLarge;     //datouxiang
    std::string country;          //国家
    std::string province;          //省份(老版本属性，为了不让外部app改代码，没有放在AddressInfo)
    std::string city;             //城市(老版本属性，为了不让外部app改代码，没有放在AddressInfo)

    //手Q相关字段
    bool is_yellow_vip;
    bool is_yellow_year_vip;
    int yellow_vip_level;
    bool is_yellow_high_vip;

}PersonInfo;

typedef struct {
    int ret;
    int flag;               //返回标记，标识成功和失败类型
    std::string msg;       //返回描述
    std::vector<PersonInfo> persons;//保存好友或个人信息
    std::string extInfo; //游戏查询是传入的自定义字段，用来标示一次查询
}UserRelationRet;

typedef struct {
    int ret;
    int flag;               //返回标记，标识成功和失败类型
    std::string msg;       //返回描述
    int platform;           //当前登录的平台

    int realSaveNum;
    int payChannel;
    int payState;
    int provideState;
    std::string extendInfo;
    std::string payReserve1;
    std::string payReserve2;
    std::string payReserve3;

    std::string ysdkExtInfo;

}PayRet;

typedef enum
{
    eFlag_Succ = 0, //成功
    eFlag_Error = -1, //通用失败
    eFlag_User_QQ_NoAcessToken = 1000, // QQ&QZone login fail and can't get accesstoken
    eFlag_User_QQ_UserCancel = 1001, // QQ&QZone user has cancelled login process
    eFlag_User_QQ_LoginFail = 1002, // QQ&QZone login fail (tencentDidNotLogin)
    eFlag_User_QQ_NetworkErr = 1003, // QQ&QZone networkErr
    eFlag_User_QQ_NotInstall = 1004, // QQ is not install
    eFlag_User_QQ_NotSupportApi = 1005, // QQ don't support open api
    eFlag_User_QQ_AccessTokenExpired = 1006, // QQ&QZone networkErr
    eFlag_User_QQ_PayTokenExpired = 1007, // pay token 过期 时间
    eFlag_User_QQ_ParseJasonError = 1008, // 内部使用

    eFlag_User_WX_NotInstall = 2000, // Weixin is not installed
    eFlag_User_WX_NotSupportApi = 2001, // Weixin don't support api
    eFlag_User_WX_UserCancel = 2002, // Weixin user has cancelled
    eFlag_User_WX_UserDeny = 2003, // Weixin User has denys
    eFlag_User_WX_LoginFail = 2004, //
    eFlag_User_WX_RefreshTokenSucc = 2005, // Weixin 刷新票据成功
    eFlag_User_WX_RefreshTokenFail = 2006, // Weixin 刷新票据失败
    eFlag_User_WX_AccessTokenExpired = 2007, // Weixin accessToken过期, 尝试用refreshtoken刷新票据中
    eFlag_User_WX_RefreshTokenExpired = 2008, // Weixin refresh也过期


    eFlag_User_LocalTokenInvalid = -2,   //本地票据无效, 取值向前兼容
    eFlag_User_NeedLogin = 3001,         //需要进入登陆页
    eFlag_User_UrlLogin = 3002,          //使用拉起账号登陆
    eFlag_User_NeedSelectAccount = 3003, //需要弹出异帐号提示
    eFlag_User_LocalLogin = 3004,        //使用本地账号登陆
    eFlag_User_NotInWhiteList = 3005,    //不在白名单
    eFlag_User_CheckingToken = 3006,     //正在刷新票据 , 取值向前兼容
    eFlag_User_RelationNoPerson = 3007,

    eFlag_Pay_User_Cancle = 4001, //用户取消
    eFlag_Pay_Param_Error = 4002, //参数错误

}eFlag;

typedef enum
{
    PAYSTATE_PAYUNKOWN = -1,
    PAYSTATE_PAYSUCC = 0,
    PAYSTATE_PAYCANCEL = 1,
    PAYSTATE_PAYERROR = 2

}PayState;
typedef enum
{
    RET_SUCC = 0,
    RET_FAIL = 1

}BaseRet;
#endif
