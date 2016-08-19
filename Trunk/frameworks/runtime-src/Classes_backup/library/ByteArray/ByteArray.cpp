
 #include "ByteArray.h"
#include "SpriteDefine.h"
int ByteArray::globalCPUEndian = -1;

ByteArray::ByteArray():
bytes(nullptr),
pos(0),
length(0),
endian(0)
{

};

ByteArray* ByteArray::create(int len)
{
    ByteArray* ba = new ByteArray();
    if (ba)
    {
        ba->autorelease();
        ba->pos = 0;
        ba->length = len;
    }
    else
    {
        delete ba;
        ba = NULL;
        return NULL;
    }

    //auto size = sizeof(ba->bytes);
    //ba->pos = 0;
    //ba->length = len;
    //ba->endian = 1;//endian;

    //if (globalCPUEndian == -1){
    //	globalCPUEndian  =  ByteArray::checkCPUEndian();
    //}

    return ba;
}
//
ByteArray* ByteArray::createWithNotify(CNotify* notify)
{
    ByteArray* ba = new ByteArray();
    if (ba)
    {
        ba->autorelease();
        ba->bytes = (BYTE*)notify->getData();
        ba->length = notify->getSize();
        return ba;
    }
    else
    {
        delete ba;
        ba = NULL;
        return NULL;
    }
    return ba;
}

ByteArray* ByteArray::createWithPacket(TCP_BufferRef* packet)
{
    ByteArray* ba = new ByteArray();
    if (ba)
    {
        ba->autorelease();
        ba->bytes = packet->cmd.cbBuffer;
        return ba;
    }
    else
    {
        delete ba;
        ba = NULL;
        return NULL;
    }
    return ba;
}

void ByteArray::destroy(ByteArray* ba) {
    delete ba;
}

//0: big 1:little
int ByteArray::checkCPUEndian() {
    union w
    {
        int a;
        char b;
    } c;
    c.a = 1;
    return  (c.b ==1 ? endianLittle : endianBig);
}

int ByteArray::getCPUEndian() {
    return globalCPUEndian;
}

bool ByteArray::readBool()
{
    bool b;
    char* p = (char*)&b;
    memcpy(p,this->bytes+this->pos,sizeof(b));
    this->pos += sizeof(b);
    return b;
}

void ByteArray::writeBool(bool value)
{
    char* p = (char*)&value;
    memcpy(this->bytes+this->pos,p,sizeof(value));
    this->pos += sizeof(value);
}

short ByteArray::readShort()
{
    short n;
    char* p = (char*)&n;
    memcpy(p,this->bytes+this->pos,sizeof(n));
    this->pos += 2;
    return n;
}

void ByteArray::writeShort(short value)
{
    char* p = (char*)&value;
    memcpy(this->bytes+this->pos,p,sizeof(value));
    this->pos += 2;
}

int ByteArray::readInt() {
    int n;
    char* p = (char*)&n;
    memcpy(p,this->bytes+this->pos,sizeof(int));
    this->pos += 4;
    return n;
}

void ByteArray::writeInt(int value)
{
    char* p = (char*)&value;
    memcpy(this->bytes+this->pos,p,sizeof(value));
    this->pos += 4;
}

float ByteArray::readFloat() {
    float n;
    char* p = (char*)&n;
    memcpy(p,this->bytes+this->pos,sizeof(float));
    this->pos += 4;
    return n;
}

void ByteArray::writeFloat(float value)
{
    char* p = (char*)&value;
    memcpy(this->bytes+this->pos,p,sizeof(value));
    this->pos += 4;
}

unsigned int ByteArray::readUINT() {
    unsigned int n;
    char* p = (char*)&n;
    memcpy(p,this->bytes+this->pos,sizeof(n));

    this->pos += 4;
    return n;
}

void ByteArray::writeUINT(unsigned int value)
{
    char* p = (char*)&value;
    memcpy(this->bytes+this->pos,p,sizeof(value));
    this->pos += 4;
}

unsigned short ByteArray::readWORD() {
    unsigned short n;
    char* p = (char*)&n;
    memcpy(p,this->bytes+this->pos,sizeof(n));
    this->pos += 2;
    return n;
}

void ByteArray::writeWORD(unsigned short value)
{
    char* p = (char*)&value;
    memcpy(this->bytes+this->pos,p,sizeof(value));
    this->pos += 2;
}

char ByteArray::readByte() {
    signed char val = this->bytes[this->pos];
    if (val > 127){
        val = val - 255;
    }
    this->pos += 1;
    return val;
}

void ByteArray::writeByte(char value)
{
    char* p = (char*)&value;
    memcpy(this->bytes+this->pos,p,sizeof(value));
    this->pos += 1;
}

unsigned char ByteArray::readBYTE() {
    unsigned char val = this->bytes[this->pos];
    this->pos += 1;
    return val;
}

void ByteArray::writeBYTE(unsigned char value)
{
    char* p = (char*)&value;
    memcpy(this->bytes+this->pos,p,sizeof(value));
    this->pos += 1;
}

unsigned long ByteArray::readDWORD()
{
    int n;
    char* p = (char*)&n;
    memcpy(p,this->bytes+this->pos,sizeof(n));
    this->pos += sizeof(n);
    return n;
}

void ByteArray::writeDWORD(int value)
{
    char* p = (char*)&value;
    memcpy(this->bytes+this->pos,p,sizeof(value));
    this->pos += sizeof(value);
}

LONGLONG ByteArray::readLONGLONG()
{
    long long n;
    char* p = (char*)&n;
    memcpy(p,this->bytes+this->pos,sizeof(n));
    this->pos += sizeof(n);
    return n;
}

void ByteArray::writeLONGLONG(long long value)
{
    char* p = (char*)&value;
    memcpy(this->bytes+this->pos,p,sizeof(value));
    this->pos += sizeof(value);
}

string ByteArray::readString(int len) {

    char* value = new char[len + 1];

    value[len] = 0;
    memcpy(value, this->bytes + this->pos, len);
    this->pos += len;

    string str(value);
    delete [] value;
    value = nullptr;

    return str;
}

string ByteArray::readTchar(int len)
{
    TCHAR* tchar = new TCHAR[len];
    memset(tchar,0,len);
    memcpy(tchar, this->bytes + this->pos, len*sizeof(TCHAR));
    this->pos += len*sizeof(TCHAR);

    string str(YYConverUnicodeToUtf8(tchar));
    delete[] tchar;
    tchar = nullptr;

    return str;
}

void ByteArray::writeTchar(const char* value,int len)
{
    TCHAR* tchar = new TCHAR[len];
    memset(tchar,0,len);
    YYConverUtf8ToUnicodeWithArray(tchar,len,value);
    memcpy(this->bytes+this->pos,tchar,len);
    this->pos += len*sizeof(TCHAR);

    delete[] tchar;
    tchar = nullptr;
}

string ByteArray::readTCHAR(int len)
{
	return this->readTchar(len);
};

void ByteArray::writeTCHAR(const char* value,int len)
{
	this->writeTchar(value,len);
}

int ByteArray::getPosition() {

    return this->pos;
}

void ByteArray::setPosition(int pos) {

    this->pos = pos;
}


int ByteArray::getLength() {
    return this->length;
}


int ByteArray::getBytesAvailable() {
    return this->length - this->pos;
}
