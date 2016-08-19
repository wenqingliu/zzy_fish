#ifndef __URL_LOADER__
#define __URL_LOADER__
#include "cocos2d.h"
#include <string.h>
#include "network/HttpClient.h"
USING_NS_CC;
using namespace network;
using namespace std;
class URLLoader : public Ref
{
public:
	static URLLoader* create();

	void load(const string& url);

	void pushRequest(const string url);

	void removeRequest(const string url);

	void start();

	void stop();

	bool getRunning(){
		return _running;
	}

	static URLLoader* getInstance();
	
	void destroyInstance();

private:
	void onHttpRequestCompleted(HttpClient* sender,HttpResponse* response);

	void onSingleHttpRequestCompleted(HttpClient* sender,HttpResponse* response);

	vector<string> _requestQueue;

	bool _running;
	bool _isStop;

	static URLLoader* _instance;

	URLLoader():
		_isStop(false),
		_running(false)
	{
	
	};

	~URLLoader(){
		
	};

	

};

#endif //__URL_LOADER__
