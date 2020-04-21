#include <stdio.h>
#include <string.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

static void stackDump(lua_State *L)
{
    int i;
    int top = lua_gettop(L);
    for(i = 1; i <= top; i++)
    {
        int t = lua_type(L, i);
        switch (t)
        {
        case LUA_TSTRING:
            printf("'%s'", lua_tostring(L, i));
            break;
        case LUA_TBOOLEAN:
            printf(lua_toboolean(L, i) ? "true" : "false");
            break;
        case LUA_TNUMBER:
            printf("%g", lua_tonumber(L, i));
            break;

        default:
            printf("%s", lua_typename(L, t));
            break;
        }

        printf("  ");
    }
    printf("\n");
}

int main(void) 
{
    char buff[256];
    int error;
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    lua_pushinteger(L, 1);
    lua_pushinteger(L, 2);
    lua_pushinteger(L, 3);
    stackDump(L);
    lua_insert(L, 1); // 将栈顶元素放在指定索引上，指定索引以上的元素上移
    stackDump(L);
    lua_replace(L, 1); // 将栈顶元素和指定索引上的元素交换，然后再弹出栈顶
    stackDump(L);
    printf("%d\n", lua_gettop(L));

    // while(fgets(buff, sizeof(buff), stdin) != NULL)
    // {
    //     error = luaL_loadbuffer(L, buff, strlen(buff), "line") || lua_pcall(L, 0, 0, 0);
    //     if(error) 
    //     {
    //         printf("%d\n", error);
    //         fprintf(stderr, "%s", lua_tostring(L, -1));
    //         lua_pop(L, 1);
    //     }
    // }

    lua_close(L);
    return 0;
}
