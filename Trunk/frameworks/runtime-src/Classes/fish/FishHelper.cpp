#include "FishHelper.h"
#include "CCLuaEngine.h"
#include "SpriteDefine.h"
#include "Scene_Fish_Trace.h"

#ifdef WIN32
#else
#include "unistd.h"
#endif

void *ccThreadFishTraceLineLogic(void* param)
{
	//接收消息
	FishHelper* pGame = (FishHelper*)(param);
	pGame->retain();

	while (pGame->getThread())    //
	{
		if( (int)pGame->m_vTraceInfoBuff.size() )
		{
 			//拷贝数据
			pthread_mutex_lock(&pGame->m_pMutex_t);
			std::vector<TraceInfo> traceInfo;
			for (int i=0; i<(int)pGame->m_vTraceInfoBuff.size(); i++)
			{
				traceInfo.push_back(pGame->m_vTraceInfoBuff[i]);
			}
			pGame->m_vTraceInfoBuff.clear();
			pthread_mutex_unlock(&pGame->m_pMutex_t);

			// TraceList* traceList = TraceList::create();
			for (int i=0; i<(int)traceInfo.size(); i++)
			{
				Trace* trace = Trace::create();
				trace->retain();

				trace->fish_id = traceInfo[i].fish_id;
				trace->fish_kind = traceInfo[i].fish_kind;
				// std::vector<FPointAngle> vFPointAngle;
				if(traceInfo[i].trace_type == TRACE_LINEAR)
				{
					MathAide::BuildLinear(traceInfo[i].init_x_pos,
                                          traceInfo[i].init_y_pos,
                                          traceInfo[i].init_count,
										  trace->m_vFPointAngle,
                                          traceInfo[i].speed);
				} else
                {
                   MathAide::BuildBezier(traceInfo[i].init_x_pos,
                                            traceInfo[i].init_y_pos,
                                            traceInfo[i].init_count,
											trace->m_vFPointAngle,
                                            traceInfo[i].speed);
                }

				// trace->m_vFPointAngle = vFPointAngle;
				// traceList->m_vTrace.push_back(trace);

				Director::getInstance()->getScheduler()->performFunctionInCocosThread([&, pGame,trace]{
					// if (pGame->_delegate)
					// 	pGame->_delegate->onBuildTrace(trace);
				});
			}
			traceInfo.clear();
		}
		//休眠时间

#ifdef WIN32
		Sleep(1.0f);
#else
        usleep(20.0f);
#endif	// _DEBUG
	}

	pGame->release();

	return 0;
}

void FishHelper::pushBackTraceInfo(TraceInfoBuff *buff)
{
	pthread_mutex_lock(&m_pMutex_t);
	for (int i=0; i<(int)buff->m_vTraceInfo.size(); i++)
	{
		m_vTraceInfoBuff.push_back(buff->m_vTraceInfo[i]);
	}
	buff->release();
	pthread_mutex_unlock(&m_pMutex_t);
}

void FishHelper::runThread()
{
	//创建互斥锁
	m_bThread = true;
	pthread_t ptThread;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	pthread_mutex_init(&m_pMutex_t, NULL);

	int code = pthread_create(&ptThread, 0, ccThreadFishTraceLineLogic, this);
	if(code!=0)
	{
		cocos2d::log("CGameClient: createThread Failure");
	}

	pthread_detach(ptThread);
	pthread_attr_destroy(&attr);
}

// void FishHelper::loadTraceFile(int i)
// {
// 	YYDefineChar(szFile, 128, "res/trace/zuhe%d.yq", i);
// 	Data data = FileUtils::getInstance()->getDataFromFile(szFile);
//
// 	CNotify* notify = YYLayerNotify(&data);
// 	notify->setMainType(0);
//
// 	Director::getInstance()->getScheduler()->performFunctionInCocosThread([&, this,notify]{
// 			this->_delegate->onLoadTrace(notify);
// 	});
// }

void FishHelper::loadTrace(string fishname, int fishKind, int traceCount)
{
	for (int i = 1; i <= traceCount; i++)
	{
		stringstream ss;
	    string str;
	    ss<<"res/trace/";
	    ss<<fishname;
		ss<<"/";
	    ss<<i;
	    ss<<".yq";
	    ss>>str;

		Data data = FileUtils::getInstance()->getDataFromFile(str.c_str());
		FileTrack ft;
		memset(&ft, 0, sizeof(ft));
		memcpy(&ft, data.getBytes(), data.getSize());

		//获得路线
		// m_vFishTrace[i].clear();
		TraceVector vFPointAngle;
		vFPointAngle.clear();
		std::copy(ft.pos, ft.pos+ft.count, std::back_inserter(vFPointAngle));

		//返回路线到lua
		Trace* trace = Trace::create();
	    trace->retain();
		trace->trace_id = i;
		trace->fish_kind = fishKind;
	    trace->m_vFPointAngle.clear();
		trace->m_vFPointAngle = vFPointAngle;
	    if (_delegate)
	        _delegate->onLoadTrace(trace);
	}
}

void *ccThreadBuildTrace(void* param)
{
	//接收消息
	FishHelper* pGame = (FishHelper*)(param);
	pGame->retain();

	float designWidth = 1280;
	float designHeight = 720;
	BuildSceneKind1Trace(designWidth, designHeight);
    BuildSceneKind2Trace(designWidth, designHeight);
    BuildSceneKind3Trace(designWidth, designHeight);
    BuildSceneKind4Trace(designWidth, designHeight);
    BuildSceneKind5Trace(designWidth, designHeight);

	Trace* trace = Trace::create();
	Director::getInstance()->getScheduler()->performFunctionInCocosThread([&, pGame, trace]{
		pGame->onBuildGroupTrace();
	});

	pGame->release();
	return 0;
}

void FishHelper::onBuildGroupTrace()
{
	// for (int i=0; i<210; i++){
	// 	Trace* trace = Trace::create();
	//     trace->retain();
	// 	trace->trace_id = i;
	// 	trace->fish_kind = 101;
	//     trace->m_vFPointAngle.clear();
	// 	trace->m_vFPointAngle = scene_kind_1_trace_[i];
	//     if (_delegate)
	//         _delegate->onLoadTrace(trace);
	// }
	//
	// for (int i=0; i<214; i++){
	// 	Trace* trace = Trace::create();
	//     trace->retain();
	// 	trace->trace_id = i;
	// 	trace->fish_kind = 102;
	//     trace->m_vFPointAngle.clear();
	// 	trace->m_vFPointAngle = scene_kind_2_trace_[i];
	//     if (_delegate)
	//         _delegate->onLoadTrace(trace);
	// }
	//
	// for (int i=0; i<242; i++){
	// 	Trace* trace = Trace::create();
	//     trace->retain();
	// 	trace->trace_id = i;
	// 	trace->fish_kind = 103;
	//     trace->m_vFPointAngle.clear();
	// 	trace->m_vFPointAngle = scene_kind_3_trace_[i];
	//     if (_delegate)
	//         _delegate->onLoadTrace(trace);
	// }

	for (int i=0; i<64; i++){
		Trace* trace = Trace::create();
	    trace->retain();
		trace->trace_id = i;
		trace->fish_kind = 104;
	    trace->m_vFPointAngle.clear();
		trace->m_vFPointAngle = scene_kind_4_trace_[i];
	    if (_delegate)
	        _delegate->onLoadTrace(trace);
	}

	// for (int i=0; i<236; i++){
	// 	Trace* trace = Trace::create();
	//     trace->retain();
	// 	trace->trace_id = i;
	// 	trace->fish_kind = 105;
	//     trace->m_vFPointAngle.clear();
	// 	trace->m_vFPointAngle = scene_kind_5_trace_[i];
	//     if (_delegate)
	//         _delegate->onLoadTrace(trace);
	// }
	_delegate2->onBuildTrace();
}

//fish_kind 101-105 表示为鱼潮的路线
void FishHelper::loadGroupTrace(int winWidth,int winHeight)
{
	kResolutionWidth = winWidth;
	kResolutionHeight = winHeight;

	//创建互斥锁
	pthread_t ptThread;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	pthread_mutex_init(&m_pMutex_t, NULL);

	int code = pthread_create(&ptThread, 0, ccThreadBuildTrace, this);
	if(code!=0)
	{
		cocos2d::log("CGameClient: createThread Failure");
	}

	pthread_detach(ptThread);
	pthread_attr_destroy(&attr);
}

// void FishHelper::loadTrace(int traceCount)
// {
// 	m_iTrace_count = traceCount;
// 	for (int i = 0; i < traceCount; i++)
// 	{
// 		YYDefineChar(szFile, 128, "res/trace/zuhe%d.yq", i);
// 		Data data = FileUtils::getInstance()->getDataFromFile(szFile);
// 		FileTrack ft;
// 		memset(&ft, 0, sizeof(ft));
// 		memcpy(&ft, data.getBytes(), data.getSize());
//
// 		//获得路线
// 		m_vFishTrace[i].clear();
// 		std::copy(ft.pos, ft.pos+ft.count, std::back_inserter(m_vFishTrace[i]));
// 	}
// }

// void FishHelper::getAllTrace()
// {
// 	for (int i = 0; i < m_iTrace_count; i++)
// 	{
// 		Trace* trace = Trace::create();
// 	    trace->retain();
//
// 		trace->trace_id = i;
// 	    // trace->fish_id = fishId;
// 	    // trace->fish_kind = fishKind;
// 	    trace->m_vFPointAngle.clear();
//
// 		trace->m_vFPointAngle = m_vFishTrace[i];
//
// 	    if (_delegate)
// 	        _delegate->onLoadTrace(trace);
// 	}
// }

// void FishHelper::getTrace(int traceId,int fishId, int fishKind)
// {
//     Trace* trace = Trace::create();
//     trace->retain();
//
//     trace->fish_id = fishId;
//     trace->fish_kind = fishKind;
//     trace->m_vFPointAngle.clear();
// 	// std::copy( m_vFishTrace[traceId].begin(),m_vFishTrace[traceId].end(),std::back_inserter(trace->m_vFPointAngle));
//
// 	// for (int i=0; i<(int)m_vFishTrace[traceId].size(); i++)
// 	// {
// 	// 	trace->m_vFPointAngle.push_back(m_vFishTrace[traceId][i]);
// 	// }
//
// 	trace->m_vFPointAngle = m_vFishTrace[traceId];
//
//     if (_delegate)
//         _delegate->onBuildTrace(trace);
// }

void FishHelperDelegate2::onBuildTrace()
{
    LuaEngine* engine = LuaEngine::getInstance();
	Trace* trace = Trace::create();
    BasicScriptData scriptdata(this, trace);
    cocos2d::ScriptEvent eve(kCallFuncEvent, &scriptdata);
    engine->sendEvent(&eve);
}

void FishHelperDelegate::onLoadTrace(Trace* trace)
{
	LuaEngine* engine = LuaEngine::getInstance();
	BasicScriptData scriptdata(this,trace);
	cocos2d::ScriptEvent eve(kCallFuncEvent, &scriptdata);
	engine->sendEvent(&eve);
}
