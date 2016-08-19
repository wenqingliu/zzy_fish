#ifndef __FISH_HLPER__
#define __FISH_HLPER__
#include "cocos2d.h"
// #include "SpriteData.h"
#include "math_aide.h"
#include "protocol.h"
#include "JT_Macro.h"
#include <pthread.h>
#include "common_fish.h"

USING_NS_CC;
using namespace std;

class FishHelperDelegate : public Ref
{

public:
	JT_CREATE_FUNC(FishHelperDelegate);
	void onBuildTrace(Trace* trace);
	void onLoadTrace(Trace* trace);
};

class FishHelper : public Ref
{
public:
	JT_CREATE_FUNC(FishHelper);
	FishHelper(){};
	~FishHelper(){};

	void runThread();
	void pushBackTraceInfo(TraceInfoBuff *buff);
	// void loadTraceFile(int i);
	void loadTrace(string fishname, int fishKind, int traceCount);
	// void getTrace(int traceId,int fishId, int fishKind);
	// void getAllTrace();

    void setThreadFlag(bool flag) { m_bThread = flag; }
    bool getThread() { return m_bThread; }

    void setDelegate(FishHelperDelegate *delegate) { _delegate = delegate; }
    FishHelperDelegate* getDelegate() const { return _delegate ;}
// protected:

// private:
	pthread_mutex_t	m_pMutex_t;
	bool m_bThread;
	// TraceInfoBuff *m_traceInfoBuff = TraceInfoBuff::create();
	std::vector<TraceInfo> m_vTraceInfoBuff;
    FishHelperDelegate *_delegate;

	// std::vector<FPointAngle> m_vFishTrace[30];
	// TraceList m_TraceList;
	int m_iTrace_count;
};


#endif
