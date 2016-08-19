//
//  TCPSocket.cpp
//  GameProject
//
//  Created by jt on 15-09-04.
//
//

#ifndef __CC_BYTEARRAY_H_
#define __CC_BYTEARRAY_H_

#include "cocos2d.h"
USING_NS_CC;

#include "CMD_PacketRef.h"

#include <string>
using namespace std;

/**

**/
class ByteArray : public Ref
{
public:
     static ByteArray* create(int len);
	 static ByteArray* createWithNotify(CNotify* notify);
	 static ByteArray* createWithPacket(TCP_BufferRef* packet);

	 static void destroy(ByteArray* ba) ;

	 static int checkCPUEndian();

	 static const int endianLittle = 1;
	 static const int endianBig = 0;

	 bool readBool();
	 void writeBool(bool value);

	 short readShort();
	 void writeShort(short value);

	 unsigned short readWORD();
	 void writeWORD(unsigned short value);

	 int readInt();
	 void writeInt(int value);

     float readFloat();
     void writeFloat(float value);

	 unsigned int readUINT();
	 void writeUINT(unsigned int value);

	 unsigned long readDWORD();
	 void writeDWORD(int value);

	 long long readLONGLONG();
	 void writeLONGLONG(long long value);

	 string readString(int len);

	 string readTchar(int len);
	 void writeTchar(const char* value,int len);

	 string readTCHAR(int len);
	 void writeTCHAR(const char* value,int len);

	 char readByte();
	 void writeByte(char value);

	 unsigned char readBYTE();
	 void writeBYTE(unsigned char value);

	 int getLength();
	 int getCPUEndian();
	 int getPosition();
	 void setPosition(int pos);
	 int getBytesAvailable();
	 //setEndian(int n)

protected:
	ByteArray();
	virtual ~ByteArray(){};

private:
	 BYTE* bytes;
	 int pos;
	 int length;
	 int endian;

	 static int globalCPUEndian;

};



#endif // __CC_EXTRA_CCBYTEARRAY_H_
