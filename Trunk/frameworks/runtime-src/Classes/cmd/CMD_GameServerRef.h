#ifndef __CMD_GAME_SERVER_REF__
#define __CMD_GAME_SERVER_REF__

#include "cocos2d.h"
USING_NS_CC;
#include "Define.h"
#include "SpriteDefine.h"
#include "CMD_Base.h"
#include "JT_Macro.h"
#include "CMD_StructRef.h"
#include "CMD_GameServer.h"


//房间配置
JT_CLASS_CMD(CMD_GR_ConfigServer)
	//房间属性
	JT_SYNTHESIZE(WORD			,				wTableCount);						//桌子数目
	JT_SYNTHESIZE(WORD			,				wChairCount);						//椅子数目

	//房间配置
	JT_SYNTHESIZE(WORD			,				wServerType);						//房间类型
	JT_SYNTHESIZE(DWORD			,				dwServerRule);						//房间规则
};

//用户状态
JT_CLASS_CMD(CMD_GR_UserStatus)
void initRef(){
	UserStatus = tagUserStatusRef::createWithNotify();
	UserStatus->cmd = this->cmd.UserStatus;
};
	JT_SYNTHESIZE(DWORD			,dwUserID);							//用户标识
	JT_SYNTHESIZE_REF(tagUserStatusRef*,UserStatus);							//用户状态
};

//用户分数
JT_CLASS_CMD(CMD_GR_UserScore)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
void initRef(){
	UserScore = tagUserScoreRef::createWithNotify();
	UserScore->cmd = this->cmd.UserScore;
};
	JT_SYNTHESIZE(DWORD				,			dwUserID);							//用户标识
	JT_SYNTHESIZE_REF(tagUserScoreRef*	,	UserScore);							//积分信息
};

//用户分数
JT_CLASS_CMD(CMD_GR_MobileUserScore)
void initRef(){
	UserScore = tagMobileUserScoreRef::createWithNotify();
	UserScore->cmd = this->cmd.UserScore;
}
JT_SYNTHESIZE(DWORD					,		dwUserID);							//用户标识
JT_SYNTHESIZE_REF(tagMobileUserScoreRef*,UserScore);							//积分信息
};

//请求失败
JT_CLASS_CMD(CMD_GR_RequestFailure)
JT_SYNTHESIZE(LONG,lErrorCode);							//错误代码
JT_SYNTHESIZE_TCHAR(szDescribeString,256);				//描述信息
};


//发送喇叭
JT_CLASS_CMD(CMD_GR_C_SendTrumpet)
	JT_SYNTHESIZE(BYTE             ,              cbRequestArea);                        //请求范围 
	JT_SYNTHESIZE(WORD             ,              wPropertyIndex);                      //道具索引 
	JT_SYNTHESIZE(DWORD            ,              TrumpetColor);                        //喇叭颜色
	JT_SYNTHESIZE_TCHAR(szTrumpetContent,TRUMPET_MAX_CHAR);  //喇叭内容
};

//发送喇叭
JT_CLASS_CMD(CMD_GR_S_SendTrumpet)
	JT_SYNTHESIZE(WORD        ,                   wPropertyIndex);                      //道具索引 
	JT_SYNTHESIZE(DWORD       ,                   dwSendUserID);                         //用户 I D
	JT_SYNTHESIZE(DWORD       ,                   TrumpetColor);                        //喇叭颜色
	JT_SYNTHESIZE_TCHAR(szSendNickName,32);				    //玩家昵称 
	JT_SYNTHESIZE_TCHAR(szTrumpetContent,TRUMPET_MAX_CHAR);  //喇叭内容
};

// 喇叭道具
JT_CLASS_CMD(CMD_GR_PropSouna)
    JT_SYNTHESIZE(DWORD			,					playerID);							// 用户ID
    JT_SYNTHESIZE(WORD			,					wGameID);							// 游戏ID
    JT_SYNTHESIZE(WORD			,					wSuonaType);							// 喇叭类型
    JT_SYNTHESIZE_TCHAR(szMsg,256);                         // 喇叭消息内容
    JT_SYNTHESIZE_TCHAR(szNickName,LEN_NICKNAME);           // 用户昵称
} ;


//用户聊天
JT_CLASS_CMD(CMD_GR_S_UserChat)
	JT_SYNTHESIZE(WORD			,				wChatLength);						//信息长度
	JT_SYNTHESIZE(DWORD			,				dwChatColor);						//信息颜色
	JT_SYNTHESIZE(DWORD			,				dwSendUserID);						//发送用户
	JT_SYNTHESIZE(DWORD			,				dwTargetUserID);						//目标用户
	JT_SYNTHESIZE_TCHAR(szChatString,LEN_USER_CHAT);		//聊天信息
};

//用户发送表情
JT_CLASS_CMD(CMD_GF_S_UserExpression)
	JT_SYNTHESIZE(WORD			,				wItemIndex);						//信息长度
	JT_SYNTHESIZE(DWORD			,				dwSendUserID);						//发送用户
	JT_SYNTHESIZE(DWORD			,				dwTargetUserID);						//目标用户
};

//转账记录
JT_CLASS_CMD(CMD_GR_S_TransGoldRecordInfo)
	JT_SYNTHESIZE(DWORD         ,  dwSourceGameID);                            //转出ID
	JT_SYNTHESIZE(DWORD         ,  dwTargetGameID);                            //目标ID
	JT_SYNTHESIZE(SCORE         ,  lTransScores);                              //转账数目
	JT_SYNTHESIZE_TCHAR(szNickName,LEN_NICKNAME);                  //用记昵称
	JT_SYNTHESIZE_TCHAR(szDateTime,MAX_COLUMN);                    //转账日期
	JT_SYNTHESIZE_TCHAR(szClientIP,16);                            //客户端IP
	JT_SYNTHESIZE_TCHAR(szDescMsg,64);                    //结果提示
};

#endif //__CMD_GAME_SERVER_REF__