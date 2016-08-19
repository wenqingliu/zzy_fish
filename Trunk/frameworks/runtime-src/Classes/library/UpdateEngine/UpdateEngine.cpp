#include "UpdateEngine.h"
#include "cocos2d.h"
#include <stdio.h>
#include <vector>
#include <thread>


#ifdef MINIZIP_FROM_SYSTEM
#include <minizip/unzip.h>
#else // from our embedded sources
#include "unzip/unzip.h"
#endif

#include <curl/curl.h>
#include <curl/easy.h>

#include "FilePath.h"
#include "CCLuaEngine.h"



#define TEMP_PACKAGE_FILE_NAME		"cocos2dx-update-temp-package.zip"

#define BUFFER_SIZE    8192
#define MAX_FILENAME   512

#define LOW_SPEED_LIMIT 1L
#define LOW_SPEED_TIME	5L

UpdateEngine::UpdateEngine()
:  _storagePath(""), _version(""), _curl(nullptr)
	, _delegate(nullptr), _isDownloading(false)
{
	_storagePath = FileUtils::getInstance()->getWritablePath() + "download/";
	auto b1 = createDirectory(_storagePath.c_str());//下载目录
	auto b2 = createDirectory((_storagePath + "src/").c_str());//代码目录
	auto b3 = createDirectory((_storagePath + "res/").c_str());//资源目录
	log("UpdateEngine()-createDirectory  _storagePath:%s,%d,%d,%d",_storagePath.c_str(),b1,b2,b3);
}

UpdateEngine::~UpdateEngine()
{
	_delegate = nullptr;
	log("~UpdateEngine");
}

static size_t getVersionCode(void *ptr, size_t size, size_t nmemb, void *userdata)
{
	string* version = (string*)userdata;
	version->append((char*)ptr, size * nmemb);
    return (size * nmemb);
}

void UpdateEngine::pushVersionQueue(string version,string zipUrl)
{
	_versionUrls.push_back(UpdateItem(version, "", zipUrl));
}

void UpdateEngine::pushZIP(string zipUrl)
{
	_versionUrls.push_back(UpdateItem("", "", zipUrl));
}

bool UpdateEngine::checkUpdate()
{
	if(_versionUrls.size() == 0){
		log("_versionUrls.size() = 0");
		return false;
	}

    _curl = curl_easy_init();
    if (!_curl)
    {
        log("can not init curl");
        return false;
    } 
    _version.clear();
    
	//设置下载目录，不存在则创建目录
	_downloadPath = FileUtils::getInstance()->getWritablePath();
	_downloadPath += "download_temp/";
	auto b = createDirectory(_downloadPath.c_str());
	log("UpdateEngine::checkUpdate-%s,%d",_downloadPath.c_str(),b);

    return true;
}

void UpdateEngine::downloadAndUncompress()
{
    while(_versionUrls.size() > 0)
    {
		//取出当前第一个需要下载的url
		UpdateItem item = _versionUrls.front();
		_packageUrl = item.zipUrl;
		_version = item.version;
		log("downloadAndUncompress-0:size:%d, _version:%s, _packageUrl:%s",_versionUrls.size(),_version.c_str(),_packageUrl.c_str());
		//通知文件下载
		std::string zipUrl = item.zipUrl;
		Director::getInstance()->getScheduler()->performFunctionInCocosThread([&, this, zipUrl]{
			if (this->_delegate)
				this->_delegate->onDownload(_version,zipUrl);
		});

		//开始下载，下载失败退出
		if (!downLoad())
		{
			Director::getInstance()->getScheduler()->performFunctionInCocosThread([&, this]{
				if (this->_delegate)
					this->_delegate->onError(ErrorCode::UNDOWNED);
			});
			break;
		}

		//通知文件压缩
		Director::getInstance()->getScheduler()->performFunctionInCocosThread([&, this, zipUrl]{
			if (this->_delegate)
				this->_delegate->onUncompress(zipUrl);
		});
		
		//解压下载的zip文件
		string outFileName = _downloadPath + TEMP_PACKAGE_FILE_NAME;
        if (!uncompress(outFileName))
        {
			log("uncompress-UNCOMPRESS");
            Director::getInstance()->getScheduler()->performFunctionInCocosThread([&, this]{
				if (this->_delegate)
					this->_delegate->onError(ErrorCode::UNCOMPRESS);
			});
            break;
        }
		log("uncompress-success");

		//解压成功，任务出队列，写本地版本号
		_versionUrls.pop_front();
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([&, this]{
			//写本地版本号
			if(_version.length() != 0){
				UserDefault::getInstance()->setStringForKey("current-version-code", _version);
				UserDefault::getInstance()->flush();
			}else{
				log("_version.length() is 0");
			}
			if(_versionUrls.size() == 0){
				//删除本次下载的文件
				string zipfileName = this->_downloadPath + TEMP_PACKAGE_FILE_NAME;
				if (remove(zipfileName.c_str()) != 0)
				{
					log("can not remove downloaded zip file %s", zipfileName.c_str());
				}else{
					log("remove downloaded zip file %s", zipfileName.c_str());
				}
			}
			//如果更新任务已经完成，通知更新成功
			if(this->_delegate)
				this->_delegate->onSuccess();
		}); 
    }
	curl_easy_cleanup(_curl);
    _isDownloading = false;
	log("downloadAndUncompress-end");
}

void UpdateEngine::update()
{
    if (_isDownloading) return;

    _isDownloading = true;
    /*if (_versionFileUrl.size() == 0)
    {
        log("no version file url");
        _isDownloading = false;
        return;
    }*/
	//检查是否有新版本下载，如果有整理更新任务
    if (!checkUpdate())
    {
        _isDownloading = false;
		curl_easy_cleanup(_curl);
        return;
    }
	//开始下载任务
    auto t = std::thread(&UpdateEngine::downloadAndUncompress, this);
    t.detach();
}

bool UpdateEngine::uncompress(string outFileName)
{
	// Open the zip file
    //string outFileName = _storagePath + TEMP_PACKAGE_FILE_NAME;
	bool b0 = FileUtils::getInstance()->isFileExist(outFileName.c_str());
    unzFile zipfile = unzOpen(outFileName.c_str());
    if (! zipfile)
    {
        log("can not open downloaded zip file %s %d", outFileName.c_str(),b0);
        return false;
    }
    
    // Get info about the zip file
    unz_global_info global_info;
    if (unzGetGlobalInfo(zipfile, &global_info) != UNZ_OK)
    {
        log("can not read file global info of %s", outFileName.c_str());
        unzClose(zipfile);
        return false;
    }
    
    // Buffer to hold data read from the zip file
    char readBuffer[BUFFER_SIZE];
    
    log("start uncompressing");
    
    // Loop to extract all files.
    uLong i;
    for (i = 0; i < global_info.number_entry; ++i)
    {
        // Get info about current file.
        unz_file_info fileInfo;
        char fileName[MAX_FILENAME];
        if (unzGetCurrentFileInfo(zipfile,
                                  &fileInfo,
                                  fileName,
                                  MAX_FILENAME,
                                  nullptr,
                                  0,
                                  nullptr,
                                  0) != UNZ_OK)
        {
            log("can not read file info");
            unzClose(zipfile);
            return false;
        }
        
        const string fullPath = _storagePath + fileName;
        
        // Check if this entry is a directory or a file.
        const size_t filenameLength = strlen(fileName);
        if (fileName[filenameLength-1] == '/')
        {
            // Entry is a direcotry, so create it.
            // If the directory exists, it will failed scilently.
            if (!createDirectory(fullPath.c_str()))
            {
                log("can not create directory-1 %s", fullPath.c_str());
                unzClose(zipfile);
                return false;
            }
        }
        else
        {
            //There are not directory entry in some case.
            //So we need to test whether the file directory exists when uncompressing file entry
            //, if does not exist then create directory
            const string fileNameStr(fileName);
            
            size_t startIndex=0;
            
            size_t index=fileNameStr.find("/",startIndex);
            
            while(index != std::string::npos)
            {
                const string dir=_storagePath+fileNameStr.substr(0,index);
                
                FILE *out = fopen(dir.c_str(), "r");
                
                if(!out)
                {
                    if (!createDirectory(dir.c_str()))
                    {
                        log("can not create directory-2 %s", dir.c_str());
                        unzClose(zipfile);
                        return false;
                    }
                    else
                    {
                        log("create directory %s",dir.c_str());
                    }
                }
                else
                {
                    fclose(out);
                }
                
                startIndex=index+1;
                
                index=fileNameStr.find("/",startIndex);
                
            }
            
            
            
            // Entry is a file, so extract it.
            
            // Open current file.
            if (unzOpenCurrentFile(zipfile) != UNZ_OK)
            {
                log("can not open file %s", fileName);
                unzClose(zipfile);
                return false;
            }
            
            // Create a file to store current file.
            FILE *out = fopen(fullPath.c_str(), "wb");
            if (! out)
            {
                log("can not open destination file %s", fullPath.c_str());
                unzCloseCurrentFile(zipfile);
                unzClose(zipfile);
                return false;
            }
            
            // Write current file content to destinate file.
            int error = UNZ_OK;
            do
            {
                error = unzReadCurrentFile(zipfile, readBuffer, BUFFER_SIZE);
                if (error < 0)
                {
                    log("can not read zip file %s, error code is %d", fileName, error);
                    unzCloseCurrentFile(zipfile);
                    unzClose(zipfile);
                    return false;
                }
                
                if (error > 0)
                {
                    fwrite(readBuffer, error, 1, out);
                }
            } while(error > 0);
            
            fclose(out);
        }
        
        unzCloseCurrentFile(zipfile);
        
        // Goto next entry listed in the zip file.
        if ((i+1) < global_info.number_entry)
        {
            if (unzGoToNextFile(zipfile) != UNZ_OK)
            {
                log("can not read next file");
                unzClose(zipfile);
                return false;
            }
        }
    }
    
    log("end uncompressing");
    unzClose(zipfile);
    
    return true;
}

static size_t downLoadPackage(void *ptr, size_t size, size_t nmemb, void *userdata)
{
    FILE *fp = (FILE*)userdata;
    size_t written = fwrite(ptr, size, nmemb, fp);
    return written;
}

int updateProgressFunc(void *ptr, double totalToDownload, double nowDownloaded, double totalToUpLoad, double nowUpLoaded)
{
    static int percent = 0;
    int tmp = (int)(nowDownloaded / totalToDownload * 100);    
    if (percent != tmp)
    {
        percent = tmp;
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([=]{
			auto manager = static_cast<UpdateEngine*>(ptr);
			if (manager->_delegate)
				manager->_delegate->onProgress(percent);
		});  
        log("downloading... %d%%", percent);
    }    
    return 0;
}

bool UpdateEngine::downLoad()
{
    //创建临时存放的zip文件
    const string outFileName = _downloadPath + TEMP_PACKAGE_FILE_NAME;
    FILE* fp = fopen(outFileName.c_str(), "wb");
    if (!fp)
    {
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([&, this]{
			if (this->_delegate)
				this->_delegate->onError(ErrorCode::CREATE_FILE);
		});
        log("can not create temp zip file %s", outFileName.c_str());
        return false;
    }

    //开始从服务器下载
    CURLcode res;
    curl_easy_setopt(_curl, CURLOPT_URL, _packageUrl.c_str());
    curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, downLoadPackage);
    curl_easy_setopt(_curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(_curl, CURLOPT_NOPROGRESS, false);
    curl_easy_setopt(_curl, CURLOPT_PROGRESSFUNCTION, updateProgressFunc);
    curl_easy_setopt(_curl, CURLOPT_PROGRESSDATA, this);
    curl_easy_setopt(_curl, CURLOPT_NOSIGNAL, 1L);
    curl_easy_setopt(_curl, CURLOPT_LOW_SPEED_LIMIT, LOW_SPEED_LIMIT);
    curl_easy_setopt(_curl, CURLOPT_LOW_SPEED_TIME, LOW_SPEED_TIME);

    res = curl_easy_perform(_curl);
    if (res != 0)
    {
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([&, this]{
			if (this->_delegate)
				this->_delegate->onError(ErrorCode::NETWORK);
		});
		log("error when download package %s", _packageUrl.c_str());
        fclose(fp);
        return false;
    }
    log("succeed downloading package %s", _packageUrl.c_str());    
    fclose(fp);
    return true;
}

int UpdateEngine::getVersion()
{
	string verision = UserDefault::getInstance()->getStringForKey("current-version-code","1.0.0");
	if (verision.size() > 0)
	{
		return atoi(verision.c_str());
	}
	return 0;
}

void UpdateEngineDelegate::onProgress(int percent, int type /* = 1 */)
{
	log("UpdateEngineDelegate::onProgress-%d,%d",percent,type);
	CNotify* notify = CNotify::create();
	notify->setMainType(0);
	notify->setSubType(percent);
	sendEvent(notify);
}

void UpdateEngineDelegate::onSuccess() 
{
	CNotify* notify = CNotify::create();
	notify->setMainType(1);
	sendEvent(notify);
}

void UpdateEngineDelegate::onDownload(string version,string packUrl) 
{
	CNotify* notify = CNotify::create();
	notify->setMainType(2);
	notify->m_MainString = version;
	notify->m_SubString	= packUrl;
	sendEvent(notify);
}

void UpdateEngineDelegate::onUncompress(string packUrl) 
{
	CNotify* notify = CNotify::create();
	notify->setMainType(3);
	notify->m_MainString = packUrl;
	sendEvent(notify);
}

void UpdateEngineDelegate::onError(ErrorCode errorCode) 
{
	CNotify* notify = CNotify::create();
	notify->setMainType(4);
	notify->setSubType(errorCode);
	sendEvent(notify);
}

void UpdateEngineDelegate::sendEvent(CNotify* notify)
{
	LuaEngine* engine = LuaEngine::getInstance();
	BasicScriptData scriptdata(this,notify);
	cocos2d::ScriptEvent eve(kCallFuncEvent, &scriptdata);
	engine->sendEvent(&eve);
}