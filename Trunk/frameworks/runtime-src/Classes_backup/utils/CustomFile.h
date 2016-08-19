#ifndef __CUSTOM_FILE__
#define __CUSTOM_FILE__

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class CustomFile : public Ref
{
public:
	
	
	static bool writeFile(string& content,const std::string& fullPath,const string& fileName);

	static bool createDirectory(const string& dirname);

	/*bool init() { return true; };
	CREATE_FUNC(CustomFile);*/
private:
	CustomFile(){};
	~CustomFile(){};
};

#endif //__CUSTOM_FILE__