#ifndef __GameProject__FrameData__
#define __GameProject__FrameData__


#include "TCPSocket.h"
#include "Define.h"
#include "CMD_Base.h"
#include "CMD_StructRef.h"
#include "CMD_Commom.h"
#include "CMD_PacketRef.h"

// 登陆类型
enum LogonType_Enum {
    LogonType_Tourist,
    LogonType_QQ,
    LogonType_Sina,
    LogonType_Email,
    LogonType_NineOne,
	LogonType_WeChat,
	LogonType_360,
	LogonType_Fetion,
};

class CLogonData;

class CFrameData : public TCPSocketDelegate, public CAccountDataDelegate
{

public:

	// 网络变量
	CTCPSocket*					m_pTCPSocket;					// 长时连接
	string 						m_loginAddress;
	WORD		 				m_loginPort;
	string						m_validateKey;

	string						m_szHotVer;

private:
    CLogonData                  *m_pLogonData;                  // 用户登录数据
    BYTE						m_cbGameStatus;					// 游戏状态
    BYTE                        m_cbGameClient;                 // 客户端状态
    bool                        m_bNormalClose;                 // 正常关闭

public:
    // 是否进入房间
    bool s_IsEnterRoom;
    
public:
    //构造
    static CFrameData* getInstance();
	static CFrameData* createFrameData();

public:
    CFrameData();
    ~CFrameData();
    
    //消息接收
    bool SocketDelegateWithRecvData(CSpriteData* pData);        //消息处理
	void SocketDelegateWithConnectNotfiy(bool isConnect);       //连接结果
    void SocketDelegateWithCloseNotify();                        //连接关闭

	//socket连接函数
	void doConnect();
    void doConnect(const char* domain, WORD wPort);
    void setSocketClose(bool isZeroData=false);
    void setSocketLogic(bool isNextLogic);
    bool getSocketConnect();

	//获取数据包个数
	ssize_t getDataArraySize(){
		if(m_pTCPSocket!=nullptr){
			return m_pTCPSocket->getDataArraySize();
		}
		return 0;
	}

//-----------------------------------------------------
	//客户端状态
	int getGameClientStatus(){return m_cbGameClient;};

	bool isSocketClosed(){return m_bNormalClose;};

//-----------------------------------------------------
	//连接地址
	void setLoginAddress(string& loginAddress){m_loginAddress = loginAddress;};
	string getLoginAddress(){return m_loginAddress;};

	//连接端口
	void setLoginPort(WORD loginPort){m_loginPort = loginPort;};
	const WORD getLoginPort(){return m_loginPort;};

	//验证地址
	void setValidateKey(string& validateKey){m_validateKey = validateKey;};
	string getValidateKey(){return m_validateKey;};

	//游戏kindID
	void setKindID(DWORD dwKindID)  {m_dwKindID=dwKindID;}
	DWORD getKindID()   {return m_dwKindID;}

	//版本号
	void setPlazaVersion(DWORD dwPlazaVersion)  {m_dwPlazaVersion=dwPlazaVersion;}
	DWORD getPlazaVersion() {return m_dwPlazaVersion;}

	//热更新版本
	void setHotVersion(const char* szHotVer)  {m_szHotVer = szHotVer;}
	string getHotVersion()   {return m_szHotVer;}

	//设备ID
	BYTE getDeviceType()  {return m_cbDevice;}
	void setDeviceType(BYTE cbDevice)   {m_cbDevice=cbDevice;}
    
    //后台标识
    bool isEnterBackground();
    void setIsEnterBackground(bool bIsEnterBackground);

	    
public:
    void setGameSkip(bool skip)     {m_bGameSkip=skip;}
    void setChairID(WORD wChairID)  {m_wChairID=wChairID;}
    void setTableID(WORD wTableID)  {m_wTableID=wTableID;}
    void setUserID(DWORD dwUserID)  {m_dwUserID=dwUserID;}
    void setGameID(DWORD dwGameID)  {m_dwGameID=dwGameID;}
	void setGenderID(DWORD dwGenderID)  {m_cbGender = dwGenderID;}

public:
    bool getGameSkip()  {return m_bGameSkip;}
    WORD getChairID()   {return m_wChairID;}
    WORD getTableID()   {return m_wTableID;}
    DWORD getUserID()   {return m_dwUserID;}
    DWORD getGameID()   {return m_dwGameID;}
    BYTE getGenderID()  {return m_cbGender;}


//-----------------------------------------------------

    //大厅登录
    bool OnTCPNetworkWithMBDataLoad(WORD wMainCmdID, WORD wSubCmdID, void* pData, WORD wSize);
	//房间登录
    bool OnTCPNetworkWithGRDataRoom(WORD wMainCmdID, WORD wSubCmdID, void* pData, WORD wSize);
    //获取验证字符串处理
    bool OnTCPNetworkMainMBVerify(WORD wSubCmdID, void* pData, WORD wSize);
	//登录处理
    bool OnTCPNetworkMainMBLogon(WORD wSubCmdID, void* pData, WORD wSize);

	// 大厅登录成功
    bool OnSocketSubLogonSuccess(void* pData, WORD wSize);
    // 大厅登录失败
    bool OnSocketSubLogonFailure(void* pData, WORD wSize);
    // 登陆奖励
    bool OnSocketSubLogonAward(void* pData, WORD wSize);
    // 版本更新
    bool OnSocketSubMBUpdateNotify(void* pData, WORD wSize);

	//GP命令
    bool OnTCPNetworkMainGPLogon(WORD wSubCmdID, void* pData, WORD wSize);
    //登录处理
 //   bool OnTCPNetworkMainMBLogon(WORD wSubCmdID, void* pData, WORD wSize);
    //列表处理
    bool OnTCPNetworkMainMBServerList(WORD wSubCmdID, void* pData, WORD wSize);
    //用户道具
    bool OnTCPNetworkMainMBUserProps(WORD wSubCmdID, void* pData, WORD wSize);
    //用户服务
    bool OnTCPNetworkMDMGPUserService(WORD wSubCmdID, void* pData, WORD wSize);
    //房间登录
    bool OnTCPNetworkMainGRLogon(WORD wSubCmdID, void* pData, WORD wSize);
    //配置信息
    bool OnTCPNetworkMainGRConfig(WORD wSubCmdID, void* pData, WORD wSize);
    //用户处理
    bool OnTCPNetworkMainGRUser(WORD wSubCmdID, void* pData, WORD wSize);
    //框架状态
    bool OnTCPNetworkMainGRStatus(WORD wSubCmdID, void* pData, WORD wSize);
    
    //银行命令
    bool OnTCPNetworkGRBankInsure(WORD wSubCmdID, void* pData, WORD wSize);
 //   //比赛命令
 //   bool OnTCPNetworkGRMainMatch(WORD wSubCmdID, void* pData, WORD wSize);
 //   //框架命令
    bool OnTCPNetworkMainGFFrame(WORD wSubCmdID, void* pData, WORD wSize);
    //系统命令
    bool OnTCPNetworkMainCMSystem(WORD wSubCmdID, void* pData, WORD wSize);
    //游戏命令
    bool OnTCPNetworkMainGame(WORD wSubCmdID, void* pData, WORD wSize);
    

    
    //用户道具
    bool OnSocketSubMBGetPropsInfo(void*pData, WORD wSize);
    
    
    //种类列表
    bool OnSocketSubListKind(void* pData, WORD wSize);
    //房间列表
    bool OnSocketSubListServer(void* pData, WORD wSize);
    //列表完成
    bool OnSocketSubListFinish(void* pData, WORD wSize);
    //列表配置
 //   bool OnSocketSubListConfig(void* pData, WORD wSize);
 //   
 //   //登录成功
    bool OnSocketSubGRLogonSuccess(void* pData, WORD wSize);
    //登录失败
    bool OnSocketSubGRLogonFailure(void* pData, WORD wSize);
    //登录完成
    bool OnSocketSubGRLogonFinish(void* pData, WORD wSize);
	//房间更新
	bool OnSocketSubGRUpdateNotify(void* pData, WORD wSize);

 //   
    //列表配置
    bool OnSocketSubGRConfigColumn(void* pData, WORD wSize);
    //房间配置
    bool OnSocketSubGRConfigServer(void* pData, WORD wSize);
    //道具配置
    bool OnSocketSubGRConfigPropepty(void* pData, WORD wSize);
    //配置完成
    bool OnSocketSubGRConfigFinish(void* pData, WORD wSize);
    
    //游戏状态
    bool OnSocketSubGFGameStatus(void* pData, WORD wSize);
    //游戏场景
    bool OnSocketSubGFGameScene(void* pData, WORD wSize);
    
    //系统消息
    bool OnSocketSubGFSystemMessage(void* pData, WORD wSize);
    
    //用户进入
    bool OnSocketSubUserEnter(void* pData, WORD wSize);
    //用户状态
    bool OnSocketSubUserStatus(void* pData, WORD wSize);
    //用户分数
    bool OnSocketSubUserScore(void* pData, WORD wSize);
    //用户聊天
    bool OnSocketSubGFUserChat(void* pData, WORD wSize);
    //用户表情
    bool OnSocketSubGFUserExpression(void* pData, WORD wSize);
 //   //请求失败
    bool OnSocketSubRequestFailure(void* pData, WORD wSize);
	////等待分配
	bool OnSocketSubRequestDistribute(void* pData, WORD wSize);
 //   //金币变化
    bool OnSocketSubUserGold(void* pData, WORD wSize);
    //喇叭消息
    bool OnSocketSubSpeakerNews(void* pData, WORD wSize);
 //   //-------------------------------------------------------------------------------------------------------------------------------------------------------
 //   //用户头像
 //   bool OnSocketSubGPUserFaceInfo(void* pData, WORD wSize);
 //   //个人资料
 //   bool OnSocketSubGPQueryIndividual(void* pData, WORD wSize);
 //   //个人包裹
 //   bool OnSocketSubGPWrapIndividual(void* pData, WORD wSize);
 //   
 //   //银行资料
    bool OnSocketSubGPInsureInfo(void* pData, WORD wSize);
    //银行成功
    bool OnSocketSubGPBankSucceed(void* pData, WORD wSize);
    //银行失败
    bool OnSocketSubGPBankFailure(void* pData, WORD wSize);
 //   //商品信息查询响应
 //   bool OnSocketSubGRShopInfo(void *pData, WORD wSize);
 //   
 //   
 //   //大厅命令
 //   //查询操作
    void sendPacketWithGPInsureInfo(const c_char* pszInsurePass);
    //存款操作
    void sendPacketWithGPSaveScore(LONGLONG lSaveScore);
    //取款操作
    void sendPacketWithGPTakeScore(LONGLONG lTakeScore, const c_char* pPassword);
    //转帐操作
    void sendPacketWithGPTransferScore(LONGLONG lTransferScore, const c_char* pPassword, BYTE cbType, const c_char* pNickName);
	//转账记录
	void sendPacketWithGPTransferRecord(DWORD dwGameID,DWORD dwTargetID,WORD wNumber);
 //   //商品信息查询
 //   void sendPacketWithGRShopInfo();
 //   //排行榜请求(已改为URL形式加载)
    void sendPacketWithRankInfo();
 //   //验证AppStore购买
 //   void sendPacketWithAppStorePurchase(c_char *verifyCode, c_char *productID);
	//典当操作
	//void sendPacketWithGPPawnShop(WORD wOP,WORD wItemType,WORD wItemCount);

 //   //查询用户资料
 //   void sendPacketWithGPQueryIndividual(DWORD dwUserID);
 //   //修改用户资料
    void sendPacketWithModifyIndividual(const char* nickString,BYTE cbGender, DWORD dwUserID,const c_char* szPassword, bool isMd5);
	////修改头像系统
	//void sendPacketWithModifySystemFace(WORD wFaceID, c_char* password,c_char* machineID,bool isMd5);
	//void sendPacketWithModifySystemFace(WORD wFaceID, TCHAR password[],c_char* machineID);
 //  
	////查询用户包裹
 //   void sendPacketWithGPUserWrap(DWORD dwUserID);
 //   void sendPacketWithGPGetProps(DWORD dwUserID);
 //   //-------------------------------------------------------------------------------------------------------------------------------------------------------
 //   
 //   //连接消息服务器
 //   void sendPacketWithMessageSever();
 //   
 //   //版本号检测
 //   void sendPacketWithCheckVersion(WORD wKindID, DWORD dwVersion);
 //   //帐号注册
    void sendPacketWithAccountRegister(const c_char* pAccount,const c_char* pPassword,const c_char* pBankPass,const c_char* pNickName);
    //用户登录
    void sendPacketWithUserLogon(CLogonData *logonData);
 //   //帐号登录
 //   void sendPacketWithAccountLogonKindID(WORD wKindID, c_char* pAccount, c_char* pPassword, BYTE cbDevice);
 //   //其他登陆
 //   void sendPacketWithLogonOtherPlatform(WORD wKindID, WORD wPlatformID, c_char* pOpenID, c_char* pNickName, BYTE cbDevice);
 //   //绑定帐号
 //   void sendPacketWithMBFillAccount(DWORD dwUserID, c_char* cAccount, c_char* cPassword);

    //房间登录
    void sendPacketWithEnterRoomPageCount(WORD wBehaviorFlags, tagGameServerRef* server);
 //   //91登陆
 //   void sendPacketWithNineOneUserName(c_char *UDID,c_char *nickName,DWORD Uin);
    //发送规则
    void sendPacketWithUserRule();
    //发送游戏规则
    void sendPacketWithGameOption();
	//发送喇叭
	void sendUserHorn(const c_char* szchat);
	//发送喇叭
	void sendUserHorn(const c_char* szNickName,const c_char* szchat);
    //发送表情
    void sendPacketWithUserExpression(DWORD dwTargetUserID, WORD index);
    //发送聊天
    void sendPacketWithUserChat(DWORD dwTagerUserID,const c_char* chat, WORD wSize);
 //   //发送坐下
    void sendPacketWithSitDown(WORD wTableID,WORD wChairID);
 //   //发送起立
    void sendPacketWithStandUpLeave(BYTE cbForce);
 //   //发送起立2
 //   void sendPacketWithStandUpLeave2(BYTE cbForce);
 //   //发送状态
    void sendPacketWithUserStatus(BYTE cbStatus);
    //快速坐下
	void sendPacketWithQuickStart();
	//快速加入
	void sendPacketWithQuickJin();
 //   //发送换桌
    void sendPacketWithCutoverTable();
 //   //请求用户
    void sendPacketWithRequestUserInfo(DWORD dwUserID,WORD wTableID);
 //   //请求椅子用户
    void sendPacketWithRequestChairUserInfo(WORD wTableID, WORD wChairID);

	//内核命令
	bool OnTCPNewordkWithKNCommon(WORD wMainCmdID, WORD wSubCmdID, void* pData, WORD wSize);
	//网络验证
    void sendPacketWithCompilatio();
    void sendPacketWithCompilatio(const char* ValidateKey);
public:
    //网络数据
    //void sendData(Ref* object);
	void sendData(CMD_BASE* cmd);
    void sendData(void* pData, WORD wSize);
	void sendData(WORD wMainCmdID, WORD wSubCmdID,CMD_BASE* cmd = nullptr);
    void sendData(WORD wMainCmdID, WORD wSubCmdID, void* buffer, WORD wSize);
	void sendSocketData(TCP_BufferRef* buffer, WORD wSize);

public:
	Ref* getSender(){return CFrameData::s_sender;};
    
private:
	//消息发送者
    static Node* s_sender;
	//LUA事件
	static void sendEvent(string eventName,CNotify* pData);
	bool sendEvent(WORD TypeData,WORD wMainCmdID,WORD wSubCmdID,void* pData, WORD wSize);
//    static void sendEvent(string eventName, void *pData, WORD wSize);
	//未处理事件
	static void sendUnknownEvent(WORD TypeData,WORD wMainCmdID,WORD wSubCmdID,CNotify* pData);
    /// 获取令牌
    void sendPacketWithVerifyString();
};
CFrameData* GetFrameData();

class CLogonData : public cocos2d::Ref
{
public:

	CC_SYNTHESIZE(BYTE,m_cbLogonType,LogonType);
	CC_SYNTHESIZE(BYTE,m_cbGender,Gender);
	CC_SYNTHESIZE(string,m_UUID,UUID);
	CC_SYNTHESIZE(string,m_nickName,NickName);
	CC_SYNTHESIZE(string,m_avatarURL,AvatarURL);
	CC_SYNTHESIZE(string,m_passwd,Passwd);
	CC_SYNTHESIZE(string,m_deviceid,Deviceid);

public:
    CLogonData();
    ~CLogonData();
    static CLogonData *create();
    static CLogonData *create(BYTE cbLogonType, std::string UUID, std::string passwd, std::string deviceid);
    static CLogonData *create(BYTE cbLogonType, std::string UUID, std::string deviceid);
    static CLogonData *create(BYTE cbLogonType, BYTE cbGender, std::string UUID, std::string nickName, std::string avatarURL, std::string deviceid);
};

#endif

