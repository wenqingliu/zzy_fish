#include "FrameData.h"
#include "SpriteStdafx.h"
#include "CCLuaEngine.h"
#include "ByteArray.h"
#include "CMD_LogonServerRef.h"
#include "HelloWorldScene.h"
#include "SDKControl.h"
#include "network/HttpClient.h"
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include "NDKHelper.h"
#endif

CFrameData* GetFrameData(){
    return CFrameData::getInstance();
}

static CFrameData* frameData=NULL;
Node* CFrameData::s_sender = NULL;
CFrameData* CFrameData::getInstance()
{
    if(!frameData){
		frameData = new CFrameData();
		s_sender = Node::create();
		s_sender->retain();
	}
    return frameData;
}

CFrameData* CFrameData::createFrameData()
{
    CFrameData* pFrameData = new CFrameData();
    pFrameData->autorelease();
    return pFrameData;
}


CFrameData::CFrameData()
{
	m_pTCPSocket=NULL;

    //数据重置
    m_cbGameStatus=0;
    m_cbGameClient=GC_NONE;
	m_loginAddress = "";
	m_validateKey = "";
	m_szHotVer = "";
	m_loginPort = 0;
    m_bNormalClose = false;
	m_pLogonData = NULL;
	auto head = sizeof(tagMobileUserInfoHead);
}

CFrameData::~CFrameData()
{
    log("~CFrameData:%p",this);
}

void CFrameData::setSocketClose(bool isZeroData/*=false*/)
{
	log("CFrameData::setSocketClose-isZeroData:%d",isZeroData);
    if(m_pTCPSocket)
    {
		log("CFrameData::setSocketClose-m_pTCPSocket");
        m_bNormalClose = true;
        m_pTCPSocket->setZeroData(isZeroData);
        m_pTCPSocket->setConnect(false);
        m_pTCPSocket->autorelease();
        m_pTCPSocket=NULL;
    }
}

void CFrameData::setSocketLogic(bool isNextLogic)
{
    if(m_pTCPSocket)
        m_pTCPSocket->m_bNextLogic=isNextLogic;
}
bool CFrameData::getSocketConnect()
{
    if(m_pTCPSocket)
        return m_pTCPSocket->getConnect();
    return false;
}

void CFrameData::doConnect()
{
	doConnect(CFrameData::getInstance()->getLoginAddress().c_str(),CFrameData::getInstance()->getLoginPort());
}

void CFrameData::doConnect(const char* domain, WORD wPort)
{
        m_bNormalClose = false;
        m_pTCPSocket=CTCPSocket::create();
        m_pTCPSocket->retain();
        m_pTCPSocket->setSocketTarget(this);
        m_pTCPSocket->socketConnect(domain, wPort);
}

void CFrameData::sendData(CMD_BASE* cmd)
{
//	int size = cmd->getSize();
//	void* data = cmd->getData();
    //CNotify* pNotify=(CNotify*)object;
    //CSpriteData* pData=(CSpriteData*)pNotify->getData();
    //sendData(pData->getMainCmdID(), pData->getSubCmdID(), pData->getData(), pData->getSize());
}
//#pragma mark 发送数据
void CFrameData::sendData(void* pData, WORD wSize)
{
    m_pTCPSocket->socketSend(pData, wSize);
}

void CFrameData::sendData(WORD wMainCmdID, WORD wSubCmdID,CMD_BASE* cmd)
{
	if(cmd != nullptr)
	{
		int size = cmd->getSize();
		void* data = cmd->getData();
		sendData(wMainCmdID,wSubCmdID,data,size);
	}else{
		sendData(wMainCmdID,wSubCmdID,0,0);
	}
}

//#pragma mark 发送数据
void CFrameData::sendData(WORD wMainCmdID, WORD wSubCmdID, void* buffer, WORD wSize)
{
   

	TCP_Buffer tcp_buffer;
	memset(&tcp_buffer,0,sizeof(TCP_Buffer));
	tcp_buffer.Head.CommandInfo.wMainCmdID=wMainCmdID;
	tcp_buffer.Head.CommandInfo.wSubCmdID=wSubCmdID;
	memcpy(&tcp_buffer.cbBuffer, buffer, wSize);
	log("CFrameData::sendData,time:%ld",YYSystemTimeNowSec());
    if (m_pTCPSocket) {
        m_pTCPSocket->socketSend(&tcp_buffer, wSize+sizeof(TCP_Head));
    }
}

void CFrameData::sendSocketData(TCP_BufferRef* tcp_buffer,WORD wSize)
{
	log("CFrameData::sendSocketData:%d,%d,%d",tcp_buffer->cmd.Head.CommandInfo.wMainCmdID,tcp_buffer->cmd.Head.CommandInfo.wSubCmdID,wSize);
	if (m_pTCPSocket) {
        m_pTCPSocket->socketSend(&tcp_buffer->cmd, wSize+sizeof(TCP_Head));
    }
}

void CFrameData::SocketDelegateWithConnectNotfiy(bool isConnect)
{
	//发送连接通知
	sendEvent(ccNd_Socket_ConnectResult, CreateNotify(isConnect?RT_SUCCESS:RT_FAILURE));

	//清理socket
	if(!isConnect)
		setSocketClose(true);
}

// 连接关闭
void CFrameData::SocketDelegateWithCloseNotify()
{
    if (m_bNormalClose == false) {
        auto notify = CreateNotify(RT_FAILURE);
		notify->setObject(this);
        sendEvent(ccNd_Socket_CloseLink,notify);
    }
	setSocketClose(true);
}
//#pragma mark 数据接收
bool CFrameData::SocketDelegateWithRecvData(CSpriteData* pData)
{
    static int enterCount = 1;
    enterCount ++;
    //数据转换
	TCP_Buffer tcpBuffer;
	memset(&tcpBuffer, 0, sizeof(TCP_Buffer));
	memcpy(&tcpBuffer, pData->getData(), pData->getSize());
	//命令码
	WORD wMainCmdID = tcpBuffer.Head.CommandInfo.wMainCmdID;
	WORD wSubCmdID	= tcpBuffer.Head.CommandInfo.wSubCmdID;
    void* buffer = tcpBuffer.cbBuffer;
	WORD size = tcpBuffer.Head.TCPInfo.wPacketSize - sizeof(TCP_Head);
	log("CFrameData:SocketDelegateWithRecvData:%p,  MainCmdID:%d, SubCmdID:%d, %ld",this,wMainCmdID, wSubCmdID,YYSystemTimeNowSec());
    
	//内核命令,心跳维护
	if(OnTCPNewordkWithKNCommon(wMainCmdID, wSubCmdID, buffer, size)==true){
		return true;
	}

	/*pData->m_wMainCmdID = wMainCmdID;
	pData->m_wSubCmdID = wSubCmdID;
	pData->m_wSize = size;
	pData->m_buffer = buffer;
	LuaEngine* engine = LuaEngine::getInstance();
	BasicScriptData scriptdata(getSender(),pData);  
	cocos2d::ScriptEvent eve(kCallFuncEvent, &scriptdata);
	engine->sendEvent(&eve);
	sendEvent(ccNd_Hall_Sub_MB_LogonResult,CreateNotify(pData,pData->m_wSize,RESULT_SUCCESS));
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("abs",pData);
	return true;*/
    //数据状态
	switch(pData->getType())
	{
		case Data_Default:
			CCAssert(false,"CFrameData:SocketDelegateWithRecvData-Data_Default");
			return 1;
		case Data_Load:
		{
			 log("数据接收！Data_Room-size:%d", size);
			 return sendEvent(Data_Load,wMainCmdID, wSubCmdID, buffer, size);
            //return this->OnTCPNetworkWithMBDataLoad(wMainCmdID, wSubCmdID, buffer, size);
		}
		case Data_Room:
		{
           CCLOG("数据接收！Data_Room-size:%d", size);
		   return sendEvent(Data_Room,wMainCmdID, wSubCmdID, buffer, size);
            //return this->OnTCPNetworkWithGRDataRoom(wMainCmdID, wSubCmdID, buffer, size); // 房间登录
		}
		default:
			CCAssert(false, "CFrameData:Data_Room-" + pData->getType());
			return true;
	}
	return true;
}

//大厅登录
bool CFrameData::OnTCPNetworkWithMBDataLoad(WORD wMainCmdID, WORD wSubCmdID, void* pData, WORD wSize)
{

	switch (wMainCmdID)						//主命令
	{
        case MDM_GP_LOGON:                  //PC原有命令码
        {
            return OnTCPNetworkMainGPLogon(wSubCmdID, pData, wSize);
        }
		case MDM_MB_LOGON:					//广场登录	100.
		{
            return OnTCPNetworkMainMBLogon(wSubCmdID, pData, wSize);
        }
		case MDM_MB_SERVER_LIST:			//列表信息	101
		{
            return OnTCPNetworkMainMBServerList(wSubCmdID, pData, wSize);
		}
        case MDM_MB_VALIDATE:                  // 获取验证字符串
        {
            return OnTCPNetworkMainMBVerify(wSubCmdID, pData, wSize);
        }
		case MDM_KN_COMMAND:				//内核命令    0
			return true;
  //          
        case MDM_GP_USER_SERVICE:           //用户服务    3
        {
            return OnTCPNetworkMDMGPUserService(wSubCmdID, pData, wSize);
        }
		default:
        {
			log("CFrameData::OnTCPNetworkWithMBDataLoad:%d",wMainCmdID);
			CCAssert(false, "CFrameData: 没有处理的case");
			return true;
        }
		
	}
	return true;
}

// GP命令
bool CFrameData::OnTCPNetworkMainGPLogon(WORD wSubCmdID, void* pData, WORD wSize)
{
	assert(wSize == sizeof(CMD_GP_UpdateNotify));
    if (wSize != sizeof(CMD_GP_UpdateNotify)) return false;
    CMD_GP_UpdateNotify *pUpdateNotify = (CMD_GP_UpdateNotify *)pData;
	sendEvent(ccNd_CheckVersionUpdate, CreateNotify(pUpdateNotify, wSize, RT_DEFAULT));
    return true;
}

bool CFrameData::OnTCPNetworkMainMBVerify(WORD wSubCmdID, void *pData, WORD wSize)
{
//    // 效验大小
//    if (wSize != sizeof(CMD_MB_C_PublicSeek))
//        return false;
//    
//    // 定义类型
//    CMD_MB_C_PublicSeek response;
//    memset(&response, 0, sizeof(CMD_MB_C_PublicSeek));
//    memcpy(&response, pData, sizeof(CMD_MB_C_PublicSeek));
//    string encrypt = YYConverUnicodeToUtf8(response.szRandEncp);
//    CCLOG("令牌字符串:%s", encrypt.c_str());
//    string decrypt = Decrypt(encrypt);
//    CCLOG("解密令牌字符串:%s", decrypt.c_str());
//    
//    //变量定义
//    CMD_MB_LogonOtherPlatform request;
//    memset(&request, 0, sizeof(CMD_MB_LogonOtherPlatform));
//    request.wkindID =  GetFrameData()->getKindID();
//    request.dwPlazaVersion = GetFrameData()->getPlazaVersion();
//    request.cbDeviceType = GetFrameData()->getDeviceType();
//    request.cbAcccountType = GetFrameData()->m_pLogonData->getLogonType();
//    request.cbGender = GetFrameData()->m_pLogonData->getGender();
//    YYConverUtf8ToUnicodeWithArray(request.cVerifyString,
//                                   LEN_DECRYPTO,
//                                   decrypt.c_str());
//    YYConverUtf8ToUnicodeWithArray(request.szNickName,
//                                   LEN_NICKNAME,
//                                   GetFrameData()->m_pLogonData->getNickName().c_str());
//    YYConverUtf8ToUnicodeWithArray(request.szMachineID,
//                                   LEN_MACHINE_ID,
//                                   GetFrameData()->m_pLogonData->getDeviceid().c_str());
//    YYConverUtf8ToUnicodeWithArray(request.szUUID,
//                                   LEN_UUID,
//                                   GetFrameData()->m_pLogonData->getUUID().c_str());
//	YYConverUtf8ToUnicodeWithArray(request.szDefaultFace,
//                                   LEN_URL,
//								   GetFrameData()->m_pLogonData->getAvatarURL().c_str());
//    if (m_pTCPSocket->getConnect() == false) {
//        auto notify = CreateNotify(NULL, 0, RT_FAILURE);
//        notify->m_MainString = "登录服务器未正常连接";
//        sendEvent(ccNd_Hall_Sub_GR_LogonResult,notify);
//        setSocketClose();
//        return false;
//    }
//    this->sendData(MDM_MB_LOGON, SUB_MB_LOGON_PTHERPLATFORM, &request, sizeof(request));
    return true;
}

// 登录处理
bool CFrameData::OnTCPNetworkMainMBLogon(WORD wSubCmdID, void* pData, WORD wSize)
{
    
	switch (wSubCmdID)
	{
		case SUB_MB_LOGON_SUCCESS:			//登录成功  100
		{
            return OnSocketSubLogonSuccess(pData, wSize);
		}
		case SUB_MB_LOGON_FAILURE:			//登录失败  101
		{
            return OnSocketSubLogonFailure(pData, wSize);
		}
        case SUB_GP_LOGIN_AWARD:            //登陆奖励  104
        {
            return OnSocketSubLogonAward(pData, wSize);
        }
        case SUB_MB_UPDATE_NOTIFY:          //版本升级  200
        {
            return OnSocketSubMBUpdateNotify(pData, wSize);
        }
		default:
        {
			CCAssert(false, "CFrameData: 登录处理:超出范围");
			return true;
        }
	}
	return true;
}


//MARK:大厅登录成功
bool CFrameData::OnSocketSubLogonSuccess(void* pData, WORD wSize)
{
	//效验大小
	/*assert(wSize== sizeof(CMD_MB_LogonSuccess));
	if(wSize!=sizeof(CMD_MB_LogonSuccess)) return false;
	CMD_MB_LogonSuccess logonSuccess;		
	memset(&logonSuccess,0,sizeof(CMD_MB_LogonSuccess));
	memcpy(&logonSuccess,pData,sizeof(CMD_MB_LogonSuccess));
	//登录数据
    memcpy(GetFrameData()->m_pNickName, logonSuccess.szNickName, sizeof(logonSuccess.szNickName));
    GetFrameData()->m_dwUserID=logonSuccess.dwUserID;
    GetFrameData()->m_dwGameID=logonSuccess.dwGameID;
    GetFrameData()->m_cbGender=logonSuccess.cbGender;*/
	/*auto notify = CreateNotify(pData,wSize,RESULT_SUCCESS);
	auto cmd = CMD_MB_LogonSuccessRef::create();
	cmd->setStruct(notify);
	notify->setObject(cmd);*/
	//关闭连接
    //setSocketClose();
	auto notify = CreateNotify(pData,wSize,RT_SUCCESS);
	notify->setObject(this);
	sendEvent(ccNd_Hall_Sub_MB_LogonResult,notify);
    //通知刷新界面
//    sendEvent(ccNd_Hall_RefreshData, NULL);
//    sendEvent(ccNd_Hall_LogonSuccess, NULL);
    log("CFrameData: 登录成功");
    
	return true;
}

//大厅登录失败
bool CFrameData::OnSocketSubLogonFailure(void* pData, WORD wSize)
{
	log("CFrameData: 登录失败");
	setSocketClose();
    sendEvent(ccNd_Hall_Sub_MB_LogonResult, CreateNotify(pData, wSize, RT_FAILURE));
	return true;
}

bool CFrameData::OnSocketSubLogonAward(void *pData, WORD wSize)
{
    return true;
}

bool CFrameData::OnSocketSubMBUpdateNotify(void *pData, WORD wSize)
{
    assert(wSize == sizeof(CMD_GP_UpdateNotify));
    if (wSize != sizeof(CMD_GP_UpdateNotify)) return false;
	auto notify = CreateNotify(pData, wSize, RT_DEFAULT);
	notify->setObject(this);
    sendEvent(ccNd_CheckVersionUpdate, notify);
    
    return true;
}

//列表处理
bool CFrameData::OnTCPNetworkMainMBServerList(WORD wSubCmdID, void* pData, WORD wSize)
{
    
	switch (wSubCmdID)
	{
		case SUB_MB_LIST_KIND:				//种类列表	100
		{
            return OnSocketSubListKind(pData, wSize);
		}
		case SUB_MB_LIST_SERVER:			//房间列表	101
		{
            return OnSocketSubListServer(pData, wSize);
		}
  //      case SUB_MB_LIST_CONFIG:            //列表配置   102
  //      {
  //          return OnSocketSubListConfig(pData, wSize);
  //      }
		case SUB_MB_LIST_FINISH:			//列表完成	200
		{
            return OnSocketSubListFinish(pData, wSize);
		}

        default:
        {
            //CCAssert(false, "CFrameData: 列表处理：超出范围");
            return false;
        }
	}
	return true;
}

//种类列表
bool CFrameData::OnSocketSubListKind(void* pData, WORD wSize)
{
    //列表处理
    sendEvent(ccNd_Hall_Sub_GR_ConfigList, CreateNotify(pData, wSize, RT_BEGAN));
    
    //变量定义
	//int nStructSize=sizeof(tagGameKind);
	//int nCount=wSize/nStructSize;
 //   
	////房间列表数组
	//Array* pArray = Array::create();
 //   
	////生成游戏房间列表
	//for(int i=0; i<nCount; i++)
	//{
	//	tagGameKind kind;
	//	memset(&kind, 0, sizeof(tagGameKind));
	//	memcpy(&kind, ((BYTE*)pData+i*nStructSize), sizeof(tagGameKind));
 //       
 //       pArray->addObject(CSpriteData::socketData((char*)&kind, nStructSize, Data_GameKind));
	//}
	
	//设置种类
    //GetFrameManager()->addManagerArray(pArray);//待修改

	CCLOG("CFrameData: 房间列表获取");

	return true;
}

//MARK:大厅列表完成
bool CFrameData::OnSocketSubListFinish(void* pData, WORD wSize)
{
    
    //关闭连接
    //setSocketClose();
    CCLOG("CFrameData: 大厅列表完成");
    CCLOG("CFrameData: 启动房间列表");
	auto notify =  CreateNotify(pData, wSize, RT_ENDED);
	notify->setObject(this);
    //处理通知
    sendEvent(ccNd_Hall_Sub_GR_ConfigList,notify);
    
    //启动房间
    //    PostNotification(ccNd_LayerNotify, "CRoomLayer");
    //sendEvent(ccNd_Hall_RefreshData, NULL);
    //GetNotificationCenter()->sharedNotificationCenter()->postNotification(ccNd_Hall_LogonSuccess);
    
    return true;
}

//房间列表
bool CFrameData::OnSocketSubListServer(void* pData, WORD wSize)
{
	assert(wSize % sizeof(tagGameServer) == 0);
	
    CCLOG("CFrameData: 房间列表处理");

	//setSocketClose();
    auto notify = CreateNotify(pData, wSize, RT_INGED);
	notify->setObject(this);
    //配置房间列表
	sendEvent(ccNd_Hall_Sub_GR_ConfigList,notify);

	return true;
}


//帐号注册
void CFrameData::sendPacketWithAccountRegister(const c_char* pAccount,const c_char* pPassword,const c_char* pBankPass,const c_char* pNickName)
{
	c_char* address = YYGetMacAddress();
	string deviceid = YYConverUft8ToMD5(address);
	//string deviceid = YYConverUft8ToMD5(logonData->getDeviceid().c_str());
    GetFrameData()->setMachineID(deviceid);

	//创建注册
	CFrameData* pFrameData = createFrameData();
	pFrameData->doConnect();
	pFrameData->sendPacketWithCompilatio();;

    //加密设置
	//tOptionEntry(true);
	//setKindID(dwKindID);
	//setDevice(DEVICE_TYPE_ANDROID);
    
	//帐号注册
	CMD_MB_RegisterAccounts registerAccount;
	memset(&registerAccount,0,sizeof(CMD_MB_RegisterAccounts));
	
	registerAccount.wModuleID       = GetFrameData()->getKindID();
	registerAccount.dwPlazaVersion  = GetFrameData()->getPlazaVersion();
	registerAccount.cbDeviceType	= GetFrameData()->getDeviceType();
	
	registerAccount.wFaceID  = 0;
	registerAccount.cbGender =  GENDER_MANKIND;
	
	YYConverUtf8ToUnicodeWithArray(registerAccount.szMachineID,
                                   LEN_MACHINE_ID,
                                   GetFrameData()->getMachineID().c_str());
	

    YYConverUtf8ToMD5Unicode(registerAccount.szLogonPass, pPassword);
    YYConverUtf8ToMD5Unicode(registerAccount.szInsurePass, pBankPass);
	YYConverUtf8ToMD5Unicode(registerAccount.szAccounts, pAccount);
	YYConverUtf8ToUnicodeWithArray(registerAccount.szNickName, LEN_NICKNAME,pNickName);
    //tOptionEntry(true);
    
	TCHAR m_pPhoneNum[12];
	memset(m_pPhoneNum,0,sizeof(m_pPhoneNum));
    memcpy(registerAccount.szMobilePhone, m_pPhoneNum, sizeof(m_pPhoneNum));

	//发送注册
    pFrameData->sendData(MDM_MB_LOGON, SUB_MB_REGISTER_ACCOUNTS, &registerAccount, sizeof(CMD_MB_RegisterAccounts));
    
	CCLOG("CFrameData: send SUB_MB_REGISTER_ACCOUNTS");
	
}

void CFrameData::sendPacketWithUserLogon(CLogonData *logonData)
{
    CCLOG("MD5加密前设备ID:%s", logonData->getDeviceid().c_str());
    CCLOG("MD5加密前UUID:%s", logonData->getUUID().c_str());
    string deviceid = YYConverUft8ToMD5(logonData->getDeviceid().c_str());
    string uuid = YYConverUft8ToMD5(logonData->getUUID().c_str());
    GetFrameData()->setMachineID(deviceid);
    CCLOG("MD5加密后设备ID:%s", deviceid.c_str());
    CCLOG("MD5加密后UUID:%s", logonData->getUUID().c_str());

    // 变量定义
    CMD_MB_LogonOtherPlatform request;
    memset(&request, 0, sizeof(CMD_MB_LogonOtherPlatform));
    request.wkindID =  GetFrameData()->getKindID();
    request.dwPlazaVersion = GetFrameData()->getPlazaVersion();
    request.cbDeviceType = GetFrameData()->getDeviceType();
    request.cbAcccountType = logonData->getLogonType();
    request.cbGender = logonData->getGender();
    YYConverUtf8ToUnicodeWithArray(request.szHotVer,
                                   8,
                                   GetFrameData()->getHotVersion().c_str());
//    YYConverUtf8ToUnicodeWithArray(request.cVerifyString,
//                                   LEN_DECRYPTO,
//                                   decrypt.c_str());
    YYConverUtf8ToUnicodeWithArray(request.szNickName,
                                   LEN_NICKNAME,
                                   logonData->getNickName().c_str());
    YYConverUtf8ToUnicodeWithArray(request.szMachineID,
                                   LEN_MACHINE_ID,
                                   GetFrameData()->getMachineID().c_str());
    YYConverUtf8ToUnicodeWithArray(request.szUUID,
                                   LEN_UUID,
                                   uuid.c_str());
    CCLOG("UUID:%s",uuid.c_str());
    YYConverUtf8ToUnicodeWithArray(request.szDefaultFace,
                                   LEN_URL,
                                   logonData->getAvatarURL().c_str());

	if(logonData->getPasswd().length() != 0){
		auto passwrod = YYConverUft8ToMD5(logonData->getPasswd().c_str());
		CCLOG("passwrod:%s",passwrod);
		YYConverUtf8ToUnicodeWithArray(request.szPassword,
                                   LEN_MD5,
								   passwrod);
	}

    //CFrameData* pFrameData = createFrameData();
    this->doConnect();
    this->sendPacketWithCompilatio();
    this->sendData(MDM_MB_LOGON, SUB_MB_LOGON_PTHERPLATFORM, &request, sizeof(request));
}

//#pragma mark 房间登录

//MARK:房间登录
//
void CFrameData::sendPacketWithEnterRoomPageCount(WORD wBehaviorFlags, tagGameServerRef *server)
{
    // 服务配置
    //GetFrameData()->setServerConfig(config);
    
    // 快速登陆标识
    //WORD wBehaviorFlags = (BEHAVIOR_LOGON_IMMEDIATELY|VIEW_MODE_PART);
    
    // 比赛登陆
    /*if(m_pRoomConfig->getServerType() == GAME_GENRE_MATCH ||
       m_pRoomConfig->getServerType() == GAME_GENRE_TIMING)
    {
        wBehaviorFlags = (BEHAVIOR_LOGON_NORMAL|VIEW_MODE_PART);
    }*/
    
	//进入房间标识
	s_IsEnterRoom = true;

    //房间登录
    CMD_GR_LogonMobile lm;
    memset(&lm,0,sizeof(CMD_GR_LogonMobile));
	lm.wGameID			= GetFrameData()->getKindID();    //游戏标识
    lm.dwProcessVersion = GetFrameData()->getPlazaVersion() ;						//进程版本
    lm.cbDeviceType		= GetFrameData()->getDeviceID();
    lm.wBehaviorFlags	= wBehaviorFlags;					//行为标识
    lm.wPageTableCount	= 1;							//页数
    lm.dwUserID			= GetFrameData()->m_dwUserID;						//用户id
    YYConverUtf8ToUnicodeWithArray(lm.szMachineID, LEN_MACHINE_ID, GetFrameData()->getMachineID().c_str());
	//YYConverUtf8ToUnicodeWithArray(lm.szPassword, LEN_MACHINE_ID, "888888");
    //YYConverUtf8ToMD5Unicode(lm.szPassword, "888888");
	GetFrameData()->doConnect(YYConverUnicodeToUtf8(server->cmd.szServerAddr),
		server->cmd.wServerPort);
    GetFrameData()->sendPacketWithCompilatio();

    // 请求坐下标识
    //if(wBehaviorFlags & BEHAVIOR_LOGON_IMMEDIATELY)
    //    m_pRoomConfig->m_bReqEnter=true;
    m_pTCPSocket->setData(Data_Room);
    
    //发送消息
    GetFrameData()->sendData(MDM_GR_LOGON, SUB_GR_LOGON_MOBILE, &lm, sizeof(CMD_GR_LogonMobile));
	log("CFrameData: sendPacketWithEnterRoomPageCount");
}

//房间登录
bool CFrameData::OnTCPNetworkWithGRDataRoom(WORD wMainCmdID, WORD wSubCmdID, void* pData, WORD wSize)
{
	log("CFrameData::OnTCPNetworkWithGRDataRoom:%d",wMainCmdID);
	switch (wMainCmdID)
	{
		case MDM_GR_LOGON:					//登录命令  1
		{
            return this->OnTCPNetworkMainGRLogon(wSubCmdID, pData, wSize);
		}
		case MDM_GR_CONFIG:					//房间配置  2
		{
              return this->OnTCPNetworkMainGRConfig(wSubCmdID, pData, wSize);
		}
		case MDM_GR_USER:					//用户命令  3
		{
            return this->OnTCPNetworkMainGRUser(wSubCmdID, pData, wSize);
		}
		case MDM_GR_STATUS:					//用户状态  4
		{
            return this->OnTCPNetworkMainGRStatus(wSubCmdID, pData, wSize);
		}
		case MDM_GF_GAME:					//游戏命令
		{
            return this->OnTCPNetworkMainGame(wSubCmdID, pData, wSize);
		}
		case MDM_GF_FRAME:					//框架命令 100
		{
            return this->OnTCPNetworkMainGFFrame(wSubCmdID, pData, wSize);
		}
		case MDM_GR_INSURE:					//银行命令
		{
            return this->OnTCPNetworkGRBankInsure(wSubCmdID, pData, wSize);
		}
		case MDM_GR_MANAGE:					//管理命令
		{
			return true;
		}
        case MDM_GR_MATCH:                  //比赛命令
        {
  //          return this->OnTCPNetworkGRMainMatch(wSubCmdID, pData, wSize);
			return true;
        }
		case MDM_CM_SYSTEM:					//系统命令  1000
		{
            return this->OnTCPNetworkMainCMSystem(wSubCmdID, pData, wSize);
		}
		default:
        {
			sendUnknownEvent(Data_Room,wMainCmdID,wSubCmdID,CreateNotify(pData,wSize,RT_DEFAULT));
			CCLOG("CFrameData:OnTCPNetworkWithGRDataRoom%d", wMainCmdID);
			return true;
        }
	}
	return true;
}


//MARK:房间登录
bool CFrameData::OnTCPNetworkMainGRLogon(WORD wSubCmdID, void* pData, WORD wSize)
{
    
	switch (wSubCmdID)
	{
		case SUB_GR_LOGON_SUCCESS:			//登录成功 100
		{
            return this->OnSocketSubGRLogonSuccess(pData, wSize);
		}
		case SUB_GR_LOGON_FAILURE:			//登录失败
		{
            return this->OnSocketSubGRLogonFailure(pData, wSize);
		}
		case SUB_GR_LOGON_FINISH:			//登录完成  102
		{
            return this->OnSocketSubGRLogonFinish(pData, wSize);
		}
		case SUB_GR_UPDATE_NOTIFY:			//更新提示 200
		{
            return this->OnSocketSubGRUpdateNotify(pData, wSize);
		}
	}
	return true;
}

//MARK:房间登录成功
bool CFrameData::OnSocketSubGRLogonSuccess(void* pData, WORD wSize)
{
    //通知成功
    sendEvent(ccNd_Hall_Sub_GR_LogonResult, CreateNotify(pData, wSize, RT_SUCCESS));
    
	CCLOG("CFrameData:OnSocketSubGRLogonSuccess");

	return true;
}

//房间登录失败
bool CFrameData::OnSocketSubGRLogonFailure(void* pData, WORD wSize)
{
	//变量定义
	CMD_GR_LogonFailure lf;
	memset(&lf,0,sizeof(CMD_GR_LogonFailure));
	memcpy(&lf, pData, sizeof(CMD_GR_LogonFailure));
	
	//登陆失败
    setSocketClose();

    auto notify = CreateNotify(pData,wSize,RT_FAILURE);
	notify->m_MainString = YYConverUnicodeToUtf8(lf.szDescribeString);
	sendEvent(ccNd_Hall_Sub_GR_LogonResult,notify);
    
	CCLOG("CFrameData:OnSocketSubGRLogonFailure");
    
	return true;
}
//MARK:房间登录完成
bool CFrameData::OnSocketSubGRLogonFinish(void* pData, WORD wSize)
{
    // 启动游戏
    if (getChairID() != INVALID_CHAIR && s_IsEnterRoom)
    {
        //发送游戏规则
        sendPacketWithGameOption();
    }
    
	if (s_IsEnterRoom) {
        m_cbGameClient = GC_GAME;
    }

    //通知完成
    sendEvent(ccNd_Hall_Sub_GR_LogonResult, CreateNotify(pData, wSize, RT_ENDED));
    log("CFrameData::OnSocketSubGRLogonFinish");
	return true;
}

bool CFrameData::OnSocketSubGRUpdateNotify(void* pData, WORD wSize)
{
	sendEvent(ccNd_CheckVersionUpdate, CreateNotify(pData, wSize, RT_DEFAULT));
	return true;
}

//配置信息
bool CFrameData::OnTCPNetworkMainGRConfig(WORD wSubCmdID, void* pData, WORD wSize)
{
	switch (wSubCmdID)
	{
		case SUB_GR_CONFIG_COLUMN:			//列表配置  100
		{
            return this->OnSocketSubGRConfigColumn(pData, wSize);
		}
		case SUB_GR_CONFIG_SERVER:			//房间配置  101
		{
            ///bbb
            return this->OnSocketSubGRConfigServer(pData, wSize);
		}
		case SUB_GR_CONFIG_PROPERTY:		//道具配置  102
		{
            return this->OnSocketSubGRConfigPropepty(pData, wSize);
		}
		case SUB_GR_CONFIG_FINISH:			//配置完成  103
		{
            return this->OnSocketSubGRConfigFinish(pData, wSize);
		}
		default:
			CCAssert(false, "CFrameData: 未处理的case");
			return true;
	}
	return true;
}


//列表配置
bool CFrameData::OnSocketSubGRConfigColumn(void* pData, WORD wSize)
{
    //配置开始
//   [[NSNotificationCenter defaultCenter] postNotificationName:whNd_Hall_Sub_GR_ConfigRoom
//    //                                                    object:nil
//     //                                                 userInfo:[NSDictionary resultDictionary:buffer size:size result:RESULT_BEGAN]];
    
	log("CFrameData::OnSocketSubGRConfigColumn");

	return true;
}
//房间配置
bool CFrameData::OnSocketSubGRConfigServer(void* pData, WORD wSize)
{
	//效验大小
	assert(wSize==sizeof(CMD_GR_ConfigServer));
	if(wSize!=sizeof(CMD_GR_ConfigServer)) return false;
	//待修改
	//房间配置
 	//CMD_GR_ConfigServer* server = (CMD_GR_ConfigServer *)pData;
  //  m_pRoomConfig->m_ConfigServer = *server;
	

  //  //规则显示设置
  //  if(m_pTableInterface)
  //  {
  //      m_pTableInterface->m_ConfigServer = *server;
  //      m_pTableInterface->ccInterfaceWithRule();
  //  }
	sendEvent(ccNd_Hall_Sub_GR_ConfigRoom, CreateNotify(pData, wSize, RT_INGED));
	log("CFrameData::OnSocketSubGRConfigServer");
	return true;
}
//道具配置
bool CFrameData::OnSocketSubGRConfigPropepty(void* pData, WORD wSize)
{
	CCLOG("CFrameData:OnSocketSubGRConfigPropepty");

	return true;
}	
//配置完成
bool CFrameData::OnSocketSubGRConfigFinish(void* pData, WORD wSize)
{
    sendEvent(ccNd_Hall_Sub_GR_ConfigRoom, CreateNotify(pData, wSize, RT_ENDED));
    
	CCLOG("CFrameData:OnSocketSubGRConfigFinish");

	return true;
}

//用户处理   //用户命令  3
bool CFrameData::OnTCPNetworkMainGRUser(WORD wSubCmdID, void* pData, WORD wSize)
{
	log("用户处理-OnTCPNetworkMainGRUser:%d",wSubCmdID);
	switch (wSubCmdID)
	{
		case SUB_GR_USER_ENTER:				//用户进入	100
		{
            return this->OnSocketSubUserEnter(pData, wSize);
		}	
		case SUB_GR_USER_SCORE:				//用户分数	101
		{
            return this->OnSocketSubUserScore(pData, wSize);
			break;
		}
		case SUB_GR_USER_STATUS:			//用户状态	102
		{
            
            return this->OnSocketSubUserStatus(pData, wSize);
		}
		case SUB_GR_REQUEST_FAILURE:		//请求失败	103
		{
            return this->OnSocketSubRequestFailure(pData, wSize);
		}
		case SUB_GR_USER_WAIT_DISTRIBUTE:	//等待分配
		{
			return this->OnSocketSubRequestDistribute(pData, wSize);
		}
        case SUB_GR_USER_AWARD:
        {
            return false;
        }
        case SUB_GR_USER_GOLD:
        {
            return OnSocketSubUserGold(pData, wSize);
        }
        case SUB_GR_PROPERTY_TRUMPET:
        {
            return OnSocketSubSpeakerNews(pData, wSize);
        }
  //       
		default:
		{
			sendUnknownEvent(Data_Room,MDM_GR_USER,wSubCmdID,CreateNotify(pData,wSize,RT_DEFAULT));
            CCLOG("CFrameData:OnTCPNetworkMainGRUser 未处理的命令%d",wSubCmdID);
			//CCAssert(false,"");
			return true;;
		}
	}
	return true;
}


//MARK:进入游戏状态*****************
bool CFrameData::OnSocketSubGFGameStatus(void* pData, WORD wSize)
{
	//效验大小
	assert(wSize==sizeof(CMD_GF_GameStatus));
	if(wSize!=sizeof(CMD_GF_GameStatus)) return false;
	
	//变量定义
	CMD_GF_GameStatus gameStatus;
	memset(&gameStatus,0,wSize);
	memcpy(&gameStatus,pData,wSize);
	
	//标识记录
    m_cbGameStatus = gameStatus.cbGameStatus;
    /*setOptionLookOn(gameStatus.cbAllowLookon?true:false);
    if(m_pRoomConfig)
        m_pRoomConfig->m_bReqEnter=false;*/
    //启动游戏通知
    if (s_IsEnterRoom) {
        m_cbGameClient = GC_GAME;
		//sendEvent(ccNd_LayerNotify,CreateNotify(1));
        //PostNotification(ccNd_LayerNotify, "CGameLayer");//进入游戏场景
    }
    CCLOG("CFrameData: CMD_GF_GameStatus");
	return true;
}

//游戏场景
bool CFrameData::OnSocketSubGFGameScene(void* pData, WORD wSize)
{
//	//游戏场景消息传递
	/*if(m_pGameDelegate)
	{
		m_pGameDelegate->OnGameMessageWithScene(pData, wSize);
		m_pGameDelegate->OnGameMessageWithScene(pData, wSize, m_cbGameStatus);
	}*/
    
//    SDKControl::getInstance()->sendMessage("CCSendWanpu");
	auto notify = CreateNotify(pData, wSize, RT_DEFAULT);
	notify->setSubType(m_cbGameStatus);
	sendEvent(ccNd_GAME_Sub_CM_SceneMessage,notify);
    CCLOG("CFrameData::OnSocketSubGFGameScene");
	return true;
}


//系统消息
bool CFrameData::OnSocketSubGFSystemMessage(void* pData, WORD wSize)
{
	//变量定义
	CMD_CM_SystemMessage *pSmgs = (CMD_CM_SystemMessage*)pData;
	WORD wHeadSize=sizeof(CMD_CM_SystemMessage)-sizeof(pSmgs->szString);
	
	//效验大小
	assert((wSize>=wHeadSize)&&(wSize==(wHeadSize+pSmgs->wLength*sizeof(TCHAR))));
	if((wSize<wHeadSize)||(wSize!=(wHeadSize+pSmgs->wLength*sizeof(TCHAR)))) return false;

	sendEvent(ccNd_Main_Sub_CM_System, CreateNotify(pData, wSize, RT_DEFAULT));
	return true;
}

//喇叭消息
bool CFrameData::OnSocketSubSpeakerNews(void* pData, WORD wSize)
{
    //效验参数
    assert(wSize==sizeof(CMD_GR_S_SendTrumpet));
    if (wSize<sizeof(CMD_GR_S_SendTrumpet)) return false;
	CMD_GR_S_SendTrumpet tru;
	memset(&tru,0,sizeof(tru));
	memcpy(&tru,pData,sizeof(tru));

	sendEvent(ccNd_Room_Sub_GR_PropertyTrumpet,CreateNotify(pData, wSize, RT_DEFAULT));
    return true;
}

//用户进入
bool CFrameData::OnSocketSubUserEnter(void* pData, WORD wSize)
{
	//效验大小
	assert(wSize>=sizeof(tagMobileUserInfoHead));
	if(wSize<sizeof(tagMobileUserInfoHead)) return false;
	
	CNotify* notify = CreateNotify(pData,wSize,RT_SUCCESS);
	tagMobileUserInfoHeadRef* ref = tagMobileUserInfoHeadRef::createWithNotify();
	ref->setStruct(notify);
	notify->setObject(ref);
	tagMobileUserInfoHead& pInfoHead=ref->cmd;

	//自己数据
	if(pInfoHead.dwUserID == m_dwUserID)
	{
		//记录状态
		m_cbStatus = pInfoHead.cbUserStatus;
		m_wChairID = pInfoHead.wChairID;
		m_wTableID = pInfoHead.wTableID;
        m_cbGender = pInfoHead.cbGender;
        CCLOG("CFrameData::OnSocketSubUserEnter 自己状态 %d", m_cbStatus);
    }


	//待修改
	//游戏引用
    //if(m_pGameDelegate)
    //{
    //    //旁观暂时不处理
    //    if(pInfoHead->cbUserStatus==US_LOOKON)
    //        return true;
    //    
    //    //用户进入
    //    m_pGameDelegate->OnUserEnter(pUser);
    //}
	
	sendEvent(ccNd_Hall_Sub_GR_UserEnter,notify);
	return true;
}
#include "CMD_GameServerRef.h"
// MARK:用户状态
//#define US_NULL						0x00								//没有状态
//#define US_FREE						0x01								//站立状态
//#define US_SIT						0x02								//坐下状态
//#define US_READY                      0x03								//同意状态
//#define US_LOOKON                     0x04								//旁观状态
//#define US_PLAYING					0x05								//游戏状态
//#define US_OFFLINE					0x06								//断线状态
//MARK:返回的用户状态
bool CFrameData::OnSocketSubUserStatus(void *pData, WORD wSize)
{
	//效验大小
	assert(wSize==sizeof(CMD_GR_UserStatus));
	if(wSize!=sizeof(CMD_GR_UserStatus)) return false;
	
	//变量定义
	CMD_GR_UserStatus userStatus;
	memset(&userStatus,0,sizeof(CMD_GR_UserStatus));
	memcpy(&userStatus,pData,sizeof(CMD_GR_UserStatus));
    log("CFrameData-OnSocketSubUserStatus: 用户ID:%d 用户状态:%d， 用户椅子号:%d 用户桌子号:%d", userStatus.dwUserID, userStatus.UserStatus.cbUserStatus, userStatus.UserStatus.wChairID, userStatus.UserStatus.wTableID);
	
	
	////////////////////////////////////////////////////////////////////////////////////
	//用户数据
	if(userStatus.dwUserID==m_dwUserID)
	{
        if (m_cbStatus != userStatus.UserStatus.cbUserStatus) {
            CCLOG("用户状态已经改变!");
        }
		//记录ID
        m_wTableID = userStatus.UserStatus.wTableID;
        m_wChairID = userStatus.UserStatus.wChairID;
        m_cbStatus = userStatus.UserStatus.cbUserStatus;
        
        //关闭判断
        CCLOG("CFrameData UserStatus: %d tableID:%d", userStatus.UserStatus.cbUserStatus, userStatus.UserStatus.wTableID);
		if ( (m_cbGameClient) && (userStatus.UserStatus.wTableID==INVALID_TABLE) && userStatus.UserStatus.cbUserStatus != US_SIT)
        {
            //关闭游戏
            m_cbGameClient=GC_NONE;
            
            
            // 用户离开游戏
            CCLOG("------------------------------用户离开游戏");
        }
        
		//启动判断
		if( !m_cbGameClient && userStatus.UserStatus.wTableID != INVALID_TABLE && s_IsEnterRoom)
        {
            m_cbGameClient = GC_GAME;
        }
    }

	sendEvent(ccNd_Hall_Sub_GR_UserStatus,CreateNotify(pData,wSize,RT_DEFAULT));

	return true;
}

//用户分数
bool CFrameData::OnSocketSubUserScore(void* pData, WORD wSize)
{
	//效验大小
	assert(wSize==sizeof(CMD_GR_MobileUserScore));
	
	sendEvent(ccNd_Hall_Sub_GR_UserScore,CreateNotify(pData,wSize,RT_DEFAULT));
    CCLOG("CFrameData:  UserScore");

	return true;
}

//用户聊天
bool CFrameData::OnSocketSubGFUserChat(void* pData, WORD wSize)
{	
	sendEvent(ccNd_Chat_Sub_GR_ChatWord,CreateNotify(pData,wSize,RT_DEFAULT));
    return true;
}
//用户表情
bool CFrameData::OnSocketSubGFUserExpression(void* pData, WORD wSize)
{	
	
    sendEvent(ccNd_Chat_Sub_GR_ChatExpression,CreateNotify(pData,wSize,RT_DEFAULT));
    return true;
}

//请求失败
bool CFrameData::OnSocketSubRequestFailure(void* pData, WORD wSize)
{
	assert(wSize==sizeof(CMD_GR_RequestFailure));
	if(wSize!=sizeof(CMD_GR_RequestFailure)) return false;

	CMD_GR_RequestFailure rf;
    memset(&rf, 0, sizeof(CMD_GR_RequestFailure));
    memcpy(&rf, pData, wSize);

	auto notify = CreateNotify(pData,wSize,RT_DEFAULT);
	notify->m_MainString = YYConverUnicodeToUtf8(rf.szDescribeString);
	sendEvent(ccNd_RoomEnterFailure,notify);
	return true;
}

bool CFrameData::OnSocketSubRequestDistribute(void* pData, WORD wSize)
{
    //待修改
	return true;
}

//金币变化
bool CFrameData::OnSocketSubUserGold(void* pData, WORD wSize)
{
    //效验参数
    assert(wSize==sizeof(CMD_GR_UserScore));
    if (wSize<sizeof(CMD_GR_UserScore)) return false;
    //sendEvent
    return true;
}
  
//-------------------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------------------

//框架状态
bool CFrameData::OnTCPNetworkMainGRStatus(WORD wSubCmdID, void* pData, WORD wSize)
{
	CCLOG("CFrameData::OnTCPNetworkMainGRStatus");
	return true;
}

//银行命令
bool CFrameData::OnTCPNetworkGRBankInsure(WORD wSubCmdID, void* pData, WORD wSize)
{
	auto notify = CreateNotify(pData, wSize,RT_DEFAULT);
	notify->setSubType(wSubCmdID);
    sendEvent(ccNd_BANK_Sub_CM_Message,notify);
	return true;
}



//游戏命令
bool CFrameData::OnTCPNetworkMainGame(WORD wSubCmdID, void* pData, WORD wSize)
{
    //是否跳过游戏消息处理
    if(getGameSkip()) return true;
    
    //游戏消息处理
    //if(m_pGameDelegate)
    //    return m_pGameDelegate->OnGameMessageWithCmdID(pData, wSize, wSubCmdID);
	auto notify = CreateNotify(pData, wSize,RT_DEFAULT);
	notify->setSubType(wSubCmdID);
	sendEvent(ccNd_GAME_Sub_CM_Message,notify);
    return false;
}

//系统命令
bool CFrameData::OnTCPNetworkMainCMSystem(WORD wSubCmdID, void* pData, WORD wSize)
{
	auto notify = CreateNotify(pData, wSize, RT_DEFAULT);
	notify->setSubType(wSubCmdID);
	switch (wSubCmdID)
	{
		case SUB_CM_SYSTEM_MESSAGE:                     //系统消息      1
		{
			sendEvent(ccNd_Main_Sub_CM_System,notify);
			return true;
		}
        case SUB_CM_DOWN_LOAD_MODULE:                   //下载消息          2
        {
            
            return true;
        }
		default:
		{
			CCLOG("CFrameData::OnTCPNetworkMainCMSystem 错误消息");
			return true;
		}
	}
	return true;
}


//框架命令
bool CFrameData::OnTCPNetworkMainGFFrame(WORD wSubCmdID, void* pData, WORD wSize)
{
    //游戏处理
	//if(m_pGameDelegate && m_pGameDelegate->OnGameFrameWithCmdID(wSubCmdID, pData, wSize)==true) return true;
 //   
	////比赛处理
	//if(m_pMatchInterface && m_pMatchInterface->onMatchEventWithGRCmdID(wSubCmdID, pData, wSize)==true) return true;
    
	switch (wSubCmdID)
	{
		case SUB_GF_GAME_OPTION:			//游戏配置
		{
			CCLOG("CFrameData::OnTCPNetworkMainGFFrame 游戏配置");
			return true;
		}
		case SUB_GF_USER_READY:				//用户准备
		{
			CCLOG("CFrameData::OnTCPNetworkMainGFFrame 用户准备");
			return true;
		}
		case SUB_GF_USER_CHAT:				//用户聊天
		{
            return this->OnSocketSubGFUserChat(pData, wSize);
		}
		case SUB_GF_USER_EXPRESSION:		//用户表情
		{
            return this->OnSocketSubGFUserExpression(pData, wSize);
		}
		case SUB_GF_LOOKON_CONFIG:			//旁观配置
		{
			CCLOG("CFrameData::OnTCPNetworkMainGFFrame 旁观配置");
			return true;
		}
		case SUB_GF_GAME_STATUS:			//游戏状态 100
		{
            CCLOG("CFrameData::OnTCPNetworkMainGFFrame 主子命令：框架命令 100 游戏场景 100");
            return this->OnSocketSubGFGameStatus(pData, wSize);
		}
		case SUB_GF_GAME_SCENE:				//游戏场景 101
		{
            CCLOG("CFrameData::OnTCPNetworkMainGFFrame 主子命令：框架命令 100 游戏场景 101");
            return this->OnSocketSubGFGameScene(pData, wSize);
		}
		case SUB_GF_SYSTEM_MESSAGE:			//系统消息
		{
            return this->OnSocketSubGFSystemMessage(pData, wSize);
		}
		default:
			assert("CFrameData::OnTCPNetworkMainGFFrame 框架命令");
			return true;
	}
	return true;
}

//-------------------------------------------------------------------------------------------//

//用户服务
bool CFrameData::OnTCPNetworkMDMGPUserService(WORD wSubCmdID, void* pData, WORD wSize)
{
    switch (wSubCmdID)
    {
        //case SUB_GL_USER_FACE_INFO:         //头像信息  200
        //{
        //    return OnSocketSubGPUserFaceInfo(pData, wSize);
        //}
        //    
        //case SUB_GL_USER_INDIVIDUAL:        //个人资料  301
        //{
        //    return OnSocketSubGPQueryIndividual(pData, wSize);
        //}
        //    
        //case SUB_GL_QUERY_INDIVIDUAL:       //查询包裹  304
        //{
        //    return OnSocketSubGPWrapIndividual(pData, wSize);
        //}
        //    
        case SUB_GL_USER_INSURE_INFO:       //银行资料  403
        {
            return OnSocketSubGPInsureInfo(pData, wSize);
        }
            
        case SUB_GL_USER_INSURE_SUCCESS:    //银行成功  405
        {
            return OnSocketSubGPBankSucceed(pData, wSize);
        }
            
        case SUB_GL_USER_INSURE_FAILURE:    //银行失败  406
        {
            return OnSocketSubGPBankFailure(pData, wSize);
        }
            
        case SUB_GL_OPERATE_SUCCESS:        //操作成功  900
        {
            CMD_GP_OperateSuccess operateSuccess;
            memset(&operateSuccess, 0, sizeof(operateSuccess));
            memcpy(&operateSuccess, pData, wSize);
            
            assert(wSize>=(sizeof(CMD_GP_OperateSuccess)-sizeof(operateSuccess.szDescribeString)));
            
            ////操作成功
			auto notify = CreateNotify(RT_SUCCESS);
			notify->m_MainString = YYConverUnicodeToUtf8(operateSuccess.szDescribeString);
            sendEvent(ccNd_Operate_Result,notify);
            break;
        }
        case SUB_GL_OPERATE_FAILURE:        //操作失败  901
        {
            CMD_GP_OperateFailure operateFailure;
            memset(&operateFailure, 0, sizeof(operateFailure));
            assert(wSize>=(sizeof(CMD_GP_OperateFailure)-sizeof(operateFailure.szDescribeString)));
            memcpy(&operateFailure, pData, wSize);
            //
            //// 操作失败 
            //GetFrameManager()->setAlertSystem(YYConverUnicodeToUtf8(operateFailure.szDescribeString));
			auto notify = CreateNotify(RT_FAILURE);
			notify->m_MainString = YYConverUnicodeToUtf8(operateFailure.szDescribeString);
            sendEvent(ccNd_Operate_Result,notify);
            break;
        }
        //case SUB_GL_SCORE_LIST_RESULT:
        //{
            //GetNotificationCenter()->postNotification(ccNd_RankResult, CreateNotify(pData, wSize, 1));
        //    break;
        //}
        //case SUB_MB_STORE_PURCHASE_VERIFY_RESULT:
        //{
            //GetNotificationCenter()->postNotification(ccNd_Shop_AppStore_Verify_Result, CreateNotify(pData, wSize, 1));
            //break;
        //}
		default:
			sendUnknownEvent(Data_Load,MDM_GP_USER_SERVICE,wSubCmdID,CreateNotify(pData,wSize,RT_DEFAULT));
			log("CFrameData::OnTCPNetworkMDMGPUserService:%d",wSubCmdID);
			//CCAssert(false, "CFrameData: 登录处理:超出范围");
            
    }
    //GetFrameManager()->setLockScreenString(0);
    setSocketClose();
    return true;
}


//-------------------------------------------------------------------------------------------
//查询操作
void CFrameData::sendPacketWithGPInsureInfo(const c_char* pszInsurePass)
{
    CMD_GP_QueryInsureInfo info;
    memset(&info, 0, sizeof(CMD_GP_QueryInsureInfo));
    
    info.dwUserID = m_dwUserID;

    //发送数据
	CFrameData* pFrameData = createFrameData();
    pFrameData->doConnect();
    pFrameData->sendPacketWithCompilatio();
    pFrameData->sendData(MDM_GP_USER_SERVICE, SUB_GL_QUERY_INSURE_INFO, &info, sizeof(info));

	if (m_pTCPSocket)
		m_pTCPSocket->setData(Data_Load);
    
    CCLOG("CBankDelegate::sendPacketWithGPInsureInfo 大厅 查询操作");
}

//大厅银行
//银行资料
bool CFrameData::OnSocketSubGPInsureInfo(void* pData, WORD wSize)
{
    //校验参数
    assert(wSize == sizeof(CMD_GP_UserInsureInfo));
    
    //CMD_GP_UserInsureInfo* pInfo = (CMD_GP_UserInsureInfo*)pData;
    
    //更新用户信息
    /*CSpriteUser* pUser=GetFrameManager()->getUserItemSelf();
    pUser->setUserScore(pInfo->lUserScore);
    pUser->m_InfoHead.lScore = pInfo->lUserScore;
    pUser->m_lInsure = pInfo->lUserInsure;
    
	if (GetFrameData()->m_pBankInterface)
		GetFrameData()->m_pBankInterface->OnSocketSubGPInsureInfo(pData, wSize);

    GetFrameManager()->setLockScreenString();*/
	setSocketClose();
    
    // 发送通知
	sendEvent(ccNd_Bank_InsureInfo, CreateNotify(pData,wSize,RT_SUCCESS));
    
    CCLOG("CFrameData::OnSocketSubGPInsureInfo 大厅 查询成功");
 
    return true;
}

//存款操作
void CFrameData::sendPacketWithGPSaveScore(LONGLONG lSaveScore)
{
    CMD_GP_UserSaveScore UserSaveScore;
    memset(&UserSaveScore, 0, sizeof(UserSaveScore));
    
    UserSaveScore.lSaveScore = lSaveScore;
    UserSaveScore.dwUserID = m_dwUserID;
    YYConverUtf8ToUnicodeWithArray(UserSaveScore.szMachineID, LEN_MACHINE_ID, GetFrameData()->getMachineID().c_str());
    
	//连接发送保存
	CFrameData* pFrameData = createFrameData();
	pFrameData->doConnect();
	pFrameData->sendPacketWithCompilatio();
	pFrameData->sendData(MDM_GP_USER_SERVICE, SUB_GL_USER_SAVE_SCORE, &UserSaveScore, sizeof(UserSaveScore));
    
    CCLOG("CBankDelegate::sendPacketWithGPSaveScore 大厅 存款操作");
}

//取款操作
void CFrameData::sendPacketWithGPTakeScore(LONGLONG lTakeScore, const c_char* pPassword)
{
    CMD_GP_UserTakeScore takeScore;
    memset(&takeScore, 0, sizeof(takeScore));
    takeScore.lTakeScore = lTakeScore;
    takeScore.dwUserID = m_dwUserID;
    
    //取款密码
	if(pPassword && strcmp(pPassword,""))
        YYConverUtf8ToMD5Unicode(takeScore.szPassword, pPassword);
    
    YYConverUtf8ToUnicodeWithArray(takeScore.szMachineID, LEN_MACHINE_ID, GetFrameData()->getMachineID().c_str());
    
	CFrameData* pFrameData = createFrameData();
	pFrameData->doConnect();
	pFrameData->sendPacketWithCompilatio();
	pFrameData->sendData(MDM_GP_USER_SERVICE, SUB_GL_USER_TAKE_SCORE, &takeScore, sizeof(takeScore));
    
    CCLOG("CBankDelegate::sendPacketWithGPTakeScore 大厅 取款操作");

}
//转帐操作
void CFrameData::sendPacketWithGPTransferScore(LONGLONG lTransferScore, const c_char* pPassword, BYTE cbType, const c_char* pNickName)
{
    CMD_GP_UserTransferScore transfer;
    memset(&transfer, 0, sizeof(CMD_GP_UserTransferScore));
    transfer.cbByNickName=cbType;
    transfer.dwUserID=m_dwUserID;
    transfer.lTransferScore=lTransferScore; 
    
	YYConverUtf8ToUnicodeWithArray(transfer.szNickName, LEN_PASSWORD, pNickName);
	//YYConverUtf8ToUnicode(transfer.szNickName, pNickName);
    YYConverUtf8ToUnicodeWithArray(transfer.szMachineID, LEN_MACHINE_ID, GetFrameData()->getMachineID().c_str());
    
    if(pPassword)
        YYConverUtf8ToMD5Unicode(transfer.szPassword, pPassword);
    
	CFrameData* pFrameData = createFrameData();
	pFrameData->doConnect();
	pFrameData->sendPacketWithCompilatio();
	pFrameData->sendData(MDM_GP_USER_SERVICE, SUB_GL_USER_TRANSFER_SCORE, &transfer, sizeof(transfer));
    //sendData(MDM_GP_USER_SERVICE, SUB_GP_QUERY_USER_INFO_REQUEST, &transfer, sizeof(transfer));

    CCLOG("CBankDelegate: 大厅 转帐操作");

}

//转账记录请求
void CFrameData::sendPacketWithGPTransferRecord(DWORD dwGameID,DWORD dwTargetID,WORD wNumber)
{
	CMD_GR_C_TransGoldRecordReq req;
	memset(&req, 0, sizeof(req));
	req.dwGameID = dwGameID;
	req.dwTargetID = dwTargetID;
	req.wTradeType = 3;
	req.wNumber = wNumber;
	CFrameData* pFrameData = createFrameData();
	pFrameData->doConnect();
	pFrameData->sendPacketWithCompilatio();
	pFrameData->sendData(MDM_GR_INSURE, SUB_GR_USER_GOLD_RECORD_REQUEST, &req, sizeof(req));
}

//银行成功
bool CFrameData::OnSocketSubGPBankSucceed(void* pData, WORD wSize)
{

	auto ref = CMD_GP_UserInsureSuccessRef::createWithNotify();
	memset(&ref->cmd, 0, sizeof(ref->cmd));
	memcpy(&ref->cmd, pData, wSize);
	
	setSocketClose();
    
    // 发送通知
    CNotify *notify = CreateNotify(1);
	notify->setObject(ref);
	notify->m_MainString = YYConverUnicodeToUtf8(ref->cmd.szDescribeString);
	sendEvent(ccNd_Bank_Result, notify);

    CCLOG("CFrameData: 大厅 操作成功");

    return true;
}

//银行失败
bool CFrameData::OnSocketSubGPBankFailure(void* pData, WORD wSize)
{
	CMD_GP_UserInsureFailure InsureFailure;
	memset(&InsureFailure,0,sizeof(InsureFailure));
	memcpy(&InsureFailure,pData,wSize);
   
	setSocketClose();

    CCLOG("CFrameData: 大厅 操作失败");
    
    // 发送通知
    CNotify *notify = CreateNotify(0);
    notify->m_MainString = YYConverUnicodeToUtf8(InsureFailure.szDescribeString);
	sendEvent(ccNd_Bank_Result, notify);

    return true;
}

//查询排行榜
void CFrameData::sendPacketWithRankInfo()
{
    CMD_MB_ScoreList_Request request;
    memset(&request,0,sizeof(request));
    request.wKindID = 27;//(WORD)getKindID();
    request.wTopCount = 20;
	CFrameData* pFrameData = createFrameData();
	pFrameData->doConnect();
    pFrameData->sendPacketWithCompilatio();
    pFrameData->sendData(MDM_GP_USER_SERVICE, SUB_GL_SCORE_LIST_REQUEST, &request, sizeof(request));
}

//典当操作
//void CFrameData::sendPacketWithGPPawnShop(WORD wOP,WORD wItemType,WORD wItemCount)
//{
//	CMD_GR_C_USER_PAWNSHOP_REQUEST pawnshop;
//	memset(&pawnshop,0,sizeof(pawnshop));
//	pawnshop.wOP = wOP;
//	pawnshop.wItemType = wItemType;
//	pawnshop.wItemCount = wItemCount;
//
//	//CFrameData* pFrameData = createFrameData();
//	doConnect();
//    sendPacketWithCompilatio();
//    sendData(MDM_GR_INSURE, SUB_GR_USER_PAWNSHOP_REQUEST, &pawnshop, sizeof(pawnshop));
//}

//用户道具
bool CFrameData::OnTCPNetworkMainMBUserProps(WORD wSubCmdID, void* pData, WORD wSize)
{
    return true;
}

//用户道具
bool CFrameData::OnSocketSubMBGetPropsInfo(void*pData, WORD wSize)
{

    return true;
}

//-------------------------------------------------------------------------------------------//

//修改用户资料
void CFrameData::sendPacketWithModifyIndividual(const char* nickString,BYTE cbGender, DWORD dwUserID,const c_char* szPassword, bool isMd5)
{
	CFrameData* pFrameData = createFrameData();
	pFrameData->doConnect();
	pFrameData->sendPacketWithCompilatio();
    
    //构造数据
    BYTE cbBuffer[SOCKET_TCP_BUFFER];
    memset(cbBuffer, 0, sizeof(cbBuffer));
    
    CMD_GP_ModifyIndividual* modify=(CMD_GP_ModifyIndividual*)cbBuffer;
    modify->cbGender=cbGender;
    modify->dwUserID=dwUserID;

	if(isMd5)
	{
		YYConverUtf8ToMD5Unicode(modify->szPassword,szPassword);
		//YYConverUtf8ToUnicodeWithArray(modify->szPassword, LEN_PASSWORD, szPassword);
	}
	else
	{
		memcpy(modify->szPassword, szPassword, LEN_PASSWORD*sizeof(TCHAR));
	}

    CSendPacketHelper packetHelper(cbBuffer+sizeof(CMD_GP_ModifyIndividual), SOCKET_TCP_BUFFER-sizeof(CMD_GP_ModifyIndividual));

    //用户昵称  1
    if(strlen(nickString)>0)
    {
        TCHAR tcBuffer[32];
        memset(tcBuffer, 0, sizeof(tcBuffer));
        YYConverUtf8ToUnicodeWithArray(tcBuffer, 32, nickString);
        
        packetHelper.AddPacket(tcBuffer, sizeof(tcBuffer), DTP_GP_UI_NICKNAME);
    }
	

    pFrameData->sendData(MDM_GP_USER_SERVICE, SUB_GL_MODIFY_INDIVDUAL, cbBuffer, sizeof(CMD_GP_ModifyIndividual)+packetHelper.GetDataSize());
}

//-------------------------------------------------------------------------------------------//

//请求用户
void CFrameData::sendPacketWithRequestUserInfo(DWORD dwUserID,WORD wTableID)
{
	CMD_GR_UserInfoReq info;
	memset(&info,0,sizeof(CMD_GR_UserInfoReq));
	
	info.dwUserIDReq=dwUserID;
	info.wTablePos=wTableID;

    sendData(MDM_GR_USER, SUB_GR_USER_INFO_REQ, &info, sizeof(CMD_GR_UserInfoReq));
	
    CCLOG("CFrameData:sendPacketWithRequestUserInfo 请求用户信息");

}

//请求椅子用户
void CFrameData::sendPacketWithRequestChairUserInfo(WORD wTableID, WORD wChairID)
{
	CMD_GR_ChairUserInfoReq info;
	memset(&info,0,sizeof(CMD_GR_ChairUserInfoReq));
	
	info.wChairID=wChairID;
	info.wTableID=wTableID;
	
    sendData(MDM_GR_USER, SUB_GR_USER_CHAIR_INFO_REQ, &info, sizeof(CMD_GR_ChairUserInfoReq));
	
    CCLOG("CFrameData:sendPacketWithRequestChairUserInfo 发送用户请求%d,%d",wTableID,wChairID);

}

//发送坐下
void CFrameData::sendPacketWithSitDown(WORD wTableID,WORD wChairID)
{	
	CMD_GR_UserSitDown sitdown;
	memset(&sitdown,0,sizeof(CMD_GR_UserSitDown));

	sitdown.wChairID = wChairID;
	sitdown.wTableID = wTableID;

	sendData(MDM_GR_USER, SUB_GR_USER_SITDOWN, &sitdown, sizeof(CMD_GR_UserSitDown));
	CCLOG("CFrameData::sendPacketWithSitDown");
}

//快速坐下
void CFrameData::sendPacketWithQuickStart(){
	sendData(MDM_GR_USER, SUB_GR_USER_CHAIR_REQ, 0, 0);
	CCLOG("CFrameData::sendPacketWithQuickStart");
}

//快速加入
void CFrameData::sendPacketWithQuickJin(){
	sendData(MDM_GR_USER, SUB_GR_USER_QUICK_JINE, 0, 0);
	CCLOG("CFrameData::sendPacketWithQuickJin");
}

//发送换桌
void CFrameData::sendPacketWithCutoverTable()
{
    sendData(MDM_GR_USER, SUB_GR_USER_CHAIR_REQ, 0, 0);
    
	CCLOG("CFrameData::sendPacketWithCutoverTable");

}

//#pragma mark 强行离开-起立
//发送起立
void CFrameData::sendPacketWithStandUpLeave(BYTE cbForce)
{
    ////////////////
//    WORD							wTableID;							//桌子位置
//	WORD							wChairID;							//椅子位置
//	BYTE							cbForceLeave;						//强行离开
    ////////////////
    //强制关闭客户端
	CMD_GR_UserStandUp standup;
	memset(&standup,0,sizeof(CMD_GR_UserStandUp));
	standup.wTableID = this->m_wTableID;
	standup.wChairID = this->m_wChairID;
	standup.cbForceLeave = cbForce;
    CCLOG("standup.wTableID:%d standup.wChairID:%d standup.cbForceLeave:%d", standup.wTableID, standup.wChairID, standup.cbForceLeave);
    sendData(MDM_GR_USER, SUB_GR_USER_STANDUP, &standup, sizeof(CMD_GR_UserStandUp));
	//关闭连接-我家的
	//setSocketClose(true);
	CCLOG("CFrameData::sendPacketWithStandUpLeave");
}

//发送状态-准备
void CFrameData::sendPacketWithUserStatus(BYTE cbStatus)
{
	CMD_GR_UserStatus ready;
	memset(&ready,0,sizeof(CMD_GR_UserStatus));
	
	ready.dwUserID					= this->m_dwUserID;
	ready.UserStatus.wChairID		= this->m_wChairID;
	ready.UserStatus.wTableID		= this->m_wTableID;
	ready.UserStatus.cbUserStatus	= cbStatus;
	
    sendData(MDM_GF_FRAME, SUB_GF_USER_READY, &ready, sizeof(CMD_GR_UserStatus));
	
	CCLOG("CFrameData::sendPacketWithUserStatus");
}

//发送规则
void CFrameData::sendPacketWithUserRule()
{
	CMD_GR_UserRule rule;
	memset(&rule,0,sizeof(CMD_GR_UserRule));
    
    sendData(MDM_GR_USER, SUB_GR_USER_RULE, &rule, sizeof(CMD_GR_UserRule));
    
	CCLOG("CFrameData::sendPacketWithUserRule");

}

//MARK:发送游戏规则
void CFrameData::sendPacketWithGameOption()
{
    m_bGameSkip=false;
    m_cbGameClient = GC_GAME;

	CMD_GF_GameOption gameOption;
	memset(&gameOption,0,sizeof(CMD_GF_GameOption));
	gameOption.cbAllowLookon=false;
	gameOption.dwFrameVersion=INVALID_DWORD;
	gameOption.dwClientVersion=INVALID_DWORD;
    
    sendData(MDM_GF_FRAME, SUB_GF_GAME_OPTION, &gameOption, sizeof(CMD_GF_GameOption));
    //////////////临时代码//////////////
    //启动游戏通知
    if (s_IsEnterRoom) {
//        m_cbGameClient=GC_GAME;
//        
//        PostNotification(ccNd_LayerNotify, "CGameLayer");//进入游戏场景
    }
    //////////////临时代码//////////////
    //即将启动游戏
    //GetNotificationCenter()->postNotification(ccNd_Layernotify_WillGameLayer);//没用上
    
	CCLOG("CFrameData::sendPacketWithGameOption()");
    /*
     BYTE							cbAllowLookon;						//旁观标志
     DWORD							dwFrameVersion;						//框架版本
     DWORD							dwClientVersion;					//游戏版本
     */

}

//发送喇叭
void CFrameData::sendUserHorn(const c_char* szchat)
{
	CMD_GR_C_SendTrumpet cmd;
	cmd.cbRequestArea = 4;
	cmd.TrumpetColor = 0xff000000;
	cmd.wPropertyIndex = 19;
	YYConverUtf8ToUnicodeWithArray(cmd.szTrumpetContent, TRUMPET_MAX_CHAR, szchat);
	this->sendData(3,305,&cmd,sizeof(CMD_GR_C_SendTrumpet));
}

//发送喇叭
void CFrameData::sendUserHorn(const c_char* szNickName,const c_char* szchat)
{
	CMD_GR_PropSouna prop;
	memset(&prop,0,sizeof(prop));
	prop.wGameID = m_dwGameID;
	prop.playerID = m_dwUserID;
	YYConverUtf8ToUnicodeWithArray(prop.szNickName,32,szNickName);
	YYConverUtf8ToUnicodeWithArray(prop.szMsg,32,szchat);
	this->sendData(3,CMD_GR_PROPERTY_PROPSOUNA,&prop,sizeof(CMD_GR_C_SendTrumpet));
}

//发送表情
void CFrameData::sendPacketWithUserExpression(DWORD dwTargetUserID, WORD index)
{
	log("sendPacketWithUserExpression"); 
	CMD_GR_C_UserExpression cmd;
	cmd.dwTargetUserID =dwTargetUserID;
	cmd.wItemIndex = index;

	this->sendData(100,11,&cmd,sizeof(CMD_GR_C_UserExpression));
}

//发送聊天
void CFrameData::sendPacketWithUserChat(DWORD dwTagerUserID,const c_char* chat, WORD wSize)
{
	log("sendPacketWithUserChat:%s",chat); 
	CMD_GR_C_UserChat cmd;
	cmd.dwChatColor =0xffffff;
	cmd.dwTargetUserID = 0;
	cmd.wChatLength = wSize;
	YYConverUtf8ToUnicodeWithArray(cmd.szChatString, LEN_USER_CHAT,chat);
	int len = (sizeof(CMD_GF_C_UserChat) - sizeof(cmd.szChatString) +
                  cmd.wChatLength * sizeof(cmd.szChatString[0]));
	log("sendPacketWithUserChat:%s",&cmd.szChatString[0]); 
	this->sendData(100,10,&cmd,len);

	//CMD_GR_C_UserChat cmd;
	//cmd.dwChatColor =0xffffff;
	//cmd.dwTargetUserID = 0;
	//cmd.wChatLength = wSize;
	//YYConverUtf8ToUnicodeWithArray(cmd.szChatString, LEN_USER_CHAT, chat);
	///*int len = (sizeof(CMD_GF_C_UserChat) - sizeof(cmd.szChatString) +
 //                 cmd.wChatLength * sizeof(cmd.szChatString[0]));*/

	//this->sendData(100,10,&cmd,sizeof(CMD_GR_C_UserChat));
}

//网络验证
void CFrameData::sendPacketWithCompilatio()
{
	sendPacketWithCompilatio(getInstance()->getValidateKey().c_str());
}

//网络验证
void CFrameData::sendPacketWithCompilatio(const char* ValidateKey)
{
	TCP_Validate validate;
	memset(&validate, 0, sizeof(TCP_Validate));
    YYConverUtf8ToUnicodeWithArray(validate.szValidateKey, 64,ValidateKey);
    sendData(MDM_KN_COMMAND, SUB_KN_VALIDATE_SOCKET, &validate, sizeof(TCP_Validate));
    log("sendPacketWithCompilatio");
}

//内核命令
bool CFrameData::OnTCPNewordkWithKNCommon(WORD wMainCmdID, WORD wSubCmdID, void* pData, WORD wSize)
{
	if(wMainCmdID==MDM_KN_COMMAND)
	{
		//心跳维护
		if(wSubCmdID==SUB_KN_DETECT_SOCKET)
		{
			if(m_pTCPSocket)
				sendData(MDM_KN_COMMAND, SUB_KN_DETECT_SOCKET, 0, 0);
			return true;
		}

		//验证命令
		if(wSubCmdID==SUB_KN_VALIDATE_SOCKET)
		{
			return true;
		}
	}
	return false;
}

void CFrameData::sendEvent(string eventName,CNotify* pData){
	pData->setTypeData(Data_Default);
	pData->setEventName(eventName);
	LuaEngine* engine = LuaEngine::getInstance();
	BasicScriptData scriptdata(getInstance()->getSender(),pData);
	cocos2d::ScriptEvent eve(kCallFuncEvent, &scriptdata);
	engine->sendEvent(&eve);
}

void CFrameData::sendUnknownEvent(WORD TypeData,WORD wMainCmdID,WORD wSubCmdID,CNotify* pData)
{
	pData->setTypeData(TypeData);
	pData->setMainType(wMainCmdID);
	pData->setSubType(wSubCmdID);
	LuaEngine* engine = LuaEngine::getInstance();
	BasicScriptData scriptdata(getInstance()->getSender(),pData);
	cocos2d::ScriptEvent eve(kCallFuncEvent, &scriptdata);
	engine->sendEvent(&eve);
}

bool CFrameData::sendEvent(WORD TypeData,WORD wMainCmdID,WORD wSubCmdID,void* pData, WORD wSize)
{
	auto notify = CreateNotify(pData,wSize,RT_DEFAULT);
	notify->setTypeData(TypeData);
	notify->setMainType(wMainCmdID);
	notify->setSubType(wSubCmdID);
	notify->setObject(this);
	LuaEngine* engine = LuaEngine::getInstance();
	BasicScriptData scriptdata(getInstance()->getSender(),notify);
	cocos2d::ScriptEvent eve(kCallFuncEvent, &scriptdata);
	engine->sendEvent(&eve);
	return true;
}

bool CFrameData::isEnterBackground()
{
    if (m_pTCPSocket) {
        return m_pTCPSocket->m_bEnterBackground;
    }
    return false;
}

void CFrameData::setIsEnterBackground(bool bIsEnterBackground)
{
    if (m_pTCPSocket) {
        m_pTCPSocket->m_bEnterBackground = bIsEnterBackground;
    }
}

#pragma mark - 公开方法 - 向登录服务器发送请求

void CFrameData::sendPacketWithVerifyString()
{
    CFrameData* pFrameData = createFrameData();
    pFrameData->doConnect();
    pFrameData->sendPacketWithCompilatio();
    pFrameData->sendData(MDM_MB_VALIDATE, SUB_MB_C_PUBLIC_SEEK, NULL, 0);
}

CLogonData *CLogonData::create()
{
    CLogonData *logonData = new CLogonData();
    logonData->autorelease();
    return logonData;
}

CLogonData *CLogonData::create(BYTE cbLogonType, std::string UUID, std::string passwd, std::string deviceid)
{
    CLogonData *logonData = CLogonData::create();
    logonData->m_cbLogonType = cbLogonType;
    logonData->m_UUID = UUID;
    logonData->m_passwd = passwd;
    return logonData;
}

CLogonData *CLogonData::create(BYTE cbLogonType, std::string UUID, std::string deviceid)
{
    CLogonData *logonData = CLogonData::create();
    logonData->m_cbLogonType = cbLogonType;
    logonData->m_UUID = UUID;
    return logonData;
}

CLogonData *CLogonData::create(BYTE cbLogonType, BYTE cbGender, std::string UUID, std::string nickName, std::string avatarURL, std::string deviceid)
{
    CLogonData *logonData = CLogonData::create();
    logonData->m_cbLogonType = cbLogonType;
    logonData->m_cbGender = cbGender;
    logonData->m_UUID = UUID;
    logonData->m_nickName = nickName;
    logonData->m_avatarURL = avatarURL;
    return logonData;
}

CLogonData::CLogonData()
{
    m_UUID = "";
    m_nickName = "";
    m_avatarURL = "";
    m_passwd = "";
    m_deviceid = "";
}

CLogonData::~CLogonData()
{
    
}