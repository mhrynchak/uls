#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    char *csrc = (char *)src;
    char *cdst = (char *)dst;

    for (size_t i = 0; i < n; i++)
        cdst[i] = csrc[i];
    return dst;
}
