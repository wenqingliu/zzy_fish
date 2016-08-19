#ifndef __CMD_MB_LOGON_SEVER_REF__
#define __CMD_MB_LOGON_SEVER_REF__
#include "cocos2d.h"
USING_NS_CC;
#include "Define.h"
#include "SpriteDefine.h"
#include "CMD_Base.h"
#include "CMD_LogonServer.h"
#include "JT_Macro.h"

//多平台登录
JT_CLASS_CMD(CMD_MB_LogonOtherPlatform)
	JT_SYNTHESIZE(DWORD,dwPlazaVersion);
	JT_SYNTHESIZE_TCHAR(szHotVer,8);						// 热更新版本
	JT_SYNTHESIZE(BYTE,cbDeviceType);

	JT_SYNTHESIZE(BYTE,cbGender);

	JT_SYNTHESIZE_TCHAR(cVerifyString,LEN_DECRYPTO);

	JT_SYNTHESIZE_TCHAR(szNickName,LEN_NICKNAME);

	JT_SYNTHESIZE_TCHAR(szMachineID,LEN_MACHINE_ID);
	JT_SYNTHESIZE_TCHAR(szUUID,LEN_USER_NOTE);
	JT_SYNTHESIZE_TCHAR(szPassword,LEN_MD5);
	JT_SYNTHESIZE_TCHAR(szDefaultFace,LEN_USER_NOTE);
	JT_SYNTHESIZE(BYTE,cbAcccountType);

};

JT_CLASS_CMD(CMD_GP_S_USER_PAWNSHOP)
	JT_GET_ARR(DWORD           ,                ItemType);                    // 类型
	JT_GET_ARR(DWORD           ,                ItemCount);                   // 数量
	JT_GET_ARR(DWORD           ,                BuyPrice);                    // 买价格
	JT_GET_ARR(DWORD           ,                SalePrice);                   // 卖价格
	JT_GET_ARR2(TCHAR           ,                ItemName);  // 商品名称
	//JT_GET_ARR2(TCHAR           ,                szPawnShopImageURL);    //典当图片URL
};

JT_CLASS_CMD(CMD_MB_LogonSuccess)
	JT_SYNTHESIZE(BYTE   ,					  cbGender);                           //用户性别
	JT_SYNTHESIZE(DWORD  ,                   dwUserID);                           //用户 I D
	JT_SYNTHESIZE(DWORD  ,                   dwGameID);                           //游戏 I D


	JT_SYNTHESIZE(BYTE  ,      cbAccountType);                      //登录类型
	JT_SYNTHESIZE(SCORE ,      lUserScore);                         //用户金币
	JT_SYNTHESIZE(SCORE ,      lUserDaimond);
	//JT_SYNTHESIZE(WORD  ,      wContinueReward[CONTINUE_LOGIN_NUM]);//登录奖励值
	JT_SYNTHESIZE_TCHAR(         szUUID,LEN_USER_NOTE);              //唯一标识
	JT_SYNTHESIZE_TCHAR(         szNickName,LEN_NICKNAME);           //用户昵称
	JT_SYNTHESIZE_TCHAR(         szFaceURL,LEN_USER_NOTE);           //头像URL地址
};

//登录失败
JT_CLASS_CMD(CMD_MB_LogonFailure)
	JT_SYNTHESIZE(LONG,lResultCode);						//错误代码
	JT_SYNTHESIZE_TCHAR(szDescribeString,128);				//描述消息
};

//登录奖励
JT_CLASS_CMD(tagLoginAward)
	JT_SYNTHESIZE(BYTE	,			cbLoginCount);						//登录天数
	JT_SYNTHESIZE(BYTE	,			cbAwardType);						//奖励类型
	JT_SYNTHESIZE(BYTE	,			cbAwardSubType);						//奖励类型
	JT_SYNTHESIZE(WORD	,			wAwardCount);						//奖励数目
};

//登陆奖励
JT_CLASS_CMD(CMD_GP_LoginAward)
	JT_SYNTHESIZE(BYTE	,			cbMaxCount);							//最大天数
	JT_SYNTHESIZE(BYTE	,			cbDayCount);							//当前天数
	//tagLoginAward	,	LoginAward[MAX_LOGIN_AWARD];		//奖励信息
};

//升级提示
JT_CLASS_CMD(CMD_MB_UpdateNotify)
	JT_SYNTHESIZE(BYTE	,			cbMustUpdate);						//强行升级
	JT_SYNTHESIZE(BYTE	,			cbAdviceUpdate);						//建议升级
	JT_SYNTHESIZE(BYTE	,			cbHotUpdate);						//热更新
	JT_SYNTHESIZE(DWORD	,			dwCurrentVersion);					//当前版本
	JT_SYNTHESIZE_TCHAR(szHotVer,			8);						//服务端热更新版本
};

//////////////////////////////////////////////////////////////////////////////////

//银行资料
JT_CLASS_CMD(CMD_GP_UserInsureInfo)
	JT_SYNTHESIZE(WORD				,			wRevenueTake);						//税收比例
	JT_SYNTHESIZE(WORD				,			wRevenueTransfer);					//税收比例
	JT_SYNTHESIZE(WORD				,			wServerID);							//房间标识
	JT_SYNTHESIZE(SCORE				,			lUserScore);							//用户金币
	JT_SYNTHESIZE(SCORE				,			lUserInsure);						//银行金币
	JT_SYNTHESIZE(SCORE				,			lTransferPrerequisite);				//转账条件
};

//银行成功
JT_CLASS_CMD(CMD_GP_UserInsureSuccess)
    JT_SYNTHESIZE(DWORD				,			dwUserID);							//用户 I D
    JT_SYNTHESIZE(SCORE				,			lUserScore);							//用户金币
    JT_SYNTHESIZE(SCORE				,			lUserInsure);						//银行金币
    JT_SYNTHESIZE(DWORD				,			dwFromGameID);						//转出ID
    JT_SYNTHESIZE(DWORD				,			dwReceGameID);						//接收ID
    JT_SYNTHESIZE_TCHAR(						szNickName,LEN_NICKNAME);			//转出用户
    JT_SYNTHESIZE_TCHAR(						szReceName,LEN_NICKNAME);			//接收用户
    JT_SYNTHESIZE(SCORE				,			lInsureTransfer);					//转出金币
    JT_SYNTHESIZE(SCORE				,			lInsureRevenue);						//税额
    JT_SYNTHESIZE_TCHAR(						szDateTime,20);						//转账日期
    JT_SYNTHESIZE_TCHAR(						szDescribeString,128);				//描述消息
};

//////////////////////////////////////////////////////////////////////////////////

#endif //__CMD_MB_LOGON_SEVER_REF__