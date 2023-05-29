#include "xlibc_common.h"
#include "xlibc_list.h"

XLIBC_STATE xlibc_list_test(void* arg)
{
    printf("[INFO] xlibc_list_test()\n");
    xlibc_list_t* list;
    XLIBC_STATE state = xlibc_list_create(&list, sizeof(void*), NULL);
    if (state != XLIBC_STATE_OK) {
        printf("[ERROR] xlibc_list_create() failed!\n");
        return state;
    }
    printf("[INFO] xlibc_list_create() success!\n");

    state = xlibc_list_push_head(list, (void*)1);
    state = xlibc_list_push_tail(list, (void*)3);
    state = xlibc_list_insert_after(list, list->head, (void*)2);

    xlibc_list_node_t* it;
    for (it = list->head; it != NULL; it = it->next) {
        printf("[INFO] for(list)=%lu\n", (uint64_t)it->val);
    }

    state = xlibc_list_del(list, list->head);

    state = xlibc_list_destroy(list);

    return 0;
}
