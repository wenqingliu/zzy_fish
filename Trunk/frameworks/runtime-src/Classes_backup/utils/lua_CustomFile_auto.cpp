#include "lua_CustomFile_auto.hpp"
#include "CustomFile.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_CustomFile_CustomFile_writeFile(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CustomFile",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        ok &= luaval_to_std_string(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        bool ret = CustomFile::writeFile(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "writeFile",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_CustomFile_CustomFile_writeFile'.",&tolua_err);
#endif
    return 0;
}
int lua_CustomFile_CustomFile_createDirectory(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CustomFile",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        bool ret = CustomFile::createDirectory(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createDirectory",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_CustomFile_CustomFile_createDirectory'.",&tolua_err);
#endif
    return 0;
}
static int lua_CustomFile_CustomFile_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CustomFile)");
    return 0;
}

int lua_register_CustomFile_CustomFile(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CustomFile");
    tolua_cclass(tolua_S,"CustomFile","CustomFile","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CustomFile");
        tolua_function(tolua_S,"writeFile", lua_CustomFile_CustomFile_writeFile);
        tolua_function(tolua_S,"createDirectory", lua_CustomFile_CustomFile_createDirectory);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CustomFile).name();
    g_luaType[typeName] = "CustomFile";
    g_typeCast["CustomFile"] = "CustomFile";
    return 1;
}
TOLUA_API int register_all_CustomFile(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"my",0);
	tolua_beginmodule(tolua_S,"my");

	lua_register_CustomFile_CustomFile(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

