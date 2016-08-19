//
//  TCPSocket.h
//  GameProject
//
//  Created by Foxuc on 13-2-26.
//
//

#ifndef __GameProject__TCPSocket__
#define __GameProject__TCPSocket__

#include "cocos2d.h"
#include "ODSocket.h"
#include "Packet.h"
#include "SpriteData.h"

#include <stdio.h>
#include <iostream>
#include <pthread.h>
#include <vector>

USING_NS_CC;
using namespace std;

#define DSOCKETTYPE_None            0       //无效类型
#define DSOCKETTYPE_Continued       1       //长连接
#define DSOCKETTYPE_Short           2       //短连接
#define DSOCKETTYPE_Temp            3       //待定

#define DSOCKET_OUTTIME				50

//线程接收函数
void *threadSocketRecv();

//MARK::内核消息
class TCPSocketDelegate : public Node
{
public:
    TCPSocketDelegate(){};
    virtual ~TCPSocketDelegate(){};
    
public:
    //消息处理
    virtual bool SocketDelegateWithRecvData(CSpriteData* pData)=0;		//加密消息
	virtual void SocketDelegateWithConnectNotfiy(bool isConnect)=0;     //连接通知
    virtual void SocketDelegateWithCloseNotify(){};                     //关闭通知
};

//socket使用
class CTCPSocket : public cocos2d::Ref
{
    //构造
public:
    CTCPSocket(TCPSocketDelegate* target);
    CTCPSocket();
    ~CTCPSocket();
    
    static CTCPSocket* create();
    
public:
    void initValue();
    void setSocketTarget(TCPSocketDelegate* target);
    
    //网络操作
public:
    bool socketConnect(const char *domain, WORD wPort);
    void socketClose();
    void socketCloseThread();
    
    bool socketRecv();
    bool socketSend(void* pData, WORD wSize, bool isEntry=false);
    void socketUpdate(float dt);
    void socketNotify(float dt);
    void socketFrameOver(float dt);
    
    //隐射数据
    bool mappedBuffer(void* pData, WORD wDataSize);
    
    //隐射数据
    bool unMappedBuffer(void* pData, WORD wDataSize);
    
    //多线程操作
public:
    void threadCreateConnect();
    void threadCreateRecv();
    void threadClosed();
    
public:
    void setEntry(bool isEntry) { m_bEntry=isEntry;}    //加密映射
    void setData(DataType dt)   { m_DataType=dt;}       //数据类型
    
    void setErrorNotify(bool bNotify) {m_bErrorNotify=bNotify;}
    bool getErrorNotify() {return m_bErrorNotify;}
    
    void setZeroData(bool bZero) {m_bZeroData=bZero;}
    bool getZeroData() {return m_bZeroData;}
    
    bool getEntry() {return m_bEntry;};
    DataType getData() {return m_DataType;}
    
    void setConnect(bool isConnect) {
		m_bConnect=isConnect;
	}
    bool getConnect();
    
    void ZeroBufferData();

	ssize_t getDataArraySize(){
		if(m_pDataArray!=nullptr){
			return m_pDataArray->size();
		}
		return 0;
	}
    
public:
    ODSocket                m_hSocket;                  //网络连接
    pthread_mutex_t         m_hMutext;                  //线程互斥锁
    
    bool                    m_bZeroData;                //清零数据 d:false
    bool                    m_bNextLogic;               //处理下一个包
private:
	bool                    m_bConnect;                 //连接状态 d:false

public:
	std::string				m_Address;
    WORD                    m_wPort;                    //连接端口
    
public:
    bool                    m_bEntry;                   //隐射标识 d:true
    DataType                m_DataType;                 //数据类型 d:load
    
public:
    //数据缓冲
    TCPSocketDelegate*      m_pTarget;                  //协议接口
    char                    m_pData[SOCKET_TCP_BUFFER]; //网络缓冲
    int                     m_nSize;                    //缓冲大小
    
public:
    bool                    m_bErrorNotify;             //错误通知 默认true；
	cocos2d::Vector<CSpriteData*>*			m_pDataArray;               //网络数据
    long                    m_lLastTime;                //连接时间
    bool                    m_bEnterBackground;         //进入后台标识
};




#endif /* defined(__GameProject__TCPSocket__) */
