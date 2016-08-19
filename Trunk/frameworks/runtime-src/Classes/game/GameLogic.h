#ifndef GAME_LOGIC_HEAD_FILE
#define GAME_LOGIC_HEAD_FILE

#pragma once

#include "Define.h"
#include "SpriteDefine.h"

//////////////////////////////////////////////////////////////////////////
//赔率
//enum emCardType
//{
//	CT_ERROR			=	0,								//错误类型
//	CT_POINT			=	1,								//点数类型
//	CT_SPECIAL_NIU1		=	1,								//牛一
//	CT_SPECIAL_NIU2		=	2,								//牛二
//	CT_SPECIAL_NIU3		=	3,								//牛三
//	CT_SPECIAL_NIU4		=	4,								//牛四
//	CT_SPECIAL_NIU5		=	5,								//牛五
//	CT_SPECIAL_NIU6		=	6,								//牛六
//	CT_SPECIAL_NIU7		=	7,								//牛七
//	CT_SPECIAL_NIU8		=	8,								//牛八
//	CT_SPECIAL_NIU9		=	9,								//牛九
//	CT_SPECIAL_NIUNIUXW	=	10,								//小王牛
//	CT_SPECIAL_NIUNIUDW	=	10,								//大王牛
//	CT_SPECIAL_NIUNIU	=	10,								//牛牛
//	CT_SPECIAL_NIUYING	=	10,								//银牛
//	CT_SPECIAL_NIUKING	=	10,								//金牛
//	CT_SPECIAL_BOMEBOME	=	10								//炸弹
//};
enum emCardType
{
	CT_ERROR			=	0,								//错误类型
	CT_POINT			=	1,								//无牛
	CT_SPECIAL_NIU1		=	2,								//牛一
	CT_SPECIAL_NIU2		=	3,								//牛二
	CT_SPECIAL_NIU3		=	4,								//牛三
	CT_SPECIAL_NIU4		=	5,								//牛四
	CT_SPECIAL_NIU5		=	6,								//牛五
	CT_SPECIAL_NIU6		=	7,								//牛六
	CT_SPECIAL_NIU7		=	8,								//牛七
	CT_SPECIAL_NIU8		=	9,								//牛八
	CT_SPECIAL_NIU9		=	10,								//牛九	
	CT_SPECIAL_NIUNIU	=	11,								//牛牛	
	CT_SPECIAL_BOMEBOME	=	12,								//炸弹
	CT_SPECIAL_NIUYING	=	13,								//银牛(五花牛)
	CT_SPECIAL_NIUKING	=	14,								//金牛(五花牛)	
	CT_SPECIAL_SMALL	=	15								//五小妞
};
		
//数值掩码
#define	LOGIC_MASK_COLOR			0xF0						//花色掩码
#define	LOGIC_MASK_VALUE			0x0F						//数值掩码

//排序类型
#define	ST_VALUE					1							//数值排序
#define	ST_NEW					    3							//数值排序
#define	ST_LOGIC					2							//逻辑排序

//扑克数目
#define CARD_COUNT					52							//扑克数目
#define USER_CARD_NUM               5                            //牌数

//游戏逻辑
class CGameLogic
{
	//变量定义
public:
	static const BYTE				m_cbCardListData[CARD_COUNT];		//扑克定义

	//函数定义
public:
	//构造函数
	CGameLogic();
	//析构函数
	virtual ~CGameLogic();

	//类型函数
public:
	//获取数值
	static BYTE GetCardValue(BYTE cbCardData) 
	{ 
		return cbCardData&LOGIC_MASK_VALUE; 
	}
	//获取花色
	static BYTE GetCardColor(BYTE cbCardData)
	{
		return (cbCardData&LOGIC_MASK_COLOR)>>4;
	}

	//控制函数
public:
	//混乱扑克
	static void RandCardList(BYTE cbCardBuffer[], BYTE cbBufferCount);
	//混乱扑克
	static void RandCardListEx(BYTE cbCardBuffer[], BYTE cbBufferCount);
	//排列扑克
	static void SortCardList(BYTE cbCardData[], BYTE cbCardCount, BYTE cbSortType);

	static int RetType(int itype);

	//逻辑函数
public:
	//获取牌点
	static BYTE GetCardListPip(const BYTE cbCardData[], BYTE cbCardCount);
	//获取牌型
	static BYTE GetCardType(const BYTE cbCardData[], BYTE cbCardCount,BYTE *bcOutCadData = NULL);
	//大小比较
	static int CompareCard(const BYTE cbFirstCardData[], BYTE cbFirstCardCount,const BYTE cbNextCardData[], BYTE cbNextCardCount,BYTE &Multiple);
	//逻辑大小
	static BYTE GetCardLogicValue(BYTE cbCardData);

	static BYTE GetCardNewValue(BYTE cbCardData);

	//检查大小王
	static BYTE CheckKingCard(const BYTE cbCardData[], BYTE cbCardCount);
};

//////////////////////////////////////////////////////////////////////////

#endif
