#ifndef ALLOC
#define ALLOC
#include <stdlib.h>
#include <err.h>

void *emalloc(size_t s);
void *ecalloc(size_t s, size_t t);

#endif /*ALLOC*/
