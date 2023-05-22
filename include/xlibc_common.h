#ifndef __XLIBC_COMMON__
#define __XIBC_COMMON__

typedef enum {
    XLIBC_STATE_OK = 0, // Success.
    XLIBC_STATE_ARG_ERR, // Argument error.
    XLIBC_STATE_ALLOC_MEM_FAIL, // Failed to allocate memory.
    XLIBC_STATE_UNKNOW_ERR, // Other error.
    XLIBC_STATE_NUM, // The number of enumerated types.
} XLIBC_STATE;

#endif
