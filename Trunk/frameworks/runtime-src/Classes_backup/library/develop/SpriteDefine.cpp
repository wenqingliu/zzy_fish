
#include "SpriteDefine.h"
#include "SpriteData.h"
#include "cocos2d.h"
USING_NS_CC;


//-----------------------------字符转换----------------------------------------------------------------------
//单字符:utf8 -> unicode 返回转换长度
int YYConverUtf8ToUnicode(TCHAR *destUnicode, c_char *srcUtf8)
{
    int i=0;
  
    if( ( 0x80&srcUtf8[0]) == 0 )         //一个字节的UTF-8
    {
        destUnicode[0] = srcUtf8[i++];
    }

    if( (0xE0&srcUtf8[0]) == 0xC0 )      //两字节的UTF-8
    {
        int a = ( 0x1F & srcUtf8[i++] ) << 6;
        int b = ( 0x3F & srcUtf8[i++] );
        destUnicode[0] = a + b;
    }

    if( (0xF0&srcUtf8[0]) == 0xE0 )      //三字节的UTF-8
    {
        int a = ( 0x1F & srcUtf8[i++] ) << 12;
        int b = ( 0x3F & srcUtf8[i++] ) << 6;
        int c = ( 0x3F & srcUtf8[i++] );
        
        destUnicode[0] = a + b + c;
    }
    return i;
}

//单字符:unicode -> utf8 返回转换长度
int YYConverUnicodeToUtf8(char* destUtf8, TCHAR srcUnicode)
{
    int i=0;
    if( 0x80 > srcUnicode )
    {
        destUtf8[i++]=(char)srcUnicode;
    }
    else
    {
        destUtf8[i++] = (char)(0xE0|(srcUnicode>>12));
        destUtf8[i++] = (char)(0x80|((srcUnicode>>6)&0x3F));
        destUtf8[i++] = (char)(0x80|(srcUnicode&0x3F));
    }
    return i;
}

//数组:utf8 -> unicode
void YYConverUtf8ToUnicodeWithArray(TCHAR destUnicode[], int tcharLength, c_char srcUtf8[])
{
	if(srcUtf8==NULL) return;
    
    memset(destUnicode, 0, sizeof(TCHAR)*tcharLength);
    
    WORD wLen=strlen(srcUtf8);
    WORD wIndex=0;
    for (WORD i=0; i<wLen; i++){
        if(*(srcUtf8+wIndex)!='\0')
            wIndex += YYConverUtf8ToUnicode(destUnicode+i, srcUtf8+wIndex);
        else
            break;
    }
}
//数组:utf8 -> unicode  2
void YYConverUtf8ToUnicodeWithArray2(TCHAR  pOut[],c_char pText[])
{
    TCHAR *uchar = (TCHAR *)pOut;
    uchar[1] = ((pText[0] & 0x0F) << 4) + ((pText[1] >> 2) & 0x0F);
    uchar[0] = ((pText[1] & 0x03) << 6) + (pText[2] & 0x0F);
    return;
}
int UniCharToUTF8(TCHAR UniChar, char *OutUTFString)
{
	int UTF8CharLength = 0;
	
	if (UniChar < 0x80)
	{ 
        if ( OutUTFString )
             OutUTFString[UTF8CharLength++] = (char)UniChar;
         else
             UTF8CharLength++;
	}
	else if(UniChar < 0x800)  
	{      
		if ( OutUTFString )
		{
			OutUTFString[UTF8CharLength++] = 0xc0 | ( UniChar >> 6 );
	                  OutUTFString[UTF8CharLength++] = 0x80 | ( UniChar & 0x3f );
	              
		} 
		else       
		{
			UTF8CharLength += 2;       
		} 
	}
	else if(1)
	{		      
		if ( OutUTFString )        
		{              
			OutUTFString[UTF8CharLength++] = 0xe0 | ( UniChar >> 12 );               
			OutUTFString[UTF8CharLength++] = 0x80 | ( (UniChar >> 6) & 0x3f );            
			OutUTFString[UTF8CharLength++] = 0x80 | ( UniChar & 0x3f );
			           
		}     
		else	        
		{             
			UTF8CharLength += 3;           
		}		
	}
	else if( UniChar < 0x200000 )  
	{
		if ( OutUTFString )
		{     
			OutUTFString[UTF8CharLength++] = 0xf0 | ( (int)UniChar >> 18 );      
			OutUTFString[UTF8CharLength++] = 0x80 | ( (UniChar >> 12) & 0x3f );       
			OutUTFString[UTF8CharLength++] = 0x80 | ( (UniChar >> 6) & 0x3f );   
			OutUTFString[UTF8CharLength++] = 0x80 | ( UniChar & 0x3f );     
		}
		else
		{         
			UTF8CharLength += 4;
		}
	 } 
	return UTF8CharLength;
	
}

int UTF8StrToUnicode( const char* UTF8String, int UTF8StringLength, TCHAR* OutUnicodeString, int UnicodeStringBufferSize )
{
	int UTF8Index = 0;
	int UniIndex = 0;
	      
	while ( UTF8Index < UTF8StringLength )   
	{
		unsigned char UTF8Char = UTF8String[UTF8Index];	 
		if ( UnicodeStringBufferSize != 0 && UniIndex >= UnicodeStringBufferSize )  
			break;
	    
		if ((UTF8Char & 0x80) == 0)       
		{            
			const int cUTF8CharRequire = 1;
			              
			// UTF8字码不足      
			if ( UTF8Index + cUTF8CharRequire > UTF8StringLength )
		                    
				break;
		
			if ( OutUnicodeString )                
			{                  
				TCHAR& WideChar = OutUnicodeString[UniIndex];                   
				WideChar = UTF8Char;             
			}             
			UTF8Index++;	             		        
		}
				 
		else if((UTF8Char & 0xE0) == 0xC0)  ///< 110x-xxxx 10xx-xxxx	     
		{              
			const int cUTF8CharRequire = 2;

			// UTF8字码不足             
			if ( UTF8Index + cUTF8CharRequire > UTF8StringLength )               
				break;

			if ( OutUnicodeString )     
			{        
				TCHAR& WideChar = OutUnicodeString[UniIndex];      
				WideChar  = (UTF8String[UTF8Index + 0] & 0x3F) << 6;      
				WideChar |= (UTF8String[UTF8Index + 1] & 0x3F); 
			}     
			UTF8Index += cUTF8CharRequire;     
		}
		else if((UTF8Char & 0xF0) == 0xE0)  ///< 1110-xxxx 10xx-xxxx 10xx-xxxx      
		{        
			const int cUTF8CharRequire = 3;           
			
			// UTF8字码不足         
			if ( UTF8Index + cUTF8CharRequire > UTF8StringLength )
				break;

			if ( OutUnicodeString )
			{
				TCHAR& WideChar = OutUnicodeString[UniIndex];
				WideChar  = (UTF8String[UTF8Index + 0] & 0x1F) << 12;
				WideChar |= (UTF8String[UTF8Index + 1] & 0x3F) << 6;
				WideChar |= (UTF8String[UTF8Index + 2] & 0x3F);
			}
			UTF8Index += cUTF8CharRequire;
		}
		else if((UTF8Char & 0xF8) == 0xF0)  ///< 1111-0xxx 10xx-xxxx 10xx-xxxx 10xx-xxx
		{
			const int cUTF8CharRequire = 4;
			
			// UTF8字码不足
			if ( UTF8Index + cUTF8CharRequire > UTF8StringLength )
				break;
			if ( OutUnicodeString )
			{
				TCHAR& WideChar = OutUnicodeString[UniIndex];
				WideChar  = (UTF8String[UTF8Index + 0] & 0x0F) << 18;
				WideChar  = (UTF8String[UTF8Index + 1] & 0x3F) << 12;
				WideChar |= (UTF8String[UTF8Index + 2] & 0x3F) << 6;
				WideChar |= (UTF8String[UTF8Index + 3] & 0x3F);
			}     
			UTF8Index += cUTF8CharRequire;    
		}
		else ///< 1111-10xx 10xx-xxxx 10xx-xxxx 10xx-xxxx 10xx-xxxx
		{     
			const int cUTF8CharRequire = 5;
		  
			// UTF8字码不足     
			if ( UTF8Index + cUTF8CharRequire > UTF8StringLength )     
				break;

			if ( OutUnicodeString )
			{
				TCHAR& WideChar = OutUnicodeString[UniIndex];
				WideChar  = (UTF8String[UTF8Index + 0] & 0x07) << 24;          
				WideChar  = (UTF8String[UTF8Index + 1] & 0x3F) << 18;	              
				WideChar  = (UTF8String[UTF8Index + 2] & 0x3F) << 12;	              
				WideChar |= (UTF8String[UTF8Index + 3] & 0x3F) << 6;	              
				WideChar |= (UTF8String[UTF8Index + 4] & 0x3F);	             
			}		       
			
			UTF8Index += cUTF8CharRequire;	  
		}			           
		UniIndex++;

	}

	return UniIndex; 
}

			 //数组:unicode -> utf8
void YYConverUnicodeToUtf8WithArray(char destUtf8[], TCHAR srcUnicode[])
{
    memset(destUtf8, 0, strlen(destUtf8)+1);
    
    WORD wIndex=0;
    for (int i=0; ; i++)
    {
        if(srcUnicode[i])
            wIndex += YYConverUnicodeToUtf8(destUtf8+wIndex, srcUnicode[i]);
        else
            break;
    }
}

char* YYConverUnicodeToUtf8(TCHAR srcUnicode[])
{
    static char destUtf8[1024];
    memset(destUtf8, 0, sizeof(destUtf8));

	/* #if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		if (srcUnicode != NULL)  
		{  
			int nInputStrLen = wcslen (srcUnicode); 
			int nOutputStrLen = WideCharToMultiByte (CP_ACP, 0, srcUnicode, nInputStrLen, NULL, 0, 0, 0) + 2; 
			if (destUtf8)  
			{  
				memset (destUtf8, 0x00, nOutputStrLen);  
				WideCharToMultiByte(CP_ACP, 0, srcUnicode, nInputStrLen, destUtf8, nOutputStrLen, 0, 0);  
			}  
		}  
		return destUtf8;
	#endif*/

    WORD wIndex=0;
    for (WORD i=0; ; i++)
        if(srcUnicode[i])
            wIndex += YYConverUnicodeToUtf8(destUtf8+wIndex, srcUnicode[i]);
        else
            break;
    

    return destUtf8;
}

//数组:utf8 -> md5 unicode
void YYConverUtf8ToMD5Unicode(TCHAR destUnicode[], c_char srcUtf8[])
{
    CMD5 cmd5;
    char* md5Str=cmd5.MD5_Algorithm(srcUtf8);
    YYConverUtf8ToUnicodeWithArray(destUnicode, LEN_PASSWORD, md5Str);
}

//扩展转换: uf8 -> md5
char* YYConverUft8ToMD5(c_char destUf8[])
{
    CMD5 cmd5;
    return cmd5.MD5_Algorithm(destUf8);
}
////待修改
//
////当前系统时间精确到秒
long YYSystemTimeNowSec()
{
     struct timeval nowTimeval;
    gettimeofday(&nowTimeval, NULL);
    struct tm * tm;
    time_t time_sec ;
    time_sec = nowTimeval.tv_sec;
    tm = localtime(&time_sec);
    return tm->tm_sec;
}
////获取当前时间 精确到毫秒数
long YYMillisecondNow()
{
	struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;

}
////获取当前时间秒
long YYSystemSecond()
{
     struct timeval nowTimeval;
    gettimeofday(&nowTimeval, NULL);
    struct tm * tm;
    time_t time_sec ;
    time_sec = nowTimeval.tv_sec;
    tm = localtime(&time_sec);
    return tm->tm_sec;
}

//判断是不是 双击
bool isDoubleTouch()
{
    static long lastTouchTime=0;
    long thisTouchTime=YYMillisecondNow();
    if(abs(thisTouchTime-lastTouchTime)<250)
    {
        lastTouchTime=0;
        return true;
    }
    else
    {
        lastTouchTime=YYMillisecondNow();
        return false;
    }
}
//隐射数据
bool mappedBuffer(void* pData, WORD wDataSize)
{
	//变量定义
	BYTE *buffer	 = (BYTE*)pData;

	//映射数据
	for(WORD i=0; i<wDataSize; i++){
		buffer[i] += 1;
	}
	return true;
}

//隐射数据
bool unMappedBuffer(void* pData, WORD wDataSize)
{
	//变量定义
	BYTE* buffer=(BYTE*)pData;

	//映射
	for(WORD i=0; i<wDataSize; i++){
		buffer[i] -= 1;
	}
	return true;
}




//-----------------------------字符转换----------------------------------------------------------------------

c_char* YYChar(const char* format, ...)
{
	static char pData[1024]="\0";
	memset(pData, 0, sizeof(pData));
    
	va_list ap;
	va_start(ap, format);
	vsnprintf(pData, 1024, format, ap);
    va_end(ap);
 
    return pData;
}

void YYNewChar(char* pData, WORD wDataSize, const char* format, ...)
{
    memset(pData, 0, wDataSize);
    
    va_list ap;
	va_start(ap, format);
	vsnprintf(pData, wDataSize, format, ap);
    va_end(ap);
}
void YYAppendChar(char* pData, c_char* src)
{
    strcat(pData, src);
}


CCNotificationCenter* GetNotificationCenter()
{
    return cocos2d::CCNotificationCenter::sharedNotificationCenter();
}

//-------------------------------------------------------------------------------------------------------------------
