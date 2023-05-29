#include "xlibc_common.h"
#include "xlibc_list.h"

int8_t xlibc_list_test(void* arg)
{
    xlibc_list_t* list;
    XLIBC_STATE state = xlibc_list_create(&list, sizeof(void*), NULL);
    if (state != XLIBC_STATE_OK) {
        return -1;
    }
    return 0;
}
