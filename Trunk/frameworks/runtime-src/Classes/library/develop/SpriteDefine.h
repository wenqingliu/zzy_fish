//
//  CSpriteDefine.h
//  cc2dx-test
//
//  Created by Foxuc on 13-2-20.
//
//

#ifndef cc2dx_test_CSpriteDefine_h
#define cc2dx_test_CSpriteDefine_h

#include "cocos2d.h"
#include "CMD_Stdafx.h"
#include "MD5.h"
//#include "SimpleAudioEngine.h"
#include "CMD_NotifyDefine.h"
USING_NS_CC;
//using namespace CocosDenshion;


typedef const char c_char;
typedef const char* pConstChar;

#define CCLogPoint(p)                   CCLOG("point:%f,%f",p.x,p.y)
#define CCLogSize(s)                    CCLOG("size:%f,%f",s.width,s.height)
#define CCLogRect(r)                    CCLOG("rect:%f,%f,%f,%f",r.origin.x,r.origin.y,r.size.width,r.size.height)

//字体定义
#define FONT_ARIAL                      (char*)"Arial"
#define FONT_ARIAL_HOLD                 (char*)"Arial-BoldMT"
#define FONT_HELVETICANEUE              (char*)"Helvetica Neue"
#define FONT_OPTIMA_EXTRABLACE          (char*)"Optima-ExtraBlack"
#define FONT_DEFAULT                    FONT_ARIAL_HOLD      //默认字体

//点
#define ccpZero							ccp(0,0)
#define ccpDefault                      ccp(0.5f,0.5f)
#define ccpVisibleZero                  cocos2d::CCEGLView::sharedOpenGLView()->getVisibleOrigin();
#define ccpVisibleSize                  cocos2d::CCEGLView::sharedOpenGLView()->getVisibleSize();

#define ccpMax							ccp(1.0f, 1.0f)
#define ccpWithSize(s)                  ccp(s.width, s.height)
#define ccpHalfSize(s)                  ccp(s.width/2, s.height/2)
#define ccpHalfSizeAddccp(s,p)          ccp(s.width/2+p.x, s.height/2+p.y)
#define ccpHalfSizeNode(node)           ccp(YYNodeSizeWidth_2(node),YYNodeSizeHeight_2(node))

//矩形
#define ccr(x,y,w,h)                    Rect(x,y,w,h)
#define ccr2(p,s)						ccr(p.x, p.y, s.width, s.height)
#define ccrZero							ccr(0,0,0,0)

//size
#define ccsZero							Size(0,0)
#define ccsScale(size,scale)            ccs(size.width*scale,size.height*scale)
#define ccsWithPoint(p)                 ccs(p.x,p.y)
#define ccsAddSize(s1,s2)               Size(s1.width+s2.width, s1.height+s2.height)


#define ccc4White                       ccc4(255, 255, 255, 255)
#define ccc4Blue                        ccc4(0, 0, 255, 255)
#define ccc4Black                       ccc4(0, 0, 0, 255)
#define ccc4Red                         ccc4(255, 0, 0, 255)
#define ccc4Gray                        ccc4(166,166,166,255)
#define ccc3Gray                        ccc3(180,180,180)
#define ccc4ColorFrom(ccc3color)        ccc4(ccc3color.r,ccc3color.g,ccc3color.b,255)   

//#define ccSize                          CFrameManager::getLogicSize();

//range
#define between(num,min,max)                    ((num<max)&&(num>min))
#define betweenCMin(num,min,max)                ((num<max)&&(num>=min))
#define betweenCMax(num,min,max)                ((num<=max)&&(num>min))
#define betweenCMinMax(num,min,max)             ((num<=max)&&(num>=min))
#define betweenCMinMax2(value1,value2,min,max)   ((value1<=max&&value2<=max)&&(value1>=min&&value2>=min))

//兼容PC函数
//#define ASSERT(e)                       assert(e)
//#define CopyMemory(des,src,size_t)      memcpy(des,src,size_t)

//显示标识 DP=display
typedef int DP_TYPE;
#define DP_DELETE                       0                               //删除
#define DP_SHOW                         1                               //显示
#define DP_SPECIAL_SHOW                 2                               //指定显示
#define DP_SPECIAL_DELETE               3                               //指定删除
#define DP_SKIP                         4                               //跳过

typedef int SHOWTYPE;
#define STDELETE                        0                               //删除
#define STSHOW                          1                               //显示
#define STSPECIALSHOW                   2                               //指定显示
#define STSPECIALDELETE                 3                               //指定删除
#define STSKIP                          4                               //跳过

#define ST_DELETE                       0                               //删除
#define ST_SHOW                         1                               //显示
#define ST_SHOW_SPECIAL                 2                               //指定显示
#define ST_DELETE_SPECIAL               3                               //指定删除
#define ST_SKIP                         4                               //跳过
#define ST_TEMP                         5                               //临时

//相对parent的坐标

#define CC_PARENT_RELATIVEX(node)               (node->getPositionX()-node->getContentSize().width*node->getAnchorPoint().x)
#define CC_PARENT_RELATIVEY(node)               (node->getPositionY()-node->getContentSize().height*node->getAnchorPoint().y)
#define CC_PARENT_RELATIVEXAdd(node,num)        (CC_PARENT_RELATIVEX(node)+num)
#define CC_PARENT_RELATIVEYAdd(node,num)        (CC_PARENT_RELATIVEY(node)+num)

#define CC_PARENT_RELATIVE(node)                Point(CC_PARENT_RELATIVEX(node),CC_PARENT_RELATIVEY(node))
#define CC_PARENT_RELATIVEAddPoint(node,point)  Point(CC_PARENT_RELATIVEX(node)+point.x,CC_PARENT_RELATIVEY(node)+point.y)
#define CC_PARENT_RELATIVEAddXY(node,x,y)       Point(CC_PARENT_RELATIVEX(node)+x,CC_PARENT_RELATIVEY(node)+y)

//设备标识缩放
#define IOS_RETINA                      0.5f
#define IOS_NORMAL                      1.0f

//tag优先 显示优先也可以用

#define YYMATCH_TAG_GAME                10001       //比赛游戏
#define YYMATCH_TAG_TIPS                10001       //比赛提示
#define YYMATCH_TAG_RANK                10002       //比赛名次
#define YYMATCH_TAG_INFO                10003       //比赛信息
#define YYMATCH_TAG_OVER                10004       //比赛结果

#define YYTAG_LOCK                      10000
#define YYTAG_ALERT                     9999
#define YYTAG_TIPS                      9998
#define YYTAG_USER_INFO                 9997
#define YYTAG_TEMP                      9996        //临时层
#define YYTAG_TOP                       1000        //置顶层



#define YYBetween(x,min,max) (((x)<(min))?(min):((x)>(max))?(max):(x))

#define YYNodeSpaceBoundRect(pNode)     Rect( 0-pNode->getContentSize().width*pNode->getAnchorPoint().x,\
                                                0-pNode->getContentSize().height*pNode->getAnchorPoint().y,\
                                                pNode->getContentSize().width,\
                                                pNode->getContentSize().height )

#define YYNodeBoundRect(pNode)          Rect( pNode->getPosition().x-pNode->getContentSize().width*pNode->getAnchorPoint().x,\
                                                pNode->getPosition().y-pNode->getContentSize().height*pNode->getAnchorPoint().y,\
                                                pNode->getContentSize().width,\
                                                pNode->getContentSize().height )

#define YYNodeWordBoundRect(pNode)      Rect( pNode->getPosition().x-pNode->getContentSize().width*pNode->getAnchorPoint().x + pNode->getParent()->getPosition().x,\
                                                pNode->getPosition().y-pNode->getContentSize().height*pNode->getAnchorPoint().y + pNode->getParent()->getPosition().y,\
                                                pNode->getContentSize().width,\
                                                pNode->getContentSize().height)

#define YYNodeSizeWidth(pNode)                  pNode->getContentSize().width
#define YYNodeSizeWidth_2(pNode)                pNode->getContentSize().width/2
#define YYNodeSizeWidthAddValue(pNode, value)   (pNode->getContentSize().width+value)
#define YYNodeSizeWidthHalfAddValue(pNode, value) (pNode->getContentSize().width/2+value)

#define YYNodeSize(pNode)                       pNode->getContentSize()
#define YYNodeSize_2(pNode)                     Size(pNode->getContentSize().width/2, pNode->getContentSize().height/2)
#define YYNodeSizeAddSize(pNode,w,h)            Size(pNode->getContentSize().width+w, pNode->getContentSize().height+h)
#define YYNodeSizeHeight(pNode)                 pNode->getContentSize().height
#define YYNodeSizeHeight_2(pNode)               pNode->getContentSize().height/2
#define YYNodeSizeHeightAddValue(pNode,value)   (pNode->getContentSize().height+value)

#define YYNodePoint(pNode)                      pNode->getPosition()
#define YYNodePointX(pNode)                     YYNodePoint(pNode).x
#define YYNodePointY(pNode)                     YYNodePoint(pNode).y

#define YYNodeOriginx(pNode)                    YYNodeBoundRect(pNode).origin.x
#define YYNodeOriginy(pNode)                    YYNodeBoundRect(pNode).origin.y
#define YYSizeToPoint(pNode)					ccp(pNode->getContentSize().width, pNode->getContentSize().height)
#define YYSizeHalfToPoint(pNode)				ccp(pNode->getContentSize().width/2, pNode->getContentSize().height/2)

#define YYNodeRectMinx(pNode)                   YYNodeBoundRect(pNode).origin.x
#define YYNodeRectMaxx(pNode)                   YYNodeBoundRect(pNode).origin.x+YYNodeBoundRect(pNode).size.width
#define YYNodeRectMiny(pNode)                   YYNodeBoundRect(pNode).origin.y
#define YYNodeRectMaxy(pNode)                   YYNodeBoundRect(pNode).origin.y+YYNodeBoundRect(pNode).size.height
#define YYNodeRectOrigin(pNode)                 ccp(YYNodeRectMinx(pNode),YYNodeRectMiny(pNode))
#define YYNodeRectOriginAddPoint(pNode,p)       ccp(YYNodeRectMinx(pNode)+p.x,YYNodeRectMiny(pNode)+p.y)
#define YYNodeRectOriginAddPoint2(pNode,x,y)     ccp(YYNodeRectMinx(pNode)+x,YYNodeRectMiny(pNode)+y)

#define YYRectAddValue(rect,value)              rect.origin.x+=value;   \
                                                rect.origin.y+=value;   \
                                                rect.size.width-=value; \
                                                rect.size.height-=value;

#define YYSizeAddValue(size,valus)              size.width+=value;\
                                                size.height+=value;

#define YYCompareStr(str1, str2)				(strcmp(str1, str2)==0)
#define YYCompareStr2(s1, str)					(strcmp(s1.c_str(), str)==0)
#define YYCompareStr3(s1, s2)					(strcmp(s1.c_str(), s2.c_str())==0)
#define YYCompareFind(s1, str2)					((int)s1.find(str2)>-1)
#define YYCompareFindAt0(s1, str2)				((int)s1.find(str2)==0)


#define kYYProiorityLayer                       0
#define kYYProiorityTextField                   kCCMenuHandlerPriority
#define kYYProiorityButton                      kCCMenuHandlerPriority
#define kYYProiorityCard                        kCCMenuHandlerPriority
#define kYYProiorityUser                        kCCMenuHandlerPriority

#define kYYProiorityScrollViewButton            1

#define kYYProiorityAlert                       kCCMenuHandlerPriority-99
#define kYYProiorityAlertButton                 kCCMenuHandlerPriority-100
#define kYYProiorityTestButton                  kYYProiorityAlertButton

#define kYYProiorityCCScrollView                kCCMenuHandlerPriority-4
#define kYYProiorityCCLayerEx                   kCCMenuHandlerPriority-5
#define kYYProiorityCCLayerExButton             kCCMenuHandlerPriority-6
#define kYYProiorityCCLayerExTextField          kCCMenuHandlerPriority-6
#define kYYProiorityCCLayerExScroll             kCCMenuHandlerPriority-7
#define kYYProiorityScrollExButton              kCCMenuHandlerPriority-8


#define kYYProiorityUser                        kCCMenuHandlerPriority
#define kYYProiorityLock                        kCCMenuHandlerPriority-9
#define kYYProiorityLockButton                  kYYProiorityLock-1
#define kYYProiorityNone                        1000


//-----------------------------FrameManager----------------------------------------------------------------------
#define kYYAndroid_NONE                 0       //无拦截
#define kYYAndroid_TOP                  1       //置顶拦截
#define kYYAndroid_LOCK                 2       //锁屏拦截
#define kYYAndroid_Cancel				3		//返回拦截

//-----------------------------FrameManager----------------------------------------------------------------------




//-----------------------------字符转码----------------------------------------------------------------------
//单字符:utf8 -> unicode 返回转换长度
extern int YYConverUtf8ToUnicode(TCHAR *destUnicode, c_char *srcUtf8);

//单字符:unicode -> utf8 返回转换长度
extern int YYConverUnicodeToUtf8(char* destUtf8, TCHAR srcUnicode);

//数组:utf8 -> unicode
extern void YYConverUtf8ToUnicodeWithArray(TCHAR destUnicode[], int tcharLength, c_char srcUtf8[]);
//数组:utf8 -> unicode  2
void YYConverUtf8ToUnicodeWithArray2(TCHAR  pOut[],c_char pText[]);

//数组:unicode -> utf8
extern void YYConverUnicodeToUtf8WithArray(char destUtf8[], TCHAR srcUnicode[]);

//扩展转换
extern char* YYConverUnicodeToUtf8(TCHAR srcUnicode[]);

//扩展转换：utf8 -> md5 unicode
extern void YYConverUtf8ToMD5Unicode(TCHAR destUnicode[], c_char srcUtf8[]);

//扩展转换: uf8 -> md5
extern char* YYConverUft8ToMD5(c_char destUf8[]);

extern int UniCharToUTF8(TCHAR UniChar, char *OutUTFString);
extern int UTF8StrToUnicode( const char* UTF8String, int UTF8StringLength, TCHAR* OutUnicodeString, int UnicodeStringBufferSize );

//-----------------------------字符转码----------------------------------------------------------------------


//-----------------------------字符转换----------------------------------------------------------------------

//当前系统时间精确到秒
extern long YYSystemTimeNowSec();
//获取当前时间 精确到毫秒数
extern long YYMillisecondNow();
//获取当前时间秒
extern long YYSystemSecond();
//判断是不是 双击
extern bool isDoubleTouch();
//隐射数据
extern bool mappedBuffer(void* pData, WORD wDataSize);
//隐射数据
extern bool unMappedBuffer(void* pData, WORD wDataSize);



#define YYCHAR(szFormat, ...) YYChar(szFormat, ##__VA_ARGS__)
extern c_char* YYChar(const char* format, ...);

#define YYNEWCHAR(dest, size, format, ...) YYNewChar(dest, size, format, ##__VA_ARGS__)

#define YYDefineChar(name, size, format, ...) \
char name[size]; \
memset(name, 0, size);\
YYNEWCHAR(name, size, format, ##__VA_ARGS__);

#define YYDynamic_cast(__dyT, __dyP) (dynamic_cast<__dyT>(__dyP))

extern void YYNewChar(char* pData, WORD wDataSize, const char* format, ...);
extern void YYAppendChar(char* pData, c_char* src);

//-------------------------------------------------------------------------------------------------------------------

#define kBackgroundSoundValue "kBackgroundValue"
#define kEffectSoundValue "kEffectSoundValue"

extern CCNotificationCenter*    GetNotificationCenter();

#endif
