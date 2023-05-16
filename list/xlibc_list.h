/** Doubly linked list */

#ifndef __XLIBC_LIST_H__
#define __XLIBC_LIST_H__

#include "xlibc_mempool.h"
#include <stdint.h>
#include <unistd.h>

typedef struct xlibc_list_node_s {
    struct xlibc_list_node_s* pre;
    struct xlibc_list_node_s* next;
    uint8_t val[0];
} xlibc_list_node_t;

/** Doubly linked list */
typedef struct {
    // structure:
    // head      tail end
    // │           │  │
    // O──O──O──O──O──O┐
    // └───────────────┘
    xlibc_list_node_t* head;
    xlibc_list_node_t* tail;
    xlibc_list_node_t end;

    xlibc_alloc_func_t alloc_func;
} xlibc_list_t;

xlibc_list_t* xlibc_list_create(size_t val_size, xlibc_alloc_func_t alloc_func);
int8_t xlibc_list_destroy(xlibc_list_t* list);
int8_t xlibc_list_insert_after(xlibc_list_t* list, xlibc_list_node_t* node, void* val);
int8_t xlibc_list_insert_before(xlibc_list_t* list, xlibc_list_node_t* node, void* val);
int8_t xlibc_list_del(xlibc_list_t* list, xlibc_list_node_t* node);
void* xlibc_list_pop_from_head(xlibc_list_t* list);
void* xlibc_list_pop_from_tail(xlibc_list_t* list);

#endif
