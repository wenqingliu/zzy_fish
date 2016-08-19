#include "lua_jt_cmd_auto.hpp"
#include "CMD_Base.h"
#include "CMD_GameServerRef.h"
#include "CMD_LogonServerRef.h"
#include "CMD_CommomRef.h"
#include "CMD_StructRef.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_jt_cmd_CMD_BASE_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_BASE* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_BASE",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_BASE*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_BASE_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_BASE_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_BASE:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_BASE_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_BASE_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_BASE* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_BASE",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_BASE*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_BASE_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_BASE_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_BASE:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_BASE_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_BASE_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_BASE* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_BASE",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_BASE*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_BASE_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_BASE_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_BASE:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_BASE_getData'.",&tolua_err);
#endif

    return 0;
}
static int lua_jt_cmd_CMD_BASE_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_BASE)");
    return 0;
}

int lua_register_jt_cmd_CMD_BASE(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_BASE");
    tolua_cclass(tolua_S,"CMD_BASE","CMD_BASE","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CMD_BASE");
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_BASE_getSize);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_BASE_setStruct);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_BASE_getData);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_BASE).name();
    g_luaType[typeName] = "CMD_BASE";
    g_typeCast["CMD_BASE"] = "CMD_BASE";
    return 1;
}

int lua_jt_cmd_tagGameServerRef_szServerName(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagGameServerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagGameServerRef_szServerName'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagGameServerRef:szServerName"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szServerName(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szServerName();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagGameServerRef:szServerName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagGameServerRef_szServerName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagGameServerRef_wSortID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagGameServerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagGameServerRef_wSortID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameServerRef:wSortID");

            if (!ok) { break; }
            cobj->wSortID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wSortID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagGameServerRef:wSortID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagGameServerRef_wSortID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagGameServerRef_lCellScore(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagGameServerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagGameServerRef_lCellScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "tagGameServerRef:lCellScore");

            if (!ok) { break; }
            cobj->lCellScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            int ret = cobj->lCellScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagGameServerRef:lCellScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagGameServerRef_lCellScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagGameServerRef_dwFullCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagGameServerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagGameServerRef_dwFullCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGameServerRef:dwFullCount");

            if (!ok) { break; }
            cobj->dwFullCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwFullCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagGameServerRef:dwFullCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagGameServerRef_dwFullCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagGameServerRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServerRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServerRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagGameServerRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagGameServerRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServerRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagGameServerRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagGameServerRef_wServerID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagGameServerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagGameServerRef_wServerID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameServerRef:wServerID");

            if (!ok) { break; }
            cobj->wServerID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wServerID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagGameServerRef:wServerID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagGameServerRef_wServerID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagGameServerRef_wKindID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagGameServerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagGameServerRef_wKindID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameServerRef:wKindID");

            if (!ok) { break; }
            cobj->wKindID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wKindID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagGameServerRef:wKindID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagGameServerRef_wKindID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagGameServerRef_wNodeID(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagGameServerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagGameServerRef_wNodeID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameServerRef:wNodeID");

            if (!ok) { break; }
            cobj->wNodeID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wNodeID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagGameServerRef:wNodeID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagGameServerRef_wNodeID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagGameServerRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServerRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServerRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagGameServerRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagGameServerRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServerRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagGameServerRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagGameServerRef_dwOnLineCount(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagGameServerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagGameServerRef_dwOnLineCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagGameServerRef:dwOnLineCount");

            if (!ok) { break; }
            cobj->dwOnLineCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwOnLineCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagGameServerRef:dwOnLineCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagGameServerRef_dwOnLineCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagGameServerRef_szServerAddr(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagGameServerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagGameServerRef_szServerAddr'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagGameServerRef:szServerAddr"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szServerAddr(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szServerAddr();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagGameServerRef:szServerAddr",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagGameServerRef_szServerAddr'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagGameServerRef_wServerPort(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagGameServerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagGameServerRef_wServerPort'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagGameServerRef:wServerPort");

            if (!ok) { break; }
            cobj->wServerPort(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wServerPort();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagGameServerRef:wServerPort",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagGameServerRef_wServerPort'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagGameServerRef_lMaxEnterScore(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagGameServerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagGameServerRef_lMaxEnterScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagGameServerRef:lMaxEnterScore");

            if (!ok) { break; }
            cobj->lMaxEnterScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lMaxEnterScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagGameServerRef:lMaxEnterScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagGameServerRef_lMaxEnterScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagGameServerRef_lMinEnterScore(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagGameServerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagGameServerRef_lMinEnterScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagGameServerRef:lMinEnterScore");

            if (!ok) { break; }
            cobj->lMinEnterScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lMinEnterScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagGameServerRef:lMinEnterScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagGameServerRef_lMinEnterScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagGameServerRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    tagGameServerRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagGameServerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagGameServerRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagGameServerRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagGameServerRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagGameServerRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagGameServerRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagGameServerRef_createWithDataArray(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"tagGameServerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        CNotify* arg0;
        int arg1;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagGameServerRef:createWithDataArray");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagGameServerRef_createWithDataArray'", nullptr);
            return 0;
        }
        tagGameServerRef* ret = tagGameServerRef::createWithDataArray(arg0, arg1);
        object_to_luaval<tagGameServerRef>(tolua_S, "tagGameServerRef",(tagGameServerRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "tagGameServerRef:createWithDataArray",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagGameServerRef_createWithDataArray'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_cmd_tagGameServerRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"tagGameServerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagGameServerRef_createWithNotify'", nullptr);
            return 0;
        }
        tagGameServerRef* ret = tagGameServerRef::createWithNotify();
        object_to_luaval<tagGameServerRef>(tolua_S, "tagGameServerRef",(tagGameServerRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagGameServerRef_createWithNotify'", nullptr);
            return 0;
        }
        tagGameServerRef* ret = tagGameServerRef::createWithNotify(arg0);
        object_to_luaval<tagGameServerRef>(tolua_S, "tagGameServerRef",(tagGameServerRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "tagGameServerRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagGameServerRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_tagGameServerRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagGameServerRef)");
    return 0;
}

int lua_register_jt_cmd_tagGameServerRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagGameServerRef");
    tolua_cclass(tolua_S,"tagGameServerRef","tagGameServerRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"tagGameServerRef");
        tolua_function(tolua_S,"szServerName",lua_jt_cmd_tagGameServerRef_szServerName);
        tolua_function(tolua_S,"wSortID",lua_jt_cmd_tagGameServerRef_wSortID);
        tolua_function(tolua_S,"lCellScore",lua_jt_cmd_tagGameServerRef_lCellScore);
        tolua_function(tolua_S,"dwFullCount",lua_jt_cmd_tagGameServerRef_dwFullCount);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_tagGameServerRef_setStruct);
        tolua_function(tolua_S,"wServerID",lua_jt_cmd_tagGameServerRef_wServerID);
        tolua_function(tolua_S,"wKindID",lua_jt_cmd_tagGameServerRef_wKindID);
        tolua_function(tolua_S,"wNodeID",lua_jt_cmd_tagGameServerRef_wNodeID);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_tagGameServerRef_getSize);
        tolua_function(tolua_S,"dwOnLineCount",lua_jt_cmd_tagGameServerRef_dwOnLineCount);
        tolua_function(tolua_S,"szServerAddr",lua_jt_cmd_tagGameServerRef_szServerAddr);
        tolua_function(tolua_S,"wServerPort",lua_jt_cmd_tagGameServerRef_wServerPort);
        tolua_function(tolua_S,"lMaxEnterScore",lua_jt_cmd_tagGameServerRef_lMaxEnterScore);
        tolua_function(tolua_S,"lMinEnterScore",lua_jt_cmd_tagGameServerRef_lMinEnterScore);
        tolua_function(tolua_S,"getData",lua_jt_cmd_tagGameServerRef_getData);
        tolua_function(tolua_S,"createWithDataArray", lua_jt_cmd_tagGameServerRef_createWithDataArray);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_tagGameServerRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagGameServerRef).name();
    g_luaType[typeName] = "tagGameServerRef";
    g_typeCast["tagGameServerRef"] = "tagGameServerRef";
    return 1;
}

int lua_jt_cmd_tagMobileUserInfoHeadRef_cbGender(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_cbGender'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagMobileUserInfoHeadRef:cbGender");

            if (!ok) { break; }
            cobj->cbGender(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbGender();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserInfoHeadRef:cbGender",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_cbGender'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_cbMemberOrder(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_cbMemberOrder'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagMobileUserInfoHeadRef:cbMemberOrder");

            if (!ok) { break; }
            cobj->cbMemberOrder(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbMemberOrder();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserInfoHeadRef:cbMemberOrder",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_cbMemberOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_dwCustomID(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_dwCustomID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagMobileUserInfoHeadRef:dwCustomID");

            if (!ok) { break; }
            cobj->dwCustomID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwCustomID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserInfoHeadRef:dwCustomID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_dwCustomID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_cbUserStatus(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_cbUserStatus'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagMobileUserInfoHeadRef:cbUserStatus");

            if (!ok) { break; }
            cobj->cbUserStatus(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbUserStatus();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserInfoHeadRef:cbUserStatus",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_cbUserStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMobileUserInfoHeadRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_lScore(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_lScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagMobileUserInfoHeadRef:lScore");

            if (!ok) { break; }
            cobj->lScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserInfoHeadRef:lScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_lScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_dwExperience(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_dwExperience'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagMobileUserInfoHeadRef:dwExperience");

            if (!ok) { break; }
            cobj->dwExperience(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwExperience();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserInfoHeadRef:dwExperience",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_dwExperience'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_wTableID(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_wTableID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagMobileUserInfoHeadRef:wTableID");

            if (!ok) { break; }
            cobj->wTableID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wTableID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserInfoHeadRef:wTableID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_wTableID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_dwFleeCount(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_dwFleeCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagMobileUserInfoHeadRef:dwFleeCount");

            if (!ok) { break; }
            cobj->dwFleeCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwFleeCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserInfoHeadRef:dwFleeCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_dwFleeCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMobileUserInfoHeadRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_szNickName(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_szNickName'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagMobileUserInfoHeadRef:szNickName"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szNickName(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szNickName();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserInfoHeadRef:szNickName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_szNickName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_dwDrawCount(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_dwDrawCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagMobileUserInfoHeadRef:dwDrawCount");

            if (!ok) { break; }
            cobj->dwDrawCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwDrawCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserInfoHeadRef:dwDrawCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_dwDrawCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_dwWinCount(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_dwWinCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagMobileUserInfoHeadRef:dwWinCount");

            if (!ok) { break; }
            cobj->dwWinCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwWinCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserInfoHeadRef:dwWinCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_dwWinCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_wChairID(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_wChairID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagMobileUserInfoHeadRef:wChairID");

            if (!ok) { break; }
            cobj->wChairID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wChairID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserInfoHeadRef:wChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_wChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_szFaceIDDownURL(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_szFaceIDDownURL'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagMobileUserInfoHeadRef:szFaceIDDownURL"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szFaceIDDownURL(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szFaceIDDownURL();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserInfoHeadRef:szFaceIDDownURL",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_szFaceIDDownURL'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_dwLostCount(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_dwLostCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagMobileUserInfoHeadRef:dwLostCount");

            if (!ok) { break; }
            cobj->dwLostCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwLostCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserInfoHeadRef:dwLostCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_dwLostCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_dwUserID(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_dwUserID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagMobileUserInfoHeadRef:dwUserID");

            if (!ok) { break; }
            cobj->dwUserID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwUserID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserInfoHeadRef:dwUserID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_dwUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_dwGameID(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_dwGameID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagMobileUserInfoHeadRef:dwGameID");

            if (!ok) { break; }
            cobj->dwGameID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwGameID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserInfoHeadRef:dwGameID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_dwGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMobileUserInfoHeadRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_wFaceID(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserInfoHeadRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserInfoHeadRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_wFaceID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagMobileUserInfoHeadRef:wFaceID");

            if (!ok) { break; }
            cobj->wFaceID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wFaceID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserInfoHeadRef:wFaceID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_wFaceID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserInfoHeadRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"tagMobileUserInfoHeadRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_createWithNotify'", nullptr);
            return 0;
        }
        tagMobileUserInfoHeadRef* ret = tagMobileUserInfoHeadRef::createWithNotify();
        object_to_luaval<tagMobileUserInfoHeadRef>(tolua_S, "tagMobileUserInfoHeadRef",(tagMobileUserInfoHeadRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_createWithNotify'", nullptr);
            return 0;
        }
        tagMobileUserInfoHeadRef* ret = tagMobileUserInfoHeadRef::createWithNotify(arg0);
        object_to_luaval<tagMobileUserInfoHeadRef>(tolua_S, "tagMobileUserInfoHeadRef",(tagMobileUserInfoHeadRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "tagMobileUserInfoHeadRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserInfoHeadRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_tagMobileUserInfoHeadRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagMobileUserInfoHeadRef)");
    return 0;
}

int lua_register_jt_cmd_tagMobileUserInfoHeadRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagMobileUserInfoHeadRef");
    tolua_cclass(tolua_S,"tagMobileUserInfoHeadRef","tagMobileUserInfoHeadRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"tagMobileUserInfoHeadRef");
        tolua_function(tolua_S,"cbGender",lua_jt_cmd_tagMobileUserInfoHeadRef_cbGender);
        tolua_function(tolua_S,"cbMemberOrder",lua_jt_cmd_tagMobileUserInfoHeadRef_cbMemberOrder);
        tolua_function(tolua_S,"dwCustomID",lua_jt_cmd_tagMobileUserInfoHeadRef_dwCustomID);
        tolua_function(tolua_S,"cbUserStatus",lua_jt_cmd_tagMobileUserInfoHeadRef_cbUserStatus);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_tagMobileUserInfoHeadRef_setStruct);
        tolua_function(tolua_S,"lScore",lua_jt_cmd_tagMobileUserInfoHeadRef_lScore);
        tolua_function(tolua_S,"dwExperience",lua_jt_cmd_tagMobileUserInfoHeadRef_dwExperience);
        tolua_function(tolua_S,"wTableID",lua_jt_cmd_tagMobileUserInfoHeadRef_wTableID);
        tolua_function(tolua_S,"dwFleeCount",lua_jt_cmd_tagMobileUserInfoHeadRef_dwFleeCount);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_tagMobileUserInfoHeadRef_getSize);
        tolua_function(tolua_S,"szNickName",lua_jt_cmd_tagMobileUserInfoHeadRef_szNickName);
        tolua_function(tolua_S,"dwDrawCount",lua_jt_cmd_tagMobileUserInfoHeadRef_dwDrawCount);
        tolua_function(tolua_S,"dwWinCount",lua_jt_cmd_tagMobileUserInfoHeadRef_dwWinCount);
        tolua_function(tolua_S,"wChairID",lua_jt_cmd_tagMobileUserInfoHeadRef_wChairID);
        tolua_function(tolua_S,"szFaceIDDownURL",lua_jt_cmd_tagMobileUserInfoHeadRef_szFaceIDDownURL);
        tolua_function(tolua_S,"dwLostCount",lua_jt_cmd_tagMobileUserInfoHeadRef_dwLostCount);
        tolua_function(tolua_S,"dwUserID",lua_jt_cmd_tagMobileUserInfoHeadRef_dwUserID);
        tolua_function(tolua_S,"dwGameID",lua_jt_cmd_tagMobileUserInfoHeadRef_dwGameID);
        tolua_function(tolua_S,"getData",lua_jt_cmd_tagMobileUserInfoHeadRef_getData);
        tolua_function(tolua_S,"wFaceID",lua_jt_cmd_tagMobileUserInfoHeadRef_wFaceID);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_tagMobileUserInfoHeadRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagMobileUserInfoHeadRef).name();
    g_luaType[typeName] = "tagMobileUserInfoHeadRef";
    g_typeCast["tagMobileUserInfoHeadRef"] = "tagMobileUserInfoHeadRef";
    return 1;
}

int lua_jt_cmd_tagUserStatusRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    tagUserStatusRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserStatusRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserStatusRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagUserStatusRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagUserStatusRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserStatusRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserStatusRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagUserStatusRef_wTableID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserStatusRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserStatusRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagUserStatusRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagUserStatusRef_wTableID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagUserStatusRef:wTableID");

            if (!ok) { break; }
            cobj->wTableID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wTableID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagUserStatusRef:wTableID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserStatusRef_wTableID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagUserStatusRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    tagUserStatusRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserStatusRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserStatusRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagUserStatusRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagUserStatusRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserStatusRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserStatusRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagUserStatusRef_wChairID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserStatusRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserStatusRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagUserStatusRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagUserStatusRef_wChairID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagUserStatusRef:wChairID");

            if (!ok) { break; }
            cobj->wChairID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wChairID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagUserStatusRef:wChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserStatusRef_wChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagUserStatusRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    tagUserStatusRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserStatusRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserStatusRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagUserStatusRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagUserStatusRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserStatusRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserStatusRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagUserStatusRef_cbUserStatus(lua_State* tolua_S)
{
    int argc = 0;
    tagUserStatusRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserStatusRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagUserStatusRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagUserStatusRef_cbUserStatus'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagUserStatusRef:cbUserStatus");

            if (!ok) { break; }
            cobj->cbUserStatus(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbUserStatus();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagUserStatusRef:cbUserStatus",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserStatusRef_cbUserStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagUserStatusRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"tagUserStatusRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagUserStatusRef_createWithNotify'", nullptr);
            return 0;
        }
        tagUserStatusRef* ret = tagUserStatusRef::createWithNotify();
        object_to_luaval<tagUserStatusRef>(tolua_S, "tagUserStatusRef",(tagUserStatusRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagUserStatusRef_createWithNotify'", nullptr);
            return 0;
        }
        tagUserStatusRef* ret = tagUserStatusRef::createWithNotify(arg0);
        object_to_luaval<tagUserStatusRef>(tolua_S, "tagUserStatusRef",(tagUserStatusRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "tagUserStatusRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserStatusRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_tagUserStatusRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagUserStatusRef)");
    return 0;
}

int lua_register_jt_cmd_tagUserStatusRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagUserStatusRef");
    tolua_cclass(tolua_S,"tagUserStatusRef","tagUserStatusRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"tagUserStatusRef");
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_tagUserStatusRef_setStruct);
        tolua_function(tolua_S,"wTableID",lua_jt_cmd_tagUserStatusRef_wTableID);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_tagUserStatusRef_getSize);
        tolua_function(tolua_S,"wChairID",lua_jt_cmd_tagUserStatusRef_wChairID);
        tolua_function(tolua_S,"getData",lua_jt_cmd_tagUserStatusRef_getData);
        tolua_function(tolua_S,"cbUserStatus",lua_jt_cmd_tagUserStatusRef_cbUserStatus);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_tagUserStatusRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagUserStatusRef).name();
    g_luaType[typeName] = "tagUserStatusRef";
    g_typeCast["tagUserStatusRef"] = "tagUserStatusRef";
    return 1;
}

int lua_jt_cmd_tagUserScoreRef_dwUserMedal(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagUserScoreRef_dwUserMedal'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserScoreRef:dwUserMedal");

            if (!ok) { break; }
            cobj->dwUserMedal(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwUserMedal();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagUserScoreRef:dwUserMedal",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserScoreRef_dwUserMedal'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagUserScoreRef_lLoveLiness(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagUserScoreRef_lLoveLiness'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "tagUserScoreRef:lLoveLiness");

            if (!ok) { break; }
            cobj->lLoveLiness(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            int ret = cobj->lLoveLiness();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagUserScoreRef:lLoveLiness",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserScoreRef_lLoveLiness'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagUserScoreRef_dwLostCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagUserScoreRef_dwLostCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserScoreRef:dwLostCount");

            if (!ok) { break; }
            cobj->dwLostCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwLostCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagUserScoreRef:dwLostCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserScoreRef_dwLostCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagUserScoreRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagUserScoreRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagUserScoreRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScoreRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserScoreRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagUserScoreRef_lScore(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagUserScoreRef_lScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagUserScoreRef:lScore");

            if (!ok) { break; }
            cobj->lScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagUserScoreRef:lScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserScoreRef_lScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagUserScoreRef_dwWinCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagUserScoreRef_dwWinCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserScoreRef:dwWinCount");

            if (!ok) { break; }
            cobj->dwWinCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwWinCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagUserScoreRef:dwWinCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserScoreRef_dwWinCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagUserScoreRef_dwFleeCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagUserScoreRef_dwFleeCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserScoreRef:dwFleeCount");

            if (!ok) { break; }
            cobj->dwFleeCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwFleeCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagUserScoreRef:dwFleeCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserScoreRef_dwFleeCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagUserScoreRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagUserScoreRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagUserScoreRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScoreRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserScoreRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagUserScoreRef_dwExperience(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagUserScoreRef_dwExperience'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserScoreRef:dwExperience");

            if (!ok) { break; }
            cobj->dwExperience(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwExperience();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagUserScoreRef:dwExperience",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserScoreRef_dwExperience'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagUserScoreRef_dwDrawCount(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagUserScoreRef_dwDrawCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagUserScoreRef:dwDrawCount");

            if (!ok) { break; }
            cobj->dwDrawCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwDrawCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagUserScoreRef:dwDrawCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserScoreRef_dwDrawCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagUserScoreRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagUserScoreRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagUserScoreRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserScoreRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserScoreRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagUserScoreRef_lInsure(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagUserScoreRef_lInsure'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagUserScoreRef:lInsure");

            if (!ok) { break; }
            cobj->lInsure(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lInsure();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagUserScoreRef:lInsure",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserScoreRef_lInsure'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagUserScoreRef_lGrade(lua_State* tolua_S)
{
    int argc = 0;
    tagUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagUserScoreRef_lGrade'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagUserScoreRef:lGrade");

            if (!ok) { break; }
            cobj->lGrade(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lGrade();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagUserScoreRef:lGrade",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserScoreRef_lGrade'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagUserScoreRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"tagUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagUserScoreRef_createWithNotify'", nullptr);
            return 0;
        }
        tagUserScoreRef* ret = tagUserScoreRef::createWithNotify();
        object_to_luaval<tagUserScoreRef>(tolua_S, "tagUserScoreRef",(tagUserScoreRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagUserScoreRef_createWithNotify'", nullptr);
            return 0;
        }
        tagUserScoreRef* ret = tagUserScoreRef::createWithNotify(arg0);
        object_to_luaval<tagUserScoreRef>(tolua_S, "tagUserScoreRef",(tagUserScoreRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "tagUserScoreRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagUserScoreRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_tagUserScoreRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagUserScoreRef)");
    return 0;
}

int lua_register_jt_cmd_tagUserScoreRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagUserScoreRef");
    tolua_cclass(tolua_S,"tagUserScoreRef","tagUserScoreRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"tagUserScoreRef");
        tolua_function(tolua_S,"dwUserMedal",lua_jt_cmd_tagUserScoreRef_dwUserMedal);
        tolua_function(tolua_S,"lLoveLiness",lua_jt_cmd_tagUserScoreRef_lLoveLiness);
        tolua_function(tolua_S,"dwLostCount",lua_jt_cmd_tagUserScoreRef_dwLostCount);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_tagUserScoreRef_setStruct);
        tolua_function(tolua_S,"lScore",lua_jt_cmd_tagUserScoreRef_lScore);
        tolua_function(tolua_S,"dwWinCount",lua_jt_cmd_tagUserScoreRef_dwWinCount);
        tolua_function(tolua_S,"dwFleeCount",lua_jt_cmd_tagUserScoreRef_dwFleeCount);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_tagUserScoreRef_getSize);
        tolua_function(tolua_S,"dwExperience",lua_jt_cmd_tagUserScoreRef_dwExperience);
        tolua_function(tolua_S,"dwDrawCount",lua_jt_cmd_tagUserScoreRef_dwDrawCount);
        tolua_function(tolua_S,"getData",lua_jt_cmd_tagUserScoreRef_getData);
        tolua_function(tolua_S,"lInsure",lua_jt_cmd_tagUserScoreRef_lInsure);
        tolua_function(tolua_S,"lGrade",lua_jt_cmd_tagUserScoreRef_lGrade);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_tagUserScoreRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagUserScoreRef).name();
    g_luaType[typeName] = "tagUserScoreRef";
    g_typeCast["tagUserScoreRef"] = "tagUserScoreRef";
    return 1;
}

int lua_jt_cmd_tagMobileUserScoreRef_dwLostCount(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserScoreRef_dwLostCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagMobileUserScoreRef:dwLostCount");

            if (!ok) { break; }
            cobj->dwLostCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwLostCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserScoreRef:dwLostCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserScoreRef_dwLostCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserScoreRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMobileUserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserScoreRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagMobileUserScoreRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMobileUserScoreRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserScoreRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserScoreRef_lScore(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserScoreRef_lScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagMobileUserScoreRef:lScore");

            if (!ok) { break; }
            cobj->lScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserScoreRef:lScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserScoreRef_lScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserScoreRef_dwWinCount(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserScoreRef_dwWinCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagMobileUserScoreRef:dwWinCount");

            if (!ok) { break; }
            cobj->dwWinCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwWinCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserScoreRef:dwWinCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserScoreRef_dwWinCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserScoreRef_dwFleeCount(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserScoreRef_dwFleeCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagMobileUserScoreRef:dwFleeCount");

            if (!ok) { break; }
            cobj->dwFleeCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwFleeCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserScoreRef:dwFleeCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserScoreRef_dwFleeCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserScoreRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMobileUserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserScoreRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagMobileUserScoreRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMobileUserScoreRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserScoreRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserScoreRef_dwExperience(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserScoreRef_dwExperience'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagMobileUserScoreRef:dwExperience");

            if (!ok) { break; }
            cobj->dwExperience(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwExperience();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserScoreRef:dwExperience",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserScoreRef_dwExperience'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserScoreRef_dwDrawCount(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagMobileUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserScoreRef_dwDrawCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagMobileUserScoreRef:dwDrawCount");

            if (!ok) { break; }
            cobj->dwDrawCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwDrawCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagMobileUserScoreRef:dwDrawCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserScoreRef_dwDrawCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserScoreRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    tagMobileUserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagMobileUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagMobileUserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagMobileUserScoreRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagMobileUserScoreRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagMobileUserScoreRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserScoreRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagMobileUserScoreRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"tagMobileUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagMobileUserScoreRef_createWithNotify'", nullptr);
            return 0;
        }
        tagMobileUserScoreRef* ret = tagMobileUserScoreRef::createWithNotify();
        object_to_luaval<tagMobileUserScoreRef>(tolua_S, "tagMobileUserScoreRef",(tagMobileUserScoreRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagMobileUserScoreRef_createWithNotify'", nullptr);
            return 0;
        }
        tagMobileUserScoreRef* ret = tagMobileUserScoreRef::createWithNotify(arg0);
        object_to_luaval<tagMobileUserScoreRef>(tolua_S, "tagMobileUserScoreRef",(tagMobileUserScoreRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "tagMobileUserScoreRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagMobileUserScoreRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_tagMobileUserScoreRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagMobileUserScoreRef)");
    return 0;
}

int lua_register_jt_cmd_tagMobileUserScoreRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagMobileUserScoreRef");
    tolua_cclass(tolua_S,"tagMobileUserScoreRef","tagMobileUserScoreRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"tagMobileUserScoreRef");
        tolua_function(tolua_S,"dwLostCount",lua_jt_cmd_tagMobileUserScoreRef_dwLostCount);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_tagMobileUserScoreRef_setStruct);
        tolua_function(tolua_S,"lScore",lua_jt_cmd_tagMobileUserScoreRef_lScore);
        tolua_function(tolua_S,"dwWinCount",lua_jt_cmd_tagMobileUserScoreRef_dwWinCount);
        tolua_function(tolua_S,"dwFleeCount",lua_jt_cmd_tagMobileUserScoreRef_dwFleeCount);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_tagMobileUserScoreRef_getSize);
        tolua_function(tolua_S,"dwExperience",lua_jt_cmd_tagMobileUserScoreRef_dwExperience);
        tolua_function(tolua_S,"dwDrawCount",lua_jt_cmd_tagMobileUserScoreRef_dwDrawCount);
        tolua_function(tolua_S,"getData",lua_jt_cmd_tagMobileUserScoreRef_getData);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_tagMobileUserScoreRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagMobileUserScoreRef).name();
    g_luaType[typeName] = "tagMobileUserScoreRef";
    g_typeCast["tagMobileUserScoreRef"] = "tagMobileUserScoreRef";
    return 1;
}

int lua_jt_cmd_CMD_GR_ConfigServerRef_wChairCount(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_ConfigServerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_ConfigServerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_ConfigServerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_wChairCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_GR_ConfigServerRef:wChairCount");

            if (!ok) { break; }
            cobj->wChairCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wChairCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_ConfigServerRef:wChairCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_wChairCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_ConfigServerRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_ConfigServerRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_ConfigServerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_ConfigServerRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_ConfigServerRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_ConfigServerRef_dwServerRule(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_ConfigServerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_ConfigServerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_ConfigServerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_dwServerRule'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_GR_ConfigServerRef:dwServerRule");

            if (!ok) { break; }
            cobj->dwServerRule(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwServerRule();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_ConfigServerRef:dwServerRule",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_dwServerRule'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_ConfigServerRef_wServerType(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_ConfigServerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_ConfigServerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_ConfigServerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_wServerType'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_GR_ConfigServerRef:wServerType");

            if (!ok) { break; }
            cobj->wServerType(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wServerType();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_ConfigServerRef:wServerType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_wServerType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_ConfigServerRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_ConfigServerRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_ConfigServerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_ConfigServerRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_ConfigServerRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_ConfigServerRef_wTableCount(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_ConfigServerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_ConfigServerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_ConfigServerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_wTableCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_GR_ConfigServerRef:wTableCount");

            if (!ok) { break; }
            cobj->wTableCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wTableCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_ConfigServerRef:wTableCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_wTableCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_ConfigServerRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_ConfigServerRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_ConfigServerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_ConfigServerRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_ConfigServerRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_ConfigServerRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_GR_ConfigServerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_ConfigServerRef* ret = CMD_GR_ConfigServerRef::createWithNotify();
        object_to_luaval<CMD_GR_ConfigServerRef>(tolua_S, "CMD_GR_ConfigServerRef",(CMD_GR_ConfigServerRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_ConfigServerRef* ret = CMD_GR_ConfigServerRef::createWithNotify(arg0);
        object_to_luaval<CMD_GR_ConfigServerRef>(tolua_S, "CMD_GR_ConfigServerRef",(CMD_GR_ConfigServerRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_GR_ConfigServerRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_ConfigServerRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_GR_ConfigServerRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_GR_ConfigServerRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_GR_ConfigServerRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_GR_ConfigServerRef");
    tolua_cclass(tolua_S,"CMD_GR_ConfigServerRef","CMD_GR_ConfigServerRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_GR_ConfigServerRef");
        tolua_function(tolua_S,"wChairCount",lua_jt_cmd_CMD_GR_ConfigServerRef_wChairCount);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_GR_ConfigServerRef_setStruct);
        tolua_function(tolua_S,"dwServerRule",lua_jt_cmd_CMD_GR_ConfigServerRef_dwServerRule);
        tolua_function(tolua_S,"wServerType",lua_jt_cmd_CMD_GR_ConfigServerRef_wServerType);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_GR_ConfigServerRef_getSize);
        tolua_function(tolua_S,"wTableCount",lua_jt_cmd_CMD_GR_ConfigServerRef_wTableCount);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_GR_ConfigServerRef_getData);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_GR_ConfigServerRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_GR_ConfigServerRef).name();
    g_luaType[typeName] = "CMD_GR_ConfigServerRef";
    g_typeCast["CMD_GR_ConfigServerRef"] = "CMD_GR_ConfigServerRef";
    return 1;
}

int lua_jt_cmd_CMD_GR_UserStatusRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_UserStatusRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_UserStatusRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_UserStatusRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_UserStatusRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_UserStatusRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_UserStatusRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_UserStatusRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_UserStatusRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_UserStatusRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_UserStatusRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_UserStatusRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_UserStatusRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_UserStatusRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_UserStatusRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_UserStatusRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_UserStatusRef_initRef(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_UserStatusRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_UserStatusRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_UserStatusRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_UserStatusRef_initRef'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_UserStatusRef_initRef'", nullptr);
            return 0;
        }
        cobj->initRef();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_UserStatusRef:initRef",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_UserStatusRef_initRef'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_UserStatusRef_dwUserID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_UserStatusRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_UserStatusRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_UserStatusRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_UserStatusRef_dwUserID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_GR_UserStatusRef:dwUserID");

            if (!ok) { break; }
            cobj->dwUserID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwUserID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_UserStatusRef:dwUserID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_UserStatusRef_dwUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_UserStatusRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_UserStatusRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_UserStatusRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_UserStatusRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_UserStatusRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_UserStatusRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_UserStatusRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_UserStatusRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_UserStatusRef_setUserStatus(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_UserStatusRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_UserStatusRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_UserStatusRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_UserStatusRef_setUserStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        tagUserStatusRef* arg0;

        ok &= luaval_to_object<tagUserStatusRef>(tolua_S, 2, "tagUserStatusRef",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_UserStatusRef_setUserStatus'", nullptr);
            return 0;
        }
        cobj->setUserStatus(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_UserStatusRef:setUserStatus",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_UserStatusRef_setUserStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_UserStatusRef_getUserStatus(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_UserStatusRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_UserStatusRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_UserStatusRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_UserStatusRef_getUserStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_UserStatusRef_getUserStatus'", nullptr);
            return 0;
        }
        tagUserStatusRef* ret = cobj->getUserStatus();
        object_to_luaval<tagUserStatusRef>(tolua_S, "tagUserStatusRef",(tagUserStatusRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_UserStatusRef:getUserStatus",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_UserStatusRef_getUserStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_UserStatusRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_GR_UserStatusRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_UserStatusRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_UserStatusRef* ret = CMD_GR_UserStatusRef::createWithNotify();
        object_to_luaval<CMD_GR_UserStatusRef>(tolua_S, "CMD_GR_UserStatusRef",(CMD_GR_UserStatusRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_UserStatusRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_UserStatusRef* ret = CMD_GR_UserStatusRef::createWithNotify(arg0);
        object_to_luaval<CMD_GR_UserStatusRef>(tolua_S, "CMD_GR_UserStatusRef",(CMD_GR_UserStatusRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_GR_UserStatusRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_UserStatusRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_GR_UserStatusRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_GR_UserStatusRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_GR_UserStatusRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_GR_UserStatusRef");
    tolua_cclass(tolua_S,"CMD_GR_UserStatusRef","CMD_GR_UserStatusRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_GR_UserStatusRef");
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_GR_UserStatusRef_setStruct);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_GR_UserStatusRef_getSize);
        tolua_function(tolua_S,"initRef",lua_jt_cmd_CMD_GR_UserStatusRef_initRef);
        tolua_function(tolua_S,"dwUserID",lua_jt_cmd_CMD_GR_UserStatusRef_dwUserID);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_GR_UserStatusRef_getData);
        tolua_function(tolua_S,"setUserStatus",lua_jt_cmd_CMD_GR_UserStatusRef_setUserStatus);
        tolua_function(tolua_S,"getUserStatus",lua_jt_cmd_CMD_GR_UserStatusRef_getUserStatus);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_GR_UserStatusRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_GR_UserStatusRef).name();
    g_luaType[typeName] = "CMD_GR_UserStatusRef";
    g_typeCast["CMD_GR_UserStatusRef"] = "CMD_GR_UserStatusRef";
    return 1;
}

int lua_jt_cmd_CMD_GR_UserScoreRef_setUserScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_UserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_UserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_UserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_UserScoreRef_setUserScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        tagUserScoreRef* arg0;

        ok &= luaval_to_object<tagUserScoreRef>(tolua_S, 2, "tagUserScoreRef",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_UserScoreRef_setUserScore'", nullptr);
            return 0;
        }
        cobj->setUserScore(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_UserScoreRef:setUserScore",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_UserScoreRef_setUserScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_UserScoreRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_UserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_UserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_UserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_UserScoreRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_UserScoreRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_UserScoreRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_UserScoreRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_UserScoreRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_UserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_UserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_UserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_UserScoreRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_UserScoreRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_UserScoreRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_UserScoreRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_UserScoreRef_dwUserID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_UserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_UserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_UserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_UserScoreRef_dwUserID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_GR_UserScoreRef:dwUserID");

            if (!ok) { break; }
            cobj->dwUserID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwUserID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_UserScoreRef:dwUserID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_UserScoreRef_dwUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_UserScoreRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_UserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_UserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_UserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_UserScoreRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_UserScoreRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_UserScoreRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_UserScoreRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_UserScoreRef_getUserScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_UserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_UserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_UserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_UserScoreRef_getUserScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_UserScoreRef_getUserScore'", nullptr);
            return 0;
        }
        tagUserScoreRef* ret = cobj->getUserScore();
        object_to_luaval<tagUserScoreRef>(tolua_S, "tagUserScoreRef",(tagUserScoreRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_UserScoreRef:getUserScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_UserScoreRef_getUserScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_UserScoreRef_initRef(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_UserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_UserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_UserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_UserScoreRef_initRef'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_UserScoreRef_initRef'", nullptr);
            return 0;
        }
        cobj->initRef();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_UserScoreRef:initRef",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_UserScoreRef_initRef'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_UserScoreRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_GR_UserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_UserScoreRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_UserScoreRef* ret = CMD_GR_UserScoreRef::createWithNotify();
        object_to_luaval<CMD_GR_UserScoreRef>(tolua_S, "CMD_GR_UserScoreRef",(CMD_GR_UserScoreRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_UserScoreRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_UserScoreRef* ret = CMD_GR_UserScoreRef::createWithNotify(arg0);
        object_to_luaval<CMD_GR_UserScoreRef>(tolua_S, "CMD_GR_UserScoreRef",(CMD_GR_UserScoreRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_GR_UserScoreRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_UserScoreRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_GR_UserScoreRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_GR_UserScoreRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_GR_UserScoreRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_GR_UserScoreRef");
    tolua_cclass(tolua_S,"CMD_GR_UserScoreRef","CMD_GR_UserScoreRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_GR_UserScoreRef");
        tolua_function(tolua_S,"setUserScore",lua_jt_cmd_CMD_GR_UserScoreRef_setUserScore);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_GR_UserScoreRef_setStruct);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_GR_UserScoreRef_getSize);
        tolua_function(tolua_S,"dwUserID",lua_jt_cmd_CMD_GR_UserScoreRef_dwUserID);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_GR_UserScoreRef_getData);
        tolua_function(tolua_S,"getUserScore",lua_jt_cmd_CMD_GR_UserScoreRef_getUserScore);
        tolua_function(tolua_S,"initRef",lua_jt_cmd_CMD_GR_UserScoreRef_initRef);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_GR_UserScoreRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_GR_UserScoreRef).name();
    g_luaType[typeName] = "CMD_GR_UserScoreRef";
    g_typeCast["CMD_GR_UserScoreRef"] = "CMD_GR_UserScoreRef";
    return 1;
}

int lua_jt_cmd_CMD_GR_MobileUserScoreRef_setUserScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_MobileUserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_MobileUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_MobileUserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_setUserScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        tagMobileUserScoreRef* arg0;

        ok &= luaval_to_object<tagMobileUserScoreRef>(tolua_S, 2, "tagMobileUserScoreRef",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_setUserScore'", nullptr);
            return 0;
        }
        cobj->setUserScore(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_MobileUserScoreRef:setUserScore",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_setUserScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_MobileUserScoreRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_MobileUserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_MobileUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_MobileUserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_MobileUserScoreRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_MobileUserScoreRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_MobileUserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_MobileUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_MobileUserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_MobileUserScoreRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_MobileUserScoreRef_dwUserID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_MobileUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_MobileUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_MobileUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_dwUserID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_GR_MobileUserScoreRef:dwUserID");

            if (!ok) { break; }
            cobj->dwUserID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwUserID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_MobileUserScoreRef:dwUserID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_dwUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_MobileUserScoreRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_MobileUserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_MobileUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_MobileUserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_MobileUserScoreRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_MobileUserScoreRef_getUserScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_MobileUserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_MobileUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_MobileUserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_getUserScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_getUserScore'", nullptr);
            return 0;
        }
        tagMobileUserScoreRef* ret = cobj->getUserScore();
        object_to_luaval<tagMobileUserScoreRef>(tolua_S, "tagMobileUserScoreRef",(tagMobileUserScoreRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_MobileUserScoreRef:getUserScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_getUserScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_MobileUserScoreRef_initRef(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_MobileUserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_MobileUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_MobileUserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_initRef'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_initRef'", nullptr);
            return 0;
        }
        cobj->initRef();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_MobileUserScoreRef:initRef",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_initRef'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_MobileUserScoreRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_GR_MobileUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_MobileUserScoreRef* ret = CMD_GR_MobileUserScoreRef::createWithNotify();
        object_to_luaval<CMD_GR_MobileUserScoreRef>(tolua_S, "CMD_GR_MobileUserScoreRef",(CMD_GR_MobileUserScoreRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_MobileUserScoreRef* ret = CMD_GR_MobileUserScoreRef::createWithNotify(arg0);
        object_to_luaval<CMD_GR_MobileUserScoreRef>(tolua_S, "CMD_GR_MobileUserScoreRef",(CMD_GR_MobileUserScoreRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_GR_MobileUserScoreRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_MobileUserScoreRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_GR_MobileUserScoreRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_GR_MobileUserScoreRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_GR_MobileUserScoreRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_GR_MobileUserScoreRef");
    tolua_cclass(tolua_S,"CMD_GR_MobileUserScoreRef","CMD_GR_MobileUserScoreRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_GR_MobileUserScoreRef");
        tolua_function(tolua_S,"setUserScore",lua_jt_cmd_CMD_GR_MobileUserScoreRef_setUserScore);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_GR_MobileUserScoreRef_setStruct);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_GR_MobileUserScoreRef_getSize);
        tolua_function(tolua_S,"dwUserID",lua_jt_cmd_CMD_GR_MobileUserScoreRef_dwUserID);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_GR_MobileUserScoreRef_getData);
        tolua_function(tolua_S,"getUserScore",lua_jt_cmd_CMD_GR_MobileUserScoreRef_getUserScore);
        tolua_function(tolua_S,"initRef",lua_jt_cmd_CMD_GR_MobileUserScoreRef_initRef);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_GR_MobileUserScoreRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_GR_MobileUserScoreRef).name();
    g_luaType[typeName] = "CMD_GR_MobileUserScoreRef";
    g_typeCast["CMD_GR_MobileUserScoreRef"] = "CMD_GR_MobileUserScoreRef";
    return 1;
}

int lua_jt_cmd_CMD_GR_RequestFailureRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_RequestFailureRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_RequestFailureRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_RequestFailureRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_RequestFailureRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_RequestFailureRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_RequestFailureRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_RequestFailureRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_RequestFailureRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_RequestFailureRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_RequestFailureRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_RequestFailureRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_RequestFailureRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_RequestFailureRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_RequestFailureRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_RequestFailureRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_RequestFailureRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_RequestFailureRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_RequestFailureRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_RequestFailureRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_RequestFailureRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_RequestFailureRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_RequestFailureRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_RequestFailureRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_RequestFailureRef_szDescribeString(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_RequestFailureRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_RequestFailureRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_RequestFailureRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_RequestFailureRef_szDescribeString'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_GR_RequestFailureRef:szDescribeString"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szDescribeString(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szDescribeString();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_RequestFailureRef:szDescribeString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_RequestFailureRef_szDescribeString'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_RequestFailureRef_lErrorCode(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_RequestFailureRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_RequestFailureRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_RequestFailureRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_RequestFailureRef_lErrorCode'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_GR_RequestFailureRef:lErrorCode");

            if (!ok) { break; }
            cobj->lErrorCode(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            int ret = cobj->lErrorCode();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_RequestFailureRef:lErrorCode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_RequestFailureRef_lErrorCode'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_RequestFailureRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_GR_RequestFailureRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_RequestFailureRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_RequestFailureRef* ret = CMD_GR_RequestFailureRef::createWithNotify();
        object_to_luaval<CMD_GR_RequestFailureRef>(tolua_S, "CMD_GR_RequestFailureRef",(CMD_GR_RequestFailureRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_RequestFailureRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_RequestFailureRef* ret = CMD_GR_RequestFailureRef::createWithNotify(arg0);
        object_to_luaval<CMD_GR_RequestFailureRef>(tolua_S, "CMD_GR_RequestFailureRef",(CMD_GR_RequestFailureRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_GR_RequestFailureRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_RequestFailureRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_GR_RequestFailureRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_GR_RequestFailureRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_GR_RequestFailureRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_GR_RequestFailureRef");
    tolua_cclass(tolua_S,"CMD_GR_RequestFailureRef","CMD_GR_RequestFailureRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_GR_RequestFailureRef");
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_GR_RequestFailureRef_getSize);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_GR_RequestFailureRef_setStruct);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_GR_RequestFailureRef_getData);
        tolua_function(tolua_S,"szDescribeString",lua_jt_cmd_CMD_GR_RequestFailureRef_szDescribeString);
        tolua_function(tolua_S,"lErrorCode",lua_jt_cmd_CMD_GR_RequestFailureRef_lErrorCode);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_GR_RequestFailureRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_GR_RequestFailureRef).name();
    g_luaType[typeName] = "CMD_GR_RequestFailureRef";
    g_typeCast["CMD_GR_RequestFailureRef"] = "CMD_GR_RequestFailureRef";
    return 1;
}

int lua_jt_cmd_CMD_GR_C_SendTrumpetRef_TrumpetColor(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_C_SendTrumpetRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_C_SendTrumpetRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_C_SendTrumpetRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_TrumpetColor'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_GR_C_SendTrumpetRef:TrumpetColor");

            if (!ok) { break; }
            cobj->TrumpetColor(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->TrumpetColor();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_C_SendTrumpetRef:TrumpetColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_TrumpetColor'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_C_SendTrumpetRef_wPropertyIndex(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_C_SendTrumpetRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_C_SendTrumpetRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_C_SendTrumpetRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_wPropertyIndex'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_GR_C_SendTrumpetRef:wPropertyIndex");

            if (!ok) { break; }
            cobj->wPropertyIndex(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wPropertyIndex();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_C_SendTrumpetRef:wPropertyIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_wPropertyIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_C_SendTrumpetRef_szTrumpetContent(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_C_SendTrumpetRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_C_SendTrumpetRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_C_SendTrumpetRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_szTrumpetContent'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_GR_C_SendTrumpetRef:szTrumpetContent"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szTrumpetContent(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szTrumpetContent();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_C_SendTrumpetRef:szTrumpetContent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_szTrumpetContent'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_C_SendTrumpetRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_C_SendTrumpetRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_C_SendTrumpetRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_C_SendTrumpetRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_C_SendTrumpetRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_C_SendTrumpetRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_C_SendTrumpetRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_C_SendTrumpetRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_C_SendTrumpetRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_C_SendTrumpetRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_C_SendTrumpetRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_C_SendTrumpetRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_C_SendTrumpetRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_C_SendTrumpetRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_C_SendTrumpetRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_C_SendTrumpetRef_cbRequestArea(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_C_SendTrumpetRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_C_SendTrumpetRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_C_SendTrumpetRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_cbRequestArea'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_GR_C_SendTrumpetRef:cbRequestArea");

            if (!ok) { break; }
            cobj->cbRequestArea(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbRequestArea();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_C_SendTrumpetRef:cbRequestArea",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_cbRequestArea'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_C_SendTrumpetRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_GR_C_SendTrumpetRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_C_SendTrumpetRef* ret = CMD_GR_C_SendTrumpetRef::createWithNotify();
        object_to_luaval<CMD_GR_C_SendTrumpetRef>(tolua_S, "CMD_GR_C_SendTrumpetRef",(CMD_GR_C_SendTrumpetRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_C_SendTrumpetRef* ret = CMD_GR_C_SendTrumpetRef::createWithNotify(arg0);
        object_to_luaval<CMD_GR_C_SendTrumpetRef>(tolua_S, "CMD_GR_C_SendTrumpetRef",(CMD_GR_C_SendTrumpetRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_GR_C_SendTrumpetRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_C_SendTrumpetRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_GR_C_SendTrumpetRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_GR_C_SendTrumpetRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_GR_C_SendTrumpetRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_GR_C_SendTrumpetRef");
    tolua_cclass(tolua_S,"CMD_GR_C_SendTrumpetRef","CMD_GR_C_SendTrumpetRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_GR_C_SendTrumpetRef");
        tolua_function(tolua_S,"TrumpetColor",lua_jt_cmd_CMD_GR_C_SendTrumpetRef_TrumpetColor);
        tolua_function(tolua_S,"wPropertyIndex",lua_jt_cmd_CMD_GR_C_SendTrumpetRef_wPropertyIndex);
        tolua_function(tolua_S,"szTrumpetContent",lua_jt_cmd_CMD_GR_C_SendTrumpetRef_szTrumpetContent);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_GR_C_SendTrumpetRef_setStruct);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_GR_C_SendTrumpetRef_getSize);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_GR_C_SendTrumpetRef_getData);
        tolua_function(tolua_S,"cbRequestArea",lua_jt_cmd_CMD_GR_C_SendTrumpetRef_cbRequestArea);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_GR_C_SendTrumpetRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_GR_C_SendTrumpetRef).name();
    g_luaType[typeName] = "CMD_GR_C_SendTrumpetRef";
    g_typeCast["CMD_GR_C_SendTrumpetRef"] = "CMD_GR_C_SendTrumpetRef";
    return 1;
}

int lua_jt_cmd_CMD_GR_S_SendTrumpetRef_TrumpetColor(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_SendTrumpetRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_SendTrumpetRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_S_SendTrumpetRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_TrumpetColor'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_GR_S_SendTrumpetRef:TrumpetColor");

            if (!ok) { break; }
            cobj->TrumpetColor(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->TrumpetColor();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_S_SendTrumpetRef:TrumpetColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_TrumpetColor'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_SendTrumpetRef_wPropertyIndex(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_SendTrumpetRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_SendTrumpetRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_S_SendTrumpetRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_wPropertyIndex'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_GR_S_SendTrumpetRef:wPropertyIndex");

            if (!ok) { break; }
            cobj->wPropertyIndex(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wPropertyIndex();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_S_SendTrumpetRef:wPropertyIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_wPropertyIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_SendTrumpetRef_szSendNickName(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_SendTrumpetRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_SendTrumpetRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_S_SendTrumpetRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_szSendNickName'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_GR_S_SendTrumpetRef:szSendNickName"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szSendNickName(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szSendNickName();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_S_SendTrumpetRef:szSendNickName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_szSendNickName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_SendTrumpetRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_SendTrumpetRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_SendTrumpetRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_S_SendTrumpetRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_S_SendTrumpetRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_SendTrumpetRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_SendTrumpetRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_SendTrumpetRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_S_SendTrumpetRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_S_SendTrumpetRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_SendTrumpetRef_szTrumpetContent(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_SendTrumpetRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_SendTrumpetRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_S_SendTrumpetRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_szTrumpetContent'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_GR_S_SendTrumpetRef:szTrumpetContent"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szTrumpetContent(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szTrumpetContent();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_S_SendTrumpetRef:szTrumpetContent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_szTrumpetContent'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_SendTrumpetRef_dwSendUserID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_SendTrumpetRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_SendTrumpetRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_S_SendTrumpetRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_dwSendUserID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_GR_S_SendTrumpetRef:dwSendUserID");

            if (!ok) { break; }
            cobj->dwSendUserID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwSendUserID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_S_SendTrumpetRef:dwSendUserID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_dwSendUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_SendTrumpetRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_SendTrumpetRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_SendTrumpetRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_S_SendTrumpetRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_S_SendTrumpetRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_SendTrumpetRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_GR_S_SendTrumpetRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_S_SendTrumpetRef* ret = CMD_GR_S_SendTrumpetRef::createWithNotify();
        object_to_luaval<CMD_GR_S_SendTrumpetRef>(tolua_S, "CMD_GR_S_SendTrumpetRef",(CMD_GR_S_SendTrumpetRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_S_SendTrumpetRef* ret = CMD_GR_S_SendTrumpetRef::createWithNotify(arg0);
        object_to_luaval<CMD_GR_S_SendTrumpetRef>(tolua_S, "CMD_GR_S_SendTrumpetRef",(CMD_GR_S_SendTrumpetRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_GR_S_SendTrumpetRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_SendTrumpetRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_GR_S_SendTrumpetRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_GR_S_SendTrumpetRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_GR_S_SendTrumpetRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_GR_S_SendTrumpetRef");
    tolua_cclass(tolua_S,"CMD_GR_S_SendTrumpetRef","CMD_GR_S_SendTrumpetRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_GR_S_SendTrumpetRef");
        tolua_function(tolua_S,"TrumpetColor",lua_jt_cmd_CMD_GR_S_SendTrumpetRef_TrumpetColor);
        tolua_function(tolua_S,"wPropertyIndex",lua_jt_cmd_CMD_GR_S_SendTrumpetRef_wPropertyIndex);
        tolua_function(tolua_S,"szSendNickName",lua_jt_cmd_CMD_GR_S_SendTrumpetRef_szSendNickName);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_GR_S_SendTrumpetRef_setStruct);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_GR_S_SendTrumpetRef_getSize);
        tolua_function(tolua_S,"szTrumpetContent",lua_jt_cmd_CMD_GR_S_SendTrumpetRef_szTrumpetContent);
        tolua_function(tolua_S,"dwSendUserID",lua_jt_cmd_CMD_GR_S_SendTrumpetRef_dwSendUserID);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_GR_S_SendTrumpetRef_getData);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_GR_S_SendTrumpetRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_GR_S_SendTrumpetRef).name();
    g_luaType[typeName] = "CMD_GR_S_SendTrumpetRef";
    g_typeCast["CMD_GR_S_SendTrumpetRef"] = "CMD_GR_S_SendTrumpetRef";
    return 1;
}

int lua_jt_cmd_CMD_GR_PropSounaRef_playerID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_PropSounaRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_PropSounaRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_PropSounaRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_PropSounaRef_playerID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_GR_PropSounaRef:playerID");

            if (!ok) { break; }
            cobj->playerID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->playerID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_PropSounaRef:playerID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_PropSounaRef_playerID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_PropSounaRef_wGameID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_PropSounaRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_PropSounaRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_PropSounaRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_PropSounaRef_wGameID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_GR_PropSounaRef:wGameID");

            if (!ok) { break; }
            cobj->wGameID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wGameID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_PropSounaRef:wGameID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_PropSounaRef_wGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_PropSounaRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_PropSounaRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_PropSounaRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_PropSounaRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_PropSounaRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_PropSounaRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_PropSounaRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_PropSounaRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_PropSounaRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_PropSounaRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_PropSounaRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_PropSounaRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_PropSounaRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_PropSounaRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_PropSounaRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_PropSounaRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_PropSounaRef_szNickName(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_PropSounaRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_PropSounaRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_PropSounaRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_PropSounaRef_szNickName'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_GR_PropSounaRef:szNickName"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szNickName(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szNickName();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_PropSounaRef:szNickName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_PropSounaRef_szNickName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_PropSounaRef_wSuonaType(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_PropSounaRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_PropSounaRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_PropSounaRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_PropSounaRef_wSuonaType'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_GR_PropSounaRef:wSuonaType");

            if (!ok) { break; }
            cobj->wSuonaType(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wSuonaType();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_PropSounaRef:wSuonaType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_PropSounaRef_wSuonaType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_PropSounaRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_PropSounaRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_PropSounaRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_PropSounaRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_PropSounaRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_PropSounaRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_PropSounaRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_PropSounaRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_PropSounaRef_szMsg(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_PropSounaRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_PropSounaRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_PropSounaRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_PropSounaRef_szMsg'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_GR_PropSounaRef:szMsg"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szMsg(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szMsg();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_PropSounaRef:szMsg",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_PropSounaRef_szMsg'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_PropSounaRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_GR_PropSounaRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_PropSounaRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_PropSounaRef* ret = CMD_GR_PropSounaRef::createWithNotify();
        object_to_luaval<CMD_GR_PropSounaRef>(tolua_S, "CMD_GR_PropSounaRef",(CMD_GR_PropSounaRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_PropSounaRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_PropSounaRef* ret = CMD_GR_PropSounaRef::createWithNotify(arg0);
        object_to_luaval<CMD_GR_PropSounaRef>(tolua_S, "CMD_GR_PropSounaRef",(CMD_GR_PropSounaRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_GR_PropSounaRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_PropSounaRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_GR_PropSounaRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_GR_PropSounaRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_GR_PropSounaRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_GR_PropSounaRef");
    tolua_cclass(tolua_S,"CMD_GR_PropSounaRef","CMD_GR_PropSounaRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_GR_PropSounaRef");
        tolua_function(tolua_S,"playerID",lua_jt_cmd_CMD_GR_PropSounaRef_playerID);
        tolua_function(tolua_S,"wGameID",lua_jt_cmd_CMD_GR_PropSounaRef_wGameID);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_GR_PropSounaRef_setStruct);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_GR_PropSounaRef_getSize);
        tolua_function(tolua_S,"szNickName",lua_jt_cmd_CMD_GR_PropSounaRef_szNickName);
        tolua_function(tolua_S,"wSuonaType",lua_jt_cmd_CMD_GR_PropSounaRef_wSuonaType);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_GR_PropSounaRef_getData);
        tolua_function(tolua_S,"szMsg",lua_jt_cmd_CMD_GR_PropSounaRef_szMsg);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_GR_PropSounaRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_GR_PropSounaRef).name();
    g_luaType[typeName] = "CMD_GR_PropSounaRef";
    g_typeCast["CMD_GR_PropSounaRef"] = "CMD_GR_PropSounaRef";
    return 1;
}

int lua_jt_cmd_CMD_GR_S_UserChatRef_dwChatColor(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_UserChatRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_UserChatRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_S_UserChatRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_dwChatColor'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_GR_S_UserChatRef:dwChatColor");

            if (!ok) { break; }
            cobj->dwChatColor(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwChatColor();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_S_UserChatRef:dwChatColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_dwChatColor'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_UserChatRef_dwTargetUserID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_UserChatRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_UserChatRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_S_UserChatRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_dwTargetUserID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_GR_S_UserChatRef:dwTargetUserID");

            if (!ok) { break; }
            cobj->dwTargetUserID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwTargetUserID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_S_UserChatRef:dwTargetUserID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_dwTargetUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_UserChatRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_UserChatRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_UserChatRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_S_UserChatRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_S_UserChatRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_UserChatRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_UserChatRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_UserChatRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_S_UserChatRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_S_UserChatRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_UserChatRef_dwSendUserID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_UserChatRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_UserChatRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_S_UserChatRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_dwSendUserID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_GR_S_UserChatRef:dwSendUserID");

            if (!ok) { break; }
            cobj->dwSendUserID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwSendUserID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_S_UserChatRef:dwSendUserID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_dwSendUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_UserChatRef_szChatString(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_UserChatRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_UserChatRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_S_UserChatRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_szChatString'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_GR_S_UserChatRef:szChatString"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szChatString(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szChatString();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_S_UserChatRef:szChatString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_szChatString'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_UserChatRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_UserChatRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_UserChatRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_S_UserChatRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_S_UserChatRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_UserChatRef_wChatLength(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_UserChatRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_UserChatRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_S_UserChatRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_wChatLength'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_GR_S_UserChatRef:wChatLength");

            if (!ok) { break; }
            cobj->wChatLength(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wChatLength();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_S_UserChatRef:wChatLength",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_wChatLength'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_UserChatRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_GR_S_UserChatRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_S_UserChatRef* ret = CMD_GR_S_UserChatRef::createWithNotify();
        object_to_luaval<CMD_GR_S_UserChatRef>(tolua_S, "CMD_GR_S_UserChatRef",(CMD_GR_S_UserChatRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_S_UserChatRef* ret = CMD_GR_S_UserChatRef::createWithNotify(arg0);
        object_to_luaval<CMD_GR_S_UserChatRef>(tolua_S, "CMD_GR_S_UserChatRef",(CMD_GR_S_UserChatRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_GR_S_UserChatRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_UserChatRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_GR_S_UserChatRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_GR_S_UserChatRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_GR_S_UserChatRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_GR_S_UserChatRef");
    tolua_cclass(tolua_S,"CMD_GR_S_UserChatRef","CMD_GR_S_UserChatRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_GR_S_UserChatRef");
        tolua_function(tolua_S,"dwChatColor",lua_jt_cmd_CMD_GR_S_UserChatRef_dwChatColor);
        tolua_function(tolua_S,"dwTargetUserID",lua_jt_cmd_CMD_GR_S_UserChatRef_dwTargetUserID);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_GR_S_UserChatRef_setStruct);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_GR_S_UserChatRef_getSize);
        tolua_function(tolua_S,"dwSendUserID",lua_jt_cmd_CMD_GR_S_UserChatRef_dwSendUserID);
        tolua_function(tolua_S,"szChatString",lua_jt_cmd_CMD_GR_S_UserChatRef_szChatString);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_GR_S_UserChatRef_getData);
        tolua_function(tolua_S,"wChatLength",lua_jt_cmd_CMD_GR_S_UserChatRef_wChatLength);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_GR_S_UserChatRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_GR_S_UserChatRef).name();
    g_luaType[typeName] = "CMD_GR_S_UserChatRef";
    g_typeCast["CMD_GR_S_UserChatRef"] = "CMD_GR_S_UserChatRef";
    return 1;
}

int lua_jt_cmd_CMD_GF_S_UserExpressionRef_dwTargetUserID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GF_S_UserExpressionRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GF_S_UserExpressionRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GF_S_UserExpressionRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GF_S_UserExpressionRef_dwTargetUserID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_GF_S_UserExpressionRef:dwTargetUserID");

            if (!ok) { break; }
            cobj->dwTargetUserID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwTargetUserID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GF_S_UserExpressionRef:dwTargetUserID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GF_S_UserExpressionRef_dwTargetUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GF_S_UserExpressionRef_wItemIndex(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GF_S_UserExpressionRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GF_S_UserExpressionRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GF_S_UserExpressionRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GF_S_UserExpressionRef_wItemIndex'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_GF_S_UserExpressionRef:wItemIndex");

            if (!ok) { break; }
            cobj->wItemIndex(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wItemIndex();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GF_S_UserExpressionRef:wItemIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GF_S_UserExpressionRef_wItemIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GF_S_UserExpressionRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GF_S_UserExpressionRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GF_S_UserExpressionRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GF_S_UserExpressionRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GF_S_UserExpressionRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GF_S_UserExpressionRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GF_S_UserExpressionRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GF_S_UserExpressionRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GF_S_UserExpressionRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GF_S_UserExpressionRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GF_S_UserExpressionRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GF_S_UserExpressionRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GF_S_UserExpressionRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GF_S_UserExpressionRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GF_S_UserExpressionRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GF_S_UserExpressionRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GF_S_UserExpressionRef_dwSendUserID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GF_S_UserExpressionRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GF_S_UserExpressionRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GF_S_UserExpressionRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GF_S_UserExpressionRef_dwSendUserID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_GF_S_UserExpressionRef:dwSendUserID");

            if (!ok) { break; }
            cobj->dwSendUserID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwSendUserID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GF_S_UserExpressionRef:dwSendUserID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GF_S_UserExpressionRef_dwSendUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GF_S_UserExpressionRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GF_S_UserExpressionRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GF_S_UserExpressionRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GF_S_UserExpressionRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GF_S_UserExpressionRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GF_S_UserExpressionRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GF_S_UserExpressionRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GF_S_UserExpressionRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GF_S_UserExpressionRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_GF_S_UserExpressionRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GF_S_UserExpressionRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GF_S_UserExpressionRef* ret = CMD_GF_S_UserExpressionRef::createWithNotify();
        object_to_luaval<CMD_GF_S_UserExpressionRef>(tolua_S, "CMD_GF_S_UserExpressionRef",(CMD_GF_S_UserExpressionRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GF_S_UserExpressionRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GF_S_UserExpressionRef* ret = CMD_GF_S_UserExpressionRef::createWithNotify(arg0);
        object_to_luaval<CMD_GF_S_UserExpressionRef>(tolua_S, "CMD_GF_S_UserExpressionRef",(CMD_GF_S_UserExpressionRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_GF_S_UserExpressionRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GF_S_UserExpressionRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_GF_S_UserExpressionRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_GF_S_UserExpressionRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_GF_S_UserExpressionRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_GF_S_UserExpressionRef");
    tolua_cclass(tolua_S,"CMD_GF_S_UserExpressionRef","CMD_GF_S_UserExpressionRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_GF_S_UserExpressionRef");
        tolua_function(tolua_S,"dwTargetUserID",lua_jt_cmd_CMD_GF_S_UserExpressionRef_dwTargetUserID);
        tolua_function(tolua_S,"wItemIndex",lua_jt_cmd_CMD_GF_S_UserExpressionRef_wItemIndex);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_GF_S_UserExpressionRef_setStruct);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_GF_S_UserExpressionRef_getSize);
        tolua_function(tolua_S,"dwSendUserID",lua_jt_cmd_CMD_GF_S_UserExpressionRef_dwSendUserID);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_GF_S_UserExpressionRef_getData);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_GF_S_UserExpressionRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_GF_S_UserExpressionRef).name();
    g_luaType[typeName] = "CMD_GF_S_UserExpressionRef";
    g_typeCast["CMD_GF_S_UserExpressionRef"] = "CMD_GF_S_UserExpressionRef";
    return 1;
}

int lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_lTransScores(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_TransGoldRecordInfoRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_TransGoldRecordInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_S_TransGoldRecordInfoRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_lTransScores'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_GR_S_TransGoldRecordInfoRef:lTransScores");

            if (!ok) { break; }
            cobj->lTransScores(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lTransScores();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_S_TransGoldRecordInfoRef:lTransScores",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_lTransScores'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_szDescMsg(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_TransGoldRecordInfoRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_TransGoldRecordInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_S_TransGoldRecordInfoRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_szDescMsg'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_GR_S_TransGoldRecordInfoRef:szDescMsg"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szDescMsg(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szDescMsg();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_S_TransGoldRecordInfoRef:szDescMsg",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_szDescMsg'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_szDateTime(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_TransGoldRecordInfoRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_TransGoldRecordInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_S_TransGoldRecordInfoRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_szDateTime'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_GR_S_TransGoldRecordInfoRef:szDateTime"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szDateTime(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szDateTime();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_S_TransGoldRecordInfoRef:szDateTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_szDateTime'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_dwSourceGameID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_TransGoldRecordInfoRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_TransGoldRecordInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_S_TransGoldRecordInfoRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_dwSourceGameID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_GR_S_TransGoldRecordInfoRef:dwSourceGameID");

            if (!ok) { break; }
            cobj->dwSourceGameID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwSourceGameID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_S_TransGoldRecordInfoRef:dwSourceGameID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_dwSourceGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_TransGoldRecordInfoRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_TransGoldRecordInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_S_TransGoldRecordInfoRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_S_TransGoldRecordInfoRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_szClientIP(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_TransGoldRecordInfoRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_TransGoldRecordInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_S_TransGoldRecordInfoRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_szClientIP'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_GR_S_TransGoldRecordInfoRef:szClientIP"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szClientIP(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szClientIP();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_S_TransGoldRecordInfoRef:szClientIP",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_szClientIP'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_TransGoldRecordInfoRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_TransGoldRecordInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_S_TransGoldRecordInfoRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_S_TransGoldRecordInfoRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_szNickName(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_TransGoldRecordInfoRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_TransGoldRecordInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_S_TransGoldRecordInfoRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_szNickName'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_GR_S_TransGoldRecordInfoRef:szNickName"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szNickName(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szNickName();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_S_TransGoldRecordInfoRef:szNickName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_szNickName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_TransGoldRecordInfoRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_TransGoldRecordInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GR_S_TransGoldRecordInfoRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GR_S_TransGoldRecordInfoRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_dwTargetGameID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GR_S_TransGoldRecordInfoRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GR_S_TransGoldRecordInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GR_S_TransGoldRecordInfoRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_dwTargetGameID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_GR_S_TransGoldRecordInfoRef:dwTargetGameID");

            if (!ok) { break; }
            cobj->dwTargetGameID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwTargetGameID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GR_S_TransGoldRecordInfoRef:dwTargetGameID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_dwTargetGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_GR_S_TransGoldRecordInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_S_TransGoldRecordInfoRef* ret = CMD_GR_S_TransGoldRecordInfoRef::createWithNotify();
        object_to_luaval<CMD_GR_S_TransGoldRecordInfoRef>(tolua_S, "CMD_GR_S_TransGoldRecordInfoRef",(CMD_GR_S_TransGoldRecordInfoRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GR_S_TransGoldRecordInfoRef* ret = CMD_GR_S_TransGoldRecordInfoRef::createWithNotify(arg0);
        object_to_luaval<CMD_GR_S_TransGoldRecordInfoRef>(tolua_S, "CMD_GR_S_TransGoldRecordInfoRef",(CMD_GR_S_TransGoldRecordInfoRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_GR_S_TransGoldRecordInfoRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_GR_S_TransGoldRecordInfoRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_GR_S_TransGoldRecordInfoRef");
    tolua_cclass(tolua_S,"CMD_GR_S_TransGoldRecordInfoRef","CMD_GR_S_TransGoldRecordInfoRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_GR_S_TransGoldRecordInfoRef");
        tolua_function(tolua_S,"lTransScores",lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_lTransScores);
        tolua_function(tolua_S,"szDescMsg",lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_szDescMsg);
        tolua_function(tolua_S,"szDateTime",lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_szDateTime);
        tolua_function(tolua_S,"dwSourceGameID",lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_dwSourceGameID);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_setStruct);
        tolua_function(tolua_S,"szClientIP",lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_szClientIP);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_getSize);
        tolua_function(tolua_S,"szNickName",lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_szNickName);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_getData);
        tolua_function(tolua_S,"dwTargetGameID",lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_dwTargetGameID);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_GR_S_TransGoldRecordInfoRef).name();
    g_luaType[typeName] = "CMD_GR_S_TransGoldRecordInfoRef";
    g_typeCast["CMD_GR_S_TransGoldRecordInfoRef"] = "CMD_GR_S_TransGoldRecordInfoRef";
    return 1;
}

int lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_cbDeviceType(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonOtherPlatformRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonOtherPlatformRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonOtherPlatformRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_cbDeviceType'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_MB_LogonOtherPlatformRef:cbDeviceType");

            if (!ok) { break; }
            cobj->cbDeviceType(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbDeviceType();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonOtherPlatformRef:cbDeviceType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_cbDeviceType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_cbGender(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonOtherPlatformRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonOtherPlatformRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonOtherPlatformRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_cbGender'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_MB_LogonOtherPlatformRef:cbGender");

            if (!ok) { break; }
            cobj->cbGender(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbGender();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonOtherPlatformRef:cbGender",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_cbGender'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szPassword(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonOtherPlatformRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonOtherPlatformRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonOtherPlatformRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szPassword'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_MB_LogonOtherPlatformRef:szPassword"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szPassword(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szPassword();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonOtherPlatformRef:szPassword",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szPassword'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_dwPlazaVersion(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonOtherPlatformRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonOtherPlatformRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonOtherPlatformRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_dwPlazaVersion'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_MB_LogonOtherPlatformRef:dwPlazaVersion");

            if (!ok) { break; }
            cobj->dwPlazaVersion(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwPlazaVersion();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonOtherPlatformRef:dwPlazaVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_dwPlazaVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szDefaultFace(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonOtherPlatformRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonOtherPlatformRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonOtherPlatformRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szDefaultFace'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_MB_LogonOtherPlatformRef:szDefaultFace"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szDefaultFace(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szDefaultFace();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonOtherPlatformRef:szDefaultFace",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szDefaultFace'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonOtherPlatformRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonOtherPlatformRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_MB_LogonOtherPlatformRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_MB_LogonOtherPlatformRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_cVerifyString(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonOtherPlatformRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonOtherPlatformRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonOtherPlatformRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_cVerifyString'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_MB_LogonOtherPlatformRef:cVerifyString"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->cVerifyString(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->cVerifyString();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonOtherPlatformRef:cVerifyString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_cVerifyString'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonOtherPlatformRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonOtherPlatformRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_MB_LogonOtherPlatformRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_MB_LogonOtherPlatformRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szNickName(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonOtherPlatformRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonOtherPlatformRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonOtherPlatformRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szNickName'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_MB_LogonOtherPlatformRef:szNickName"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szNickName(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szNickName();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonOtherPlatformRef:szNickName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szNickName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_cbAcccountType(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonOtherPlatformRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonOtherPlatformRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonOtherPlatformRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_cbAcccountType'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_MB_LogonOtherPlatformRef:cbAcccountType");

            if (!ok) { break; }
            cobj->cbAcccountType(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbAcccountType();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonOtherPlatformRef:cbAcccountType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_cbAcccountType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonOtherPlatformRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonOtherPlatformRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_MB_LogonOtherPlatformRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_MB_LogonOtherPlatformRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szUUID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonOtherPlatformRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonOtherPlatformRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonOtherPlatformRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szUUID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_MB_LogonOtherPlatformRef:szUUID"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szUUID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szUUID();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonOtherPlatformRef:szUUID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szUUID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szMachineID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonOtherPlatformRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonOtherPlatformRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonOtherPlatformRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szMachineID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_MB_LogonOtherPlatformRef:szMachineID"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szMachineID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szMachineID();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonOtherPlatformRef:szMachineID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szMachineID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szHotVer(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonOtherPlatformRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonOtherPlatformRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonOtherPlatformRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szHotVer'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_MB_LogonOtherPlatformRef:szHotVer"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szHotVer(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szHotVer();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonOtherPlatformRef:szHotVer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szHotVer'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_MB_LogonOtherPlatformRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_MB_LogonOtherPlatformRef* ret = CMD_MB_LogonOtherPlatformRef::createWithNotify();
        object_to_luaval<CMD_MB_LogonOtherPlatformRef>(tolua_S, "CMD_MB_LogonOtherPlatformRef",(CMD_MB_LogonOtherPlatformRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_MB_LogonOtherPlatformRef* ret = CMD_MB_LogonOtherPlatformRef::createWithNotify(arg0);
        object_to_luaval<CMD_MB_LogonOtherPlatformRef>(tolua_S, "CMD_MB_LogonOtherPlatformRef",(CMD_MB_LogonOtherPlatformRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_MB_LogonOtherPlatformRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_MB_LogonOtherPlatformRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_MB_LogonOtherPlatformRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_MB_LogonOtherPlatformRef");
    tolua_cclass(tolua_S,"CMD_MB_LogonOtherPlatformRef","CMD_MB_LogonOtherPlatformRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_MB_LogonOtherPlatformRef");
        tolua_function(tolua_S,"cbDeviceType",lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_cbDeviceType);
        tolua_function(tolua_S,"cbGender",lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_cbGender);
        tolua_function(tolua_S,"szPassword",lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szPassword);
        tolua_function(tolua_S,"dwPlazaVersion",lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_dwPlazaVersion);
        tolua_function(tolua_S,"szDefaultFace",lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szDefaultFace);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_setStruct);
        tolua_function(tolua_S,"cVerifyString",lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_cVerifyString);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_getSize);
        tolua_function(tolua_S,"szNickName",lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szNickName);
        tolua_function(tolua_S,"cbAcccountType",lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_cbAcccountType);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_getData);
        tolua_function(tolua_S,"szUUID",lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szUUID);
        tolua_function(tolua_S,"szMachineID",lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szMachineID);
        tolua_function(tolua_S,"szHotVer",lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_szHotVer);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_MB_LogonOtherPlatformRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_MB_LogonOtherPlatformRef).name();
    g_luaType[typeName] = "CMD_MB_LogonOtherPlatformRef";
    g_typeCast["CMD_MB_LogonOtherPlatformRef"] = "CMD_MB_LogonOtherPlatformRef";
    return 1;
}

int lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_ItemCount(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_S_USER_PAWNSHOPRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_S_USER_PAWNSHOPRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GP_S_USER_PAWNSHOPRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_ItemCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_GP_S_USER_PAWNSHOPRef:ItemCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_ItemCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->ItemCount(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GP_S_USER_PAWNSHOPRef:ItemCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_ItemCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_ItemType(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_S_USER_PAWNSHOPRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_S_USER_PAWNSHOPRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GP_S_USER_PAWNSHOPRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_ItemType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_GP_S_USER_PAWNSHOPRef:ItemType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_ItemType'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->ItemType(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GP_S_USER_PAWNSHOPRef:ItemType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_ItemType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_BuyPrice(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_S_USER_PAWNSHOPRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_S_USER_PAWNSHOPRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GP_S_USER_PAWNSHOPRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_BuyPrice'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_GP_S_USER_PAWNSHOPRef:BuyPrice");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_BuyPrice'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->BuyPrice(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GP_S_USER_PAWNSHOPRef:BuyPrice",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_BuyPrice'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_S_USER_PAWNSHOPRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_S_USER_PAWNSHOPRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GP_S_USER_PAWNSHOPRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GP_S_USER_PAWNSHOPRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_S_USER_PAWNSHOPRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_S_USER_PAWNSHOPRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GP_S_USER_PAWNSHOPRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GP_S_USER_PAWNSHOPRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_SalePrice(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_S_USER_PAWNSHOPRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_S_USER_PAWNSHOPRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GP_S_USER_PAWNSHOPRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_SalePrice'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_GP_S_USER_PAWNSHOPRef:SalePrice");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_SalePrice'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->SalePrice(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GP_S_USER_PAWNSHOPRef:SalePrice",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_SalePrice'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_S_USER_PAWNSHOPRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_S_USER_PAWNSHOPRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GP_S_USER_PAWNSHOPRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GP_S_USER_PAWNSHOPRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_ItemName(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_S_USER_PAWNSHOPRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_S_USER_PAWNSHOPRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GP_S_USER_PAWNSHOPRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_ItemName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_GP_S_USER_PAWNSHOPRef:ItemName");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMD_GP_S_USER_PAWNSHOPRef:ItemName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_ItemName'", nullptr);
            return 0;
        }
        unsigned short ret = cobj->ItemName(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GP_S_USER_PAWNSHOPRef:ItemName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_ItemName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_GP_S_USER_PAWNSHOPRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GP_S_USER_PAWNSHOPRef* ret = CMD_GP_S_USER_PAWNSHOPRef::createWithNotify();
        object_to_luaval<CMD_GP_S_USER_PAWNSHOPRef>(tolua_S, "CMD_GP_S_USER_PAWNSHOPRef",(CMD_GP_S_USER_PAWNSHOPRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GP_S_USER_PAWNSHOPRef* ret = CMD_GP_S_USER_PAWNSHOPRef::createWithNotify(arg0);
        object_to_luaval<CMD_GP_S_USER_PAWNSHOPRef>(tolua_S, "CMD_GP_S_USER_PAWNSHOPRef",(CMD_GP_S_USER_PAWNSHOPRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_GP_S_USER_PAWNSHOPRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_GP_S_USER_PAWNSHOPRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_GP_S_USER_PAWNSHOPRef");
    tolua_cclass(tolua_S,"CMD_GP_S_USER_PAWNSHOPRef","CMD_GP_S_USER_PAWNSHOPRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_GP_S_USER_PAWNSHOPRef");
        tolua_function(tolua_S,"ItemCount",lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_ItemCount);
        tolua_function(tolua_S,"ItemType",lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_ItemType);
        tolua_function(tolua_S,"BuyPrice",lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_BuyPrice);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_setStruct);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_getSize);
        tolua_function(tolua_S,"SalePrice",lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_SalePrice);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_getData);
        tolua_function(tolua_S,"ItemName",lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_ItemName);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_GP_S_USER_PAWNSHOPRef).name();
    g_luaType[typeName] = "CMD_GP_S_USER_PAWNSHOPRef";
    g_typeCast["CMD_GP_S_USER_PAWNSHOPRef"] = "CMD_GP_S_USER_PAWNSHOPRef";
    return 1;
}

int lua_jt_cmd_CMD_MB_LogonSuccessRef_cbGender(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_cbGender'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_MB_LogonSuccessRef:cbGender");

            if (!ok) { break; }
            cobj->cbGender(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbGender();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonSuccessRef:cbGender",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_cbGender'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonSuccessRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonSuccessRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_MB_LogonSuccessRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_MB_LogonSuccessRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonSuccessRef_lUserDaimond(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_lUserDaimond'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_MB_LogonSuccessRef:lUserDaimond");

            if (!ok) { break; }
            cobj->lUserDaimond(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lUserDaimond();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonSuccessRef:lUserDaimond",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_lUserDaimond'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonSuccessRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonSuccessRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_MB_LogonSuccessRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_MB_LogonSuccessRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonSuccessRef_szNickName(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_szNickName'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_MB_LogonSuccessRef:szNickName"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szNickName(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szNickName();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonSuccessRef:szNickName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_szNickName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonSuccessRef_szFaceURL(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_szFaceURL'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_MB_LogonSuccessRef:szFaceURL"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szFaceURL(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szFaceURL();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonSuccessRef:szFaceURL",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_szFaceURL'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonSuccessRef_lUserScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_lUserScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_MB_LogonSuccessRef:lUserScore");

            if (!ok) { break; }
            cobj->lUserScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lUserScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonSuccessRef:lUserScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_lUserScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonSuccessRef_cbAccountType(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_cbAccountType'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_MB_LogonSuccessRef:cbAccountType");

            if (!ok) { break; }
            cobj->cbAccountType(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbAccountType();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonSuccessRef:cbAccountType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_cbAccountType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonSuccessRef_dwUserID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_dwUserID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_MB_LogonSuccessRef:dwUserID");

            if (!ok) { break; }
            cobj->dwUserID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwUserID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonSuccessRef:dwUserID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_dwUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonSuccessRef_dwGameID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_dwGameID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_MB_LogonSuccessRef:dwGameID");

            if (!ok) { break; }
            cobj->dwGameID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwGameID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonSuccessRef:dwGameID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_dwGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonSuccessRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonSuccessRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_MB_LogonSuccessRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_MB_LogonSuccessRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonSuccessRef_szUUID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_szUUID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_MB_LogonSuccessRef:szUUID"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szUUID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szUUID();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonSuccessRef:szUUID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_szUUID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonSuccessRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_MB_LogonSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_MB_LogonSuccessRef* ret = CMD_MB_LogonSuccessRef::createWithNotify();
        object_to_luaval<CMD_MB_LogonSuccessRef>(tolua_S, "CMD_MB_LogonSuccessRef",(CMD_MB_LogonSuccessRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_MB_LogonSuccessRef* ret = CMD_MB_LogonSuccessRef::createWithNotify(arg0);
        object_to_luaval<CMD_MB_LogonSuccessRef>(tolua_S, "CMD_MB_LogonSuccessRef",(CMD_MB_LogonSuccessRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_MB_LogonSuccessRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonSuccessRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_MB_LogonSuccessRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_MB_LogonSuccessRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_MB_LogonSuccessRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_MB_LogonSuccessRef");
    tolua_cclass(tolua_S,"CMD_MB_LogonSuccessRef","CMD_MB_LogonSuccessRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_MB_LogonSuccessRef");
        tolua_function(tolua_S,"cbGender",lua_jt_cmd_CMD_MB_LogonSuccessRef_cbGender);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_MB_LogonSuccessRef_setStruct);
        tolua_function(tolua_S,"lUserDaimond",lua_jt_cmd_CMD_MB_LogonSuccessRef_lUserDaimond);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_MB_LogonSuccessRef_getSize);
        tolua_function(tolua_S,"szNickName",lua_jt_cmd_CMD_MB_LogonSuccessRef_szNickName);
        tolua_function(tolua_S,"szFaceURL",lua_jt_cmd_CMD_MB_LogonSuccessRef_szFaceURL);
        tolua_function(tolua_S,"lUserScore",lua_jt_cmd_CMD_MB_LogonSuccessRef_lUserScore);
        tolua_function(tolua_S,"cbAccountType",lua_jt_cmd_CMD_MB_LogonSuccessRef_cbAccountType);
        tolua_function(tolua_S,"dwUserID",lua_jt_cmd_CMD_MB_LogonSuccessRef_dwUserID);
        tolua_function(tolua_S,"dwGameID",lua_jt_cmd_CMD_MB_LogonSuccessRef_dwGameID);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_MB_LogonSuccessRef_getData);
        tolua_function(tolua_S,"szUUID",lua_jt_cmd_CMD_MB_LogonSuccessRef_szUUID);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_MB_LogonSuccessRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_MB_LogonSuccessRef).name();
    g_luaType[typeName] = "CMD_MB_LogonSuccessRef";
    g_typeCast["CMD_MB_LogonSuccessRef"] = "CMD_MB_LogonSuccessRef";
    return 1;
}

int lua_jt_cmd_CMD_MB_LogonFailureRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonFailureRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonFailureRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_MB_LogonFailureRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonFailureRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_LogonFailureRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_MB_LogonFailureRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonFailureRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonFailureRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonFailureRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonFailureRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_MB_LogonFailureRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonFailureRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_LogonFailureRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_MB_LogonFailureRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonFailureRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonFailureRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonFailureRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonFailureRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_MB_LogonFailureRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonFailureRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_LogonFailureRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_MB_LogonFailureRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonFailureRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonFailureRef_szDescribeString(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonFailureRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonFailureRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonFailureRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonFailureRef_szDescribeString'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_MB_LogonFailureRef:szDescribeString"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szDescribeString(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szDescribeString();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonFailureRef:szDescribeString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonFailureRef_szDescribeString'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonFailureRef_lResultCode(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_LogonFailureRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_LogonFailureRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_LogonFailureRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_LogonFailureRef_lResultCode'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_MB_LogonFailureRef:lResultCode");

            if (!ok) { break; }
            cobj->lResultCode(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            int ret = cobj->lResultCode();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_LogonFailureRef:lResultCode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonFailureRef_lResultCode'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_LogonFailureRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_MB_LogonFailureRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_LogonFailureRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_MB_LogonFailureRef* ret = CMD_MB_LogonFailureRef::createWithNotify();
        object_to_luaval<CMD_MB_LogonFailureRef>(tolua_S, "CMD_MB_LogonFailureRef",(CMD_MB_LogonFailureRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_LogonFailureRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_MB_LogonFailureRef* ret = CMD_MB_LogonFailureRef::createWithNotify(arg0);
        object_to_luaval<CMD_MB_LogonFailureRef>(tolua_S, "CMD_MB_LogonFailureRef",(CMD_MB_LogonFailureRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_MB_LogonFailureRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_LogonFailureRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_MB_LogonFailureRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_MB_LogonFailureRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_MB_LogonFailureRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_MB_LogonFailureRef");
    tolua_cclass(tolua_S,"CMD_MB_LogonFailureRef","CMD_MB_LogonFailureRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_MB_LogonFailureRef");
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_MB_LogonFailureRef_getSize);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_MB_LogonFailureRef_setStruct);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_MB_LogonFailureRef_getData);
        tolua_function(tolua_S,"szDescribeString",lua_jt_cmd_CMD_MB_LogonFailureRef_szDescribeString);
        tolua_function(tolua_S,"lResultCode",lua_jt_cmd_CMD_MB_LogonFailureRef_lResultCode);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_MB_LogonFailureRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_MB_LogonFailureRef).name();
    g_luaType[typeName] = "CMD_MB_LogonFailureRef";
    g_typeCast["CMD_MB_LogonFailureRef"] = "CMD_MB_LogonFailureRef";
    return 1;
}

int lua_jt_cmd_tagLoginAwardRef_cbLoginCount(lua_State* tolua_S)
{
    int argc = 0;
    tagLoginAwardRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagLoginAwardRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagLoginAwardRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagLoginAwardRef_cbLoginCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagLoginAwardRef:cbLoginCount");

            if (!ok) { break; }
            cobj->cbLoginCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbLoginCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagLoginAwardRef:cbLoginCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagLoginAwardRef_cbLoginCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagLoginAwardRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    tagLoginAwardRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagLoginAwardRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagLoginAwardRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagLoginAwardRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagLoginAwardRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagLoginAwardRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagLoginAwardRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagLoginAwardRef_wAwardCount(lua_State* tolua_S)
{
    int argc = 0;
    tagLoginAwardRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagLoginAwardRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagLoginAwardRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagLoginAwardRef_wAwardCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagLoginAwardRef:wAwardCount");

            if (!ok) { break; }
            cobj->wAwardCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wAwardCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagLoginAwardRef:wAwardCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagLoginAwardRef_wAwardCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagLoginAwardRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    tagLoginAwardRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagLoginAwardRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagLoginAwardRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagLoginAwardRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagLoginAwardRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagLoginAwardRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagLoginAwardRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagLoginAwardRef_cbAwardType(lua_State* tolua_S)
{
    int argc = 0;
    tagLoginAwardRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagLoginAwardRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagLoginAwardRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagLoginAwardRef_cbAwardType'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagLoginAwardRef:cbAwardType");

            if (!ok) { break; }
            cobj->cbAwardType(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbAwardType();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagLoginAwardRef:cbAwardType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagLoginAwardRef_cbAwardType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagLoginAwardRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    tagLoginAwardRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagLoginAwardRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagLoginAwardRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagLoginAwardRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagLoginAwardRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagLoginAwardRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagLoginAwardRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagLoginAwardRef_cbAwardSubType(lua_State* tolua_S)
{
    int argc = 0;
    tagLoginAwardRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagLoginAwardRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagLoginAwardRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_tagLoginAwardRef_cbAwardSubType'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "tagLoginAwardRef:cbAwardSubType");

            if (!ok) { break; }
            cobj->cbAwardSubType(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbAwardSubType();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagLoginAwardRef:cbAwardSubType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagLoginAwardRef_cbAwardSubType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_tagLoginAwardRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"tagLoginAwardRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagLoginAwardRef_createWithNotify'", nullptr);
            return 0;
        }
        tagLoginAwardRef* ret = tagLoginAwardRef::createWithNotify();
        object_to_luaval<tagLoginAwardRef>(tolua_S, "tagLoginAwardRef",(tagLoginAwardRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_tagLoginAwardRef_createWithNotify'", nullptr);
            return 0;
        }
        tagLoginAwardRef* ret = tagLoginAwardRef::createWithNotify(arg0);
        object_to_luaval<tagLoginAwardRef>(tolua_S, "tagLoginAwardRef",(tagLoginAwardRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "tagLoginAwardRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_tagLoginAwardRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_tagLoginAwardRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagLoginAwardRef)");
    return 0;
}

int lua_register_jt_cmd_tagLoginAwardRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagLoginAwardRef");
    tolua_cclass(tolua_S,"tagLoginAwardRef","tagLoginAwardRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"tagLoginAwardRef");
        tolua_function(tolua_S,"cbLoginCount",lua_jt_cmd_tagLoginAwardRef_cbLoginCount);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_tagLoginAwardRef_setStruct);
        tolua_function(tolua_S,"wAwardCount",lua_jt_cmd_tagLoginAwardRef_wAwardCount);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_tagLoginAwardRef_getSize);
        tolua_function(tolua_S,"cbAwardType",lua_jt_cmd_tagLoginAwardRef_cbAwardType);
        tolua_function(tolua_S,"getData",lua_jt_cmd_tagLoginAwardRef_getData);
        tolua_function(tolua_S,"cbAwardSubType",lua_jt_cmd_tagLoginAwardRef_cbAwardSubType);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_tagLoginAwardRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagLoginAwardRef).name();
    g_luaType[typeName] = "tagLoginAwardRef";
    g_typeCast["tagLoginAwardRef"] = "tagLoginAwardRef";
    return 1;
}

int lua_jt_cmd_CMD_GP_LoginAwardRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_LoginAwardRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_LoginAwardRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GP_LoginAwardRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_LoginAwardRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_LoginAwardRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GP_LoginAwardRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_LoginAwardRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_LoginAwardRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_LoginAwardRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_LoginAwardRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GP_LoginAwardRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_LoginAwardRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_LoginAwardRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GP_LoginAwardRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_LoginAwardRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_LoginAwardRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_LoginAwardRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_LoginAwardRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GP_LoginAwardRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_LoginAwardRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_LoginAwardRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GP_LoginAwardRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_LoginAwardRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_LoginAwardRef_cbDayCount(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_LoginAwardRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_LoginAwardRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GP_LoginAwardRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_LoginAwardRef_cbDayCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_GP_LoginAwardRef:cbDayCount");

            if (!ok) { break; }
            cobj->cbDayCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbDayCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GP_LoginAwardRef:cbDayCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_LoginAwardRef_cbDayCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_LoginAwardRef_cbMaxCount(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_LoginAwardRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_LoginAwardRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GP_LoginAwardRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_LoginAwardRef_cbMaxCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_GP_LoginAwardRef:cbMaxCount");

            if (!ok) { break; }
            cobj->cbMaxCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbMaxCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GP_LoginAwardRef:cbMaxCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_LoginAwardRef_cbMaxCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_LoginAwardRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_GP_LoginAwardRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_LoginAwardRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GP_LoginAwardRef* ret = CMD_GP_LoginAwardRef::createWithNotify();
        object_to_luaval<CMD_GP_LoginAwardRef>(tolua_S, "CMD_GP_LoginAwardRef",(CMD_GP_LoginAwardRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_LoginAwardRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GP_LoginAwardRef* ret = CMD_GP_LoginAwardRef::createWithNotify(arg0);
        object_to_luaval<CMD_GP_LoginAwardRef>(tolua_S, "CMD_GP_LoginAwardRef",(CMD_GP_LoginAwardRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_GP_LoginAwardRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_LoginAwardRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_GP_LoginAwardRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_GP_LoginAwardRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_GP_LoginAwardRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_GP_LoginAwardRef");
    tolua_cclass(tolua_S,"CMD_GP_LoginAwardRef","CMD_GP_LoginAwardRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_GP_LoginAwardRef");
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_GP_LoginAwardRef_getSize);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_GP_LoginAwardRef_setStruct);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_GP_LoginAwardRef_getData);
        tolua_function(tolua_S,"cbDayCount",lua_jt_cmd_CMD_GP_LoginAwardRef_cbDayCount);
        tolua_function(tolua_S,"cbMaxCount",lua_jt_cmd_CMD_GP_LoginAwardRef_cbMaxCount);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_GP_LoginAwardRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_GP_LoginAwardRef).name();
    g_luaType[typeName] = "CMD_GP_LoginAwardRef";
    g_typeCast["CMD_GP_LoginAwardRef"] = "CMD_GP_LoginAwardRef";
    return 1;
}

int lua_jt_cmd_CMD_MB_UpdateNotifyRef_cbAdviceUpdate(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_UpdateNotifyRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_UpdateNotifyRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_UpdateNotifyRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_cbAdviceUpdate'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_MB_UpdateNotifyRef:cbAdviceUpdate");

            if (!ok) { break; }
            cobj->cbAdviceUpdate(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbAdviceUpdate();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_UpdateNotifyRef:cbAdviceUpdate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_cbAdviceUpdate'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_UpdateNotifyRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_UpdateNotifyRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_UpdateNotifyRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_MB_UpdateNotifyRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_MB_UpdateNotifyRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_UpdateNotifyRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_UpdateNotifyRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_UpdateNotifyRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_MB_UpdateNotifyRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_MB_UpdateNotifyRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_UpdateNotifyRef_cbMustUpdate(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_UpdateNotifyRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_UpdateNotifyRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_UpdateNotifyRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_cbMustUpdate'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_MB_UpdateNotifyRef:cbMustUpdate");

            if (!ok) { break; }
            cobj->cbMustUpdate(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbMustUpdate();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_UpdateNotifyRef:cbMustUpdate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_cbMustUpdate'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_UpdateNotifyRef_dwCurrentVersion(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_UpdateNotifyRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_UpdateNotifyRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_UpdateNotifyRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_dwCurrentVersion'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_MB_UpdateNotifyRef:dwCurrentVersion");

            if (!ok) { break; }
            cobj->dwCurrentVersion(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwCurrentVersion();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_UpdateNotifyRef:dwCurrentVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_dwCurrentVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_UpdateNotifyRef_cbHotUpdate(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_UpdateNotifyRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_UpdateNotifyRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_UpdateNotifyRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_cbHotUpdate'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_MB_UpdateNotifyRef:cbHotUpdate");

            if (!ok) { break; }
            cobj->cbHotUpdate(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbHotUpdate();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_UpdateNotifyRef:cbHotUpdate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_cbHotUpdate'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_UpdateNotifyRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_UpdateNotifyRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_UpdateNotifyRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_MB_UpdateNotifyRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_MB_UpdateNotifyRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_UpdateNotifyRef_szHotVer(lua_State* tolua_S)
{
    int argc = 0;
    CMD_MB_UpdateNotifyRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_MB_UpdateNotifyRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_MB_UpdateNotifyRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_szHotVer'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_MB_UpdateNotifyRef:szHotVer"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szHotVer(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szHotVer();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_MB_UpdateNotifyRef:szHotVer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_szHotVer'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_MB_UpdateNotifyRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_MB_UpdateNotifyRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_MB_UpdateNotifyRef* ret = CMD_MB_UpdateNotifyRef::createWithNotify();
        object_to_luaval<CMD_MB_UpdateNotifyRef>(tolua_S, "CMD_MB_UpdateNotifyRef",(CMD_MB_UpdateNotifyRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_MB_UpdateNotifyRef* ret = CMD_MB_UpdateNotifyRef::createWithNotify(arg0);
        object_to_luaval<CMD_MB_UpdateNotifyRef>(tolua_S, "CMD_MB_UpdateNotifyRef",(CMD_MB_UpdateNotifyRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_MB_UpdateNotifyRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_MB_UpdateNotifyRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_MB_UpdateNotifyRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_MB_UpdateNotifyRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_MB_UpdateNotifyRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_MB_UpdateNotifyRef");
    tolua_cclass(tolua_S,"CMD_MB_UpdateNotifyRef","CMD_MB_UpdateNotifyRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_MB_UpdateNotifyRef");
        tolua_function(tolua_S,"cbAdviceUpdate",lua_jt_cmd_CMD_MB_UpdateNotifyRef_cbAdviceUpdate);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_MB_UpdateNotifyRef_setStruct);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_MB_UpdateNotifyRef_getSize);
        tolua_function(tolua_S,"cbMustUpdate",lua_jt_cmd_CMD_MB_UpdateNotifyRef_cbMustUpdate);
        tolua_function(tolua_S,"dwCurrentVersion",lua_jt_cmd_CMD_MB_UpdateNotifyRef_dwCurrentVersion);
        tolua_function(tolua_S,"cbHotUpdate",lua_jt_cmd_CMD_MB_UpdateNotifyRef_cbHotUpdate);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_MB_UpdateNotifyRef_getData);
        tolua_function(tolua_S,"szHotVer",lua_jt_cmd_CMD_MB_UpdateNotifyRef_szHotVer);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_MB_UpdateNotifyRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_MB_UpdateNotifyRef).name();
    g_luaType[typeName] = "CMD_MB_UpdateNotifyRef";
    g_typeCast["CMD_MB_UpdateNotifyRef"] = "CMD_MB_UpdateNotifyRef";
    return 1;
}

int lua_jt_cmd_CMD_GP_UserInsureInfoRef_wRevenueTransfer(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureInfoRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GP_UserInsureInfoRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_wRevenueTransfer'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_GP_UserInsureInfoRef:wRevenueTransfer");

            if (!ok) { break; }
            cobj->wRevenueTransfer(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wRevenueTransfer();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GP_UserInsureInfoRef:wRevenueTransfer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_wRevenueTransfer'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureInfoRef_lUserInsure(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureInfoRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GP_UserInsureInfoRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_lUserInsure'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_GP_UserInsureInfoRef:lUserInsure");

            if (!ok) { break; }
            cobj->lUserInsure(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lUserInsure();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GP_UserInsureInfoRef:lUserInsure",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_lUserInsure'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureInfoRef_wRevenueTake(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureInfoRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GP_UserInsureInfoRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_wRevenueTake'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_GP_UserInsureInfoRef:wRevenueTake");

            if (!ok) { break; }
            cobj->wRevenueTake(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wRevenueTake();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GP_UserInsureInfoRef:wRevenueTake",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_wRevenueTake'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureInfoRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureInfoRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GP_UserInsureInfoRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GP_UserInsureInfoRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureInfoRef_wServerID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureInfoRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GP_UserInsureInfoRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_wServerID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_GP_UserInsureInfoRef:wServerID");

            if (!ok) { break; }
            cobj->wServerID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wServerID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GP_UserInsureInfoRef:wServerID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_wServerID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureInfoRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureInfoRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GP_UserInsureInfoRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GP_UserInsureInfoRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureInfoRef_lUserScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureInfoRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GP_UserInsureInfoRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_lUserScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_GP_UserInsureInfoRef:lUserScore");

            if (!ok) { break; }
            cobj->lUserScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lUserScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GP_UserInsureInfoRef:lUserScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_lUserScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureInfoRef_lTransferPrerequisite(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureInfoRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GP_UserInsureInfoRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_lTransferPrerequisite'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_GP_UserInsureInfoRef:lTransferPrerequisite");

            if (!ok) { break; }
            cobj->lTransferPrerequisite(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lTransferPrerequisite();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GP_UserInsureInfoRef:lTransferPrerequisite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_lTransferPrerequisite'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureInfoRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureInfoRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GP_UserInsureInfoRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GP_UserInsureInfoRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureInfoRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_GP_UserInsureInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GP_UserInsureInfoRef* ret = CMD_GP_UserInsureInfoRef::createWithNotify();
        object_to_luaval<CMD_GP_UserInsureInfoRef>(tolua_S, "CMD_GP_UserInsureInfoRef",(CMD_GP_UserInsureInfoRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GP_UserInsureInfoRef* ret = CMD_GP_UserInsureInfoRef::createWithNotify(arg0);
        object_to_luaval<CMD_GP_UserInsureInfoRef>(tolua_S, "CMD_GP_UserInsureInfoRef",(CMD_GP_UserInsureInfoRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_GP_UserInsureInfoRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureInfoRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_GP_UserInsureInfoRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_GP_UserInsureInfoRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_GP_UserInsureInfoRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_GP_UserInsureInfoRef");
    tolua_cclass(tolua_S,"CMD_GP_UserInsureInfoRef","CMD_GP_UserInsureInfoRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_GP_UserInsureInfoRef");
        tolua_function(tolua_S,"wRevenueTransfer",lua_jt_cmd_CMD_GP_UserInsureInfoRef_wRevenueTransfer);
        tolua_function(tolua_S,"lUserInsure",lua_jt_cmd_CMD_GP_UserInsureInfoRef_lUserInsure);
        tolua_function(tolua_S,"wRevenueTake",lua_jt_cmd_CMD_GP_UserInsureInfoRef_wRevenueTake);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_GP_UserInsureInfoRef_setStruct);
        tolua_function(tolua_S,"wServerID",lua_jt_cmd_CMD_GP_UserInsureInfoRef_wServerID);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_GP_UserInsureInfoRef_getSize);
        tolua_function(tolua_S,"lUserScore",lua_jt_cmd_CMD_GP_UserInsureInfoRef_lUserScore);
        tolua_function(tolua_S,"lTransferPrerequisite",lua_jt_cmd_CMD_GP_UserInsureInfoRef_lTransferPrerequisite);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_GP_UserInsureInfoRef_getData);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_GP_UserInsureInfoRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_GP_UserInsureInfoRef).name();
    g_luaType[typeName] = "CMD_GP_UserInsureInfoRef";
    g_typeCast["CMD_GP_UserInsureInfoRef"] = "CMD_GP_UserInsureInfoRef";
    return 1;
}

int lua_jt_cmd_CMD_GP_UserInsureSuccessRef_lUserInsure(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GP_UserInsureSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_lUserInsure'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_GP_UserInsureSuccessRef:lUserInsure");

            if (!ok) { break; }
            cobj->lUserInsure(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lUserInsure();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GP_UserInsureSuccessRef:lUserInsure",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_lUserInsure'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureSuccessRef_szReceName(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GP_UserInsureSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_szReceName'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_GP_UserInsureSuccessRef:szReceName"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szReceName(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szReceName();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GP_UserInsureSuccessRef:szReceName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_szReceName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureSuccessRef_szDateTime(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GP_UserInsureSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_szDateTime'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_GP_UserInsureSuccessRef:szDateTime"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szDateTime(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szDateTime();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GP_UserInsureSuccessRef:szDateTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_szDateTime'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureSuccessRef_dwFromGameID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GP_UserInsureSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_dwFromGameID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_GP_UserInsureSuccessRef:dwFromGameID");

            if (!ok) { break; }
            cobj->dwFromGameID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwFromGameID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GP_UserInsureSuccessRef:dwFromGameID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_dwFromGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureSuccessRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureSuccessRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GP_UserInsureSuccessRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GP_UserInsureSuccessRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureSuccessRef_szDescribeString(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GP_UserInsureSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_szDescribeString'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_GP_UserInsureSuccessRef:szDescribeString"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szDescribeString(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szDescribeString();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GP_UserInsureSuccessRef:szDescribeString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_szDescribeString'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureSuccessRef_lInsureRevenue(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GP_UserInsureSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_lInsureRevenue'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_GP_UserInsureSuccessRef:lInsureRevenue");

            if (!ok) { break; }
            cobj->lInsureRevenue(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lInsureRevenue();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GP_UserInsureSuccessRef:lInsureRevenue",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_lInsureRevenue'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureSuccessRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureSuccessRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GP_UserInsureSuccessRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GP_UserInsureSuccessRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureSuccessRef_szNickName(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GP_UserInsureSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_szNickName'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_GP_UserInsureSuccessRef:szNickName"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szNickName(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szNickName();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GP_UserInsureSuccessRef:szNickName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_szNickName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureSuccessRef_lUserScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GP_UserInsureSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_lUserScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_GP_UserInsureSuccessRef:lUserScore");

            if (!ok) { break; }
            cobj->lUserScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lUserScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GP_UserInsureSuccessRef:lUserScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_lUserScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureSuccessRef_dwReceGameID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GP_UserInsureSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_dwReceGameID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_GP_UserInsureSuccessRef:dwReceGameID");

            if (!ok) { break; }
            cobj->dwReceGameID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwReceGameID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GP_UserInsureSuccessRef:dwReceGameID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_dwReceGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureSuccessRef_lInsureTransfer(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GP_UserInsureSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_lInsureTransfer'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_GP_UserInsureSuccessRef:lInsureTransfer");

            if (!ok) { break; }
            cobj->lInsureTransfer(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lInsureTransfer();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GP_UserInsureSuccessRef:lInsureTransfer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_lInsureTransfer'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureSuccessRef_dwUserID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureSuccessRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_GP_UserInsureSuccessRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_dwUserID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "CMD_GP_UserInsureSuccessRef:dwUserID");

            if (!ok) { break; }
            cobj->dwUserID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned int ret = cobj->dwUserID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_GP_UserInsureSuccessRef:dwUserID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_dwUserID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureSuccessRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_GP_UserInsureSuccessRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_GP_UserInsureSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_GP_UserInsureSuccessRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_GP_UserInsureSuccessRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_GP_UserInsureSuccessRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_GP_UserInsureSuccessRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GP_UserInsureSuccessRef* ret = CMD_GP_UserInsureSuccessRef::createWithNotify();
        object_to_luaval<CMD_GP_UserInsureSuccessRef>(tolua_S, "CMD_GP_UserInsureSuccessRef",(CMD_GP_UserInsureSuccessRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_GP_UserInsureSuccessRef* ret = CMD_GP_UserInsureSuccessRef::createWithNotify(arg0);
        object_to_luaval<CMD_GP_UserInsureSuccessRef>(tolua_S, "CMD_GP_UserInsureSuccessRef",(CMD_GP_UserInsureSuccessRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_GP_UserInsureSuccessRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_GP_UserInsureSuccessRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_GP_UserInsureSuccessRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_GP_UserInsureSuccessRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_GP_UserInsureSuccessRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_GP_UserInsureSuccessRef");
    tolua_cclass(tolua_S,"CMD_GP_UserInsureSuccessRef","CMD_GP_UserInsureSuccessRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_GP_UserInsureSuccessRef");
        tolua_function(tolua_S,"lUserInsure",lua_jt_cmd_CMD_GP_UserInsureSuccessRef_lUserInsure);
        tolua_function(tolua_S,"szReceName",lua_jt_cmd_CMD_GP_UserInsureSuccessRef_szReceName);
        tolua_function(tolua_S,"szDateTime",lua_jt_cmd_CMD_GP_UserInsureSuccessRef_szDateTime);
        tolua_function(tolua_S,"dwFromGameID",lua_jt_cmd_CMD_GP_UserInsureSuccessRef_dwFromGameID);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_GP_UserInsureSuccessRef_setStruct);
        tolua_function(tolua_S,"szDescribeString",lua_jt_cmd_CMD_GP_UserInsureSuccessRef_szDescribeString);
        tolua_function(tolua_S,"lInsureRevenue",lua_jt_cmd_CMD_GP_UserInsureSuccessRef_lInsureRevenue);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_GP_UserInsureSuccessRef_getSize);
        tolua_function(tolua_S,"szNickName",lua_jt_cmd_CMD_GP_UserInsureSuccessRef_szNickName);
        tolua_function(tolua_S,"lUserScore",lua_jt_cmd_CMD_GP_UserInsureSuccessRef_lUserScore);
        tolua_function(tolua_S,"dwReceGameID",lua_jt_cmd_CMD_GP_UserInsureSuccessRef_dwReceGameID);
        tolua_function(tolua_S,"lInsureTransfer",lua_jt_cmd_CMD_GP_UserInsureSuccessRef_lInsureTransfer);
        tolua_function(tolua_S,"dwUserID",lua_jt_cmd_CMD_GP_UserInsureSuccessRef_dwUserID);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_GP_UserInsureSuccessRef_getData);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_GP_UserInsureSuccessRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_GP_UserInsureSuccessRef).name();
    g_luaType[typeName] = "CMD_GP_UserInsureSuccessRef";
    g_typeCast["CMD_GP_UserInsureSuccessRef"] = "CMD_GP_UserInsureSuccessRef";
    return 1;
}

int lua_jt_cmd_CMD_CM_SystemMessageRef_wLength(lua_State* tolua_S)
{
    int argc = 0;
    CMD_CM_SystemMessageRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_CM_SystemMessageRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_CM_SystemMessageRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_CM_SystemMessageRef_wLength'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_CM_SystemMessageRef:wLength");

            if (!ok) { break; }
            cobj->wLength(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wLength();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_CM_SystemMessageRef:wLength",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_CM_SystemMessageRef_wLength'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_CM_SystemMessageRef_szString(lua_State* tolua_S)
{
    int argc = 0;
    CMD_CM_SystemMessageRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_CM_SystemMessageRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_CM_SystemMessageRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_CM_SystemMessageRef_szString'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_CM_SystemMessageRef:szString"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szString(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szString();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_CM_SystemMessageRef:szString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_CM_SystemMessageRef_szString'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_CM_SystemMessageRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_CM_SystemMessageRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_CM_SystemMessageRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_CM_SystemMessageRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_CM_SystemMessageRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_CM_SystemMessageRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_CM_SystemMessageRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_CM_SystemMessageRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_CM_SystemMessageRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_CM_SystemMessageRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_CM_SystemMessageRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_CM_SystemMessageRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_CM_SystemMessageRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_CM_SystemMessageRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_CM_SystemMessageRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_CM_SystemMessageRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_CM_SystemMessageRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_CM_SystemMessageRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_CM_SystemMessageRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_CM_SystemMessageRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_CM_SystemMessageRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_CM_SystemMessageRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_CM_SystemMessageRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_CM_SystemMessageRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_CM_SystemMessageRef_wType(lua_State* tolua_S)
{
    int argc = 0;
    CMD_CM_SystemMessageRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_CM_SystemMessageRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_CM_SystemMessageRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_cmd_CMD_CM_SystemMessageRef_wType'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_CM_SystemMessageRef:wType");

            if (!ok) { break; }
            cobj->wType(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wType();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_CM_SystemMessageRef:wType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_CM_SystemMessageRef_wType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_cmd_CMD_CM_SystemMessageRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_CM_SystemMessageRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_CM_SystemMessageRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_CM_SystemMessageRef* ret = CMD_CM_SystemMessageRef::createWithNotify();
        object_to_luaval<CMD_CM_SystemMessageRef>(tolua_S, "CMD_CM_SystemMessageRef",(CMD_CM_SystemMessageRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_cmd_CMD_CM_SystemMessageRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_CM_SystemMessageRef* ret = CMD_CM_SystemMessageRef::createWithNotify(arg0);
        object_to_luaval<CMD_CM_SystemMessageRef>(tolua_S, "CMD_CM_SystemMessageRef",(CMD_CM_SystemMessageRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_CM_SystemMessageRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_cmd_CMD_CM_SystemMessageRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_cmd_CMD_CM_SystemMessageRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_CM_SystemMessageRef)");
    return 0;
}

int lua_register_jt_cmd_CMD_CM_SystemMessageRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_CM_SystemMessageRef");
    tolua_cclass(tolua_S,"CMD_CM_SystemMessageRef","CMD_CM_SystemMessageRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_CM_SystemMessageRef");
        tolua_function(tolua_S,"wLength",lua_jt_cmd_CMD_CM_SystemMessageRef_wLength);
        tolua_function(tolua_S,"szString",lua_jt_cmd_CMD_CM_SystemMessageRef_szString);
        tolua_function(tolua_S,"setStruct",lua_jt_cmd_CMD_CM_SystemMessageRef_setStruct);
        tolua_function(tolua_S,"getSize",lua_jt_cmd_CMD_CM_SystemMessageRef_getSize);
        tolua_function(tolua_S,"getData",lua_jt_cmd_CMD_CM_SystemMessageRef_getData);
        tolua_function(tolua_S,"wType",lua_jt_cmd_CMD_CM_SystemMessageRef_wType);
        tolua_function(tolua_S,"createWithNotify", lua_jt_cmd_CMD_CM_SystemMessageRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_CM_SystemMessageRef).name();
    g_luaType[typeName] = "CMD_CM_SystemMessageRef";
    g_typeCast["CMD_CM_SystemMessageRef"] = "CMD_CM_SystemMessageRef";
    return 1;
}
TOLUA_API int register_all_jt_cmd(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"jt",0);
	tolua_beginmodule(tolua_S,"jt");

	lua_register_jt_cmd_CMD_BASE(tolua_S);
	lua_register_jt_cmd_CMD_GR_PropSounaRef(tolua_S);
	lua_register_jt_cmd_CMD_MB_LogonFailureRef(tolua_S);
	lua_register_jt_cmd_tagUserScoreRef(tolua_S);
	lua_register_jt_cmd_CMD_GR_UserScoreRef(tolua_S);
	lua_register_jt_cmd_tagLoginAwardRef(tolua_S);
	lua_register_jt_cmd_CMD_CM_SystemMessageRef(tolua_S);
	lua_register_jt_cmd_CMD_GR_ConfigServerRef(tolua_S);
	lua_register_jt_cmd_CMD_GR_RequestFailureRef(tolua_S);
	lua_register_jt_cmd_CMD_GP_UserInsureSuccessRef(tolua_S);
	lua_register_jt_cmd_CMD_GP_LoginAwardRef(tolua_S);
	lua_register_jt_cmd_tagGameServerRef(tolua_S);
	lua_register_jt_cmd_tagMobileUserScoreRef(tolua_S);
	lua_register_jt_cmd_CMD_GR_UserStatusRef(tolua_S);
	lua_register_jt_cmd_tagUserStatusRef(tolua_S);
	lua_register_jt_cmd_CMD_GR_S_TransGoldRecordInfoRef(tolua_S);
	lua_register_jt_cmd_CMD_GR_S_UserChatRef(tolua_S);
	lua_register_jt_cmd_CMD_GR_S_SendTrumpetRef(tolua_S);
	lua_register_jt_cmd_CMD_MB_LogonSuccessRef(tolua_S);
	lua_register_jt_cmd_CMD_MB_UpdateNotifyRef(tolua_S);
	lua_register_jt_cmd_CMD_GP_S_USER_PAWNSHOPRef(tolua_S);
	lua_register_jt_cmd_CMD_GR_C_SendTrumpetRef(tolua_S);
	lua_register_jt_cmd_CMD_MB_LogonOtherPlatformRef(tolua_S);
	lua_register_jt_cmd_tagMobileUserInfoHeadRef(tolua_S);
	lua_register_jt_cmd_CMD_GR_MobileUserScoreRef(tolua_S);
	lua_register_jt_cmd_CMD_GP_UserInsureInfoRef(tolua_S);
	lua_register_jt_cmd_CMD_GF_S_UserExpressionRef(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

