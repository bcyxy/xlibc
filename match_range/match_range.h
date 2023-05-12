#ifndef __XLIBC_MATCH_RANGE__
#define __XLIBC_MATCH_RANGE__

#include "common.h"
#include <stdint.h>
#include <string.h>
#include "tree.h"

typedef struct range_table_s {
    size_t _key_size;
    uint8_t _part_num;
    uint32_t _range_num;
    range_node_t *_tree;
    uint32_t version;
} range_tab_t;

XLIBC_STATE create_range_table(range_tab_t** tab, size_t key_size, uint8_t part_num);

XLIBC_STATE destroy_range_table(range_tab_t* tab);

XLIBC_STATE add_range(
    range_tab_t* tab,
    uint32_t id,
    const uint8_t* from, size_t from_size,
    const uint8_t* to, size_t to_size);

XLIBC_STATE del_range(range_tab_t* tab, uint32_t id);

XLIBC_STATE match_ranges(
    range_tab_t* tab,
    const uint8_t* key, size_t key_size,
    uint32_t* range_ids, size_t range_ids_max);

#endif
