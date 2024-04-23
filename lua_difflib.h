#pragma once

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#ifdef _MSC_VER
	_declspec(dllexport) int luaopen_difflib(lua_State* L);
#else 
	extern int luaopen_difflib(lua_State* L);
#endif

#if !defined LUA_VERSION_NUM || LUA_VERSION_NUM==501
	/*
	** Adapted from Lua 5.2.0
	*/
	void luaL_setfuncs(lua_State* L, const luaL_Reg* l, int nup) {
		luaL_checkstack(L, nup + 1, "too many upvalues");
		for (; l->name != NULL; l++) {  /* fill the table with given functions */
			int i;
			lua_pushstring(L, l->name);
			for (i = 0; i < nup; i++)  /* copy upvalues to the top */
				lua_pushvalue(L, -(nup + 1));
			lua_pushcclosure(L, l->func, nup);  /* closure with those upvalues */
			lua_settable(L, -(nup + 3)); /* table must be below the upvalues, the name and the closure */
		}
		lua_pop(L, nup);  /* remove upvalues */
	}
#endif

}

#include "difflib.h"