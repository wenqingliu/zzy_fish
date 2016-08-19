#include "ODSocket.h"
#include <stdio.h>
#ifdef WIN32
#pragma comment(lib, "wsock32")
#endif

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

#define TIME_OUT_TIME  3    //连接超时时间

char ODSocket::m_szLocalIP[32]="\0";
ODSocket::ODSocket(SOCKET sock)
{
    m_sock = sock;
}

ODSocket::~ODSocket()
{
    //printf("~ODSocket");
}

int ODSocket::Init()
{
#ifdef WIN32
    /*
     typedef struct WSAData {
     WORD wVersion;								//winsock version
     WORD wHighVersion;							//The highest version of the Windows Sockets specification that the Ws2_32.dll can support
     char szDescription[WSADESCRIPTION_LEN+1];
     char szSystemStatus[WSASYSSTATUS_LEN+1];
     unsigned short iMaxSockets;
     unsigned short iMaxUdpDg;
     char FAR * lpVendorInfo;
     }WSADATA, *LPWSADATA;
     */
    WSADATA wsaData;
    //#define MAKEWORD(a,b) ((WORD) (((BYTE) (a)) | ((WORD) ((BYTE) (b))) << 8))
    WORD version = MAKEWORD(2, 0);
    int ret = WSAStartup(version, &wsaData);//win sock start up
    if ( ret ) {
        //		cerr << "Initilize winsock error !" << endl;
        return -1;
    }
#endif
    
    return 0;
}

//this is just for windows
int ODSocket::Clean()
{
#ifdef WIN32
    return (WSACleanup());
#endif
    return 0;
}


ODSocket& ODSocket::operator = (SOCKET s)
{
    m_sock = s;
    return (*this);
}

ODSocket::operator SOCKET ()
{
    return m_sock;
}


//create a socket object win/lin is the same
// af:
bool ODSocket::Create(int af, int type, int protocol)
{
    m_sock = socket(af, type, IPPROTO_TCP);
    if ( m_sock == INVALID_SOCKET )
    {
        return false;
    }
    return true;
}

bool ODSocket::Connect(const char* domain, unsigned short port)
{
    //连接ip
    char ip[128];
    memset(ip, 0, sizeof(ip));
    strcpy(ip, domain);
    
    //域名解析
//    if( domain[0]>='0' && domain[0]<='9' )
//        strcpy(ip, domain);
//    else
//        this->DnsParse(domain, ip);
    
    void* svraddr = nullptr;
    int error=-1, svraddr_len;
    bool ret = true;
    struct sockaddr_in svraddr_4;
	

#ifdef WIN32
    svraddr_4.sin_family = AF_INET;
    svraddr_4.sin_addr.s_addr = inet_addr(ip);
    svraddr_4.sin_port = htons(port);
    //len = sizeof(svraddr_4);
	svraddr_len = sizeof(int);
    svraddr = &svraddr_4;
#else
    struct sockaddr_in6 svraddr_6;

    //获取网络协议
    struct addrinfo *result;
    error = getaddrinfo(ip, NULL, NULL, &result);
    const struct sockaddr *sa = result->ai_addr;
    socklen_t maxlen = 128;
    switch(sa->sa_family) {
        case AF_INET://ipv4
            if(inet_ntop(AF_INET, &(((struct sockaddr_in *)sa)->sin_addr),
                         ip, maxlen) < 0){
                perror(ip);
                ret = false;
                break;
            }
            svraddr_4.sin_family = AF_INET;
            svraddr_4.sin_addr.s_addr = inet_addr(ip);
            svraddr_4.sin_port = htons(port);
            svraddr_len = sizeof(svraddr_4);
			//svraddr_len = sizeof(int);
            svraddr = &svraddr_4;
            break;
        case AF_INET6://ipv6
            Close();
            inet_ntop(AF_INET6, &(((struct sockaddr_in6 *)sa)->sin6_addr),
                      ip, maxlen);
            
            if ((m_sock = socket(AF_INET6, SOCK_STREAM, 0)) < 0) {
                perror("socket create failed");
                ret = false;
                break;
            }
            printf("socket created ipv6/n");
            
            bzero(&svraddr_6, sizeof(svraddr_6));
            svraddr_6.sin6_family = AF_INET6;
            svraddr_6.sin6_port = htons(port);
            if ( inet_pton(AF_INET6, ip, &svraddr_6.sin6_addr) < 0 ) {
                perror(ip);
                ret = false;
                break;
            }
            svraddr_len = sizeof(svraddr_6);
            svraddr = &svraddr_6;
            break;
            
        default:
            printf("Unknown AF\ns");
			ret = false;
            //return false;
    }
	freeaddrinfo(result);
#endif
    
    if(!ret){
        Close();
        return false;
    }
    
    timeval tm;
    fd_set wset;
    
    //非阻塞模式，设置连接超时时间
    tm.tv_sec = TIME_OUT_TIME;
    tm.tv_usec = 0;
    FD_ZERO(&wset);
    FD_SET(m_sock, &wset);
    
    //设置为非阻塞模式
    unsigned long ul = 1;
    
#ifdef WIN32
    ioctlsocket(m_sock, FIONBIO, &ul);
		if( connect(m_sock, (struct sockaddr *)svraddr,sizeof(struct sockaddr_in)) == -1)
		{
			if( select(m_sock+1, NULL, &wset, NULL, &tm) > 0)
			{
				getsockopt(m_sock, SOL_SOCKET, SO_ERROR, (char *)&error, /*(socklen_t *)*/&svraddr_len);
				if(error == 0) ret = true;
				else ret = false;
			}
		}else{
            ret = false;
		}
		ul = 0;
		ioctlsocket(m_sock, FIONBIO, &ul); //设置为阻塞模式
    #else
        
        ioctl(m_sock, FIONBIO, &ul);
		if( connect(m_sock, (struct sockaddr *)svraddr, svraddr_len) == -1)
		{
			auto ret_s = select(m_sock+1, NULL, &wset, NULL, &tm);
			if( ret_s > 0)
			{
				socklen_t len = sizeof(error);
				getsockopt(m_sock, SOL_SOCKET, SO_ERROR, &error, (socklen_t *)&len);
				if(error == 0) ret = true;
				else ret = false;
			} else {
				ret = false;
			}
		}else{
			ret = false;
		}
    
		//还原设置为非阻塞模式
		ul = 0;
		ioctl(m_sock, FIONBIO, &ul);
#endif
    if(!ret)
    {
        Close();
        fprintf(stderr , "Cannot Connect the server!n");
        return false;
    }
#ifdef WIN32
    int iSendTime = 15000;
    setsockopt(m_sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&iSendTime, sizeof(iSendTime));
    //int iRecvTime = 5000;
    //setsockopt(m_sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&iRecvTime, sizeof(iRecvTime));
    #else
        //设置socket超时
        struct timeval timeout;
    timeout.tv_sec = 15;
    timeout.tv_usec = 0;
    
    setsockopt(m_sock,SOL_SOCKET,SO_SNDTIMEO,&timeout,sizeof(timeout));
#endif
    //    setsockopt(m_sock,SOL_SOCKET,SO_RCVTIMEO,&timeout,sizeof(timeout));
    //	socket阻塞模式，不能设置连接超时时间
    //int ret = connect(m_sock, (struct sockaddr*)&svraddr, sizeof(svraddr));
    //if ( ret==SOCKET_ERROR )
    //       return false;
    
    
    return true;
}

bool ODSocket::Bind(unsigned short port)
{
    struct sockaddr_in svraddr;
    svraddr.sin_family = AF_INET;
    svraddr.sin_addr.s_addr = INADDR_ANY;
    svraddr.sin_port = htons(port);
    
    int opt =  1;
    if ( setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt)) < 0 )
    {
        return false;
    }
    
    int ret = bind(m_sock, (struct sockaddr*)&svraddr, sizeof(svraddr));
    if ( ret == SOCKET_ERROR )
    {
        return false;
    }
    return true;
}
//for server
bool ODSocket::Listen(int backlog)
{
    int ret = listen(m_sock, backlog);
    if ( ret == SOCKET_ERROR )
    {
        return false;
    }
    return true;
}

bool ODSocket::Accept(ODSocket& s, char* fromip)
{
    struct sockaddr_in cliaddr;
    socklen_t addrlen = sizeof(cliaddr);
    SOCKET sock = accept(m_sock, (struct sockaddr*)&cliaddr, &addrlen);
    if ( sock == SOCKET_ERROR )
    {
        return false;
    }
    s = sock;
    if ( fromip != NULL )
    {
        sprintf(fromip, "%s", inet_ntoa(cliaddr.sin_addr));
    }
    return true;
}

int ODSocket::Send(const char* buf, int len, int flags)
{
    int bytes;
    int count = 0;
    while ( count < len )
    {
        bytes = (int)send(m_sock, buf + count, len - count, flags);
        if (bytes == -1 || bytes == 0)
        {
            return -1;
        }
        count += bytes;
    }
    return count;
}

bool ODSocket::isLocalWIFI()
{
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    
    //ios下检测是否wifi
    struct ifaddrs *addresses;
    struct ifaddrs *cursor;
    bool wiFiAvailable = false;
    
    if (getifaddrs(&addresses) != 0) return wiFiAvailable;
    
    cursor = addresses;
    while (cursor != NULL)
    {
        if (cursor -> ifa_addr -> sa_family == AF_INET && !(cursor -> ifa_flags & IFF_LOOPBACK)) // Ignore the loopback address
        {
            // Check for WiFi adapter
            if (strcmp(cursor -> ifa_name, "en0") == 0)
            {
                wiFiAvailable = true;
                break;
            }
        }
        cursor = cursor -> ifa_next;
    }
    
    freeifaddrs(addresses);
    
    return wiFiAvailable;
    
#endif
    
    return false;
}

int ODSocket::Recv(char* buf, int len, int flags)
{
    return ((int)recv(m_sock, buf, len, flags));
}

int ODSocket::Close()
{
#ifdef WIN32
    return (closesocket(m_sock));
#else
    shutdown(m_sock, SHUT_RDWR);
    return close(m_sock);
#endif
}

int ODSocket::GetError()
{
#ifdef WIN32
    return (WSAGetLastError());
#else
    return (errno);
#endif
}

int ODSocket::GetFlags()
{
    return 0;
}

bool ODSocket::DnsParse(const char* domain, char* ip)
{
    struct hostent* p;
    if ((p = gethostbyname(domain)) == NULL)
    {
        return false;
    }
    sprintf(ip, 
            "%u.%u.%u.%u",
            (unsigned char)p->h_addr_list[0][0], 
            (unsigned char)p->h_addr_list[0][1], 
            (unsigned char)p->h_addr_list[0][2], 
            (unsigned char)p->h_addr_list[0][3]);	
    return true;
}