#ifndef __KPQZ_GAME_LOGIC_REF__
#define __KPQZ_GAME_LOGIC_REF__

#include "KPQZGameLogic.h"
#include "cocos2d.h"
USING_NS_CC;

class KPQZGameLogicRef : public Ref
{

	KPQZGameLogicRef()
		:_Multiple(1),
		logic(nullptr)
	{
		for (int i = 0; i < MAX_COUNT; i++)
		{
			_cbFirstCardData[i] = 0;
			_cbNextCardData[i] = 0;
		}
	}

protected:
	BYTE _cbFirstCardData[MAX_COUNT];
	BYTE _cbNextCardData[MAX_COUNT];
	BYTE _Multiple;

	KPQZGameLogic* logic;


public:
	bool init(){
		if(!logic){
			logic = new KPQZGameLogic();
		}
		return true;
	}
	CREATE_FUNC(KPQZGameLogicRef);

	~KPQZGameLogicRef(){
		CC_SAFE_DELETE(logic);
	}

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
		auto cardType = logic->GetCardType(_cbFirstCardData,MAX_COUNT);
		this->_Multiple = logic->GetTimes(cardType);
		return cardType;
	};

	//大小比较
	int CompareCard()
	{
		return logic->CompareCard(_cbFirstCardData,_cbNextCardData,MAX_COUNT,false,false);
		//return 0;
	};

	//
	bool GetOxCard()
	{
		return logic->GetOxCard(_cbFirstCardData,MAX_COUNT);
	}
};

#endif //__HUNNEW_GAME_LOGIC_REF__