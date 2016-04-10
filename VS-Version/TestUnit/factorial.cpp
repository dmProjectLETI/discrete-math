#include "factorial.h"

unsigned factorial(unsigned n)
{
    unsigned res = 1;

    for(int i = 2; i <= n; i++)
        res *= i;

    return res;
}
