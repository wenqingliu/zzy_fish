#include "lua_jt_update_auto.hpp"
#include "UpdateEngine.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_jt_update_UpdateEngineDelegate_sendEvent(lua_State* tolua_S)
{
    int argc = 0;
    UpdateEngineDelegate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateEngineDelegate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateEngineDelegate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_update_UpdateEngineDelegate_sendEvent'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_update_UpdateEngineDelegate_sendEvent'", nullptr);
            return 0;
        }
        cobj->sendEvent(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateEngineDelegate:sendEvent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_update_UpdateEngineDelegate_sendEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_update_UpdateEngineDelegate_onError(lua_State* tolua_S)
{
    int argc = 0;
    UpdateEngineDelegate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateEngineDelegate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateEngineDelegate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_update_UpdateEngineDelegate_onError'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        ErrorCode arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "UpdateEngineDelegate:onError");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_update_UpdateEngineDelegate_onError'", nullptr);
            return 0;
        }
        cobj->onError(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateEngineDelegate:onError",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_update_UpdateEngineDelegate_onError'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_update_UpdateEngineDelegate_onProgress(lua_State* tolua_S)
{
    int argc = 0;
    UpdateEngineDelegate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateEngineDelegate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateEngineDelegate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_update_UpdateEngineDelegate_onProgress'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "UpdateEngineDelegate:onProgress");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_update_UpdateEngineDelegate_onProgress'", nullptr);
            return 0;
        }
        cobj->onProgress(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "UpdateEngineDelegate:onProgress");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "UpdateEngineDelegate:onProgress");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_update_UpdateEngineDelegate_onProgress'", nullptr);
            return 0;
        }
        cobj->onProgress(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateEngineDelegate:onProgress",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_update_UpdateEngineDelegate_onProgress'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_update_UpdateEngineDelegate_onDownload(lua_State* tolua_S)
{
    int argc = 0;
    UpdateEngineDelegate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateEngineDelegate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateEngineDelegate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_update_UpdateEngineDelegate_onDownload'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "UpdateEngineDelegate:onDownload");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "UpdateEngineDelegate:onDownload");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_update_UpdateEngineDelegate_onDownload'", nullptr);
            return 0;
        }
        cobj->onDownload(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateEngineDelegate:onDownload",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_update_UpdateEngineDelegate_onDownload'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_update_UpdateEngineDelegate_onUncompress(lua_State* tolua_S)
{
    int argc = 0;
    UpdateEngineDelegate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateEngineDelegate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateEngineDelegate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_update_UpdateEngineDelegate_onUncompress'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "UpdateEngineDelegate:onUncompress");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_update_UpdateEngineDelegate_onUncompress'", nullptr);
            return 0;
        }
        cobj->onUncompress(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateEngineDelegate:onUncompress",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_update_UpdateEngineDelegate_onUncompress'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_update_UpdateEngineDelegate_onSuccess(lua_State* tolua_S)
{
    int argc = 0;
    UpdateEngineDelegate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateEngineDelegate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateEngineDelegate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_update_UpdateEngineDelegate_onSuccess'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_update_UpdateEngineDelegate_onSuccess'", nullptr);
            return 0;
        }
        cobj->onSuccess();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateEngineDelegate:onSuccess",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_update_UpdateEngineDelegate_onSuccess'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_update_UpdateEngineDelegate_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UpdateEngineDelegate",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_update_UpdateEngineDelegate_create'", nullptr);
            return 0;
        }
        UpdateEngineDelegate* ret = UpdateEngineDelegate::create();
        object_to_luaval<UpdateEngineDelegate>(tolua_S, "UpdateEngineDelegate",(UpdateEngineDelegate*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "UpdateEngineDelegate:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_update_UpdateEngineDelegate_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_update_UpdateEngineDelegate_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UpdateEngineDelegate)");
    return 0;
}

int lua_register_jt_update_UpdateEngineDelegate(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UpdateEngineDelegate");
    tolua_cclass(tolua_S,"UpdateEngineDelegate","UpdateEngineDelegate","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"UpdateEngineDelegate");
        tolua_function(tolua_S,"sendEvent",lua_jt_update_UpdateEngineDelegate_sendEvent);
        tolua_function(tolua_S,"onError",lua_jt_update_UpdateEngineDelegate_onError);
        tolua_function(tolua_S,"onProgress",lua_jt_update_UpdateEngineDelegate_onProgress);
        tolua_function(tolua_S,"onDownload",lua_jt_update_UpdateEngineDelegate_onDownload);
        tolua_function(tolua_S,"onUncompress",lua_jt_update_UpdateEngineDelegate_onUncompress);
        tolua_function(tolua_S,"onSuccess",lua_jt_update_UpdateEngineDelegate_onSuccess);
        tolua_function(tolua_S,"create", lua_jt_update_UpdateEngineDelegate_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(UpdateEngineDelegate).name();
    g_luaType[typeName] = "UpdateEngineDelegate";
    g_typeCast["UpdateEngineDelegate"] = "UpdateEngineDelegate";
    return 1;
}

int lua_jt_update_UpdateEngine_getDelegate(lua_State* tolua_S)
{
    int argc = 0;
    UpdateEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_update_UpdateEngine_getDelegate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_update_UpdateEngine_getDelegate'", nullptr);
            return 0;
        }
        UpdateEngineDelegate* ret = cobj->getDelegate();
        object_to_luaval<UpdateEngineDelegate>(tolua_S, "UpdateEngineDelegate",(UpdateEngineDelegate*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateEngine:getDelegate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_update_UpdateEngine_getDelegate'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_update_UpdateEngine_checkUpdate(lua_State* tolua_S)
{
    int argc = 0;
    UpdateEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_update_UpdateEngine_checkUpdate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_update_UpdateEngine_checkUpdate'", nullptr);
            return 0;
        }
        bool ret = cobj->checkUpdate();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateEngine:checkUpdate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_update_UpdateEngine_checkUpdate'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_update_UpdateEngine_update(lua_State* tolua_S)
{
    int argc = 0;
    UpdateEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_update_UpdateEngine_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_update_UpdateEngine_update'", nullptr);
            return 0;
        }
        cobj->update();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateEngine:update",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_update_UpdateEngine_update'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_update_UpdateEngine_setDelegate(lua_State* tolua_S)
{
    int argc = 0;
    UpdateEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_update_UpdateEngine_setDelegate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        UpdateEngineDelegate* arg0;

        ok &= luaval_to_object<UpdateEngineDelegate>(tolua_S, 2, "UpdateEngineDelegate",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_update_UpdateEngine_setDelegate'", nullptr);
            return 0;
        }
        cobj->setDelegate(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateEngine:setDelegate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_update_UpdateEngine_setDelegate'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_update_UpdateEngine_pushVersionQueue(lua_State* tolua_S)
{
    int argc = 0;
    UpdateEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_update_UpdateEngine_pushVersionQueue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "UpdateEngine:pushVersionQueue");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "UpdateEngine:pushVersionQueue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_update_UpdateEngine_pushVersionQueue'", nullptr);
            return 0;
        }
        cobj->pushVersionQueue(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateEngine:pushVersionQueue",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_update_UpdateEngine_pushVersionQueue'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_update_UpdateEngine_pushZIP(lua_State* tolua_S)
{
    int argc = 0;
    UpdateEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateEngine*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_update_UpdateEngine_pushZIP'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "UpdateEngine:pushZIP");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_update_UpdateEngine_pushZIP'", nullptr);
            return 0;
        }
        cobj->pushZIP(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateEngine:pushZIP",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_update_UpdateEngine_pushZIP'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_update_UpdateEngine_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UpdateEngine",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_update_UpdateEngine_create'", nullptr);
            return 0;
        }
        UpdateEngine* ret = UpdateEngine::create();
        object_to_luaval<UpdateEngine>(tolua_S, "UpdateEngine",(UpdateEngine*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "UpdateEngine:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_update_UpdateEngine_create'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_update_UpdateEngine_constructor(lua_State* tolua_S)
{
    int argc = 0;
    UpdateEngine* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_update_UpdateEngine_constructor'", nullptr);
            return 0;
        }
        cobj = new UpdateEngine();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UpdateEngine");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateEngine:UpdateEngine",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_jt_update_UpdateEngine_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_jt_update_UpdateEngine_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UpdateEngine)");
    return 0;
}

int lua_register_jt_update_UpdateEngine(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UpdateEngine");
    tolua_cclass(tolua_S,"UpdateEngine","UpdateEngine","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"UpdateEngine");
        tolua_function(tolua_S,"new",lua_jt_update_UpdateEngine_constructor);
        tolua_function(tolua_S,"getDelegate",lua_jt_update_UpdateEngine_getDelegate);
        tolua_function(tolua_S,"checkUpdate",lua_jt_update_UpdateEngine_checkUpdate);
        tolua_function(tolua_S,"update",lua_jt_update_UpdateEngine_update);
        tolua_function(tolua_S,"setDelegate",lua_jt_update_UpdateEngine_setDelegate);
        tolua_function(tolua_S,"pushVersionQueue",lua_jt_update_UpdateEngine_pushVersionQueue);
        tolua_function(tolua_S,"pushZIP",lua_jt_update_UpdateEngine_pushZIP);
        tolua_function(tolua_S,"create", lua_jt_update_UpdateEngine_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(UpdateEngine).name();
    g_luaType[typeName] = "UpdateEngine";
    g_typeCast["UpdateEngine"] = "UpdateEngine";
    return 1;
}
TOLUA_API int register_all_jt_update(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"jt",0);
	tolua_beginmodule(tolua_S,"jt");

	lua_register_jt_update_UpdateEngineDelegate(tolua_S);
	lua_register_jt_update_UpdateEngine(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

