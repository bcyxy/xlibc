#include "xlibc_list.h"

xlibc_list_t* xlibc_list_create(size_t val_size, xlibc_alloc_func_t alloc_func) { }
int8_t xlibc_list_destroy(xlibc_list_t* list) { }
int8_t xlibc_list_insert_after(xlibc_list_t* list, xlibc_list_node_t* node, void* val) { }
int8_t xlibc_list_insert_before(xlibc_list_t* list, xlibc_list_node_t* node, void* val) { }
int8_t xlibc_list_del(xlibc_list_t* list, xlibc_list_node_t* node) { }
void* xlibc_list_pop_from_head(xlibc_list_t* list) { }
void* xlibc_list_pop_from_tail(xlibc_list_t* list) { }
