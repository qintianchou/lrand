#include "lua.h"
#include "lauxlib.h"

#define NAME "rand"
#define VERSION	"1.0.0"
#define META_TABLE_NAME "rand_state"
#define SEED 1UL

#include "mt19937ar.h"

static MT *Pget(lua_State *L, int i) 
{
    return luaL_checkudata(L, i, META_TABLE_NAME);
}

static MT *Pnew(lua_State *L) 
{
    MT *c= lua_newuserdata(L, sizeof(MT));
    luaL_getmetatable(L, META_TABLE_NAME);
    lua_setmetatable(L, -2);
    return c;
}

static int rand_new(lua_State *L) 
{
    lua_Integer seed = luaL_optinteger(L, 1, SEED);
    MT *c = Pnew(L);
    init_genrand(c, seed);
    return 1;
}

static int rand_next(lua_State *L) 
{
    MT *c = Pget(L, 1);
    lua_pushinteger(L, genrand_int32(c));
    return 1;
}

static const luaL_Reg R[] = 
{
    {"new", rand_new},
    {"next", rand_next},
    {NULL, NULL}
};

LUALIB_API int luaopen_rand(lua_State *L) 
{
    luaL_newmetatable(L, META_TABLE_NAME);
    luaL_setfuncs(L, R, 0);

    lua_pushliteral(L, "name");
    lua_pushliteral(L, NAME);
    lua_settable(L, -3);

    lua_pushliteral(L, "version");
    lua_pushliteral(L, VERSION);
    lua_settable(L, -3);

    lua_pushliteral(L, "__index");
    lua_pushvalue(L, -2);
    lua_settable(L, -3);

    return 1;
}
