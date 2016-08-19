//
//  SocketData.h
//  YQYGameProject
//
//  Created by 曾 亚东 on 13-5-21.
//
//

#ifndef __YQYGameProject__SocketData__
#define __YQYGameProject__SocketData__

#include <iostream>
#include "cocos2d.h"
#include "SpriteDefine.h"

USING_NS_CC;


class CSpriteData : public Ref
{
public:
    CSpriteData(CSpriteData *pData);
    CSpriteData(const c_char* pData, WORD wSize, DataType dt=Data_Load);
    CSpriteData(WORD wMainCmdID, WORD wSubCmdID,const c_char* pData, WORD wSize);
    ~CSpriteData();

public:
	
	static CSpriteData* socketData(const char* pData, WORD wSize, DataType dt=Data_Load);
    static CSpriteData* socketData(WORD wMainCmdID, WORD wSubCmdID,const c_char* pData, WORD wSize);

	static CSpriteData* spriteData(WORD wMainCmdID, WORD wSubCmdID,const c_char* pData, WORD wSize);
	static CSpriteData* spriteData(const char* pData, WORD wSize, DataType dt=Data_Load);
	//static CSpriteData* spriteData(const c_char* pData, Ref* pObject);
    
public:
	char*       getData()const   {return m_pData;}
    WORD        getSize()   {return m_wSize;}
    DataType    getType()   {return m_DataType;}
    //Ref*   getObject() {return m_pObject;};
	void*	getBuffer(){return m_buffer;};
    
    WORD getMainCmdID() {return m_wMainCmdID;}
    WORD getSubCmdID()  {return m_wSubCmdID;}

	void setMainCmdID(WORD value) {this->m_wMainCmdID = value;}
    void setSubCmdID(WORD value)  {this->m_wSubCmdID = value;}
    
public:
    //void setObject(Ref* object) {m_pObject=object;}
    //void setType(DataType dataType) {m_DataType=dataType;}
    
public:
    DataType        m_DataType;             //数据类型
    
    WORD            m_wMainCmdID;           //主命令码
    WORD            m_wSubCmdID;            //子命令码

    
public:
    WORD            m_wSize;                //数据大小
    char*           m_pData;                //数据内容
	void*			m_buffer;				//数据缓存
    //Ref*       m_pObject;              //扩展指针
};


#endif
