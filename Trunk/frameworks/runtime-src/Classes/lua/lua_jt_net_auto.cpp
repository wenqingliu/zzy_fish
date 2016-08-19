#include "lua_jt_net_auto.hpp"
#include "FrameData.h"
#include "SpriteData.h"
#include "ByteArray.h"
#include "CMD_PacketRef.h"
#include "protocol.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_jt_net_CNotify_getMainType(lua_State* tolua_S)
{
    int argc = 0;
    CNotify* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CNotify",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CNotify*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CNotify_getMainType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CNotify_getMainType'", nullptr);
            return 0;
        }
        int ret = cobj->getMainType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CNotify:getMainType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CNotify_getMainType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CNotify_getObject(lua_State* tolua_S)
{
    int argc = 0;
    CNotify* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CNotify",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CNotify*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CNotify_getObject'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CNotify_getObject'", nullptr);
            return 0;
        }
        cocos2d::Ref* ret = cobj->getObject();
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CNotify:getObject",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CNotify_getObject'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CNotify_setTypeData(lua_State* tolua_S)
{
    int argc = 0;
    CNotify* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CNotify",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CNotify*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CNotify_setTypeData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CNotify:setTypeData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CNotify_setTypeData'", nullptr);
            return 0;
        }
        cobj->setTypeData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CNotify:setTypeData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CNotify_setTypeData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CNotify_setObject(lua_State* tolua_S)
{
    int argc = 0;
    CNotify* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CNotify",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CNotify*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CNotify_setObject'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Ref* arg0;

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CNotify_setObject'", nullptr);
            return 0;
        }
        cobj->setObject(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CNotify:setObject",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CNotify_setObject'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CNotify_getMainString(lua_State* tolua_S)
{
    int argc = 0;
    CNotify* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CNotify",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CNotify*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CNotify_getMainString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CNotify_getMainString'", nullptr);
            return 0;
        }
        std::string ret = cobj->getMainString();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CNotify:getMainString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CNotify_getMainString'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CNotify_getEventName(lua_State* tolua_S)
{
    int argc = 0;
    CNotify* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CNotify",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CNotify*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CNotify_getEventName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CNotify_getEventName'", nullptr);
            return 0;
        }
        std::string ret = cobj->getEventName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CNotify:getEventName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CNotify_getEventName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CNotify_getSubType(lua_State* tolua_S)
{
    int argc = 0;
    CNotify* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CNotify",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CNotify*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CNotify_getSubType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CNotify_getSubType'", nullptr);
            return 0;
        }
        int ret = cobj->getSubType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CNotify:getSubType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CNotify_getSubType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CNotify_setMainType(lua_State* tolua_S)
{
    int argc = 0;
    CNotify* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CNotify",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CNotify*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CNotify_setMainType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CNotify:setMainType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CNotify_setMainType'", nullptr);
            return 0;
        }
        cobj->setMainType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CNotify:setMainType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CNotify_setMainType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CNotify_getResult(lua_State* tolua_S)
{
    int argc = 0;
    CNotify* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CNotify",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CNotify*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CNotify_getResult'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CNotify_getResult'", nullptr);
            return 0;
        }
        int ret = cobj->getResult();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CNotify:getResult",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CNotify_getResult'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CNotify_getTypeData(lua_State* tolua_S)
{
    int argc = 0;
    CNotify* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CNotify",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CNotify*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CNotify_getTypeData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CNotify_getTypeData'", nullptr);
            return 0;
        }
        int ret = cobj->getTypeData();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CNotify:getTypeData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CNotify_getTypeData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CNotify_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CNotify* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CNotify",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CNotify*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CNotify_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CNotify_getSize'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CNotify:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CNotify_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CNotify_setEventName(lua_State* tolua_S)
{
    int argc = 0;
    CNotify* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CNotify",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CNotify*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CNotify_setEventName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CNotify:setEventName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CNotify_setEventName'", nullptr);
            return 0;
        }
        cobj->setEventName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CNotify:setEventName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CNotify_setEventName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CNotify_getSubString(lua_State* tolua_S)
{
    int argc = 0;
    CNotify* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CNotify",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CNotify*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CNotify_getSubString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CNotify_getSubString'", nullptr);
            return 0;
        }
        std::string ret = cobj->getSubString();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CNotify:getSubString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CNotify_getSubString'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CNotify_getData(lua_State* tolua_S)
{
    int argc = 0;
    CNotify* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CNotify",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CNotify*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CNotify_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CNotify_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CNotify:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CNotify_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CNotify_setSubType(lua_State* tolua_S)
{
    int argc = 0;
    CNotify* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CNotify",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CNotify*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CNotify_setSubType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CNotify:setSubType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CNotify_setSubType'", nullptr);
            return 0;
        }
        cobj->setSubType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CNotify:setSubType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CNotify_setSubType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CNotify_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CNotify",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            void* arg0;
            #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;
            if (!ok) { break; }
            CNotify* ret = CNotify::create(arg0);
            object_to_luaval<CNotify>(tolua_S, "CNotify",(CNotify*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            void* arg0;
            #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;
            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CNotify:create");
            if (!ok) { break; }
            int arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "CNotify:create");
            if (!ok) { break; }
            CNotify* ret = CNotify::create(arg0, arg1, arg2);
            object_to_luaval<CNotify>(tolua_S, "CNotify",(CNotify*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            CNotify* ret = CNotify::create();
            object_to_luaval<CNotify>(tolua_S, "CNotify",(CNotify*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "CNotify:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CNotify_create'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_net_CNotify_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CNotify* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            void* arg0;
            #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CNotify:CNotify");

            if (!ok) { break; }
            int arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "CNotify:CNotify");

            if (!ok) { break; }
            cobj = new CNotify(arg0, arg1, arg2);
            cobj->autorelease();
            int ID =  (int)cobj->_ID ;
            int* luaID =  &cobj->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CNotify");
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj = new CNotify();
            cobj->autorelease();
            int ID =  (int)cobj->_ID ;
            int* luaID =  &cobj->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CNotify");
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CNotify:CNotify",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CNotify_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_jt_net_CNotify_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CNotify)");
    return 0;
}

int lua_register_jt_net_CNotify(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CNotify");
    tolua_cclass(tolua_S,"CNotify","CNotify","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CNotify");
        tolua_function(tolua_S,"new",lua_jt_net_CNotify_constructor);
        tolua_function(tolua_S,"getMainType",lua_jt_net_CNotify_getMainType);
        tolua_function(tolua_S,"getObject",lua_jt_net_CNotify_getObject);
        tolua_function(tolua_S,"setTypeData",lua_jt_net_CNotify_setTypeData);
        tolua_function(tolua_S,"setObject",lua_jt_net_CNotify_setObject);
        tolua_function(tolua_S,"getMainString",lua_jt_net_CNotify_getMainString);
        tolua_function(tolua_S,"getEventName",lua_jt_net_CNotify_getEventName);
        tolua_function(tolua_S,"getSubType",lua_jt_net_CNotify_getSubType);
        tolua_function(tolua_S,"setMainType",lua_jt_net_CNotify_setMainType);
        tolua_function(tolua_S,"getResult",lua_jt_net_CNotify_getResult);
        tolua_function(tolua_S,"getTypeData",lua_jt_net_CNotify_getTypeData);
        tolua_function(tolua_S,"getSize",lua_jt_net_CNotify_getSize);
        tolua_function(tolua_S,"setEventName",lua_jt_net_CNotify_setEventName);
        tolua_function(tolua_S,"getSubString",lua_jt_net_CNotify_getSubString);
        tolua_function(tolua_S,"getData",lua_jt_net_CNotify_getData);
        tolua_function(tolua_S,"setSubType",lua_jt_net_CNotify_setSubType);
        tolua_function(tolua_S,"create", lua_jt_net_CNotify_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CNotify).name();
    g_luaType[typeName] = "CNotify";
    g_typeCast["CNotify"] = "CNotify";
    return 1;
}

int lua_jt_net_CSpriteData_getBuffer(lua_State* tolua_S)
{
    int argc = 0;
    CSpriteData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSpriteData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSpriteData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CSpriteData_getBuffer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CSpriteData_getBuffer'", nullptr);
            return 0;
        }
        void* ret = cobj->getBuffer();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSpriteData:getBuffer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CSpriteData_getBuffer'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CSpriteData_setSubCmdID(lua_State* tolua_S)
{
    int argc = 0;
    CSpriteData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSpriteData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSpriteData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CSpriteData_setSubCmdID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CSpriteData:setSubCmdID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CSpriteData_setSubCmdID'", nullptr);
            return 0;
        }
        cobj->setSubCmdID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSpriteData:setSubCmdID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CSpriteData_setSubCmdID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CSpriteData_getType(lua_State* tolua_S)
{
    int argc = 0;
    CSpriteData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSpriteData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSpriteData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CSpriteData_getType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CSpriteData_getType'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSpriteData:getType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CSpriteData_getType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CSpriteData_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CSpriteData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSpriteData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSpriteData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CSpriteData_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CSpriteData_getSize'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSpriteData:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CSpriteData_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CSpriteData_getMainCmdID(lua_State* tolua_S)
{
    int argc = 0;
    CSpriteData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSpriteData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSpriteData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CSpriteData_getMainCmdID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CSpriteData_getMainCmdID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getMainCmdID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSpriteData:getMainCmdID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CSpriteData_getMainCmdID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CSpriteData_setMainCmdID(lua_State* tolua_S)
{
    int argc = 0;
    CSpriteData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSpriteData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSpriteData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CSpriteData_setMainCmdID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CSpriteData:setMainCmdID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CSpriteData_setMainCmdID'", nullptr);
            return 0;
        }
        cobj->setMainCmdID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSpriteData:setMainCmdID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CSpriteData_setMainCmdID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CSpriteData_getSubCmdID(lua_State* tolua_S)
{
    int argc = 0;
    CSpriteData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSpriteData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSpriteData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CSpriteData_getSubCmdID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CSpriteData_getSubCmdID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getSubCmdID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSpriteData:getSubCmdID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CSpriteData_getSubCmdID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CSpriteData_getData(lua_State* tolua_S)
{
    int argc = 0;
    CSpriteData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CSpriteData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CSpriteData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CSpriteData_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CSpriteData_getData'", nullptr);
            return 0;
        }
        char* ret = cobj->getData();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CSpriteData:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CSpriteData_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CSpriteData_socketData(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CSpriteData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 4)
        {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CSpriteData:socketData");
            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CSpriteData:socketData");
            if (!ok) { break; }
            const char* arg2;
            std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "CSpriteData:socketData"); arg2 = arg2_tmp.c_str();
            if (!ok) { break; }
            unsigned short arg3;
            ok &= luaval_to_ushort(tolua_S, 5, &arg3, "CSpriteData:socketData");
            if (!ok) { break; }
            CSpriteData* ret = CSpriteData::socketData(arg0, arg1, arg2, arg3);
            object_to_luaval<CSpriteData>(tolua_S, "CSpriteData",(CSpriteData*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CSpriteData:socketData"); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CSpriteData:socketData");
            if (!ok) { break; }
            CSpriteData* ret = CSpriteData::socketData(arg0, arg1);
            object_to_luaval<CSpriteData>(tolua_S, "CSpriteData",(CSpriteData*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CSpriteData:socketData"); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CSpriteData:socketData");
            if (!ok) { break; }
            _DataType arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "CSpriteData:socketData");
            if (!ok) { break; }
            CSpriteData* ret = CSpriteData::socketData(arg0, arg1, arg2);
            object_to_luaval<CSpriteData>(tolua_S, "CSpriteData",(CSpriteData*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "CSpriteData:socketData",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CSpriteData_socketData'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_net_CSpriteData_spriteData(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CSpriteData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CSpriteData:spriteData"); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CSpriteData:spriteData");
            if (!ok) { break; }
            CSpriteData* ret = CSpriteData::spriteData(arg0, arg1);
            object_to_luaval<CSpriteData>(tolua_S, "CSpriteData",(CSpriteData*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CSpriteData:spriteData"); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CSpriteData:spriteData");
            if (!ok) { break; }
            _DataType arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "CSpriteData:spriteData");
            if (!ok) { break; }
            CSpriteData* ret = CSpriteData::spriteData(arg0, arg1, arg2);
            object_to_luaval<CSpriteData>(tolua_S, "CSpriteData",(CSpriteData*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 4)
        {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CSpriteData:spriteData");
            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CSpriteData:spriteData");
            if (!ok) { break; }
            const char* arg2;
            std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "CSpriteData:spriteData"); arg2 = arg2_tmp.c_str();
            if (!ok) { break; }
            unsigned short arg3;
            ok &= luaval_to_ushort(tolua_S, 5, &arg3, "CSpriteData:spriteData");
            if (!ok) { break; }
            CSpriteData* ret = CSpriteData::spriteData(arg0, arg1, arg2, arg3);
            object_to_luaval<CSpriteData>(tolua_S, "CSpriteData",(CSpriteData*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "CSpriteData:spriteData",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CSpriteData_spriteData'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_net_CSpriteData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CSpriteData* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CSpriteData:CSpriteData"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CSpriteData:CSpriteData");

            if (!ok) { break; }
            cobj = new CSpriteData(arg0, arg1);
            cobj->autorelease();
            int ID =  (int)cobj->_ID ;
            int* luaID =  &cobj->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CSpriteData");
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CSpriteData:CSpriteData"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CSpriteData:CSpriteData");

            if (!ok) { break; }
            _DataType arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "CSpriteData:CSpriteData");

            if (!ok) { break; }
            cobj = new CSpriteData(arg0, arg1, arg2);
            cobj->autorelease();
            int ID =  (int)cobj->_ID ;
            int* luaID =  &cobj->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CSpriteData");
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            CSpriteData* arg0;
            ok &= luaval_to_object<CSpriteData>(tolua_S, 2, "CSpriteData",&arg0);

            if (!ok) { break; }
            cobj = new CSpriteData(arg0);
            cobj->autorelease();
            int ID =  (int)cobj->_ID ;
            int* luaID =  &cobj->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CSpriteData");
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 4) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CSpriteData:CSpriteData");

            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CSpriteData:CSpriteData");

            if (!ok) { break; }
            const char* arg2;
            std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "CSpriteData:CSpriteData"); arg2 = arg2_tmp.c_str();

            if (!ok) { break; }
            unsigned short arg3;
            ok &= luaval_to_ushort(tolua_S, 5, &arg3, "CSpriteData:CSpriteData");

            if (!ok) { break; }
            cobj = new CSpriteData(arg0, arg1, arg2, arg3);
            cobj->autorelease();
            int ID =  (int)cobj->_ID ;
            int* luaID =  &cobj->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CSpriteData");
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CSpriteData:CSpriteData",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CSpriteData_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_jt_net_CSpriteData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CSpriteData)");
    return 0;
}

int lua_register_jt_net_CSpriteData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CSpriteData");
    tolua_cclass(tolua_S,"CSpriteData","CSpriteData","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CSpriteData");
        tolua_function(tolua_S,"new",lua_jt_net_CSpriteData_constructor);
        tolua_function(tolua_S,"getBuffer",lua_jt_net_CSpriteData_getBuffer);
        tolua_function(tolua_S,"setSubCmdID",lua_jt_net_CSpriteData_setSubCmdID);
        tolua_function(tolua_S,"getType",lua_jt_net_CSpriteData_getType);
        tolua_function(tolua_S,"getSize",lua_jt_net_CSpriteData_getSize);
        tolua_function(tolua_S,"getMainCmdID",lua_jt_net_CSpriteData_getMainCmdID);
        tolua_function(tolua_S,"setMainCmdID",lua_jt_net_CSpriteData_setMainCmdID);
        tolua_function(tolua_S,"getSubCmdID",lua_jt_net_CSpriteData_getSubCmdID);
        tolua_function(tolua_S,"getData",lua_jt_net_CSpriteData_getData);
        tolua_function(tolua_S,"socketData", lua_jt_net_CSpriteData_socketData);
        tolua_function(tolua_S,"spriteData", lua_jt_net_CSpriteData_spriteData);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CSpriteData).name();
    g_luaType[typeName] = "CSpriteData";
    g_typeCast["CSpriteData"] = "CSpriteData";
    return 1;
}

int lua_jt_net_TCP_BufferRef_setMainCmdID(lua_State* tolua_S)
{
    int argc = 0;
    TCP_BufferRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TCP_BufferRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TCP_BufferRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_TCP_BufferRef_setMainCmdID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "TCP_BufferRef:setMainCmdID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_TCP_BufferRef_setMainCmdID'", nullptr);
            return 0;
        }
        cobj->setMainCmdID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TCP_BufferRef:setMainCmdID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_TCP_BufferRef_setMainCmdID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_TCP_BufferRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    TCP_BufferRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TCP_BufferRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TCP_BufferRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_TCP_BufferRef_setStruct'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        CNotify* arg0;

        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_TCP_BufferRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TCP_BufferRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_TCP_BufferRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_TCP_BufferRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    TCP_BufferRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TCP_BufferRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TCP_BufferRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_TCP_BufferRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_TCP_BufferRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TCP_BufferRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_TCP_BufferRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_TCP_BufferRef_setSubCmdID(lua_State* tolua_S)
{
    int argc = 0;
    TCP_BufferRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TCP_BufferRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TCP_BufferRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_TCP_BufferRef_setSubCmdID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "TCP_BufferRef:setSubCmdID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_TCP_BufferRef_setSubCmdID'", nullptr);
            return 0;
        }
        cobj->setSubCmdID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TCP_BufferRef:setSubCmdID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_TCP_BufferRef_setSubCmdID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_TCP_BufferRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    TCP_BufferRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TCP_BufferRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TCP_BufferRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_TCP_BufferRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_TCP_BufferRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TCP_BufferRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_TCP_BufferRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_TCP_BufferRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TCP_BufferRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_TCP_BufferRef_createWithNotify'", nullptr);
            return 0;
        }
        TCP_BufferRef* ret = TCP_BufferRef::createWithNotify();
        object_to_luaval<TCP_BufferRef>(tolua_S, "TCP_BufferRef",(TCP_BufferRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_TCP_BufferRef_createWithNotify'", nullptr);
            return 0;
        }
        TCP_BufferRef* ret = TCP_BufferRef::createWithNotify(arg0);
        object_to_luaval<TCP_BufferRef>(tolua_S, "TCP_BufferRef",(TCP_BufferRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "TCP_BufferRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_TCP_BufferRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_net_TCP_BufferRef_constructor(lua_State* tolua_S)
{
    int argc = 0;
    TCP_BufferRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_TCP_BufferRef_constructor'", nullptr);
            return 0;
        }
        cobj = new TCP_BufferRef();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"TCP_BufferRef");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TCP_BufferRef:TCP_BufferRef",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_TCP_BufferRef_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_jt_net_TCP_BufferRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TCP_BufferRef)");
    return 0;
}

int lua_register_jt_net_TCP_BufferRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"TCP_BufferRef");
    tolua_cclass(tolua_S,"TCP_BufferRef","TCP_BufferRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"TCP_BufferRef");
        tolua_function(tolua_S,"new",lua_jt_net_TCP_BufferRef_constructor);
        tolua_function(tolua_S,"setMainCmdID",lua_jt_net_TCP_BufferRef_setMainCmdID);
        tolua_function(tolua_S,"setStruct",lua_jt_net_TCP_BufferRef_setStruct);
        tolua_function(tolua_S,"getSize",lua_jt_net_TCP_BufferRef_getSize);
        tolua_function(tolua_S,"setSubCmdID",lua_jt_net_TCP_BufferRef_setSubCmdID);
        tolua_function(tolua_S,"getData",lua_jt_net_TCP_BufferRef_getData);
        tolua_function(tolua_S,"createWithNotify", lua_jt_net_TCP_BufferRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(TCP_BufferRef).name();
    g_luaType[typeName] = "TCP_BufferRef";
    g_typeCast["TCP_BufferRef"] = "TCP_BufferRef";
    return 1;
}

int lua_jt_net_CFrameData_getGenderID(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_getGenderID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_getGenderID'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getGenderID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:getGenderID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_getGenderID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithUserStatus(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithUserStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CFrameData:sendPacketWithUserStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithUserStatus'", nullptr);
            return 0;
        }
        cobj->sendPacketWithUserStatus(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithUserStatus",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithUserStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithGameOption(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithGameOption'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithGameOption'", nullptr);
            return 0;
        }
        cobj->sendPacketWithGameOption();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithGameOption",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithGameOption'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubUserEnter(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubUserEnter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubUserEnter");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubUserEnter'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubUserEnter(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubUserEnter",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubUserEnter'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubGRConfigServer(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubGRConfigServer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubGRConfigServer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubGRConfigServer'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubGRConfigServer(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubGRConfigServer",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubGRConfigServer'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubGRLogonFailure(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubGRLogonFailure'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubGRLogonFailure");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubGRLogonFailure'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubGRLogonFailure(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubGRLogonFailure",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubGRLogonFailure'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_getGameSkip(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_getGameSkip'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_getGameSkip'", nullptr);
            return 0;
        }
        bool ret = cobj->getGameSkip();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:getGameSkip",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_getGameSkip'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_getGameClientStatus(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_getGameClientStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_getGameClientStatus'", nullptr);
            return 0;
        }
        int ret = cobj->getGameClientStatus();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:getGameClientStatus",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_getGameClientStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubGRConfigFinish(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubGRConfigFinish'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubGRConfigFinish");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubGRConfigFinish'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubGRConfigFinish(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubGRConfigFinish",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubGRConfigFinish'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubLogonFailure(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubLogonFailure'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubLogonFailure");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubLogonFailure'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubLogonFailure(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubLogonFailure",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubLogonFailure'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithGPTakeScore(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithGPTakeScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        long long arg0;
        const char* arg1;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CFrameData:sendPacketWithGPTakeScore");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "CFrameData:sendPacketWithGPTakeScore"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithGPTakeScore'", nullptr);
            return 0;
        }
        cobj->sendPacketWithGPTakeScore(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithGPTakeScore",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithGPTakeScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnTCPNetworkMainMBUserProps(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnTCPNetworkMainMBUserProps'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned short arg0;
        void* arg1;
        unsigned short arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:OnTCPNetworkMainMBUserProps");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 4, &arg2, "CFrameData:OnTCPNetworkMainMBUserProps");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnTCPNetworkMainMBUserProps'", nullptr);
            return 0;
        }
        bool ret = cobj->OnTCPNetworkMainMBUserProps(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnTCPNetworkMainMBUserProps",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnTCPNetworkMainMBUserProps'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnTCPNetworkMainGRLogon(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGRLogon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned short arg0;
        void* arg1;
        unsigned short arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:OnTCPNetworkMainGRLogon");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 4, &arg2, "CFrameData:OnTCPNetworkMainGRLogon");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGRLogon'", nullptr);
            return 0;
        }
        bool ret = cobj->OnTCPNetworkMainGRLogon(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnTCPNetworkMainGRLogon",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGRLogon'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_setGameSkip(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_setGameSkip'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CFrameData:setGameSkip");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_setGameSkip'", nullptr);
            return 0;
        }
        cobj->setGameSkip(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:setGameSkip",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_setGameSkip'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnTCPNetworkMainGRUser(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGRUser'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned short arg0;
        void* arg1;
        unsigned short arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:OnTCPNetworkMainGRUser");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 4, &arg2, "CFrameData:OnTCPNetworkMainGRUser");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGRUser'", nullptr);
            return 0;
        }
        bool ret = cobj->OnTCPNetworkMainGRUser(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnTCPNetworkMainGRUser",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGRUser'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithRequestUserInfo(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithRequestUserInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned int arg0;
        unsigned short arg1;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CFrameData:sendPacketWithRequestUserInfo");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:sendPacketWithRequestUserInfo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithRequestUserInfo'", nullptr);
            return 0;
        }
        cobj->sendPacketWithRequestUserInfo(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithRequestUserInfo",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithRequestUserInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubGRUpdateNotify(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubGRUpdateNotify'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubGRUpdateNotify");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubGRUpdateNotify'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubGRUpdateNotify(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubGRUpdateNotify",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubGRUpdateNotify'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_doConnect(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_doConnect'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CFrameData:doConnect"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:doConnect");

            if (!ok) { break; }
            cobj->doConnect(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj->doConnect();
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CFrameData:doConnect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_doConnect'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubUserStatus(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubUserStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubUserStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubUserStatus'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubUserStatus(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubUserStatus",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubUserStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnTCPNetworkMDMGPUserService(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnTCPNetworkMDMGPUserService'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned short arg0;
        void* arg1;
        unsigned short arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:OnTCPNetworkMDMGPUserService");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 4, &arg2, "CFrameData:OnTCPNetworkMDMGPUserService");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnTCPNetworkMDMGPUserService'", nullptr);
            return 0;
        }
        bool ret = cobj->OnTCPNetworkMDMGPUserService(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnTCPNetworkMDMGPUserService",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnTCPNetworkMDMGPUserService'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubLogonAward(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubLogonAward'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubLogonAward");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubLogonAward'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubLogonAward(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubLogonAward",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubLogonAward'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubGPBankSucceed(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubGPBankSucceed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubGPBankSucceed");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubGPBankSucceed'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubGPBankSucceed(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubGPBankSucceed",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubGPBankSucceed'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubRequestDistribute(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubRequestDistribute'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubRequestDistribute");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubRequestDistribute'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubRequestDistribute(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubRequestDistribute",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubRequestDistribute'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_getLoginAddress(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_getLoginAddress'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_getLoginAddress'", nullptr);
            return 0;
        }
        std::string ret = cobj->getLoginAddress();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:getLoginAddress",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_getLoginAddress'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_getHotVersion(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_getHotVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_getHotVersion'", nullptr);
            return 0;
        }
        std::string ret = cobj->getHotVersion();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:getHotVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_getHotVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_setGenderID(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_setGenderID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CFrameData:setGenderID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_setGenderID'", nullptr);
            return 0;
        }
        cobj->setGenderID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:setGenderID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_setGenderID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubGRLogonSuccess(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubGRLogonSuccess'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubGRLogonSuccess");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubGRLogonSuccess'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubGRLogonSuccess(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubGRLogonSuccess",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubGRLogonSuccess'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubGRConfigPropepty(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubGRConfigPropepty'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubGRConfigPropepty");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubGRConfigPropepty'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubGRConfigPropepty(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubGRConfigPropepty",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubGRConfigPropepty'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnTCPNetworkMainGPLogon(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGPLogon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned short arg0;
        void* arg1;
        unsigned short arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:OnTCPNetworkMainGPLogon");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 4, &arg2, "CFrameData:OnTCPNetworkMainGPLogon");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGPLogon'", nullptr);
            return 0;
        }
        bool ret = cobj->OnTCPNetworkMainGPLogon(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnTCPNetworkMainGPLogon",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGPLogon'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_getUserID(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_getUserID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_getUserID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getUserID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:getUserID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_getUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithCompilatio(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithCompilatio'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CFrameData:sendPacketWithCompilatio"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->sendPacketWithCompilatio(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj->sendPacketWithCompilatio();
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CFrameData:sendPacketWithCompilatio",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithCompilatio'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubGRConfigColumn(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubGRConfigColumn'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubGRConfigColumn");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubGRConfigColumn'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubGRConfigColumn(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubGRConfigColumn",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubGRConfigColumn'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnTCPNetworkWithMBDataLoad(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnTCPNetworkWithMBDataLoad'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        unsigned short arg0;
        unsigned short arg1;
        void* arg2;
        unsigned short arg3;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:OnTCPNetworkWithMBDataLoad");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnTCPNetworkWithMBDataLoad");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 5, &arg3, "CFrameData:OnTCPNetworkWithMBDataLoad");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnTCPNetworkWithMBDataLoad'", nullptr);
            return 0;
        }
        bool ret = cobj->OnTCPNetworkWithMBDataLoad(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnTCPNetworkWithMBDataLoad",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnTCPNetworkWithMBDataLoad'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithUserChat(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithUserChat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned int arg0;
        const char* arg1;
        unsigned short arg2;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CFrameData:sendPacketWithUserChat");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "CFrameData:sendPacketWithUserChat"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_ushort(tolua_S, 4, &arg2, "CFrameData:sendPacketWithUserChat");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithUserChat'", nullptr);
            return 0;
        }
        cobj->sendPacketWithUserChat(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithUserChat",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithUserChat'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_setLoginAddress(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_setLoginAddress'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CFrameData:setLoginAddress");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_setLoginAddress'", nullptr);
            return 0;
        }
        cobj->setLoginAddress(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:setLoginAddress",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_setLoginAddress'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_getDeviceType(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_getDeviceType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_getDeviceType'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getDeviceType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:getDeviceType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_getDeviceType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_getPlazaVersion(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_getPlazaVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_getPlazaVersion'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getPlazaVersion();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:getPlazaVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_getPlazaVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_setChairID(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_setChairID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:setChairID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_setChairID'", nullptr);
            return 0;
        }
        cobj->setChairID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:setChairID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_setChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubSpeakerNews(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubSpeakerNews'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubSpeakerNews");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubSpeakerNews'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubSpeakerNews(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubSpeakerNews",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubSpeakerNews'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubUserGold(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubUserGold'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubUserGold");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubUserGold'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubUserGold(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubUserGold",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubUserGold'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubGPBankFailure(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubGPBankFailure'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubGPBankFailure");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubGPBankFailure'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubGPBankFailure(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubGPBankFailure",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubGPBankFailure'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithRequestChairUserInfo(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithRequestChairUserInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned short arg0;
        unsigned short arg1;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:sendPacketWithRequestChairUserInfo");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:sendPacketWithRequestChairUserInfo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithRequestChairUserInfo'", nullptr);
            return 0;
        }
        cobj->sendPacketWithRequestChairUserInfo(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithRequestChairUserInfo",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithRequestChairUserInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubLogonSuccess(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubLogonSuccess'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubLogonSuccess");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubLogonSuccess'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubLogonSuccess(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubLogonSuccess",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubLogonSuccess'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnTCPNetworkMainMBServerList(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnTCPNetworkMainMBServerList'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned short arg0;
        void* arg1;
        unsigned short arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:OnTCPNetworkMainMBServerList");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 4, &arg2, "CFrameData:OnTCPNetworkMainMBServerList");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnTCPNetworkMainMBServerList'", nullptr);
            return 0;
        }
        bool ret = cobj->OnTCPNetworkMainMBServerList(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnTCPNetworkMainMBServerList",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnTCPNetworkMainMBServerList'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnTCPNetworkMainMBLogon(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnTCPNetworkMainMBLogon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned short arg0;
        void* arg1;
        unsigned short arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:OnTCPNetworkMainMBLogon");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 4, &arg2, "CFrameData:OnTCPNetworkMainMBLogon");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnTCPNetworkMainMBLogon'", nullptr);
            return 0;
        }
        bool ret = cobj->OnTCPNetworkMainMBLogon(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnTCPNetworkMainMBLogon",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnTCPNetworkMainMBLogon'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithCutoverTable(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithCutoverTable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithCutoverTable'", nullptr);
            return 0;
        }
        cobj->sendPacketWithCutoverTable();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithCutoverTable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithCutoverTable'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_setTableID(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_setTableID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:setTableID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_setTableID'", nullptr);
            return 0;
        }
        cobj->setTableID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:setTableID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_setTableID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubUserScore(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubUserScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubUserScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubUserScore'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubUserScore(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubUserScore",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubUserScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubGRLogonFinish(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubGRLogonFinish'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubGRLogonFinish");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubGRLogonFinish'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubGRLogonFinish(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubGRLogonFinish",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubGRLogonFinish'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_isEnterBackground(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_isEnterBackground'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_isEnterBackground'", nullptr);
            return 0;
        }
        bool ret = cobj->isEnterBackground();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:isEnterBackground",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_isEnterBackground'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnTCPNetworkMainGRConfig(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGRConfig'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned short arg0;
        void* arg1;
        unsigned short arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:OnTCPNetworkMainGRConfig");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 4, &arg2, "CFrameData:OnTCPNetworkMainGRConfig");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGRConfig'", nullptr);
            return 0;
        }
        bool ret = cobj->OnTCPNetworkMainGRConfig(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnTCPNetworkMainGRConfig",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGRConfig'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_getChairID(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_getChairID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_getChairID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getChairID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:getChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_getChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubRequestFailure(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubRequestFailure'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubRequestFailure");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubRequestFailure'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubRequestFailure(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubRequestFailure",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubRequestFailure'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithQuickStart(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithQuickStart'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithQuickStart'", nullptr);
            return 0;
        }
        cobj->sendPacketWithQuickStart();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithQuickStart",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithQuickStart'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithGPSaveScore(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithGPSaveScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CFrameData:sendPacketWithGPSaveScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithGPSaveScore'", nullptr);
            return 0;
        }
        cobj->sendPacketWithGPSaveScore(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithGPSaveScore",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithGPSaveScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithUserExpression(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithUserExpression'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned int arg0;
        unsigned short arg1;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CFrameData:sendPacketWithUserExpression");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:sendPacketWithUserExpression");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithUserExpression'", nullptr);
            return 0;
        }
        cobj->sendPacketWithUserExpression(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithUserExpression",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithUserExpression'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_getDataArraySize(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_getDataArraySize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_getDataArraySize'", nullptr);
            return 0;
        }
        ssize_t ret = cobj->getDataArraySize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:getDataArraySize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_getDataArraySize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithGPTransferScore(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithGPTransferScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        long long arg0;
        const char* arg1;
        uint16_t arg2;
        const char* arg3;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CFrameData:sendPacketWithGPTransferScore");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "CFrameData:sendPacketWithGPTransferScore"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_uint16(tolua_S, 4,&arg2, "CFrameData:sendPacketWithGPTransferScore");

        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp, "CFrameData:sendPacketWithGPTransferScore"); arg3 = arg3_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithGPTransferScore'", nullptr);
            return 0;
        }
        cobj->sendPacketWithGPTransferScore(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithGPTransferScore",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithGPTransferScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_getSocketConnect(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_getSocketConnect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_getSocketConnect'", nullptr);
            return 0;
        }
        bool ret = cobj->getSocketConnect();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:getSocketConnect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_getSocketConnect'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_setKindID(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_setKindID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CFrameData:setKindID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_setKindID'", nullptr);
            return 0;
        }
        cobj->setKindID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:setKindID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_setKindID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnTCPNetworkWithGRDataRoom(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnTCPNetworkWithGRDataRoom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        unsigned short arg0;
        unsigned short arg1;
        void* arg2;
        unsigned short arg3;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:OnTCPNetworkWithGRDataRoom");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnTCPNetworkWithGRDataRoom");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 5, &arg3, "CFrameData:OnTCPNetworkWithGRDataRoom");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnTCPNetworkWithGRDataRoom'", nullptr);
            return 0;
        }
        bool ret = cobj->OnTCPNetworkWithGRDataRoom(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnTCPNetworkWithGRDataRoom",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnTCPNetworkWithGRDataRoom'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_setValidateKey(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_setValidateKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CFrameData:setValidateKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_setValidateKey'", nullptr);
            return 0;
        }
        cobj->setValidateKey(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:setValidateKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_setValidateKey'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_setIsEnterBackground(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_setIsEnterBackground'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CFrameData:setIsEnterBackground");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_setIsEnterBackground'", nullptr);
            return 0;
        }
        cobj->setIsEnterBackground(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:setIsEnterBackground",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_setIsEnterBackground'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendUserHorn(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendUserHorn'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CFrameData:sendUserHorn"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "CFrameData:sendUserHorn"); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            cobj->sendUserHorn(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CFrameData:sendUserHorn"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->sendUserHorn(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CFrameData:sendUserHorn",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendUserHorn'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubGPInsureInfo(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubGPInsureInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubGPInsureInfo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubGPInsureInfo'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubGPInsureInfo(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubGPInsureInfo",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubGPInsureInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithModifyIndividual(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithModifyIndividual'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 5) 
    {
        const char* arg0;
        uint16_t arg1;
        unsigned int arg2;
        const char* arg3;
        bool arg4;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CFrameData:sendPacketWithModifyIndividual"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_uint16(tolua_S, 3,&arg1, "CFrameData:sendPacketWithModifyIndividual");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "CFrameData:sendPacketWithModifyIndividual");

        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp, "CFrameData:sendPacketWithModifyIndividual"); arg3 = arg3_tmp.c_str();

        ok &= luaval_to_boolean(tolua_S, 6,&arg4, "CFrameData:sendPacketWithModifyIndividual");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithModifyIndividual'", nullptr);
            return 0;
        }
        cobj->sendPacketWithModifyIndividual(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithModifyIndividual",argc, 5);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithModifyIndividual'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubGFSystemMessage(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubGFSystemMessage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubGFSystemMessage");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubGFSystemMessage'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubGFSystemMessage(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubGFSystemMessage",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubGFSystemMessage'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_setHotVersion(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_setHotVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CFrameData:setHotVersion"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_setHotVersion'", nullptr);
            return 0;
        }
        cobj->setHotVersion(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:setHotVersion",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_setHotVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_setUserID(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_setUserID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CFrameData:setUserID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_setUserID'", nullptr);
            return 0;
        }
        cobj->setUserID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:setUserID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_setUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_getLoginPort(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_getLoginPort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_getLoginPort'", nullptr);
            return 0;
        }
        const unsigned short ret = cobj->getLoginPort();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:getLoginPort",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_getLoginPort'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnTCPNetworkMainGFFrame(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGFFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned short arg0;
        void* arg1;
        unsigned short arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:OnTCPNetworkMainGFFrame");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 4, &arg2, "CFrameData:OnTCPNetworkMainGFFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGFFrame'", nullptr);
            return 0;
        }
        bool ret = cobj->OnTCPNetworkMainGFFrame(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnTCPNetworkMainGFFrame",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGFFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithUserLogon(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithUserLogon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        CLogonData* arg0;

        ok &= luaval_to_object<CLogonData>(tolua_S, 2, "CLogonData",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithUserLogon'", nullptr);
            return 0;
        }
        cobj->sendPacketWithUserLogon(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithUserLogon",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithUserLogon'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_getSender(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_getSender'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_getSender'", nullptr);
            return 0;
        }
        cocos2d::Ref* ret = cobj->getSender();
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:getSender",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_getSender'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_setSocketLogic(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_setSocketLogic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CFrameData:setSocketLogic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_setSocketLogic'", nullptr);
            return 0;
        }
        cobj->setSocketLogic(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:setSocketLogic",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_setSocketLogic'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubMBGetPropsInfo(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubMBGetPropsInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubMBGetPropsInfo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubMBGetPropsInfo'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubMBGetPropsInfo(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubMBGetPropsInfo",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubMBGetPropsInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendData(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendData'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            void* arg0;
            #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:sendData");

            if (!ok) { break; }
            cobj->sendData(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            CMD_BASE* arg0;
            ok &= luaval_to_object<CMD_BASE>(tolua_S, 2, "CMD_BASE",&arg0);

            if (!ok) { break; }
            cobj->sendData(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:sendData");

            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:sendData");

            if (!ok) { break; }
            cobj->sendData(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:sendData");

            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:sendData");

            if (!ok) { break; }
            CMD_BASE* arg2;
            ok &= luaval_to_object<CMD_BASE>(tolua_S, 4, "CMD_BASE",&arg2);

            if (!ok) { break; }
            cobj->sendData(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 4) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:sendData");

            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:sendData");

            if (!ok) { break; }
            void* arg2;
            #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

            if (!ok) { break; }
            unsigned short arg3;
            ok &= luaval_to_ushort(tolua_S, 5, &arg3, "CFrameData:sendData");

            if (!ok) { break; }
            cobj->sendData(arg0, arg1, arg2, arg3);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CFrameData:sendData",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_getTableID(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_getTableID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_getTableID'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->getTableID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:getTableID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_getTableID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubMBUpdateNotify(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubMBUpdateNotify'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubMBUpdateNotify");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubMBUpdateNotify'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubMBUpdateNotify(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubMBUpdateNotify",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubMBUpdateNotify'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnTCPNetworkGRBankInsure(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnTCPNetworkGRBankInsure'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned short arg0;
        void* arg1;
        unsigned short arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:OnTCPNetworkGRBankInsure");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 4, &arg2, "CFrameData:OnTCPNetworkGRBankInsure");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnTCPNetworkGRBankInsure'", nullptr);
            return 0;
        }
        bool ret = cobj->OnTCPNetworkGRBankInsure(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnTCPNetworkGRBankInsure",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnTCPNetworkGRBankInsure'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubListKind(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubListKind'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubListKind");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubListKind'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubListKind(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubListKind",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubListKind'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnTCPNetworkMainGame(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned short arg0;
        void* arg1;
        unsigned short arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:OnTCPNetworkMainGame");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 4, &arg2, "CFrameData:OnTCPNetworkMainGame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGame'", nullptr);
            return 0;
        }
        bool ret = cobj->OnTCPNetworkMainGame(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnTCPNetworkMainGame",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGame'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithRankInfo(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithRankInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithRankInfo'", nullptr);
            return 0;
        }
        cobj->sendPacketWithRankInfo();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithRankInfo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithRankInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubGFGameStatus(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubGFGameStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubGFGameStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubGFGameStatus'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubGFGameStatus(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubGFGameStatus",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubGFGameStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubGFUserChat(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubGFUserChat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubGFUserChat");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubGFUserChat'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubGFUserChat(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubGFUserChat",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubGFUserChat'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubListFinish(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubListFinish'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubListFinish");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubListFinish'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubListFinish(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubListFinish",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubListFinish'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_getGameID(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_getGameID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_getGameID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getGameID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:getGameID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_getGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_SocketDelegateWithCloseNotify(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_SocketDelegateWithCloseNotify'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_SocketDelegateWithCloseNotify'", nullptr);
            return 0;
        }
        cobj->SocketDelegateWithCloseNotify();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:SocketDelegateWithCloseNotify",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_SocketDelegateWithCloseNotify'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_setLoginPort(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_setLoginPort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:setLoginPort");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_setLoginPort'", nullptr);
            return 0;
        }
        cobj->setLoginPort(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:setLoginPort",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_setLoginPort'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendSocketData(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendSocketData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        TCP_BufferRef* arg0;
        unsigned short arg1;

        ok &= luaval_to_object<TCP_BufferRef>(tolua_S, 2, "TCP_BufferRef",&arg0);

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:sendSocketData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendSocketData'", nullptr);
            return 0;
        }
        cobj->sendSocketData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendSocketData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendSocketData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithSitDown(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithSitDown'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned short arg0;
        unsigned short arg1;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:sendPacketWithSitDown");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:sendPacketWithSitDown");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithSitDown'", nullptr);
            return 0;
        }
        cobj->sendPacketWithSitDown(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithSitDown",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithSitDown'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_SocketDelegateWithRecvData(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_SocketDelegateWithRecvData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        CSpriteData* arg0;

        ok &= luaval_to_object<CSpriteData>(tolua_S, 2, "CSpriteData",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_SocketDelegateWithRecvData'", nullptr);
            return 0;
        }
        bool ret = cobj->SocketDelegateWithRecvData(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:SocketDelegateWithRecvData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_SocketDelegateWithRecvData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubGFGameScene(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubGFGameScene'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubGFGameScene");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubGFGameScene'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubGFGameScene(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubGFGameScene",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubGFGameScene'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnTCPNetworkMainGRStatus(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGRStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned short arg0;
        void* arg1;
        unsigned short arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:OnTCPNetworkMainGRStatus");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 4, &arg2, "CFrameData:OnTCPNetworkMainGRStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGRStatus'", nullptr);
            return 0;
        }
        bool ret = cobj->OnTCPNetworkMainGRStatus(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnTCPNetworkMainGRStatus",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnTCPNetworkMainGRStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithGPTransferRecord(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithGPTransferRecord'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned int arg0;
        unsigned int arg1;
        unsigned short arg2;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CFrameData:sendPacketWithGPTransferRecord");

        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "CFrameData:sendPacketWithGPTransferRecord");

        ok &= luaval_to_ushort(tolua_S, 4, &arg2, "CFrameData:sendPacketWithGPTransferRecord");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithGPTransferRecord'", nullptr);
            return 0;
        }
        cobj->sendPacketWithGPTransferRecord(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithGPTransferRecord",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithGPTransferRecord'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_setPlazaVersion(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_setPlazaVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CFrameData:setPlazaVersion");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_setPlazaVersion'", nullptr);
            return 0;
        }
        cobj->setPlazaVersion(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:setPlazaVersion",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_setPlazaVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_isSocketClosed(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_isSocketClosed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_isSocketClosed'", nullptr);
            return 0;
        }
        bool ret = cobj->isSocketClosed();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:isSocketClosed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_isSocketClosed'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithGPInsureInfo(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithGPInsureInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CFrameData:sendPacketWithGPInsureInfo"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithGPInsureInfo'", nullptr);
            return 0;
        }
        cobj->sendPacketWithGPInsureInfo(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithGPInsureInfo",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithGPInsureInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithQuickJin(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithQuickJin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithQuickJin'", nullptr);
            return 0;
        }
        cobj->sendPacketWithQuickJin();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithQuickJin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithQuickJin'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubGFUserExpression(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubGFUserExpression'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubGFUserExpression");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubGFUserExpression'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubGFUserExpression(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubGFUserExpression",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubGFUserExpression'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_setSocketClose(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_setSocketClose'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_setSocketClose'", nullptr);
            return 0;
        }
        cobj->setSocketClose();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CFrameData:setSocketClose");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_setSocketClose'", nullptr);
            return 0;
        }
        cobj->setSocketClose(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:setSocketClose",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_setSocketClose'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_SocketDelegateWithConnectNotfiy(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_SocketDelegateWithConnectNotfiy'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CFrameData:SocketDelegateWithConnectNotfiy");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_SocketDelegateWithConnectNotfiy'", nullptr);
            return 0;
        }
        cobj->SocketDelegateWithConnectNotfiy(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:SocketDelegateWithConnectNotfiy",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_SocketDelegateWithConnectNotfiy'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_getValidateKey(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_getValidateKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_getValidateKey'", nullptr);
            return 0;
        }
        std::string ret = cobj->getValidateKey();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:getValidateKey",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_getValidateKey'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithEnterRoomPageCount(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithEnterRoomPageCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned short arg0;
        tagGameServerRef* arg1;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:sendPacketWithEnterRoomPageCount");

        ok &= luaval_to_object<tagGameServerRef>(tolua_S, 3, "tagGameServerRef",&arg1);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithEnterRoomPageCount'", nullptr);
            return 0;
        }
        cobj->sendPacketWithEnterRoomPageCount(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithEnterRoomPageCount",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithEnterRoomPageCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_setGameID(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_setGameID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CFrameData:setGameID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_setGameID'", nullptr);
            return 0;
        }
        cobj->setGameID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:setGameID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_setGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithStandUpLeave(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithStandUpLeave'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CFrameData:sendPacketWithStandUpLeave");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithStandUpLeave'", nullptr);
            return 0;
        }
        cobj->sendPacketWithStandUpLeave(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithStandUpLeave",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithStandUpLeave'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_setDeviceType(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_setDeviceType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CFrameData:setDeviceType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_setDeviceType'", nullptr);
            return 0;
        }
        cobj->setDeviceType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:setDeviceType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_setDeviceType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_sendPacketWithUserRule(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_sendPacketWithUserRule'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_sendPacketWithUserRule'", nullptr);
            return 0;
        }
        cobj->sendPacketWithUserRule();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:sendPacketWithUserRule",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_sendPacketWithUserRule'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnTCPNetworkMainCMSystem(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnTCPNetworkMainCMSystem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned short arg0;
        void* arg1;
        unsigned short arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:OnTCPNetworkMainCMSystem");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 4, &arg2, "CFrameData:OnTCPNetworkMainCMSystem");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnTCPNetworkMainCMSystem'", nullptr);
            return 0;
        }
        bool ret = cobj->OnTCPNetworkMainCMSystem(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnTCPNetworkMainCMSystem",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnTCPNetworkMainCMSystem'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnTCPNetworkMainMBVerify(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnTCPNetworkMainMBVerify'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned short arg0;
        void* arg1;
        unsigned short arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:OnTCPNetworkMainMBVerify");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 4, &arg2, "CFrameData:OnTCPNetworkMainMBVerify");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnTCPNetworkMainMBVerify'", nullptr);
            return 0;
        }
        bool ret = cobj->OnTCPNetworkMainMBVerify(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnTCPNetworkMainMBVerify",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnTCPNetworkMainMBVerify'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_getKindID(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_getKindID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_getKindID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getKindID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:getKindID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_getKindID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnTCPNewordkWithKNCommon(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnTCPNewordkWithKNCommon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        unsigned short arg0;
        unsigned short arg1;
        void* arg2;
        unsigned short arg3;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CFrameData:OnTCPNewordkWithKNCommon");

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnTCPNewordkWithKNCommon");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 5, &arg3, "CFrameData:OnTCPNewordkWithKNCommon");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnTCPNewordkWithKNCommon'", nullptr);
            return 0;
        }
        bool ret = cobj->OnTCPNewordkWithKNCommon(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnTCPNewordkWithKNCommon",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnTCPNewordkWithKNCommon'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_OnSocketSubListServer(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CFrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CFrameData_OnSocketSubListServer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        unsigned short arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "CFrameData:OnSocketSubListServer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_OnSocketSubListServer'", nullptr);
            return 0;
        }
        bool ret = cobj->OnSocketSubListServer(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:OnSocketSubListServer",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_OnSocketSubListServer'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CFrameData_createFrameData(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_createFrameData'", nullptr);
            return 0;
        }
        CFrameData* ret = CFrameData::createFrameData();
        object_to_luaval<CFrameData>(tolua_S, "CFrameData",(CFrameData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CFrameData:createFrameData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_createFrameData'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_net_CFrameData_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CFrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_getInstance'", nullptr);
            return 0;
        }
        CFrameData* ret = CFrameData::getInstance();
        object_to_luaval<CFrameData>(tolua_S, "CFrameData",(CFrameData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CFrameData:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_net_CFrameData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CFrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CFrameData_constructor'", nullptr);
            return 0;
        }
        cobj = new CFrameData();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CFrameData");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CFrameData:CFrameData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CFrameData_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_jt_net_CFrameData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CFrameData)");
    return 0;
}

int lua_register_jt_net_CFrameData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CFrameData");
    tolua_cclass(tolua_S,"CFrameData","CFrameData","TCPSocketDelegate",nullptr);

    tolua_beginmodule(tolua_S,"CFrameData");
        tolua_function(tolua_S,"new",lua_jt_net_CFrameData_constructor);
        tolua_function(tolua_S,"getGenderID",lua_jt_net_CFrameData_getGenderID);
        tolua_function(tolua_S,"sendPacketWithUserStatus",lua_jt_net_CFrameData_sendPacketWithUserStatus);
        tolua_function(tolua_S,"sendPacketWithGameOption",lua_jt_net_CFrameData_sendPacketWithGameOption);
        tolua_function(tolua_S,"OnSocketSubUserEnter",lua_jt_net_CFrameData_OnSocketSubUserEnter);
        tolua_function(tolua_S,"OnSocketSubGRConfigServer",lua_jt_net_CFrameData_OnSocketSubGRConfigServer);
        tolua_function(tolua_S,"OnSocketSubGRLogonFailure",lua_jt_net_CFrameData_OnSocketSubGRLogonFailure);
        tolua_function(tolua_S,"getGameSkip",lua_jt_net_CFrameData_getGameSkip);
        tolua_function(tolua_S,"getGameClientStatus",lua_jt_net_CFrameData_getGameClientStatus);
        tolua_function(tolua_S,"OnSocketSubGRConfigFinish",lua_jt_net_CFrameData_OnSocketSubGRConfigFinish);
        tolua_function(tolua_S,"OnSocketSubLogonFailure",lua_jt_net_CFrameData_OnSocketSubLogonFailure);
        tolua_function(tolua_S,"sendPacketWithGPTakeScore",lua_jt_net_CFrameData_sendPacketWithGPTakeScore);
        tolua_function(tolua_S,"OnTCPNetworkMainMBUserProps",lua_jt_net_CFrameData_OnTCPNetworkMainMBUserProps);
        tolua_function(tolua_S,"OnTCPNetworkMainGRLogon",lua_jt_net_CFrameData_OnTCPNetworkMainGRLogon);
        tolua_function(tolua_S,"setGameSkip",lua_jt_net_CFrameData_setGameSkip);
        tolua_function(tolua_S,"OnTCPNetworkMainGRUser",lua_jt_net_CFrameData_OnTCPNetworkMainGRUser);
        tolua_function(tolua_S,"sendPacketWithRequestUserInfo",lua_jt_net_CFrameData_sendPacketWithRequestUserInfo);
        tolua_function(tolua_S,"OnSocketSubGRUpdateNotify",lua_jt_net_CFrameData_OnSocketSubGRUpdateNotify);
        tolua_function(tolua_S,"doConnect",lua_jt_net_CFrameData_doConnect);
        tolua_function(tolua_S,"OnSocketSubUserStatus",lua_jt_net_CFrameData_OnSocketSubUserStatus);
        tolua_function(tolua_S,"OnTCPNetworkMDMGPUserService",lua_jt_net_CFrameData_OnTCPNetworkMDMGPUserService);
        tolua_function(tolua_S,"OnSocketSubLogonAward",lua_jt_net_CFrameData_OnSocketSubLogonAward);
        tolua_function(tolua_S,"OnSocketSubGPBankSucceed",lua_jt_net_CFrameData_OnSocketSubGPBankSucceed);
        tolua_function(tolua_S,"OnSocketSubRequestDistribute",lua_jt_net_CFrameData_OnSocketSubRequestDistribute);
        tolua_function(tolua_S,"getLoginAddress",lua_jt_net_CFrameData_getLoginAddress);
        tolua_function(tolua_S,"getHotVersion",lua_jt_net_CFrameData_getHotVersion);
        tolua_function(tolua_S,"setGenderID",lua_jt_net_CFrameData_setGenderID);
        tolua_function(tolua_S,"OnSocketSubGRLogonSuccess",lua_jt_net_CFrameData_OnSocketSubGRLogonSuccess);
        tolua_function(tolua_S,"OnSocketSubGRConfigPropepty",lua_jt_net_CFrameData_OnSocketSubGRConfigPropepty);
        tolua_function(tolua_S,"OnTCPNetworkMainGPLogon",lua_jt_net_CFrameData_OnTCPNetworkMainGPLogon);
        tolua_function(tolua_S,"getUserID",lua_jt_net_CFrameData_getUserID);
        tolua_function(tolua_S,"sendPacketWithCompilatio",lua_jt_net_CFrameData_sendPacketWithCompilatio);
        tolua_function(tolua_S,"OnSocketSubGRConfigColumn",lua_jt_net_CFrameData_OnSocketSubGRConfigColumn);
        tolua_function(tolua_S,"OnTCPNetworkWithMBDataLoad",lua_jt_net_CFrameData_OnTCPNetworkWithMBDataLoad);
        tolua_function(tolua_S,"sendPacketWithUserChat",lua_jt_net_CFrameData_sendPacketWithUserChat);
        tolua_function(tolua_S,"setLoginAddress",lua_jt_net_CFrameData_setLoginAddress);
        tolua_function(tolua_S,"getDeviceType",lua_jt_net_CFrameData_getDeviceType);
        tolua_function(tolua_S,"getPlazaVersion",lua_jt_net_CFrameData_getPlazaVersion);
        tolua_function(tolua_S,"setChairID",lua_jt_net_CFrameData_setChairID);
        tolua_function(tolua_S,"OnSocketSubSpeakerNews",lua_jt_net_CFrameData_OnSocketSubSpeakerNews);
        tolua_function(tolua_S,"OnSocketSubUserGold",lua_jt_net_CFrameData_OnSocketSubUserGold);
        tolua_function(tolua_S,"OnSocketSubGPBankFailure",lua_jt_net_CFrameData_OnSocketSubGPBankFailure);
        tolua_function(tolua_S,"sendPacketWithRequestChairUserInfo",lua_jt_net_CFrameData_sendPacketWithRequestChairUserInfo);
        tolua_function(tolua_S,"OnSocketSubLogonSuccess",lua_jt_net_CFrameData_OnSocketSubLogonSuccess);
        tolua_function(tolua_S,"OnTCPNetworkMainMBServerList",lua_jt_net_CFrameData_OnTCPNetworkMainMBServerList);
        tolua_function(tolua_S,"OnTCPNetworkMainMBLogon",lua_jt_net_CFrameData_OnTCPNetworkMainMBLogon);
        tolua_function(tolua_S,"sendPacketWithCutoverTable",lua_jt_net_CFrameData_sendPacketWithCutoverTable);
        tolua_function(tolua_S,"setTableID",lua_jt_net_CFrameData_setTableID);
        tolua_function(tolua_S,"OnSocketSubUserScore",lua_jt_net_CFrameData_OnSocketSubUserScore);
        tolua_function(tolua_S,"OnSocketSubGRLogonFinish",lua_jt_net_CFrameData_OnSocketSubGRLogonFinish);
        tolua_function(tolua_S,"isEnterBackground",lua_jt_net_CFrameData_isEnterBackground);
        tolua_function(tolua_S,"OnTCPNetworkMainGRConfig",lua_jt_net_CFrameData_OnTCPNetworkMainGRConfig);
        tolua_function(tolua_S,"getChairID",lua_jt_net_CFrameData_getChairID);
        tolua_function(tolua_S,"OnSocketSubRequestFailure",lua_jt_net_CFrameData_OnSocketSubRequestFailure);
        tolua_function(tolua_S,"sendPacketWithQuickStart",lua_jt_net_CFrameData_sendPacketWithQuickStart);
        tolua_function(tolua_S,"sendPacketWithGPSaveScore",lua_jt_net_CFrameData_sendPacketWithGPSaveScore);
        tolua_function(tolua_S,"sendPacketWithUserExpression",lua_jt_net_CFrameData_sendPacketWithUserExpression);
        tolua_function(tolua_S,"getDataArraySize",lua_jt_net_CFrameData_getDataArraySize);
        tolua_function(tolua_S,"sendPacketWithGPTransferScore",lua_jt_net_CFrameData_sendPacketWithGPTransferScore);
        tolua_function(tolua_S,"getSocketConnect",lua_jt_net_CFrameData_getSocketConnect);
        tolua_function(tolua_S,"setKindID",lua_jt_net_CFrameData_setKindID);
        tolua_function(tolua_S,"OnTCPNetworkWithGRDataRoom",lua_jt_net_CFrameData_OnTCPNetworkWithGRDataRoom);
        tolua_function(tolua_S,"setValidateKey",lua_jt_net_CFrameData_setValidateKey);
        tolua_function(tolua_S,"setIsEnterBackground",lua_jt_net_CFrameData_setIsEnterBackground);
        tolua_function(tolua_S,"sendUserHorn",lua_jt_net_CFrameData_sendUserHorn);
        tolua_function(tolua_S,"OnSocketSubGPInsureInfo",lua_jt_net_CFrameData_OnSocketSubGPInsureInfo);
        tolua_function(tolua_S,"sendPacketWithModifyIndividual",lua_jt_net_CFrameData_sendPacketWithModifyIndividual);
        tolua_function(tolua_S,"OnSocketSubGFSystemMessage",lua_jt_net_CFrameData_OnSocketSubGFSystemMessage);
        tolua_function(tolua_S,"setHotVersion",lua_jt_net_CFrameData_setHotVersion);
        tolua_function(tolua_S,"setUserID",lua_jt_net_CFrameData_setUserID);
        tolua_function(tolua_S,"getLoginPort",lua_jt_net_CFrameData_getLoginPort);
        tolua_function(tolua_S,"OnTCPNetworkMainGFFrame",lua_jt_net_CFrameData_OnTCPNetworkMainGFFrame);
        tolua_function(tolua_S,"sendPacketWithUserLogon",lua_jt_net_CFrameData_sendPacketWithUserLogon);
        tolua_function(tolua_S,"getSender",lua_jt_net_CFrameData_getSender);
        tolua_function(tolua_S,"setSocketLogic",lua_jt_net_CFrameData_setSocketLogic);
        tolua_function(tolua_S,"OnSocketSubMBGetPropsInfo",lua_jt_net_CFrameData_OnSocketSubMBGetPropsInfo);
        tolua_function(tolua_S,"sendData",lua_jt_net_CFrameData_sendData);
        tolua_function(tolua_S,"getTableID",lua_jt_net_CFrameData_getTableID);
        tolua_function(tolua_S,"OnSocketSubMBUpdateNotify",lua_jt_net_CFrameData_OnSocketSubMBUpdateNotify);
        tolua_function(tolua_S,"OnTCPNetworkGRBankInsure",lua_jt_net_CFrameData_OnTCPNetworkGRBankInsure);
        tolua_function(tolua_S,"OnSocketSubListKind",lua_jt_net_CFrameData_OnSocketSubListKind);
        tolua_function(tolua_S,"OnTCPNetworkMainGame",lua_jt_net_CFrameData_OnTCPNetworkMainGame);
        tolua_function(tolua_S,"sendPacketWithRankInfo",lua_jt_net_CFrameData_sendPacketWithRankInfo);
        tolua_function(tolua_S,"OnSocketSubGFGameStatus",lua_jt_net_CFrameData_OnSocketSubGFGameStatus);
        tolua_function(tolua_S,"OnSocketSubGFUserChat",lua_jt_net_CFrameData_OnSocketSubGFUserChat);
        tolua_function(tolua_S,"OnSocketSubListFinish",lua_jt_net_CFrameData_OnSocketSubListFinish);
        tolua_function(tolua_S,"getGameID",lua_jt_net_CFrameData_getGameID);
        tolua_function(tolua_S,"SocketDelegateWithCloseNotify",lua_jt_net_CFrameData_SocketDelegateWithCloseNotify);
        tolua_function(tolua_S,"setLoginPort",lua_jt_net_CFrameData_setLoginPort);
        tolua_function(tolua_S,"sendSocketData",lua_jt_net_CFrameData_sendSocketData);
        tolua_function(tolua_S,"sendPacketWithSitDown",lua_jt_net_CFrameData_sendPacketWithSitDown);
        tolua_function(tolua_S,"SocketDelegateWithRecvData",lua_jt_net_CFrameData_SocketDelegateWithRecvData);
        tolua_function(tolua_S,"OnSocketSubGFGameScene",lua_jt_net_CFrameData_OnSocketSubGFGameScene);
        tolua_function(tolua_S,"OnTCPNetworkMainGRStatus",lua_jt_net_CFrameData_OnTCPNetworkMainGRStatus);
        tolua_function(tolua_S,"sendPacketWithGPTransferRecord",lua_jt_net_CFrameData_sendPacketWithGPTransferRecord);
        tolua_function(tolua_S,"setPlazaVersion",lua_jt_net_CFrameData_setPlazaVersion);
        tolua_function(tolua_S,"isSocketClosed",lua_jt_net_CFrameData_isSocketClosed);
        tolua_function(tolua_S,"sendPacketWithGPInsureInfo",lua_jt_net_CFrameData_sendPacketWithGPInsureInfo);
        tolua_function(tolua_S,"sendPacketWithQuickJin",lua_jt_net_CFrameData_sendPacketWithQuickJin);
        tolua_function(tolua_S,"OnSocketSubGFUserExpression",lua_jt_net_CFrameData_OnSocketSubGFUserExpression);
        tolua_function(tolua_S,"setSocketClose",lua_jt_net_CFrameData_setSocketClose);
        tolua_function(tolua_S,"SocketDelegateWithConnectNotfiy",lua_jt_net_CFrameData_SocketDelegateWithConnectNotfiy);
        tolua_function(tolua_S,"getValidateKey",lua_jt_net_CFrameData_getValidateKey);
        tolua_function(tolua_S,"sendPacketWithEnterRoomPageCount",lua_jt_net_CFrameData_sendPacketWithEnterRoomPageCount);
        tolua_function(tolua_S,"setGameID",lua_jt_net_CFrameData_setGameID);
        tolua_function(tolua_S,"sendPacketWithStandUpLeave",lua_jt_net_CFrameData_sendPacketWithStandUpLeave);
        tolua_function(tolua_S,"setDeviceType",lua_jt_net_CFrameData_setDeviceType);
        tolua_function(tolua_S,"sendPacketWithUserRule",lua_jt_net_CFrameData_sendPacketWithUserRule);
        tolua_function(tolua_S,"OnTCPNetworkMainCMSystem",lua_jt_net_CFrameData_OnTCPNetworkMainCMSystem);
        tolua_function(tolua_S,"OnTCPNetworkMainMBVerify",lua_jt_net_CFrameData_OnTCPNetworkMainMBVerify);
        tolua_function(tolua_S,"getKindID",lua_jt_net_CFrameData_getKindID);
        tolua_function(tolua_S,"OnTCPNewordkWithKNCommon",lua_jt_net_CFrameData_OnTCPNewordkWithKNCommon);
        tolua_function(tolua_S,"OnSocketSubListServer",lua_jt_net_CFrameData_OnSocketSubListServer);
        tolua_function(tolua_S,"createFrameData", lua_jt_net_CFrameData_createFrameData);
        tolua_function(tolua_S,"getInstance", lua_jt_net_CFrameData_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CFrameData).name();
    g_luaType[typeName] = "CFrameData";
    g_typeCast["CFrameData"] = "CFrameData";
    return 1;
}

int lua_jt_net_CLogonData_setAvatarURL(lua_State* tolua_S)
{
    int argc = 0;
    CLogonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CLogonData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CLogonData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CLogonData_setAvatarURL'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CLogonData:setAvatarURL");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CLogonData_setAvatarURL'", nullptr);
            return 0;
        }
        cobj->setAvatarURL(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CLogonData:setAvatarURL",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CLogonData_setAvatarURL'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CLogonData_setDeviceid(lua_State* tolua_S)
{
    int argc = 0;
    CLogonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CLogonData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CLogonData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CLogonData_setDeviceid'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CLogonData:setDeviceid");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CLogonData_setDeviceid'", nullptr);
            return 0;
        }
        cobj->setDeviceid(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CLogonData:setDeviceid",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CLogonData_setDeviceid'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CLogonData_setGender(lua_State* tolua_S)
{
    int argc = 0;
    CLogonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CLogonData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CLogonData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CLogonData_setGender'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CLogonData:setGender");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CLogonData_setGender'", nullptr);
            return 0;
        }
        cobj->setGender(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CLogonData:setGender",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CLogonData_setGender'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CLogonData_setUUID(lua_State* tolua_S)
{
    int argc = 0;
    CLogonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CLogonData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CLogonData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CLogonData_setUUID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CLogonData:setUUID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CLogonData_setUUID'", nullptr);
            return 0;
        }
        cobj->setUUID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CLogonData:setUUID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CLogonData_setUUID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CLogonData_setPasswd(lua_State* tolua_S)
{
    int argc = 0;
    CLogonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CLogonData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CLogonData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CLogonData_setPasswd'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CLogonData:setPasswd");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CLogonData_setPasswd'", nullptr);
            return 0;
        }
        cobj->setPasswd(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CLogonData:setPasswd",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CLogonData_setPasswd'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CLogonData_getLogonType(lua_State* tolua_S)
{
    int argc = 0;
    CLogonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CLogonData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CLogonData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CLogonData_getLogonType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CLogonData_getLogonType'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getLogonType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CLogonData:getLogonType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CLogonData_getLogonType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CLogonData_getDeviceid(lua_State* tolua_S)
{
    int argc = 0;
    CLogonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CLogonData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CLogonData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CLogonData_getDeviceid'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CLogonData_getDeviceid'", nullptr);
            return 0;
        }
        std::string ret = cobj->getDeviceid();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CLogonData:getDeviceid",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CLogonData_getDeviceid'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CLogonData_getGender(lua_State* tolua_S)
{
    int argc = 0;
    CLogonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CLogonData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CLogonData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CLogonData_getGender'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CLogonData_getGender'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getGender();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CLogonData:getGender",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CLogonData_getGender'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CLogonData_getNickName(lua_State* tolua_S)
{
    int argc = 0;
    CLogonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CLogonData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CLogonData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CLogonData_getNickName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CLogonData_getNickName'", nullptr);
            return 0;
        }
        std::string ret = cobj->getNickName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CLogonData:getNickName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CLogonData_getNickName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CLogonData_getAvatarURL(lua_State* tolua_S)
{
    int argc = 0;
    CLogonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CLogonData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CLogonData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CLogonData_getAvatarURL'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CLogonData_getAvatarURL'", nullptr);
            return 0;
        }
        std::string ret = cobj->getAvatarURL();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CLogonData:getAvatarURL",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CLogonData_getAvatarURL'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CLogonData_getUUID(lua_State* tolua_S)
{
    int argc = 0;
    CLogonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CLogonData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CLogonData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CLogonData_getUUID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CLogonData_getUUID'", nullptr);
            return 0;
        }
        std::string ret = cobj->getUUID();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CLogonData:getUUID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CLogonData_getUUID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CLogonData_getPasswd(lua_State* tolua_S)
{
    int argc = 0;
    CLogonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CLogonData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CLogonData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CLogonData_getPasswd'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CLogonData_getPasswd'", nullptr);
            return 0;
        }
        std::string ret = cobj->getPasswd();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CLogonData:getPasswd",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CLogonData_getPasswd'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CLogonData_setLogonType(lua_State* tolua_S)
{
    int argc = 0;
    CLogonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CLogonData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CLogonData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CLogonData_setLogonType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CLogonData:setLogonType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CLogonData_setLogonType'", nullptr);
            return 0;
        }
        cobj->setLogonType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CLogonData:setLogonType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CLogonData_setLogonType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CLogonData_setNickName(lua_State* tolua_S)
{
    int argc = 0;
    CLogonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CLogonData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CLogonData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_CLogonData_setNickName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CLogonData:setNickName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CLogonData_setNickName'", nullptr);
            return 0;
        }
        cobj->setNickName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CLogonData:setNickName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CLogonData_setNickName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_CLogonData_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CLogonData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 4)
        {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CLogonData:create");
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "CLogonData:create");
            if (!ok) { break; }
            std::string arg2;
            ok &= luaval_to_std_string(tolua_S, 4,&arg2, "CLogonData:create");
            if (!ok) { break; }
            std::string arg3;
            ok &= luaval_to_std_string(tolua_S, 5,&arg3, "CLogonData:create");
            if (!ok) { break; }
            CLogonData* ret = CLogonData::create(arg0, arg1, arg2, arg3);
            object_to_luaval<CLogonData>(tolua_S, "CLogonData",(CLogonData*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            CLogonData* ret = CLogonData::create();
            object_to_luaval<CLogonData>(tolua_S, "CLogonData",(CLogonData*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CLogonData:create");
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "CLogonData:create");
            if (!ok) { break; }
            std::string arg2;
            ok &= luaval_to_std_string(tolua_S, 4,&arg2, "CLogonData:create");
            if (!ok) { break; }
            CLogonData* ret = CLogonData::create(arg0, arg1, arg2);
            object_to_luaval<CLogonData>(tolua_S, "CLogonData",(CLogonData*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 6)
        {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CLogonData:create");
            if (!ok) { break; }
            uint16_t arg1;
            ok &= luaval_to_uint16(tolua_S, 3,&arg1, "CLogonData:create");
            if (!ok) { break; }
            std::string arg2;
            ok &= luaval_to_std_string(tolua_S, 4,&arg2, "CLogonData:create");
            if (!ok) { break; }
            std::string arg3;
            ok &= luaval_to_std_string(tolua_S, 5,&arg3, "CLogonData:create");
            if (!ok) { break; }
            std::string arg4;
            ok &= luaval_to_std_string(tolua_S, 6,&arg4, "CLogonData:create");
            if (!ok) { break; }
            std::string arg5;
            ok &= luaval_to_std_string(tolua_S, 7,&arg5, "CLogonData:create");
            if (!ok) { break; }
            CLogonData* ret = CLogonData::create(arg0, arg1, arg2, arg3, arg4, arg5);
            object_to_luaval<CLogonData>(tolua_S, "CLogonData",(CLogonData*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "CLogonData:create",argc, 6);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CLogonData_create'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_net_CLogonData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CLogonData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_CLogonData_constructor'", nullptr);
            return 0;
        }
        cobj = new CLogonData();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CLogonData");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CLogonData:CLogonData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_CLogonData_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_jt_net_CLogonData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CLogonData)");
    return 0;
}

int lua_register_jt_net_CLogonData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CLogonData");
    tolua_cclass(tolua_S,"CLogonData","CLogonData","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CLogonData");
        tolua_function(tolua_S,"new",lua_jt_net_CLogonData_constructor);
        tolua_function(tolua_S,"setAvatarURL",lua_jt_net_CLogonData_setAvatarURL);
        tolua_function(tolua_S,"setDeviceid",lua_jt_net_CLogonData_setDeviceid);
        tolua_function(tolua_S,"setGender",lua_jt_net_CLogonData_setGender);
        tolua_function(tolua_S,"setUUID",lua_jt_net_CLogonData_setUUID);
        tolua_function(tolua_S,"setPasswd",lua_jt_net_CLogonData_setPasswd);
        tolua_function(tolua_S,"getLogonType",lua_jt_net_CLogonData_getLogonType);
        tolua_function(tolua_S,"getDeviceid",lua_jt_net_CLogonData_getDeviceid);
        tolua_function(tolua_S,"getGender",lua_jt_net_CLogonData_getGender);
        tolua_function(tolua_S,"getNickName",lua_jt_net_CLogonData_getNickName);
        tolua_function(tolua_S,"getAvatarURL",lua_jt_net_CLogonData_getAvatarURL);
        tolua_function(tolua_S,"getUUID",lua_jt_net_CLogonData_getUUID);
        tolua_function(tolua_S,"getPasswd",lua_jt_net_CLogonData_getPasswd);
        tolua_function(tolua_S,"setLogonType",lua_jt_net_CLogonData_setLogonType);
        tolua_function(tolua_S,"setNickName",lua_jt_net_CLogonData_setNickName);
        tolua_function(tolua_S,"create", lua_jt_net_CLogonData_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CLogonData).name();
    g_luaType[typeName] = "CLogonData";
    g_typeCast["CLogonData"] = "CLogonData";
    return 1;
}

int lua_jt_net_ByteArray_writeShort(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_writeShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "ByteArray:writeShort");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_writeShort'", nullptr);
            return 0;
        }
        cobj->writeShort(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:writeShort",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_writeShort'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_readBool(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_readBool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_readBool'", nullptr);
            return 0;
        }
        bool ret = cobj->readBool();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:readBool",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_readBool'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_writeDouble(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_writeDouble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "ByteArray:writeDouble");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_writeDouble'", nullptr);
            return 0;
        }
        cobj->writeDouble(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:writeDouble",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_writeDouble'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_readByte(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_readByte'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_readByte'", nullptr);
            return 0;
        }
        int32_t ret = cobj->readByte();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:readByte",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_readByte'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_writeLONGLONG(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_writeLONGLONG'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "ByteArray:writeLONGLONG");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_writeLONGLONG'", nullptr);
            return 0;
        }
        cobj->writeLONGLONG(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:writeLONGLONG",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_writeLONGLONG'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_getLength(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_getLength'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_getLength'", nullptr);
            return 0;
        }
        int ret = cobj->getLength();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:getLength",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_getLength'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_readFloat(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_readFloat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_readFloat'", nullptr);
            return 0;
        }
        double ret = cobj->readFloat();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:readFloat",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_readFloat'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_readTchar(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_readTchar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ByteArray:readTchar");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_readTchar'", nullptr);
            return 0;
        }
        std::string ret = cobj->readTchar(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:readTchar",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_readTchar'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_writeBool(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_writeBool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "ByteArray:writeBool");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_writeBool'", nullptr);
            return 0;
        }
        cobj->writeBool(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:writeBool",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_writeBool'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_readInt(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_readInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_readInt'", nullptr);
            return 0;
        }
        int ret = cobj->readInt();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:readInt",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_readInt'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_readBYTE(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_readBYTE'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_readBYTE'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->readBYTE();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:readBYTE",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_readBYTE'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_writeFloat(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_writeFloat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "ByteArray:writeFloat");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_writeFloat'", nullptr);
            return 0;
        }
        cobj->writeFloat(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:writeFloat",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_writeFloat'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_writeTchar(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_writeTchar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "ByteArray:writeTchar"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "ByteArray:writeTchar");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_writeTchar'", nullptr);
            return 0;
        }
        cobj->writeTchar(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:writeTchar",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_writeTchar'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_writeUINT(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_writeUINT'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "ByteArray:writeUINT");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_writeUINT'", nullptr);
            return 0;
        }
        cobj->writeUINT(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:writeUINT",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_writeUINT'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_readTCHAR(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_readTCHAR'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ByteArray:readTCHAR");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_readTCHAR'", nullptr);
            return 0;
        }
        std::string ret = cobj->readTCHAR(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:readTCHAR",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_readTCHAR'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_writeDWORD(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_writeDWORD'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ByteArray:writeDWORD");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_writeDWORD'", nullptr);
            return 0;
        }
        cobj->writeDWORD(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:writeDWORD",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_writeDWORD'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_readShort(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_readShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_readShort'", nullptr);
            return 0;
        }
        int32_t ret = cobj->readShort();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:readShort",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_readShort'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_writeWORD(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_writeWORD'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "ByteArray:writeWORD");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_writeWORD'", nullptr);
            return 0;
        }
        cobj->writeWORD(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:writeWORD",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_writeWORD'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_readDWORD(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_readDWORD'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_readDWORD'", nullptr);
            return 0;
        }
        unsigned long ret = cobj->readDWORD();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:readDWORD",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_readDWORD'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_writeByte(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_writeByte'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "ByteArray:writeByte");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_writeByte'", nullptr);
            return 0;
        }
        cobj->writeByte(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:writeByte",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_writeByte'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_readLONGLONG(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_readLONGLONG'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_readLONGLONG'", nullptr);
            return 0;
        }
        long long ret = cobj->readLONGLONG();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:readLONGLONG",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_readLONGLONG'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_readDouble(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_readDouble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_readDouble'", nullptr);
            return 0;
        }
        double ret = cobj->readDouble();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:readDouble",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_readDouble'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_setPosition(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_setPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ByteArray:setPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_setPosition'", nullptr);
            return 0;
        }
        cobj->setPosition(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:setPosition",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_setPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_getCPUEndian(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_getCPUEndian'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_getCPUEndian'", nullptr);
            return 0;
        }
        int ret = cobj->getCPUEndian();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:getCPUEndian",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_getCPUEndian'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_readUINT(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_readUINT'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_readUINT'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->readUINT();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:readUINT",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_readUINT'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_readString(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_readString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ByteArray:readString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_readString'", nullptr);
            return 0;
        }
        std::string ret = cobj->readString(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:readString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_readString'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_getPosition(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_getPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_getPosition'", nullptr);
            return 0;
        }
        int ret = cobj->getPosition();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:getPosition",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_getPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_getBytesAvailable(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_getBytesAvailable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_getBytesAvailable'", nullptr);
            return 0;
        }
        int ret = cobj->getBytesAvailable();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:getBytesAvailable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_getBytesAvailable'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_writeBYTE(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_writeBYTE'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "ByteArray:writeBYTE");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_writeBYTE'", nullptr);
            return 0;
        }
        cobj->writeBYTE(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:writeBYTE",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_writeBYTE'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_writeInt(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_writeInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ByteArray:writeInt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_writeInt'", nullptr);
            return 0;
        }
        cobj->writeInt(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:writeInt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_writeInt'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_writeTCHAR(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_writeTCHAR'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "ByteArray:writeTCHAR"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "ByteArray:writeTCHAR");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_writeTCHAR'", nullptr);
            return 0;
        }
        cobj->writeTCHAR(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:writeTCHAR",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_writeTCHAR'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_readWORD(lua_State* tolua_S)
{
    int argc = 0;
    ByteArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ByteArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_net_ByteArray_readWORD'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_readWORD'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->readWORD();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ByteArray:readWORD",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_readWORD'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_net_ByteArray_destroy(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        ByteArray* arg0;
        ok &= luaval_to_object<ByteArray>(tolua_S, 2, "ByteArray",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_destroy'", nullptr);
            return 0;
        }
        ByteArray::destroy(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ByteArray:destroy",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_destroy'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_net_ByteArray_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ByteArray:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_create'", nullptr);
            return 0;
        }
        ByteArray* ret = ByteArray::create(arg0);
        object_to_luaval<ByteArray>(tolua_S, "ByteArray",(ByteArray*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ByteArray:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_create'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_net_ByteArray_createWithPacket(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        TCP_BufferRef* arg0;
        ok &= luaval_to_object<TCP_BufferRef>(tolua_S, 2, "TCP_BufferRef",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_createWithPacket'", nullptr);
            return 0;
        }
        ByteArray* ret = ByteArray::createWithPacket(arg0);
        object_to_luaval<ByteArray>(tolua_S, "ByteArray",(ByteArray*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ByteArray:createWithPacket",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_createWithPacket'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_net_ByteArray_checkCPUEndian(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_checkCPUEndian'", nullptr);
            return 0;
        }
        int ret = ByteArray::checkCPUEndian();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ByteArray:checkCPUEndian",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_checkCPUEndian'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_net_ByteArray_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ByteArray",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_net_ByteArray_createWithNotify'", nullptr);
            return 0;
        }
        ByteArray* ret = ByteArray::createWithNotify(arg0);
        object_to_luaval<ByteArray>(tolua_S, "ByteArray",(ByteArray*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ByteArray:createWithNotify",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_net_ByteArray_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_net_ByteArray_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ByteArray)");
    return 0;
}

int lua_register_jt_net_ByteArray(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ByteArray");
    tolua_cclass(tolua_S,"ByteArray","ByteArray","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"ByteArray");
        tolua_function(tolua_S,"writeShort",lua_jt_net_ByteArray_writeShort);
        tolua_function(tolua_S,"readBool",lua_jt_net_ByteArray_readBool);
        tolua_function(tolua_S,"writeDouble",lua_jt_net_ByteArray_writeDouble);
        tolua_function(tolua_S,"readByte",lua_jt_net_ByteArray_readByte);
        tolua_function(tolua_S,"writeLONGLONG",lua_jt_net_ByteArray_writeLONGLONG);
        tolua_function(tolua_S,"getLength",lua_jt_net_ByteArray_getLength);
        tolua_function(tolua_S,"readFloat",lua_jt_net_ByteArray_readFloat);
        tolua_function(tolua_S,"readTchar",lua_jt_net_ByteArray_readTchar);
        tolua_function(tolua_S,"writeBool",lua_jt_net_ByteArray_writeBool);
        tolua_function(tolua_S,"readInt",lua_jt_net_ByteArray_readInt);
        tolua_function(tolua_S,"readBYTE",lua_jt_net_ByteArray_readBYTE);
        tolua_function(tolua_S,"writeFloat",lua_jt_net_ByteArray_writeFloat);
        tolua_function(tolua_S,"writeTchar",lua_jt_net_ByteArray_writeTchar);
        tolua_function(tolua_S,"writeUINT",lua_jt_net_ByteArray_writeUINT);
        tolua_function(tolua_S,"readTCHAR",lua_jt_net_ByteArray_readTCHAR);
        tolua_function(tolua_S,"writeDWORD",lua_jt_net_ByteArray_writeDWORD);
        tolua_function(tolua_S,"readShort",lua_jt_net_ByteArray_readShort);
        tolua_function(tolua_S,"writeWORD",lua_jt_net_ByteArray_writeWORD);
        tolua_function(tolua_S,"readDWORD",lua_jt_net_ByteArray_readDWORD);
        tolua_function(tolua_S,"writeByte",lua_jt_net_ByteArray_writeByte);
        tolua_function(tolua_S,"readLONGLONG",lua_jt_net_ByteArray_readLONGLONG);
        tolua_function(tolua_S,"readDouble",lua_jt_net_ByteArray_readDouble);
        tolua_function(tolua_S,"setPosition",lua_jt_net_ByteArray_setPosition);
        tolua_function(tolua_S,"getCPUEndian",lua_jt_net_ByteArray_getCPUEndian);
        tolua_function(tolua_S,"readUINT",lua_jt_net_ByteArray_readUINT);
        tolua_function(tolua_S,"readString",lua_jt_net_ByteArray_readString);
        tolua_function(tolua_S,"getPosition",lua_jt_net_ByteArray_getPosition);
        tolua_function(tolua_S,"getBytesAvailable",lua_jt_net_ByteArray_getBytesAvailable);
        tolua_function(tolua_S,"writeBYTE",lua_jt_net_ByteArray_writeBYTE);
        tolua_function(tolua_S,"writeInt",lua_jt_net_ByteArray_writeInt);
        tolua_function(tolua_S,"writeTCHAR",lua_jt_net_ByteArray_writeTCHAR);
        tolua_function(tolua_S,"readWORD",lua_jt_net_ByteArray_readWORD);
        tolua_function(tolua_S,"destroy", lua_jt_net_ByteArray_destroy);
        tolua_function(tolua_S,"create", lua_jt_net_ByteArray_create);
        tolua_function(tolua_S,"createWithPacket", lua_jt_net_ByteArray_createWithPacket);
        tolua_function(tolua_S,"checkCPUEndian", lua_jt_net_ByteArray_checkCPUEndian);
        tolua_function(tolua_S,"createWithNotify", lua_jt_net_ByteArray_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(ByteArray).name();
    g_luaType[typeName] = "ByteArray";
    g_typeCast["ByteArray"] = "ByteArray";
    return 1;
}
TOLUA_API int register_all_jt_net(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"jt",0);
	tolua_beginmodule(tolua_S,"jt");

	lua_register_jt_net_ByteArray(tolua_S);
	lua_register_jt_net_CSpriteData(tolua_S);
	lua_register_jt_net_TCP_BufferRef(tolua_S);
	lua_register_jt_net_CNotify(tolua_S);
	lua_register_jt_net_CLogonData(tolua_S);
	lua_register_jt_net_CFrameData(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

