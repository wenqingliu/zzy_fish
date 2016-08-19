

//
//  SocketData.cpp
//  YQYGameProject
//
//  Created by 曾 亚东 on 13-5-21.
//
//

#include "SpriteData.h"
#include "cocos-ext.h"
USING_NS_CC_EXT;

CSpriteData::CSpriteData(const c_char* pData, WORD wSize, DataType dt)
{
	m_wMainCmdID = 0;
	m_wSubCmdID=0;
    m_wSize = wSize;
    m_pData = new char[wSize+1];
    m_DataType=dt;

	memset(m_pData, 0, sizeof(c_char)*(wSize+1));
	memcpy(m_pData, pData, wSize);
}
CSpriteData::CSpriteData(WORD wMainCmdID, WORD wSubCmdID,const c_char* pData, WORD wSize)
{
    m_DataType=Data_Default;
    
    m_wMainCmdID=wMainCmdID;
    m_wSubCmdID=wSubCmdID;
    m_wSize=wSize;
    m_pData=new char[wSize+1];
    
    memset(m_pData, 0, sizeof(c_char)*(wSize+1));
    memcpy(m_pData, pData, sizeof(c_char)*wSize);
}


CSpriteData::CSpriteData(CSpriteData *pData)
{
    m_wSize = pData->getSize();
    m_pData = new char[m_wSize+1];
    
    memset(m_pData, 0, sizeof(char)*(m_wSize+1));
    memcpy(m_pData, pData->m_pData, m_wSize);
    
    m_DataType=pData->getType();
}


CSpriteData::~CSpriteData()
{
    CC_SAFE_DELETE_ARRAY(m_pData);
}

CSpriteData* CSpriteData::socketData(const char* pData, WORD wSize, DataType dt)
{
    CSpriteData* socketData = new CSpriteData(pData, wSize, dt);
	//socketData->autorelease();
    return socketData;
}
CSpriteData* CSpriteData::socketData(WORD wMainCmdID, WORD wSubCmdID,const c_char* pData, WORD wSize)
{
    CSpriteData* socketData=new CSpriteData(wMainCmdID, wSubCmdID, pData, wSize);
	//socketData->autorelease();
    return socketData;
}


CSpriteData* CSpriteData::spriteData(WORD wMainCmdID, WORD wSubCmdID,const c_char* pData, WORD wSize)
{
	CSpriteData* socketData=CSpriteData::socketData(wMainCmdID, wSubCmdID, pData, wSize);
	socketData->autorelease();
	return socketData;
}
CSpriteData* CSpriteData::spriteData(const char* pData, WORD wSize, DataType dt)
{
	CSpriteData* socketData=new CSpriteData(pData, wSize, dt);
	socketData->autorelease();
	return socketData;
}
//
//CSpriteData* CSpriteData::spriteData(const c_char* pData, Ref* pObject)
//{
//	CSpriteData* socketData=new CSpriteData(pData, strlen(pData), Data_Default);
//	socketData->setObject(pObject);
//	socketData->autorelease();
//	return socketData;
//}


















