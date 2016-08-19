
/*
 定义所有委托协议方法
	大厅需要实现所有界面的共有方法
	
	1。协议		流委托
	2。主界面		按钮委托
	3。登录界面	登录委托
	4。房间界面	按钮委托
	5。桌位界面	按钮委托
	6。游戏界面	待
 */

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "define.h"
#include "CMD_GameServer.h"
#include "cocos2d.h"

//MARK::帐号数据
#define YYRAND_PASSWORD_LEN     8

class CAccountDataDelegate
{
public:
    TCHAR           m_pNickName[LEN_NICKNAME];              //昵称
    
public:
    bool            m_bGameSkip;                            //消息标识
    
public:
    BYTE            m_cbDevice;                             //设备I D
    WORD			m_wChairID;                             //椅子I D
    WORD			m_wTableID;                             //桌子I D
    DWORD			m_dwUserID;                             //用户I D
    DWORD			m_dwGameID;                             //游戏I D
    DWORD			m_dwKindID;                             //类型I D
    DWORD           m_dwPlazaVersion;                       //广场版本
	std::string     m_machineID;                            //硬件标识
    
    BYTE			m_cbStatus;                             //用户状态
    BYTE			m_cbGender;                             //用户性别

    
public:
    CAccountDataDelegate()
    {
        initAccountData();
    };
    
    virtual ~CAccountDataDelegate(){};
    
    virtual void initAccountData()
    {
        memset(m_pNickName, 0, sizeof(m_pNickName));
        
        m_cbDevice  = 0;
        m_wChairID  = 0;
        m_wTableID  = 0;
        m_dwUserID  = 0;
        m_dwGameID  = 0;
        m_dwKindID  = 0;
        m_cbStatus  = 0;
        m_cbGender  = 0;
        m_bGameSkip = false;
    }
    
public:
    void setGameSkip(bool skip)     {m_bGameSkip=skip;}
    void setDevice(BYTE cbDevice)   {m_cbDevice=cbDevice;}
    void setChairID(WORD wChairID)  {m_wChairID=wChairID;}
    void setTableID(WORD wTableID)  {m_wTableID=wTableID;}
    void setUserID(DWORD dwUserID)  {m_dwUserID=dwUserID;}
    void setGameID(DWORD dwGameID)  {m_dwGameID=dwGameID;}
    void setKindID(DWORD dwKindID)  {m_dwKindID=dwKindID;}
    void setPlazaVersion(DWORD dwPlazaVersion)  {m_dwPlazaVersion=dwPlazaVersion;}
	void setMachineID(std::string machineID) {m_machineID=machineID;}

public:
    bool getGameSkip()  {return m_bGameSkip;}
    BYTE getDeviceID()  {return m_cbDevice;}
    WORD getChairID()   {return m_wChairID;}
    WORD getTableID()   {return m_wTableID;}
    DWORD getUserID()   {return m_dwUserID;}
    DWORD getGameID()   {return m_dwGameID;}
    DWORD getKindID()   {return m_dwKindID;}
    DWORD getPlazaVersion() {return m_dwPlazaVersion;}
	std::string getMachineID() {return m_machineID;}
    BYTE getGenderID()  {return m_cbGender;}
};


//数据分类
typedef enum _DataType
{
	Data_Default	= 0,		//默认
	Data_Load		= 1,		//登录命令
	Data_Room		= 2,		//房间命令
    Data_Send       = 9,        //发送命令
	Data_End		= 10,		//结束
    
    Data_GameServer     = 11,   //游戏服务
    Data_TableConfig    = 12,   //桌子配置
    Data_LoginAward     = 13,   //登陆奖励
    Data_GameKind       = 14,   //游戏种类
    
    Data_RoomName       = 20,   //房间名字
    Data_DeskName       = 21,   //椅子名字
    Data_UserCutsom     = 100,   //自定义数据
}DataType;

//弹窗提示
#define ALERT_DEFAULT_TIPS					0								//默认
#define ALERT_LOGON_FAILURE					2								//连接失败
#define ALERT_EXCEPTION_TIPS				3								//异常断开
#define ALERT_OUTTIME_TIPS					4								//网络超时断开
#define ALERT_ROOMLOAD_TIPS					5								//进入房间失败
#define ALERT_DESKLIST_TIPS					6								//坐下失败
#define ALERT_GAME_DISCONNET				7								//游戏中异常断开
#define ALERT_UPDATE_TIPS					9								//更新提示
#define ALERT_REQUESTFAILURE_TIPS			10								//请求失败提示

//大厅提示
#define ALERT_GP_DEFAULT                    0                               //默认
#define ALERT_GP_LOGON_FAILURE              1                               //登陆失败
#define ALERT_GR_LOGON_FAILURE              2                               //房间失败


//系统提示
#define ALERT_CLOSE_GAME                    0x11                            //关闭游戏
#define ALERT_CLOSE_ROOM                    0x12                            //关闭房间
#define ALERT_CLOSE_LINK                    0x13                            //中断连接
#define ALERT_SYSTEM_MGS                    0x14                            //系统消息
#define ALERT_ACTION_MGS                    0x15                            //动作消息
#define ALERT_OPERATE_SUCCESS               0x16                            //操作成功

#define ALERT_SHORTSTREAM                   20                              //短连接处理
#define ALERT_DOWNLOAD                      21

//比赛提示
#define ALERT_MATCH_FEE                     100                             //比赛报名费


#define UIClassType_None            0
#define UIClassType_Layer           1
#define UIClassType_Button          2
#define UIClassType_ImageView       3

#define MAX_DATA_COUNT  10
class CSpriteParamData
{
public:
    CSpriteParamData()
    {
        initSpriteParamData();
    }
    virtual ~CSpriteParamData(){}
    
public:
    
    //类型参数
public:
    int					m_nMainType;
    int					m_nSubType;
	int					m_nTypeData;

public:
	std::string			m_MainString;
	std::string			m_SubString;

public:
    void initSpriteParamData()
    {
        resetSpriteParamData();
    }
    
    void resetSpriteParamData()
    {
        m_nMainType = 0;
        m_nSubType  = 0;

		m_SubString.clear();
		m_MainString.clear();
    }
    
public:
    int  getMainType() {return m_nMainType;}
	int  getSubType()  {return m_nSubType;}
	int  getTypeData() {return m_nTypeData;}

    void setMainType(int nMainType){m_nMainType=nMainType;}
    void setSubType(int nSubType)  {m_nSubType=nSubType;}
	void setTypeData(int nTypeData){m_nTypeData=nTypeData;}

};

typedef int RESULT_TYPE;            //结果处理
#define RT_DEFAULT      0           //默认结果

#define RT_SUCCESS      1           //处理成功
#define RT_FAILURE      2			//处理失败

#define RT_BEGAN        10           //处理开始
#define RT_INGED        15           //处理过程
#define RT_ENDED        20           //处理完成

#define RT_OTHER        100          //其他处理

class CNotify : public cocos2d::Ref, public CSpriteParamData
{
public:
    void*       m_pData;
    WORD        m_wSize;
    RESULT_TYPE m_Result;
	std::string m_eventName;
    Ref*		m_object;
public:
    CNotify(){}
    
    CNotify(void* pData, WORD wSize, RESULT_TYPE result):
		m_pData(pData),
		m_wSize(wSize),
		m_Result(result),
		m_object(nullptr)
    {
        //初始化
        initSpriteParamData();
    };
    ~CNotify(){};
    
public:
    static CNotify* create(void* pData, WORD wSize, RESULT_TYPE result)
    {
        CNotify* notify = new CNotify(pData, wSize, result);
        notify->autorelease();
        return notify;
    }
    
    static CNotify* create(void* pData)
    {
        CNotify* notify = new CNotify(pData, 0, 0);
        notify->autorelease();
        return notify;
    }

	static CNotify* create()
    {
        CNotify* notify = new CNotify();
        notify->autorelease();
        return notify;
    }
    
public:
    void* getData() {return m_pData;}
    WORD getSize()  {return m_wSize;}
    int getResult() {return m_Result;}

	Ref* getObject(){return m_object;}
	void setObject(Ref* object){m_object = object;}

	std::string getSubString(){return m_SubString;}
	std::string getMainString(){return m_MainString;}

	std::string getEventName(){return m_eventName;}
	void setEventName(std::string name){m_eventName = name;}

public:
    int  getMainType() {return m_nMainType;}
	int  getSubType()  {return m_nSubType;}
	int  getTypeData() {return m_nTypeData;}

    void setMainType(int nMainType){m_nMainType=nMainType;}
    void setSubType(int nSubType)  {m_nSubType=nSubType;}
	void setTypeData(int nTypeData){m_nTypeData=nTypeData;}

};

static CNotify* CreateNotify(void* pData, WORD wSize, RESULT_TYPE result)
{
    return CNotify::create(pData, wSize, result);
}
static CNotify* CreateNotify(void* pData)
{
    return CNotify::create(pData);
}
static CNotify* CreateNotify(RESULT_TYPE result)
{
    return CNotify::create(0, 0, result);
}

static CNotify* YYLayerNotify(int nMainType)
{
    CNotify* pNotify = new CNotify;
    pNotify->setMainType(nMainType);
    pNotify->autorelease();
    return pNotify;
}

static CNotify* YYLayerNotify(int nMainType, int nSubType)
{
    CNotify* pNotify = new CNotify;
    pNotify->setMainType(nMainType);
    pNotify->setSubType(nSubType);
    pNotify->autorelease();
    return pNotify;
}
static CNotify* YYLayerNotify(void* data)
{
	CNotify* pNotify = new CNotify;
	pNotify->m_pData = data;
	pNotify->autorelease();
	return pNotify;
}

#endif







