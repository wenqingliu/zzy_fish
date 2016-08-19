#pragma once
#ifndef __SDK_CONTROL__
#define __SDK_CONTROL__

#include "cocos2d.h"
#include "JT_Macro.h"

USING_NS_CC;
using namespace std;

//ValueMap类封装
class ValueMapRef: public Ref
{
public:
    
    JT_CREATE_FUNC(ValueMapRef);
    
    //方法名称
    string getName();
    //操作结果
    int getResult();
    
    int getInt(const char* key);
    string getString(const char* key);
    bool getBool(const char* key);
    
    void putInt(const char* key,int value);
    void putString(const char* key,const char* value);
    void putBool(const char* key,bool value);
    
public:
    ValueMap valueMap;
    
private:
    
};

class SDKControl : public Node
{
public:
    SDKControl(void);
    ~SDKControl(void);
    
    JT_CREATE_FUNC(SDKControl);
    static SDKControl* getInstance();
    
    // 调用java方法(C++  -> java)
    void sendMessage(const char* nativeMethod);
    
    void sendMessage(const char* nativeMethod,const char* jsonStr);
    
    // 调用java方法(C++  -> java)
    void sendMessage(const char* nativeMethod,ValueMapRef* valueMap);
    
    //注册java调用C++方法(C++  -> java)
    void addSelector(const char *name);
    
    void removeSelectors(const char *name);
    
    void handleMessage(Node *sender, Value data);
    
    // 获取平台字符串
    std::string getStringFromPlatform(const unsigned int notifyCode, const char *notifyName);
    
    // 获取平台数值
    int getValueFromPlatform(const unsigned int notifyCode, const char *notifyName);
    
    // 初始化平台版本号
    std::string getVersion() {return m_version;}
    void setVersion(std::string version) {m_version = version;}
    
    int getVersionCode();
    void setVersionCode(int code) {m_versionCode = code;}
    
    // 获取SDK平台渠道标识
    int getSDKPlatform();
    
    // 获取WIFI状态
    int getWifiState();
    
    // 是否debug模式
    bool isCocosDebug();
    
    // app是否debug或普通运行版本
    bool isAppDebug();
    
    void printInfo(const char* tag,const char* msg);
    
    void printError(const char* msg);
    
    // 初始化分享
    void initUmengShareSDK(const std::string ShareWord,
                           const std::string sharePng,
                           const std::string shareURL,
                           const std::string title);
    
    // 退出游戏
    void exitGame();
    
private:
    std::string m_version;
    int m_versionCode;
    static SDKControl* _instance;
};


#endif
