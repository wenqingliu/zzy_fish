#include "lua_jt_game_auto.hpp"
#include "CMD_Base.h"
#include "CMD_OxBattleRef.h"
#include "CMD_OxBattleNewRef.h"
#include "GameLogicHunNewRef.h"
#include "VSGameLogicRef.h"
#include "KPQZGameLogicRef.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_jt_game_CMD_BASE_getSize(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_BASE_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_BASE_getSize'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_BASE_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_BASE_setStruct(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_BASE_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_BASE_setStruct'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_BASE_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_BASE_getData(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_BASE_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_BASE_getData'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_BASE_getData'.",&tolua_err);
#endif

    return 0;
}
static int lua_jt_game_CMD_BASE_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_BASE)");
    return 0;
}

int lua_register_jt_game_CMD_BASE(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_BASE");
    tolua_cclass(tolua_S,"CMD_BASE","CMD_BASE","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CMD_BASE");
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_BASE_getSize);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_BASE_setStruct);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_BASE_getData);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_BASE).name();
    g_luaType[typeName] = "CMD_BASE";
    g_typeCast["CMD_BASE"] = "CMD_BASE";
    return 1;
}

int lua_jt_game_tagServerGameRecordRef_bWinDuiMen(lua_State* tolua_S)
{
    int argc = 0;
    tagServerGameRecordRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerGameRecordRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagServerGameRecordRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagServerGameRecordRef_bWinDuiMen'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2,&arg0, "tagServerGameRecordRef:bWinDuiMen");

            if (!ok) { break; }
            cobj->bWinDuiMen(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            bool ret = cobj->bWinDuiMen();
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagServerGameRecordRef:bWinDuiMen",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagServerGameRecordRef_bWinDuiMen'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagServerGameRecordRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    tagServerGameRecordRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerGameRecordRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerGameRecordRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagServerGameRecordRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_tagServerGameRecordRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerGameRecordRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagServerGameRecordRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagServerGameRecordRef_bWinShunMen(lua_State* tolua_S)
{
    int argc = 0;
    tagServerGameRecordRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerGameRecordRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagServerGameRecordRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagServerGameRecordRef_bWinShunMen'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2,&arg0, "tagServerGameRecordRef:bWinShunMen");

            if (!ok) { break; }
            cobj->bWinShunMen(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            bool ret = cobj->bWinShunMen();
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagServerGameRecordRef:bWinShunMen",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagServerGameRecordRef_bWinShunMen'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagServerGameRecordRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    tagServerGameRecordRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerGameRecordRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerGameRecordRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagServerGameRecordRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_tagServerGameRecordRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerGameRecordRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagServerGameRecordRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagServerGameRecordRef_bWinHuang(lua_State* tolua_S)
{
    int argc = 0;
    tagServerGameRecordRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerGameRecordRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagServerGameRecordRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagServerGameRecordRef_bWinHuang'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2,&arg0, "tagServerGameRecordRef:bWinHuang");

            if (!ok) { break; }
            cobj->bWinHuang(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            bool ret = cobj->bWinHuang();
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagServerGameRecordRef:bWinHuang",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagServerGameRecordRef_bWinHuang'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagServerGameRecordRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    tagServerGameRecordRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerGameRecordRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagServerGameRecordRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagServerGameRecordRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_tagServerGameRecordRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagServerGameRecordRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagServerGameRecordRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagServerGameRecordRef_bWinDaoMen(lua_State* tolua_S)
{
    int argc = 0;
    tagServerGameRecordRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagServerGameRecordRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagServerGameRecordRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagServerGameRecordRef_bWinDaoMen'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2,&arg0, "tagServerGameRecordRef:bWinDaoMen");

            if (!ok) { break; }
            cobj->bWinDaoMen(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            bool ret = cobj->bWinDaoMen();
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagServerGameRecordRef:bWinDaoMen",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagServerGameRecordRef_bWinDaoMen'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagServerGameRecordRef_createWithDataArray(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"tagServerGameRecordRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        CNotify* arg0;
        int arg1;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "tagServerGameRecordRef:createWithDataArray");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_tagServerGameRecordRef_createWithDataArray'", nullptr);
            return 0;
        }
        tagServerGameRecordRef* ret = tagServerGameRecordRef::createWithDataArray(arg0, arg1);
        object_to_luaval<tagServerGameRecordRef>(tolua_S, "tagServerGameRecordRef",(tagServerGameRecordRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "tagServerGameRecordRef:createWithDataArray",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagServerGameRecordRef_createWithDataArray'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_game_tagServerGameRecordRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"tagServerGameRecordRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_tagServerGameRecordRef_createWithNotify'", nullptr);
            return 0;
        }
        tagServerGameRecordRef* ret = tagServerGameRecordRef::createWithNotify();
        object_to_luaval<tagServerGameRecordRef>(tolua_S, "tagServerGameRecordRef",(tagServerGameRecordRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_tagServerGameRecordRef_createWithNotify'", nullptr);
            return 0;
        }
        tagServerGameRecordRef* ret = tagServerGameRecordRef::createWithNotify(arg0);
        object_to_luaval<tagServerGameRecordRef>(tolua_S, "tagServerGameRecordRef",(tagServerGameRecordRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "tagServerGameRecordRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagServerGameRecordRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_tagServerGameRecordRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagServerGameRecordRef)");
    return 0;
}

int lua_register_jt_game_tagServerGameRecordRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagServerGameRecordRef");
    tolua_cclass(tolua_S,"tagServerGameRecordRef","tagServerGameRecordRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"tagServerGameRecordRef");
        tolua_function(tolua_S,"bWinDuiMen",lua_jt_game_tagServerGameRecordRef_bWinDuiMen);
        tolua_function(tolua_S,"setStruct",lua_jt_game_tagServerGameRecordRef_setStruct);
        tolua_function(tolua_S,"bWinShunMen",lua_jt_game_tagServerGameRecordRef_bWinShunMen);
        tolua_function(tolua_S,"getSize",lua_jt_game_tagServerGameRecordRef_getSize);
        tolua_function(tolua_S,"bWinHuang",lua_jt_game_tagServerGameRecordRef_bWinHuang);
        tolua_function(tolua_S,"getData",lua_jt_game_tagServerGameRecordRef_getData);
        tolua_function(tolua_S,"bWinDaoMen",lua_jt_game_tagServerGameRecordRef_bWinDaoMen);
        tolua_function(tolua_S,"createWithDataArray", lua_jt_game_tagServerGameRecordRef_createWithDataArray);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_tagServerGameRecordRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagServerGameRecordRef).name();
    g_luaType[typeName] = "tagServerGameRecordRef";
    g_typeCast["tagServerGameRecordRef"] = "tagServerGameRecordRef";
    return 1;
}

int lua_jt_game_CMD_S_HunPlaceJettonFailRef_lJettonArea(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunPlaceJettonFailRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunPlaceJettonFailRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunPlaceJettonFailRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunPlaceJettonFailRef_lJettonArea'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_S_HunPlaceJettonFailRef:lJettonArea");

            if (!ok) { break; }
            cobj->lJettonArea(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->lJettonArea();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunPlaceJettonFailRef:lJettonArea",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunPlaceJettonFailRef_lJettonArea'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunPlaceJettonFailRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunPlaceJettonFailRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunPlaceJettonFailRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunPlaceJettonFailRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunPlaceJettonFailRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunPlaceJettonFailRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunPlaceJettonFailRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunPlaceJettonFailRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunPlaceJettonFailRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunPlaceJettonFailRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunPlaceJettonFailRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunPlaceJettonFailRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunPlaceJettonFailRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunPlaceJettonFailRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunPlaceJettonFailRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunPlaceJettonFailRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunPlaceJettonFailRef_lPlaceScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunPlaceJettonFailRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunPlaceJettonFailRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunPlaceJettonFailRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunPlaceJettonFailRef_lPlaceScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunPlaceJettonFailRef:lPlaceScore");

            if (!ok) { break; }
            cobj->lPlaceScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lPlaceScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunPlaceJettonFailRef:lPlaceScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunPlaceJettonFailRef_lPlaceScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunPlaceJettonFailRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunPlaceJettonFailRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunPlaceJettonFailRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunPlaceJettonFailRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunPlaceJettonFailRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunPlaceJettonFailRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunPlaceJettonFailRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunPlaceJettonFailRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunPlaceJettonFailRef_wPlaceUser(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunPlaceJettonFailRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunPlaceJettonFailRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunPlaceJettonFailRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunPlaceJettonFailRef_wPlaceUser'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_HunPlaceJettonFailRef:wPlaceUser");

            if (!ok) { break; }
            cobj->wPlaceUser(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wPlaceUser();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunPlaceJettonFailRef:wPlaceUser",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunPlaceJettonFailRef_wPlaceUser'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunPlaceJettonFailRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_S_HunPlaceJettonFailRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunPlaceJettonFailRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunPlaceJettonFailRef* ret = CMD_S_HunPlaceJettonFailRef::createWithNotify();
        object_to_luaval<CMD_S_HunPlaceJettonFailRef>(tolua_S, "CMD_S_HunPlaceJettonFailRef",(CMD_S_HunPlaceJettonFailRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunPlaceJettonFailRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunPlaceJettonFailRef* ret = CMD_S_HunPlaceJettonFailRef::createWithNotify(arg0);
        object_to_luaval<CMD_S_HunPlaceJettonFailRef>(tolua_S, "CMD_S_HunPlaceJettonFailRef",(CMD_S_HunPlaceJettonFailRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_S_HunPlaceJettonFailRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunPlaceJettonFailRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_S_HunPlaceJettonFailRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_S_HunPlaceJettonFailRef)");
    return 0;
}

int lua_register_jt_game_CMD_S_HunPlaceJettonFailRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_S_HunPlaceJettonFailRef");
    tolua_cclass(tolua_S,"CMD_S_HunPlaceJettonFailRef","CMD_S_HunPlaceJettonFailRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_S_HunPlaceJettonFailRef");
        tolua_function(tolua_S,"lJettonArea",lua_jt_game_CMD_S_HunPlaceJettonFailRef_lJettonArea);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_S_HunPlaceJettonFailRef_setStruct);
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_S_HunPlaceJettonFailRef_getSize);
        tolua_function(tolua_S,"lPlaceScore",lua_jt_game_CMD_S_HunPlaceJettonFailRef_lPlaceScore);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_S_HunPlaceJettonFailRef_getData);
        tolua_function(tolua_S,"wPlaceUser",lua_jt_game_CMD_S_HunPlaceJettonFailRef_wPlaceUser);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_S_HunPlaceJettonFailRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_S_HunPlaceJettonFailRef).name();
    g_luaType[typeName] = "CMD_S_HunPlaceJettonFailRef";
    g_typeCast["CMD_S_HunPlaceJettonFailRef"] = "CMD_S_HunPlaceJettonFailRef";
    return 1;
}

int lua_jt_game_CMD_S_HunChangeUserScoreRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunChangeUserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunChangeUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunChangeUserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunChangeUserScoreRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunChangeUserScoreRef_lScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunChangeUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunChangeUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunChangeUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_lScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "CMD_S_HunChangeUserScoreRef:lScore");

            if (!ok) { break; }
            cobj->lScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            double ret = cobj->lScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunChangeUserScoreRef:lScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_lScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunChangeUserScoreRef_lCurrentBankerScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunChangeUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunChangeUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunChangeUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_lCurrentBankerScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "CMD_S_HunChangeUserScoreRef:lCurrentBankerScore");

            if (!ok) { break; }
            cobj->lCurrentBankerScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            double ret = cobj->lCurrentBankerScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunChangeUserScoreRef:lCurrentBankerScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_lCurrentBankerScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunChangeUserScoreRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunChangeUserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunChangeUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunChangeUserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunChangeUserScoreRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunChangeUserScoreRef_wChairID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunChangeUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunChangeUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunChangeUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_wChairID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_HunChangeUserScoreRef:wChairID");

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
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunChangeUserScoreRef:wChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_wChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunChangeUserScoreRef_wCurrentBankerChairID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunChangeUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunChangeUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunChangeUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_wCurrentBankerChairID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_HunChangeUserScoreRef:wCurrentBankerChairID");

            if (!ok) { break; }
            cobj->wCurrentBankerChairID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wCurrentBankerChairID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunChangeUserScoreRef:wCurrentBankerChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_wCurrentBankerChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunChangeUserScoreRef_cbBankerTime(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunChangeUserScoreRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunChangeUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunChangeUserScoreRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_cbBankerTime'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_S_HunChangeUserScoreRef:cbBankerTime");

            if (!ok) { break; }
            cobj->cbBankerTime(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbBankerTime();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunChangeUserScoreRef:cbBankerTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_cbBankerTime'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunChangeUserScoreRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunChangeUserScoreRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunChangeUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunChangeUserScoreRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunChangeUserScoreRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunChangeUserScoreRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_S_HunChangeUserScoreRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunChangeUserScoreRef* ret = CMD_S_HunChangeUserScoreRef::createWithNotify();
        object_to_luaval<CMD_S_HunChangeUserScoreRef>(tolua_S, "CMD_S_HunChangeUserScoreRef",(CMD_S_HunChangeUserScoreRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunChangeUserScoreRef* ret = CMD_S_HunChangeUserScoreRef::createWithNotify(arg0);
        object_to_luaval<CMD_S_HunChangeUserScoreRef>(tolua_S, "CMD_S_HunChangeUserScoreRef",(CMD_S_HunChangeUserScoreRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_S_HunChangeUserScoreRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunChangeUserScoreRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_S_HunChangeUserScoreRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_S_HunChangeUserScoreRef)");
    return 0;
}

int lua_register_jt_game_CMD_S_HunChangeUserScoreRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_S_HunChangeUserScoreRef");
    tolua_cclass(tolua_S,"CMD_S_HunChangeUserScoreRef","CMD_S_HunChangeUserScoreRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_S_HunChangeUserScoreRef");
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_S_HunChangeUserScoreRef_setStruct);
        tolua_function(tolua_S,"lScore",lua_jt_game_CMD_S_HunChangeUserScoreRef_lScore);
        tolua_function(tolua_S,"lCurrentBankerScore",lua_jt_game_CMD_S_HunChangeUserScoreRef_lCurrentBankerScore);
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_S_HunChangeUserScoreRef_getSize);
        tolua_function(tolua_S,"wChairID",lua_jt_game_CMD_S_HunChangeUserScoreRef_wChairID);
        tolua_function(tolua_S,"wCurrentBankerChairID",lua_jt_game_CMD_S_HunChangeUserScoreRef_wCurrentBankerChairID);
        tolua_function(tolua_S,"cbBankerTime",lua_jt_game_CMD_S_HunChangeUserScoreRef_cbBankerTime);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_S_HunChangeUserScoreRef_getData);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_S_HunChangeUserScoreRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_S_HunChangeUserScoreRef).name();
    g_luaType[typeName] = "CMD_S_HunChangeUserScoreRef";
    g_typeCast["CMD_S_HunChangeUserScoreRef"] = "CMD_S_HunChangeUserScoreRef";
    return 1;
}

int lua_jt_game_CMD_S_HunApplyBankerRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunApplyBankerRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunApplyBankerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunApplyBankerRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunApplyBankerRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunApplyBankerRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunApplyBankerRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunApplyBankerRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunApplyBankerRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunApplyBankerRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunApplyBankerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunApplyBankerRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunApplyBankerRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunApplyBankerRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunApplyBankerRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunApplyBankerRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunApplyBankerRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunApplyBankerRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunApplyBankerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunApplyBankerRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunApplyBankerRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunApplyBankerRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunApplyBankerRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunApplyBankerRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunApplyBankerRef_wApplyUser(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunApplyBankerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunApplyBankerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunApplyBankerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunApplyBankerRef_wApplyUser'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_HunApplyBankerRef:wApplyUser");

            if (!ok) { break; }
            cobj->wApplyUser(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wApplyUser();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunApplyBankerRef:wApplyUser",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunApplyBankerRef_wApplyUser'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunApplyBankerRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_S_HunApplyBankerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunApplyBankerRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunApplyBankerRef* ret = CMD_S_HunApplyBankerRef::createWithNotify();
        object_to_luaval<CMD_S_HunApplyBankerRef>(tolua_S, "CMD_S_HunApplyBankerRef",(CMD_S_HunApplyBankerRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunApplyBankerRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunApplyBankerRef* ret = CMD_S_HunApplyBankerRef::createWithNotify(arg0);
        object_to_luaval<CMD_S_HunApplyBankerRef>(tolua_S, "CMD_S_HunApplyBankerRef",(CMD_S_HunApplyBankerRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_S_HunApplyBankerRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunApplyBankerRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_S_HunApplyBankerRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_S_HunApplyBankerRef)");
    return 0;
}

int lua_register_jt_game_CMD_S_HunApplyBankerRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_S_HunApplyBankerRef");
    tolua_cclass(tolua_S,"CMD_S_HunApplyBankerRef","CMD_S_HunApplyBankerRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_S_HunApplyBankerRef");
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_S_HunApplyBankerRef_getSize);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_S_HunApplyBankerRef_setStruct);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_S_HunApplyBankerRef_getData);
        tolua_function(tolua_S,"wApplyUser",lua_jt_game_CMD_S_HunApplyBankerRef_wApplyUser);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_S_HunApplyBankerRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_S_HunApplyBankerRef).name();
    g_luaType[typeName] = "CMD_S_HunApplyBankerRef";
    g_typeCast["CMD_S_HunApplyBankerRef"] = "CMD_S_HunApplyBankerRef";
    return 1;
}

int lua_jt_game_CMD_S_HunCancelBankerRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunCancelBankerRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunCancelBankerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunCancelBankerRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunCancelBankerRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunCancelBankerRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunCancelBankerRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunCancelBankerRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunCancelBankerRef_szCancelUser(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunCancelBankerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunCancelBankerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunCancelBankerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunCancelBankerRef_szCancelUser'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_S_HunCancelBankerRef:szCancelUser"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szCancelUser(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szCancelUser();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunCancelBankerRef:szCancelUser",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunCancelBankerRef_szCancelUser'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunCancelBankerRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunCancelBankerRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunCancelBankerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunCancelBankerRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunCancelBankerRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunCancelBankerRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunCancelBankerRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunCancelBankerRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunCancelBankerRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunCancelBankerRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunCancelBankerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunCancelBankerRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunCancelBankerRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunCancelBankerRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunCancelBankerRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunCancelBankerRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunCancelBankerRef_wChairID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunCancelBankerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunCancelBankerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunCancelBankerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunCancelBankerRef_wChairID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_HunCancelBankerRef:wChairID");

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
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunCancelBankerRef:wChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunCancelBankerRef_wChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunCancelBankerRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_S_HunCancelBankerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunCancelBankerRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunCancelBankerRef* ret = CMD_S_HunCancelBankerRef::createWithNotify();
        object_to_luaval<CMD_S_HunCancelBankerRef>(tolua_S, "CMD_S_HunCancelBankerRef",(CMD_S_HunCancelBankerRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunCancelBankerRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunCancelBankerRef* ret = CMD_S_HunCancelBankerRef::createWithNotify(arg0);
        object_to_luaval<CMD_S_HunCancelBankerRef>(tolua_S, "CMD_S_HunCancelBankerRef",(CMD_S_HunCancelBankerRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_S_HunCancelBankerRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunCancelBankerRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_S_HunCancelBankerRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_S_HunCancelBankerRef)");
    return 0;
}

int lua_register_jt_game_CMD_S_HunCancelBankerRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_S_HunCancelBankerRef");
    tolua_cclass(tolua_S,"CMD_S_HunCancelBankerRef","CMD_S_HunCancelBankerRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_S_HunCancelBankerRef");
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_S_HunCancelBankerRef_getSize);
        tolua_function(tolua_S,"szCancelUser",lua_jt_game_CMD_S_HunCancelBankerRef_szCancelUser);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_S_HunCancelBankerRef_setStruct);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_S_HunCancelBankerRef_getData);
        tolua_function(tolua_S,"wChairID",lua_jt_game_CMD_S_HunCancelBankerRef_wChairID);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_S_HunCancelBankerRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_S_HunCancelBankerRef).name();
    g_luaType[typeName] = "CMD_S_HunCancelBankerRef";
    g_typeCast["CMD_S_HunCancelBankerRef"] = "CMD_S_HunCancelBankerRef";
    return 1;
}

int lua_jt_game_CMD_S_HunChangeBankerRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunChangeBankerRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunChangeBankerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunChangeBankerRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunChangeBankerRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunChangeBankerRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunChangeBankerRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunChangeBankerRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunChangeBankerRef_lBankerScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunChangeBankerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunChangeBankerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunChangeBankerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunChangeBankerRef_lBankerScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunChangeBankerRef:lBankerScore");

            if (!ok) { break; }
            cobj->lBankerScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lBankerScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunChangeBankerRef:lBankerScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunChangeBankerRef_lBankerScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunChangeBankerRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunChangeBankerRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunChangeBankerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunChangeBankerRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunChangeBankerRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunChangeBankerRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunChangeBankerRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunChangeBankerRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunChangeBankerRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunChangeBankerRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunChangeBankerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunChangeBankerRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunChangeBankerRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunChangeBankerRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunChangeBankerRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunChangeBankerRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunChangeBankerRef_wBankerUser(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunChangeBankerRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunChangeBankerRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunChangeBankerRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunChangeBankerRef_wBankerUser'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_HunChangeBankerRef:wBankerUser");

            if (!ok) { break; }
            cobj->wBankerUser(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wBankerUser();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunChangeBankerRef:wBankerUser",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunChangeBankerRef_wBankerUser'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunChangeBankerRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_S_HunChangeBankerRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunChangeBankerRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunChangeBankerRef* ret = CMD_S_HunChangeBankerRef::createWithNotify();
        object_to_luaval<CMD_S_HunChangeBankerRef>(tolua_S, "CMD_S_HunChangeBankerRef",(CMD_S_HunChangeBankerRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunChangeBankerRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunChangeBankerRef* ret = CMD_S_HunChangeBankerRef::createWithNotify(arg0);
        object_to_luaval<CMD_S_HunChangeBankerRef>(tolua_S, "CMD_S_HunChangeBankerRef",(CMD_S_HunChangeBankerRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_S_HunChangeBankerRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunChangeBankerRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_S_HunChangeBankerRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_S_HunChangeBankerRef)");
    return 0;
}

int lua_register_jt_game_CMD_S_HunChangeBankerRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_S_HunChangeBankerRef");
    tolua_cclass(tolua_S,"CMD_S_HunChangeBankerRef","CMD_S_HunChangeBankerRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_S_HunChangeBankerRef");
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_S_HunChangeBankerRef_getSize);
        tolua_function(tolua_S,"lBankerScore",lua_jt_game_CMD_S_HunChangeBankerRef_lBankerScore);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_S_HunChangeBankerRef_setStruct);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_S_HunChangeBankerRef_getData);
        tolua_function(tolua_S,"wBankerUser",lua_jt_game_CMD_S_HunChangeBankerRef_wBankerUser);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_S_HunChangeBankerRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_S_HunChangeBankerRef).name();
    g_luaType[typeName] = "CMD_S_HunChangeBankerRef";
    g_typeCast["CMD_S_HunChangeBankerRef"] = "CMD_S_HunChangeBankerRef";
    return 1;
}

int lua_jt_game_CMD_S_HunStatusFreeRef_lBankerScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusFreeRef_lBankerScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunStatusFreeRef:lBankerScore");

            if (!ok) { break; }
            cobj->lBankerScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lBankerScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusFreeRef:lBankerScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusFreeRef_lBankerScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusFreeRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusFreeRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunStatusFreeRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusFreeRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunStatusFreeRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunStatusFreeRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusFreeRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusFreeRef_szGameRoomName(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusFreeRef_szGameRoomName'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_S_HunStatusFreeRef:szGameRoomName"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szGameRoomName(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szGameRoomName();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusFreeRef:szGameRoomName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusFreeRef_szGameRoomName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusFreeRef_lBankerWinScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusFreeRef_lBankerWinScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunStatusFreeRef:lBankerWinScore");

            if (!ok) { break; }
            cobj->lBankerWinScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lBankerWinScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusFreeRef:lBankerWinScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusFreeRef_lBankerWinScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusFreeRef_bEnableSysBanker(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusFreeRef_bEnableSysBanker'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CMD_S_HunStatusFreeRef:bEnableSysBanker");

            if (!ok) { break; }
            cobj->bEnableSysBanker(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            bool ret = cobj->bEnableSysBanker();
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusFreeRef:bEnableSysBanker",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusFreeRef_bEnableSysBanker'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusFreeRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusFreeRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunStatusFreeRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusFreeRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunStatusFreeRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunStatusFreeRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusFreeRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusFreeRef_lSitMinSocre(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusFreeRef_lSitMinSocre'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunStatusFreeRef:lSitMinSocre");

            if (!ok) { break; }
            cobj->lSitMinSocre(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lSitMinSocre();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusFreeRef:lSitMinSocre",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusFreeRef_lSitMinSocre'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusFreeRef_lApplyBankerCondition(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusFreeRef_lApplyBankerCondition'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunStatusFreeRef:lApplyBankerCondition");

            if (!ok) { break; }
            cobj->lApplyBankerCondition(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lApplyBankerCondition();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusFreeRef:lApplyBankerCondition",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusFreeRef_lApplyBankerCondition'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusFreeRef_lAreaLimitScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusFreeRef_lAreaLimitScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunStatusFreeRef:lAreaLimitScore");

            if (!ok) { break; }
            cobj->lAreaLimitScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lAreaLimitScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusFreeRef:lAreaLimitScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusFreeRef_lAreaLimitScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusFreeRef_cbTimeLeave(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusFreeRef_cbTimeLeave'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_S_HunStatusFreeRef:cbTimeLeave");

            if (!ok) { break; }
            cobj->cbTimeLeave(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbTimeLeave();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusFreeRef:cbTimeLeave",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusFreeRef_cbTimeLeave'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusFreeRef_cbBankerTime(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusFreeRef_cbBankerTime'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_HunStatusFreeRef:cbBankerTime");

            if (!ok) { break; }
            cobj->cbBankerTime(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->cbBankerTime();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusFreeRef:cbBankerTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusFreeRef_cbBankerTime'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusFreeRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusFreeRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunStatusFreeRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusFreeRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunStatusFreeRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunStatusFreeRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusFreeRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusFreeRef_lUserMaxScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusFreeRef_lUserMaxScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunStatusFreeRef:lUserMaxScore");

            if (!ok) { break; }
            cobj->lUserMaxScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lUserMaxScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusFreeRef:lUserMaxScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusFreeRef_lUserMaxScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusFreeRef_wBankerUser(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusFreeRef_wBankerUser'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_HunStatusFreeRef:wBankerUser");

            if (!ok) { break; }
            cobj->wBankerUser(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wBankerUser();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusFreeRef:wBankerUser",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusFreeRef_wBankerUser'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusFreeRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_S_HunStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunStatusFreeRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunStatusFreeRef* ret = CMD_S_HunStatusFreeRef::createWithNotify();
        object_to_luaval<CMD_S_HunStatusFreeRef>(tolua_S, "CMD_S_HunStatusFreeRef",(CMD_S_HunStatusFreeRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunStatusFreeRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunStatusFreeRef* ret = CMD_S_HunStatusFreeRef::createWithNotify(arg0);
        object_to_luaval<CMD_S_HunStatusFreeRef>(tolua_S, "CMD_S_HunStatusFreeRef",(CMD_S_HunStatusFreeRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_S_HunStatusFreeRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusFreeRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_S_HunStatusFreeRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_S_HunStatusFreeRef)");
    return 0;
}

int lua_register_jt_game_CMD_S_HunStatusFreeRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_S_HunStatusFreeRef");
    tolua_cclass(tolua_S,"CMD_S_HunStatusFreeRef","CMD_S_HunStatusFreeRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_S_HunStatusFreeRef");
        tolua_function(tolua_S,"lBankerScore",lua_jt_game_CMD_S_HunStatusFreeRef_lBankerScore);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_S_HunStatusFreeRef_setStruct);
        tolua_function(tolua_S,"szGameRoomName",lua_jt_game_CMD_S_HunStatusFreeRef_szGameRoomName);
        tolua_function(tolua_S,"lBankerWinScore",lua_jt_game_CMD_S_HunStatusFreeRef_lBankerWinScore);
        tolua_function(tolua_S,"bEnableSysBanker",lua_jt_game_CMD_S_HunStatusFreeRef_bEnableSysBanker);
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_S_HunStatusFreeRef_getSize);
        tolua_function(tolua_S,"lSitMinSocre",lua_jt_game_CMD_S_HunStatusFreeRef_lSitMinSocre);
        tolua_function(tolua_S,"lApplyBankerCondition",lua_jt_game_CMD_S_HunStatusFreeRef_lApplyBankerCondition);
        tolua_function(tolua_S,"lAreaLimitScore",lua_jt_game_CMD_S_HunStatusFreeRef_lAreaLimitScore);
        tolua_function(tolua_S,"cbTimeLeave",lua_jt_game_CMD_S_HunStatusFreeRef_cbTimeLeave);
        tolua_function(tolua_S,"cbBankerTime",lua_jt_game_CMD_S_HunStatusFreeRef_cbBankerTime);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_S_HunStatusFreeRef_getData);
        tolua_function(tolua_S,"lUserMaxScore",lua_jt_game_CMD_S_HunStatusFreeRef_lUserMaxScore);
        tolua_function(tolua_S,"wBankerUser",lua_jt_game_CMD_S_HunStatusFreeRef_wBankerUser);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_S_HunStatusFreeRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_S_HunStatusFreeRef).name();
    g_luaType[typeName] = "CMD_S_HunStatusFreeRef";
    g_typeCast["CMD_S_HunStatusFreeRef"] = "CMD_S_HunStatusFreeRef";
    return 1;
}

int lua_jt_game_CMD_S_HunStatusPlayRef_lEndUserScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lEndUserScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunStatusPlayRef:lEndUserScore");

            if (!ok) { break; }
            cobj->lEndUserScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lEndUserScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusPlayRef:lEndUserScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lEndUserScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_cbGameStatus(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_cbGameStatus'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_S_HunStatusPlayRef:cbGameStatus");

            if (!ok) { break; }
            cobj->cbGameStatus(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbGameStatus();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusPlayRef:cbGameStatus",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_cbGameStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunStatusPlayRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunStatusPlayRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_lBankerWinScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lBankerWinScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunStatusPlayRef:lBankerWinScore");

            if (!ok) { break; }
            cobj->lBankerWinScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lBankerWinScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusPlayRef:lBankerWinScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lBankerWinScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunStatusPlayRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunStatusPlayRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_lEndRevenue(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lEndRevenue'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunStatusPlayRef:lEndRevenue");

            if (!ok) { break; }
            cobj->lEndRevenue(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lEndRevenue();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusPlayRef:lEndRevenue",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lEndRevenue'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_lEndBankerScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lEndBankerScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunStatusPlayRef:lEndBankerScore");

            if (!ok) { break; }
            cobj->lEndBankerScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lEndBankerScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusPlayRef:lEndBankerScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lEndBankerScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_lSitMinSocre(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lSitMinSocre'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunStatusPlayRef:lSitMinSocre");

            if (!ok) { break; }
            cobj->lSitMinSocre(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lSitMinSocre();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusPlayRef:lSitMinSocre",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lSitMinSocre'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_lBankerScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lBankerScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunStatusPlayRef:lBankerScore");

            if (!ok) { break; }
            cobj->lBankerScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lBankerScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusPlayRef:lBankerScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lBankerScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_cbTableCardArray(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_cbTableCardArray'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_S_HunStatusPlayRef:cbTableCardArray");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMD_S_HunStatusPlayRef:cbTableCardArray");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunStatusPlayRef_cbTableCardArray'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->cbTableCardArray(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunStatusPlayRef:cbTableCardArray",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_cbTableCardArray'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_szGameRoomName(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_szGameRoomName'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_S_HunStatusPlayRef:szGameRoomName"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szGameRoomName(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szGameRoomName();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusPlayRef:szGameRoomName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_szGameRoomName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_bEnableSysBanker(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_bEnableSysBanker'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CMD_S_HunStatusPlayRef:bEnableSysBanker");

            if (!ok) { break; }
            cobj->bEnableSysBanker(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            bool ret = cobj->bEnableSysBanker();
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusPlayRef:bEnableSysBanker",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_bEnableSysBanker'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunStatusPlayRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunStatusPlayRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_wBankerUser(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_wBankerUser'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_HunStatusPlayRef:wBankerUser");

            if (!ok) { break; }
            cobj->wBankerUser(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wBankerUser();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusPlayRef:wBankerUser",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_wBankerUser'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_lEndUserReturnScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lEndUserReturnScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunStatusPlayRef:lEndUserReturnScore");

            if (!ok) { break; }
            cobj->lEndUserReturnScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lEndUserReturnScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusPlayRef:lEndUserReturnScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lEndUserReturnScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_lUserJettonScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lUserJettonScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_S_HunStatusPlayRef:lUserJettonScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lUserJettonScore'", nullptr);
            return 0;
        }
        long long ret = cobj->lUserJettonScore(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunStatusPlayRef:lUserJettonScore",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lUserJettonScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_lApplyBankerCondition(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lApplyBankerCondition'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunStatusPlayRef:lApplyBankerCondition");

            if (!ok) { break; }
            cobj->lApplyBankerCondition(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lApplyBankerCondition();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusPlayRef:lApplyBankerCondition",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lApplyBankerCondition'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_lAllJettonScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lAllJettonScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_S_HunStatusPlayRef:lAllJettonScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lAllJettonScore'", nullptr);
            return 0;
        }
        long long ret = cobj->lAllJettonScore(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunStatusPlayRef:lAllJettonScore",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lAllJettonScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_lAreaLimitScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lAreaLimitScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunStatusPlayRef:lAreaLimitScore");

            if (!ok) { break; }
            cobj->lAreaLimitScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lAreaLimitScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusPlayRef:lAreaLimitScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lAreaLimitScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_cbTimeLeave(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_cbTimeLeave'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_S_HunStatusPlayRef:cbTimeLeave");

            if (!ok) { break; }
            cobj->cbTimeLeave(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbTimeLeave();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusPlayRef:cbTimeLeave",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_cbTimeLeave'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_cbBankerTime(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_cbBankerTime'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_HunStatusPlayRef:cbBankerTime");

            if (!ok) { break; }
            cobj->cbBankerTime(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->cbBankerTime();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusPlayRef:cbBankerTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_cbBankerTime'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_lUserMaxScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lUserMaxScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunStatusPlayRef:lUserMaxScore");

            if (!ok) { break; }
            cobj->lUserMaxScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lUserMaxScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunStatusPlayRef:lUserMaxScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_lUserMaxScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunStatusPlayRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_S_HunStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunStatusPlayRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunStatusPlayRef* ret = CMD_S_HunStatusPlayRef::createWithNotify();
        object_to_luaval<CMD_S_HunStatusPlayRef>(tolua_S, "CMD_S_HunStatusPlayRef",(CMD_S_HunStatusPlayRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunStatusPlayRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunStatusPlayRef* ret = CMD_S_HunStatusPlayRef::createWithNotify(arg0);
        object_to_luaval<CMD_S_HunStatusPlayRef>(tolua_S, "CMD_S_HunStatusPlayRef",(CMD_S_HunStatusPlayRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_S_HunStatusPlayRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunStatusPlayRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_S_HunStatusPlayRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_S_HunStatusPlayRef)");
    return 0;
}

int lua_register_jt_game_CMD_S_HunStatusPlayRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_S_HunStatusPlayRef");
    tolua_cclass(tolua_S,"CMD_S_HunStatusPlayRef","CMD_S_HunStatusPlayRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_S_HunStatusPlayRef");
        tolua_function(tolua_S,"lEndUserScore",lua_jt_game_CMD_S_HunStatusPlayRef_lEndUserScore);
        tolua_function(tolua_S,"cbGameStatus",lua_jt_game_CMD_S_HunStatusPlayRef_cbGameStatus);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_S_HunStatusPlayRef_setStruct);
        tolua_function(tolua_S,"lBankerWinScore",lua_jt_game_CMD_S_HunStatusPlayRef_lBankerWinScore);
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_S_HunStatusPlayRef_getSize);
        tolua_function(tolua_S,"lEndRevenue",lua_jt_game_CMD_S_HunStatusPlayRef_lEndRevenue);
        tolua_function(tolua_S,"lEndBankerScore",lua_jt_game_CMD_S_HunStatusPlayRef_lEndBankerScore);
        tolua_function(tolua_S,"lSitMinSocre",lua_jt_game_CMD_S_HunStatusPlayRef_lSitMinSocre);
        tolua_function(tolua_S,"lBankerScore",lua_jt_game_CMD_S_HunStatusPlayRef_lBankerScore);
        tolua_function(tolua_S,"cbTableCardArray",lua_jt_game_CMD_S_HunStatusPlayRef_cbTableCardArray);
        tolua_function(tolua_S,"szGameRoomName",lua_jt_game_CMD_S_HunStatusPlayRef_szGameRoomName);
        tolua_function(tolua_S,"bEnableSysBanker",lua_jt_game_CMD_S_HunStatusPlayRef_bEnableSysBanker);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_S_HunStatusPlayRef_getData);
        tolua_function(tolua_S,"wBankerUser",lua_jt_game_CMD_S_HunStatusPlayRef_wBankerUser);
        tolua_function(tolua_S,"lEndUserReturnScore",lua_jt_game_CMD_S_HunStatusPlayRef_lEndUserReturnScore);
        tolua_function(tolua_S,"lUserJettonScore",lua_jt_game_CMD_S_HunStatusPlayRef_lUserJettonScore);
        tolua_function(tolua_S,"lApplyBankerCondition",lua_jt_game_CMD_S_HunStatusPlayRef_lApplyBankerCondition);
        tolua_function(tolua_S,"lAllJettonScore",lua_jt_game_CMD_S_HunStatusPlayRef_lAllJettonScore);
        tolua_function(tolua_S,"lAreaLimitScore",lua_jt_game_CMD_S_HunStatusPlayRef_lAreaLimitScore);
        tolua_function(tolua_S,"cbTimeLeave",lua_jt_game_CMD_S_HunStatusPlayRef_cbTimeLeave);
        tolua_function(tolua_S,"cbBankerTime",lua_jt_game_CMD_S_HunStatusPlayRef_cbBankerTime);
        tolua_function(tolua_S,"lUserMaxScore",lua_jt_game_CMD_S_HunStatusPlayRef_lUserMaxScore);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_S_HunStatusPlayRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_S_HunStatusPlayRef).name();
    g_luaType[typeName] = "CMD_S_HunStatusPlayRef";
    g_typeCast["CMD_S_HunStatusPlayRef"] = "CMD_S_HunStatusPlayRef";
    return 1;
}

int lua_jt_game_CMD_S_HunGameFreeRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameFreeRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunGameFreeRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameFreeRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunGameFreeRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunGameFreeRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameFreeRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameFreeRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameFreeRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunGameFreeRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameFreeRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunGameFreeRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunGameFreeRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameFreeRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameFreeRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameFreeRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunGameFreeRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameFreeRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunGameFreeRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunGameFreeRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameFreeRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameFreeRef_cbTimeLeave(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunGameFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameFreeRef_cbTimeLeave'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_S_HunGameFreeRef:cbTimeLeave");

            if (!ok) { break; }
            cobj->cbTimeLeave(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbTimeLeave();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunGameFreeRef:cbTimeLeave",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameFreeRef_cbTimeLeave'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameFreeRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_S_HunGameFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunGameFreeRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunGameFreeRef* ret = CMD_S_HunGameFreeRef::createWithNotify();
        object_to_luaval<CMD_S_HunGameFreeRef>(tolua_S, "CMD_S_HunGameFreeRef",(CMD_S_HunGameFreeRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunGameFreeRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunGameFreeRef* ret = CMD_S_HunGameFreeRef::createWithNotify(arg0);
        object_to_luaval<CMD_S_HunGameFreeRef>(tolua_S, "CMD_S_HunGameFreeRef",(CMD_S_HunGameFreeRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_S_HunGameFreeRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameFreeRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_S_HunGameFreeRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_S_HunGameFreeRef)");
    return 0;
}

int lua_register_jt_game_CMD_S_HunGameFreeRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_S_HunGameFreeRef");
    tolua_cclass(tolua_S,"CMD_S_HunGameFreeRef","CMD_S_HunGameFreeRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_S_HunGameFreeRef");
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_S_HunGameFreeRef_getSize);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_S_HunGameFreeRef_setStruct);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_S_HunGameFreeRef_getData);
        tolua_function(tolua_S,"cbTimeLeave",lua_jt_game_CMD_S_HunGameFreeRef_cbTimeLeave);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_S_HunGameFreeRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_S_HunGameFreeRef).name();
    g_luaType[typeName] = "CMD_S_HunGameFreeRef";
    g_typeCast["CMD_S_HunGameFreeRef"] = "CMD_S_HunGameFreeRef";
    return 1;
}

int lua_jt_game_CMD_S_HunGameStartRef_lBankerScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameStartRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameStartRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunGameStartRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameStartRef_lBankerScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunGameStartRef:lBankerScore");

            if (!ok) { break; }
            cobj->lBankerScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lBankerScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunGameStartRef:lBankerScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameStartRef_lBankerScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameStartRef_bContiueCard(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameStartRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameStartRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunGameStartRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameStartRef_bContiueCard'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CMD_S_HunGameStartRef:bContiueCard");

            if (!ok) { break; }
            cobj->bContiueCard(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            bool ret = cobj->bContiueCard();
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunGameStartRef:bContiueCard",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameStartRef_bContiueCard'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameStartRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameStartRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameStartRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunGameStartRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameStartRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunGameStartRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunGameStartRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameStartRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameStartRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameStartRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameStartRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunGameStartRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameStartRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunGameStartRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunGameStartRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameStartRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameStartRef_nChipRobotCount(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameStartRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameStartRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunGameStartRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameStartRef_nChipRobotCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_S_HunGameStartRef:nChipRobotCount");

            if (!ok) { break; }
            cobj->nChipRobotCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            int ret = cobj->nChipRobotCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunGameStartRef:nChipRobotCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameStartRef_nChipRobotCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameStartRef_cbTimeLeave(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameStartRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameStartRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunGameStartRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameStartRef_cbTimeLeave'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_S_HunGameStartRef:cbTimeLeave");

            if (!ok) { break; }
            cobj->cbTimeLeave(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbTimeLeave();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunGameStartRef:cbTimeLeave",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameStartRef_cbTimeLeave'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameStartRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameStartRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameStartRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunGameStartRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameStartRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunGameStartRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunGameStartRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameStartRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameStartRef_lUserMaxScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameStartRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameStartRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunGameStartRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameStartRef_lUserMaxScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunGameStartRef:lUserMaxScore");

            if (!ok) { break; }
            cobj->lUserMaxScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lUserMaxScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunGameStartRef:lUserMaxScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameStartRef_lUserMaxScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameStartRef_wBankerUser(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameStartRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameStartRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunGameStartRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameStartRef_wBankerUser'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_HunGameStartRef:wBankerUser");

            if (!ok) { break; }
            cobj->wBankerUser(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wBankerUser();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunGameStartRef:wBankerUser",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameStartRef_wBankerUser'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameStartRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_S_HunGameStartRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunGameStartRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunGameStartRef* ret = CMD_S_HunGameStartRef::createWithNotify();
        object_to_luaval<CMD_S_HunGameStartRef>(tolua_S, "CMD_S_HunGameStartRef",(CMD_S_HunGameStartRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunGameStartRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunGameStartRef* ret = CMD_S_HunGameStartRef::createWithNotify(arg0);
        object_to_luaval<CMD_S_HunGameStartRef>(tolua_S, "CMD_S_HunGameStartRef",(CMD_S_HunGameStartRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_S_HunGameStartRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameStartRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_S_HunGameStartRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_S_HunGameStartRef)");
    return 0;
}

int lua_register_jt_game_CMD_S_HunGameStartRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_S_HunGameStartRef");
    tolua_cclass(tolua_S,"CMD_S_HunGameStartRef","CMD_S_HunGameStartRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_S_HunGameStartRef");
        tolua_function(tolua_S,"lBankerScore",lua_jt_game_CMD_S_HunGameStartRef_lBankerScore);
        tolua_function(tolua_S,"bContiueCard",lua_jt_game_CMD_S_HunGameStartRef_bContiueCard);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_S_HunGameStartRef_setStruct);
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_S_HunGameStartRef_getSize);
        tolua_function(tolua_S,"nChipRobotCount",lua_jt_game_CMD_S_HunGameStartRef_nChipRobotCount);
        tolua_function(tolua_S,"cbTimeLeave",lua_jt_game_CMD_S_HunGameStartRef_cbTimeLeave);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_S_HunGameStartRef_getData);
        tolua_function(tolua_S,"lUserMaxScore",lua_jt_game_CMD_S_HunGameStartRef_lUserMaxScore);
        tolua_function(tolua_S,"wBankerUser",lua_jt_game_CMD_S_HunGameStartRef_wBankerUser);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_S_HunGameStartRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_S_HunGameStartRef).name();
    g_luaType[typeName] = "CMD_S_HunGameStartRef";
    g_typeCast["CMD_S_HunGameStartRef"] = "CMD_S_HunGameStartRef";
    return 1;
}

int lua_jt_game_CMD_S_HunPlaceJettonRef_bIsAndroid(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunPlaceJettonRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunPlaceJettonRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunPlaceJettonRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_bIsAndroid'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CMD_S_HunPlaceJettonRef:bIsAndroid");

            if (!ok) { break; }
            cobj->bIsAndroid(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            bool ret = cobj->bIsAndroid();
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunPlaceJettonRef:bIsAndroid",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_bIsAndroid'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunPlaceJettonRef_lJettonScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunPlaceJettonRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunPlaceJettonRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunPlaceJettonRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_lJettonScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunPlaceJettonRef:lJettonScore");

            if (!ok) { break; }
            cobj->lJettonScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lJettonScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunPlaceJettonRef:lJettonScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_lJettonScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunPlaceJettonRef_cbJettonArea(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunPlaceJettonRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunPlaceJettonRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunPlaceJettonRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_cbJettonArea'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_S_HunPlaceJettonRef:cbJettonArea");

            if (!ok) { break; }
            cobj->cbJettonArea(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbJettonArea();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunPlaceJettonRef:cbJettonArea",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_cbJettonArea'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunPlaceJettonRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunPlaceJettonRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunPlaceJettonRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunPlaceJettonRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunPlaceJettonRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunPlaceJettonRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunPlaceJettonRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunPlaceJettonRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunPlaceJettonRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunPlaceJettonRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunPlaceJettonRef_wChairID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunPlaceJettonRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunPlaceJettonRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunPlaceJettonRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_wChairID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_HunPlaceJettonRef:wChairID");

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
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunPlaceJettonRef:wChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_wChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunPlaceJettonRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunPlaceJettonRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunPlaceJettonRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunPlaceJettonRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunPlaceJettonRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunPlaceJettonRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_S_HunPlaceJettonRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunPlaceJettonRef* ret = CMD_S_HunPlaceJettonRef::createWithNotify();
        object_to_luaval<CMD_S_HunPlaceJettonRef>(tolua_S, "CMD_S_HunPlaceJettonRef",(CMD_S_HunPlaceJettonRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunPlaceJettonRef* ret = CMD_S_HunPlaceJettonRef::createWithNotify(arg0);
        object_to_luaval<CMD_S_HunPlaceJettonRef>(tolua_S, "CMD_S_HunPlaceJettonRef",(CMD_S_HunPlaceJettonRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_S_HunPlaceJettonRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunPlaceJettonRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_S_HunPlaceJettonRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_S_HunPlaceJettonRef)");
    return 0;
}

int lua_register_jt_game_CMD_S_HunPlaceJettonRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_S_HunPlaceJettonRef");
    tolua_cclass(tolua_S,"CMD_S_HunPlaceJettonRef","CMD_S_HunPlaceJettonRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_S_HunPlaceJettonRef");
        tolua_function(tolua_S,"bIsAndroid",lua_jt_game_CMD_S_HunPlaceJettonRef_bIsAndroid);
        tolua_function(tolua_S,"lJettonScore",lua_jt_game_CMD_S_HunPlaceJettonRef_lJettonScore);
        tolua_function(tolua_S,"cbJettonArea",lua_jt_game_CMD_S_HunPlaceJettonRef_cbJettonArea);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_S_HunPlaceJettonRef_setStruct);
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_S_HunPlaceJettonRef_getSize);
        tolua_function(tolua_S,"wChairID",lua_jt_game_CMD_S_HunPlaceJettonRef_wChairID);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_S_HunPlaceJettonRef_getData);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_S_HunPlaceJettonRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_S_HunPlaceJettonRef).name();
    g_luaType[typeName] = "CMD_S_HunPlaceJettonRef";
    g_typeCast["CMD_S_HunPlaceJettonRef"] = "CMD_S_HunPlaceJettonRef";
    return 1;
}

int lua_jt_game_CMD_S_HunGameEndRef_lBankerScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameEndRef_lBankerScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunGameEndRef:lBankerScore");

            if (!ok) { break; }
            cobj->lBankerScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lBankerScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunGameEndRef:lBankerScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameEndRef_lBankerScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameEndRef_lRevenue(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameEndRef_lRevenue'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunGameEndRef:lRevenue");

            if (!ok) { break; }
            cobj->lRevenue(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lRevenue();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunGameEndRef:lRevenue",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameEndRef_lRevenue'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameEndRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameEndRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunGameEndRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameEndRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunGameEndRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunGameEndRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameEndRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameEndRef_cbLeftCardCount(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameEndRef_cbLeftCardCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_S_HunGameEndRef:cbLeftCardCount");

            if (!ok) { break; }
            cobj->cbLeftCardCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbLeftCardCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunGameEndRef:cbLeftCardCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameEndRef_cbLeftCardCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameEndRef_nBankerTime(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameEndRef_nBankerTime'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_S_HunGameEndRef:nBankerTime");

            if (!ok) { break; }
            cobj->nBankerTime(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            int ret = cobj->nBankerTime();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunGameEndRef:nBankerTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameEndRef_nBankerTime'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameEndRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameEndRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunGameEndRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameEndRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunGameEndRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunGameEndRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameEndRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameEndRef_lUserScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameEndRef_lUserScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunGameEndRef:lUserScore");

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
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunGameEndRef:lUserScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameEndRef_lUserScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameEndRef_bcFirstCard(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameEndRef_bcFirstCard'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_S_HunGameEndRef:bcFirstCard");

            if (!ok) { break; }
            cobj->bcFirstCard(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->bcFirstCard();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunGameEndRef:bcFirstCard",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameEndRef_bcFirstCard'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameEndRef_cbTimeLeave(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameEndRef_cbTimeLeave'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_S_HunGameEndRef:cbTimeLeave");

            if (!ok) { break; }
            cobj->cbTimeLeave(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbTimeLeave();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunGameEndRef:cbTimeLeave",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameEndRef_cbTimeLeave'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameEndRef_lUserReturnScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameEndRef_lUserReturnScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunGameEndRef:lUserReturnScore");

            if (!ok) { break; }
            cobj->lUserReturnScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lUserReturnScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunGameEndRef:lUserReturnScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameEndRef_lUserReturnScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameEndRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameEndRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunGameEndRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameEndRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunGameEndRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunGameEndRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameEndRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameEndRef_cbTableCardArray(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameEndRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunGameEndRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameEndRef_cbTableCardArray'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_S_HunGameEndRef:cbTableCardArray");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMD_S_HunGameEndRef:cbTableCardArray");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunGameEndRef_cbTableCardArray'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->cbTableCardArray(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunGameEndRef:cbTableCardArray",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameEndRef_cbTableCardArray'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameEndRef_lBankerTotallScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunGameEndRef_lBankerTotallScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunGameEndRef:lBankerTotallScore");

            if (!ok) { break; }
            cobj->lBankerTotallScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lBankerTotallScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunGameEndRef:lBankerTotallScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameEndRef_lBankerTotallScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunGameEndRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_S_HunGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunGameEndRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunGameEndRef* ret = CMD_S_HunGameEndRef::createWithNotify();
        object_to_luaval<CMD_S_HunGameEndRef>(tolua_S, "CMD_S_HunGameEndRef",(CMD_S_HunGameEndRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunGameEndRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunGameEndRef* ret = CMD_S_HunGameEndRef::createWithNotify(arg0);
        object_to_luaval<CMD_S_HunGameEndRef>(tolua_S, "CMD_S_HunGameEndRef",(CMD_S_HunGameEndRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_S_HunGameEndRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunGameEndRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_S_HunGameEndRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_S_HunGameEndRef)");
    return 0;
}

int lua_register_jt_game_CMD_S_HunGameEndRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_S_HunGameEndRef");
    tolua_cclass(tolua_S,"CMD_S_HunGameEndRef","CMD_S_HunGameEndRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_S_HunGameEndRef");
        tolua_function(tolua_S,"lBankerScore",lua_jt_game_CMD_S_HunGameEndRef_lBankerScore);
        tolua_function(tolua_S,"lRevenue",lua_jt_game_CMD_S_HunGameEndRef_lRevenue);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_S_HunGameEndRef_setStruct);
        tolua_function(tolua_S,"cbLeftCardCount",lua_jt_game_CMD_S_HunGameEndRef_cbLeftCardCount);
        tolua_function(tolua_S,"nBankerTime",lua_jt_game_CMD_S_HunGameEndRef_nBankerTime);
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_S_HunGameEndRef_getSize);
        tolua_function(tolua_S,"lUserScore",lua_jt_game_CMD_S_HunGameEndRef_lUserScore);
        tolua_function(tolua_S,"bcFirstCard",lua_jt_game_CMD_S_HunGameEndRef_bcFirstCard);
        tolua_function(tolua_S,"cbTimeLeave",lua_jt_game_CMD_S_HunGameEndRef_cbTimeLeave);
        tolua_function(tolua_S,"lUserReturnScore",lua_jt_game_CMD_S_HunGameEndRef_lUserReturnScore);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_S_HunGameEndRef_getData);
        tolua_function(tolua_S,"cbTableCardArray",lua_jt_game_CMD_S_HunGameEndRef_cbTableCardArray);
        tolua_function(tolua_S,"lBankerTotallScore",lua_jt_game_CMD_S_HunGameEndRef_lBankerTotallScore);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_S_HunGameEndRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_S_HunGameEndRef).name();
    g_luaType[typeName] = "CMD_S_HunGameEndRef";
    g_typeCast["CMD_S_HunGameEndRef"] = "CMD_S_HunGameEndRef";
    return 1;
}

int lua_jt_game_CMD_C_HunPlaceJettonRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_C_HunPlaceJettonRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_C_HunPlaceJettonRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_C_HunPlaceJettonRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_C_HunPlaceJettonRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_C_HunPlaceJettonRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_C_HunPlaceJettonRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_C_HunPlaceJettonRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_C_HunPlaceJettonRef_cbJettonArea(lua_State* tolua_S)
{
    int argc = 0;
    CMD_C_HunPlaceJettonRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_C_HunPlaceJettonRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_C_HunPlaceJettonRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_C_HunPlaceJettonRef_cbJettonArea'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_C_HunPlaceJettonRef:cbJettonArea");

            if (!ok) { break; }
            cobj->cbJettonArea(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbJettonArea();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_C_HunPlaceJettonRef:cbJettonArea",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_C_HunPlaceJettonRef_cbJettonArea'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_C_HunPlaceJettonRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_C_HunPlaceJettonRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_C_HunPlaceJettonRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_C_HunPlaceJettonRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_C_HunPlaceJettonRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_C_HunPlaceJettonRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_C_HunPlaceJettonRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_C_HunPlaceJettonRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_C_HunPlaceJettonRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_C_HunPlaceJettonRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_C_HunPlaceJettonRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_C_HunPlaceJettonRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_C_HunPlaceJettonRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_C_HunPlaceJettonRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_C_HunPlaceJettonRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_C_HunPlaceJettonRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_C_HunPlaceJettonRef_lJettonScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_C_HunPlaceJettonRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_C_HunPlaceJettonRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_C_HunPlaceJettonRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_C_HunPlaceJettonRef_lJettonScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_C_HunPlaceJettonRef:lJettonScore");

            if (!ok) { break; }
            cobj->lJettonScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lJettonScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_C_HunPlaceJettonRef:lJettonScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_C_HunPlaceJettonRef_lJettonScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_C_HunPlaceJettonRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_C_HunPlaceJettonRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_C_HunPlaceJettonRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_C_HunPlaceJettonRef* ret = CMD_C_HunPlaceJettonRef::createWithNotify();
        object_to_luaval<CMD_C_HunPlaceJettonRef>(tolua_S, "CMD_C_HunPlaceJettonRef",(CMD_C_HunPlaceJettonRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_C_HunPlaceJettonRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_C_HunPlaceJettonRef* ret = CMD_C_HunPlaceJettonRef::createWithNotify(arg0);
        object_to_luaval<CMD_C_HunPlaceJettonRef>(tolua_S, "CMD_C_HunPlaceJettonRef",(CMD_C_HunPlaceJettonRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_C_HunPlaceJettonRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_C_HunPlaceJettonRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_C_HunPlaceJettonRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_C_HunPlaceJettonRef)");
    return 0;
}

int lua_register_jt_game_CMD_C_HunPlaceJettonRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_C_HunPlaceJettonRef");
    tolua_cclass(tolua_S,"CMD_C_HunPlaceJettonRef","CMD_C_HunPlaceJettonRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_C_HunPlaceJettonRef");
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_C_HunPlaceJettonRef_getSize);
        tolua_function(tolua_S,"cbJettonArea",lua_jt_game_CMD_C_HunPlaceJettonRef_cbJettonArea);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_C_HunPlaceJettonRef_setStruct);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_C_HunPlaceJettonRef_getData);
        tolua_function(tolua_S,"lJettonScore",lua_jt_game_CMD_C_HunPlaceJettonRef_lJettonScore);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_C_HunPlaceJettonRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_C_HunPlaceJettonRef).name();
    g_luaType[typeName] = "CMD_C_HunPlaceJettonRef";
    g_typeCast["CMD_C_HunPlaceJettonRef"] = "CMD_C_HunPlaceJettonRef";
    return 1;
}

int lua_jt_game_CMD_C_ApplySitRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_C_ApplySitRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_C_ApplySitRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_C_ApplySitRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_C_ApplySitRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_C_ApplySitRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_C_ApplySitRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_C_ApplySitRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_C_ApplySitRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_C_ApplySitRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_C_ApplySitRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_C_ApplySitRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_C_ApplySitRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_C_ApplySitRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_C_ApplySitRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_C_ApplySitRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_C_ApplySitRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_C_ApplySitRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_C_ApplySitRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_C_ApplySitRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_C_ApplySitRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_C_ApplySitRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_C_ApplySitRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_C_ApplySitRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_C_ApplySitRef_wSitChairID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_C_ApplySitRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_C_ApplySitRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_C_ApplySitRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_C_ApplySitRef_wSitChairID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_C_ApplySitRef:wSitChairID");

            if (!ok) { break; }
            cobj->wSitChairID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wSitChairID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_C_ApplySitRef:wSitChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_C_ApplySitRef_wSitChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_C_ApplySitRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_C_ApplySitRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_C_ApplySitRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_C_ApplySitRef* ret = CMD_C_ApplySitRef::createWithNotify();
        object_to_luaval<CMD_C_ApplySitRef>(tolua_S, "CMD_C_ApplySitRef",(CMD_C_ApplySitRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_C_ApplySitRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_C_ApplySitRef* ret = CMD_C_ApplySitRef::createWithNotify(arg0);
        object_to_luaval<CMD_C_ApplySitRef>(tolua_S, "CMD_C_ApplySitRef",(CMD_C_ApplySitRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_C_ApplySitRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_C_ApplySitRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_C_ApplySitRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_C_ApplySitRef)");
    return 0;
}

int lua_register_jt_game_CMD_C_ApplySitRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_C_ApplySitRef");
    tolua_cclass(tolua_S,"CMD_C_ApplySitRef","CMD_C_ApplySitRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_C_ApplySitRef");
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_C_ApplySitRef_getSize);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_C_ApplySitRef_setStruct);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_C_ApplySitRef_getData);
        tolua_function(tolua_S,"wSitChairID",lua_jt_game_CMD_C_ApplySitRef_wSitChairID);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_C_ApplySitRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_C_ApplySitRef).name();
    g_luaType[typeName] = "CMD_C_ApplySitRef";
    g_typeCast["CMD_C_ApplySitRef"] = "CMD_C_ApplySitRef";
    return 1;
}

int lua_jt_game_CMD_C_CancelSitRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_C_CancelSitRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_C_CancelSitRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_C_CancelSitRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_C_CancelSitRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_C_CancelSitRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_C_CancelSitRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_C_CancelSitRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_C_CancelSitRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_C_CancelSitRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_C_CancelSitRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_C_CancelSitRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_C_CancelSitRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_C_CancelSitRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_C_CancelSitRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_C_CancelSitRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_C_CancelSitRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_C_CancelSitRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_C_CancelSitRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_C_CancelSitRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_C_CancelSitRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_C_CancelSitRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_C_CancelSitRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_C_CancelSitRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_C_CancelSitRef_wSitChairID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_C_CancelSitRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_C_CancelSitRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_C_CancelSitRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_C_CancelSitRef_wSitChairID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_C_CancelSitRef:wSitChairID");

            if (!ok) { break; }
            cobj->wSitChairID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wSitChairID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_C_CancelSitRef:wSitChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_C_CancelSitRef_wSitChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_C_CancelSitRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_C_CancelSitRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_C_CancelSitRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_C_CancelSitRef* ret = CMD_C_CancelSitRef::createWithNotify();
        object_to_luaval<CMD_C_CancelSitRef>(tolua_S, "CMD_C_CancelSitRef",(CMD_C_CancelSitRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_C_CancelSitRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_C_CancelSitRef* ret = CMD_C_CancelSitRef::createWithNotify(arg0);
        object_to_luaval<CMD_C_CancelSitRef>(tolua_S, "CMD_C_CancelSitRef",(CMD_C_CancelSitRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_C_CancelSitRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_C_CancelSitRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_C_CancelSitRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_C_CancelSitRef)");
    return 0;
}

int lua_register_jt_game_CMD_C_CancelSitRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_C_CancelSitRef");
    tolua_cclass(tolua_S,"CMD_C_CancelSitRef","CMD_C_CancelSitRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_C_CancelSitRef");
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_C_CancelSitRef_getSize);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_C_CancelSitRef_setStruct);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_C_CancelSitRef_getData);
        tolua_function(tolua_S,"wSitChairID",lua_jt_game_CMD_C_CancelSitRef_wSitChairID);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_C_CancelSitRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_C_CancelSitRef).name();
    g_luaType[typeName] = "CMD_C_CancelSitRef";
    g_typeCast["CMD_C_CancelSitRef"] = "CMD_C_CancelSitRef";
    return 1;
}

int lua_jt_game_CMD_S_ApplySitRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_ApplySitRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_ApplySitRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_ApplySitRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_ApplySitRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_ApplySitRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_ApplySitRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_ApplySitRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_ApplySitRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_ApplySitRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_ApplySitRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_ApplySitRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_ApplySitRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_ApplySitRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_ApplySitRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_ApplySitRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_ApplySitRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_ApplySitRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_ApplySitRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_ApplySitRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_ApplySitRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_ApplySitRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_ApplySitRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_ApplySitRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_ApplySitRef_wSitChairID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_ApplySitRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_ApplySitRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_ApplySitRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_ApplySitRef_wSitChairID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_ApplySitRef:wSitChairID");

            if (!ok) { break; }
            cobj->wSitChairID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wSitChairID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_ApplySitRef:wSitChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_ApplySitRef_wSitChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_ApplySitRef_wApplySitID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_ApplySitRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_ApplySitRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_ApplySitRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_ApplySitRef_wApplySitID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_ApplySitRef:wApplySitID");

            if (!ok) { break; }
            cobj->wApplySitID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wApplySitID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_ApplySitRef:wApplySitID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_ApplySitRef_wApplySitID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_ApplySitRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_S_ApplySitRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_ApplySitRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_ApplySitRef* ret = CMD_S_ApplySitRef::createWithNotify();
        object_to_luaval<CMD_S_ApplySitRef>(tolua_S, "CMD_S_ApplySitRef",(CMD_S_ApplySitRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_ApplySitRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_ApplySitRef* ret = CMD_S_ApplySitRef::createWithNotify(arg0);
        object_to_luaval<CMD_S_ApplySitRef>(tolua_S, "CMD_S_ApplySitRef",(CMD_S_ApplySitRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_S_ApplySitRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_ApplySitRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_S_ApplySitRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_S_ApplySitRef)");
    return 0;
}

int lua_register_jt_game_CMD_S_ApplySitRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_S_ApplySitRef");
    tolua_cclass(tolua_S,"CMD_S_ApplySitRef","CMD_S_ApplySitRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_S_ApplySitRef");
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_S_ApplySitRef_getSize);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_S_ApplySitRef_setStruct);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_S_ApplySitRef_getData);
        tolua_function(tolua_S,"wSitChairID",lua_jt_game_CMD_S_ApplySitRef_wSitChairID);
        tolua_function(tolua_S,"wApplySitID",lua_jt_game_CMD_S_ApplySitRef_wApplySitID);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_S_ApplySitRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_S_ApplySitRef).name();
    g_luaType[typeName] = "CMD_S_ApplySitRef";
    g_typeCast["CMD_S_ApplySitRef"] = "CMD_S_ApplySitRef";
    return 1;
}

int lua_jt_game_CMD_S_CancelSitRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_CancelSitRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_CancelSitRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_CancelSitRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_CancelSitRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_CancelSitRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_CancelSitRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_CancelSitRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_CancelSitRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_CancelSitRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_CancelSitRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_CancelSitRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_CancelSitRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_CancelSitRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_CancelSitRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_CancelSitRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_CancelSitRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_CancelSitRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_CancelSitRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_CancelSitRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_CancelSitRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_CancelSitRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_CancelSitRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_CancelSitRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_CancelSitRef_wSitChairID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_CancelSitRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_CancelSitRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_CancelSitRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_CancelSitRef_wSitChairID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_CancelSitRef:wSitChairID");

            if (!ok) { break; }
            cobj->wSitChairID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wSitChairID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_CancelSitRef:wSitChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_CancelSitRef_wSitChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_CancelSitRef_wCancelID(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_CancelSitRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_CancelSitRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_CancelSitRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_CancelSitRef_wCancelID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_CancelSitRef:wCancelID");

            if (!ok) { break; }
            cobj->wCancelID(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wCancelID();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_CancelSitRef:wCancelID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_CancelSitRef_wCancelID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_CancelSitRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_S_CancelSitRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_CancelSitRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_CancelSitRef* ret = CMD_S_CancelSitRef::createWithNotify();
        object_to_luaval<CMD_S_CancelSitRef>(tolua_S, "CMD_S_CancelSitRef",(CMD_S_CancelSitRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_CancelSitRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_CancelSitRef* ret = CMD_S_CancelSitRef::createWithNotify(arg0);
        object_to_luaval<CMD_S_CancelSitRef>(tolua_S, "CMD_S_CancelSitRef",(CMD_S_CancelSitRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_S_CancelSitRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_CancelSitRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_S_CancelSitRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_S_CancelSitRef)");
    return 0;
}

int lua_register_jt_game_CMD_S_CancelSitRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_S_CancelSitRef");
    tolua_cclass(tolua_S,"CMD_S_CancelSitRef","CMD_S_CancelSitRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_S_CancelSitRef");
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_S_CancelSitRef_getSize);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_S_CancelSitRef_setStruct);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_S_CancelSitRef_getData);
        tolua_function(tolua_S,"wSitChairID",lua_jt_game_CMD_S_CancelSitRef_wSitChairID);
        tolua_function(tolua_S,"wCancelID",lua_jt_game_CMD_S_CancelSitRef_wCancelID);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_S_CancelSitRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_S_CancelSitRef).name();
    g_luaType[typeName] = "CMD_S_CancelSitRef";
    g_typeCast["CMD_S_CancelSitRef"] = "CMD_S_CancelSitRef";
    return 1;
}

int lua_jt_game_tagUserWLInfoRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    tagUserWLInfoRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserWLInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserWLInfoRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagUserWLInfoRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_tagUserWLInfoRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserWLInfoRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagUserWLInfoRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagUserWLInfoRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    tagUserWLInfoRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserWLInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserWLInfoRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagUserWLInfoRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_tagUserWLInfoRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserWLInfoRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagUserWLInfoRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagUserWLInfoRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    tagUserWLInfoRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserWLInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagUserWLInfoRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagUserWLInfoRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_tagUserWLInfoRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagUserWLInfoRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagUserWLInfoRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagUserWLInfoRef_wChairID(lua_State* tolua_S)
{
    int argc = 0;
    tagUserWLInfoRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserWLInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagUserWLInfoRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagUserWLInfoRef_wChairID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "tagUserWLInfoRef:wChairID");

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
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagUserWLInfoRef:wChairID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagUserWLInfoRef_wChairID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagUserWLInfoRef_lJettonScore(lua_State* tolua_S)
{
    int argc = 0;
    tagUserWLInfoRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagUserWLInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagUserWLInfoRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagUserWLInfoRef_lJettonScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagUserWLInfoRef:lJettonScore");

            if (!ok) { break; }
            cobj->lJettonScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lJettonScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagUserWLInfoRef:lJettonScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagUserWLInfoRef_lJettonScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagUserWLInfoRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"tagUserWLInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_tagUserWLInfoRef_createWithNotify'", nullptr);
            return 0;
        }
        tagUserWLInfoRef* ret = tagUserWLInfoRef::createWithNotify();
        object_to_luaval<tagUserWLInfoRef>(tolua_S, "tagUserWLInfoRef",(tagUserWLInfoRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_tagUserWLInfoRef_createWithNotify'", nullptr);
            return 0;
        }
        tagUserWLInfoRef* ret = tagUserWLInfoRef::createWithNotify(arg0);
        object_to_luaval<tagUserWLInfoRef>(tolua_S, "tagUserWLInfoRef",(tagUserWLInfoRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "tagUserWLInfoRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagUserWLInfoRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_tagUserWLInfoRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagUserWLInfoRef)");
    return 0;
}

int lua_register_jt_game_tagUserWLInfoRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagUserWLInfoRef");
    tolua_cclass(tolua_S,"tagUserWLInfoRef","tagUserWLInfoRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"tagUserWLInfoRef");
        tolua_function(tolua_S,"getSize",lua_jt_game_tagUserWLInfoRef_getSize);
        tolua_function(tolua_S,"setStruct",lua_jt_game_tagUserWLInfoRef_setStruct);
        tolua_function(tolua_S,"getData",lua_jt_game_tagUserWLInfoRef_getData);
        tolua_function(tolua_S,"wChairID",lua_jt_game_tagUserWLInfoRef_wChairID);
        tolua_function(tolua_S,"lJettonScore",lua_jt_game_tagUserWLInfoRef_lJettonScore);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_tagUserWLInfoRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagUserWLInfoRef).name();
    g_luaType[typeName] = "tagUserWLInfoRef";
    g_typeCast["tagUserWLInfoRef"] = "tagUserWLInfoRef";
    return 1;
}

int lua_jt_game_CMD_S_WLInfoRef_gettagWinInfo(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_WLInfoRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_WLInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_WLInfoRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_WLInfoRef_gettagWinInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_S_WLInfoRef:gettagWinInfo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_WLInfoRef_gettagWinInfo'", nullptr);
            return 0;
        }
        tagUserWLInfoRef* ret = cobj->gettagWinInfo(arg0);
        object_to_luaval<tagUserWLInfoRef>(tolua_S, "tagUserWLInfoRef",(tagUserWLInfoRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_WLInfoRef:gettagWinInfo",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_WLInfoRef_gettagWinInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_WLInfoRef_settagLoseInfo(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_WLInfoRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_WLInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_WLInfoRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_WLInfoRef_settagLoseInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        tagUserWLInfoRef* arg0;

        ok &= luaval_to_object<tagUserWLInfoRef>(tolua_S, 2, "tagUserWLInfoRef",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_WLInfoRef_settagLoseInfo'", nullptr);
            return 0;
        }
        cobj->settagLoseInfo(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_WLInfoRef:settagLoseInfo",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_WLInfoRef_settagLoseInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_WLInfoRef_settagWinInfo(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_WLInfoRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_WLInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_WLInfoRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_WLInfoRef_settagWinInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        tagUserWLInfoRef* arg0;
        int arg1;

        ok &= luaval_to_object<tagUserWLInfoRef>(tolua_S, 2, "tagUserWLInfoRef",&arg0);

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMD_S_WLInfoRef:settagWinInfo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_WLInfoRef_settagWinInfo'", nullptr);
            return 0;
        }
        cobj->settagWinInfo(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_WLInfoRef:settagWinInfo",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_WLInfoRef_settagWinInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_WLInfoRef_gettagLoseInfo(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_WLInfoRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_WLInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_WLInfoRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_WLInfoRef_gettagLoseInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_WLInfoRef_gettagLoseInfo'", nullptr);
            return 0;
        }
        tagUserWLInfoRef* ret = cobj->gettagLoseInfo();
        object_to_luaval<tagUserWLInfoRef>(tolua_S, "tagUserWLInfoRef",(tagUserWLInfoRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_WLInfoRef:gettagLoseInfo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_WLInfoRef_gettagLoseInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_WLInfoRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_WLInfoRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_WLInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_WLInfoRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_WLInfoRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_WLInfoRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_WLInfoRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_WLInfoRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_WLInfoRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_WLInfoRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_WLInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_WLInfoRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_WLInfoRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_WLInfoRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_WLInfoRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_WLInfoRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_WLInfoRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_WLInfoRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_WLInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_WLInfoRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_WLInfoRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_WLInfoRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_WLInfoRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_WLInfoRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_WLInfoRef_initRef(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_WLInfoRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_WLInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_WLInfoRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_WLInfoRef_initRef'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_WLInfoRef_initRef'", nullptr);
            return 0;
        }
        cobj->initRef();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_WLInfoRef:initRef",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_WLInfoRef_initRef'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_WLInfoRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_S_WLInfoRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_WLInfoRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_WLInfoRef* ret = CMD_S_WLInfoRef::createWithNotify();
        object_to_luaval<CMD_S_WLInfoRef>(tolua_S, "CMD_S_WLInfoRef",(CMD_S_WLInfoRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_WLInfoRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_WLInfoRef* ret = CMD_S_WLInfoRef::createWithNotify(arg0);
        object_to_luaval<CMD_S_WLInfoRef>(tolua_S, "CMD_S_WLInfoRef",(CMD_S_WLInfoRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_S_WLInfoRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_WLInfoRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_S_WLInfoRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_S_WLInfoRef)");
    return 0;
}

int lua_register_jt_game_CMD_S_WLInfoRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_S_WLInfoRef");
    tolua_cclass(tolua_S,"CMD_S_WLInfoRef","CMD_S_WLInfoRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_S_WLInfoRef");
        tolua_function(tolua_S,"gettagWinInfo",lua_jt_game_CMD_S_WLInfoRef_gettagWinInfo);
        tolua_function(tolua_S,"settagLoseInfo",lua_jt_game_CMD_S_WLInfoRef_settagLoseInfo);
        tolua_function(tolua_S,"settagWinInfo",lua_jt_game_CMD_S_WLInfoRef_settagWinInfo);
        tolua_function(tolua_S,"gettagLoseInfo",lua_jt_game_CMD_S_WLInfoRef_gettagLoseInfo);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_S_WLInfoRef_setStruct);
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_S_WLInfoRef_getSize);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_S_WLInfoRef_getData);
        tolua_function(tolua_S,"initRef",lua_jt_game_CMD_S_WLInfoRef_initRef);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_S_WLInfoRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_S_WLInfoRef).name();
    g_luaType[typeName] = "CMD_S_WLInfoRef";
    g_typeCast["CMD_S_WLInfoRef"] = "CMD_S_WLInfoRef";
    return 1;
}

int lua_jt_game_tagAwardFirstRef_lExtraScore(lua_State* tolua_S)
{
    int argc = 0;
    tagAwardFirstRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagAwardFirstRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagAwardFirstRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagAwardFirstRef_lExtraScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagAwardFirstRef:lExtraScore");

            if (!ok) { break; }
            cobj->lExtraScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lExtraScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagAwardFirstRef:lExtraScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagAwardFirstRef_lExtraScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagAwardFirstRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    tagAwardFirstRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagAwardFirstRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagAwardFirstRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagAwardFirstRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_tagAwardFirstRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagAwardFirstRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagAwardFirstRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagAwardFirstRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    tagAwardFirstRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagAwardFirstRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagAwardFirstRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagAwardFirstRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_tagAwardFirstRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagAwardFirstRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagAwardFirstRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagAwardFirstRef_bExtraScore(lua_State* tolua_S)
{
    int argc = 0;
    tagAwardFirstRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagAwardFirstRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagAwardFirstRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagAwardFirstRef_bExtraScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2,&arg0, "tagAwardFirstRef:bExtraScore");

            if (!ok) { break; }
            cobj->bExtraScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            bool ret = cobj->bExtraScore();
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagAwardFirstRef:bExtraScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagAwardFirstRef_bExtraScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagAwardFirstRef_lWinScore(lua_State* tolua_S)
{
    int argc = 0;
    tagAwardFirstRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagAwardFirstRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagAwardFirstRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagAwardFirstRef_lWinScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "tagAwardFirstRef:lWinScore");

            if (!ok) { break; }
            cobj->lWinScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lWinScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagAwardFirstRef:lWinScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagAwardFirstRef_lWinScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagAwardFirstRef_dwGameID(lua_State* tolua_S)
{
    int argc = 0;
    tagAwardFirstRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagAwardFirstRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagAwardFirstRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagAwardFirstRef_dwGameID'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "tagAwardFirstRef:dwGameID");

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
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagAwardFirstRef:dwGameID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagAwardFirstRef_dwGameID'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagAwardFirstRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    tagAwardFirstRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagAwardFirstRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (tagAwardFirstRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagAwardFirstRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_tagAwardFirstRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "tagAwardFirstRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagAwardFirstRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagAwardFirstRef_szUserName(lua_State* tolua_S)
{
    int argc = 0;
    tagAwardFirstRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tagAwardFirstRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (tagAwardFirstRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_tagAwardFirstRef_szUserName'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "tagAwardFirstRef:szUserName"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szUserName(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szUserName();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "tagAwardFirstRef:szUserName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagAwardFirstRef_szUserName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_tagAwardFirstRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"tagAwardFirstRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_tagAwardFirstRef_createWithNotify'", nullptr);
            return 0;
        }
        tagAwardFirstRef* ret = tagAwardFirstRef::createWithNotify();
        object_to_luaval<tagAwardFirstRef>(tolua_S, "tagAwardFirstRef",(tagAwardFirstRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_tagAwardFirstRef_createWithNotify'", nullptr);
            return 0;
        }
        tagAwardFirstRef* ret = tagAwardFirstRef::createWithNotify(arg0);
        object_to_luaval<tagAwardFirstRef>(tolua_S, "tagAwardFirstRef",(tagAwardFirstRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "tagAwardFirstRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_tagAwardFirstRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_tagAwardFirstRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (tagAwardFirstRef)");
    return 0;
}

int lua_register_jt_game_tagAwardFirstRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tagAwardFirstRef");
    tolua_cclass(tolua_S,"tagAwardFirstRef","tagAwardFirstRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"tagAwardFirstRef");
        tolua_function(tolua_S,"lExtraScore",lua_jt_game_tagAwardFirstRef_lExtraScore);
        tolua_function(tolua_S,"setStruct",lua_jt_game_tagAwardFirstRef_setStruct);
        tolua_function(tolua_S,"getSize",lua_jt_game_tagAwardFirstRef_getSize);
        tolua_function(tolua_S,"bExtraScore",lua_jt_game_tagAwardFirstRef_bExtraScore);
        tolua_function(tolua_S,"lWinScore",lua_jt_game_tagAwardFirstRef_lWinScore);
        tolua_function(tolua_S,"dwGameID",lua_jt_game_tagAwardFirstRef_dwGameID);
        tolua_function(tolua_S,"getData",lua_jt_game_tagAwardFirstRef_getData);
        tolua_function(tolua_S,"szUserName",lua_jt_game_tagAwardFirstRef_szUserName);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_tagAwardFirstRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(tagAwardFirstRef).name();
    g_luaType[typeName] = "tagAwardFirstRef";
    g_typeCast["tagAwardFirstRef"] = "tagAwardFirstRef";
    return 1;
}

int lua_jt_game_CMD_S_HunNewStatusFreeRef_getTagAwardFirst(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusFreeRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewStatusFreeRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_getTagAwardFirst'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_getTagAwardFirst'", nullptr);
            return 0;
        }
        tagAwardFirstRef* ret = cobj->getTagAwardFirst();
        object_to_luaval<tagAwardFirstRef>(tolua_S, "tagAwardFirstRef",(tagAwardFirstRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewStatusFreeRef:getTagAwardFirst",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_getTagAwardFirst'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusFreeRef_lStorageStart(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_lStorageStart'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewStatusFreeRef:lStorageStart");

            if (!ok) { break; }
            cobj->lStorageStart(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lStorageStart();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusFreeRef:lStorageStart",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_lStorageStart'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusFreeRef_lBankerScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_lBankerScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewStatusFreeRef:lBankerScore");

            if (!ok) { break; }
            cobj->lBankerScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lBankerScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusFreeRef:lBankerScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_lBankerScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusFreeRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusFreeRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewStatusFreeRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewStatusFreeRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusFreeRef_setTagAwardFirst(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusFreeRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewStatusFreeRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_setTagAwardFirst'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        tagAwardFirstRef* arg0;

        ok &= luaval_to_object<tagAwardFirstRef>(tolua_S, 2, "tagAwardFirstRef",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_setTagAwardFirst'", nullptr);
            return 0;
        }
        cobj->setTagAwardFirst(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewStatusFreeRef:setTagAwardFirst",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_setTagAwardFirst'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusFreeRef_lBankerWinScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_lBankerWinScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewStatusFreeRef:lBankerWinScore");

            if (!ok) { break; }
            cobj->lBankerWinScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lBankerWinScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusFreeRef:lBankerWinScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_lBankerWinScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusFreeRef_bEnableSysBanker(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_bEnableSysBanker'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CMD_S_HunNewStatusFreeRef:bEnableSysBanker");

            if (!ok) { break; }
            cobj->bEnableSysBanker(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            bool ret = cobj->bEnableSysBanker();
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusFreeRef:bEnableSysBanker",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_bEnableSysBanker'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusFreeRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusFreeRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewStatusFreeRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewStatusFreeRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusFreeRef_lSitMinSocre(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_lSitMinSocre'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewStatusFreeRef:lSitMinSocre");

            if (!ok) { break; }
            cobj->lSitMinSocre(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lSitMinSocre();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusFreeRef:lSitMinSocre",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_lSitMinSocre'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusFreeRef_lApplyBankerCondition(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_lApplyBankerCondition'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewStatusFreeRef:lApplyBankerCondition");

            if (!ok) { break; }
            cobj->lApplyBankerCondition(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lApplyBankerCondition();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusFreeRef:lApplyBankerCondition",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_lApplyBankerCondition'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusFreeRef_wBankerUser(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_wBankerUser'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_HunNewStatusFreeRef:wBankerUser");

            if (!ok) { break; }
            cobj->wBankerUser(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wBankerUser();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusFreeRef:wBankerUser",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_wBankerUser'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusFreeRef_cbTimeLeave(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_cbTimeLeave'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_S_HunNewStatusFreeRef:cbTimeLeave");

            if (!ok) { break; }
            cobj->cbTimeLeave(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbTimeLeave();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusFreeRef:cbTimeLeave",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_cbTimeLeave'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusFreeRef_cbBankerTime(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_cbBankerTime'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_HunNewStatusFreeRef:cbBankerTime");

            if (!ok) { break; }
            cobj->cbBankerTime(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->cbBankerTime();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusFreeRef:cbBankerTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_cbBankerTime'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusFreeRef_szGameRoomName(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_szGameRoomName'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_S_HunNewStatusFreeRef:szGameRoomName"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szGameRoomName(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szGameRoomName();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusFreeRef:szGameRoomName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_szGameRoomName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusFreeRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusFreeRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewStatusFreeRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewStatusFreeRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusFreeRef_lUserMaxScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_lUserMaxScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewStatusFreeRef:lUserMaxScore");

            if (!ok) { break; }
            cobj->lUserMaxScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lUserMaxScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusFreeRef:lUserMaxScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_lUserMaxScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusFreeRef_initRef(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusFreeRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewStatusFreeRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_initRef'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_initRef'", nullptr);
            return 0;
        }
        cobj->initRef();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewStatusFreeRef:initRef",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_initRef'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusFreeRef_lAreaLimitScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_lAreaLimitScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewStatusFreeRef:lAreaLimitScore");

            if (!ok) { break; }
            cobj->lAreaLimitScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lAreaLimitScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusFreeRef:lAreaLimitScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_lAreaLimitScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusFreeRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_S_HunNewStatusFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunNewStatusFreeRef* ret = CMD_S_HunNewStatusFreeRef::createWithNotify();
        object_to_luaval<CMD_S_HunNewStatusFreeRef>(tolua_S, "CMD_S_HunNewStatusFreeRef",(CMD_S_HunNewStatusFreeRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunNewStatusFreeRef* ret = CMD_S_HunNewStatusFreeRef::createWithNotify(arg0);
        object_to_luaval<CMD_S_HunNewStatusFreeRef>(tolua_S, "CMD_S_HunNewStatusFreeRef",(CMD_S_HunNewStatusFreeRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_S_HunNewStatusFreeRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusFreeRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_S_HunNewStatusFreeRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_S_HunNewStatusFreeRef)");
    return 0;
}

int lua_register_jt_game_CMD_S_HunNewStatusFreeRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_S_HunNewStatusFreeRef");
    tolua_cclass(tolua_S,"CMD_S_HunNewStatusFreeRef","CMD_S_HunNewStatusFreeRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_S_HunNewStatusFreeRef");
        tolua_function(tolua_S,"getTagAwardFirst",lua_jt_game_CMD_S_HunNewStatusFreeRef_getTagAwardFirst);
        tolua_function(tolua_S,"lStorageStart",lua_jt_game_CMD_S_HunNewStatusFreeRef_lStorageStart);
        tolua_function(tolua_S,"lBankerScore",lua_jt_game_CMD_S_HunNewStatusFreeRef_lBankerScore);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_S_HunNewStatusFreeRef_setStruct);
        tolua_function(tolua_S,"setTagAwardFirst",lua_jt_game_CMD_S_HunNewStatusFreeRef_setTagAwardFirst);
        tolua_function(tolua_S,"lBankerWinScore",lua_jt_game_CMD_S_HunNewStatusFreeRef_lBankerWinScore);
        tolua_function(tolua_S,"bEnableSysBanker",lua_jt_game_CMD_S_HunNewStatusFreeRef_bEnableSysBanker);
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_S_HunNewStatusFreeRef_getSize);
        tolua_function(tolua_S,"lSitMinSocre",lua_jt_game_CMD_S_HunNewStatusFreeRef_lSitMinSocre);
        tolua_function(tolua_S,"lApplyBankerCondition",lua_jt_game_CMD_S_HunNewStatusFreeRef_lApplyBankerCondition);
        tolua_function(tolua_S,"wBankerUser",lua_jt_game_CMD_S_HunNewStatusFreeRef_wBankerUser);
        tolua_function(tolua_S,"cbTimeLeave",lua_jt_game_CMD_S_HunNewStatusFreeRef_cbTimeLeave);
        tolua_function(tolua_S,"cbBankerTime",lua_jt_game_CMD_S_HunNewStatusFreeRef_cbBankerTime);
        tolua_function(tolua_S,"szGameRoomName",lua_jt_game_CMD_S_HunNewStatusFreeRef_szGameRoomName);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_S_HunNewStatusFreeRef_getData);
        tolua_function(tolua_S,"lUserMaxScore",lua_jt_game_CMD_S_HunNewStatusFreeRef_lUserMaxScore);
        tolua_function(tolua_S,"initRef",lua_jt_game_CMD_S_HunNewStatusFreeRef_initRef);
        tolua_function(tolua_S,"lAreaLimitScore",lua_jt_game_CMD_S_HunNewStatusFreeRef_lAreaLimitScore);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_S_HunNewStatusFreeRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_S_HunNewStatusFreeRef).name();
    g_luaType[typeName] = "CMD_S_HunNewStatusFreeRef";
    g_typeCast["CMD_S_HunNewStatusFreeRef"] = "CMD_S_HunNewStatusFreeRef";
    return 1;
}

int lua_jt_game_CMD_S_HunNewStatusPlayRef_lEndUserScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lEndUserScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewStatusPlayRef:lEndUserScore");

            if (!ok) { break; }
            cobj->lEndUserScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lEndUserScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusPlayRef:lEndUserScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lEndUserScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_cbGameStatus(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_cbGameStatus'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_S_HunNewStatusPlayRef:cbGameStatus");

            if (!ok) { break; }
            cobj->cbGameStatus(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbGameStatus();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusPlayRef:cbGameStatus",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_cbGameStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewStatusPlayRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_lBankerWinScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lBankerWinScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewStatusPlayRef:lBankerWinScore");

            if (!ok) { break; }
            cobj->lBankerWinScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lBankerWinScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusPlayRef:lBankerWinScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lBankerWinScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_initRef(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_initRef'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_initRef'", nullptr);
            return 0;
        }
        cobj->initRef();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewStatusPlayRef:initRef",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_initRef'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewStatusPlayRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_getTagAwardFirst(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_getTagAwardFirst'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_getTagAwardFirst'", nullptr);
            return 0;
        }
        tagAwardFirstRef* ret = cobj->getTagAwardFirst();
        object_to_luaval<tagAwardFirstRef>(tolua_S, "tagAwardFirstRef",(tagAwardFirstRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewStatusPlayRef:getTagAwardFirst",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_getTagAwardFirst'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_lEndRevenue(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lEndRevenue'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewStatusPlayRef:lEndRevenue");

            if (!ok) { break; }
            cobj->lEndRevenue(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lEndRevenue();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusPlayRef:lEndRevenue",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lEndRevenue'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_lEndBankerScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lEndBankerScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewStatusPlayRef:lEndBankerScore");

            if (!ok) { break; }
            cobj->lEndBankerScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lEndBankerScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusPlayRef:lEndBankerScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lEndBankerScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_lSitMinSocre(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lSitMinSocre'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewStatusPlayRef:lSitMinSocre");

            if (!ok) { break; }
            cobj->lSitMinSocre(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lSitMinSocre();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusPlayRef:lSitMinSocre",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lSitMinSocre'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_lBankerScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lBankerScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewStatusPlayRef:lBankerScore");

            if (!ok) { break; }
            cobj->lBankerScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lBankerScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusPlayRef:lBankerScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lBankerScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_cbTableCardArray(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_cbTableCardArray'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_S_HunNewStatusPlayRef:cbTableCardArray");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMD_S_HunNewStatusPlayRef:cbTableCardArray");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_cbTableCardArray'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->cbTableCardArray(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewStatusPlayRef:cbTableCardArray",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_cbTableCardArray'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_szGameRoomName(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_szGameRoomName'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMD_S_HunNewStatusPlayRef:szGameRoomName"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->szGameRoomName(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            const char* ret = cobj->szGameRoomName();
            tolua_pushstring(tolua_S,(const char*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusPlayRef:szGameRoomName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_szGameRoomName'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_bEnableSysBanker(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_bEnableSysBanker'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CMD_S_HunNewStatusPlayRef:bEnableSysBanker");

            if (!ok) { break; }
            cobj->bEnableSysBanker(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            bool ret = cobj->bEnableSysBanker();
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusPlayRef:bEnableSysBanker",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_bEnableSysBanker'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_lStorageStart(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lStorageStart'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewStatusPlayRef:lStorageStart");

            if (!ok) { break; }
            cobj->lStorageStart(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lStorageStart();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusPlayRef:lStorageStart",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lStorageStart'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_setTagAwardFirst(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_setTagAwardFirst'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        tagAwardFirstRef* arg0;

        ok &= luaval_to_object<tagAwardFirstRef>(tolua_S, 2, "tagAwardFirstRef",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_setTagAwardFirst'", nullptr);
            return 0;
        }
        cobj->setTagAwardFirst(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewStatusPlayRef:setTagAwardFirst",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_setTagAwardFirst'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewStatusPlayRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_wBankerUser(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_wBankerUser'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_HunNewStatusPlayRef:wBankerUser");

            if (!ok) { break; }
            cobj->wBankerUser(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->wBankerUser();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusPlayRef:wBankerUser",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_wBankerUser'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_lAreaLimitScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lAreaLimitScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewStatusPlayRef:lAreaLimitScore");

            if (!ok) { break; }
            cobj->lAreaLimitScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lAreaLimitScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusPlayRef:lAreaLimitScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lAreaLimitScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_lUserJettonScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lUserJettonScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_S_HunNewStatusPlayRef:lUserJettonScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lUserJettonScore'", nullptr);
            return 0;
        }
        long long ret = cobj->lUserJettonScore(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewStatusPlayRef:lUserJettonScore",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lUserJettonScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_lApplyBankerCondition(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lApplyBankerCondition'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewStatusPlayRef:lApplyBankerCondition");

            if (!ok) { break; }
            cobj->lApplyBankerCondition(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lApplyBankerCondition();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusPlayRef:lApplyBankerCondition",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lApplyBankerCondition'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_lAllJettonScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lAllJettonScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_S_HunNewStatusPlayRef:lAllJettonScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lAllJettonScore'", nullptr);
            return 0;
        }
        long long ret = cobj->lAllJettonScore(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewStatusPlayRef:lAllJettonScore",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lAllJettonScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_lEndUserReturnScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lEndUserReturnScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewStatusPlayRef:lEndUserReturnScore");

            if (!ok) { break; }
            cobj->lEndUserReturnScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lEndUserReturnScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusPlayRef:lEndUserReturnScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lEndUserReturnScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_cbTimeLeave(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_cbTimeLeave'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_S_HunNewStatusPlayRef:cbTimeLeave");

            if (!ok) { break; }
            cobj->cbTimeLeave(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbTimeLeave();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusPlayRef:cbTimeLeave",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_cbTimeLeave'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_cbBankerTime(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_cbBankerTime'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned short arg0;
            ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMD_S_HunNewStatusPlayRef:cbBankerTime");

            if (!ok) { break; }
            cobj->cbBankerTime(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            unsigned short ret = cobj->cbBankerTime();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusPlayRef:cbBankerTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_cbBankerTime'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_lUserMaxScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewStatusPlayRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewStatusPlayRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lUserMaxScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewStatusPlayRef:lUserMaxScore");

            if (!ok) { break; }
            cobj->lUserMaxScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lUserMaxScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewStatusPlayRef:lUserMaxScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_lUserMaxScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewStatusPlayRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_S_HunNewStatusPlayRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunNewStatusPlayRef* ret = CMD_S_HunNewStatusPlayRef::createWithNotify();
        object_to_luaval<CMD_S_HunNewStatusPlayRef>(tolua_S, "CMD_S_HunNewStatusPlayRef",(CMD_S_HunNewStatusPlayRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunNewStatusPlayRef* ret = CMD_S_HunNewStatusPlayRef::createWithNotify(arg0);
        object_to_luaval<CMD_S_HunNewStatusPlayRef>(tolua_S, "CMD_S_HunNewStatusPlayRef",(CMD_S_HunNewStatusPlayRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_S_HunNewStatusPlayRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewStatusPlayRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_S_HunNewStatusPlayRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_S_HunNewStatusPlayRef)");
    return 0;
}

int lua_register_jt_game_CMD_S_HunNewStatusPlayRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_S_HunNewStatusPlayRef");
    tolua_cclass(tolua_S,"CMD_S_HunNewStatusPlayRef","CMD_S_HunNewStatusPlayRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_S_HunNewStatusPlayRef");
        tolua_function(tolua_S,"lEndUserScore",lua_jt_game_CMD_S_HunNewStatusPlayRef_lEndUserScore);
        tolua_function(tolua_S,"cbGameStatus",lua_jt_game_CMD_S_HunNewStatusPlayRef_cbGameStatus);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_S_HunNewStatusPlayRef_setStruct);
        tolua_function(tolua_S,"lBankerWinScore",lua_jt_game_CMD_S_HunNewStatusPlayRef_lBankerWinScore);
        tolua_function(tolua_S,"initRef",lua_jt_game_CMD_S_HunNewStatusPlayRef_initRef);
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_S_HunNewStatusPlayRef_getSize);
        tolua_function(tolua_S,"getTagAwardFirst",lua_jt_game_CMD_S_HunNewStatusPlayRef_getTagAwardFirst);
        tolua_function(tolua_S,"lEndRevenue",lua_jt_game_CMD_S_HunNewStatusPlayRef_lEndRevenue);
        tolua_function(tolua_S,"lEndBankerScore",lua_jt_game_CMD_S_HunNewStatusPlayRef_lEndBankerScore);
        tolua_function(tolua_S,"lSitMinSocre",lua_jt_game_CMD_S_HunNewStatusPlayRef_lSitMinSocre);
        tolua_function(tolua_S,"lBankerScore",lua_jt_game_CMD_S_HunNewStatusPlayRef_lBankerScore);
        tolua_function(tolua_S,"cbTableCardArray",lua_jt_game_CMD_S_HunNewStatusPlayRef_cbTableCardArray);
        tolua_function(tolua_S,"szGameRoomName",lua_jt_game_CMD_S_HunNewStatusPlayRef_szGameRoomName);
        tolua_function(tolua_S,"bEnableSysBanker",lua_jt_game_CMD_S_HunNewStatusPlayRef_bEnableSysBanker);
        tolua_function(tolua_S,"lStorageStart",lua_jt_game_CMD_S_HunNewStatusPlayRef_lStorageStart);
        tolua_function(tolua_S,"setTagAwardFirst",lua_jt_game_CMD_S_HunNewStatusPlayRef_setTagAwardFirst);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_S_HunNewStatusPlayRef_getData);
        tolua_function(tolua_S,"wBankerUser",lua_jt_game_CMD_S_HunNewStatusPlayRef_wBankerUser);
        tolua_function(tolua_S,"lAreaLimitScore",lua_jt_game_CMD_S_HunNewStatusPlayRef_lAreaLimitScore);
        tolua_function(tolua_S,"lUserJettonScore",lua_jt_game_CMD_S_HunNewStatusPlayRef_lUserJettonScore);
        tolua_function(tolua_S,"lApplyBankerCondition",lua_jt_game_CMD_S_HunNewStatusPlayRef_lApplyBankerCondition);
        tolua_function(tolua_S,"lAllJettonScore",lua_jt_game_CMD_S_HunNewStatusPlayRef_lAllJettonScore);
        tolua_function(tolua_S,"lEndUserReturnScore",lua_jt_game_CMD_S_HunNewStatusPlayRef_lEndUserReturnScore);
        tolua_function(tolua_S,"cbTimeLeave",lua_jt_game_CMD_S_HunNewStatusPlayRef_cbTimeLeave);
        tolua_function(tolua_S,"cbBankerTime",lua_jt_game_CMD_S_HunNewStatusPlayRef_cbBankerTime);
        tolua_function(tolua_S,"lUserMaxScore",lua_jt_game_CMD_S_HunNewStatusPlayRef_lUserMaxScore);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_S_HunNewStatusPlayRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_S_HunNewStatusPlayRef).name();
    g_luaType[typeName] = "CMD_S_HunNewStatusPlayRef";
    g_typeCast["CMD_S_HunNewStatusPlayRef"] = "CMD_S_HunNewStatusPlayRef";
    return 1;
}

int lua_jt_game_CMD_S_HunNewGameEndRef_getTagAwardFirst(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_getTagAwardFirst'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewGameEndRef_getTagAwardFirst'", nullptr);
            return 0;
        }
        tagAwardFirstRef* ret = cobj->getTagAwardFirst();
        object_to_luaval<tagAwardFirstRef>(tolua_S, "tagAwardFirstRef",(tagAwardFirstRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewGameEndRef:getTagAwardFirst",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_getTagAwardFirst'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewGameEndRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewGameEndRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_lRevenue(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_lRevenue'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewGameEndRef:lRevenue");

            if (!ok) { break; }
            cobj->lRevenue(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lRevenue();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewGameEndRef:lRevenue",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_lRevenue'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewGameEndRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewGameEndRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_bcFirstCard(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_bcFirstCard'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_S_HunNewGameEndRef:bcFirstCard");

            if (!ok) { break; }
            cobj->bcFirstCard(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->bcFirstCard();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewGameEndRef:bcFirstCard",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_bcFirstCard'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_gettagWinInfo(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_gettagWinInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_S_HunNewGameEndRef:gettagWinInfo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewGameEndRef_gettagWinInfo'", nullptr);
            return 0;
        }
        tagUserWLInfoRef* ret = cobj->gettagWinInfo(arg0);
        object_to_luaval<tagUserWLInfoRef>(tolua_S, "tagUserWLInfoRef",(tagUserWLInfoRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewGameEndRef:gettagWinInfo",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_gettagWinInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_lBankerScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_lBankerScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewGameEndRef:lBankerScore");

            if (!ok) { break; }
            cobj->lBankerScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lBankerScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewGameEndRef:lBankerScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_lBankerScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_settagLoseInfo(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_settagLoseInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        tagUserWLInfoRef* arg0;

        ok &= luaval_to_object<tagUserWLInfoRef>(tolua_S, 2, "tagUserWLInfoRef",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewGameEndRef_settagLoseInfo'", nullptr);
            return 0;
        }
        cobj->settagLoseInfo(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewGameEndRef:settagLoseInfo",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_settagLoseInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_cbTableCardArray(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_cbTableCardArray'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_S_HunNewGameEndRef:cbTableCardArray");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMD_S_HunNewGameEndRef:cbTableCardArray");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewGameEndRef_cbTableCardArray'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->cbTableCardArray(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewGameEndRef:cbTableCardArray",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_cbTableCardArray'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_nBankerTime(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_nBankerTime'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_S_HunNewGameEndRef:nBankerTime");

            if (!ok) { break; }
            cobj->nBankerTime(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            int ret = cobj->nBankerTime();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewGameEndRef:nBankerTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_nBankerTime'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_lStorageStart(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_lStorageStart'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewGameEndRef:lStorageStart");

            if (!ok) { break; }
            cobj->lStorageStart(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lStorageStart();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewGameEndRef:lStorageStart",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_lStorageStart'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_setTagAwardFirst(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_setTagAwardFirst'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        tagAwardFirstRef* arg0;

        ok &= luaval_to_object<tagAwardFirstRef>(tolua_S, 2, "tagAwardFirstRef",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewGameEndRef_setTagAwardFirst'", nullptr);
            return 0;
        }
        cobj->setTagAwardFirst(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewGameEndRef:setTagAwardFirst",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_setTagAwardFirst'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewGameEndRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewGameEndRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_initRef(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_initRef'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewGameEndRef_initRef'", nullptr);
            return 0;
        }
        cobj->initRef();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewGameEndRef:initRef",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_initRef'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_nRedPackage(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_nRedPackage'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMD_S_HunNewGameEndRef:nRedPackage");

            if (!ok) { break; }
            cobj->nRedPackage(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            int ret = cobj->nRedPackage();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewGameEndRef:nRedPackage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_nRedPackage'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_settagWinInfo(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_settagWinInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        tagUserWLInfoRef* arg0;
        int arg1;

        ok &= luaval_to_object<tagUserWLInfoRef>(tolua_S, 2, "tagUserWLInfoRef",&arg0);

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMD_S_HunNewGameEndRef:settagWinInfo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewGameEndRef_settagWinInfo'", nullptr);
            return 0;
        }
        cobj->settagWinInfo(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewGameEndRef:settagWinInfo",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_settagWinInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_gettagLoseInfo(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_gettagLoseInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewGameEndRef_gettagLoseInfo'", nullptr);
            return 0;
        }
        tagUserWLInfoRef* ret = cobj->gettagLoseInfo();
        object_to_luaval<tagUserWLInfoRef>(tolua_S, "tagUserWLInfoRef",(tagUserWLInfoRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewGameEndRef:gettagLoseInfo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_gettagLoseInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_lExtraScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_lExtraScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewGameEndRef:lExtraScore");

            if (!ok) { break; }
            cobj->lExtraScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lExtraScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewGameEndRef:lExtraScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_lExtraScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_lUserReturnScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_lUserReturnScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewGameEndRef:lUserReturnScore");

            if (!ok) { break; }
            cobj->lUserReturnScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lUserReturnScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewGameEndRef:lUserReturnScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_lUserReturnScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_lBankerTotallScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_lBankerTotallScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewGameEndRef:lBankerTotallScore");

            if (!ok) { break; }
            cobj->lBankerTotallScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lBankerTotallScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewGameEndRef:lBankerTotallScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_lBankerTotallScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_cbRedTimeLeave(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_cbRedTimeLeave'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_S_HunNewGameEndRef:cbRedTimeLeave");

            if (!ok) { break; }
            cobj->cbRedTimeLeave(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbRedTimeLeave();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewGameEndRef:cbRedTimeLeave",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_cbRedTimeLeave'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_cbLeftCardCount(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_cbLeftCardCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_S_HunNewGameEndRef:cbLeftCardCount");

            if (!ok) { break; }
            cobj->cbLeftCardCount(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbLeftCardCount();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewGameEndRef:cbLeftCardCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_cbLeftCardCount'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_lUserScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_lUserScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewGameEndRef:lUserScore");

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
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewGameEndRef:lUserScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_lUserScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_cbTimeLeave(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameEndRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewGameEndRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameEndRef_cbTimeLeave'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_S_HunNewGameEndRef:cbTimeLeave");

            if (!ok) { break; }
            cobj->cbTimeLeave(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbTimeLeave();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewGameEndRef:cbTimeLeave",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_cbTimeLeave'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameEndRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_S_HunNewGameEndRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewGameEndRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunNewGameEndRef* ret = CMD_S_HunNewGameEndRef::createWithNotify();
        object_to_luaval<CMD_S_HunNewGameEndRef>(tolua_S, "CMD_S_HunNewGameEndRef",(CMD_S_HunNewGameEndRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewGameEndRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunNewGameEndRef* ret = CMD_S_HunNewGameEndRef::createWithNotify(arg0);
        object_to_luaval<CMD_S_HunNewGameEndRef>(tolua_S, "CMD_S_HunNewGameEndRef",(CMD_S_HunNewGameEndRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_S_HunNewGameEndRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameEndRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_S_HunNewGameEndRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_S_HunNewGameEndRef)");
    return 0;
}

int lua_register_jt_game_CMD_S_HunNewGameEndRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_S_HunNewGameEndRef");
    tolua_cclass(tolua_S,"CMD_S_HunNewGameEndRef","CMD_S_HunNewGameEndRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_S_HunNewGameEndRef");
        tolua_function(tolua_S,"getTagAwardFirst",lua_jt_game_CMD_S_HunNewGameEndRef_getTagAwardFirst);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_S_HunNewGameEndRef_setStruct);
        tolua_function(tolua_S,"lRevenue",lua_jt_game_CMD_S_HunNewGameEndRef_lRevenue);
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_S_HunNewGameEndRef_getSize);
        tolua_function(tolua_S,"bcFirstCard",lua_jt_game_CMD_S_HunNewGameEndRef_bcFirstCard);
        tolua_function(tolua_S,"gettagWinInfo",lua_jt_game_CMD_S_HunNewGameEndRef_gettagWinInfo);
        tolua_function(tolua_S,"lBankerScore",lua_jt_game_CMD_S_HunNewGameEndRef_lBankerScore);
        tolua_function(tolua_S,"settagLoseInfo",lua_jt_game_CMD_S_HunNewGameEndRef_settagLoseInfo);
        tolua_function(tolua_S,"cbTableCardArray",lua_jt_game_CMD_S_HunNewGameEndRef_cbTableCardArray);
        tolua_function(tolua_S,"nBankerTime",lua_jt_game_CMD_S_HunNewGameEndRef_nBankerTime);
        tolua_function(tolua_S,"lStorageStart",lua_jt_game_CMD_S_HunNewGameEndRef_lStorageStart);
        tolua_function(tolua_S,"setTagAwardFirst",lua_jt_game_CMD_S_HunNewGameEndRef_setTagAwardFirst);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_S_HunNewGameEndRef_getData);
        tolua_function(tolua_S,"initRef",lua_jt_game_CMD_S_HunNewGameEndRef_initRef);
        tolua_function(tolua_S,"nRedPackage",lua_jt_game_CMD_S_HunNewGameEndRef_nRedPackage);
        tolua_function(tolua_S,"settagWinInfo",lua_jt_game_CMD_S_HunNewGameEndRef_settagWinInfo);
        tolua_function(tolua_S,"gettagLoseInfo",lua_jt_game_CMD_S_HunNewGameEndRef_gettagLoseInfo);
        tolua_function(tolua_S,"lExtraScore",lua_jt_game_CMD_S_HunNewGameEndRef_lExtraScore);
        tolua_function(tolua_S,"lUserReturnScore",lua_jt_game_CMD_S_HunNewGameEndRef_lUserReturnScore);
        tolua_function(tolua_S,"lBankerTotallScore",lua_jt_game_CMD_S_HunNewGameEndRef_lBankerTotallScore);
        tolua_function(tolua_S,"cbRedTimeLeave",lua_jt_game_CMD_S_HunNewGameEndRef_cbRedTimeLeave);
        tolua_function(tolua_S,"cbLeftCardCount",lua_jt_game_CMD_S_HunNewGameEndRef_cbLeftCardCount);
        tolua_function(tolua_S,"lUserScore",lua_jt_game_CMD_S_HunNewGameEndRef_lUserScore);
        tolua_function(tolua_S,"cbTimeLeave",lua_jt_game_CMD_S_HunNewGameEndRef_cbTimeLeave);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_S_HunNewGameEndRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_S_HunNewGameEndRef).name();
    g_luaType[typeName] = "CMD_S_HunNewGameEndRef";
    g_typeCast["CMD_S_HunNewGameEndRef"] = "CMD_S_HunNewGameEndRef";
    return 1;
}

int lua_jt_game_CMD_S_HunNewGameFreeRef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameFreeRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewGameFreeRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameFreeRef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewGameFreeRef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewGameFreeRef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameFreeRef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameFreeRef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameFreeRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewGameFreeRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameFreeRef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewGameFreeRef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewGameFreeRef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameFreeRef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameFreeRef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameFreeRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewGameFreeRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameFreeRef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewGameFreeRef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewGameFreeRef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameFreeRef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameFreeRef_cbTimeLeave(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewGameFreeRef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewGameFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewGameFreeRef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewGameFreeRef_cbTimeLeave'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            uint16_t arg0;
            ok &= luaval_to_uint16(tolua_S, 2,&arg0, "CMD_S_HunNewGameFreeRef:cbTimeLeave");

            if (!ok) { break; }
            cobj->cbTimeLeave(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            uint16_t ret = cobj->cbTimeLeave();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewGameFreeRef:cbTimeLeave",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameFreeRef_cbTimeLeave'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewGameFreeRef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_S_HunNewGameFreeRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewGameFreeRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunNewGameFreeRef* ret = CMD_S_HunNewGameFreeRef::createWithNotify();
        object_to_luaval<CMD_S_HunNewGameFreeRef>(tolua_S, "CMD_S_HunNewGameFreeRef",(CMD_S_HunNewGameFreeRef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewGameFreeRef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunNewGameFreeRef* ret = CMD_S_HunNewGameFreeRef::createWithNotify(arg0);
        object_to_luaval<CMD_S_HunNewGameFreeRef>(tolua_S, "CMD_S_HunNewGameFreeRef",(CMD_S_HunNewGameFreeRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_S_HunNewGameFreeRef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewGameFreeRef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_S_HunNewGameFreeRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_S_HunNewGameFreeRef)");
    return 0;
}

int lua_register_jt_game_CMD_S_HunNewGameFreeRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_S_HunNewGameFreeRef");
    tolua_cclass(tolua_S,"CMD_S_HunNewGameFreeRef","CMD_S_HunNewGameFreeRef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_S_HunNewGameFreeRef");
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_S_HunNewGameFreeRef_getSize);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_S_HunNewGameFreeRef_setStruct);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_S_HunNewGameFreeRef_getData);
        tolua_function(tolua_S,"cbTimeLeave",lua_jt_game_CMD_S_HunNewGameFreeRef_cbTimeLeave);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_S_HunNewGameFreeRef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_S_HunNewGameFreeRef).name();
    g_luaType[typeName] = "CMD_S_HunNewGameFreeRef";
    g_typeCast["CMD_S_HunNewGameFreeRef"] = "CMD_S_HunNewGameFreeRef";
    return 1;
}

int lua_jt_game_CMD_S_HunNewRED_PACKAGERef_getSize(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewRED_PACKAGERef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewRED_PACKAGERef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewRED_PACKAGERef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewRED_PACKAGERef_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewRED_PACKAGERef_getSize'", nullptr);
            return 0;
        }
        int ret = cobj->getSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewRED_PACKAGERef:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewRED_PACKAGERef_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewRED_PACKAGERef_setStruct(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewRED_PACKAGERef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewRED_PACKAGERef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewRED_PACKAGERef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewRED_PACKAGERef_setStruct'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewRED_PACKAGERef_setStruct'", nullptr);
            return 0;
        }
        cobj->setStruct(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewRED_PACKAGERef:setStruct",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewRED_PACKAGERef_setStruct'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewRED_PACKAGERef_getData(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewRED_PACKAGERef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewRED_PACKAGERef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMD_S_HunNewRED_PACKAGERef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewRED_PACKAGERef_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewRED_PACKAGERef_getData'", nullptr);
            return 0;
        }
        void* ret = cobj->getData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMD_S_HunNewRED_PACKAGERef:getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewRED_PACKAGERef_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewRED_PACKAGERef_lAwardScore(lua_State* tolua_S)
{
    int argc = 0;
    CMD_S_HunNewRED_PACKAGERef* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMD_S_HunNewRED_PACKAGERef",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CMD_S_HunNewRED_PACKAGERef*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_CMD_S_HunNewRED_PACKAGERef_lAwardScore'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "CMD_S_HunNewRED_PACKAGERef:lAwardScore");

            if (!ok) { break; }
            cobj->lAwardScore(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            long long ret = cobj->lAwardScore();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CMD_S_HunNewRED_PACKAGERef:lAwardScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewRED_PACKAGERef_lAwardScore'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_CMD_S_HunNewRED_PACKAGERef_createWithNotify(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMD_S_HunNewRED_PACKAGERef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewRED_PACKAGERef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunNewRED_PACKAGERef* ret = CMD_S_HunNewRED_PACKAGERef::createWithNotify();
        object_to_luaval<CMD_S_HunNewRED_PACKAGERef>(tolua_S, "CMD_S_HunNewRED_PACKAGERef",(CMD_S_HunNewRED_PACKAGERef*)ret);
        return 1;
    }
    if (argc == 1)
    {
        CNotify* arg0;
        ok &= luaval_to_object<CNotify>(tolua_S, 2, "CNotify",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_CMD_S_HunNewRED_PACKAGERef_createWithNotify'", nullptr);
            return 0;
        }
        CMD_S_HunNewRED_PACKAGERef* ret = CMD_S_HunNewRED_PACKAGERef::createWithNotify(arg0);
        object_to_luaval<CMD_S_HunNewRED_PACKAGERef>(tolua_S, "CMD_S_HunNewRED_PACKAGERef",(CMD_S_HunNewRED_PACKAGERef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMD_S_HunNewRED_PACKAGERef:createWithNotify",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_CMD_S_HunNewRED_PACKAGERef_createWithNotify'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_CMD_S_HunNewRED_PACKAGERef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMD_S_HunNewRED_PACKAGERef)");
    return 0;
}

int lua_register_jt_game_CMD_S_HunNewRED_PACKAGERef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMD_S_HunNewRED_PACKAGERef");
    tolua_cclass(tolua_S,"CMD_S_HunNewRED_PACKAGERef","CMD_S_HunNewRED_PACKAGERef","CMD_BASE",nullptr);

    tolua_beginmodule(tolua_S,"CMD_S_HunNewRED_PACKAGERef");
        tolua_function(tolua_S,"getSize",lua_jt_game_CMD_S_HunNewRED_PACKAGERef_getSize);
        tolua_function(tolua_S,"setStruct",lua_jt_game_CMD_S_HunNewRED_PACKAGERef_setStruct);
        tolua_function(tolua_S,"getData",lua_jt_game_CMD_S_HunNewRED_PACKAGERef_getData);
        tolua_function(tolua_S,"lAwardScore",lua_jt_game_CMD_S_HunNewRED_PACKAGERef_lAwardScore);
        tolua_function(tolua_S,"createWithNotify", lua_jt_game_CMD_S_HunNewRED_PACKAGERef_createWithNotify);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMD_S_HunNewRED_PACKAGERef).name();
    g_luaType[typeName] = "CMD_S_HunNewRED_PACKAGERef";
    g_typeCast["CMD_S_HunNewRED_PACKAGERef"] = "CMD_S_HunNewRED_PACKAGERef";
    return 1;
}

int lua_jt_game_GameLogicHunNewRef_getFirstCardData(lua_State* tolua_S)
{
    int argc = 0;
    GameLogicHunNewRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameLogicHunNewRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameLogicHunNewRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_GameLogicHunNewRef_getFirstCardData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "GameLogicHunNewRef:getFirstCardData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_GameLogicHunNewRef_getFirstCardData'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getFirstCardData(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameLogicHunNewRef:getFirstCardData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_GameLogicHunNewRef_getFirstCardData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_GameLogicHunNewRef_getNextCardData(lua_State* tolua_S)
{
    int argc = 0;
    GameLogicHunNewRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameLogicHunNewRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameLogicHunNewRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_GameLogicHunNewRef_getNextCardData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "GameLogicHunNewRef:getNextCardData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_GameLogicHunNewRef_getNextCardData'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getNextCardData(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameLogicHunNewRef:getNextCardData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_GameLogicHunNewRef_getNextCardData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_GameLogicHunNewRef_setNextCardData(lua_State* tolua_S)
{
    int argc = 0;
    GameLogicHunNewRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameLogicHunNewRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameLogicHunNewRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_GameLogicHunNewRef_setNextCardData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        uint16_t arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "GameLogicHunNewRef:setNextCardData");

        ok &= luaval_to_uint16(tolua_S, 3,&arg1, "GameLogicHunNewRef:setNextCardData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_GameLogicHunNewRef_setNextCardData'", nullptr);
            return 0;
        }
        cobj->setNextCardData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameLogicHunNewRef:setNextCardData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_GameLogicHunNewRef_setNextCardData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_GameLogicHunNewRef_getMultiple(lua_State* tolua_S)
{
    int argc = 0;
    GameLogicHunNewRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameLogicHunNewRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameLogicHunNewRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_GameLogicHunNewRef_getMultiple'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_GameLogicHunNewRef_getMultiple'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getMultiple();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameLogicHunNewRef:getMultiple",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_GameLogicHunNewRef_getMultiple'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_GameLogicHunNewRef_setFirstCardData(lua_State* tolua_S)
{
    int argc = 0;
    GameLogicHunNewRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameLogicHunNewRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameLogicHunNewRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_GameLogicHunNewRef_setFirstCardData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        uint16_t arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "GameLogicHunNewRef:setFirstCardData");

        ok &= luaval_to_uint16(tolua_S, 3,&arg1, "GameLogicHunNewRef:setFirstCardData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_GameLogicHunNewRef_setFirstCardData'", nullptr);
            return 0;
        }
        cobj->setFirstCardData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameLogicHunNewRef:setFirstCardData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_GameLogicHunNewRef_setFirstCardData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_GameLogicHunNewRef_init(lua_State* tolua_S)
{
    int argc = 0;
    GameLogicHunNewRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameLogicHunNewRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameLogicHunNewRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_GameLogicHunNewRef_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_GameLogicHunNewRef_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameLogicHunNewRef:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_GameLogicHunNewRef_init'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_GameLogicHunNewRef_CompareCard(lua_State* tolua_S)
{
    int argc = 0;
    GameLogicHunNewRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameLogicHunNewRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameLogicHunNewRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_GameLogicHunNewRef_CompareCard'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_GameLogicHunNewRef_CompareCard'", nullptr);
            return 0;
        }
        int ret = cobj->CompareCard();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameLogicHunNewRef:CompareCard",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_GameLogicHunNewRef_CompareCard'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_GameLogicHunNewRef_GetCardType(lua_State* tolua_S)
{
    int argc = 0;
    GameLogicHunNewRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameLogicHunNewRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameLogicHunNewRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_GameLogicHunNewRef_GetCardType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_GameLogicHunNewRef_GetCardType'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->GetCardType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GameLogicHunNewRef:GetCardType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_GameLogicHunNewRef_GetCardType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_GameLogicHunNewRef_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GameLogicHunNewRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_GameLogicHunNewRef_create'", nullptr);
            return 0;
        }
        GameLogicHunNewRef* ret = GameLogicHunNewRef::create();
        object_to_luaval<GameLogicHunNewRef>(tolua_S, "GameLogicHunNewRef",(GameLogicHunNewRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "GameLogicHunNewRef:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_GameLogicHunNewRef_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_GameLogicHunNewRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameLogicHunNewRef)");
    return 0;
}

int lua_register_jt_game_GameLogicHunNewRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"GameLogicHunNewRef");
    tolua_cclass(tolua_S,"GameLogicHunNewRef","GameLogicHunNewRef","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"GameLogicHunNewRef");
        tolua_function(tolua_S,"getFirstCardData",lua_jt_game_GameLogicHunNewRef_getFirstCardData);
        tolua_function(tolua_S,"getNextCardData",lua_jt_game_GameLogicHunNewRef_getNextCardData);
        tolua_function(tolua_S,"setNextCardData",lua_jt_game_GameLogicHunNewRef_setNextCardData);
        tolua_function(tolua_S,"getMultiple",lua_jt_game_GameLogicHunNewRef_getMultiple);
        tolua_function(tolua_S,"setFirstCardData",lua_jt_game_GameLogicHunNewRef_setFirstCardData);
        tolua_function(tolua_S,"init",lua_jt_game_GameLogicHunNewRef_init);
        tolua_function(tolua_S,"CompareCard",lua_jt_game_GameLogicHunNewRef_CompareCard);
        tolua_function(tolua_S,"GetCardType",lua_jt_game_GameLogicHunNewRef_GetCardType);
        tolua_function(tolua_S,"create", lua_jt_game_GameLogicHunNewRef_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GameLogicHunNewRef).name();
    g_luaType[typeName] = "GameLogicHunNewRef";
    g_typeCast["GameLogicHunNewRef"] = "GameLogicHunNewRef";
    return 1;
}

int lua_jt_game_VSGameLogicRef_getFirstCardData(lua_State* tolua_S)
{
    int argc = 0;
    VSGameLogicRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"VSGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (VSGameLogicRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_VSGameLogicRef_getFirstCardData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "VSGameLogicRef:getFirstCardData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_VSGameLogicRef_getFirstCardData'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getFirstCardData(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "VSGameLogicRef:getFirstCardData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_VSGameLogicRef_getFirstCardData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_VSGameLogicRef_getNextCardData(lua_State* tolua_S)
{
    int argc = 0;
    VSGameLogicRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"VSGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (VSGameLogicRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_VSGameLogicRef_getNextCardData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "VSGameLogicRef:getNextCardData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_VSGameLogicRef_getNextCardData'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getNextCardData(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "VSGameLogicRef:getNextCardData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_VSGameLogicRef_getNextCardData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_VSGameLogicRef_setNextCardData(lua_State* tolua_S)
{
    int argc = 0;
    VSGameLogicRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"VSGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (VSGameLogicRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_VSGameLogicRef_setNextCardData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        uint16_t arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "VSGameLogicRef:setNextCardData");

        ok &= luaval_to_uint16(tolua_S, 3,&arg1, "VSGameLogicRef:setNextCardData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_VSGameLogicRef_setNextCardData'", nullptr);
            return 0;
        }
        cobj->setNextCardData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "VSGameLogicRef:setNextCardData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_VSGameLogicRef_setNextCardData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_VSGameLogicRef_getMultiple(lua_State* tolua_S)
{
    int argc = 0;
    VSGameLogicRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"VSGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (VSGameLogicRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_VSGameLogicRef_getMultiple'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_VSGameLogicRef_getMultiple'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getMultiple();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "VSGameLogicRef:getMultiple",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_VSGameLogicRef_getMultiple'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_VSGameLogicRef_setFirstCardData(lua_State* tolua_S)
{
    int argc = 0;
    VSGameLogicRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"VSGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (VSGameLogicRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_VSGameLogicRef_setFirstCardData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        uint16_t arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "VSGameLogicRef:setFirstCardData");

        ok &= luaval_to_uint16(tolua_S, 3,&arg1, "VSGameLogicRef:setFirstCardData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_VSGameLogicRef_setFirstCardData'", nullptr);
            return 0;
        }
        cobj->setFirstCardData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "VSGameLogicRef:setFirstCardData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_VSGameLogicRef_setFirstCardData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_VSGameLogicRef_GetOxCard(lua_State* tolua_S)
{
    int argc = 0;
    VSGameLogicRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"VSGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (VSGameLogicRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_VSGameLogicRef_GetOxCard'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_VSGameLogicRef_GetOxCard'", nullptr);
            return 0;
        }
        bool ret = cobj->GetOxCard();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "VSGameLogicRef:GetOxCard",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_VSGameLogicRef_GetOxCard'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_VSGameLogicRef_init(lua_State* tolua_S)
{
    int argc = 0;
    VSGameLogicRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"VSGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (VSGameLogicRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_VSGameLogicRef_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_VSGameLogicRef_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "VSGameLogicRef:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_VSGameLogicRef_init'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_VSGameLogicRef_CompareCard(lua_State* tolua_S)
{
    int argc = 0;
    VSGameLogicRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"VSGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (VSGameLogicRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_VSGameLogicRef_CompareCard'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_VSGameLogicRef_CompareCard'", nullptr);
            return 0;
        }
        int ret = cobj->CompareCard();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "VSGameLogicRef:CompareCard",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_VSGameLogicRef_CompareCard'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_VSGameLogicRef_GetCardType(lua_State* tolua_S)
{
    int argc = 0;
    VSGameLogicRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"VSGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (VSGameLogicRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_VSGameLogicRef_GetCardType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_VSGameLogicRef_GetCardType'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->GetCardType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "VSGameLogicRef:GetCardType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_VSGameLogicRef_GetCardType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_VSGameLogicRef_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VSGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_VSGameLogicRef_create'", nullptr);
            return 0;
        }
        VSGameLogicRef* ret = VSGameLogicRef::create();
        object_to_luaval<VSGameLogicRef>(tolua_S, "VSGameLogicRef",(VSGameLogicRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VSGameLogicRef:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_VSGameLogicRef_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_VSGameLogicRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (VSGameLogicRef)");
    return 0;
}

int lua_register_jt_game_VSGameLogicRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"VSGameLogicRef");
    tolua_cclass(tolua_S,"VSGameLogicRef","VSGameLogicRef","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"VSGameLogicRef");
        tolua_function(tolua_S,"getFirstCardData",lua_jt_game_VSGameLogicRef_getFirstCardData);
        tolua_function(tolua_S,"getNextCardData",lua_jt_game_VSGameLogicRef_getNextCardData);
        tolua_function(tolua_S,"setNextCardData",lua_jt_game_VSGameLogicRef_setNextCardData);
        tolua_function(tolua_S,"getMultiple",lua_jt_game_VSGameLogicRef_getMultiple);
        tolua_function(tolua_S,"setFirstCardData",lua_jt_game_VSGameLogicRef_setFirstCardData);
        tolua_function(tolua_S,"GetOxCard",lua_jt_game_VSGameLogicRef_GetOxCard);
        tolua_function(tolua_S,"init",lua_jt_game_VSGameLogicRef_init);
        tolua_function(tolua_S,"CompareCard",lua_jt_game_VSGameLogicRef_CompareCard);
        tolua_function(tolua_S,"GetCardType",lua_jt_game_VSGameLogicRef_GetCardType);
        tolua_function(tolua_S,"create", lua_jt_game_VSGameLogicRef_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(VSGameLogicRef).name();
    g_luaType[typeName] = "VSGameLogicRef";
    g_typeCast["VSGameLogicRef"] = "VSGameLogicRef";
    return 1;
}

int lua_jt_game_KPQZGameLogicRef_getFirstCardData(lua_State* tolua_S)
{
    int argc = 0;
    KPQZGameLogicRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"KPQZGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (KPQZGameLogicRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_KPQZGameLogicRef_getFirstCardData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "KPQZGameLogicRef:getFirstCardData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_KPQZGameLogicRef_getFirstCardData'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getFirstCardData(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "KPQZGameLogicRef:getFirstCardData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_KPQZGameLogicRef_getFirstCardData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_KPQZGameLogicRef_getNextCardData(lua_State* tolua_S)
{
    int argc = 0;
    KPQZGameLogicRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"KPQZGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (KPQZGameLogicRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_KPQZGameLogicRef_getNextCardData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "KPQZGameLogicRef:getNextCardData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_KPQZGameLogicRef_getNextCardData'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getNextCardData(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "KPQZGameLogicRef:getNextCardData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_KPQZGameLogicRef_getNextCardData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_KPQZGameLogicRef_setNextCardData(lua_State* tolua_S)
{
    int argc = 0;
    KPQZGameLogicRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"KPQZGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (KPQZGameLogicRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_KPQZGameLogicRef_setNextCardData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        uint16_t arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "KPQZGameLogicRef:setNextCardData");

        ok &= luaval_to_uint16(tolua_S, 3,&arg1, "KPQZGameLogicRef:setNextCardData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_KPQZGameLogicRef_setNextCardData'", nullptr);
            return 0;
        }
        cobj->setNextCardData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "KPQZGameLogicRef:setNextCardData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_KPQZGameLogicRef_setNextCardData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_KPQZGameLogicRef_getMultiple(lua_State* tolua_S)
{
    int argc = 0;
    KPQZGameLogicRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"KPQZGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (KPQZGameLogicRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_KPQZGameLogicRef_getMultiple'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_KPQZGameLogicRef_getMultiple'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->getMultiple();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "KPQZGameLogicRef:getMultiple",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_KPQZGameLogicRef_getMultiple'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_KPQZGameLogicRef_setFirstCardData(lua_State* tolua_S)
{
    int argc = 0;
    KPQZGameLogicRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"KPQZGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (KPQZGameLogicRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_KPQZGameLogicRef_setFirstCardData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        uint16_t arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "KPQZGameLogicRef:setFirstCardData");

        ok &= luaval_to_uint16(tolua_S, 3,&arg1, "KPQZGameLogicRef:setFirstCardData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_KPQZGameLogicRef_setFirstCardData'", nullptr);
            return 0;
        }
        cobj->setFirstCardData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "KPQZGameLogicRef:setFirstCardData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_KPQZGameLogicRef_setFirstCardData'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_KPQZGameLogicRef_GetOxCard(lua_State* tolua_S)
{
    int argc = 0;
    KPQZGameLogicRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"KPQZGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (KPQZGameLogicRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_KPQZGameLogicRef_GetOxCard'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_KPQZGameLogicRef_GetOxCard'", nullptr);
            return 0;
        }
        bool ret = cobj->GetOxCard();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "KPQZGameLogicRef:GetOxCard",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_KPQZGameLogicRef_GetOxCard'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_KPQZGameLogicRef_init(lua_State* tolua_S)
{
    int argc = 0;
    KPQZGameLogicRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"KPQZGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (KPQZGameLogicRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_KPQZGameLogicRef_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_KPQZGameLogicRef_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "KPQZGameLogicRef:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_KPQZGameLogicRef_init'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_KPQZGameLogicRef_CompareCard(lua_State* tolua_S)
{
    int argc = 0;
    KPQZGameLogicRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"KPQZGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (KPQZGameLogicRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_KPQZGameLogicRef_CompareCard'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_KPQZGameLogicRef_CompareCard'", nullptr);
            return 0;
        }
        int ret = cobj->CompareCard();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "KPQZGameLogicRef:CompareCard",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_KPQZGameLogicRef_CompareCard'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_KPQZGameLogicRef_GetCardType(lua_State* tolua_S)
{
    int argc = 0;
    KPQZGameLogicRef* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"KPQZGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (KPQZGameLogicRef*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_game_KPQZGameLogicRef_GetCardType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_KPQZGameLogicRef_GetCardType'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->GetCardType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "KPQZGameLogicRef:GetCardType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_KPQZGameLogicRef_GetCardType'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_game_KPQZGameLogicRef_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"KPQZGameLogicRef",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_game_KPQZGameLogicRef_create'", nullptr);
            return 0;
        }
        KPQZGameLogicRef* ret = KPQZGameLogicRef::create();
        object_to_luaval<KPQZGameLogicRef>(tolua_S, "KPQZGameLogicRef",(KPQZGameLogicRef*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "KPQZGameLogicRef:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_game_KPQZGameLogicRef_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_game_KPQZGameLogicRef_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (KPQZGameLogicRef)");
    return 0;
}

int lua_register_jt_game_KPQZGameLogicRef(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"KPQZGameLogicRef");
    tolua_cclass(tolua_S,"KPQZGameLogicRef","KPQZGameLogicRef","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"KPQZGameLogicRef");
        tolua_function(tolua_S,"getFirstCardData",lua_jt_game_KPQZGameLogicRef_getFirstCardData);
        tolua_function(tolua_S,"getNextCardData",lua_jt_game_KPQZGameLogicRef_getNextCardData);
        tolua_function(tolua_S,"setNextCardData",lua_jt_game_KPQZGameLogicRef_setNextCardData);
        tolua_function(tolua_S,"getMultiple",lua_jt_game_KPQZGameLogicRef_getMultiple);
        tolua_function(tolua_S,"setFirstCardData",lua_jt_game_KPQZGameLogicRef_setFirstCardData);
        tolua_function(tolua_S,"GetOxCard",lua_jt_game_KPQZGameLogicRef_GetOxCard);
        tolua_function(tolua_S,"init",lua_jt_game_KPQZGameLogicRef_init);
        tolua_function(tolua_S,"CompareCard",lua_jt_game_KPQZGameLogicRef_CompareCard);
        tolua_function(tolua_S,"GetCardType",lua_jt_game_KPQZGameLogicRef_GetCardType);
        tolua_function(tolua_S,"create", lua_jt_game_KPQZGameLogicRef_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(KPQZGameLogicRef).name();
    g_luaType[typeName] = "KPQZGameLogicRef";
    g_typeCast["KPQZGameLogicRef"] = "KPQZGameLogicRef";
    return 1;
}
TOLUA_API int register_all_jt_game(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"jt",0);
	tolua_beginmodule(tolua_S,"jt");

	lua_register_jt_game_CMD_BASE(tolua_S);
	lua_register_jt_game_CMD_S_HunChangeBankerRef(tolua_S);
	lua_register_jt_game_CMD_S_HunPlaceJettonRef(tolua_S);
	lua_register_jt_game_CMD_S_HunGameFreeRef(tolua_S);
	lua_register_jt_game_CMD_S_HunCancelBankerRef(tolua_S);
	lua_register_jt_game_CMD_S_WLInfoRef(tolua_S);
	lua_register_jt_game_CMD_C_CancelSitRef(tolua_S);
	lua_register_jt_game_CMD_S_ApplySitRef(tolua_S);
	lua_register_jt_game_CMD_S_HunNewGameEndRef(tolua_S);
	lua_register_jt_game_tagAwardFirstRef(tolua_S);
	lua_register_jt_game_CMD_S_HunChangeUserScoreRef(tolua_S);
	lua_register_jt_game_VSGameLogicRef(tolua_S);
	lua_register_jt_game_CMD_S_HunApplyBankerRef(tolua_S);
	lua_register_jt_game_CMD_S_HunNewStatusFreeRef(tolua_S);
	lua_register_jt_game_CMD_S_HunStatusPlayRef(tolua_S);
	lua_register_jt_game_CMD_S_HunGameStartRef(tolua_S);
	lua_register_jt_game_CMD_S_HunStatusFreeRef(tolua_S);
	lua_register_jt_game_CMD_S_CancelSitRef(tolua_S);
	lua_register_jt_game_CMD_S_HunPlaceJettonFailRef(tolua_S);
	lua_register_jt_game_GameLogicHunNewRef(tolua_S);
	lua_register_jt_game_CMD_C_ApplySitRef(tolua_S);
	lua_register_jt_game_CMD_S_HunNewStatusPlayRef(tolua_S);
	lua_register_jt_game_tagServerGameRecordRef(tolua_S);
	lua_register_jt_game_tagUserWLInfoRef(tolua_S);
	lua_register_jt_game_CMD_S_HunGameEndRef(tolua_S);
	lua_register_jt_game_KPQZGameLogicRef(tolua_S);
	lua_register_jt_game_CMD_S_HunNewGameFreeRef(tolua_S);
	lua_register_jt_game_CMD_C_HunPlaceJettonRef(tolua_S);
	lua_register_jt_game_CMD_S_HunNewRED_PACKAGERef(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

