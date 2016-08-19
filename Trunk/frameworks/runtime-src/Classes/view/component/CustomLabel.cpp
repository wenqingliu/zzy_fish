#include "CustomLabel.h"

Label* CustomLabel::createWithCharMap(const std::string& charMapFile, int itemWidth, int itemHeight, int startCharMap)
{
	//return Label::createWithCharMap("fonts/digital_level.png",31,29,'0');
	return Label::createWithCharMap(charMapFile,itemWidth,itemHeight,startCharMap + '0');
};