//
//  FineLuaLoader.cpp
//  FineSDK
//
//  Created by Cylee on 2019/4/1.
//  Copyright © 2019年 cylee. All rights reserved.
//

#include "FineLuaLoader.h"

void FineLuaLoader::loader(lua_State* tolua_S) {
    tolua_Platform_open(tolua_S);
}
