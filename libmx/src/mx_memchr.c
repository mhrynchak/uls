#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    char *ptr = (char*) s;

    for (size_t i = 0; i < n; i++) {
        if (*(ptr + i) == c)
            return ptr + i;
    }
    return NULL;
}
