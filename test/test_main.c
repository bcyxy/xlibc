#include <stddef.h>
#include <stdint.h>
#include "xlibc_common.h"

extern XLIBC_STATE xlibc_list_test(void* arg);

int main()
{
    xlibc_list_test(NULL);
    return 0;
}
