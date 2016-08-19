#ifndef __HUNNEW_GAME_LOGIC_REF__
#define __HUNNEW_GAME_LOGIC_REF__

#include "GameLogic.h"
#include "CMD_OxBattle.h"
#include "cocos2d.h"
USING_NS_CC;

class GameLogicHunNewRef : public Ref
{

	GameLogicHunNewRef()
		:_Multiple(1)
	{
		for (int i = 0; i < AREA_CARD_COUNT; i++)
		{
			_cbFirstCardData[i] = 0;
			_cbNextCardData[i] = 0;
		}
	}

protected:
	BYTE _cbFirstCardData[AREA_CARD_COUNT];
	BYTE _cbNextCardData[AREA_CARD_COUNT];
	BYTE _Multiple;

public:
	bool init(){return true;}
	CREATE_FUNC(GameLogicHunNewRef);

	void setFirstCardData(int index,BYTE value){_cbFirstCardData[index] = value;};
	BYTE getFirstCardData(int index){return _cbFirstCardData[index];};

	void setNextCardData(int index,BYTE value){_cbNextCardData[index] = value;};
	BYTE getNextCardData(int index){return _cbNextCardData[index];};

	BYTE getMultiple(){
		return _Multiple;
	}

	//获取牌型
	BYTE GetCardType()
	{
		return CGameLogic::GetCardType(_cbFirstCardData,AREA_CARD_COUNT,_cbNextCardData);
		//return 0;
	};

	//大小比较
	int CompareCard()
	{
		return CGameLogic::CompareCard(_cbFirstCardData,AREA_CARD_COUNT,_cbNextCardData,AREA_CARD_COUNT,_Multiple);
		//return 0;
	};

};

#endif //__HUNNEW_GAME_LOGIC_REF__