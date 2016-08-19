#include "lua_ens_effnode_auto.hpp"
#include "ensRippleNode.h"
#include "ensLightningBoltNode.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_ens_effnode_CrippleSprite_setIsDrawDebug(lua_State* tolua_S)
{
    int argc = 0;
    ens::CrippleSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ens.CrippleSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::CrippleSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ens_effnode_CrippleSprite_setIsDrawDebug'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "ens.CrippleSprite:setIsDrawDebug");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_CrippleSprite_setIsDrawDebug'", nullptr);
            return 0;
        }
        cobj->setIsDrawDebug(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.CrippleSprite:setIsDrawDebug",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_CrippleSprite_setIsDrawDebug'.",&tolua_err);
#endif

    return 0;
}
int lua_ens_effnode_CrippleSprite_draw(lua_State* tolua_S)
{
    int argc = 0;
    ens::CrippleSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ens.CrippleSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::CrippleSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ens_effnode_CrippleSprite_draw'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        cocos2d::Mat4 arg1;
        unsigned int arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0);

        ok &= luaval_to_mat4(tolua_S, 3, &arg1, "ens.CrippleSprite:draw");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "ens.CrippleSprite:draw");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_CrippleSprite_draw'", nullptr);
            return 0;
        }
        cobj->draw(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.CrippleSprite:draw",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_CrippleSprite_draw'.",&tolua_err);
#endif

    return 0;
}
int lua_ens_effnode_CrippleSprite_onDraw(lua_State* tolua_S)
{
    int argc = 0;
    ens::CrippleSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ens.CrippleSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::CrippleSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ens_effnode_CrippleSprite_onDraw'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Mat4 arg0;
        unsigned int arg1;

        ok &= luaval_to_mat4(tolua_S, 2, &arg0, "ens.CrippleSprite:onDraw");

        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "ens.CrippleSprite:onDraw");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_CrippleSprite_onDraw'", nullptr);
            return 0;
        }
        cobj->onDraw(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.CrippleSprite:onDraw",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_CrippleSprite_onDraw'.",&tolua_err);
#endif

    return 0;
}
int lua_ens_effnode_CrippleSprite_update(lua_State* tolua_S)
{
    int argc = 0;
    ens::CrippleSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ens.CrippleSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::CrippleSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ens_effnode_CrippleSprite_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "ens.CrippleSprite:update");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_CrippleSprite_update'", nullptr);
            return 0;
        }
        cobj->update(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.CrippleSprite:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_CrippleSprite_update'.",&tolua_err);
#endif

    return 0;
}
int lua_ens_effnode_CrippleSprite_init(lua_State* tolua_S)
{
    int argc = 0;
    ens::CrippleSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ens.CrippleSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::CrippleSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ens_effnode_CrippleSprite_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "ens.CrippleSprite:init");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "ens.CrippleSprite:init");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_CrippleSprite_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.CrippleSprite:init",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_CrippleSprite_init'.",&tolua_err);
#endif

    return 0;
}
int lua_ens_effnode_CrippleSprite_doTouch(lua_State* tolua_S)
{
    int argc = 0;
    ens::CrippleSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ens.CrippleSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::CrippleSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ens_effnode_CrippleSprite_doTouch'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Vec2 arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "ens.CrippleSprite:doTouch");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "ens.CrippleSprite:doTouch");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "ens.CrippleSprite:doTouch");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_CrippleSprite_doTouch'", nullptr);
            return 0;
        }
        cobj->doTouch(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.CrippleSprite:doTouch",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_CrippleSprite_doTouch'.",&tolua_err);
#endif

    return 0;
}
int lua_ens_effnode_CrippleSprite_getIsDrawDebug(lua_State* tolua_S)
{
    int argc = 0;
    ens::CrippleSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ens.CrippleSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::CrippleSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ens_effnode_CrippleSprite_getIsDrawDebug'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_CrippleSprite_getIsDrawDebug'", nullptr);
            return 0;
        }
        bool ret = cobj->getIsDrawDebug();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.CrippleSprite:getIsDrawDebug",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_CrippleSprite_getIsDrawDebug'.",&tolua_err);
#endif

    return 0;
}
int lua_ens_effnode_CrippleSprite_onDrawDebug(lua_State* tolua_S)
{
    int argc = 0;
    ens::CrippleSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ens.CrippleSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::CrippleSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ens_effnode_CrippleSprite_onDrawDebug'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Mat4 arg0;
        unsigned int arg1;

        ok &= luaval_to_mat4(tolua_S, 2, &arg0, "ens.CrippleSprite:onDrawDebug");

        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "ens.CrippleSprite:onDrawDebug");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_CrippleSprite_onDrawDebug'", nullptr);
            return 0;
        }
        cobj->onDrawDebug(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.CrippleSprite:onDrawDebug",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_CrippleSprite_onDrawDebug'.",&tolua_err);
#endif

    return 0;
}
int lua_ens_effnode_CrippleSprite_getGridSideLen(lua_State* tolua_S)
{
    int argc = 0;
    ens::CrippleSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ens.CrippleSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::CrippleSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ens_effnode_CrippleSprite_getGridSideLen'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_CrippleSprite_getGridSideLen'", nullptr);
            return 0;
        }
        double ret = cobj->getGridSideLen();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.CrippleSprite:getGridSideLen",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_CrippleSprite_getGridSideLen'.",&tolua_err);
#endif

    return 0;
}
int lua_ens_effnode_CrippleSprite_constructor(lua_State* tolua_S)
{
    int argc = 0;
    ens::CrippleSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_CrippleSprite_constructor'", nullptr);
            return 0;
        }
        cobj = new ens::CrippleSprite();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"ens.CrippleSprite");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.CrippleSprite:CrippleSprite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_CrippleSprite_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_ens_effnode_CrippleSprite_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CrippleSprite)");
    return 0;
}

int lua_register_ens_effnode_CrippleSprite(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ens.CrippleSprite");
    tolua_cclass(tolua_S,"CrippleSprite","ens.CrippleSprite","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"CrippleSprite");
        tolua_function(tolua_S,"new",lua_ens_effnode_CrippleSprite_constructor);
        tolua_function(tolua_S,"setIsDrawDebug",lua_ens_effnode_CrippleSprite_setIsDrawDebug);
        tolua_function(tolua_S,"draw",lua_ens_effnode_CrippleSprite_draw);
        tolua_function(tolua_S,"onDraw",lua_ens_effnode_CrippleSprite_onDraw);
        tolua_function(tolua_S,"update",lua_ens_effnode_CrippleSprite_update);
        tolua_function(tolua_S,"init",lua_ens_effnode_CrippleSprite_init);
        tolua_function(tolua_S,"doTouch",lua_ens_effnode_CrippleSprite_doTouch);
        tolua_function(tolua_S,"getIsDrawDebug",lua_ens_effnode_CrippleSprite_getIsDrawDebug);
        tolua_function(tolua_S,"onDrawDebug",lua_ens_effnode_CrippleSprite_onDrawDebug);
        tolua_function(tolua_S,"getGridSideLen",lua_ens_effnode_CrippleSprite_getGridSideLen);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(ens::CrippleSprite).name();
    g_luaType[typeName] = "ens.CrippleSprite";
    g_typeCast["CrippleSprite"] = "ens.CrippleSprite";
    return 1;
}

int lua_ens_effnode_ClightningBoltNode_setIsDrawDebug(lua_State* tolua_S)
{
    int argc = 0;
    ens::ClightningBoltNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ens.ClightningBoltNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::ClightningBoltNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ens_effnode_ClightningBoltNode_setIsDrawDebug'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "ens.ClightningBoltNode:setIsDrawDebug");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_ClightningBoltNode_setIsDrawDebug'", nullptr);
            return 0;
        }
        cobj->setIsDrawDebug(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.ClightningBoltNode:setIsDrawDebug",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_ClightningBoltNode_setIsDrawDebug'.",&tolua_err);
#endif

    return 0;
}
int lua_ens_effnode_ClightningBoltNode_runFlashAction(lua_State* tolua_S)
{
    int argc = 0;
    ens::ClightningBoltNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ens.ClightningBoltNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::ClightningBoltNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ens_effnode_ClightningBoltNode_runFlashAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_ClightningBoltNode_runFlashAction'", nullptr);
            return 0;
        }
        cobj->runFlashAction();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.ClightningBoltNode:runFlashAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_ClightningBoltNode_runFlashAction'.",&tolua_err);
#endif

    return 0;
}
int lua_ens_effnode_ClightningBoltNode_setStartAndEnd(lua_State* tolua_S)
{
    int argc = 0;
    ens::ClightningBoltNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ens.ClightningBoltNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::ClightningBoltNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ens_effnode_ClightningBoltNode_setStartAndEnd'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Vec2 arg0;
        cocos2d::Vec2 arg1;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "ens.ClightningBoltNode:setStartAndEnd");

        ok &= luaval_to_vec2(tolua_S, 3, &arg1, "ens.ClightningBoltNode:setStartAndEnd");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_ClightningBoltNode_setStartAndEnd'", nullptr);
            return 0;
        }
        cobj->setStartAndEnd(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.ClightningBoltNode:setStartAndEnd",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_ClightningBoltNode_setStartAndEnd'.",&tolua_err);
#endif

    return 0;
}
int lua_ens_effnode_ClightningBoltNode_getLBSprite2(lua_State* tolua_S)
{
    int argc = 0;
    ens::ClightningBoltNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ens.ClightningBoltNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::ClightningBoltNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ens_effnode_ClightningBoltNode_getLBSprite2'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_ClightningBoltNode_getLBSprite2'", nullptr);
            return 0;
        }
        ens::ClightningBoltSprite* ret = cobj->getLBSprite2();
        object_to_luaval<ens::ClightningBoltSprite>(tolua_S, "ens.ClightningBoltSprite",(ens::ClightningBoltSprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.ClightningBoltNode:getLBSprite2",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_ClightningBoltNode_getLBSprite2'.",&tolua_err);
#endif

    return 0;
}
int lua_ens_effnode_ClightningBoltNode_getLBSprite1(lua_State* tolua_S)
{
    int argc = 0;
    ens::ClightningBoltNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ens.ClightningBoltNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::ClightningBoltNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ens_effnode_ClightningBoltNode_getLBSprite1'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_ClightningBoltNode_getLBSprite1'", nullptr);
            return 0;
        }
        ens::ClightningBoltSprite* ret = cobj->getLBSprite1();
        object_to_luaval<ens::ClightningBoltSprite>(tolua_S, "ens.ClightningBoltSprite",(ens::ClightningBoltSprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.ClightningBoltNode:getLBSprite1",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_ClightningBoltNode_getLBSprite1'.",&tolua_err);
#endif

    return 0;
}
int lua_ens_effnode_ClightningBoltNode_runFlashActionOnce(lua_State* tolua_S)
{
    int argc = 0;
    ens::ClightningBoltNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ens.ClightningBoltNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::ClightningBoltNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ens_effnode_ClightningBoltNode_runFlashActionOnce'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_ClightningBoltNode_runFlashActionOnce'", nullptr);
            return 0;
        }
        cobj->runFlashActionOnce();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.ClightningBoltNode:runFlashActionOnce",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_ClightningBoltNode_runFlashActionOnce'.",&tolua_err);
#endif

    return 0;
}
int lua_ens_effnode_ClightningBoltNode_getStart(lua_State* tolua_S)
{
    int argc = 0;
    ens::ClightningBoltNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ens.ClightningBoltNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::ClightningBoltNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ens_effnode_ClightningBoltNode_getStart'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_ClightningBoltNode_getStart'", nullptr);
            return 0;
        }
        cocos2d::Vec2 ret = cobj->getStart();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.ClightningBoltNode:getStart",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_ClightningBoltNode_getStart'.",&tolua_err);
#endif

    return 0;
}
int lua_ens_effnode_ClightningBoltNode_init(lua_State* tolua_S)
{
    int argc = 0;
    ens::ClightningBoltNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ens.ClightningBoltNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::ClightningBoltNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ens_effnode_ClightningBoltNode_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        cocos2d::Vec2 arg1;
        cocos2d::Vec2 arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "ens.ClightningBoltNode:init");

        ok &= luaval_to_vec2(tolua_S, 3, &arg1, "ens.ClightningBoltNode:init");

        ok &= luaval_to_vec2(tolua_S, 4, &arg2, "ens.ClightningBoltNode:init");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_ClightningBoltNode_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.ClightningBoltNode:init",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_ClightningBoltNode_init'.",&tolua_err);
#endif

    return 0;
}
int lua_ens_effnode_ClightningBoltNode_getIsDrawDebug(lua_State* tolua_S)
{
    int argc = 0;
    ens::ClightningBoltNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ens.ClightningBoltNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::ClightningBoltNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ens_effnode_ClightningBoltNode_getIsDrawDebug'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_ClightningBoltNode_getIsDrawDebug'", nullptr);
            return 0;
        }
        bool ret = cobj->getIsDrawDebug();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.ClightningBoltNode:getIsDrawDebug",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_ClightningBoltNode_getIsDrawDebug'.",&tolua_err);
#endif

    return 0;
}
int lua_ens_effnode_ClightningBoltNode_getEnd(lua_State* tolua_S)
{
    int argc = 0;
    ens::ClightningBoltNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ens.ClightningBoltNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ens::ClightningBoltNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ens_effnode_ClightningBoltNode_getEnd'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_ClightningBoltNode_getEnd'", nullptr);
            return 0;
        }
        cocos2d::Vec2 ret = cobj->getEnd();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.ClightningBoltNode:getEnd",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_ClightningBoltNode_getEnd'.",&tolua_err);
#endif

    return 0;
}
int lua_ens_effnode_ClightningBoltNode_constructor(lua_State* tolua_S)
{
    int argc = 0;
    ens::ClightningBoltNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ens_effnode_ClightningBoltNode_constructor'", nullptr);
            return 0;
        }
        cobj = new ens::ClightningBoltNode();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"ens.ClightningBoltNode");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ens.ClightningBoltNode:ClightningBoltNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_ens_effnode_ClightningBoltNode_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_ens_effnode_ClightningBoltNode_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ClightningBoltNode)");
    return 0;
}

int lua_register_ens_effnode_ClightningBoltNode(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ens.ClightningBoltNode");
    tolua_cclass(tolua_S,"ClightningBoltNode","ens.ClightningBoltNode","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"ClightningBoltNode");
        tolua_function(tolua_S,"new",lua_ens_effnode_ClightningBoltNode_constructor);
        tolua_function(tolua_S,"setIsDrawDebug",lua_ens_effnode_ClightningBoltNode_setIsDrawDebug);
        tolua_function(tolua_S,"runFlashAction",lua_ens_effnode_ClightningBoltNode_runFlashAction);
        tolua_function(tolua_S,"setStartAndEnd",lua_ens_effnode_ClightningBoltNode_setStartAndEnd);
        tolua_function(tolua_S,"getLBSprite2",lua_ens_effnode_ClightningBoltNode_getLBSprite2);
        tolua_function(tolua_S,"getLBSprite1",lua_ens_effnode_ClightningBoltNode_getLBSprite1);
        tolua_function(tolua_S,"runFlashActionOnce",lua_ens_effnode_ClightningBoltNode_runFlashActionOnce);
        tolua_function(tolua_S,"getStart",lua_ens_effnode_ClightningBoltNode_getStart);
        tolua_function(tolua_S,"init",lua_ens_effnode_ClightningBoltNode_init);
        tolua_function(tolua_S,"getIsDrawDebug",lua_ens_effnode_ClightningBoltNode_getIsDrawDebug);
        tolua_function(tolua_S,"getEnd",lua_ens_effnode_ClightningBoltNode_getEnd);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(ens::ClightningBoltNode).name();
    g_luaType[typeName] = "ens.ClightningBoltNode";
    g_typeCast["ClightningBoltNode"] = "ens.ClightningBoltNode";
    return 1;
}
TOLUA_API int register_all_ens_effnode(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ens",0);
	tolua_beginmodule(tolua_S,"ens");

	lua_register_ens_effnode_ClightningBoltNode(tolua_S);
	lua_register_ens_effnode_CrippleSprite(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

