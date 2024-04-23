#include "lua_difflib.h"
#include "difflib.h"

static int string_sequence_ratio(lua_State* L) {
	std::string a = luaL_checkstring(L, 1);
	std::string b = luaL_checkstring(L, 2);

	auto matcher = difflib::MakeSequenceMatcher<>(a, b);
	double ratio = matcher.ratio();
	lua_pushnumber(L, ratio);
	return 1;
}

int luaopen_difflib(lua_State* L) {
	luaL_Reg reg[] = {
		{ "sequence_ratio", string_sequence_ratio },
		{ NULL, NULL }
	};

	lua_newtable(L);
	luaL_setfuncs(L, reg, 0);

	return 1;
}