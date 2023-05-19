#include "malloc.h"
#include "xlibc_list.h"

typedef struct {
    uint64_t a;
    char b;
} mytest_t;

int main()
{
    xlibc_list_t* list = xlibc_list_create(sizeof(mytest_t), NULL);
    if (list == NULL) {
        return -1;
    }

    mytest_t* val = malloc(sizeof(mytest_t));
    val->a = 12;
    val->b = 'A';
    xlibc_list_insert_after(list, list->head, val);

    xlibc_list_del(list, list->tail);

    xlibc_list_node_t* it = NULL;
    for (it = list->head; it != &list->end; it = it->next) {
        val = (mytest_t*)it->val;
        printf("\n");
    }

    xlibc_list_destroy(list);
}
