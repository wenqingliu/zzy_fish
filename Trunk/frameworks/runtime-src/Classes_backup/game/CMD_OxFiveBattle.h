#ifndef CMD_OX_HEAD_FILE
#define CMD_OX_HEAD_FILE

#include "Define.h"

#pragma pack(push)  
#pragma pack(1)
//////////////////////////////////////////////////////////////////////////
//公共宏定义

#define KIND_ID							25									//游戏 I D
#define GAME_PLAYER						5									//游戏人数
#define GAME_NAME						TEXT("百变牛牛")					//游戏名字
#define MAX_COUNT						5									//最大数目
#define MAX_JETTON_AREA					4									//下注区域
#define MAX_TIMES						10									//最大赔率

#define VERSION_SERVER					PROCESS_VERSION(6,0,3)				//程序版本
#define VERSION_CLIENT					PROCESS_VERSION(6,0,3)				//程序版本

//结束原因
#define GER_NO_PLAYER					0x10								//没有玩家

//游戏状态
#define GS_TK_FREE						GAME_STATUS_FREE					//等待开始
#define GS_TK_CALL						GAME_STATUS_PLAY					//叫庄状态
#define GS_TK_SCORE						GAME_STATUS_PLAY+1					//下注状态
#define GS_TK_PLAYING					GAME_STATUS_PLAY+2					//游戏进行

#define SERVER_LEN						32 

//////////////////////////////////////////////////////////////////////////
//服务器命令结构
#define SUB_MB_C_SHOW_TIP_REQUEST      19                         //出牌提示
#define SUB_MB_S_SHOW_TIP_RESPONSE     20                         //提示返回

enum SUB_S
{
	 SUB_S_GAME_START		=	100,								//游戏开始
	 SUB_S_ADD_SCORE		=	101,								//加注结果
	 SUB_S_PLAYER_EXIT		=	102,								//用户强退
	 SUB_S_SEND_CARD		=	103,								//发牌消息
	 SUB_S_GAME_END			=	104,								//游戏结束
	 SUB_S_OPEN_CARD		=	105,								//用户摊牌
	 SUB_S_CALL_BANKER		=	106,								//通知叫庄
	 SUB_S_ALL_CARD			=	107,								//所有扑克
	 SUB_S_AMDIN_COMMAND	=	108,								//系统控制
	 SUB_S_BANKER_OPERATE	=	109,								//存取款
	 SUB_S_BONUS_GAME		=	110,								//有奖游戏
	 SUB_S_BONUS_GAME_Result =	111,								//有奖结果
	 SUB_S_ENABLE_OPEN_CARD  =  112,								//通知开牌
	 SUB_S_USER_CALL		 =	113,								//用户叫庄
};

#ifndef _UNICODE
#define myprintf	_snprintf
#define mystrcpy	strcpy
#define mystrlen	strlen
#define myscanf		_snscanf
#define	myLPSTR		LPCSTR
#define myatoi      atoi
#define myatoi64    _atoi64
#else
#define myprintf	swprintf
#define mystrcpy	wcscpy
#define mystrlen	wcslen
#define myscanf		_snwscanf
#define	myLPSTR		LPWSTR
#define myatoi      _wtoi
#define myatoi64	_wtoi64
#endif

//空闲状态
struct CMD_S_StatusFree
{
	LONGLONG							lCellScore;							//基础积分
	LONGLONG							lTurnScore[GAME_PLAYER];			//积分信息
	LONGLONG							lCollectScore[GAME_PLAYER];			//积分信息
	TCHAR								szGameRoomName[SERVER_LEN];			//房间名称
};

//叫庄状态
struct CMD_S_StatusCall
{
	WORD                                wCallBanker;                           //叫庄用户
	BYTE                                cbDynamicJoin;                         //动态加入 
	BYTE                                cbPlayStatus[GAME_PLAYER];             //用户状态
	LONGLONG							lTurnScore[GAME_PLAYER];			   //积分信息
	LONGLONG							lCollectScore[GAME_PLAYER];			   //积分信息
	TCHAR								szGameRoomName[SERVER_LEN];			   //房间名称
	BYTE								cbHandCardData[GAME_PLAYER][MAX_COUNT];//桌面扑克
	BYTE								cbCallBankerStatus[GAME_PLAYER];	   //叫庄状态(0:不叫,1:叫庄,2:未叫)
};

//下注状态
struct CMD_S_StatusScore
{
	//下注信息
	BYTE                                cbPlayStatus[GAME_PLAYER];             //用户状态
	BYTE                                cbDynamicJoin;                         //动态加入
	LONGLONG							lTurnMaxScore;						   //最大下注
	LONGLONG							lTableScore[GAME_PLAYER];			   //下注分数
	WORD								wBankerUser;						   //庄家用户
	TCHAR								szGameRoomName[SERVER_LEN];			   //房间名称
	LONGLONG							lTurnScore[GAME_PLAYER];			   //积分信息
	LONGLONG							lCollectScore[GAME_PLAYER];			   //积分信息
	BYTE								cbHandCardData[GAME_PLAYER][MAX_COUNT];//桌面扑克
};

//游戏状态
struct CMD_S_StatusPlay
{
	BYTE                                cbPlayStatus[GAME_PLAYER];              //用户状态
	BYTE                                cbDynamicJoin;                          //动态加入
	LONGLONG							lTurnMaxScore;						    //最大下注
	LONGLONG							lTableScore[GAME_PLAYER];			    //下注数目
	WORD								wBankerUser;						    //庄家用户

	//扑克信息
	BYTE								cbHandCardData[GAME_PLAYER][MAX_COUNT]; //桌面扑克
	BYTE								bOxCard[GAME_PLAYER];					//牛牛数据
	BOOL								bOpenUser[GAME_PLAYER];					//摊牌用户

	//历史积分
	LONGLONG							lTurnScore[GAME_PLAYER];			    //积分信息
	LONGLONG							lCollectScore[GAME_PLAYER];			    //积分信息
	TCHAR								szGameRoomName[SERVER_LEN];			    //房间名称
};

//用户叫庄
struct CMD_S_CallBanker
{
	WORD								wCallBanker;						//叫庄用户
	bool								bFirstTimes;						//是否叫庄
	BYTE								cbCallTime;							//叫庄时间
};

//游戏开始
struct CMD_S_GameStart
{	
	LONGLONG							lTurnMaxScore;						//最大下注
	WORD								wBankerUser;						//庄家用户
	BYTE								cbSelBankerTime;					//选庄家时间
};

//用户下注
struct CMD_S_AddScore
{
	WORD								wAddScoreUser;						//加注用户
	LONGLONG							lAddScoreCount;						//加注数目
};

//游戏结束
struct CMD_S_GameEnd
{
	LONGLONG							lGameTax[GAME_PLAYER];				//游戏税收
	LONGLONG							lGameScore[GAME_PLAYER];			//游戏得分
	BYTE								cbCardData[GAME_PLAYER];			//用户扑克
};

//发牌数据包
struct CMD_S_SendCard
{
	BYTE								cbCardData[GAME_PLAYER][MAX_COUNT];	//用户扑克
};

//发牌数据包(不用)
struct CMD_S_AllCard
{
	bool								bAICount[GAME_PLAYER];
	BYTE								cbCardData[GAME_PLAYER][MAX_COUNT];	//用户扑克
};

//用户退出
struct CMD_S_PlayerExit
{
	WORD								wPlayerID;							//退出用户
};

//用户摊牌
struct CMD_S_Open_Card
{
	WORD								wPlayerID;							//摊牌用户
	BYTE								bOpen;								//摊牌标志
};

//提示剩余次数
struct CMD_S_TipResponse
{	
	WORD			wRemainTimes;					//剩余提示次数
	TCHAR			szDesc[64];						//操作结果
};

//////////////////////////////////////////////////////////////////////////
//客户端命令结构
enum SUB_C
{
	SUB_C_CALL_BANKER		=		1,									//用户叫庄
	SUB_C_ADD_SCORE			=		2,									//用户加注
	SUB_C_OPEN_CARD			=		3,									//用户摊牌
	SUB_C_SPECIAL_CLIENT_REPORT =   4,									//特殊终端
	SUB_C_AMDIN_COMMAND         =   5,									//系统控制
	SUB_C_PLAY_BONUS_GAME       =   6,									//开玩奖励积分游戏
    SUB_C_DISCARD_TIP_REQUEST   =   7,									//出牌提示    
};

enum eBONUS_GAME
{
	eGUESS_BIG = 1 ,                         //猜大小
};

//用户叫庄
struct CMD_C_CallBanker
{
	BYTE  bBanker;                           //做庄标志
};

//终端类型
struct CMD_C_SPECIAL_CLIENT_REPORT
{
	WORD  wUserChairID;                       //用户方位
};

//用户加注
struct CMD_C_AddScore
{
	LONGLONG lScore;                          //加注数目
};

//用户摊牌
struct CMD_C_OxCard
{
	BYTE bOX;                                 //牛牛标志
};

//请求提示
struct CMD_C_ShowTip
{
    DWORD dwGameID;                           //玩家ID
};

//////////////////////////////////////////////////////////////////////////
struct CMD_C_AdminReq
{
	BYTE cbReqType;
#define RQ_SET_WIN_AREA     1
#define RQ_RESET_CONTROL    2
#define RQ_PRINT_SYN        3
	BYTE cbExtendData[20];  //附加数据
};

//s->c 有奖励游戏
struct CMD_S_BONUS_GAME //SUB_S_BONUS_GAME
{
	int gametype;       //奖励game类型 1 猜大小
	int serialnum;      //本次序列号 依据
	int chip;           //注数
};

//c->s 要猜
struct CMD_C_PLAY_BONUS_GAME_REQ	//SUB_C_PLAY_BONUS_GAME
{
	int gametype;       //奖励game类型 1 猜大小
	int serialnum;      //本次序列号 依据
	int param;          //参数
};

//s->c 猜的结果
struct CMD_S_BONUS_GAME_Result	// SUB_S_BONUS_GAME_Result
{
	int gametype;       //奖励game类型 1 猜大小
	int serialnum;      //本次序列号 依据
	int ctime;          //连续赢的次数 0-6
	int ret;            //赚了多少？ 可能是负的.即输了
	WORD result[5];     //猜得结果 8个空位 宝箱状况
};

//请求回复
struct CMD_S_CommandResult
{
	BYTE cbAckType;				//回复类型
#define ACK_SET_WIN_AREA  1
#define ACK_PRINT_SYN     2
#define ACK_RESET_CONTROL 3
	BYTE cbResult;
#define CR_ACCEPT  2			//接受
#define CR_REFUSAL 3			//拒绝
	BYTE cbExtendData[20];		//附加数据
};

#define IDM_ADMIN_COMMDN WM_USER+1000

//控制区域信息
struct tagControlInfo
{
	INT  nAreaWin;		//控制区域
};

//服务器控制返回
#define	 S_CR_FAILURE				0		//失败
#define  S_CR_UPDATE_SUCCES			1		//更新成功
#define	 S_CR_SET_SUCCESS			2		//设置成功
#define  S_CR_CANCEL_SUCCESS		3		//取消成功

struct CMD_S_ControlReturns
{
	BYTE cbReturnsType;				//回复类型
	BYTE cbControlArea;				//控制区域
	BYTE cbControlTimes;			//控制次数
};


//客户端控制申请
#define  C_CA_UPDATE				1		//更新
#define	 C_CA_SET					2		//设置
#define  C_CA_CANCELS				3		//取消
struct CMD_C_ControlApplication
{
	BYTE cbControlAppType;			//申请类型
	BYTE cbControlArea;				//控制区域
	BYTE cbControlTimes;			//控制次数
};

#pragma pack(pop)

#endif
