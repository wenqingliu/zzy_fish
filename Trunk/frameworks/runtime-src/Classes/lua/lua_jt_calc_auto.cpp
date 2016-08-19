#include "lua_jt_calc_auto.hpp"
#include "CalcHelper.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_jt_calc_PosAngle_getX(lua_State* tolua_S)
{
    int argc = 0;
    PosAngle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PosAngle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PosAngle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_calc_PosAngle_getX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_calc_PosAngle_getX'", nullptr);
            return 0;
        }
        double ret = cobj->getX();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PosAngle:getX",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_calc_PosAngle_getX'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_calc_PosAngle_getY(lua_State* tolua_S)
{
    int argc = 0;
    PosAngle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PosAngle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PosAngle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_calc_PosAngle_getY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_calc_PosAngle_getY'", nullptr);
            return 0;
        }
        double ret = cobj->getY();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PosAngle:getY",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_calc_PosAngle_getY'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_calc_PosAngle_getAngle(lua_State* tolua_S)
{
    int argc = 0;
    PosAngle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"PosAngle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (PosAngle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_calc_PosAngle_getAngle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_calc_PosAngle_getAngle'", nullptr);
            return 0;
        }
        double ret = cobj->getAngle();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "PosAngle:getAngle",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_calc_PosAngle_getAngle'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_calc_PosAngle_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"PosAngle",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_calc_PosAngle_create'", nullptr);
            return 0;
        }
        PosAngle* ret = PosAngle::create();
        object_to_luaval<PosAngle>(tolua_S, "PosAngle",(PosAngle*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "PosAngle:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_calc_PosAngle_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_calc_PosAngle_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PosAngle)");
    return 0;
}

int lua_register_jt_calc_PosAngle(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"PosAngle");
    tolua_cclass(tolua_S,"PosAngle","PosAngle","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"PosAngle");
        tolua_function(tolua_S,"getX",lua_jt_calc_PosAngle_getX);
        tolua_function(tolua_S,"getY",lua_jt_calc_PosAngle_getY);
        tolua_function(tolua_S,"getAngle",lua_jt_calc_PosAngle_getAngle);
        tolua_function(tolua_S,"create", lua_jt_calc_PosAngle_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(PosAngle).name();
    g_luaType[typeName] = "PosAngle";
    g_typeCast["PosAngle"] = "PosAngle";
    return 1;
}

int lua_jt_calc_CalcHelperDelegate_onCalcBulletPos(lua_State* tolua_S)
{
    int argc = 0;
    CalcHelperDelegate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CalcHelperDelegate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CalcHelperDelegate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_calc_CalcHelperDelegate_onCalcBulletPos'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        PosAngle* arg0;

        ok &= luaval_to_object<PosAngle>(tolua_S, 2, "PosAngle",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_calc_CalcHelperDelegate_onCalcBulletPos'", nullptr);
            return 0;
        }
        cobj->onCalcBulletPos(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CalcHelperDelegate:onCalcBulletPos",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_calc_CalcHelperDelegate_onCalcBulletPos'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_calc_CalcHelperDelegate_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CalcHelperDelegate",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_calc_CalcHelperDelegate_create'", nullptr);
            return 0;
        }
        CalcHelperDelegate* ret = CalcHelperDelegate::create();
        object_to_luaval<CalcHelperDelegate>(tolua_S, "CalcHelperDelegate",(CalcHelperDelegate*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CalcHelperDelegate:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_calc_CalcHelperDelegate_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_calc_CalcHelperDelegate_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CalcHelperDelegate)");
    return 0;
}

int lua_register_jt_calc_CalcHelperDelegate(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CalcHelperDelegate");
    tolua_cclass(tolua_S,"CalcHelperDelegate","CalcHelperDelegate","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CalcHelperDelegate");
        tolua_function(tolua_S,"onCalcBulletPos",lua_jt_calc_CalcHelperDelegate_onCalcBulletPos);
        tolua_function(tolua_S,"create", lua_jt_calc_CalcHelperDelegate_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CalcHelperDelegate).name();
    g_luaType[typeName] = "CalcHelperDelegate";
    g_typeCast["CalcHelperDelegate"] = "CalcHelperDelegate";
    return 1;
}

int lua_jt_calc_CalcHelper_getDelegate(lua_State* tolua_S)
{
    int argc = 0;
    CalcHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CalcHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CalcHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_calc_CalcHelper_getDelegate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_calc_CalcHelper_getDelegate'", nullptr);
            return 0;
        }
        CalcHelperDelegate* ret = cobj->getDelegate();
        object_to_luaval<CalcHelperDelegate>(tolua_S, "CalcHelperDelegate",(CalcHelperDelegate*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CalcHelper:getDelegate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_calc_CalcHelper_getDelegate'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_calc_CalcHelper_setWinSize(lua_State* tolua_S)
{
    int argc = 0;
    CalcHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CalcHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CalcHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_calc_CalcHelper_setWinSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CalcHelper:setWinSize");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CalcHelper:setWinSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_calc_CalcHelper_setWinSize'", nullptr);
            return 0;
        }
        cobj->setWinSize(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CalcHelper:setWinSize",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_calc_CalcHelper_setWinSize'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_calc_CalcHelper_setDelegate(lua_State* tolua_S)
{
    int argc = 0;
    CalcHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CalcHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CalcHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_calc_CalcHelper_setDelegate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        CalcHelperDelegate* arg0;

        ok &= luaval_to_object<CalcHelperDelegate>(tolua_S, 2, "CalcHelperDelegate",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_calc_CalcHelper_setDelegate'", nullptr);
            return 0;
        }
        cobj->setDelegate(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CalcHelper:setDelegate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_calc_CalcHelper_setDelegate'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_calc_CalcHelper_nextBulletPos(lua_State* tolua_S)
{
    int argc = 0;
    CalcHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CalcHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CalcHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_calc_CalcHelper_nextBulletPos'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 5) 
    {
        double arg0;
        double arg1;
        double arg2;
        double arg3;
        int arg4;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "CalcHelper:nextBulletPos");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "CalcHelper:nextBulletPos");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "CalcHelper:nextBulletPos");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "CalcHelper:nextBulletPos");

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4, "CalcHelper:nextBulletPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_calc_CalcHelper_nextBulletPos'", nullptr);
            return 0;
        }
        cobj->nextBulletPos(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CalcHelper:nextBulletPos",argc, 5);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_calc_CalcHelper_nextBulletPos'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_calc_CalcHelper_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CalcHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_calc_CalcHelper_create'", nullptr);
            return 0;
        }
        CalcHelper* ret = CalcHelper::create();
        object_to_luaval<CalcHelper>(tolua_S, "CalcHelper",(CalcHelper*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CalcHelper:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_calc_CalcHelper_create'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_calc_CalcHelper_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CalcHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_calc_CalcHelper_constructor'", nullptr);
            return 0;
        }
        cobj = new CalcHelper();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CalcHelper");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CalcHelper:CalcHelper",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_jt_calc_CalcHelper_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_jt_calc_CalcHelper_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CalcHelper)");
    return 0;
}

int lua_register_jt_calc_CalcHelper(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CalcHelper");
    tolua_cclass(tolua_S,"CalcHelper","CalcHelper","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CalcHelper");
        tolua_function(tolua_S,"new",lua_jt_calc_CalcHelper_constructor);
        tolua_function(tolua_S,"getDelegate",lua_jt_calc_CalcHelper_getDelegate);
        tolua_function(tolua_S,"setWinSize",lua_jt_calc_CalcHelper_setWinSize);
        tolua_function(tolua_S,"setDelegate",lua_jt_calc_CalcHelper_setDelegate);
        tolua_function(tolua_S,"nextBulletPos",lua_jt_calc_CalcHelper_nextBulletPos);
        tolua_function(tolua_S,"create", lua_jt_calc_CalcHelper_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CalcHelper).name();
    g_luaType[typeName] = "CalcHelper";
    g_typeCast["CalcHelper"] = "CalcHelper";
    return 1;
}
TOLUA_API int register_all_jt_calc(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"jt",0);
	tolua_beginmodule(tolua_S,"jt");

	lua_register_jt_calc_CalcHelperDelegate(tolua_S);
	lua_register_jt_calc_PosAngle(tolua_S);
	lua_register_jt_calc_CalcHelper(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

