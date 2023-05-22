#include "xlibc_common.h"

static char* xlibc_state_msgs[XLIBC_STATE_NUM];

XLIBC_STATE xlibc_init()
{
    xlibc_state_msgs[XLIBC_STATE_OK] = "OK";
    return XLIBC_STATE_OK;
}