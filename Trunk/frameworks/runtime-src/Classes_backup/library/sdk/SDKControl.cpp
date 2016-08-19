#include "SDKControl.h"
#include "CCLuaEngine.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    #include "Cocos2dx/Common/CCUMSocialSDK.h"
    #include "platform/android/jni/JniHelper.h"
    #include <android/log.h>
    USING_NS_UM_SOCIAL;
#endif

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
    #include "NDKHelper.h"
#endif

#include "FrameData.h"

#define _QQAccount 1
#define _QQAccount_OFFLINE -1

SDKControl::SDKControl(void):
	m_version(""),
	m_versionCode(0)
{
}


SDKControl::~SDKControl(void)
{
}

SDKControl* SDKControl::_instance = nullptr;
SDKControl* SDKControl::getInstance()
{
	if(_instance == nullptr)
	{
		_instance = new SDKControl();
		_instance->retain();
	}
	return _instance;
}


void SDKControl::sendMessage(const char* nativeMethod)
{
	log("SDKControl::sendMessage:%s ",nativeMethod); 
	#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
		ValueMap valueMap;
		Value parameters = Value(valueMap);
        sendMessageWithParams(nativeMethod, "{}");
	#endif
}


void SDKControl::sendMessage(const char* nativeMethod,const char* jsonStr)
{
    #if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
        sendMessageWithParams(nativeMethod,jsonStr);
    #endif
}


void SDKControl::sendMessage(const char* nativeMethod,ValueMapRef* ref)
{
	auto map = ref->valueMap;
	Value parameters = Value(map);
	#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
		sendMessageWithParams(nativeMethod, "{}");
	#endif

}

void SDKControl::addSelector(const char *name)
{
	log("SDKControl::addSelector:%s ",name);
	#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
		NDKHelper::addSelector(name,
                           name,
                           CC_CALLBACK_2(SDKControl::handleMessage, this),
                           this);
	#endif
}

void SDKControl::removeSelectors(const char *name)
{
	#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
		NDKHelper::removeSelectorsInGroup(name);
	#endif
}

void SDKControl::handleMessage(Node *sender, Value data)
{
    auto notify = CNotify::create();
    if (!data.isNull() && data.getType() == Value::Type::STRING) {
        notify->m_MainString = data.asString();
    }
    LuaEngine* engine = LuaEngine::getInstance();
    BasicScriptData scriptdata(SDKControl::getInstance(), notify);
    cocos2d::ScriptEvent eve(kCallFuncEvent, &scriptdata);
    engine->sendEvent(&eve);
}

std::string SDKControl::getStringFromPlatform(const unsigned int notifyCode, const char *notifyName)
{
    std::string result;
    #if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo info;
        bool ret = JniHelper::getStaticMethodInfo(info,"YYProjectJni/JniHelper", notifyName,"()Ljava/lang/String;");
        if (ret) {
            jstring jstr = (jstring)info.env->CallStaticIntMethod(info.classID, info.methodID);
            result = JniHelper::jstring2string(jstr);
			info.env->DeleteLocalRef(jstr);
        }
    #endif
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        CNotify *pNotify = CreateNotify(0);
        pNotify->setMainType(notifyCode);
        GetNotificationCenter()->postNotification(ccNd_PlatFormNotify, pNotify);
        result = pNotify->getMainString();
    #endif
    log("call method succeed - getStringFromPlatform:%s", result.c_str());
    return result;
}

int SDKControl::getValueFromPlatform(const unsigned int notifyCode, const char *notifyName)
{
    int result = -1;
    #if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo info;
        bool ret = JniHelper::getStaticMethodInfo(info,"YYProjectJni/JniHelper", notifyName,"()I");
        if (ret) {
            jint i = info.env->CallStaticIntMethod(info.classID, info.methodID);
            result = i;
        }
    #endif
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        CNotify *pNotify = CreateNotify(0);
        pNotify->setMainType(notifyCode);
        GetNotificationCenter()->postNotification(ccNd_PlatFormNotify, pNotify);
        result = pNotify->getMainType();
    #endif
    log("call method succeed - getValueFromPlatform:%d",result);
    return result;
}

int SDKControl::getVersionCode() {
	if(m_versionCode == 0)
	{
		#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
			JniMethodInfo info;
			bool ret = JniHelper::getStaticMethodInfo(info,"YYProjectJni/JniHelper","getAppVersionCode","()I");
			if (ret)
			{
				jint i = info.env->CallStaticIntMethod(info.classID, info.methodID);
				m_versionCode = i;
				log("call method succeed-getVersionCode:%d",i);
				return m_versionCode;
			}
		#endif

		#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
			CNotify *pNotify = CreateNotify(0);
			pNotify->setMainType(3);
			GetNotificationCenter()->postNotification(ccNd_PlatFormNotify, pNotify);
			m_versionCode = pNotify->getMainType();
			return m_versionCode;
		#endif
	}
	return m_versionCode;
}

int SDKControl::getSDKPlatform()
{
	log("SDKControl::getSDKPlatform()");
	#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		JniMethodInfo info;
		bool ret = JniHelper::getStaticMethodInfo(info,"YYProjectJni/JniHelper","getSDKPlatform","()I");
		if (ret)
		{
			jint i = info.env->CallStaticIntMethod(info.classID, info.methodID);
			log("call method succeed%d",i);
			return i;
		}
	#endif

	return 0;
}

int SDKControl::getWifiState()
{
	log("SDKControl::getWifiState()");
	#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		JniMethodInfo info;
		bool ret = JniHelper::getStaticMethodInfo(info,"YYProjectJni/JniHelper","getWifiState","()I");
		if (ret)
		{
			jint i = info.env->CallStaticIntMethod(info.classID, info.methodID);
			log("call method succeed%d",i);
			return i;
		}
	#endif

	#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		return 3;
	#endif

	#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        CNotify *pNotify = CreateNotify(0);
        pNotify->setMainType(2);
        GetNotificationCenter()->postNotification(ccNd_PlatFormNotify, pNotify);
        WORD status = pNotify->getMainType();
        if (status == 2) return 3;
        if (status == 1) return 1;
	#endif
	return 4;
}

bool SDKControl::isCocosDebug()
{
	#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		JniMethodInfo info;
		bool ret = JniHelper::getStaticMethodInfo(info,"YYProjectJni/JniHelper","getCocosDebug","()I");
		if (ret)
		{
			jint i = info.env->CallStaticIntMethod(info.classID, info.methodID);
			log("call method succeed%d",i);
			return i;
		}
    #elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        #ifdef DEBUG
            return true;
        #endif
    #elif(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
        return COCOS2D_DEBUG > 0;
    #else
        return false;
    #endif
    return false;
}

bool SDKControl::isAppDebug()
{
	#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		JniMethodInfo info;
		bool ret = JniHelper::getStaticMethodInfo(info,"YYProjectJni/JniHelper","getAppDebug","()I");
		if (ret)
		{
			jint i = info.env->CallStaticIntMethod(info.classID, info.methodID);
			log("call method succeed%d",i);
			return i;
		}
	#elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        #ifdef DEBUG
            return true;
        #endif
	#elif(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		return COCOS2D_DEBUG > 0;
    #else
        return false;
	#endif

	return false;
}

void SDKControl::printInfo(const char* tag,const char* msg){
	log("SDKControl::printInfo:%s,%s",tag,msg);
};

void SDKControl::printError(const char* msg){
	log("SDKControl::printError:%s",msg);
};

void shareCallback(int platform, int stCode,string errorMsg)
{
	Director::getInstance()->getScheduler()->performFunctionInCocosThread([&,platform,stCode,errorMsg]{
		log("shareCallback   code:%d  ",stCode);
		string str = StringUtils::format("{\"methodToCall\":\"share\",\"platform\":%d,\"stCode\":%d,\"errorMsg\":\"%s\"}",platform,stCode,errorMsg.c_str());
		SDKControl::getInstance()->handleMessage(SDKControl::getInstance(),Value(str.c_str()));
	});
	
}

void authCallback(int platform, int stCode,const map<string, string>& data)
{
	if (stCode == 200)
	{
		log("authCallback-----------%d",platform);
	}
}
void SDKControl::initUmengShareSDK(const std::string ShareWord,
                                   const std::string sharePng,
                                   const std::string shareURL,
                                   const std::string title)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    // 设置key
    CCUMSocialSDK *sdk = CCUMSocialSDK::create("561e0023e0f55a8eea000980");
    
    //IOS版与安卓线下包
    sdk->setQQAppIdAndAppKey("1104540804", "7IcL3m2HVP94R5qD");
    sdk->setWeiXinAppInfo("wx528513398d6a8277","20a8589bb7d92c8cec15c13ff1e358a2");
    
    // 设置icon地址
    sdk->setTargetUrl(shareURL.c_str());
    
    // 加入社交平台
    vector<int>* platforms = new vector<int>();
    if(getSDKPlatform()==_QQAccount){//应用宝渠道,线上包
		sdk->setQQAppIdAndAppKey("1105125571", "WPccATx7WTCM2Je7");
		sdk->setWeiXinAppInfo("wx75c8a9e911510672","0286c88109eea534857086e44ff830cb");

		platforms->push_back(WEIXIN);
		platforms->push_back(WEIXIN_CIRCLE);
	}else if(getSDKPlatform()==_QQAccount_OFFLINE){//应用宝渠道,线下包

		platforms->push_back(WEIXIN);
		platforms->push_back(WEIXIN_CIRCLE);
		platforms->push_back(SINA);
	}
    platforms->push_back(QQ) ;
    platforms->push_back(QZONE);
    
    sdk->setPlatforms(platforms);
    
    // 设置授权验证地址
    sdk->setSsoAuthorization(SINA, "http://sns.whalecloud.com/sina2/callback");
    
    // 设置回调
    sdk->openShare(ShareWord.c_str(),sharePng.c_str(), share_selector(shareCallback));
    
    // 设置分享内容
    sdk->setPlatformShareContent(SINA, ShareWord.c_str(), sharePng.c_str(), title.c_str(), shareURL.c_str());
    sdk->setPlatformShareContent(WEIXIN, ShareWord.c_str(), sharePng.c_str(), title.c_str(), shareURL.c_str());
    sdk->setPlatformShareContent(WEIXIN_CIRCLE, " ", sharePng.c_str(), ShareWord.c_str(), shareURL.c_str());
    sdk->setPlatformShareContent(QQ, ShareWord.c_str(), sharePng.c_str(), title.c_str(), shareURL.c_str());
    sdk->setPlatformShareContent(QZONE, ShareWord.c_str(), sharePng.c_str(), title.c_str(), shareURL.c_str());
#endif
}

void SDKControl::exitGame()
{
	Director::getInstance()->end();
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		exit(0);
	#endif
}

//-------------------------------------------------------

string ValueMapRef::getName()
{
	return this->valueMap["methodToCall"].asString();
}

int ValueMapRef::getResult()
{
	return this->valueMap["result"].asInt(); 
}

int ValueMapRef::getInt(const char* key){
	return this->valueMap[key].asInt();
}

string ValueMapRef::getString(const char* key)
{
	return this->valueMap[key].asString();
}

bool ValueMapRef::getBool(const char* key)
{
	return this->valueMap[key].asBool();
}


void ValueMapRef::putInt(const char* key,int value)
{
	this->valueMap[key] = value;
}
void ValueMapRef::putString(const char* key,const char* value)
{
	this->valueMap[key] = value;
}

void ValueMapRef::putBool(const char* key,bool value)
{
	this->valueMap[key] = value;
}

