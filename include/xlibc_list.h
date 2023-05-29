/** Doubly linked list */

#ifndef __XLIBC_LIST_H__
#define __XLIBC_LIST_H__

#include <stdint.h>
#include <unistd.h>
#include "xlibc_common.h"
#include "xlibc_mempool.h"

typedef struct xlibc_list_node_s {
    struct xlibc_list_node_s* pre;
    struct xlibc_list_node_s* next;
    void* val;
} xlibc_list_node_t;

typedef struct {
    xlibc_list_node_t* head;
    size_t val_size;
    size_t list_len;
    xlibc_alloc_func_t alloc_func;
} xlibc_list_t;

//TODO free_func
XLIBC_STATE xlibc_list_create(xlibc_list_t** list, size_t val_size, xlibc_alloc_func_t alloc_func);
XLIBC_STATE xlibc_list_destroy(xlibc_list_t* list);
XLIBC_STATE xlibc_list_push_head(xlibc_list_t* list, void* val);
XLIBC_STATE xlibc_list_push_tail(xlibc_list_t* list, void* val);
XLIBC_STATE xlibc_list_insert_after(xlibc_list_t* list, xlibc_list_node_t* node, void* val);
XLIBC_STATE xlibc_list_del(xlibc_list_t* list, xlibc_list_node_t* node);

#endif
