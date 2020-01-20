//
//  FineLuaLoader.h
//  FineSDK
//
//  Created by Cylee on 2019/4/1.
//  Copyright © 2019年 cylee. All rights reserved.
//

#ifndef FineLuaLoader_h
#define FineLuaLoader_h

#define COCOS_VERSION 3

#if COCOS_VERSION == 2
#include "CCLuaEngine.h"
#include "tolua++.h"
#else
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#endif

TOLUA_API int tolua_Platform_open (lua_State* tolua_S);

class FineLuaLoader {
    
public:
    static void loader(lua_State* tolua_S);
    
};

#endif /* FineLuaLoader_h */
