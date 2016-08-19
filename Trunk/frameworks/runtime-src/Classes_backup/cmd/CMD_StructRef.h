#ifndef __CMD_STRUCTREF_H__
#define __CMD_STRUCTREF_H__
#include "cocos2d.h"
USING_NS_CC;
#include "Define.h"
#include "SpriteDefine.h"
#include "CMD_Base.h"
#include "JT_Macro.h"
#include "Struct.h"

JT_CLASS_CMD(tagGameServer)
	JT_SYNTHESIZE(WORD			,			wKindID);							//名称索引
	JT_SYNTHESIZE(WORD			,			wNodeID);							//节点索引
	JT_SYNTHESIZE(WORD			,			wSortID);							//排序索引
	JT_SYNTHESIZE(WORD			,			wServerID);							//房间索引
	JT_SYNTHESIZE(WORD			,			wServerPort);						//房间端口
	JT_SYNTHESIZE(DWORD			,			dwOnLineCount);						//在线人数
	JT_SYNTHESIZE(DWORD			,			dwFullCount);						//满员人数
	JT_SYNTHESIZE(LONG			,			lCellScore);							//单位积分
	JT_SYNTHESIZE(SCORE			,			lMinEnterScore);						//最低积分
	JT_SYNTHESIZE(SCORE			,			lMaxEnterScore);						//最高积分
	JT_SYNTHESIZE_TCHAR(szServerAddr,32);					//房间名称（应该是服务器地址吧）
	JT_SYNTHESIZE_TCHAR(szServerName,LEN_SERVER);			//房间名称
	JT_CREATE_WITH_DATAARRAY(tagGameServer);
};

//用户信息
JT_CLASS_CMD(tagMobileUserInfoHead)
	//用户属性
	JT_SYNTHESIZE(DWORD			,			dwGameID);							//游戏 I D
	JT_SYNTHESIZE(DWORD			,			dwUserID);							//用户 I D

		//头像信息
	JT_SYNTHESIZE(WORD			,			wFaceID);							//头像索引
	JT_SYNTHESIZE(DWORD			,			dwCustomID);							//自定标识

		//用户属性
	JT_SYNTHESIZE(BYTE			,			cbGender);							//用户性别
	JT_SYNTHESIZE(BYTE			,			cbMemberOrder);						//会员等级

		//用户状态
	JT_SYNTHESIZE(WORD			,			wTableID);							//桌子索引
	JT_SYNTHESIZE(WORD			,			wChairID);							//椅子索引
	JT_SYNTHESIZE(BYTE			,			cbUserStatus);						//用户状态

		//积分信息
	JT_SYNTHESIZE(SCORE			,			lScore);								//用户分数

		//游戏信息
	JT_SYNTHESIZE(DWORD			,			dwWinCount);							//胜利盘数
	JT_SYNTHESIZE(DWORD			,			dwLostCount);						//失败盘数
	JT_SYNTHESIZE(DWORD			,			dwDrawCount);						//和局盘数
	JT_SYNTHESIZE(DWORD			,			dwFleeCount);						//逃跑盘数
	JT_SYNTHESIZE(DWORD			,			dwExperience);						//用户经验

	JT_SYNTHESIZE_TCHAR(szNickName	,		LEN_NICKNAME);						//用户昵称
	JT_SYNTHESIZE_TCHAR(szFaceIDDownURL	,	LEN_USER_NOTE);						//自定义头像地址
};

//用户状态
JT_CLASS_CMD(tagUserStatus)
	JT_SYNTHESIZE(WORD			,			wTableID);							//桌子索引
	JT_SYNTHESIZE(WORD			,			wChairID);							//椅子位置
	JT_SYNTHESIZE(BYTE			,			cbUserStatus);						//用户状态
};

//用户积分
JT_CLASS_CMD(tagUserScore)
	//积分信息
	JT_SYNTHESIZE(SCORE			,				lScore);								//用户分数
	JT_SYNTHESIZE(SCORE			,				lGrade);								//用户成绩
	JT_SYNTHESIZE(SCORE			,				lInsure);							//用户银行

	//输赢信息
	JT_SYNTHESIZE(DWORD			,				dwWinCount);							//胜利盘数
	JT_SYNTHESIZE(DWORD			,				dwLostCount);						//失败盘数
	JT_SYNTHESIZE(DWORD			,				dwDrawCount);						//和局盘数
	JT_SYNTHESIZE(DWORD			,				dwFleeCount);						//逃跑盘数

	//全局信息
	JT_SYNTHESIZE(DWORD			,				dwUserMedal);						//用户奖牌
	JT_SYNTHESIZE(DWORD			,				dwExperience);						//用户经验
	JT_SYNTHESIZE(LONG			,				lLoveLiness);						//用户魅力
};

//用户积分
JT_CLASS_CMD(tagMobileUserScore)
	//积分信息
	JT_SYNTHESIZE(SCORE			,				lScore);								//用户分数

	//输赢信息
	JT_SYNTHESIZE(DWORD			,				dwWinCount);							//胜利盘数
	JT_SYNTHESIZE(DWORD			,				dwLostCount);						//失败盘数
	JT_SYNTHESIZE(DWORD			,				dwDrawCount);						//和局盘数
	JT_SYNTHESIZE(DWORD			,				dwFleeCount);						//逃跑盘数

	//全局信息
	JT_SYNTHESIZE(DWORD			,				dwExperience);						//用户经验
};

#endif // !__CMD_STRUCTREF_H__



