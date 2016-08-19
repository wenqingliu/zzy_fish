#ifndef KPQZ_GAME_LOGIC_HEAD_FILE
#define KPQZ_GAME_LOGIC_HEAD_FILE

#pragma once

#include "Define.h"
#include "SpriteDefine.h"

//////////////////////////////////////////////////////////////////////////

//数值掩码
#define	LOGIC_MASK_COLOR			0xF0								//花色掩码
#define	LOGIC_MASK_VALUE			0x0F								//数值掩码

#define	MAX_COUNT					5

//扑克类型
#define OX_VALUE0					0									//混合牌型
#define OX_THREE_SAME				102									//三条牌型
#define OX_FOUR_SAME				103									//四条牌型
#define OX_FOURKING					104									//天王牌型
#define OX_FIVEKING					105									//天王牌型
#define OX_FIVEXNIU					106									//五小牛牌型

//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////

//游戏逻辑类
class KPQZGameLogic
{
	//变量定义
private:
	static BYTE						m_cbCardListData[52];				//扑克定义

	//函数定义
public:
	//构造函数
	KPQZGameLogic();
	//析构函数
	virtual ~KPQZGameLogic();

	//类型函数
public:
	//获取类型
	BYTE GetCardType(BYTE cbCardData[], BYTE cbCardCount);
	//获取数值
	BYTE GetCardValue(BYTE cbCardData) { return cbCardData&LOGIC_MASK_VALUE; }
	//获取花色
	BYTE GetCardColor(BYTE cbCardData) { return cbCardData&LOGIC_MASK_COLOR; }
	//获取倍数
	BYTE GetTimes(BYTE cbCardData[], BYTE cbCardCount);
	
	BYTE GetTimes(BYTE cardType);
	//---

	BYTE GetTimes_5(BYTE cbCardData[], BYTE cbCardCount);

	//获取牛牛
	bool GetOxCard(BYTE cbCardData[], BYTE cbCardCount);
	//获取整数
	bool IsIntValue(BYTE cbCardData[], BYTE cbCardCount);

	//控制函数
public:
	//排列扑克
	void SortCardList(BYTE cbCardData[], BYTE cbCardCount);
	//混乱扑克
	void RandCardList(BYTE cbCardBuffer[], BYTE cbBufferCount);

	//功能函数
public:
	//逻辑数值
	BYTE GetCardLogicValue(BYTE cbCardData);
	//对比扑克
	bool CompareCard(BYTE cbFirstData[], BYTE cbNextData[], BYTE cbCardCount,int FirstOX,int NextOX);
};

//////////////////////////////////////////////////////////////////////////

#endif
