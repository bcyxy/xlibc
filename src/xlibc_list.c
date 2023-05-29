#include "xlibc_list.h"
#include <string.h>

XLIBC_STATE xlibc_list_create(xlibc_list_t** pp_list, size_t val_size, xlibc_alloc_func_t alloc_func)
{
    xlibc_list_t* list = malloc(sizeof(xlibc_list_t));
    if (list == NULL) {
        return -1;
    }
    memset(list, 0, sizeof(xlibc_list_t));
    list->val_size = val_size;
    *pp_list = list;
    return 0;
}

XLIBC_STATE xlibc_list_destroy(xlibc_list_t* list)
{
    // 释放所有节点
    // 释放list
    free(list);
    return 0;
}

XLIBC_STATE xlibc_list_push_head(xlibc_list_t* list, void* val)
{
    if (list->head == NULL) {
        xlibc_list_node_t* new_node = malloc(list->val_size);
        new_node->val = val;
        list->head = new_node;
        list->head->next = list->head;
        list->head->pre = list->head;
        list->list_len = 1;
        return XLIBC_STATE_OK;
    }
    xlibc_list_insert_after(list, list->head->pre, val);
    list->head = list->head->pre;
    return XLIBC_STATE_OK;
}

XLIBC_STATE xlibc_list_push_tail(xlibc_list_t* list, void* val)
{
    if (list->head == NULL) {
        xlibc_list_node_t* new_node = malloc(list->val_size);
        new_node->val = val;
        list->head = new_node;
        list->head->next = list->head;
        list->head->pre = list->head;
        list->list_len = 1;
        return 0;
    }
    xlibc_list_insert_after(list, list->head->pre, val);
    return 0;
}

XLIBC_STATE xlibc_list_insert_after(xlibc_list_t* list, xlibc_list_node_t* node, void* val)
{
    if (node == NULL) {
        return -1;
    }

    xlibc_list_node_t* new_node = malloc(list->val_size);
    new_node->val = val;

    new_node->next = node->next;
    new_node->pre = node;
    node->next->pre = new_node;
    node->next = new_node;

    list->list_len++;
    return 0;
}

XLIBC_STATE xlibc_list_del(xlibc_list_t* list, xlibc_list_node_t* node)
{
    if (node == NULL) {
        return -1;
    }

    if (list->head->next == list->head) { // 只有一个节点
        list->head = NULL;
        list->list_len = 0;
        free(node);
        return 0;
    }

    if (node == list->head) { // 删除头节点
        list->head = list->head->next;
    }

    node->pre->next = node->next;
    node->next->pre = node->pre;
    free(node);
    list->list_len--;
    return 0;
}
