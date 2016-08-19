#ifndef __LUA_TEMPLATE_RUNTIME_FRAMEWORKS_RUNTIME_SRC_CLASSES_LUA_MODULE_REGISTER_H__
#define __LUA_TEMPLATE_RUNTIME_FRAMEWORKS_RUNTIME_SRC_CLASSES_LUA_MODULE_REGISTER_H__

#include "cocosdenshion/lua_cocos2dx_cocosdenshion_manual.h"
#include "network/lua_cocos2dx_network_manual.h"
#include "cocostudio/lua_cocos2dx_coco_studio_manual.hpp"
#include "extension/lua_cocos2dx_extension_manual.h"
#include "ui/lua_cocos2dx_ui_manual.hpp"
#include "3d/lua_cocos2dx_3d_manual.h"
#include "audioengine/lua_cocos2dx_audioengine_manual.h"
#include "lua/quick/lua_cocos2dx_quick_manual.hpp"

#include "lua_jt_cmd_auto.hpp"
#include "lua_jt_net_auto.hpp"
#include "lua_jt_http_auto.hpp"
#include "lua_jt_game_auto.hpp"
#include "lua_jt_view_auto.hpp"
#include "lua_jt_sdk_auto.hpp"
#include "lua_jt_update_auto.hpp"
#include "lua_jt_fish_auto.hpp"

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include "quick-src/lua_extensions/lua_extensions_more.h"
#endif

int lua_module_register(lua_State* L)
{
    //Dont' change the module register order unless you know what your are doing
    register_cocosdenshion_module(L);
    register_network_module(L);
    register_cocostudio_module(L);
    register_ui_moudle(L);
    register_extension_module(L);
    register_cocos3d_module(L);
    register_audioengine_module(L);
    
    register_all_jt_net(L);
    register_all_jt_http(L);
    register_all_jt_cmd(L);
    register_all_jt_game(L);
    register_all_jt_view(L);
    register_all_jt_sdk(L);
	register_all_jt_update(L);
	register_all_jt_fish(L);
	
	#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
		luaopen_lua_extensions_more(L);//CJSON
	#endif

    return 1;
}

#endif  // __LUA_TEMPLATE_RUNTIME_FRAMEWORKS_RUNTIME_SRC_CLASSES_LUA_MODULE_REGISTER_H__

