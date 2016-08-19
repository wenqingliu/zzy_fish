#ifndef __URL_DATA__
#define __URL_DATA__

#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class URLData : public Ref
{
public:
	URLData(){};

	URLData(int statusCode,string data);

	string getData(){return data;};

	int getStatusCode(){return statusCode;};

	void setData(string data){this->data = data;};

	void setStatusCode(int statusCode){this->statusCode = statusCode;};

	~URLData();

	int statusCode;

	string data;
private:

};

#endif //__URL_DATA__