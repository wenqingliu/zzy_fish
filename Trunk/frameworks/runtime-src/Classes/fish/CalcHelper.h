#ifndef __CALC_HELPER
#define __CALC_HELPER
#include "cocos2d.h"
#include "protocol.h"
#include "JT_Macro.h"
#include <pthread.h>
#include "common_fish.h"

USING_NS_CC;
using namespace std;

class PosAngle : public Ref
{
public:
    JT_CREATE_FUNC(PosAngle);
public:
    float m_x;
    float m_y;
    float m_angle;
public:
    float getX(){ return m_x; }
    float getY(){ return m_y; }
    float getAngle(){ return m_angle; }
};


class CalcHelperDelegate : public Ref
{

public:
	JT_CREATE_FUNC(CalcHelperDelegate);
	void onCalcBulletPos(PosAngle* pos);
};

class CalcHelper : public Ref
{
public:
	JT_CREATE_FUNC(CalcHelper);
	CalcHelper(){};
	~CalcHelper(){};
    void nextBulletPos(float lastX,float lastY,float lastDir,float dt,int speed);
    void setDelegate(CalcHelperDelegate *delegate) { _delegate = delegate; }
    void setWinSize(int width,int height) { m_winWidth = width; m_winHeight = height; }
    CalcHelperDelegate* getDelegate() const { return _delegate ;}
// protected:

// private:
    CalcHelperDelegate *_delegate;
    int m_winWidth;
    int m_winHeight;
};


#endif
