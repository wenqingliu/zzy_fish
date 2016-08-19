//
//  SpriteStdafx.cpp
//  GameProject
//
//  Created by Foxuc on 13-4-24.
//
//

#include "SpriteStdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "MD5.h"
#if ( (CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID) )
#include <jni.h>
#include "platform/android/jni/JniHelper.h" 
#include <android/log.h>
#endif


#ifdef WIN32

#else

#include <wchar.h>

#endif

//ios导入
#if ( (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) )


#endif



//----------------------------------------------------------------------------------------------------------
//测试back
void testBackGround(CCSize size, CCNode* target)
{
    CCLayerColor* backColor=CCLayerColor::create(ccc4Red, size.width, size.height);
    backColor->setAnchorPoint(ccpZero);
    backColor->setPosition(ccpZero);
    backColor->setOpacity(50);
    target->addChild(backColor);
}
//测试back
void testBackGround(CCNode* target)
{
    CCLayerColor* backColor=CCLayerColor::create(ccc4Red, target->getContentSize().width, target->getContentSize().height);
    backColor->setAnchorPoint(ccpZero);
    backColor->setPosition(ccpZero);
    backColor->setOpacity(50);
    target->addChild(backColor);
}
//测试size
void testBackGround(CCNode* target, ccColor3B color)
{
    CCLayerColor* backColor=CCLayerColor::create(ccc4ColorFrom(color), target->getContentSize().width, target->getContentSize().height);
    backColor->setAnchorPoint(ccpZero);
    backColor->setPosition(ccpZero);
    backColor->setOpacity(50);
    target->addChild(backColor);
}

//删除节点
void YYRemoveNodeChildTag(CCNode* pParent, int nTag)
{
    //删除滚动层
    /*Array* pArray=pParent->getChildren();
    for (WORD i=0; i<pArray->count();)
    {
        CCNode* pNode=(CCNode*)pArray->objectAtIndex(i);
        if(pNode->getTag()>nTag)
            pNode->removeFromParent();
        else
            i++;
    }*/
}
//debug显示到屏幕上的
void YYDebugShow(CCNode* target, c_char* format, ...)
{
#if YYDEBUG
    static int nCount=0;
    static int nIndex=-1;
    if(target)
    {
        //连接字符
        static char pData[256];
        memset(pData, 0, sizeof(pData));
        va_list ap;
        va_start(ap, format);
        vsnprintf(pData, 1024, format, ap);
        va_end(ap);
        
        static CCLayer* pLayer=new CCLayer;
        if(!target->getChildByTag(YYDEBUGTAG) )
        {
            pLayer->removeFromParent();
            target->addChild(pLayer, 10, YYDEBUGTAG);
        }
        
        //输出结果
        CSpriteLabel* pTips = CSpriteLabel::spriteLabelWithString(pData, FONT_ARIAL_HOLD, 25);
        pTips->setAnchorPoint(ccpZero);
        pTips->setPosition(ccp(0, 680-nCount*25));
        pTips->setColor(ccORANGE);
        pLayer->addChild(pTips, 10, nCount);
        
        //删除顶条
        if(nIndex!=-1)
        {
            pLayer->removeChildByTag(nIndex);
            pLayer->setPosition(ccp(0, 25*nIndex));
        }
        
        nCount++;
        if(nCount>24)
            nIndex++;
    }
#endif
}
//----------------------------------------------------------------------------------------------------------


//转换数值
int SwitchStringToValue(c_char* pszSring, int &index)
{
	//效验参数
	assert( (pszSring!=NULL) && (pszSring[0]!=0) );
	if ((pszSring==NULL)||(pszSring[0]==0)) return 0;
    
	//寻找开始
	while ( ((pszSring[0]>0)&&(pszSring[0]<'0')) || (pszSring[0]>'9'))
    {
        pszSring++;
        index++;
    }
    
	//读取数值
	int nValue=0;
	while ((pszSring[0]>='0') && (pszSring[0]<='9'))
	{
		nValue=nValue*10 + pszSring[0]-'0';
		++pszSring;
        ++index;
	}
	return nValue;
}

c_char* YYConverString(c_char* pszString)
{
	int index = 0;
	std::string string = pszString;
	string = YYReplaceStringWithString(string.c_str(), "亿", "00000000", index);
	string = YYReplaceStringWithString(string.c_str(), "千万", "0000000", index);
	string = YYReplaceStringWithString(string.c_str(), "百万", "000000", index);
	string = YYReplaceStringWithString(string.c_str(), "十万", "00000", index);
	string = YYReplaceStringWithString(string.c_str(), "万",   "0000", index);

	return string.c_str();
}

c_char* YYReplaceStringWithString(c_char* pszString, c_char* findString, c_char* replaceString, int &result)
{
	std::string string = pszString;
	result = (unsigned int)string.find(findString);
	if(result!=-1)
	{
		string.replace(result, strlen(findString), replaceString);

		while (result!=-1)
		{
			string = YYReplaceStringWithString(string.c_str(), findString, replaceString, result);
		}
	}

	return string.c_str();
}

//------------------------------------------------------address------------------------------------------------------
//mac address
c_char* YYGetMacAddress(WORD wKindID)
{
    //cout<<"打印设备wKindID:"<<wKindID<<endl;
#if ( (CC_TARGET_PLATFORM==CC_PLATFORM_WIN32) )
	c_char* device = "12345678901234567890123456789012";
	return device;
#endif
    //安卓设备 mac
#if ( (CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID) )
    return YYGetMacAddress_Android(wKindID);
#endif
    
    //ios设备 mac
#if ( (CC_TARGET_PLATFORM==CC_PLATFORM_IOS) )
    return YYGetMacAddress_IOS(1);//wKindID
#endif
    
    return NULL;
}

c_char* YYGetMacAddress_Android(WORD wKindID)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo minfo;
    bool isDeviceInfo = JniHelper::getStaticMethodInfo(minfo, "YYProjectJni/JniHelper", "GetMac","(I)Ljava/lang/String;");
    if (isDeviceInfo)
    {
        jobject jobj;
        CCLOG("jni-检测到此函数，进入执行");
        //调用此函数
        jobj = minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID,5);
        CCLOG("jni-java函数执行完毕");
        
        jstring str = (jstring)jobj;
        CCLOG("转换为 jstring成功");
        
        const char *pkgName = minfo.env->GetStringUTFChars(str, NULL);
        CCLOG("转换为 char 成功");
        
		static char txt[50];
        memset(txt, 0, sizeof(txt));
		sprintf(txt, "%s", pkgName);
        minfo.env->ReleaseStringUTFChars(str, pkgName);
        return txt;
    }
	else
	{
		CCLOG("未检测到GetMac函数");
	}
#endif
    return NULL;
}

void YYGetApkInfoAddress_Android(c_char* pkgname)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	JniMethodInfo minfo;
	bool isDeviceInfo = JniHelper::getStaticMethodInfo(minfo, "YYProjectJni/JniHelper", "GetAPPIsExist","(Ljava/lang/String;)V");
	if (isDeviceInfo)
	{
		jobject jobj;
		CCLOG("jni-检测到此函数，进入执行");
		//调用此函数
		jstring jpkgname = minfo.env->NewStringUTF(pkgname);
		jobj = minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID,jpkgname);
		CCLOG("jni-java函数执行完毕");
	}
	else
	{
		CCLOG("未检测到GetAPPIsExist函数----------------------------------------");
	}
#endif
}

void YYStartGameWithPackageName_Android(c_char* pkgname)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	JniMethodInfo minfo;
	bool isDeviceInfo = JniHelper::getStaticMethodInfo(minfo, "YYProjectJni/JniHelper", "StartGame","(Ljava/lang/String;)V");
	if (isDeviceInfo)
	{
		jobject jobj;
		CCLOG("jni-检测到此函数，进入执行");
		//调用此函数
		jstring jpkgname = minfo.env->NewStringUTF(pkgname);
		jobj = minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID,jpkgname);
		CCLOG("jni-java函数执行完毕");
	}
	else
	{
		CCLOG("未检测到GetAPPIsExist函数----------------------------------------");
	}
#endif
}

c_char* YYGetMacAddress_IOS(WORD wKindID)
{
    return NULL;
}
//--------------------------------------------------------------------------------------------------------------------


float YYRand0_1()
{
	struct timeval psv;  
	gettimeofday(&psv,NULL);
	//CCTime::gettimeofdayCocos2d( &psv, NULL );    // 获取本地时间
	//根据时间产生随机种子
	unsigned int tsrans = (u_int)(psv.tv_sec * 1000 + psv.tv_usec / 1000);
	srand(tsrans);    //设定随机数种子
	return CCRANDOM_0_1();
}




//------------------------------------------------------nickName------------------------------------------------------
char* YYGetNickName()
{
#if ( (CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID) )
    return YYGetNickName_Android();
#endif
    
#if ( (CC_TARGET_PLATFORM==CC_PLATFORM_IOS) )
    return YYGetNickName_IOS();
#endif
    return NULL;
}
char* YYGetNickName_Android()
{

    return NULL;
}
char* YYGetNickName_IOS()
{

    return NULL;
}
//-------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------share--------------------------------------------------------
void YYShare()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    return YYShare_Android();
#endif
    
#if ( (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) )
    return YYShare_IOS();
#endif
    return;
}

void YYShare_Android()
{
#if ( (CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID) )
	JniMethodInfo minfo;
	if(JniHelper::getStaticMethodInfo(minfo, "com/yqy/Landlords/JniLandlordsHelper", "share","(I)V"))    //斗地主
	{
		CCLOG("jni-检测到share(int)函数，进入执行");
		//调用此函数
		minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID,2);
		CCLOG("jni-java share(int)函数执行完毕");
		return;
	}
	CCLOG("jni-未检测到share(int)函数");
	/*if (JniHelper::getStaticMethodInfo(minfo, "com/yqy/Landlords/JniLandlordsHelper", "Share","()V"))    //斗地主
	{
		jobject jobj;
		CCLOG("jni-检测到click函数，进入执行");
		//调用此函数
		minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
		CCLOG("jni-javaclick函数执行完毕");
		return;
	}
	CCLOG("jni-未检测到click函数");*/
#endif
}
void YYShare_IOS()
{
#if ( (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) )

    
#endif
}
//-------------------------------------------------------------------------------------------------------------------



