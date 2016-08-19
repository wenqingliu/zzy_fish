#ifndef CMD_OX_BACCARAT_NEW_REF
#define CMD_OX_BACCARAT_NEW_REF

#include "cocos2d.h"
USING_NS_CC;

#include "CMD_OxBattleNew.h"
#include "CMD_OxBattleRef.h"
#include "Define.h"
#include "SpriteDefine.h"
#include "CMD_Base.h"
#include "JT_Macro.h"

//上一轮从奖池获得第一名
JT_CLASS_CMD(tagAwardFirst)
	JT_SYNTHESIZE(DWORD              ,             dwGameID);							//玩家ID
	JT_SYNTHESIZE_TCHAR(szUserName  ,			LEN_NICKNAME);				//玩家昵称
	JT_SYNTHESIZE(LONGLONG          ,             lWinScore);							//玩家分数
	JT_SYNTHESIZE(LONGLONG			,		   lExtraScore);							//玩家额外分数
	JT_SYNTHESIZE(bool				,		   bExtraScore);							//玩家上轮是否有额外分数
};

//游戏状态(场景消息:空闲进入)
JT_CLASS_CMD(CMD_S_HunNewStatusFree)

	void initRef()
	{
		TagAwardFirst = tagAwardFirstRef::createWithNotify();
		TagAwardFirst->cmd = this->cmd.awardFirst;
	}

	//全局信息
	JT_SYNTHESIZE(BYTE				,			cbTimeLeave);						//剩余时间
	JT_SYNTHESIZE(bool				,			bEnableSysBanker);					//系统做庄


	//庄家信息
	JT_SYNTHESIZE(WORD				,			wBankerUser);						//当前庄家
	JT_SYNTHESIZE(WORD				,			cbBankerTime);						//庄家局数

	//玩家信息
	JT_SYNTHESIZE(LONGLONG			,			lUserMaxScore);						//玩家金币
	JT_SYNTHESIZE(LONGLONG			,			lBankerWinScore);					//庄家成绩
	JT_SYNTHESIZE(LONGLONG			,			lBankerScore);						//庄家分数

	//控制信息
	JT_SYNTHESIZE(LONGLONG			,			lApplyBankerCondition);				//申请条件
	JT_SYNTHESIZE(LONGLONG			,			lAreaLimitScore);					//区域限制
	JT_SYNTHESIZE(LONGLONG			,			lStorageStart);						//库存
	JT_SYNTHESIZE(LONGLONG			,			lSitMinSocre);						//坐下的最小金额
	JT_SYNTHESIZE_REF(tagAwardFirstRef*    ,           TagAwardFirst);						//奖金池赢家

	//房间信息
	JT_SYNTHESIZE_TCHAR(szGameRoomName,SERVER_LEN);			//房间名称
};

//游戏状态(场景消息:游戏进行中)
JT_CLASS_CMD(CMD_S_HunNewStatusPlay)

	void initRef()
	{
		TagAwardFirst = tagAwardFirstRef::createWithNotify();
		TagAwardFirst->cmd = this->cmd.awardFirst;
	}

	//全局信息
	JT_SYNTHESIZE(BYTE				,			cbTimeLeave);						//剩余时间
	JT_SYNTHESIZE(BYTE				,			cbGameStatus);						//游戏状态
	JT_SYNTHESIZE(bool				,			bEnableSysBanker);					//系统做庄
	
	JT_GET_ARR2(BYTE				,			cbTableCardArray);				//桌面扑克

	//庄家信息
	JT_SYNTHESIZE(WORD				,			wBankerUser);						//当前庄家
	JT_SYNTHESIZE(WORD				,			cbBankerTime);						//庄家局数
	//全局下注
	JT_GET_ARR(LONGLONG			,			lAllJettonScore);		//全体总注

	//玩家下注
	JT_GET_ARR(LONGLONG			,			lUserJettonScore);		//个人总注

	//玩家积分
	JT_SYNTHESIZE(LONGLONG			,			lUserMaxScore);						//最大下注							

	//控制信息
	JT_SYNTHESIZE(LONGLONG			,			lApplyBankerCondition);				//申请条件
	JT_SYNTHESIZE(LONGLONG			,			lAreaLimitScore);					//区域限制


	JT_SYNTHESIZE(LONGLONG			,			lBankerWinScore);					//庄家赢分
	JT_SYNTHESIZE(LONGLONG			,			lBankerScore);						//庄家分数

	//结束信息
	JT_SYNTHESIZE(LONGLONG			,			lEndBankerScore);					//庄家成绩
	JT_SYNTHESIZE(LONGLONG			,			lEndUserScore);						//玩家成绩
	JT_SYNTHESIZE(LONGLONG			,			lEndUserReturnScore);				//返回积分
	JT_SYNTHESIZE(LONGLONG			,			lEndRevenue);						//游戏税收
    JT_SYNTHESIZE(LONGLONG			,			lStorageStart);						//奖池库存
	JT_SYNTHESIZE(LONGLONG			,			lSitMinSocre);						//坐下的最小金额
	JT_SYNTHESIZE_REF(tagAwardFirstRef* ,		TagAwardFirst);						//奖金池赢家
	

	//房间信息
	JT_SYNTHESIZE_TCHAR(szGameRoomName,SERVER_LEN);			//房间名称
};

//游戏结束
JT_CLASS_CMD(CMD_S_HunNewGameEnd)
	void initRef()
	{
		tagLoseInfo = tagUserWLInfoRef::createWithNotify();
		tagLoseInfo->cmd = this->cmd.tagLoseInfo;

		for(int i = 0;i < WIN_COUNT;i++)
		{
			tagWinInfo[i] = tagUserWLInfoRef::createWithNotify();
			tagWinInfo[i]->cmd = this->cmd.tagWinInfo[i];
		}
		TagAwardFirst = tagAwardFirstRef::createWithNotify();
		TagAwardFirst->cmd = this->cmd.awardFirst;
	}

	//下局信息
	JT_SYNTHESIZE(BYTE				,			cbTimeLeave);						//剩余时间

	//扑克信息
	JT_SYNTHESIZE(BYTE				,			cbLeftCardCount);					//扑克数目

	JT_SYNTHESIZE(BYTE				,			bcFirstCard);
 	JT_GET_ARR2(BYTE				,			cbTableCardArray);				//桌面扑克
	JT_SYNTHESIZE(int				,				nBankerTime);						//做庄次数

	//庄家信息
	JT_SYNTHESIZE(LONGLONG			,			lBankerScore);						//庄家成绩
	JT_SYNTHESIZE(LONGLONG			,			lBankerTotallScore);					//庄家成绩

	//玩家成绩
	JT_SYNTHESIZE(LONGLONG			,			lUserScore);							//玩家成绩
	JT_SYNTHESIZE(LONGLONG			,			lUserReturnScore);					//返回积分

	//全局信息
	JT_SYNTHESIZE(LONGLONG			,			lRevenue);							//游戏税收
	JT_SYNTHESIZE_REF_ARR(tagUserWLInfoRef*,tagWinInfo,         WIN_COUNT);				//赢的玩家
	JT_SYNTHESIZE_REF(tagUserWLInfoRef*	,		tagLoseInfo);						//输的玩家
	JT_SYNTHESIZE(LONGLONG			,			lExtraScore);						//奖励金额
	JT_SYNTHESIZE(int 				,			nRedPackage);						//是否可以领取红包	
	JT_SYNTHESIZE(LONGLONG			,			lStorageStart);						//奖金池
	//奖金池
	JT_SYNTHESIZE_REF(tagAwardFirstRef*    ,	TagAwardFirst);						    //奖金池赢家
	JT_SYNTHESIZE(BYTE				,			cbRedTimeLeave);						//红包剩余时间
};

//游戏空闲
JT_CLASS_CMD(CMD_S_HunNewGameFree)
	JT_SYNTHESIZE(BYTE				,			cbTimeLeave);						//剩余时间	
	//JT_SYNTHESIZE(WORD				,			wLastBankerID);						//上轮庄家
 //   JT_SYNTHESIZE(int 				,			nRedPackage);						//可以领几个红包，0不可以领红包
} ;

//领取红包成功
JT_CLASS_CMD(CMD_S_HunNewRED_PACKAGE)
	JT_SYNTHESIZE(LONGLONG			,		   lAwardScore);							//领取红包金额;
};


#endif //CMD_OX_BACCARAT_NEW_REF