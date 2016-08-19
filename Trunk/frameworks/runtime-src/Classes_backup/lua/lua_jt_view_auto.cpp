#include "lua_jt_view_auto.hpp"
#include "CustomLabel.h"
#include "SpriteURL.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_jt_view_CustomLabel_createWithCharMap(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CustomLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        std::string arg0;
        int arg1;
        int arg2;
        int arg3;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CustomLabel:createWithCharMap");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CustomLabel:createWithCharMap");
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "CustomLabel:createWithCharMap");
        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "CustomLabel:createWithCharMap");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_view_CustomLabel_createWithCharMap'", nullptr);
            return 0;
        }
        cocos2d::Label* ret = CustomLabel::createWithCharMap(arg0, arg1, arg2, arg3);
        object_to_luaval<cocos2d::Label>(tolua_S, "cc.Label",(cocos2d::Label*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CustomLabel:createWithCharMap",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_view_CustomLabel_createWithCharMap'.",&tolua_err);
#endif
    return 0;
}
static int lua_jt_view_CustomLabel_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CustomLabel)");
    return 0;
}

int lua_register_jt_view_CustomLabel(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CustomLabel");
    tolua_cclass(tolua_S,"CustomLabel","CustomLabel","cc.Label",nullptr);

    tolua_beginmodule(tolua_S,"CustomLabel");
        tolua_function(tolua_S,"createWithCharMap", lua_jt_view_CustomLabel_createWithCharMap);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CustomLabel).name();
    g_luaType[typeName] = "CustomLabel";
    g_typeCast["CustomLabel"] = "CustomLabel";
    return 1;
}

int lua_jt_view_SpriteURL_getCachePath(lua_State* tolua_S)
{
    int argc = 0;
    SpriteURL* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteURL",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteURL*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_view_SpriteURL_getCachePath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Node* arg0;
        cocos2d::Value arg1;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);

        ok &= luaval_to_ccvalue(tolua_S, 3, &arg1, "SpriteURL:getCachePath");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_view_SpriteURL_getCachePath'", nullptr);
            return 0;
        }
        cobj->getCachePath(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteURL:getCachePath",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_view_SpriteURL_getCachePath'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_view_SpriteURL_createStorgePath(lua_State* tolua_S)
{
    int argc = 0;
    SpriteURL* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteURL",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteURL*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_view_SpriteURL_createStorgePath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_view_SpriteURL_createStorgePath'", nullptr);
            return 0;
        }
        cobj->createStorgePath();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteURL:createStorgePath",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_view_SpriteURL_createStorgePath'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_view_SpriteURL_getHttpPic(lua_State* tolua_S)
{
    int argc = 0;
    SpriteURL* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteURL",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteURL*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_jt_view_SpriteURL_getHttpPic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0, "SpriteURL:getHttpPic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_view_SpriteURL_getHttpPic'", nullptr);
            return 0;
        }
        cobj->getHttpPic(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteURL:getHttpPic",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_view_SpriteURL_getHttpPic'.",&tolua_err);
#endif

    return 0;
}
int lua_jt_view_SpriteURL_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteURL",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpriteURL:create");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "SpriteURL:create");
        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "SpriteURL:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_view_SpriteURL_create'", nullptr);
            return 0;
        }
        SpriteURL* ret = SpriteURL::create(arg0, arg1, arg2);
        object_to_luaval<SpriteURL>(tolua_S, "SpriteURL",(SpriteURL*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpriteURL:create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_jt_view_SpriteURL_create'.",&tolua_err);
#endif
    return 0;
}
int lua_jt_view_SpriteURL_constructor(lua_State* tolua_S)
{
    int argc = 0;
    SpriteURL* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpriteURL:SpriteURL");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "SpriteURL:SpriteURL");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "SpriteURL:SpriteURL");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_jt_view_SpriteURL_constructor'", nullptr);
            return 0;
        }
        cobj = new SpriteURL(arg0, arg1, arg2);
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"SpriteURL");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteURL:SpriteURL",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_jt_view_SpriteURL_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_jt_view_SpriteURL_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SpriteURL)");
    return 0;
}

int lua_register_jt_view_SpriteURL(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SpriteURL");
    tolua_cclass(tolua_S,"SpriteURL","SpriteURL","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"SpriteURL");
        tolua_function(tolua_S,"new",lua_jt_view_SpriteURL_constructor);
        tolua_function(tolua_S,"getCachePath",lua_jt_view_SpriteURL_getCachePath);
        tolua_function(tolua_S,"createStorgePath",lua_jt_view_SpriteURL_createStorgePath);
        tolua_function(tolua_S,"getHttpPic",lua_jt_view_SpriteURL_getHttpPic);
        tolua_function(tolua_S,"create", lua_jt_view_SpriteURL_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(SpriteURL).name();
    g_luaType[typeName] = "SpriteURL";
    g_typeCast["SpriteURL"] = "SpriteURL";
    return 1;
}
TOLUA_API int register_all_jt_view(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"jt",0);
	tolua_beginmodule(tolua_S,"jt");

	lua_register_jt_view_SpriteURL(tolua_S);
	lua_register_jt_view_CustomLabel(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

