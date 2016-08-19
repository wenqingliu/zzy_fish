#include "lua_jt_http_auto.hpp"
#include "URLLoader.h"
#include "URLData.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_jt_http_URLLoader_load(lua_State* tolua_S)
{
    int argc = 0;
    URLLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"URLLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (URLLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_http_URLLoader_load'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "URLLoader:load");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_http_URLLoader_load'", nullptr);
            return 0;
        }
        cobj->load(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "URLLoader:load",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_http_URLLoader_load'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_http_URLLoader_getRunning(lua_State* tolua_S)
{
    int argc = 0;
    URLLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"URLLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (URLLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_http_URLLoader_getRunning'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_http_URLLoader_getRunning'", nullptr);
            return 0;
        }
        bool ret = cobj->getRunning();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "URLLoader:getRunning",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_http_URLLoader_getRunning'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_http_URLLoader_pushRequest(lua_State* tolua_S)
{
    int argc = 0;
    URLLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"URLLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (URLLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_http_URLLoader_pushRequest'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "URLLoader:pushRequest");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_http_URLLoader_pushRequest'", nullptr);
            return 0;
        }
        cobj->pushRequest(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "URLLoader:pushRequest",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_http_URLLoader_pushRequest'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_http_URLLoader_destroyInstance(lua_State* tolua_S)
{
    int argc = 0;
    URLLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"URLLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (URLLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_http_URLLoader_destroyInstance'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_http_URLLoader_destroyInstance'", nullptr);
            return 0;
        }
        cobj->destroyInstance();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "URLLoader:destroyInstance",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_http_URLLoader_destroyInstance'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_http_URLLoader_stop(lua_State* tolua_S)
{
    int argc = 0;
    URLLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"URLLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (URLLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_http_URLLoader_stop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_http_URLLoader_stop'", nullptr);
            return 0;
        }
        cobj->stop();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "URLLoader:stop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_http_URLLoader_stop'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_http_URLLoader_removeRequest(lua_State* tolua_S)
{
    int argc = 0;
    URLLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"URLLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (URLLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_http_URLLoader_removeRequest'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "URLLoader:removeRequest");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_http_URLLoader_removeRequest'", nullptr);
            return 0;
        }
        cobj->removeRequest(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "URLLoader:removeRequest",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_http_URLLoader_removeRequest'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_http_URLLoader_start(lua_State* tolua_S)
{
    int argc = 0;
    URLLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"URLLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (URLLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_http_URLLoader_start'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_http_URLLoader_start'", nullptr);
            return 0;
        }
        cobj->start();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "URLLoader:start",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_http_URLLoader_start'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_http_URLLoader_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"URLLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_http_URLLoader_create'", nullptr);
            return 0;
        }
        URLLoader* ret = URLLoader::create();
        object_to_luaval<URLLoader>(tolua_S, "URLLoader",(URLLoader*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "URLLoader:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_http_URLLoader_create'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_http_URLLoader_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"URLLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_http_URLLoader_getInstance'", nullptr);
            return 0;
        }
        URLLoader* ret = URLLoader::getInstance();
        object_to_luaval<URLLoader>(tolua_S, "URLLoader",(URLLoader*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "URLLoader:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_http_URLLoader_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_http_URLLoader_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (URLLoader)");
    return 0;
}

int lua_register_jt_http_URLLoader(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"URLLoader");
    tolua_cclass(tolua_S,"URLLoader","URLLoader","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"URLLoader");
        tolua_function(tolua_S,"load",lua_jt_http_URLLoader_load);
        tolua_function(tolua_S,"getRunning",lua_jt_http_URLLoader_getRunning);
        tolua_function(tolua_S,"pushRequest",lua_jt_http_URLLoader_pushRequest);
        tolua_function(tolua_S,"destroyInstance",lua_jt_http_URLLoader_destroyInstance);
        tolua_function(tolua_S,"stop",lua_jt_http_URLLoader_stop);
        tolua_function(tolua_S,"removeRequest",lua_jt_http_URLLoader_removeRequest);
        tolua_function(tolua_S,"start",lua_jt_http_URLLoader_start);
        tolua_function(tolua_S,"create", lua_jt_http_URLLoader_create);
        tolua_function(tolua_S,"getInstance", lua_jt_http_URLLoader_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(URLLoader).name();
    g_luaType[typeName] = "URLLoader";
    g_typeCast["URLLoader"] = "URLLoader";
    return 1;
}

int lua_jt_http_URLData_setStatusCode(lua_State* tolua_S)
{
    int argc = 0;
    URLData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"URLData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (URLData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_http_URLData_setStatusCode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "URLData:setStatusCode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_http_URLData_setStatusCode'", nullptr);
            return 0;
        }
        cobj->setStatusCode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "URLData:setStatusCode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_http_URLData_setStatusCode'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_http_URLData_getData(lua_State* tolua_S)
{
    int argc = 0;
    URLData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"URLData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (URLData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_http_URLData_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_http_URLData_getData'", nullptr);
            return 0;
        }
        std::string ret = cobj->getData();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "URLData:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_http_URLData_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_http_URLData_getStatusCode(lua_State* tolua_S)
{
    int argc = 0;
    URLData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"URLData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (URLData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_http_URLData_getStatusCode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_http_URLData_getStatusCode'", nullptr);
            return 0;
        }
        int ret = cobj->getStatusCode();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "URLData:getStatusCode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_http_URLData_getStatusCode'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_http_URLData_setData(lua_State* tolua_S)
{
    int argc = 0;
    URLData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"URLData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (URLData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_http_URLData_setData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "URLData:setData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_http_URLData_setData'", nullptr);
            return 0;
        }
        cobj->setData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "URLData:setData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_http_URLData_setData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_http_URLData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    URLData* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "URLData:URLData");

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "URLData:URLData");

            if (!ok) { break; }
            cobj = new URLData(arg0, arg1);
            cobj->autorelease();
            int ID =  (int)cobj->_ID ;
            int* luaID =  &cobj->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"URLData");
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj = new URLData();
            cobj->autorelease();
            int ID =  (int)cobj->_ID ;
            int* luaID =  &cobj->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"URLData");
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "URLData:URLData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_jt_http_URLData_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_jt_http_URLData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (URLData)");
    return 0;
}

int lua_register_jt_http_URLData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"URLData");
    tolua_cclass(tolua_S,"URLData","URLData","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"URLData");
        tolua_function(tolua_S,"new",lua_jt_http_URLData_constructor);
        tolua_function(tolua_S,"setStatusCode",lua_jt_http_URLData_setStatusCode);
        tolua_function(tolua_S,"getData",lua_jt_http_URLData_getData);
        tolua_function(tolua_S,"getStatusCode",lua_jt_http_URLData_getStatusCode);
        tolua_function(tolua_S,"setData",lua_jt_http_URLData_setData);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(URLData).name();
    g_luaType[typeName] = "URLData";
    g_typeCast["URLData"] = "URLData";
    return 1;
}
TOLUA_API int register_all_jt_http(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"jt",0);
	tolua_beginmodule(tolua_S,"jt");

	lua_register_jt_http_URLData(tolua_S);
	lua_register_jt_http_URLLoader(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

