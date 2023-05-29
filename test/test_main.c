#include <stddef.h>
#include <stdint.h>

extern int8_t xlibc_list_test(void* arg);

int main()
{
    xlibc_list_test(NULL);
}
