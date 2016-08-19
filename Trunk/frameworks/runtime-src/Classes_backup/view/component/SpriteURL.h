#ifndef SPRITEURL_H_
#define SPRITEURL_H_

/**
	获取网络图片
**/

#include "cocos2d.h"
#include "network/HttpClient.h"
#include "URLData.h"

USING_NS_CC;
using namespace network;
using namespace std;

class SpriteURL:public Sprite
{
public:
	SpriteURL(std::string _path,std::string _defaultPath,std::string _userGameID);
	~SpriteURL();
	static SpriteURL*create(std::string _path,std::string _defaultPath,std::string _userGameID);
	void createStorgePath();		//创建图片保存路径
	void getHttpPic(cocos2d::Size size_);				//获取网络图片

	void saveURLPic(std::vector<char>*_data);				//将获取的图片保存下来

	//BUG,编译到安卓,需重写
	//virtual void setDisplayFrameWithAnimationName(const std::string& animationName, ssize_t frameIndex){};
    void getCachePath(Node *sender, Value data);
    
	
private:
	void onURLLoaderCompleted(EventCustom* event);
	void onHttpRequestCompleted(HttpClient *sender,HttpResponse *response);

	std::string m_path;				//网络图片地址
	std::string m_defaultPath;		//默认图片
	std::string _storagePath;		//存储路劲
	std::string m_picName;			//网络图片的名字
	std::string m_userGameID;    //玩家ID   用于保存图片名
    cocos2d::Size m_size;								//网络图片替换后的大小
};

#endif