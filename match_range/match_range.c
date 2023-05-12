#include "match_range.h"
#include <malloc.h>
#include <pthread.h>

XLIBC_STATE create_range_table(range_tab_t** tab, size_t key_size, uint8_t part_num)
{
    if (part_num != 2 && part_num != 4 && part_num != 16) {
        return XLIBC_STATE_UNKNOW_ERROR;
    }
    *tab = malloc(sizeof(range_tab_t));
    (*tab)->_key_size = key_size;
    (*tab)->_part_num = part_num;
    (*tab)->_tree = malloc(sizeof(range_node_t));
    memset((*tab)->_tree, 0, sizeof(range_node_t));
    return XLIBC_STATE_OK;
}

XLIBC_STATE destroy_range_table(range_tab_t* tab)
{
    return XLIBC_STATE_OK;
}

XLIBC_STATE add_range(
    range_tab_t* tab,
    uint32_t id,
    const uint8_t* from, size_t from_size,
    const uint8_t* to, size_t to_size)
{
    if (from_size > tab->_key_size || to_size > tab->_key_size) {
        return XLIBC_STATE_UNKNOW_ERROR;
    }

    range_node_t* cursur = tab->_tree;

    // ==== 填充同key
    uint8_t* from_full = malloc(tab->_key_size);
    memset(from_full, 0, tab->_key_size);
    memcpy(from_full + tab->_key_size - from_size, from, from_size);

    uint8_t* to_full = malloc(tab->_key_size);
    memset(to_full, 0, tab->_key_size);
    memcpy(to_full + tab->_key_size - to_size, to, to_size);

    uint8_t from_v = 0, to_v = 0;
    int i;
    for (i = 0; i < tab->_key_size; i++) {
        int j;
        for (j = 0; j < 8 / 2; j++) {
            from_v = from_full[i] >> (8 / 2 - i) * 2 & 0x03;
            to_v = to[i] >> (8 / 2 - i) * 2 & 0x03;

            if (from_v != to_v) {
                break;
            }

            if (cursur->sub_nodes == NULL) {
                cursur->sub_nodes = malloc(sizeof(range_node_t) * (1 << 2));
            }
            range_node_t* sub_node = &cursur->sub_nodes[from_full[i] >> (8 / 2 - i) * 2 & 0x03];
            sub_node->cnt++;

            // 将节点加到
        }
        if (from_v != to_v) {
            break;
        }
    }

    // ==== 填充不同key
    if (from_v != to_v) {
        // from 右填充
        // to 左填充
        // 如果from和to都满，上层做标记
    }

    return XLIBC_STATE_OK;
}

XLIBC_STATE del_range(range_tab_t* tab, uint32_t id) { return XLIBC_STATE_OK; }

XLIBC_STATE match_ranges(
    range_tab_t* tab,
    const uint8_t* key, size_t key_size,
    uint32_t* range_ids, size_t range_ids_max)
{
    return 0;
}