#ifndef __MD_OXFIVE_BATTLEREF__
#define __MD_OXFIVE_BATTLEREF__

#include "CMD_OxFiveBattle.h"

#include "Define.h"
#include "SpriteDefine.h"
#include "CMD_Base.h"
#include "JT_Macro.h"

//发牌数据包
JT_CLASS_CMD(CMD_S_SendCard)
	JT_GET_ARR2(BYTE,cbCardData);
	JT_SET_ARR2(BYTE,cbCardData);
};

#endif