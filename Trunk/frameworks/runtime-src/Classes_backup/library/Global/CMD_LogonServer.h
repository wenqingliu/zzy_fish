#ifndef CMD_LONGON_HEAD_FILE
#define CMD_LONGON_HEAD_FILE

#pragma pack(1)

//////////////////////////////////////////////////////////////////////////////////
//登录命令

#define MDM_GP_LOGON				1									//广场登录

//登录模式
#define SUB_GP_LOGON_GAMEID			1									//I D 登录
#define SUB_GP_LOGON_ACCOUNTS		2									//帐号登录
#define SUB_GP_REGISTER_ACCOUNTS	3									//注册帐号

//登录结果
#define SUB_GP_LOGON_SUCCESS		100									//登录成功
#define SUB_GP_LOGON_FAILURE		101									//登录失败
#define SUB_GP_LOGON_FINISH			102									//登录完成
#define SUB_GP_VALIDATE_MBCARD      103                                 //登录失败

//升级提示
#define SUB_GP_UPDATE_NOTIFY		200									//升级提示

//////////////////////////////////////////////////////////////////////////////////
//

#define MB_VALIDATE_FLAGS           0x01                                //效验密保
#define LOW_VER_VALIDATE_FLAGS      0x02                                //效验低版本

//I D 登录
struct CMD_GP_LogonGameID
{
	//系统信息
	DWORD							dwPlazaVersion;						//广场版本
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列

	//登录信息
	DWORD							dwGameID;							//游戏 I D
	TCHAR							szPassword[LEN_MD5];				//登录密码
	BYTE							cbValidateFlags;			        //校验标识
};

//帐号登录
struct CMD_GP_LogonAccounts
{
	//系统信息
	DWORD							dwPlazaVersion;						//广场版本
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列

	//登录信息
	TCHAR							szPassword[LEN_MD5];				//登录密码
	TCHAR							szAccounts[LEN_ACCOUNTS];			//登录帐号
	BYTE							cbValidateFlags;			        //校验标识
};

//注册帐号
struct CMD_GP_RegisterAccounts
{
	//系统信息
	DWORD							dwPlazaVersion;						//广场版本
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列

	//密码变量
	TCHAR							szLogonPass[LEN_MD5];				//登录密码
	TCHAR							szInsurePass[LEN_MD5];				//银行密码

	//注册信息
	WORD							wFaceID;							//头像标识
	BYTE							cbGender;							//用户性别
	TCHAR							szAccounts[LEN_ACCOUNTS];			//登录帐号
	TCHAR							szNickName[LEN_NICKNAME];			//用户昵称
	TCHAR							szSpreader[LEN_ACCOUNTS];			//推荐帐号
	TCHAR							szPassPortID[LEN_PASS_PORT_ID];		//证件号码
	TCHAR							szCompellation[LEN_COMPELLATION];	//真实名字
	BYTE							cbValidateFlags;			        //校验标识
};

//登录成功
struct CMD_GP_LogonSuccess
{
	//属性资料
	WORD							wFaceID;							//头像标识
	DWORD							dwUserID;							//用户 I D
	DWORD							dwGameID;							//游戏 I D
	DWORD							dwGroupID;							//社团标识
	DWORD							dwCustomID;							//自定标识
	DWORD							dwUserMedal;						//用户奖牌
	DWORD							dwExperience;						//经验数值
	DWORD							dwLoveLiness;						//用户魅力

	//用户成绩
	SCORE							lUserScore;							//用户金币
	SCORE							lUserInsure;						//用户银行

	//用户信息
	BYTE							cbGender;							//用户性别
	BYTE							cbMoorMachine;						//锁定机器
	TCHAR							szAccounts[LEN_ACCOUNTS];			//登录帐号
	TCHAR							szNickName[LEN_ACCOUNTS];			//用户昵称
	TCHAR							szGroupName[LEN_GROUP_NAME];		//社团名字

	//配置信息
	BYTE                            cbShowServerStatus;                 //显示服务器状态
};

//登录失败
struct CMD_GP_LogonFailure
{
	LONG							lResultCode;						//错误代码
	TCHAR							szDescribeString[128];				//描述消息
};

//登陆完成
struct CMD_GP_LogonFinish
{
	WORD							wIntermitTime;						//中断时间
	WORD							wOnLineCountTime;					//更新时间
};

//登录失败
struct CMD_GP_ValidateMBCard
{
	UINT                            uMBCardID;                          //机器序列
};

// 升级提示
struct CMD_GP_UpdateNotify
{
	BYTE							cbMustUpdate;						//强行升级
	BYTE							cbAdviceUpdate;						//建议升级
	BYTE							cbHotUpdate;						//热更新
	DWORD							dwCurrentVersion;					//当前版本
	TCHAR							szHotVer[8];						//服务端热更新版本
};

//游戏ID
struct CMD_GP_MoblieVersion
{
    WORD                            wKindID;                            //游戏I D
    DWORD                           dwVersion;                          //版本号
};


//任务类型
#define TASK_TYPE_NULL				0									//无效任务
#define TASK_TYPE_DAILY				1									//每日任务
#define TASK_TYPE_GROW				2									//成长任务

//任务条件
#define TASK_COND_NLL				0									//无效条件
#define TASK_COND_PLAY				1									//游戏局数
#define TASK_COND_WIN				2									//游戏赢局

//奖励类型
#define AWARD_TYPE_NULL				0									//无效类型
#define AWARD_TYPE_GOLD				1									//金币奖励
#define AWARD_TYPE_EXPR				2									//经验奖励
#define AWARD_TYPE_MEDAL			3									//奖牌奖励
#define AWARD_TYPE_PROP				4									//道具奖励

//道具类型
#define AWARD_SUB_TYPE_NULL			0									//无效类型
#define AWARD_SUB_TYPE_VOUCHERS		1									//话费劵


//////////////////////////////////////////////////////////////////////////////////
//携带信息 CMD_GP_LogonSuccess

#define DTP_GP_GROUP_INFO			1									//社团信息
#define DTP_GP_MEMBER_INFO			2									//会员信息
#define	DTP_GP_UNDER_WRITE			3									//个性签名
#define DTP_GP_STATION_URL			4									//主页信息

//社团信息
struct DTP_GP_GroupInfo
{
	DWORD							dwGroupID;							//社团索引
	TCHAR							szGroupName[LEN_GROUP_NAME];		//社团名字
};


#ifdef WIN32

//会员信息
struct DTP_GP_MemberInfo
{
	BYTE							cbMemberOrder;						//会员等级
	YYSYSTEMTIME                    MemberOverDate;						//到期时间
};

#endif

//////////////////////////////////////////////////////////////////////////////////
//列表命令

#define MDM_GP_SERVER_LIST			2									//列表信息

//获取命令
#define SUB_GP_GET_LIST				1									//获取列表
#define SUB_GP_GET_SERVER			2									//获取房间
#define SUB_GP_GET_ONLINE			3									//获取在线
#define SUB_GP_GET_COLLECTION		4									//获取收藏

//列表信息
#define SUB_GP_LIST_TYPE			100									//类型列表
#define SUB_GP_LIST_KIND			101									//种类列表
#define SUB_GP_LIST_NODE			102									//节点列表
#define SUB_GP_LIST_PAGE			103									//定制列表
#define SUB_GP_LIST_SERVER			104									//房间列表
#define SUB_GP_VIDEO_OPTION			105									//视频配置
#define SUB_GP_NOTICE				106									//平台公告

//完成信息
#define SUB_GP_LIST_FINISH			200									//发送完成
#define SUB_GP_SERVER_FINISH		201									//房间完成

//在线信息
#define SUB_GR_KINE_ONLINE			300									//类型在线
#define SUB_GR_SERVER_ONLINE		301									//房间在线

//////////////////////////////////////////////////////////////////////////////////

//获取在线
struct CMD_GP_GetOnline
{
	WORD							wServerCount;						//房间数目
	WORD							wOnLineServerID[MAX_SERVER];		//房间标识
};

//类型在线
struct CMD_GP_KindOnline
{
	WORD							wKindCount;							//类型数目
	tagOnLineInfoKind				OnLineInfoKind[MAX_KIND];			//类型在线
};

//房间在线
struct CMD_GP_ServerOnline
{
	WORD							wServerCount;						//房间数目
	tagOnLineInfoServer				OnLineInfoServer[MAX_SERVER];		//房间在线
};

//////////////////////////////////////////////////////////////////////////////////
//服务命令
#define MDM_GP_USER_SERVICE			3									//用户服务
#define MDM_GR_INSURE				5									//用户操作

//账号服务
#define SUB_GL_MODIFY_MACHINE		100									//修改机器
#define SUB_GL_MODIFY_LOGON_PASS	101									//修改密码
#define SUB_GL_MODIFY_INSURE_PASS	102									//修改密码
#define SUB_GL_MODIFY_UNDER_WRITE	103									//修改签名

//修改头像
#define SUB_GL_USER_FACE_INFO		200									//头像信息
#define SUB_GL_SYSTEM_FACE_INFO		201									//系统头像
#define SUB_GL_CUSTOM_FACE_INFO		202									//自定头像

//个人资料
#define SUB_GL_USER_INDIVIDUAL		301									//个人资料
#define	SUB_GL_QUERY_INDIVIDUAL		302									//查询信息
#define SUB_GL_MODIFY_INDIVDUAL     303									//修改资料
#define SUB_GL_USER_WRAP            304                                 //用户包裹

//银行服务
#define SUB_GL_USER_SAVE_SCORE		400									//存款操作
#define SUB_GL_USER_TAKE_SCORE		401									//取款操作
#define SUB_GL_USER_TRANSFER_SCORE	402									//转账操作
#define SUB_GL_USER_INSURE_INFO		403									//银行资料
#define SUB_GL_QUERY_INSURE_INFO	404									//查询银行
#define SUB_GL_USER_INSURE_SUCCESS	405									//银行成功
#define SUB_GL_USER_INSURE_FAILURE	406									//银行失败
#define SUB_GL_QUERY_USER_INFO_REQUEST	407								//查询用户
#define SUB_GL_QUERY_USER_INFO_RESULT	408								//用户信息

// 排行榜查询
#define SUB_GL_SCORE_LIST_REQUEST   420                                 //查询排行
#define SUB_GL_SCORE_LIST_RESULT    421                                 //排行结果

//操作结果
#define SUB_GL_OPERATE_SUCCESS		900									//操作成功
#define SUB_GL_OPERATE_FAILURE		901									//操作失败

//AppStore购买验证
#define SUB_MB_STORE_PURCHASE_VERIFY_REQUEST    423                     //AppStore购买验证
#define SUB_MB_STORE_PURCHASE_VERIFY_RESULT     424                     //AppStore购买验证结果

//典当功能
#define	SUB_GR_USER_PAWNSHOP_REQUEST		8							//典当查询

//////////////////////////////////////////////////////////////////////////////////

//修改密码
struct CMD_GP_ModifyLogonPass
{
	DWORD							dwUserID;							//用户 I D
	TCHAR							szDesPassword[LEN_PASSWORD];		//用户密码
	TCHAR							szScrPassword[LEN_PASSWORD];		//用户密码
};

//修改密码
struct CMD_GP_ModifyInsurePass
{
	DWORD							dwUserID;							//用户 I D
	TCHAR							szDesPassword[LEN_PASSWORD];		//用户密码
	TCHAR							szScrPassword[LEN_PASSWORD];		//用户密码
};

//修改签名
struct CMD_GP_ModifyUnderWrite
{
	DWORD							dwUserID;							//用户 I D
	TCHAR							szPassword[LEN_PASSWORD];			//用户密码
	TCHAR							szUnderWrite[LEN_UNDER_WRITE];		//个性签名
};

//////////////////////////////////////////////////////////////////////////////////

//用户头像
struct CMD_GP_UserFaceInfo
{
	WORD							wFaceID;							//头像标识
	DWORD							dwCustomID;							//自定标识
};

//修改头像
struct CMD_GP_SystemFaceInfo
{
	WORD							wFaceID;							//头像标识
	DWORD							dwUserID;							//用户 I D
	TCHAR							szPassword[LEN_PASSWORD];			//用户密码
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列
};

//修改头像
struct CMD_GP_CustomFaceInfo
{
	DWORD							dwUserID;							//用户 I D
	TCHAR							szPassword[LEN_PASSWORD];			//用户密码
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列
	DWORD							dwCustomFace[FACE_CX*FACE_CY];		//图片信息
};

//////////////////////////////////////////////////////////////////////////////////

//绑定机器
struct CMD_GP_ModifyMachine
{
	BYTE							cbBind;								//绑定标志
	DWORD							dwUserID;							//用户标识
	TCHAR							szPassword[LEN_PASSWORD];			//用户密码
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列
};

//////////////////////////////////////////////////////////////////////////////////

//个人资料
struct CMD_GP_UserIndividual
{
	DWORD							dwUserID;							//用户 I D
};

//查询信息
struct CMD_GP_QueryIndividual
{
	DWORD							dwUserID;							//用户 I D
	//TCHAR							szPassword[LEN_PASSWORD];			//用户密码
};

//修改资料
struct CMD_GP_ModifyIndividual
{
	BYTE							cbGender;							//用户性别
	DWORD							dwUserID;							//用户 I D
	TCHAR							szPassword[LEN_PASSWORD];			//用户密码
};

//查询包裹
struct CMD_GP_WrapIndividual
{
	DWORD							dwUserID;							//用户 I D
};

//////////////////////////////////////////////////////////////////////////////////
//携带信息 
#define DTP_GP_UI_NICKNAME			1									//用户昵称
#define DTP_GP_UI_USER_NOTE			2									//用户说明
#define DTP_GP_UI_UNDER_WRITE		3									//个性签名
#define DTP_GP_UI_QQ				4									//Q Q 号码
#define DTP_GP_UI_EMAIL				5									//电子邮件
#define DTP_GP_UI_SEAT_PHONE		6									//固定电话
#define DTP_GP_UI_MOBILE_PHONE		7									//移动电话
#define DTP_GP_UI_COMPELLATION		8									//真实名字
#define DTP_GP_UI_DWELLING_PLACE	9									//联系地址
#define DTP_GP_UI_PASSPORTID        10                                  //身份证号

//////////////////////////////////////////////////////////////////////////////////

//银行资料
struct CMD_GP_UserInsureInfo
{
	WORD							wRevenueTake;						//税收比例
	WORD							wRevenueTransfer;					//税收比例
	WORD							wServerID;							//房间标识
	SCORE							lUserScore;							//用户金币
	SCORE							lUserInsure;						//银行金币
	SCORE							lTransferPrerequisite;				//转账条件
};

//存入金币
struct CMD_GP_UserSaveScore
{
	DWORD							dwUserID;							//用户 I D
	SCORE							lSaveScore;							//存入金币
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列
};

//提取金币
struct CMD_GP_UserTakeScore
{
	DWORD							dwUserID;							//用户 I D
	SCORE							lTakeScore;							//提取金币
	TCHAR							szPassword[LEN_MD5];				//银行密码
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列
};

//转账金币
struct CMD_GP_UserTransferScore
{
	DWORD							dwUserID;							//用户 I D
	BYTE                            cbByNickName;                       //昵称赠送
	SCORE							lTransferScore;						//转账金币
	TCHAR							szPassword[LEN_MD5];				//银行密码
	TCHAR							szNickName[LEN_NICKNAME];			//目标用户
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列
};

//银行成功
struct CMD_GP_UserInsureSuccess
{
    DWORD							dwUserID;							//用户 I D
    SCORE							lUserScore;							//用户金币
    SCORE							lUserInsure;						//银行金币
    DWORD							dwFromGameID;						//转出ID
    DWORD							dwReceGameID;						//接收ID
    TCHAR							szNickName[LEN_NICKNAME];			//转出用户
    TCHAR							szReceName[LEN_NICKNAME];			//接收用户
    SCORE							lInsureTransfer;					//转出金币
    SCORE							lInsureRevenue;						//税额
    TCHAR							szDateTime[20];						//转账日期
    TCHAR							szDescribeString[128];				//描述消息
};

//银行失败
struct CMD_GP_UserInsureFailure
{
	LONG							lResultCode;						//错误代码
	TCHAR							szDescribeString[128];				//描述消息
};

//典当
struct CMD_GR_C_USER_PAWNSHOP_REQUEST
{
	int							wOP;	//1查  2典当
	int							wItemType;// 类型
	int							wItemCount;// 数量
};

//提取结果
struct CMD_GP_UserTakeResult
{
	DWORD							dwUserID;							//用户 I D
	SCORE							lUserScore;							//用户金币
	SCORE							lUserInsure;						//银行金币
};

//查询银行
struct CMD_GP_QueryInsureInfo
{
	DWORD							dwUserID;							//用户 I D
	//TCHAR							szPassword[LEN_MD5];				//银行密码
};

//查询用户
struct CMD_GP_QueryUserInfoRequest
{
	BYTE                            cbByNickName;                       //昵称赠送
	TCHAR							szNickName[LEN_NICKNAME];			//目标用户
};

//用户信息
struct CMD_GP_UserTransferUserInfo
{
	DWORD							dwTargetGameID;						//目标用户
	TCHAR							szNickName[LEN_NICKNAME];			//目标用户
};
//////////////////////////////////////////////////////////////////////////////////

//操作失败
struct CMD_GP_OperateFailure
{
	LONG							lResultCode;						//错误代码
	TCHAR							szDescribeString[128];				//描述消息
};

//操作成功
struct CMD_GP_OperateSuccess
{
	LONG							lResultCode;						//操作代码
	TCHAR							szDescribeString[128];				//成功消息
};

// 排行榜查询
struct CMD_MB_ScoreList_Request
{
    WORD                            wKindID;                            //游戏ID
    WORD                            wTopCount;                          //排行条数
};

// 排行榜结果
struct CMD_MB_ScoreList_Result
{
    DWORD                           dwUserID;                           //用户ID
    SCORE                           lUserScore;                         //用户分数
    TCHAR                           szNickName[LEN_NICKNAME];           //用户昵称
};

// 商品购买验证
struct tagVerifyPurchase
{
    WORD                            wKindID;                             //游戏ID
    WORD                            wOperType;                           //请求类型
    DWORD                           dwGameID;                            //用户ID
    TCHAR                           szProductID[32];                     //商品ID
    TCHAR                           szReceiptData[4096];                 //验证数据
};

// 商品购买验证结果回调
struct tagPurchaseResult
{
    UINT                            nResult;                            //购买结果(0:成功)
    WORD                            wKindID;                            //游戏ID
    DWORD                           dwGameID;                           //玩家ID
    SCORE                           lUserScore;                         //用户分数
    TCHAR                           szProductID[32];                    //商品ID
    TCHAR                           szTransactionID[20];                //交易ID
    TCHAR                           szTransDateTime[20];                //交易日期
    TCHAR                           szBuyResultDesc[32];                //结果描述
};
//////////////////////////////////////////////////////////////////////////////////
//远程服务

#define MDM_GP_REMOTE_SERVICE		4									//远程服务

//查找服务
#define SUB_GP_C_SEARCH_DATABASE	100									//数据查找
#define SUB_GP_C_SEARCH_CORRESPOND	101									//协调查找

//查找服务
#define SUB_GP_S_SEARCH_DATABASE	200									//数据查找
#define SUB_GP_S_SEARCH_CORRESPOND	201									//协调查找

//////////////////////////////////////////////////////////////////////////////////

//协调查找
struct CMD_GP_C_SearchCorrespond
{
	DWORD							dwGameID;							//游戏标识
	TCHAR							szNickName[LEN_NICKNAME];			//用户昵称
};

//协调查找
struct CMD_GP_S_SearchCorrespond
{
	WORD							wUserCount;							//用户数目
	tagUserRemoteInfo				UserRemoteInfo[16];					//用户信息
};

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

//登录命令
#define MDM_MB_LOGON				100									//广场登录

//登录模式
#define SUB_MB_LOGON_GAMEID			1									//I D 登录
#define SUB_MB_LOGON_ACCOUNTS		2									//帐号登录
#define SUB_MB_REGISTER_ACCOUNTS	3									//注册帐号
#define SUB_MB_LOGON_PTHERPLATFORM  4                                   //多平台登陆
#define SUB_MB_CHECK_VERSION		5									//版本检测
#define SUB_MB_FILL_ACCOUNT         6                                   //帐号填充
#define SUB_MB_USER_REQUEST_FAILURE 7                                   //用户请求失败

//登录结果
#define SUB_MB_LOGON_SUCCESS		100									//登录成功
#define SUB_MB_LOGON_FAILURE		101									//登录失败
#define SUB_GP_LOGIN_AWARD			104									//登录奖励

//升级提示
#define SUB_MB_UPDATE_NOTIFY		200									//升级提示
#define ITEM_NUM                    8                                   //典当数目
#define CONTINUE_LOGIN_NUM          7                                   //连续登录天数
//////////////////////////////////////////////////////////////////////////////////

//I D 登录
struct CMD_MB_LogonGameID
{
	//系统信息
	WORD							wModuleID;							//模块标识
	DWORD							dwPlazaVersion;						//广场版本
	BYTE                            cbDeviceType;                       //设备类型

	//登录信息
	DWORD							dwGameID;							//游戏 I D
	TCHAR							szPassword[LEN_MD5];				//登录密码

	//连接信息
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器标识
	TCHAR							szMobilePhone[LEN_MOBILE_PHONE];	//电话号码
};

//帐号登录
struct CMD_MB_LogonAccounts
{
	//系统信息
	WORD							wModuleID;							//模块标识
	DWORD							dwPlazaVersion;						//广场版本
	BYTE                            cbDeviceType;                       //设备类型

	//登录信息
	TCHAR							szPassword[LEN_MD5];				//登录密码
	TCHAR							szAccounts[LEN_ACCOUNTS];			//登录帐号

	//连接信息
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器标识
	TCHAR							szMobilePhone[LEN_MOBILE_PHONE];	//电话号码
};

//注册帐号
struct CMD_MB_RegisterAccounts
{
	//系统信息
	WORD							wModuleID;							//模块标识
	DWORD							dwPlazaVersion;						//广场版本
	BYTE                            cbDeviceType;                       //设备类型

	//密码变量
	TCHAR							szLogonPass[LEN_MD5];				//登录密码
	TCHAR							szInsurePass[LEN_MD5];				//银行密码

	//注册信息
	WORD							wFaceID;							//头像标识
	BYTE							cbGender;							//用户性别
	TCHAR							szAccounts[LEN_ACCOUNTS];			//登录帐号
	TCHAR							szNickName[LEN_NICKNAME];			//用户昵称

	//连接信息
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器标识
	TCHAR							szMobilePhone[LEN_MOBILE_PHONE];	//电话号码
};

/// 登录类型
#define LogonTypeTourist            0                                   //  游客
#define LogonTypeQQ                 1                                   //  QQ
#define LogonTypeSina               2                                   //  新浪
#define LogonTypeEmail              3                                   //  邮箱
#define LogonTypeNineOne            4                                   //  91
#define LogonTypeWeChat             5                                   //  微信
#define LogonType360                6                                   //  360
#define LogonTypeFeiXin             7                                   //  飞信
#define LogonTypeGameID             8                                   //  GameID

/// 帐号登录
typedef struct {
    WORD                            wkindID;                            // 模块标识
    DWORD                           dwPlazaVersion;                     // 广场版本
	TCHAR							szHotVer[8];		// 热更新版本
    BYTE                            cbDeviceType;                       // 设备类型
    BYTE                            cbAcccountType;                     // 账号类型
    BYTE                            cbGender;                           // 用户性别
    TCHAR                           cVerifyString[LEN_DECRYPTO];        // 解密令牌
    TCHAR                           szNickName[LEN_NICKNAME];           // 用户昵称
    TCHAR                           szMachineID[LEN_MACHINE_ID];        // 机器标识
    TCHAR                           szUUID[LEN_UUID];                   // 唯一标识
    TCHAR                           szPassword[LEN_MD5];                // 登录密码
    TCHAR                           szDefaultFace[LEN_URL];             // 默认头像
} CMD_MB_LogonOtherPlatform;

//绑定帐号
struct CMD_MB_FillAccounts
{
	//登录信息
	DWORD							dwUserID;							//用户I D
	TCHAR							szAccounts[LEN_ACCOUNTS];			//登录帐号
	TCHAR							szPassword[LEN_MD5];				//登录密码
    
	//连接信息
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器标识
};

//典当
struct CMD_GP_S_USER_PAWNSHOP
{
	DWORD                           ItemType[ITEM_NUM];                    // 类型
	DWORD                           ItemCount[ITEM_NUM];                   // 数量
	DWORD                           BuyPrice[ITEM_NUM];                    // 买价格
	DWORD                           SalePrice[ITEM_NUM];                   // 卖价格
	TCHAR                           ItemName[ITEM_NUM][LEN_GROUP_NAME/2];  // 商品名称
	TCHAR                           szPawnShopImageURL[LEN_USER_NOTE/2];    //典当图片URL
};

/// 登录成功
typedef struct
{
    BYTE                            cbGender;                           // 用户性别
    DWORD                           dwUserID;                           // 用户 I D
    DWORD                           dwGameID;                           // 游戏 I D
    BYTE                            cbAccountType;                      // 登录类型
    SCORE                           lUserScore;                         // 用户金币
    SCORE                           lUserDaimond;                       // 用户钻石
    TCHAR                           szUUID[LEN_UUID];                   // 唯一标识
    TCHAR                           szNickName[LEN_NICKNAME];           // 用户昵称
    TCHAR                           szFaceURL[LEN_URL];                 // 头像URL
} CMD_MB_LogonSuccess;

//登录失败
struct CMD_MB_LogonFailure
{
	LONG							lResultCode;						//错误代码
	TCHAR							szDescribeString[128];				//描述消息
};

//登录奖励
struct tagLoginAward
{
	BYTE							cbLoginCount;						//登录天数
	BYTE							cbAwardType;						//奖励类型
	BYTE							cbAwardSubType;						//奖励类型
	WORD							wAwardCount;						//奖励数目
};

struct CMD_GP_LoginAward
{
	BYTE							cbMaxCount;							//最大天数
    BYTE							cbDayCount;							//当前天数
    tagLoginAward					LoginAward[MAX_LOGIN_AWARD];		//奖励信息
};

//升级提示
struct CMD_MB_UpdateNotify
{
	BYTE							cbMustUpdate;						//强行升级
	BYTE							cbAdviceUpdate;						//建议升级
	BYTE							cbHotUpdate;						//热更新
	DWORD							dwCurrentVersion;					//当前版本
	TCHAR							szHotVer[8];						//服务端热更新版本
};

//////////////////////////////////////////////////////////////////////////////////
//列表命令

#define MDM_MB_SERVER_LIST			101									//列表信息

//列表信息
#define SUB_MB_LIST_KIND			100									//种类列表
#define SUB_MB_LIST_SERVER			101									//房间列表
#define SUB_MB_LIST_CONFIG			102									//桌子配置
#define SUB_MB_LIST_FINISH			200									//列表完成

//列表配置
struct tagMBTableConfig
{
	WORD							wKindID;							//名称索引
	WORD							wServerID;							//房间索引
	BYTE							cbConfigType;						//配置类型
    BYTE							cbValueCont;						//数值数量
	LONG							lConfigValue[16];					//配置数值
};


//大厅公告
struct CMD_GP_PlatformNotice
{
	WORD							wNoticeID;							//消息ID
	TCHAR							szSystemMessage[LEN_USER_CHAT];		//系统消息
};

//////////////////////////////////////////////////////////////////////////////////

#define MDM_MB_VALIDATE                 200								// 验证信息

#define SUB_MB_C_PUBLIC_SEEK			10								// 验证信息
#define SUB_MB_S_PUBLIC_SEEK			11								// 验证信息

typedef struct
{
    TCHAR szRandEncp[LEN_CRYPTO];
} CMD_MB_C_PublicSeek;

#define C1                              52845
#define C2                              22719
#define PUBLIC_KEY                      2063

static inline std::string Encrypt(std::string str)
{
    char result[LEN_DECRYPTO * 2];
    unsigned short key = PUBLIC_KEY;
    for (int i = 0; i < str.length(); i ++) {
        unsigned char j = (unsigned char)str.at(i) ^ (key >> 8);
        key = ((unsigned char)j + key) * C1 + C2;
        result[i * 2] = 65 + j / 26;
        result[i * 2 + 1] = 65 + j % 26;
    }
    return result;
}

static inline std::string Decrypt(std::string str)
{
     char result[LEN_DECRYPTO];
    for (int i = 0; i < str.length() / 2; i ++) {
        unsigned char j = ((unsigned char)str.at(2 * i) - 65) * 26;
        j += (unsigned char)str.at(2 * i + 1) - 65;
        result[i] = j;
    }
    result[LEN_DECRYPTO - 1] = '\0';
    std::string temp = result;
    unsigned short key = PUBLIC_KEY;
    for(int i = 0; i < temp.length(); i ++) {
        result[i] = (unsigned char)temp.at(i) ^ (key >> 8);
        key = ((unsigned char)temp.at(i) + key) * C1 + C2;
    }
    result[LEN_DECRYPTO - 1] = '\0';
    return result;
}

#pragma pack()

#endif