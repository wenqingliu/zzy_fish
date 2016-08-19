//
//  TCPSocket.cpp
//  GameProject
//
//  Created by Foxuc on 13-2-26.
//
//

#include "TCPSocket.h"
//#include "FrameManager.h"


#ifdef WIN32
	#include <winsock.h>
	typedef int				socklen_t;
#else
	#include <sys/socket.h>
	#include <sys/ioctl.h>
	#include <netinet/in.h>
	#include <netdb.h>
	#include <fcntl.h>
	#include "errno.h"
	#include <unistd.h>
	#include <sys/stat.h>
	#include <sys/types.h>
	#include <arpa/inet.h>
#endif


#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    #include <net/if.h>
    #include <ifaddrs.h>
    #include <string.h>
#endif

//线程接收函数
void *threadSocketRecv(void* param)
{
    //接收消息
    CTCPSocket* socket=(CTCPSocket*)param;
    socket->retain();
    
    while(socket->getConnect())
    {
        if(!socket)
            break;
        
        if(!socket->socketRecv())
            break;

#ifdef WIN32
        Sleep(1.0/60.0f);
#else
        usleep(16);
#endif // _DEBUG
	}

    //释放socket
    socket->release();
    
    return 0;
}

void *threadScoketConnect(void* param)
{
    //接收消息
    CTCPSocket* socket=(CTCPSocket*)param;
    
    socket->m_hSocket.Init();
    socket->m_hSocket.Create(AF_INET, SOCK_STREAM);
    
    //连接成功
    if(socket->m_hSocket.Connect(socket->m_Address.c_str(), socket->m_wPort))
    {
        //创建接收线程
        socket->threadCreateRecv();
    }
    
    //连接通知
	Director::getInstance()->getScheduler()->scheduleSelector(schedule_selector(CTCPSocket::socketNotify), socket, 1.0f/60.0f, false, 0, false);

    return 0;
}


CTCPSocket* CTCPSocket::create()
{
    CTCPSocket* socket = new CTCPSocket;
    socket->autorelease();  
    return socket;
}

CTCPSocket::CTCPSocket()
{
    this->initValue();
}

CTCPSocket::CTCPSocket(TCPSocketDelegate* target)
{
    this->initValue();
    this->setSocketTarget(target);
}

static cocos2d::Vector<CTCPSocket*>* sockerArr = new cocos2d::Vector<CTCPSocket*>();
void CTCPSocket::initValue()
{
    m_hSocket  = 0;
    m_pTarget  = NULL;
    m_bEntry   = true;
    m_bConnect = false;
    m_DataType = Data_Load;
    m_bNextLogic = true;
    m_bZeroData = false;
    m_bErrorNotify = true;
    m_bZeroData = false;
    
    m_nSize = 0;
    m_lLastTime=0;
    
    memset(m_pData, 0, sizeof(m_pData));
	
    m_pDataArray = new cocos2d::Vector<CSpriteData*>();

	for(int i=sockerArr->size()-1;i>=0;i--)
    {
        auto socket = sockerArr->at(i);
        if(socket->getReferenceCount() == 1)
        {
            sockerArr->erase(i);
        }
    }
    sockerArr->pushBack(this);
}

CTCPSocket::~CTCPSocket()
{
	log("~CTCPSocket-1:%p, this_thread-id:%p",this,std::this_thread::get_id());
    setSocketTarget(NULL);
    ZeroBufferData();
	//socketFrameOver(0);
   
	CC_SAFE_DELETE(m_pDataArray);

    log("~CTCPSocket-2::%p",this);
}
void CTCPSocket::setSocketTarget(TCPSocketDelegate* target)
{
    if(target)
    {
        m_nSize=0;
        memset(m_pData, 0, sizeof(m_pData));
        
        m_pTarget = dynamic_cast<TCPSocketDelegate*>(target);
        m_pTarget->retain();
    }
    else
    {
        m_pTarget->release();
        m_pTarget=NULL;
    }
}


bool CTCPSocket::socketConnect(const char *domain, WORD wPort)
{
    //设置数据
	m_Address.clear();
    m_Address = domain;
    m_wPort = wPort;
    
    //当前连接时间
    m_lLastTime = YYSystemSecond();

	//避免在多线程中类被释放
	//this->retain();
    
    //创建连接
    threadCreateConnect();
    return true;
}

//关闭socket
void CTCPSocket::socketClose()
{
	log("CTCPSocket::socketClose-1:%p, this_thread-id:%p",this,std::this_thread::get_id());
    if(m_hSocket && m_pTarget)
    {
        //关闭连接
        m_pTarget->SocketDelegateWithCloseNotify();
		log("CTCPSocket::socketClose-m_pTarget");
        m_hSocket.Close();

        //reset
        threadClosed();
        
        //标识
        m_bConnect=false;
        m_hSocket=NULL;
    
        //reset
        m_nSize=0;
        memset(m_pData, 0, sizeof(m_pData));
        
        socketFrameOver(0.0f);
		
        log("CTCPSocket::socketClose-2:%p",this); 
		//线程数据等清理完毕,释放本类
		//this->release();
    }
}

//关闭线程
void CTCPSocket::socketCloseThread()
{
    //reset
    threadClosed();
    
    //标识
    m_bConnect=false;
}

//消息接收
bool CTCPSocket::socketRecv()
{
    int nSize=m_hSocket.Recv(m_pData+m_nSize, SOCKET_TCP_BUFFER-m_nSize);
    
    log("消息接收CTCPSocket: RecvSize: %d", nSize);
    
    //断开设置
    if (nSize==-1 || nSize==0 || !m_bConnect)
	{
		//关闭线程
        socketCloseThread();
        log("CTCPSocket: closeRecv");
		return false;
	}
    
    m_nSize += nSize;
    m_lLastTime = YYSystemSecond();
    
    //wh协议映射
    if(m_bEntry)
    {
        while ( m_nSize>=sizeof(TCP_Head) )
        {
            //取出前8字节数据
            char headChar[8];
            memset(headChar,0,sizeof(headChar));
            memcpy(headChar,m_pData,8);
            
            //取的数据长度
            TCP_Head* head = (TCP_Head*)headChar;
            WORD wCurSize = head->TCPInfo.wPacketSize;
            
            //长度效验，小于包头 或者 大于当前数据总长度,说明只接收了一半数据，跳出处理
            if( wCurSize<sizeof(TCP_Head) || wCurSize>m_nSize){
                break;
            }
            
            //取的当前长度 开始处理
            char curBuffer[SOCKET_TCP_PACKET];
            
            memset(curBuffer,0,sizeof(curBuffer));
            memcpy(curBuffer,m_pData,wCurSize);
            
            //数据映射
            if( !unMappedBuffer(curBuffer,wCurSize)){
                log("CTCPSocket: unMapped Error");
                break;
            }

            //添加数据
            pthread_mutex_lock(&m_hMutext);
            if(m_pDataArray)
            {
                CSpriteData* pSpriteData = CSpriteData::socketData(curBuffer, wCurSize, m_DataType);
				//pSpriteData->retain();
                m_pDataArray->pushBack(pSpriteData);
            }
			pthread_mutex_unlock(&m_hMutext);
            
            //减去已处理长度
            m_nSize -= wCurSize;
            
            //数据移动
            memmove(m_pData, m_pData+wCurSize, m_nSize);
            
            //跳出判断
            if( m_nSize<sizeof(TCP_Head) )
            {
                break;
            }
        }
    }
    
    //其他映射
    else
    {
        //添加数据
        pthread_mutex_lock(&m_hMutext);
        
        if(m_pDataArray)
		{
			CSpriteData* pData = CSpriteData::socketData(m_pData, m_nSize, m_DataType);
			//pData->retain();
            m_pDataArray->pushBack(pData);
		}
        pthread_mutex_unlock(&m_hMutext);
    }
    
    return true;
}

void CTCPSocket::socketFrameOver(float dt)
{
    //关闭循环
	log("CTCPSocket::socketFrameOver:%p",this);
	Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
}

void CTCPSocket::socketNotify(float dt)
{
    //连接成功
    if(m_bConnect)
    {
        m_pTarget->SocketDelegateWithConnectNotfiy(true);
    }
    
	//连接失败
	else
	{
		m_pTarget->SocketDelegateWithConnectNotfiy(false);
    }
}

void CTCPSocket::socketUpdate(float dt)
{
	//log("CTCPSocket::socketUpdate-%d",dt);
	//网络断开
	if(!m_bConnect)
    {
        //不清零 & 没有数据 = 关闭
        if(!m_bZeroData && !m_pDataArray->size())
        {
			log("CTCPSocket::socketUpdate-1: m_bZeroData:%d,m_pDataArray->size():%d",m_bZeroData,m_pDataArray->size());
            socketClose();    
            return;
        }
        //清零数据=直接关闭
        if(m_bZeroData)
        {
			log("CTCPSocket::socketUpdate-2:%d",m_bZeroData);
            socketClose();
            return;
        }
	}
    //不处理下一个包
    if(!m_bNextLogic)
        return;
    //处理消息
    pthread_mutex_lock(&m_hMutext);
    if(m_pDataArray && m_pDataArray->size())
    {
        //解密完的数据发送到大厅做分类处理
        if(m_pTarget)
        {
			CSpriteData* pData=*m_pDataArray->begin();
			if(pData->getType()==Data_Send)
            {
                if(m_bConnect)//
                {
                    socketSend(pData->getData(), pData->getSize(), true);
					if (pData->getReferenceCount()>1){
						pData->release();
					}
                    m_pDataArray->erase(m_pDataArray->begin());
					//m_pDataArray->begin() = it;
					//pData->release();
                }
            }
            else
            {
                m_pTarget->SocketDelegateWithRecvData(pData);//代理回调
                
                if(m_pDataArray->size()>0)
				{
					if (pData->getReferenceCount()>1){
						pData->release();
					}
                    auto it = m_pDataArray->erase(m_pDataArray->begin());
					//m_pDataArray->begin() = it;
					//pData->release();
				}
            }
        }
    }
    pthread_mutex_unlock(&m_hMutext);
}

bool CTCPSocket::socketSend(void* pData, WORD wSize, bool isEntry)
{
    //数据映射
    if(!isEntry)
        mappedBuffer(pData, wSize);
    
    //已连接，直接发送
    if(m_bConnect)
    {
        log("CTCPSocket:socketSend-succeed:%p",this);
        int count=m_hSocket.Send((char*)pData, wSize);
        if(count>0 && count<=wSize)
        {
            log("CTCPSocket: sendSize:%d", count);
        }
        else
            log("CTCPSocket:socketSend-Failure");
    }
    else
    {
		CSpriteData* spriteData = CSpriteData::spriteData((char*)pData, wSize, Data_Send);
		//spriteData->retain();
        m_pDataArray->pushBack(spriteData);
    }
    
    return true;
}

//隐射数据
bool CTCPSocket::mappedBuffer(void* pData, WORD wDataSize)
{
	//变量定义
	BYTE *buffer	 = (BYTE*)pData;
	BYTE cbCheckCode = 0;
	
	//映射数据
	for(WORD i=sizeof(TCP_Info);i<wDataSize;i++)
	{
		cbCheckCode+=buffer[i];
		buffer[i]=g_SendByteMap[buffer[i]];
	}
	
	//设置数据
	TCP_Info *pInfo	 = (TCP_Info*)pData;
	pInfo->cbCheckCode = ~cbCheckCode+1;
	pInfo->wPacketSize = wDataSize;
	pInfo->cbDataKind |= DK_MAPPED;
    
    return true;
}

//隐射数据
bool CTCPSocket::unMappedBuffer(void* pData, WORD wDataSize)
{
    //变量定义
	BYTE* buffer=(BYTE*)pData;
	TCP_Info* pInfo=(TCP_Info*)pData;
	
	//映射
	if( (pInfo->cbDataKind & DK_MAPPED) !=0)
	{
		BYTE cbCheckCode = pInfo->cbCheckCode;
		
		for(WORD i=sizeof(TCP_Info);i<wDataSize;i++)
		{
			cbCheckCode += g_RecvByteMap[buffer[i]];
			buffer[i] = g_RecvByteMap[buffer[i]];
		}
		//效验
		if(cbCheckCode!=0)
			return false;
	}
	return true;
}

//线程连接
void CTCPSocket::threadCreateConnect()
{
#ifdef WIN32
#ifdef PTW32_STATIC_LIB
    pthread_win32_process_attach_np();
#endif
#endif

    //创建互斥锁
    pthread_t ptThread;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    
    int code = pthread_create(&ptThread, 0, threadScoketConnect, this);
    if(code!=0)
    {
        log("CTCPSocket: createThread Failure");
    }
    pthread_detach(ptThread);
    pthread_attr_destroy(&attr);
}

//多线程创建
void CTCPSocket::threadCreateRecv()
{
#ifdef WIN32
#ifdef PTW32_STATIC_LIB
    pthread_win32_process_attach_np();
#endif
#endif
    //创建线程
    m_bConnect=true;
    
    //创建互斥锁
    pthread_t ptThread;
    pthread_mutex_init(&m_hMutext, NULL);
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    
    int code = pthread_create(&ptThread, 0, threadSocketRecv, this);
    if(code!=0)
    {
        log("CTCPSocket: createThread Failure");
    }
    pthread_detach(ptThread);
    pthread_attr_destroy(&attr);
    
    //打开socket循环
    Director::getInstance()->getScheduler()->scheduleSelector(schedule_selector(CTCPSocket::socketUpdate), this, 1.0f/60.0f, false);
}

//detach线程
void CTCPSocket::threadClosed()
{
#ifdef WIN32
#ifdef PTW32_STATIC_LIB
    
    pthread_win32_process_detach_np();
    
#endif
#endif
}

bool CTCPSocket::getConnect()
{
    return m_bConnect;
}

void CTCPSocket::ZeroBufferData()
{
	for (unsigned int i=0; i<m_pDataArray->size(); i++)
	{
		CSpriteData* pData = (CSpriteData*)m_pDataArray->at(i);
		if (pData->getReferenceCount()>1){
			pData->release();
		}
		//pData->release();
	}
}
