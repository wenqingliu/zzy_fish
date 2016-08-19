#include "SpriteURL.h"
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32) && (CC_TARGET_PLATFORM != CC_PLATFORM_WP8) && (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT)
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#endif
using namespace network;
#include "cocos-ext.h"
#include "protocol.h"
#include "SpriteDefine.h"
#include "URLLoader.h"

USING_NS_CC_EXT;

SpriteURL::SpriteURL(std::string _path,std::string _defaultPath,std::string _userGameID)
	:m_path(_path),
	m_defaultPath(_defaultPath),
	m_userGameID(_userGameID),
	_storagePath("/sdcard/NiuPic/"),
	m_picName("")
{
	
}

void SpriteURL::getCachePath(Node *sender, Value data)
{
    if (!data.isNull() && data.getType() == Value::Type::MAP) {
        ValueMap valueMap = data.asValueMap();
        _storagePath = valueMap["cachepath"].asString();
    }
}

SpriteURL::~SpriteURL()
{
	Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(m_path.c_str());
	//URLLoader::getInstance()->stop();
}

SpriteURL*SpriteURL::create(std::string _path,std::string _defaultPath,std::string _userGameID)
{
	//_path = "http://cdn.cocimg.com/bbs/images/post/smile/default/1.gif";
	SpriteURL * sp = new SpriteURL(_path,_defaultPath,_userGameID);
	if (sp && sp->initWithFile(_defaultPath))
	{
		sp->autorelease();
		return sp;
	}
	CC_SAFE_DELETE(sp);
	return nullptr;
}
void SpriteURL::getHttpPic(cocos2d::Size size_)
{
	m_size = size_;
	createStorgePath();
	auto yy = m_path.find("http://q.qlogo.cn/qqapp/");
	auto yyyy = std::string::npos;
	if (m_path.find("http://q.qlogo.cn/qqapp/") != std::string::npos)					//QQ
	{
		m_picName =m_userGameID + ".png";
	}else if (m_path.find("http://wx.qlogo.cn/mmopen/") != std::string::npos)																					//Œ¢–≈
	{
		m_picName =m_userGameID + ".png";
	}else if (m_path.find("http://tp2.sinaimg.cn/")  != std::string::npos)																					//–¬¿À
	{
		m_picName =m_userGameID + ".png";
	}else
	{
		int posLast = m_path.find_last_of('.');
		//≈–∂œ◊Ó∫Û√Ê «∑Ò «.png ªÚ.jpgΩ·Œ≤
		if (m_path.find_last_of('.')  == std::string::npos)
		{
			log("URL wrong!!!");
			return;
		}else{
			std::string lastStr = m_path.substr(posLast+1);
			if(strcmp(lastStr.c_str(),"png") && strcmp(lastStr.c_str(),"jpg"))
			{
				log("url pic is not .png or jpg");
				return;
			}
		}
			int pos = m_path.find_last_of('/');
			if (m_path.find_last_of('/')  == std::string::npos)
			{
				return;
			}

			m_picName = m_path.substr(pos+1);
			if (strcmp(m_picName.c_str(),"mm.png") == 0 || strcmp(m_picName.c_str(),"gg.png") == 0 || strcmp(m_picName.c_str(),"mm.jpg") == 0 || strcmp(m_picName.c_str(),"gg.jpg") == 0)
			{
				//m_picName =m_userGameID + ".png";
				log("img is mm.png or gg.png");
				return;
			}
	}

	if (FileUtils::getInstance()->isFileExist(_storagePath + m_picName))			//±æµÿ «∑Ò¥Ê‘⁄’‚’≈Õº∆¨
	{
		log("file is isFileExist!!");
		bool v = this->initWithFile(_storagePath + m_picName);
		this->setScaleX(m_size.width/this->getContentSize().width);
	    this->setScaleY(m_size.height/this->getContentSize().height);

		return;
	}

	Director::getInstance()->getEventDispatcher()->addCustomEventListener(m_path.c_str(),CC_CALLBACK_1(SpriteURL::onURLLoaderCompleted,this));
	auto loader = URLLoader::getInstance();
	loader->pushRequest(m_path.c_str());
	if(!loader->getRunning())
	{
		loader->start();
	}
}

void SpriteURL::onURLLoaderCompleted(EventCustom* event)
{
	HttpResponse* response = (HttpResponse*)event->getUserData();
	if(!event->getUserData() || !response->isSucceed() || response->getResponseCode() != 200)
	{
		return;
	}

	vector<char> *buffer = response->getResponseData();
	auto img = new Image();
    img->autorelease();
    auto b1 = img->initWithImageData((const unsigned char *)buffer->data(), buffer->size());
	if(b1){
		Texture2D * texture_ = new Texture2D();
		texture_->autorelease();
		texture_->initWithImage(img);
		this->initWithTexture(texture_);
		this->setScaleX(m_size.width/this->getContentSize().width);
		this->setScaleY(m_size.height/this->getContentSize().height);
		saveURLPic(buffer);//存到本地

		log("SpriteURL::onHttpRequestCompleted saveURLPic succeed:%s",m_path.c_str());
	}else{
		log("SpriteURL::onHttpRequestCompleted saveURLPic failed:%s",m_path.c_str());
	}
}

void SpriteURL::createStorgePath()
{
	log("create start");
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		_storagePath = "C:/NiuPic/";
		if ((GetFileAttributesA(_storagePath.c_str())) == INVALID_FILE_ATTRIBUTES)
		{
			CreateDirectoryA(_storagePath.c_str(), 0);
		}
	#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		_storagePath = "/sdcard/NiuPic/";
		DIR *dir = nullptr;
		dir = opendir (_storagePath.c_str());
		if (!dir)
		{
			log("mkdir");
			mkdir(_storagePath.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
		}else{
			log("closedir");
			closedir(dir); 
		}
	#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		CNotify *pNotify = CreateNotify(0);
		pNotify->setMainType(1);
		GetNotificationCenter()->postNotification(ccNd_PlatFormNotify, pNotify);
		_storagePath = pNotify->m_MainString.c_str();
		log("复制后的路径:%s", _storagePath.c_str());
	#endif
	log("create end");
}

void SpriteURL::saveURLPic(std::vector<char>*_data)
{
	if (_data->size() <= 0)
	{
		log("SpriteURL::saveURLPic-date size <= 0!!!!");
		return;
	}

    log("SpriteURL::saveURLPic-路径:%s,%s", _storagePath.c_str(),m_picName.c_str());
    if (std::strlen(_storagePath.c_str()) == 0 || std::strlen(m_picName.c_str()) == 0) {
        return;
    }
    std::string fullFile = _storagePath + m_picName;
    FILE * file_ = NULL;
    file_ = fopen(fullFile.c_str(),"wb+");
	if(file_){
		fwrite(_data->data(),_data->size(),1,file_);
 		fclose(file_);
	}
}