#include "xlibc_mempool.h"

void* xlibc_default_alloc_func(size_t size, void* arg)
{
    return malloc(size);
}
