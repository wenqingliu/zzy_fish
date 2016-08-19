//
//  CSpriteStdafx.h
//  cc2dx-test
//
//  Created by Foxuc on 13-2-20.
//
//

#ifndef cc2dx_test_CSpriteStdafx_h
#define cc2dx_test_CSpriteStdafx_h

#include "SpriteDefine.h"
#include "protocol.h"

//#include "SpriteImage.h"
//#include "SpriteLabel.h"
//#include "SpriteButton.h"
//#include "SpriteAlert.h"
//#include "SpriteLock.h"
#include "SpriteData.h"
//#include "SpriteUser.h"
//#include "SpriteCard.h"
//#include "SpriteEditBox.h"
//#include "CParseLayer.h"
//
//
//#include "CCLayerEx.h"
//#include "CCActionEx.h"
//#include "GameDelegate.h"

#include <stdlib.h>
#include <stdio.h>


#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include <sys/types.h>
#include <sys/socket.h> // Per msqr
#include <sys/sysctl.h>
#include <net/if.h>
#include <net/if_dl.h>
#endif


#define P_SIZE          CCEGLView::sharedOpenGLView()->getDesignResolutionSize()
#define P_WIDTH         P_SIZE.width
#define P_HEIGHT        P_SIZE.height
#define P_WIDTH_2       P_WIDTH/2
#define P_HEIGHT_2      P_HEIGHT/2

#define P_V_ZERO        CCEGLView::sharedOpenGLView()->getVisibleOrigin()
#define P_V_SIZE        CCEGLView::sharedOpenGLView()->getVisibleSize()

#define P_FRAME_SIZE	CCEGLView::sharedOpenGLView()->getFrameSize()


//输出到屏幕显示
#define YYDEBUG         0
#define YYDEBUGTAG      1000000

//----------------------------------------------------------------------------------------------------------
//测试size大小 CCLayerColor显示出当前的Size大小
extern void testBackGround(CCSize size, CCNode* target);
//测试size
extern void testBackGround(CCNode* target);
//测试size
extern void testBackGround(CCNode* target, ccColor3B color);
//删除节点 
extern void YYRemoveNodeChildTag(CCNode* pParent, int nTag);


//debug显示到屏幕上的
#define YYDEBUGSHOW(target, format, ...)  YYDebugShow(target, format, ##__VA_ARGS__)
#define YYCURRENTSHOW(format, ...) YYDebugShow(GetFrameManager()->m_pCurrentLayer, format, ##__VA_ARGS__)
extern void YYDebugShow(CCNode* target, c_char* format, ...);
//----------------------------------------------------------------------------------------------------------

//转换数值
extern int SwitchStringToValue(c_char* pszSring, int &index);
extern c_char* YYConverString(c_char* pszString);
extern c_char* YYReplaceStringWithString(c_char* pszString, c_char* findString, c_char* replaceString, int &result);

#define YYRANDOM()      (int)(CCRANDOM_0_1()*1000)


//------------------------------------------------------device-------------------------------------------------------
extern c_char* YYGetMacAddress(WORD wKindID=0);
extern c_char* YYGetMacAddress_Android(WORD wKindID=0);
extern void YYGetApkInfoAddress_Android(c_char* pkgname);
extern void YYStartGameWithPackageName_Android(c_char* pkgname);
extern c_char* YYGetMacAddress_IOS(WORD wKindID=0);

extern float YYRand0_1();

extern char* YYGetNickName();
extern char* YYGetNickName_Android();
extern char* YYGetNickName_IOS();


extern void YYShare();
extern void YYShare_Android();
extern void YYShare_IOS();

//-------------------------------------------------------------------------------------------------------------------



#endif
