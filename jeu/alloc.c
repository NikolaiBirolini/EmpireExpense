#include "alloc.h"
void *emalloc(size_t s)
{
    void *p = malloc(s);
    if (p == NULL)
        err(-1,"no memory");
    return p;
}

void *ecalloc(size_t s, size_t t)
{
    void *p = calloc(s,t);
    if (p == 0)
        err(-1,"no memory");
    return p;
}

