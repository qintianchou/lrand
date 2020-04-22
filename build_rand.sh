gcc -shared \
    -o rand.dll \
    luajit-2.1/src/lua51.dll \
    rand.c \
    mt19937ar.c \
    -I./luajit-2.1/src

cp rand.dll /usr/local/bin

luajit test2.lua
