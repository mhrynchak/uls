#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *cdst = (char *) dst;
    const char *csrc = (const char*) src;
    char *tmp = (char *) malloc(sizeof(char) * len);

    if (tmp == NULL) return NULL;

    for (size_t i = 0; i < len; i++) {
        tmp[i] = csrc[i];
    }

    for (size_t i = 0; i < len; i++) {
        cdst[i] = tmp[i];
    }

    free(tmp);
    return dst;
}
