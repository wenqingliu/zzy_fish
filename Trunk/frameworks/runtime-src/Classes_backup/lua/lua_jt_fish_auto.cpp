#include "lua_jt_fish_auto.hpp"
#include "FishHelper.h"
#include "math_aide.h"
#include "common_fish.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_jt_fish_Trace_getTraceId(lua_State* tolua_S)
{
    int argc = 0;
    Trace* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Trace",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Trace*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_Trace_getTraceId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_Trace_getTraceId'", nullptr);
            return 0;
        }
        int ret = cobj->getTraceId();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Trace:getTraceId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_Trace_getTraceId'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_Trace_getAngle(lua_State* tolua_S)
{
    int argc = 0;
    Trace* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Trace",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Trace*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_Trace_getAngle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "Trace:getAngle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_Trace_getAngle'", nullptr);
            return 0;
        }
        double ret = cobj->getAngle(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Trace:getAngle",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_Trace_getAngle'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_Trace_getFishId(lua_State* tolua_S)
{
    int argc = 0;
    Trace* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Trace",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Trace*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_Trace_getFishId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_Trace_getFishId'", nullptr);
            return 0;
        }
        int ret = cobj->getFishId();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Trace:getFishId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_Trace_getFishId'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_Trace_getFishKind(lua_State* tolua_S)
{
    int argc = 0;
    Trace* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Trace",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Trace*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_Trace_getFishKind'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_Trace_getFishKind'", nullptr);
            return 0;
        }
        int ret = cobj->getFishKind();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Trace:getFishKind",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_Trace_getFishKind'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_Trace_getX(lua_State* tolua_S)
{
    int argc = 0;
    Trace* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Trace",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Trace*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_Trace_getX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "Trace:getX");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_Trace_getX'", nullptr);
            return 0;
        }
        double ret = cobj->getX(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Trace:getX",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_Trace_getX'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_Trace_getY(lua_State* tolua_S)
{
    int argc = 0;
    Trace* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Trace",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Trace*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_Trace_getY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "Trace:getY");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_Trace_getY'", nullptr);
            return 0;
        }
        double ret = cobj->getY(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Trace:getY",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_Trace_getY'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_Trace_getCount(lua_State* tolua_S)
{
    int argc = 0;
    Trace* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Trace",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Trace*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_Trace_getCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_Trace_getCount'", nullptr);
            return 0;
        }
        int ret = cobj->getCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Trace:getCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_Trace_getCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_Trace_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Trace",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_Trace_create'", nullptr);
            return 0;
        }
        Trace* ret = Trace::create();
        object_to_luaval<Trace>(tolua_S, "Trace",(Trace*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "Trace:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_Trace_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_fish_Trace_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Trace)");
    return 0;
}

int lua_register_jt_fish_Trace(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Trace");
    tolua_cclass(tolua_S,"Trace","Trace","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"Trace");
        tolua_function(tolua_S,"getTraceId",lua_jt_fish_Trace_getTraceId);
        tolua_function(tolua_S,"getAngle",lua_jt_fish_Trace_getAngle);
        tolua_function(tolua_S,"getFishId",lua_jt_fish_Trace_getFishId);
        tolua_function(tolua_S,"getFishKind",lua_jt_fish_Trace_getFishKind);
        tolua_function(tolua_S,"getX",lua_jt_fish_Trace_getX);
        tolua_function(tolua_S,"getY",lua_jt_fish_Trace_getY);
        tolua_function(tolua_S,"getCount",lua_jt_fish_Trace_getCount);
        tolua_function(tolua_S,"create", lua_jt_fish_Trace_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(Trace).name();
    g_luaType[typeName] = "Trace";
    g_typeCast["Trace"] = "Trace";
    return 1;
}

int lua_jt_fish_TraceInfoBuff_setFishId(lua_State* tolua_S)
{
    int argc = 0;
    TraceInfoBuff* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TraceInfoBuff",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TraceInfoBuff*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_TraceInfoBuff_setFishId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "TraceInfoBuff:setFishId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_TraceInfoBuff_setFishId'", nullptr);
            return 0;
        }
        cobj->setFishId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TraceInfoBuff:setFishId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_TraceInfoBuff_setFishId'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_TraceInfoBuff_setTraceType(lua_State* tolua_S)
{
    int argc = 0;
    TraceInfoBuff* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TraceInfoBuff",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TraceInfoBuff*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_TraceInfoBuff_setTraceType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "TraceInfoBuff:setTraceType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_TraceInfoBuff_setTraceType'", nullptr);
            return 0;
        }
        cobj->setTraceType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TraceInfoBuff:setTraceType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_TraceInfoBuff_setTraceType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_TraceInfoBuff_setSpeed(lua_State* tolua_S)
{
    int argc = 0;
    TraceInfoBuff* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TraceInfoBuff",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TraceInfoBuff*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_TraceInfoBuff_setSpeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "TraceInfoBuff:setSpeed");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_TraceInfoBuff_setSpeed'", nullptr);
            return 0;
        }
        cobj->setSpeed(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TraceInfoBuff:setSpeed",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_TraceInfoBuff_setSpeed'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_TraceInfoBuff_setInitCount(lua_State* tolua_S)
{
    int argc = 0;
    TraceInfoBuff* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TraceInfoBuff",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TraceInfoBuff*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_TraceInfoBuff_setInitCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "TraceInfoBuff:setInitCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_TraceInfoBuff_setInitCount'", nullptr);
            return 0;
        }
        cobj->setInitCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TraceInfoBuff:setInitCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_TraceInfoBuff_setInitCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_TraceInfoBuff_pushBackTraceInfo(lua_State* tolua_S)
{
    int argc = 0;
    TraceInfoBuff* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TraceInfoBuff",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TraceInfoBuff*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_TraceInfoBuff_pushBackTraceInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_TraceInfoBuff_pushBackTraceInfo'", nullptr);
            return 0;
        }
        cobj->pushBackTraceInfo();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TraceInfoBuff:pushBackTraceInfo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_TraceInfoBuff_pushBackTraceInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_TraceInfoBuff_setPosY(lua_State* tolua_S)
{
    int argc = 0;
    TraceInfoBuff* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TraceInfoBuff",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TraceInfoBuff*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_TraceInfoBuff_setPosY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "TraceInfoBuff:setPosY");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "TraceInfoBuff:setPosY");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_TraceInfoBuff_setPosY'", nullptr);
            return 0;
        }
        cobj->setPosY(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TraceInfoBuff:setPosY",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_TraceInfoBuff_setPosY'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_TraceInfoBuff_setPosX(lua_State* tolua_S)
{
    int argc = 0;
    TraceInfoBuff* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TraceInfoBuff",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TraceInfoBuff*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_TraceInfoBuff_setPosX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "TraceInfoBuff:setPosX");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "TraceInfoBuff:setPosX");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_TraceInfoBuff_setPosX'", nullptr);
            return 0;
        }
        cobj->setPosX(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TraceInfoBuff:setPosX",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_TraceInfoBuff_setPosX'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_TraceInfoBuff_setFishKind(lua_State* tolua_S)
{
    int argc = 0;
    TraceInfoBuff* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TraceInfoBuff",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TraceInfoBuff*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_TraceInfoBuff_setFishKind'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "TraceInfoBuff:setFishKind");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_TraceInfoBuff_setFishKind'", nullptr);
            return 0;
        }
        cobj->setFishKind(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TraceInfoBuff:setFishKind",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_TraceInfoBuff_setFishKind'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_TraceInfoBuff_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TraceInfoBuff",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_TraceInfoBuff_create'", nullptr);
            return 0;
        }
        TraceInfoBuff* ret = TraceInfoBuff::create();
        object_to_luaval<TraceInfoBuff>(tolua_S, "TraceInfoBuff",(TraceInfoBuff*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "TraceInfoBuff:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_TraceInfoBuff_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_fish_TraceInfoBuff_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TraceInfoBuff)");
    return 0;
}

int lua_register_jt_fish_TraceInfoBuff(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"TraceInfoBuff");
    tolua_cclass(tolua_S,"TraceInfoBuff","TraceInfoBuff","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"TraceInfoBuff");
        tolua_function(tolua_S,"setFishId",lua_jt_fish_TraceInfoBuff_setFishId);
        tolua_function(tolua_S,"setTraceType",lua_jt_fish_TraceInfoBuff_setTraceType);
        tolua_function(tolua_S,"setSpeed",lua_jt_fish_TraceInfoBuff_setSpeed);
        tolua_function(tolua_S,"setInitCount",lua_jt_fish_TraceInfoBuff_setInitCount);
        tolua_function(tolua_S,"pushBackTraceInfo",lua_jt_fish_TraceInfoBuff_pushBackTraceInfo);
        tolua_function(tolua_S,"setPosY",lua_jt_fish_TraceInfoBuff_setPosY);
        tolua_function(tolua_S,"setPosX",lua_jt_fish_TraceInfoBuff_setPosX);
        tolua_function(tolua_S,"setFishKind",lua_jt_fish_TraceInfoBuff_setFishKind);
        tolua_function(tolua_S,"create", lua_jt_fish_TraceInfoBuff_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(TraceInfoBuff).name();
    g_luaType[typeName] = "TraceInfoBuff";
    g_typeCast["TraceInfoBuff"] = "TraceInfoBuff";
    return 1;
}

int lua_jt_fish_FishHelperDelegate_onBuildTrace(lua_State* tolua_S)
{
    int argc = 0;
    FishHelperDelegate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"FishHelperDelegate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (FishHelperDelegate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_FishHelperDelegate_onBuildTrace'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        Trace* arg0;

        ok &= luaval_to_object<Trace>(tolua_S, 2, "Trace",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_FishHelperDelegate_onBuildTrace'", nullptr);
            return 0;
        }
        cobj->onBuildTrace(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "FishHelperDelegate:onBuildTrace",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_FishHelperDelegate_onBuildTrace'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_FishHelperDelegate_onLoadTrace(lua_State* tolua_S)
{
    int argc = 0;
    FishHelperDelegate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"FishHelperDelegate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (FishHelperDelegate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_FishHelperDelegate_onLoadTrace'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        Trace* arg0;

        ok &= luaval_to_object<Trace>(tolua_S, 2, "Trace",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_FishHelperDelegate_onLoadTrace'", nullptr);
            return 0;
        }
        cobj->onLoadTrace(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "FishHelperDelegate:onLoadTrace",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_FishHelperDelegate_onLoadTrace'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_FishHelperDelegate_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"FishHelperDelegate",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_FishHelperDelegate_create'", nullptr);
            return 0;
        }
        FishHelperDelegate* ret = FishHelperDelegate::create();
        object_to_luaval<FishHelperDelegate>(tolua_S, "FishHelperDelegate",(FishHelperDelegate*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "FishHelperDelegate:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_FishHelperDelegate_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_fish_FishHelperDelegate_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (FishHelperDelegate)");
    return 0;
}

int lua_register_jt_fish_FishHelperDelegate(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"FishHelperDelegate");
    tolua_cclass(tolua_S,"FishHelperDelegate","FishHelperDelegate","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"FishHelperDelegate");
        tolua_function(tolua_S,"onBuildTrace",lua_jt_fish_FishHelperDelegate_onBuildTrace);
        tolua_function(tolua_S,"onLoadTrace",lua_jt_fish_FishHelperDelegate_onLoadTrace);
        tolua_function(tolua_S,"create", lua_jt_fish_FishHelperDelegate_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(FishHelperDelegate).name();
    g_luaType[typeName] = "FishHelperDelegate";
    g_typeCast["FishHelperDelegate"] = "FishHelperDelegate";
    return 1;
}

int lua_jt_fish_FishHelper_getDelegate(lua_State* tolua_S)
{
    int argc = 0;
    FishHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"FishHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (FishHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_FishHelper_getDelegate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_FishHelper_getDelegate'", nullptr);
            return 0;
        }
        FishHelperDelegate* ret = cobj->getDelegate();
        object_to_luaval<FishHelperDelegate>(tolua_S, "FishHelperDelegate",(FishHelperDelegate*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "FishHelper:getDelegate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_FishHelper_getDelegate'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_FishHelper_getThread(lua_State* tolua_S)
{
    int argc = 0;
    FishHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"FishHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (FishHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_FishHelper_getThread'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_FishHelper_getThread'", nullptr);
            return 0;
        }
        bool ret = cobj->getThread();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "FishHelper:getThread",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_FishHelper_getThread'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_FishHelper_loadTrace(lua_State* tolua_S)
{
    int argc = 0;
    FishHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"FishHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (FishHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_FishHelper_loadTrace'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        int arg1;
        int arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "FishHelper:loadTrace");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "FishHelper:loadTrace");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "FishHelper:loadTrace");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_FishHelper_loadTrace'", nullptr);
            return 0;
        }
        cobj->loadTrace(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "FishHelper:loadTrace",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_FishHelper_loadTrace'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_FishHelper_pushBackTraceInfo(lua_State* tolua_S)
{
    int argc = 0;
    FishHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"FishHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (FishHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_FishHelper_pushBackTraceInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        TraceInfoBuff* arg0;

        ok &= luaval_to_object<TraceInfoBuff>(tolua_S, 2, "TraceInfoBuff",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_FishHelper_pushBackTraceInfo'", nullptr);
            return 0;
        }
        cobj->pushBackTraceInfo(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "FishHelper:pushBackTraceInfo",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_FishHelper_pushBackTraceInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_FishHelper_runThread(lua_State* tolua_S)
{
    int argc = 0;
    FishHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"FishHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (FishHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_FishHelper_runThread'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_FishHelper_runThread'", nullptr);
            return 0;
        }
        cobj->runThread();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "FishHelper:runThread",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_FishHelper_runThread'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_FishHelper_setDelegate(lua_State* tolua_S)
{
    int argc = 0;
    FishHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"FishHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (FishHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_FishHelper_setDelegate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        FishHelperDelegate* arg0;

        ok &= luaval_to_object<FishHelperDelegate>(tolua_S, 2, "FishHelperDelegate",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_FishHelper_setDelegate'", nullptr);
            return 0;
        }
        cobj->setDelegate(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "FishHelper:setDelegate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_FishHelper_setDelegate'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_FishHelper_setThreadFlag(lua_State* tolua_S)
{
    int argc = 0;
    FishHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"FishHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (FishHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_fish_FishHelper_setThreadFlag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "FishHelper:setThreadFlag");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_FishHelper_setThreadFlag'", nullptr);
            return 0;
        }
        cobj->setThreadFlag(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "FishHelper:setThreadFlag",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_FishHelper_setThreadFlag'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_fish_FishHelper_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"FishHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_FishHelper_create'", nullptr);
            return 0;
        }
        FishHelper* ret = FishHelper::create();
        object_to_luaval<FishHelper>(tolua_S, "FishHelper",(FishHelper*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "FishHelper:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_FishHelper_create'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_fish_FishHelper_constructor(lua_State* tolua_S)
{
    int argc = 0;
    FishHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_fish_FishHelper_constructor'", nullptr);
            return 0;
        }
        cobj = new FishHelper();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"FishHelper");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "FishHelper:FishHelper",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_jt_fish_FishHelper_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_jt_fish_FishHelper_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (FishHelper)");
    return 0;
}

int lua_register_jt_fish_FishHelper(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"FishHelper");
    tolua_cclass(tolua_S,"FishHelper","FishHelper","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"FishHelper");
        tolua_function(tolua_S,"new",lua_jt_fish_FishHelper_constructor);
        tolua_function(tolua_S,"getDelegate",lua_jt_fish_FishHelper_getDelegate);
        tolua_function(tolua_S,"getThread",lua_jt_fish_FishHelper_getThread);
        tolua_function(tolua_S,"loadTrace",lua_jt_fish_FishHelper_loadTrace);
        tolua_function(tolua_S,"pushBackTraceInfo",lua_jt_fish_FishHelper_pushBackTraceInfo);
        tolua_function(tolua_S,"runThread",lua_jt_fish_FishHelper_runThread);
        tolua_function(tolua_S,"setDelegate",lua_jt_fish_FishHelper_setDelegate);
        tolua_function(tolua_S,"setThreadFlag",lua_jt_fish_FishHelper_setThreadFlag);
        tolua_function(tolua_S,"create", lua_jt_fish_FishHelper_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(FishHelper).name();
    g_luaType[typeName] = "FishHelper";
    g_typeCast["FishHelper"] = "FishHelper";
    return 1;
}
TOLUA_API int register_all_jt_fish(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"jt",0);
	tolua_beginmodule(tolua_S,"jt");

	lua_register_jt_fish_FishHelper(tolua_S);
	lua_register_jt_fish_FishHelperDelegate(tolua_S);
	lua_register_jt_fish_TraceInfoBuff(tolua_S);
	lua_register_jt_fish_Trace(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

