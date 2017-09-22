/*
 * FileName : CCUMScoialSDK.h
 * Author   : hehonghui
 * Company  : umeng.com
 *
 */

#ifndef __CCUMLuaPush__
#define __CCUMLuaPush__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif


/**
 * Call this function can import the lua bindings for the mobclick module and start mobclick.
 * After registering, we could call the related mobclick code conveniently in the lua.
 */

int lua_register_umpush_module(lua_State* L);
#endif
