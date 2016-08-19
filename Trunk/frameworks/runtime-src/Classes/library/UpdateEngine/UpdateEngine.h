#ifndef __UpdateEngine__
#define __UpdateEngine__
#include <string>
#include <mutex>

#include "cocos2d.h"
#include "protocol.h"
#include "JT_Macro.h"

USING_NS_CC;

using namespace std;

enum ErrorCode
{
	NETWORK,
	CREATE_FILE,
	NO_NEW_VERSION,
	UNDOWNED,
	UNCOMPRESS,
};

class UpdateEngineDelegate : public Ref
{

public:

	JT_CREATE_FUNC(UpdateEngineDelegate);

	void onDownload(string _version,std::string packUrl);
	void onUncompress(std::string packUrl);
	void onError(ErrorCode errorCode);
	void onProgress(int percent, int type = 1);	
	void onSuccess();
	void sendEvent(CNotify* notify);
};

class UpdateEngine : public cocos2d::Node
{
public:
	struct UpdateItem
	{
		std::string version;
		std::string zipPath;
		std::string zipUrl;

		UpdateItem(std::string v, std::string p, std::string u) : version(v), zipPath(p), zipUrl(u) {}
	};
    
    UpdateEngine();
    virtual ~UpdateEngine();

	JT_CREATE_FUNC(UpdateEngine);

	//添加下载版本队列
	void pushVersionQueue(string version,string zipUrl);
	void pushZIP(string zipUrl);

	//读取服务器版本号信息
    virtual bool checkUpdate();
    
    virtual void update();

    void setDelegate(UpdateEngineDelegate *delegate) { _delegate = delegate; }
    
    UpdateEngineDelegate* getDelegate() const { return _delegate ;}  

	friend int updateProgressFunc(void *ptr, double totalToDownload, double nowDownloaded, double totalToUpLoad, double nowUpLoaded);

protected:
	int getVersion();
    bool downLoad();
	bool uncompress(std::string outFileName);
	void downloadAndUncompress();

    void setSearchPath();
    
private:
    std::string _version;    
	std::string _packageUrl;
	std::string _storagePath;      
	std::string _downloadPath;

	std::deque<UpdateItem> _versionUrls;
    
    void *_curl;    
	bool _isDownloading;
	UpdateEngineDelegate *_delegate; 

	void sendEvent(CNotify* notify);
};

#endif
