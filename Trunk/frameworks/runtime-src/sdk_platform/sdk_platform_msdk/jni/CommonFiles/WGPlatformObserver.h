//
//  WGPlatformObserver.h
//  WGPlatform
//
//  Created by fly chen on 2/22/13.
//  Copyright (c) 2013 tencent.com. All rights reserved.
//

#ifndef WGPlatform_WGPlatformObserver_h
#define WGPlatform_WGPlatformObserver_h

#include <string>
#include "WGCommon.h"

/*! @brief WGPlatform通知类
 *
 * SDK通过通知类和外部调用者通讯
 */
class WGPlatformObserver
{
public:
	/*! @brief 登录回调
	 *
	 * 登录时通知上层App，并传递结果
	 * @param loginRet 参数
	 * @return void
	 */
	virtual void OnLoginNotify(LoginRet& loginRet) = 0;
    
	/*! @brief 被其他应用拉起
	 *
	 *被其他平台拉起
	 * @param wakeupRet  唤起参数
	 * @return void
	 */
	virtual void OnWakeupNotify(WakeupRet& wakeupRet) = 0;

	virtual void OnRelationNotify(RelationRet& relationRet) = 0;
    
	virtual ~WGPlatformObserver() {};
	

};

#endif
