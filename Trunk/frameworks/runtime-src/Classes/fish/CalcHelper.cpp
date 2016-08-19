#include "CalcHelper.h"
#include "CCLuaEngine.h"

void CalcHelper::nextBulletPos(float lastX,float lastY,float lastDir,float dt,int speed)
{
    float angle = (90-lastDir)/180*3.14159265358979323846f;
    float s = sinf(angle);
    float c = cosf(angle);
    float dtx = speed*c*dt*100;
    float dty = speed*s*dt*100;
    float curX = lastX + dtx;
    float curY = lastY + dty;

    PosAngle* pos = PosAngle::create();
    pos->m_x = curX;
    pos->m_y = curY;
    pos->m_angle = lastDir;

    if (curX > m_winWidth - 10){
        pos->m_angle = -lastDir;
        pos->m_x = m_winWidth - 11;
        pos->m_y = curY;
    }else if (curX < 10){
        pos->m_angle = -lastDir;
        pos->m_x = 11;
        pos->m_y = curY;
    }else if (curY >  m_winHeight - 10){
        pos->m_angle = 180 - lastDir;
        pos->m_x = curX;
        pos->m_y = m_winHeight - 11;
    }else if (curY < 10){
        pos->m_angle = 180 - lastDir;
        pos->m_x = curX;
        pos->m_y = 11;
    }

    if (_delegate)
        _delegate->onCalcBulletPos(pos);
}

void CalcHelperDelegate::onCalcBulletPos(PosAngle* pos)
{
	LuaEngine* engine = LuaEngine::getInstance();
	BasicScriptData scriptdata(this,pos);
	cocos2d::ScriptEvent eve(kCallFuncEvent, &scriptdata);
	engine->sendEvent(&eve);
}
