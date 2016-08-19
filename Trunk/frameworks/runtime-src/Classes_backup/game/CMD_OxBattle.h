#ifndef CMD_BACCARAT_HEAD_FILE
#define CMD_BACCARAT_HEAD_FILE

#include "Define.h"

//状态定义
#define	GS_PLACE_JETTON				GAME_STATUS_PLAY					//下注状态
#define	GS_GAME_END					GAME_STATUS_PLAY+1					//结束状态
#define	GS_MOVECARD_END				GAME_STATUS_PLAY+2					//结束状态

//长度
#define MAX_INDEX					3									//最大索引
#define AREA_COUNT					5									//区域数目
#define AREA_CARD_COUNT             5                                   //拥有牌数
#define SERVER_LEN					32									//房间长度
#define HUN_GAME_PLAYER			    100									//游戏人数

#pragma pack(1)

//服务器命令结构
#define SUB_S_GAME_FREE				99									//游戏空闲
#define SUB_S_GAME_START			100									//游戏开始
#define SUB_S_PLACE_JETTON			101									//用户下注
#define SUB_S_HUN_GAME_END		    102									//游戏结束
#define SUB_S_APPLY_BANKER			103									//申请庄家
#define SUB_S_CHANGE_BANKER			104									//切换庄家
#define SUB_S_CHANGE_USER_SCORE		105									//更新积分
#define SUB_S_SEND_RECORD			106									//游戏记录
#define SUB_S_PLACE_JETTON_FAIL		107									//下注失败
#define SUB_S_CANCEL_BANKER			108									//取消申请

//游戏状态
#define GAME_STATUS_FREE            0                                  //空闲状态
#define GAME_STATUS_PLAY            100                                //游戏状态
#define GAME_STATUS_WAIT            200                                //等待状态

//记录信息
typedef struct
{
	bool							bWinShunMen;						//顺门胜利
	bool							bWinDuiMen;							//对门胜利
	bool							bWinDaoMen;							//倒门胜利
	bool							bWinHuang;							//倒门胜利
} tagServerGameRecord;


//失败结构
typedef struct
{
    BYTE							lJettonArea;						//下注区域
	WORD							wPlaceUser;							//下注玩家
	LONGLONG						lPlaceScore;						//当前下注
} CMD_S_HunPlaceJettonFail;

//更新积分
typedef struct
{
    BYTE							cbBankerTime;						//庄家局数
	WORD							wChairID;							//椅子号码
    WORD							wCurrentBankerChairID;				//当前庄家
    
    //庄家信息
	DOUBLE							lScore;								//玩家积分
	DOUBLE							lCurrentBankerScore;				//庄家分数
} CMD_S_HunChangeUserScore;

//申请庄家
typedef struct
{
	WORD							wApplyUser;							//申请玩家
} CMD_S_HunApplyBanker;

//取消申请
typedef struct
{
    WORD                            wChairID;                           //玩家椅子
	TCHAR							szCancelUser[32];					//取消玩家
} CMD_S_HunCancelBanker;

//切换庄家
typedef struct
{
	WORD							wBankerUser;						//当庄玩家
	LONGLONG						lBankerScore;						//庄家金币
} CMD_S_HunChangeBanker;

//游戏状态
typedef struct
{
	//全局信息
	BYTE							cbTimeLeave;						//剩余时间
    bool							bEnableSysBanker;					//系统做庄
	WORD							wBankerUser;						//当前庄家
    WORD							cbBankerTime;						//庄家局数
	
    //玩家信息
	LONGLONG						lUserMaxScore;						//玩家金币
	LONGLONG						lBankerWinScore;					//庄家成绩
	LONGLONG						lBankerScore;						//庄家分数

	//控制信息
	LONGLONG						lApplyBankerCondition;				//申请条件
	LONGLONG						lAreaLimitScore;					//区域限制
    LONGLONG						lSitMinSocre;						//坐下的最小金额

	//房间信息
	TCHAR							szGameRoomName[SERVER_LEN];			//房间名称
} CMD_S_HunStatusFree;

//游戏状态
typedef struct
{
	//全局信息
	BYTE							cbTimeLeave;						//剩余时间
	BYTE							cbGameStatus;						//游戏状态
	bool							bEnableSysBanker;					//系统做庄
    
	//扑克信息
	BYTE							cbTableCardArray[AREA_COUNT][AREA_CARD_COUNT]; //桌面扑克
    
	WORD							wBankerUser;						//当前庄家
	WORD							cbBankerTime;						//庄家局数
    
	//全局下注
	LONGLONG						lAllJettonScore[AREA_COUNT];        //全体总注
    
	//玩家下注
	LONGLONG						lUserJettonScore[AREA_COUNT];		//个人总注
    
	//玩家积分
	LONGLONG						lUserMaxScore;						//最大下注
    
	//控制信息
	LONGLONG						lApplyBankerCondition;				//申请条件
	LONGLONG						lAreaLimitScore;					//区域限制
    
	//庄家信息
	LONGLONG						lBankerWinScore;					//庄家赢分
	LONGLONG						lBankerScore;						//庄家分数
    
	//结束信息
	LONGLONG						lEndBankerScore;					//庄家成绩
	LONGLONG						lEndUserScore;						//玩家成绩
	LONGLONG						lEndUserReturnScore;				//返回积分
	LONGLONG						lEndRevenue;						//游戏税收
    LONGLONG						lSitMinSocre;						//坐下的最小金额

	//房间信息
	TCHAR							szGameRoomName[SERVER_LEN];			//房间名称
    
} CMD_S_HunStatusPlay;

//游戏空闲
typedef struct
{
	BYTE							cbTimeLeave;						//剩余时间
} CMD_S_HunGameFree;

//游戏开始
typedef struct
{
    BYTE							cbTimeLeave;						//剩余时间
    bool							bContiueCard;						//继续发牌
    WORD							wBankerUser;						//庄家位置
    int								nChipRobotCount;					//人数上限 (下注机器人)
    LONGLONG						lBankerScore;						//庄家金币
	LONGLONG						lUserMaxScore;						//我的金币
} CMD_S_HunGameStart;

//用户下注
typedef struct
{
    bool							bIsAndroid;							//是否机器人
    BYTE							cbJettonArea;						//筹码区域
	WORD							wChairID;							//用户位置
	LONGLONG						lJettonScore;						//加注数目
} CMD_S_HunPlaceJetton;

//游戏结束
typedef struct
{
	//下局信息
    BYTE							cbTimeLeave;						//剩余时间
	BYTE							cbLeftCardCount;					//扑克数目
	BYTE							bcFirstCard;                        //第一张牌
	BYTE							cbTableCardArray[AREA_COUNT][AREA_CARD_COUNT]; //桌面扑克
	int								nBankerTime;						//做庄次数
	//庄家信息
	LONGLONG						lBankerScore;						//庄家成绩
	LONGLONG						lBankerTotallScore;					//庄家总成绩
	LONGLONG						lUserScore;							//玩家成绩
	LONGLONG						lUserReturnScore;					//返回积分
	LONGLONG						lRevenue;							//游戏税收
} CMD_S_HunGameEnd;

//客户端命令结构
#define SUB_C_PLACE_JETTON			1									//用户下注
#define SUB_C_APPLY_BANKER			2									//申请庄家
#define SUB_C_CANCEL_BANKER			3									//取消申请
#define SUB_C_CONTINUE_CARD			4									//继续发牌
#define SUB_C_AMDIN_COMMAND			5									//管理员命令
#define SUB_C_GET_ACCOUNT			6									//获取昵称
#define SUB_C_CHEAK_ACCOUNT			7									//获取昵称

//客户端消息
#define IDM_ADMIN_COMMDN			WM_USER+1000
#define IDM_GET_ACCOUNT				WM_USER+1001
#define IDM_CHEAK_ACCOUNT			WM_USER+1002

typedef struct
{
	LONGLONG						lUserJettonScore[AREA_COUNT];		//个人总注
} CMD_S_HunUserJettonScore;

//用户下注
typedef struct
{
	BYTE							cbJettonArea;						//筹码区域
	LONGLONG						lJettonScore;						//加注数目
} CMD_C_HunPlaceJetton;



//14.08.05新增------------------------------------------------

//申请坐下
struct CMD_C_ApplySit
{
	WORD                            wSitChairID;							//坐下的椅子ID
};
//离开位置
struct CMD_C_CancelSit
{
	WORD                            wSitChairID;							//坐下的椅子ID
};

//申请坐下成功
struct CMD_S_ApplySit
{
	WORD                            wSitChairID;							//坐下的椅子ID
	WORD							wApplySitID;						//申请玩家坐下ID
};

//离开位置成功
struct CMD_S_CancelSit
{
	WORD                            wSitChairID;							//坐下的椅子ID
	WORD							wCancelID;							//玩家椅子号					
};

#define SUB_S_WLOSE_INFO            114									//输赢信息
#define WIN_COUNT					3									//胜利个数

//输赢信息
struct tagUserWLInfo
{
	WORD                           wChairID;							//玩家ID
	LONGLONG					   lJettonScore;						//玩家成绩
};

struct CMD_S_WLInfo
{
	tagUserWLInfo                   tagWinInfo[WIN_COUNT];				//赢的玩家
	tagUserWLInfo					tagLoseInfo;						//输的玩家
};
///




//--------------------------------------------------//


#pragma pack()
//
///// 筹码金额
//#define ChipQuota @[@"1000", @"10000", @"100000", @"500000", @"1000000", @"5000000"]
//
///// 系统坐庄的椅子号
//#define SystemBankerChairID 65535
//#define SystemBankerName @"无人坐庄"

/// 游戏状态
typedef enum {
    GameStatusKnown     = 0,
    GameStatusBet       = 1,
    GameStatusPlay      = 2,
    GameStatusFree      = 3,
} GameStatusType;

/// 申请上庄状态
typedef enum {
    AskBankerStatusAsk           = 0,  // 申请上庄
    AskBankerStatusRelieved      = 1,  // 申请下庄
    AskBankerStatusCancel        = 2,  // 取消申请上庄
} AskBankerStatus;

/// 申请上庄需要最低分数
#define AskBankerMaxScore 1000000

/// 动画时间
#define TimeForDistribute      0.3f        // 扑克移动
#define TimeForStretchCardBack 0.4f        // 牌背伸展
#define TimeForTurnCard        0.2f        // 翻牌
#define TimeForStretchRealCard 0.5f        // 牌面伸展
#define TimeForShowCardMachine 0.5f        // 显示发牌机
#define TimeForShowNiuNiuView  0.5f        // 显示牛牛
#define TimeForShowStatusView  0.5f        // 显示状态
#define TimeForChipHaloBreath  0.2f        // 筹码光圈
#define TimeForAreaHalo        0.4f        // 区域输赢光圈效果
#define TimeForAreaHaloDelay   3.0f        // 闪朔等待时间

#endif