#ifndef __XLIBC_MEMPOOL_H__
#define __XLIBC_MEMPOOL_H__

#include <malloc.h>
#include <stddef.h>

typedef void* (*xlibc_alloc_func_t)(size_t size, void* arg);

static void* xlibc_default_alloc_func(size_t size, void* arg) {
    return malloc(size);
}

#endif