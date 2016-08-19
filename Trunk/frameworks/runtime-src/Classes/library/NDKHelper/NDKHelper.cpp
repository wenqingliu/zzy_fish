//
//  NDKHelper.cpp
//  EasyNDK-for-cocos2dx
//
//  Created by Amir Ali Jiwani on 23/02/2013.
//  Updated by Alfonso Cejudo March, 2014.
//
//

#include "NDKHelper.h"
#include "CallFuncNV.h"

USING_NS_CC;

#define __CALLED_METHOD__           "calling_method_name"
#define __CALLED_METHOD_PARAMS__    "calling_method_params"

std::vector<NDKCallbackNode> NDKHelper::selectorList;

void NDKHelper::addSelector(const char *groupName, const char *name, FuncNV selector, Node *target)
{
    NDKHelper::selectorList.push_back(NDKCallbackNode(groupName, name, selector, target));
}

void NDKHelper::printSelectorList()
{
    for (unsigned int i = 0; i < NDKHelper::selectorList.size(); ++i) {
        std::string s = NDKHelper::selectorList[i].getGroup();
        s.append(NDKHelper::selectorList[i].getName());
    }
}

void NDKHelper::removeSelectorsInGroup(const char *groupName)
{
    std::vector<int> markedIndices;
    
    for (unsigned int i = 0; i < NDKHelper::selectorList.size(); ++i) {
        if (NDKHelper::selectorList[i].getGroup().compare(groupName) == 0) {
            markedIndices.push_back(i);
        }
    }
    
    for (long i = markedIndices.size() - 1; i >= 0; --i) {
        NDKHelper::selectorList.erase(NDKHelper::selectorList.begin() + markedIndices[i]);
    }
}

void NDKHelper::handleMessage(const char *methodNameStr, const char *methodParamsStr)
{
    if (methodNameStr == NULL) {
        return;
    }
    
//    const char *methodNameStr = json_string_value(methodName);
    
    for (unsigned int i = 0; i < NDKHelper::selectorList.size(); ++i) {
        if (NDKHelper::selectorList[i].getName().compare(methodNameStr) == 0) {
            
            // FuncNV sel = NDKHelper::selectorList[i].getSelector();
            Node *target = NDKHelper::selectorList[i].getTarget();
            
            // CallFuncNV *caller = CallFuncNV::create(sel);
            // caller->setValue(Value(methodParamsStr));
            auto params = Value(methodParamsStr);
            if (target) {
				// caller->execute();
                // FiniteTimeAction *action = Sequence::create(caller, NULL);
                // target->runAction(action);
				//自定义修改;16/05/09
				Director::getInstance()->getScheduler()->performFunctionInCocosThread([&,i,params]{
					        
					FuncNV sel = NDKHelper::selectorList[i].getSelector();
					Node *target = NDKHelper::selectorList[i].getTarget();
					
					CallFuncNV *caller = CallFuncNV::create(sel);
					caller->setValue(params);
					caller->execute();
				});
            } else {
				FuncNV sel = NDKHelper::selectorList[i].getSelector();
				CallFuncNV *caller = CallFuncNV::create(sel);
				caller->setValue(Value(methodParamsStr));
                caller->execute();
            }
            
            break;
        }
    }
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/jni/JniHelper.h" 
#include <android/log.h>
#include <jni.h>

#define LOG_TAG    "EasyNDK-for-cocos2dx"
#define CLASS_NAME "com/easyndk/classes/AndroidNDKHelper"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#import "IOSNDKHelper-C-Interface.h"
#endif

extern "C"
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    // Method for receiving NDK messages from Java, Android
    void Java_com_easyndk_classes_AndroidNDKHelper_CPPNativeCallHandler(JNIEnv *env, jobject thiz,jstring jmethodNameStr, jstring jparamsJsonStr) {
        /* The JniHelper call resulted in crash, so copy the jstring2string method here */
        //std::string jsonString = JniHelper::jstring2string(json);

        if (jparamsJsonStr == NULL) {
            return;
        }
        
        JNIEnv *pEnv = JniHelper::getEnv();
        if (!env) {
            return;
        }
        
		//方法名称
		const char *methodNameStr = env->GetStringUTFChars(jmethodNameStr,NULL);
		
        //参数
        const char *paramsJsonStr = env->GetStringUTFChars(jparamsJsonStr, NULL);
		
		//复制对象
		std::string strMethod(methodNameStr);
		env->ReleaseStringUTFChars(jmethodNameStr, methodNameStr);
		
		std::string strParams(paramsJsonStr);
		env->ReleaseStringUTFChars(jparamsJsonStr, paramsJsonStr);
		
        NDKHelper::handleMessage(strMethod.c_str(), strParams.c_str());
		// env->ReleaseStringUTFChars(jmethodNameStr, methodNameStr);
		// env->ReleaseStringUTFChars(jparamsJsonStr, paramsJsonStr);
    }
#endif
    
    // Method for sending message from CPP to the targeted platform
    void sendMessageWithParams(std::string methodName, std::string methodParams) {
        if (0 == strcmp(methodName.c_str(), "")) {
            return;
        }
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo t;
        
		if (JniHelper::getStaticMethodInfo(t,
                                           CLASS_NAME,
                                           "ReceiveCppMessage",
                                           "(Ljava/lang/String;Ljava/lang/String;)V")) {
            std::string jsonStr(methodParams);
            jstring jmethodName = t.env->NewStringUTF(methodName.c_str());
            jstring stringArg1 = t.env->NewStringUTF(jsonStr.c_str());
            t.env->CallStaticVoidMethod(t.classID, t.methodID, jmethodName,stringArg1);
			t.env->DeleteLocalRef(jmethodName);
            t.env->DeleteLocalRef(stringArg1);
			t.env->DeleteLocalRef(t.classID);
		}
#endif
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

        if (!methodParams.empty()) {
            IOSNDKHelperImpl::receiveCPPMessage(methodName.c_str(), methodParams.c_str());
        } else {
            IOSNDKHelperImpl::receiveCPPMessage(methodName.c_str(), NULL);
        }
        
#endif
    }
}
