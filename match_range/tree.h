#ifndef __XLIBC_TREE__
#define __XLIBC_TREE__

#include <stddef.h>
#include <stdint.h>

typedef struct range_node_s {
    struct range_node_s* sub_nodes; // 数组指针，指向：range_node_s[X]
    size_t num;

    uint32_t ids[100];
    uint32_t cnt; // 范围内计数
    uint32_t version;
} range_node_t;

#endif