#include "URLLoader.h"
#include "CCLuaEngine.h"
#include "URLData.h"

void URLLoader::load(const string& url)
{
	log("URLLoader::load: %s",url.c_str());
	HttpRequest* request = new HttpRequest();
	request->setUrl(url.c_str());
	/*char* postData = "a=1&b=2";
	request->setRequestData(postData,strlen(postData));*/
	request->setRequestType(HttpRequest::Type::GET);
	request->setResponseCallback(CC_CALLBACK_2(URLLoader::onHttpRequestCompleted,this));
	HttpClient::getInstance()->setTimeoutForConnect(3);
	HttpClient::getInstance()->setTimeoutForRead(10);
	HttpClient::getInstance()->send(request);
	request->release();
	//URLLoader::s_requestQueue->pushBack(this);
	this->retain();
}

void URLLoader::pushRequest(const string url)
{
	log("URLLoader::load: %s",url.c_str());
	_requestQueue.push_back(url);
}

void URLLoader::removeRequest(const string url)
{
	for(auto iter = _requestQueue.end();iter != _requestQueue.end();++iter)
	{
		if(url.find(*iter) != -1){
			_requestQueue.erase(iter);
			break;
		}
	}
}

void URLLoader::start()
{
	if(_requestQueue.size()==0)
	{
		_running = false;
		return;
	}
	_running = true;
	_isStop = false;
	
	auto iter = _requestQueue.begin();
	string url = *iter;
	_requestQueue.erase(iter);
	
	HttpRequest* request = new HttpRequest();
	request->setUrl(url.c_str());
	request->setRequestType(HttpRequest::Type::GET);
	request->setResponseCallback(CC_CALLBACK_2(URLLoader::onSingleHttpRequestCompleted,this));
	HttpClient::getInstance()->setTimeoutForConnect(3);
	HttpClient::getInstance()->setTimeoutForRead(10);
	HttpClient::getInstance()->send(request);
	request->release();
}

void URLLoader::stop()
{
	_isStop = true;
	_running = false;
	_requestQueue.clear();
}

void URLLoader::onSingleHttpRequestCompleted(HttpClient* sender,HttpResponse* response)
{
	if(_isStop){
		log("URLLoader::onSingleHttpRequestCompleted-stop");
		return;
	}
	const char* eventname = response->getHttpRequest()->getUrl();
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(eventname,response);

	if(_requestQueue.size()>0 && !_isStop)
	{
		this->start();
	}else{
		this->_running = false;
	}
}

void URLLoader::onHttpRequestCompleted(HttpClient* sender,HttpResponse* response)
{
	URLData data(-1,"");
	auto engine = cocos2d::LuaEngine::getInstance();
	cocos2d::BasicScriptData    scriptdata(this, &data);
	cocos2d::ScriptEvent    eve(kCallFuncEvent, &scriptdata);
	
	if(!response)
	{
		engine->sendEvent(&eve);
		this->release();
		return;
	}
	
	long statusCode = response->getResponseCode();
	data.setStatusCode((int)statusCode);
    char statusString[64] = {};
    sprintf(statusString, "HTTP Status Code: %ld, tag = %s", statusCode, response->getHttpRequest()->getTag());
    log("response code: %ld", statusCode);

	if(!response->isSucceed())
	{
		log("response failed");
        log("error buffer: %s", response->getErrorBuffer());
		data.setData(response->getErrorBuffer());
		engine->sendEvent(&eve);
		this->release();
        return;
	}
	vector<char> *buffer = response->getResponseData();
	 std::string temp(buffer->begin(),buffer->end());
	data.setData(temp);
	
	engine->sendEvent(&eve);
	this->release();
}

//cocos2d::Vector<Ref*>* URLLoader::s_requestQueue = new Vector<Ref*>();
URLLoader* URLLoader::create()
{
	auto loader = new URLLoader();
	loader->autorelease();
	return loader;
};

URLLoader* URLLoader::_instance = nullptr;
URLLoader* URLLoader::getInstance()
{
	if(_instance == nullptr){
		_instance = new URLLoader();
	}
	return _instance;
}

void URLLoader::destroyInstance()
{
	log("URLLoader::destroyInstance");
	//HttpClient::getInstance()->destroyInstance();
	this->stop();
	//URLLoader::s_requestQueue->clear();
};