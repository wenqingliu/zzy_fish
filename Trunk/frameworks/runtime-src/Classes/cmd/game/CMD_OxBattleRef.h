#ifndef CMD_OX_BACCARAT_REF
#define CMD_OX_BACCARAT_REF

#include "CMD_OxBattle.h"

#include "Define.h"
#include "SpriteDefine.h"
#include "CMD_Base.h"
#include "JT_Macro.h"

//记录信息
JT_CLASS_CMD(tagServerGameRecord)
	JT_CREATE_WITH_DATAARRAY(tagServerGameRecord);
	JT_SYNTHESIZE(bool				,			bWinShunMen);						//顺门胜利
	JT_SYNTHESIZE(bool				,			bWinDuiMen);							//对门胜利
	JT_SYNTHESIZE(bool				,			bWinDaoMen);							//倒门胜利
	JT_SYNTHESIZE(bool				,			bWinHuang);							//倒门胜利
};


//失败结构
JT_CLASS_CMD(CMD_S_HunPlaceJettonFail)
	JT_SYNTHESIZE(WORD				,			wPlaceUser);							//下注玩家
	JT_SYNTHESIZE(BYTE				,			lJettonArea);						//下注区域
	JT_SYNTHESIZE(LONGLONG			,			lPlaceScore);						//当前下注
};

//更新积分
JT_CLASS_CMD(CMD_S_HunChangeUserScore)
	JT_SYNTHESIZE(WORD				,			wChairID);							//椅子号码
	JT_SYNTHESIZE(DOUBLE			,				lScore);								//玩家积分

	//庄家信息
	JT_SYNTHESIZE(WORD				,			wCurrentBankerChairID);				//当前庄家
	JT_SYNTHESIZE(BYTE				,			cbBankerTime);						//庄家局数
	JT_SYNTHESIZE(DOUBLE			,				lCurrentBankerScore);				//庄家分数
};

//申请庄家
JT_CLASS_CMD(CMD_S_HunApplyBanker)
	JT_SYNTHESIZE(WORD				,			wApplyUser);							//申请玩家
};

//取消申请(加wChairID防止昵称重名)
JT_CLASS_CMD(CMD_S_HunCancelBanker)
	JT_SYNTHESIZE(WORD              ,              wChairID);                           //玩家椅子
	JT_SYNTHESIZE_TCHAR(szCancelUser,						32);					//取消玩家
};

//切换庄家
JT_CLASS_CMD(CMD_S_HunChangeBanker)
	JT_SYNTHESIZE(WORD				,			wBankerUser);						//当庄玩家
	JT_SYNTHESIZE(LONGLONG			,			lBankerScore);						//庄家金币
};

//游戏状态
JT_CLASS_CMD(CMD_S_HunStatusFree)
	//全局信息
	JT_SYNTHESIZE(BYTE				,			cbTimeLeave);						//剩余时间

	//玩家信息
	JT_SYNTHESIZE(LONGLONG			,			lUserMaxScore);						//玩家金币

	//庄家信息
	JT_SYNTHESIZE(WORD				,			wBankerUser);						//当前庄家
	JT_SYNTHESIZE(WORD				,			cbBankerTime);						//庄家局数
	JT_SYNTHESIZE(LONGLONG			,			lBankerWinScore);					//庄家成绩
	JT_SYNTHESIZE(LONGLONG			,			lBankerScore);						//庄家分数
	JT_SYNTHESIZE(bool				,			bEnableSysBanker);					//系统做庄

	//控制信息
	JT_SYNTHESIZE(LONGLONG			,			lApplyBankerCondition);				//申请条件
	JT_SYNTHESIZE(LONGLONG			,			lAreaLimitScore);					//区域限制
	JT_SYNTHESIZE(LONGLONG			,			lSitMinSocre);						//坐下的最小金额

	//房间信息
	JT_SYNTHESIZE_TCHAR(szGameRoomName	,		SERVER_LEN);			//房间名称
};

//游戏状态
JT_CLASS_CMD(CMD_S_HunStatusPlay)
	//全局下注
	JT_GET_ARR(LONGLONG				,			lAllJettonScore);		//全体总注

	//玩家下注
	JT_GET_ARR(LONGLONG				,			lUserJettonScore);		//个人总注

	//玩家积分
	JT_SYNTHESIZE(LONGLONG			,			lUserMaxScore);						//最大下注							

	//控制信息
	JT_SYNTHESIZE(LONGLONG			,			lApplyBankerCondition);				//申请条件
	JT_SYNTHESIZE(LONGLONG			,			lAreaLimitScore);					//区域限制

	//扑克信息
	JT_GET_ARR2(BYTE				,			cbTableCardArray);					//桌面扑克

	//庄家信息
	JT_SYNTHESIZE(WORD				,			wBankerUser);						//当前庄家
	JT_SYNTHESIZE(WORD				,			cbBankerTime);						//庄家局数
	JT_SYNTHESIZE(LONGLONG			,			lBankerWinScore);					//庄家赢分
	JT_SYNTHESIZE(LONGLONG			,			lBankerScore);						//庄家分数
	JT_SYNTHESIZE(bool				,			bEnableSysBanker);					//系统做庄

	//结束信息
	JT_SYNTHESIZE(LONGLONG			,			lEndBankerScore);					//庄家成绩
	JT_SYNTHESIZE(LONGLONG			,			lEndUserScore);						//玩家成绩
	JT_SYNTHESIZE(LONGLONG			,			lEndUserReturnScore);				//返回积分
	JT_SYNTHESIZE(LONGLONG			,			lEndRevenue);						//游戏税收

	//全局信息
	JT_SYNTHESIZE(BYTE				,			cbTimeLeave);						//剩余时间
	JT_SYNTHESIZE(BYTE				,			cbGameStatus);						//游戏状态
	JT_SYNTHESIZE(LONGLONG			,			lSitMinSocre);						//坐下的最小金额

	//房间信息
	JT_SYNTHESIZE_TCHAR(szGameRoomName	,SERVER_LEN);			//房间名称
};

//游戏空闲
JT_CLASS_CMD(CMD_S_HunGameFree)
	JT_SYNTHESIZE(BYTE				,			cbTimeLeave);						//剩余时间
};



//游戏开始
JT_CLASS_CMD(CMD_S_HunGameStart)
	JT_SYNTHESIZE(WORD				,			wBankerUser);						//庄家位置
	JT_SYNTHESIZE(LONGLONG			,			lBankerScore);						//庄家金币
	JT_SYNTHESIZE(LONGLONG			,			lUserMaxScore);						//我的金币
	JT_SYNTHESIZE(BYTE				,			cbTimeLeave);						//剩余时间	
	JT_SYNTHESIZE(bool				,			bContiueCard);						//继续发牌
	JT_SYNTHESIZE(int				,			nChipRobotCount);					//人数上限 (下注机器人)
};

//用户下注
JT_CLASS_CMD(CMD_S_HunPlaceJetton)
	JT_SYNTHESIZE(WORD				,			wChairID);							//用户位置
	JT_SYNTHESIZE(BYTE				,			cbJettonArea);						//筹码区域
	JT_SYNTHESIZE(LONGLONG			,			lJettonScore);						//加注数目
	JT_SYNTHESIZE(bool				,			bIsAndroid);							//是否机器人
};

//游戏结束
JT_CLASS_CMD(CMD_S_HunGameEnd)
	//下局信息
	JT_SYNTHESIZE(BYTE				,			cbTimeLeave);						//剩余时间

	//扑克信息
	JT_GET_ARR2(BYTE				,			cbTableCardArray);				//桌面扑克
	JT_SYNTHESIZE(BYTE				,			cbLeftCardCount);					//扑克数目

	JT_SYNTHESIZE(BYTE				,			bcFirstCard);
 
	//庄家信息
	JT_SYNTHESIZE(LONGLONG			,			lBankerScore);						//庄家成绩
	JT_SYNTHESIZE(LONGLONG			,			lBankerTotallScore);					//庄家成绩
	JT_SYNTHESIZE(INT				,				nBankerTime);						//做庄次数

	//玩家成绩
	JT_SYNTHESIZE(LONGLONG			,			lUserScore);							//玩家成绩
	JT_SYNTHESIZE(LONGLONG			,			lUserReturnScore);					//返回积分

	//全局信息
	JT_SYNTHESIZE(LONGLONG			,			lRevenue);							//游戏税收
};

//用户下注
JT_CLASS_CMD(CMD_C_HunPlaceJetton)
	JT_SYNTHESIZE(BYTE				,			cbJettonArea);						//筹码区域
	JT_SYNTHESIZE(LONGLONG			,			lJettonScore);						//加注数目
};

//14.08.05新增------------------------------------------------

//申请坐下
JT_CLASS_CMD(CMD_C_ApplySit)
	JT_SYNTHESIZE(WORD				,			wSitChairID);						//申请玩家坐下ID
};

//离开位置
JT_CLASS_CMD(CMD_C_CancelSit)
	JT_SYNTHESIZE(WORD				,			wSitChairID);							//玩家椅子号	
};

//申请坐下成功
JT_CLASS_CMD(CMD_S_ApplySit)
	JT_SYNTHESIZE(WORD              ,           wSitChairID);							//坐下的椅子ID
	JT_SYNTHESIZE(WORD				,			wApplySitID);						//申请玩家坐下ID
};

//离开位置成功
JT_CLASS_CMD(CMD_S_CancelSit)
	JT_SYNTHESIZE(WORD              ,           wSitChairID);							//坐下的椅子ID
	JT_SYNTHESIZE(WORD				,			wCancelID);							//玩家椅子号					
};

//输赢信息
JT_CLASS_CMD(tagUserWLInfo)
	JT_SYNTHESIZE(WORD              ,             wChairID);							//玩家ID
	JT_SYNTHESIZE(LONGLONG			,		   lJettonScore);						//玩家成绩
};

JT_CLASS_CMD(CMD_S_WLInfo)
public:

	void initRef()
	{
		tagLoseInfo = tagUserWLInfoRef::createWithNotify();
		tagLoseInfo->cmd = this->cmd.tagLoseInfo;

		for(int i = 0;i < WIN_COUNT;i++)
		{
			tagWinInfo[i] = tagUserWLInfoRef::createWithNotify();
			tagWinInfo[i]->cmd = this->cmd.tagWinInfo[i];
		}
	};

	JT_SYNTHESIZE_REF_ARR(tagUserWLInfoRef*,	tagWinInfo,WIN_COUNT);								//赢的玩家
	JT_SYNTHESIZE_REF(tagUserWLInfoRef*,		tagLoseInfo);						//输的玩家
};

//--------------------------------------------------//



#endif //CMD_OX_BACCARAT_REF