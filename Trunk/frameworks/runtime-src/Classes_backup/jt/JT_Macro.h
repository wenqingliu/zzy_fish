#ifndef __JT_MACROS_H__
#define __JT_MACROS_H__

//-------------------------------------------------------------------------------------------------------------

//CMD类定义
#define JT_CLASS_CMD(__TYPE__)\
class __TYPE__##Ref : public CMD_BASE\
{\
public:\
	JT_CREATE_WITH_DATA(__TYPE__##Ref);\
	__TYPE__ cmd;\
	JT_CMD_BASE(cmd)\
	JT_CMD_SETSTRUCT(cmd);\

//CMD基类
#define JT_CMD_BASE(VAR)\
public: \
	virtual int getSize(void) const {return sizeof(VAR);};\
	virtual void* getData()const{return (void*)(&(this->cmd));};

//生成create方法
#define JT_CREATE_FUNC(__TYPE__) \
static __TYPE__ * create() \
{\
	 __TYPE__ *pRet = new __TYPE__(); \
    if (pRet) \
    { \
        pRet->autorelease(); \
        return pRet; \
    } \
    else \
    { \
        delete pRet; \
        pRet = NULL; \
        return NULL; \
    } \
	return pRet;\
}

//从CNotify生成对象
#define JT_CREATE_WITH_DATA(__TYPE__)\
static __TYPE__ * createWithNotify(CNotify* notify = nullptr) \
{\
	 __TYPE__ *pRet = new __TYPE__(); \
    if (pRet) \
    { \
        pRet->autorelease(); \
		if(notify != nullptr) \
		{ \
			pRet->setStruct(notify); \
		} \
        return pRet; \
    } \
    else \
    { \
        delete pRet; \
        pRet = NULL; \
        return NULL; \
    } \
	return pRet;\
}

//从data数组中生成对象
#define JT_CREATE_WITH_DATAARRAY(__TYPE__)\
static __TYPE__##Ref * createWithDataArray(CNotify* notify,int index) \
{\
	__TYPE__##Ref *pRet = __TYPE__##Ref::createWithNotify();\
	memset(&(pRet->cmd),0,sizeof(__TYPE__));\
	memcpy(&(pRet->cmd),(__TYPE__*)notify->getData()+index,sizeof(__TYPE__));\
	return pRet;\
}

//get and set
#define JT_SYNTHESIZE(VARTYPE,ATTR)\
public: VARTYPE ATTR(void){ return cmd.ATTR; }\
public: void ATTR(VARTYPE VAR){ cmd.ATTR = VAR; }

//TCHAR类型引用
#define JT_SYNTHESIZE_TCHAR(ATTR,STRLEN)\
public: const char* ATTR(void){ return YYConverUnicodeToUtf8(cmd.ATTR);}\
public: void ATTR(const char* VAR){YYConverUtf8ToUnicodeWithArray(cmd.ATTR,STRLEN,VAR);}

//Ref*类型引用
#define JT_SYNTHESIZE_REF(varType, VARNAME)\
protected: varType VARNAME;\
public: virtual varType get##VARNAME(void) const { return VARNAME; }\
public: virtual void set##VARNAME(varType var){ VARNAME = var; }

//Ref*类型数组引用
#define JT_SYNTHESIZE_REF_ARR(VARTYPE,VARNAME,LENGTH)\
protected: VARTYPE VARNAME[LENGTH]; \
public: virtual VARTYPE get##VARNAME(int index) const { return VARNAME[index]; }\
public: virtual void set##VARNAME(VARTYPE var,int index){ VARNAME[index] = var; }


//数组定义
//一维数组
#define JT_GET_ARR(VARTYPE, ATTR)\
public: VARTYPE ATTR(int index1){ return cmd.ATTR[index1]; }

#define JT_SET_ARR(VARTYPE, ATTR)\
public: void ATTR(int index1,VARTYPE VAR){ cmd.ATTR[index1] = VAR; }

//二维数组
#define JT_GET_ARR2(VARTYPE, ATTR)\
public: VARTYPE ATTR(int index1,int index2){ return cmd.ATTR[index1][index2]; }

#define JT_SET_ARR2(VARTYPE, ATTR)\
public: void ATTR(int index1,int index2,VARTYPE VAR){ cmd.ATTR[index1][index2] = VAR; }

//sizeof获取字节数
#define JT_GETSIZE(VAR)\
public: int getSize(void) const {return sizeof(VAR);};

//复制结构体数据
#define JT_CMD_SETSTRUCT(_STRUCT_)\
	virtual void setStruct(CNotify* notify)\
	{\
		memset(&(this->_STRUCT_),0,sizeof(this->_STRUCT_));\
		memcpy(&(this->_STRUCT_),notify->getData(),sizeof(this->_STRUCT_));\
	}

#endif //__JT_MACROS_H__

//-------------------------------------------------------------------------------------------------------------/