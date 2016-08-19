#ifndef __CMD_PACKET_REF__
#define __CMD_PACKET_REF__

#include "cocos2d.h"
USING_NS_CC;
#include "Define.h"
#include "SpriteDefine.h"
#include "CMD_Base.h"
#include "Packet.h"
#include "JT_Macro.h"

JT_CLASS_CMD(TCP_Buffer)
	TCP_BufferRef()
{
	memset(&this->cmd,0,sizeof(this->cmd));
}

	void setMainCmdID(WORD value)
	{
		this->cmd.Head.CommandInfo.wMainCmdID = value;
	}

	void setSubCmdID(WORD value)
	{
		this->cmd.Head.CommandInfo.wSubCmdID = value;
	};
};

#endif //__CMD_PACKET_REF__