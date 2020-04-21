#include "lua.h"

#define NN 312
#define MM 156
#define MATRIX_A 0xB5026F5AA96619E9ULL
#define UM 0xFFFFFFFF80000000ULL /* Most significant 33 bits */
#define LM 0x7FFFFFFFULL /* Least significant 31 bits */

#define mt	(o->v)
#define mti	(o->i)

typedef struct {
    unsigned long long v[NN];
    int i;
} MT;

void init_genrand64(MT *o, lua_Integer seed);
unsigned long long genrand64_int64(MT *o);
lua_Integer genrand64_int63(MT *o);
lua_Number genrand64_real1(MT *o);
lua_Number genrand64_real2(MT *o);
lua_Number genrand64_real3(MT *o);

