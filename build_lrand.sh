gcc -shared -o lrand.dll lua-5.3.5/src/lua53.dll mt19937-64.c lrand.c -Ilua-5.3.5/src

cp lrand.dll /d/Lua
