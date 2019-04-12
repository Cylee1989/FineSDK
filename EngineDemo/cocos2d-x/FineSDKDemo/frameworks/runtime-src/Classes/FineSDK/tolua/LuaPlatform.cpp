/*
** Lua binding: Platform
** Generated automatically by tolua++-1.0.92 on Tue Apr  2 11:12:42 2019.
*/

/****************************************************************************
 Copyright (c) 2011 cocos2d-x.org

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include <map>
#include <string>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "FineLuaLoader.h"
#include "cocos-ext.h"

#if COCOS_VERSION == 2
#include "CCLuaEngine.h"
#include "tolua_fix.h"
#else
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "scripting/lua-bindings/manual/CCLuaStack.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#endif

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace CocosDenshion;

/* Exported function */
TOLUA_API int  tolua_Platform_open (lua_State* tolua_S);

#include "Platform.h"

int _initCallBackHandler=0;
void initCallBack(const char* param){
    if (_initCallBackHandler) {
#if COCOS_VERSION == 2
CCLuaStack* m_stack = CCLuaEngine::defaultEngine()->getLuaStack();
#else
LuaStack* m_stack = LuaEngine::getInstance()->getLuaStack();
#endif
        m_stack->pushString(param);
        m_stack->executeFunctionByHandler(_initCallBackHandler, 1);
    }else{
    }
}

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CallBack");
 tolua_usertype(tolua_S,"Platform");
}

/* method: getInstance of class  Platform */
#ifndef TOLUA_DISABLE_tolua_Platform_Platform_getInstance00
static int tolua_Platform_Platform_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Platform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Platform* tolua_ret = (Platform*)  Platform::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Platform");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initSDK of class  Platform */
#ifndef TOLUA_DISABLE_tolua_Platform_Platform_initSDK00
static int tolua_Platform_Platform_initSDK00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Platform",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !toluafix_isfunction(tolua_S,3,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Platform* self = (Platform*)  tolua_tousertype(tolua_S,1,0);
  string jsonString = ((string)  tolua_tocppstring(tolua_S,2,0));
  CallBack initBack = *initCallBack;
  LUA_FUNCTION handler = (toluafix_ref_function(tolua_S,3,0));
  _initCallBackHandler = handler;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initSDK'", NULL);
#endif
  {
   self->initSDK(jsonString,initBack);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initSDK'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: callUniversalFunction of class  Platform */
#ifndef TOLUA_DISABLE_tolua_Platform_Platform_callUniversalFunction00
static int tolua_Platform_Platform_callUniversalFunction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Platform",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Platform* self = (Platform*)  tolua_tousertype(tolua_S,1,0);
  string functionName = ((string)  tolua_tocppstring(tolua_S,2,0));
  string jsonString = ((string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'callUniversalFunction'", NULL);
#endif
  {
   self->callUniversalFunction(functionName,jsonString);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'callUniversalFunction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Platform_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"Platform","Platform","",NULL);
  tolua_beginmodule(tolua_S,"Platform");
   tolua_function(tolua_S,"getInstance",tolua_Platform_Platform_getInstance00);
   tolua_function(tolua_S,"initSDK",tolua_Platform_Platform_initSDK00);
   tolua_function(tolua_S,"callUniversalFunction",tolua_Platform_Platform_callUniversalFunction00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Platform (lua_State* tolua_S) {
 return tolua_Platform_open(tolua_S);
};
#endif

