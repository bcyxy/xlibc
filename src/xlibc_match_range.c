#include "xlibc_match_range.h"
#include <malloc.h>
#include <pthread.h>

typedef struct id_node_s {
    uint32_t id;
    struct id_node_s* next;
} id_node_t;

typedef struct match_node_s {
    struct match_node_s** sub_nodes; // 数组指针，指向：range_node_s* l[X]

    uint32_t ids[100]; // 本节点归属的范围，TODO 用链表结构
    uint32_t inner_range_num; // 内部范围数量
} match_node_t;

typedef struct range_table_s {
    size_t _key_size; // 范围key大小
    uint8_t _step_len; // 遍历步长
    id_node_t* ids; // 归属的范围ID列表

    match_node_t* _match_tree; // 匹配树
} range_tab_t;

XLIBC_STATE create_range_table(range_tab_t** tab, size_t key_size, uint8_t step_len)
{
    if (step_len != 1 && step_len != 2 && step_len != 4) {
        return XLIBC_STATE_UNKNOW_ERR;
    }
    *tab = malloc(sizeof(range_tab_t));
    memset(*tab, 0, sizeof(range_tab_t));
    (*tab)->_key_size = key_size;
    (*tab)->_step_len = step_len;
    (*tab)->_match_tree = malloc(sizeof(match_node_t));
    memset((*tab)->_match_tree, 0, sizeof(match_node_t));
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
        return XLIBC_STATE_UNKNOW_ERR;
    }

    match_node_t* cursur = tab->_match_tree;

    // ==== 填充同key
    uint8_t* from_full = malloc(tab->_key_size);
    memset(from_full, 0, tab->_key_size);
    memcpy(from_full + tab->_key_size - from_size, from, from_size);

    uint8_t* to_full = malloc(tab->_key_size);
    memset(to_full, 0, tab->_key_size);
    memcpy(to_full + tab->_key_size - to_size, to, to_size);

    uint8_t mask = (1 << tab->_step_len) - 1;
    uint8_t from_v = 0, to_v = 0;
    int i, j;
    for (i = 0; i < tab->_key_size; i++) {
        printf("from_full=0x%x, to_full=0x%x\n", from_full[i], to_full[i]);
        for (j = 0; j < 8 / tab->_step_len; j++) {

            from_v = from_full[i] >> (8 - j * tab->_step_len - tab->_step_len) & mask;
            to_v = to_full[i] >> (8 - j * tab->_step_len - tab->_step_len) & mask;

            printf("- from_full=0x%x, to_full=0x%x\n", from_v, to_v);
            if (from_v != to_v) {
                break;
            }

            if (cursur->sub_nodes == NULL) {
                cursur->sub_nodes = malloc(sizeof(void*) * (1 << tab->_key_size));
                memset(cursur->sub_nodes, 0, sizeof(void*) * (1 << tab->_key_size));
            }
            match_node_t* sub_node = cursur->sub_nodes[from_v];
            if (sub_node == NULL) {
                sub_node = malloc(sizeof(match_node_t));
                memset(sub_node, 0, sizeof(match_node_t));
            }
            sub_node->inner_range_num++;
            cursur = sub_node;
        }
        if (from_v != to_v) {
            break;
        }
    }

    // // ==== 填充不同key
    // if (from_v != to_v) {
    //     int is_r_full = fill_right(tab, cursur, from_full, i, j);
    //     int is_l_full = fill_left(tab, cursur, to, i, j);
    //     if (is_r_full && is_l_full) {
    //         cursur->inner_range_num--;
    //         // TODO cursur->ids[i] = id;
    //     }
    //     // fill_left();
    //     //  from 右填充
    //     //  to 左填充
    //     //  如果from和to都满，上层做标记
    // }

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