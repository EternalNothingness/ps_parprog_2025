#include <stdint.h>

union {
    int32_t i;
    float f;
} c;

c.f = c1;
//flip MSB; note that INT32_MAX == 01...1
c.i = ~INT32_MAX ^ c.i 
float c2 = c.f;
