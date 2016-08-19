#ifndef __COMMON_FISH__
#define __COMMON_FISH__

#include "cocos2d.h"
#include "JT_Macro.h"

USING_NS_CC;
using namespace std;

#define M_PI    3.14159265358979323846f
#define M_PI_2  1.57079632679489661923f

enum TraceType
{
    TRACE_LINEAR = 0,	//直线
    TRACE_BEZIER,		//贝塞尔曲线
    TRACE_S,			//S路线
	TRACE_COMBINATION,	//组合路线
	TRACE_SMALL_BOSS,	//boss路线
	TRACE_TOTAL
};


struct FPoint {
    float x;
    float y;
};

struct FPointAngle
{
    float x;
    float y;
    float angle;
};

// typedef std::vector<FPointAngle> TraceVector;

struct FileTrack
{
	int count;
	FPointAngle pos[3000];
};

struct TraceInfo
{
	float	init_x_pos[5];
	float	init_y_pos[5];
	int		init_count;
	int		speed;
	int		trace_type;
    int     fish_id;
    int     fish_kind;
};

class Trace : public Ref
{
public:
    JT_CREATE_FUNC(Trace);
public:
    std::vector<FPointAngle> m_vFPointAngle;
    int fish_id;
    int fish_kind;
    int trace_id;
public:
    int getTraceId(){return trace_id;}
    int getCount(){ return m_vFPointAngle.size(); }
    int getFishId(){ return fish_id; }
    int getFishKind(){ return fish_kind; }
    float getX(int idx){ return m_vFPointAngle[idx].x; }
    float getY(int idx){ return m_vFPointAngle[idx].y; }
    float getAngle(int idx){ return m_vFPointAngle[idx].angle; }
};

// class TraceList : public Ref
// {
// public:
// 	JT_CREATE_FUNC(TraceList);
//     std::vector<Trace*> m_vTrace;
// };

class TraceInfoBuff : public Ref
{
public:
	JT_CREATE_FUNC(TraceInfoBuff);
    std::vector<TraceInfo> m_vTraceInfo;

    void pushBackTraceInfo(){ TraceInfo traceInfo; m_vTraceInfo.push_back(traceInfo); };
    void setPosX(int xi, int x){ m_vTraceInfo.back().init_x_pos[xi] = x; };
    void setPosY(int yi,int y){ m_vTraceInfo.back().init_y_pos[yi] = y; };
    void setInitCount(int count){  m_vTraceInfo.back().init_count = count; };
    void setSpeed(int speed){  m_vTraceInfo.back().speed = speed; };
    void setTraceType(int type){  m_vTraceInfo.back().trace_type = type; };
    void setFishId(int id){  m_vTraceInfo.back().fish_id = id; };
    void setFishKind(int kind){  m_vTraceInfo.back().fish_kind = kind; };
};

class LuaTest : public Ref
{
public:
	JT_CREATE_FUNC(LuaTest);
public:
    int m_I;
    int getI(){ return m_I; }
};


#endif
