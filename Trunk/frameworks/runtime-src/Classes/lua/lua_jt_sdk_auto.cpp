#include "lua_jt_sdk_auto.hpp"
#include "SDKControl.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_jt_sdk_ValueMapRef_putInt(lua_State* tolua_S)
{
    int argc = 0;
    ValueMapRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ValueMapRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ValueMapRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_ValueMapRef_putInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "ValueMapRef:putInt"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "ValueMapRef:putInt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_ValueMapRef_putInt'", nullptr);
            return 0;
        }
        cobj->putInt(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ValueMapRef:putInt",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_ValueMapRef_putInt'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_ValueMapRef_getString(lua_State* tolua_S)
{
    int argc = 0;
    ValueMapRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ValueMapRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ValueMapRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_ValueMapRef_getString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "ValueMapRef:getString"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_ValueMapRef_getString'", nullptr);
            return 0;
        }
        std::string ret = cobj->getString(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ValueMapRef:getString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_ValueMapRef_getString'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_ValueMapRef_getName(lua_State* tolua_S)
{
    int argc = 0;
    ValueMapRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ValueMapRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ValueMapRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_ValueMapRef_getName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_ValueMapRef_getName'", nullptr);
            return 0;
        }
        std::string ret = cobj->getName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ValueMapRef:getName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_ValueMapRef_getName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_ValueMapRef_getBool(lua_State* tolua_S)
{
    int argc = 0;
    ValueMapRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ValueMapRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ValueMapRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_ValueMapRef_getBool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "ValueMapRef:getBool"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_ValueMapRef_getBool'", nullptr);
            return 0;
        }
        bool ret = cobj->getBool(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ValueMapRef:getBool",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_ValueMapRef_getBool'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_ValueMapRef_putBool(lua_State* tolua_S)
{
    int argc = 0;
    ValueMapRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ValueMapRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ValueMapRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_ValueMapRef_putBool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        bool arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "ValueMapRef:putBool"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "ValueMapRef:putBool");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_ValueMapRef_putBool'", nullptr);
            return 0;
        }
        cobj->putBool(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ValueMapRef:putBool",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_ValueMapRef_putBool'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_ValueMapRef_putString(lua_State* tolua_S)
{
    int argc = 0;
    ValueMapRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ValueMapRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ValueMapRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_ValueMapRef_putString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "ValueMapRef:putString"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "ValueMapRef:putString"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_ValueMapRef_putString'", nullptr);
            return 0;
        }
        cobj->putString(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ValueMapRef:putString",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_ValueMapRef_putString'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_ValueMapRef_getResult(lua_State* tolua_S)
{
    int argc = 0;
    ValueMapRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ValueMapRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ValueMapRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_ValueMapRef_getResult'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_ValueMapRef_getResult'", nullptr);
            return 0;
        }
        int ret = cobj->getResult();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ValueMapRef:getResult",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_ValueMapRef_getResult'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_ValueMapRef_getInt(lua_State* tolua_S)
{
    int argc = 0;
    ValueMapRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ValueMapRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ValueMapRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_ValueMapRef_getInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "ValueMapRef:getInt"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_ValueMapRef_getInt'", nullptr);
            return 0;
        }
        int ret = cobj->getInt(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ValueMapRef:getInt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_ValueMapRef_getInt'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_ValueMapRef_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ValueMapRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_ValueMapRef_create'", nullptr);
            return 0;
        }
        ValueMapRef* ret = ValueMapRef::create();
        object_to_luaval<ValueMapRef>(tolua_S, "ValueMapRef",(ValueMapRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ValueMapRef:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_ValueMapRef_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_sdk_ValueMapRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ValueMapRef)");
    return 0;
}

int lua_register_jt_sdk_ValueMapRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ValueMapRef");
    tolua_cclass(tolua_S,"ValueMapRef","ValueMapRef","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"ValueMapRef");
        tolua_function(tolua_S,"putInt",lua_jt_sdk_ValueMapRef_putInt);
        tolua_function(tolua_S,"getString",lua_jt_sdk_ValueMapRef_getString);
        tolua_function(tolua_S,"getName",lua_jt_sdk_ValueMapRef_getName);
        tolua_function(tolua_S,"getBool",lua_jt_sdk_ValueMapRef_getBool);
        tolua_function(tolua_S,"putBool",lua_jt_sdk_ValueMapRef_putBool);
        tolua_function(tolua_S,"putString",lua_jt_sdk_ValueMapRef_putString);
        tolua_function(tolua_S,"getResult",lua_jt_sdk_ValueMapRef_getResult);
        tolua_function(tolua_S,"getInt",lua_jt_sdk_ValueMapRef_getInt);
        tolua_function(tolua_S,"create", lua_jt_sdk_ValueMapRef_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(ValueMapRef).name();
    g_luaType[typeName] = "ValueMapRef";
    g_typeCast["ValueMapRef"] = "ValueMapRef";
    return 1;
}

int lua_jt_sdk_SDKControl_getValueFromPlatform(lua_State* tolua_S)
{
    int argc = 0;
    SDKControl* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SDKControl*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_SDKControl_getValueFromPlatform'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned int arg0;
        const char* arg1;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "SDKControl:getValueFromPlatform");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "SDKControl:getValueFromPlatform"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_getValueFromPlatform'", nullptr);
            return 0;
        }
        int ret = cobj->getValueFromPlatform(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SDKControl:getValueFromPlatform",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_getValueFromPlatform'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_SDKControl_isAppDebug(lua_State* tolua_S)
{
    int argc = 0;
    SDKControl* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SDKControl*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_SDKControl_isAppDebug'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_isAppDebug'", nullptr);
            return 0;
        }
        bool ret = cobj->isAppDebug();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SDKControl:isAppDebug",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_isAppDebug'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_SDKControl_printError(lua_State* tolua_S)
{
    int argc = 0;
    SDKControl* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SDKControl*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_SDKControl_printError'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SDKControl:printError"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_printError'", nullptr);
            return 0;
        }
        cobj->printError(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SDKControl:printError",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_printError'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_SDKControl_printInfo(lua_State* tolua_S)
{
    int argc = 0;
    SDKControl* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SDKControl*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_SDKControl_printInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SDKControl:printInfo"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "SDKControl:printInfo"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_printInfo'", nullptr);
            return 0;
        }
        cobj->printInfo(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SDKControl:printInfo",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_printInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_SDKControl_initUmengShareSDK(lua_State* tolua_S)
{
    int argc = 0;
    SDKControl* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SDKControl*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_SDKControl_initUmengShareSDK'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SDKControl:initUmengShareSDK");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "SDKControl:initUmengShareSDK");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "SDKControl:initUmengShareSDK");

        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "SDKControl:initUmengShareSDK");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_initUmengShareSDK'", nullptr);
            return 0;
        }
        cobj->initUmengShareSDK(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SDKControl:initUmengShareSDK",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_initUmengShareSDK'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_SDKControl_getSDKPlatform(lua_State* tolua_S)
{
    int argc = 0;
    SDKControl* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SDKControl*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_SDKControl_getSDKPlatform'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_getSDKPlatform'", nullptr);
            return 0;
        }
        int ret = cobj->getSDKPlatform();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SDKControl:getSDKPlatform",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_getSDKPlatform'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_SDKControl_isCocosDebug(lua_State* tolua_S)
{
    int argc = 0;
    SDKControl* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SDKControl*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_SDKControl_isCocosDebug'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_isCocosDebug'", nullptr);
            return 0;
        }
        bool ret = cobj->isCocosDebug();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SDKControl:isCocosDebug",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_isCocosDebug'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_SDKControl_getWifiState(lua_State* tolua_S)
{
    int argc = 0;
    SDKControl* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SDKControl*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_SDKControl_getWifiState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_getWifiState'", nullptr);
            return 0;
        }
        int ret = cobj->getWifiState();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SDKControl:getWifiState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_getWifiState'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_SDKControl_exitGame(lua_State* tolua_S)
{
    int argc = 0;
    SDKControl* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SDKControl*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_SDKControl_exitGame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_exitGame'", nullptr);
            return 0;
        }
        cobj->exitGame();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SDKControl:exitGame",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_exitGame'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_SDKControl_setVersionCode(lua_State* tolua_S)
{
    int argc = 0;
    SDKControl* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SDKControl*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_SDKControl_setVersionCode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SDKControl:setVersionCode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_setVersionCode'", nullptr);
            return 0;
        }
        cobj->setVersionCode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SDKControl:setVersionCode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_setVersionCode'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_SDKControl_removeSelectors(lua_State* tolua_S)
{
    int argc = 0;
    SDKControl* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SDKControl*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_SDKControl_removeSelectors'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SDKControl:removeSelectors"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_removeSelectors'", nullptr);
            return 0;
        }
        cobj->removeSelectors(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SDKControl:removeSelectors",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_removeSelectors'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_SDKControl_sendMessage(lua_State* tolua_S)
{
    int argc = 0;
    SDKControl* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SDKControl*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_SDKControl_sendMessage'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SDKControl:sendMessage"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "SDKControl:sendMessage"); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            cobj->sendMessage(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SDKControl:sendMessage"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->sendMessage(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SDKControl:sendMessage"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            ValueMapRef* arg1;
            ok &= luaval_to_object<ValueMapRef>(tolua_S, 3, "ValueMapRef",&arg1);

            if (!ok) { break; }
            cobj->sendMessage(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "SDKControl:sendMessage",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_sendMessage'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_SDKControl_getVersionCode(lua_State* tolua_S)
{
    int argc = 0;
    SDKControl* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SDKControl*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_SDKControl_getVersionCode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_getVersionCode'", nullptr);
            return 0;
        }
        int ret = cobj->getVersionCode();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SDKControl:getVersionCode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_getVersionCode'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_SDKControl_handleMessage(lua_State* tolua_S)
{
    int argc = 0;
    SDKControl* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SDKControl*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_SDKControl_handleMessage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Node* arg0;
        cocos2d::Value arg1;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);

        ok &= luaval_to_ccvalue(tolua_S, 3, &arg1, "SDKControl:handleMessage");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_handleMessage'", nullptr);
            return 0;
        }
        cobj->handleMessage(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SDKControl:handleMessage",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_handleMessage'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_SDKControl_getStringFromPlatform(lua_State* tolua_S)
{
    int argc = 0;
    SDKControl* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SDKControl*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_SDKControl_getStringFromPlatform'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned int arg0;
        const char* arg1;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "SDKControl:getStringFromPlatform");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "SDKControl:getStringFromPlatform"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_getStringFromPlatform'", nullptr);
            return 0;
        }
        std::string ret = cobj->getStringFromPlatform(arg0, arg1);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SDKControl:getStringFromPlatform",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_getStringFromPlatform'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_SDKControl_getVersion(lua_State* tolua_S)
{
    int argc = 0;
    SDKControl* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SDKControl*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_SDKControl_getVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_getVersion'", nullptr);
            return 0;
        }
        std::string ret = cobj->getVersion();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SDKControl:getVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_getVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_SDKControl_addSelector(lua_State* tolua_S)
{
    int argc = 0;
    SDKControl* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SDKControl*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_SDKControl_addSelector'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SDKControl:addSelector"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_addSelector'", nullptr);
            return 0;
        }
        cobj->addSelector(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SDKControl:addSelector",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_addSelector'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_SDKControl_setVersion(lua_State* tolua_S)
{
    int argc = 0;
    SDKControl* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SDKControl*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_sdk_SDKControl_setVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SDKControl:setVersion");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_setVersion'", nullptr);
            return 0;
        }
        cobj->setVersion(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SDKControl:setVersion",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_setVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_sdk_SDKControl_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_create'", nullptr);
            return 0;
        }
        SDKControl* ret = SDKControl::create();
        object_to_luaval<SDKControl>(tolua_S, "SDKControl",(SDKControl*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SDKControl:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_create'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_sdk_SDKControl_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SDKControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_getInstance'", nullptr);
            return 0;
        }
        SDKControl* ret = SDKControl::getInstance();
        object_to_luaval<SDKControl>(tolua_S, "SDKControl",(SDKControl*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SDKControl:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_sdk_SDKControl_constructor(lua_State* tolua_S)
{
    int argc = 0;
    SDKControl* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_sdk_SDKControl_constructor'", nullptr);
            return 0;
        }
        cobj = new SDKControl();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"SDKControl");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SDKControl:SDKControl",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_jt_sdk_SDKControl_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_jt_sdk_SDKControl_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SDKControl)");
    return 0;
}

int lua_register_jt_sdk_SDKControl(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SDKControl");
    tolua_cclass(tolua_S,"SDKControl","SDKControl","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"SDKControl");
        tolua_function(tolua_S,"new",lua_jt_sdk_SDKControl_constructor);
        tolua_function(tolua_S,"getValueFromPlatform",lua_jt_sdk_SDKControl_getValueFromPlatform);
        tolua_function(tolua_S,"isAppDebug",lua_jt_sdk_SDKControl_isAppDebug);
        tolua_function(tolua_S,"printError",lua_jt_sdk_SDKControl_printError);
        tolua_function(tolua_S,"printInfo",lua_jt_sdk_SDKControl_printInfo);
        tolua_function(tolua_S,"initUmengShareSDK",lua_jt_sdk_SDKControl_initUmengShareSDK);
        tolua_function(tolua_S,"getSDKPlatform",lua_jt_sdk_SDKControl_getSDKPlatform);
        tolua_function(tolua_S,"isCocosDebug",lua_jt_sdk_SDKControl_isCocosDebug);
        tolua_function(tolua_S,"getWifiState",lua_jt_sdk_SDKControl_getWifiState);
        tolua_function(tolua_S,"exitGame",lua_jt_sdk_SDKControl_exitGame);
        tolua_function(tolua_S,"setVersionCode",lua_jt_sdk_SDKControl_setVersionCode);
        tolua_function(tolua_S,"removeSelectors",lua_jt_sdk_SDKControl_removeSelectors);
        tolua_function(tolua_S,"sendMessage",lua_jt_sdk_SDKControl_sendMessage);
        tolua_function(tolua_S,"getVersionCode",lua_jt_sdk_SDKControl_getVersionCode);
        tolua_function(tolua_S,"handleMessage",lua_jt_sdk_SDKControl_handleMessage);
        tolua_function(tolua_S,"getStringFromPlatform",lua_jt_sdk_SDKControl_getStringFromPlatform);
        tolua_function(tolua_S,"getVersion",lua_jt_sdk_SDKControl_getVersion);
        tolua_function(tolua_S,"addSelector",lua_jt_sdk_SDKControl_addSelector);
        tolua_function(tolua_S,"setVersion",lua_jt_sdk_SDKControl_setVersion);
        tolua_function(tolua_S,"create", lua_jt_sdk_SDKControl_create);
        tolua_function(tolua_S,"getInstance", lua_jt_sdk_SDKControl_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(SDKControl).name();
    g_luaType[typeName] = "SDKControl";
    g_typeCast["SDKControl"] = "SDKControl";
    return 1;
}
TOLUA_API int register_all_jt_sdk(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"jt",0);
	tolua_beginmodule(tolua_S,"jt");

	lua_register_jt_sdk_SDKControl(tolua_S);
	lua_register_jt_sdk_ValueMapRef(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

