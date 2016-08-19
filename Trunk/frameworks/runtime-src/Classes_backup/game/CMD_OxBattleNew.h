#ifndef CMD_OXBATTLE_NEW_HEAD_FILE
#define CMD_OXBATTLE_NEW_HEAD_FILE

#include "Define.h"
#include "CMD_OxBattle.h"

#define SUB_S_RED_PACKAGE			115									//发送红包
#define SUB_C_RED_PACKAGE			10									//发送红包

#pragma pack(push)
#pragma pack(1)

//上一轮从奖池获得第一名
struct tagAwardFirst
{
	DWORD                          dwGameID;							//玩家ID
	TCHAR						   szUserName[LEN_NICKNAME];				//玩家昵称
	LONGLONG                       lWinScore;							//玩家分数
	LONGLONG					   lExtraScore;							//玩家额外分数
	bool						   bExtraScore;							//玩家上轮是否有额外分数
};


//游戏状态(场景消息:空闲进入)
struct CMD_S_HunNewStatusFree
{
	//全局信息
	BYTE							cbTimeLeave;						//剩余时间
	bool							bEnableSysBanker;					//系统做庄


	//庄家信息
	WORD							wBankerUser;						//当前庄家
	WORD							cbBankerTime;						//庄家局数

	//玩家信息
	LONGLONG						lUserMaxScore;						//玩家金币
	LONGLONG						lBankerWinScore;					//庄家成绩
	LONGLONG						lBankerScore;						//庄家分数

	//控制信息
	LONGLONG						lApplyBankerCondition;				//申请条件
	LONGLONG						lAreaLimitScore;					//区域限制
	LONGLONG						lStorageStart;						//奖池库存
	LONGLONG						lSitMinSocre;						//坐下的最小金额
	tagAwardFirst                   awardFirst;						//奖金池赢家
	//房间信息
	TCHAR							szGameRoomName[SERVER_LEN];			//房间名称

};

//游戏状态(场景消息:游戏进行中)
struct CMD_S_HunNewStatusPlay
{
	//全局信息
	BYTE							cbTimeLeave;						//剩余时间
	BYTE							cbGameStatus;						//游戏状态
	bool							bEnableSysBanker;					//系统做庄
	//扑克信息
	BYTE							cbTableCardArray[5][5];				//桌面扑克

	//庄家信息
	WORD							wBankerUser;						//当前庄家
	WORD							cbBankerTime;						//庄家局数
	//全局下注
	LONGLONG						lAllJettonScore[AREA_COUNT];		//全体总注

	//玩家下注
	LONGLONG						lUserJettonScore[AREA_COUNT];		//个人总注

	//玩家积分
	LONGLONG						lUserMaxScore;						//最大下注							

	//控制信息
	LONGLONG						lApplyBankerCondition;				//申请条件
	LONGLONG						lAreaLimitScore;					//区域限制


	LONGLONG						lBankerWinScore;					//庄家赢分
	LONGLONG						lBankerScore;						//庄家分数

	//结束信息
	LONGLONG						lEndBankerScore;					//庄家成绩
	LONGLONG						lEndUserScore;						//玩家成绩
	LONGLONG						lEndUserReturnScore;				//返回积分
	LONGLONG						lEndRevenue;						//游戏税收
    LONGLONG						lStorageStart;						//奖池库存
	LONGLONG						lSitMinSocre;						//坐下的最小金额
	tagAwardFirst                   awardFirst;						//奖金池赢家
	
	//房间信息
	TCHAR							szGameRoomName[SERVER_LEN];			//房间名称

};

//游戏结束
typedef struct
{
	//下局信息
	BYTE							cbTimeLeave;						//剩余时间

	//扑克信息
	BYTE							cbLeftCardCount;					//扑克数目

	BYTE							bcFirstCard;
 	BYTE							cbTableCardArray[5][5];				//桌面扑克
	int								nBankerTime;						//做庄次数

	//庄家信息
	LONGLONG						lBankerScore;						//庄家成绩
	LONGLONG						lBankerTotallScore;					//庄家成绩

	//玩家成绩
	LONGLONG						lUserScore;							//玩家成绩
	LONGLONG						lUserReturnScore;					//返回积分

	//全局信息
	LONGLONG						lRevenue;							//游戏税收
	tagUserWLInfo                   tagWinInfo[WIN_COUNT];				//赢的玩家
	tagUserWLInfo					tagLoseInfo;						//输的玩家
	LONGLONG						lExtraScore;						//奖励金额
	int 							nRedPackage;						//是否可以领取红包	
	LONGLONG						lStorageStart;						//奖金池

	//奖金池
	tagAwardFirst                   awardFirst;						    //奖金池赢家
	BYTE							cbRedTimeLeave;						//红包剩余时间
	
}CMD_S_HunNewGameEnd;

//游戏空闲
typedef struct
{
	BYTE							cbTimeLeave;						//剩余时间	
	//WORD                            wLastBankerID;						//上轮庄家
 //   int 							nRedPackage;						//可以领几个红包，0不可以领红包
} CMD_S_HunNewGameFree;


//领取红包成功
struct CMD_S_HunNewRED_PACKAGE
{
	LONGLONG					   lAwardScore;							//领取红包金额;
};

#pragma pack(pop)

#endif //#CMD_OXBATTLE_NEW_HEAD_FILE