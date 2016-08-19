#ifndef __CMD_BASE__
#define __CMD_BASE__
#include "cocos2d.h"
#include "SpriteData.h"
USING_NS_CC;
class CMD_BASE : public Ref
{
public:
	virtual void* getData()const =0;
	virtual int getSize()const =0;
	virtual void setStruct(CNotify* notify)=0;

protected:
	CMD_BASE(){};
	virtual ~CMD_BASE(){};

private:

};


#endif