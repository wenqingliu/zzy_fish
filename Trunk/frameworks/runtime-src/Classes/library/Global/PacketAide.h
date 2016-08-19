#ifndef PACKET_AIDE_HEAD_FILE
#define PACKET_AIDE_HEAD_FILE

#pragma once
#include "Struct.h"
#include "string.h"

#pragma pack(1)

//////////////////////////////////////////////////////////////////////////////////

//数据定义
#define DTP_NULL					0								//无效数据

//数据描述
struct tagDataDescribe
{
	WORD							wDataSize;						//数据大小
	WORD							wDataDescribe;					//数据描述
};

//////////////////////////////////////////////////////////////////////////////////

//发送辅助类
struct CSendPacketHelper
{
	WORD							m_wDataSize;					//数据大小
	WORD							m_wMaxBytes;					//缓冲大小
	BYTE*							m_pcbBuffer;					//缓冲指针

	//函数定义
public:
	//构造函数
	inline CSendPacketHelper(BYTE* pcbBuffer, WORD wMaxBytes)
    {
    	//设置变量
        m_wDataSize=0;
        m_wMaxBytes=wMaxBytes;
        m_pcbBuffer=(BYTE *)pcbBuffer;
    }

	//功能函数
public:
	//清理数据
	inline VOID CleanData()
    {
        m_wDataSize=0;
    }
    
	//获取大小
	inline WORD GetDataSize()
    {
        return m_wDataSize;
    }
    
	//获取缓冲
	inline VOID * GetDataBuffer()
    {
        return m_pcbBuffer;
    }

	//功能函数
public:
	//插入数据
	inline bool AddPacket(VOID * pData, WORD wDataSize, WORD wDataType)
    {
        //效验数据
        assert(wDataType!=DTP_NULL);
        assert((wDataSize+sizeof(tagDataDescribe)+m_wDataSize)<=m_wMaxBytes);
        if ((wDataSize+sizeof(tagDataDescribe)+m_wDataSize)>m_wMaxBytes) return false;
        
        //插入数据
        assert(m_pcbBuffer!=NULL);
        tagDataDescribe * pDataDescribe=(tagDataDescribe *)(m_pcbBuffer+m_wDataSize);
        pDataDescribe->wDataSize=wDataSize;
        pDataDescribe->wDataDescribe=wDataType;
        
        //插入数据
        if (wDataSize>0)
        {
            assert(pData!=NULL);
            memcpy(pDataDescribe+1, pData, wDataSize);
        }
        
        //设置数据
        m_wDataSize+=sizeof(tagDataDescribe)+wDataSize;
        
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////////////
//接收辅助类
struct CRecvPacketHelper
{
	WORD							m_wDataPos;						//数据点
	WORD							m_wDataSize;					//数据大小
	BYTE*							m_pcbBuffer;					//缓冲指针

	//构造函数
    CRecvPacketHelper(BYTE* pcbBuffer, WORD wDataSize)
    {
    	//设置变量
        m_wDataPos=0;
        m_wDataSize=wDataSize;
        m_pcbBuffer=(BYTE *)pcbBuffer;
    }

	//获取数据
	inline VOID* GetData(tagDataDescribe & DataDescribe)
    {
        //效验数据
        if (m_wDataPos>=m_wDataSize)
        {
            assert(m_wDataPos==m_wDataSize);
            DataDescribe.wDataSize=0;
            DataDescribe.wDataDescribe=DTP_NULL;
            return NULL;
        }
        
        //获取数据
        assert((m_wDataPos+sizeof(tagDataDescribe))<=m_wDataSize);
        memcpy(&DataDescribe, m_pcbBuffer+m_wDataPos, sizeof(tagDataDescribe));
        assert((m_wDataPos+sizeof(tagDataDescribe)+DataDescribe.wDataSize)<=m_wDataSize);
        
        //效验数据
        if ((m_wDataPos+sizeof(tagDataDescribe)+DataDescribe.wDataSize)>m_wDataSize)
        {
            DataDescribe.wDataSize=0;
            DataDescribe.wDataDescribe=DTP_NULL;
            return NULL;
        }
        
        //设置数据
        VOID * pData=NULL;
        if (DataDescribe.wDataSize>0) pData=m_pcbBuffer+m_wDataPos+sizeof(tagDataDescribe);
        m_wDataPos+=sizeof(tagDataDescribe)+DataDescribe.wDataSize;
        
        return pData;
    }
};

//////////////////////////////////////////////////////////////////////////////////
//结构定义

//用户信息
struct tagGlobalUserData
{
	//基本资料
	DWORD							dwUserID;							//用户 I D
	DWORD							dwGameID;							//游戏 I D
	DWORD							dwExperience;						//用户经验
	DWORD							dwLoveLiness;						//用户魅力
	TCHAR							szAccounts[LEN_ACCOUNTS];			//登录帐号
	TCHAR							szNickName[LEN_NICKNAME];			//用户昵称
	TCHAR							szPassword[LEN_PASSWORD];			//登录密码
    
	//用户成绩
	SCORE							lUserScore;							//用户游戏币
	SCORE							lUserInsure;						//用户银行
	DWORD							dwUserMedal;						//用户奖牌
    
	//扩展资料
	BYTE							cbGender;							//用户性别
	BYTE							cbMoorMachine;						//锁定机器
	TCHAR							szUnderWrite[LEN_UNDER_WRITE];		//个性签名
    
	//社团资料
	DWORD							dwGroupID;							//社团索引
	TCHAR							szGroupName[LEN_GROUP_NAME];		//社团名字
    
	//会员资料
	BYTE							cbMemberOrder;						//会员等级
	YYSYSTEMTIME					MemberOverDate;						//到期时间
    
	//头像信息
	WORD							wFaceID;							//头像索引
	DWORD							dwCustomID;							//自定标识
	tagCustomFaceInfo				CustomFaceInfo;						//自定头像
};

//扩展资料
struct tagIndividualUserData
{
	//用户信息
	DWORD							dwUserID;							//用户 I D
	TCHAR							szUserNote[LEN_USER_NOTE];			//用户说明
	TCHAR							szCompellation[LEN_COMPELLATION];	//真实名字
    TCHAR                           szPassPortID[LEN_PASS_PORT_ID];     //身份证号
    TCHAR							szUnderWrite[LEN_UNDER_WRITE];		//个性签名
    
	//电话号码
	TCHAR							szSeatPhone[LEN_SEAT_PHONE];		//固定电话
	TCHAR							szMobilePhone[LEN_MOBILE_PHONE];	//移动电话
    
	//联系资料
	TCHAR							szQQ[LEN_QQ];						//Q Q 号码
	TCHAR							szEMail[LEN_EMAIL];					//电子邮件
	TCHAR							szDwellingPlace[LEN_DWELLING_PLACE];//联系地址
};


//////////////////////////////////////////////////////////////////////////////////

#pragma pack()

#endif