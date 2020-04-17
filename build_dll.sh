gcc -shared \
    -o lrand.dll \
    lrand.c \
    mt19937-64.c \
    -I./lua-5.1.5/src
