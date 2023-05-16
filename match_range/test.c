#include "match_range.h"
#include <stdio.h>

int main()
{
    range_tab_t* range_tab;
    XLIBC_STATE state = create_range_table(&range_tab, 4, 2);
    if (state != XLIBC_STATE_OK) {
        printf("create_range_table failed: state=%d\n", state);
        return -1;
    }

    state = add_range(range_tab, 1, (uint8_t*)"ab", 2, (uint8_t*)"cd", 2);
    if (state != XLIBC_STATE_OK) {
        printf("add_range failed: state=%d\n", state);
        goto clean;
    }
    // state = add_range(range_tab, 2, "de", 2, "fg", 2);
    // if (state != XLIBC_STATE_OK) {
    //     printf("add_range failed: state=%d\n", state);
    //     goto clean;
    // }

    uint32_t ids[100];
    int id_num = match_ranges(range_tab, "bc", 2, ids, 100);
    if (id_num < 0) {
        printf("match_ranges failed: state=%d\n", -id_num);
    } else {
        int i;
        for (i = 0; i < id_num; i++) {
            printf("match_ranges ok: id=%d\n", id_num);
        }
    }

clean:
    state = destroy_range_table(range_tab);
    if (state != XLIBC_STATE_OK) {
        printf("destroy_range_table failed: state=%d\n", state);
    }
    return 0;
}