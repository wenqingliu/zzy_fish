#ifndef __CUSTOM_LABEL__
#define __CUSTOM_LABEL__

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class CustomLabel : public Label
{
public:
	//lua中无法使用createWithCharMap方法,重新自定义导出
	static Label* createWithCharMap(const std::string& charMapFile, int itemWidth, int itemHeight, int startCharMap);
private:

};

#endif //__CUSTOM_LABEL__