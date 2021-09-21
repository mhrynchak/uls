#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    unsigned char *hay = (unsigned char *)big;
    unsigned char *needle = (unsigned char *)little;
    unsigned int index = 0, count = 0;

    if (big_len == 0 || little_len > big_len || little_len == 0)
        return NULL;
    for (size_t i = 0; i < big_len - little_len + 1; i++) {
        index = 0;
        count = 0;
        for (size_t j = 0; j < little_len; j++, index++)
            if (hay[index] == needle[j])
                count++;
        if (count == little_len)
            return hay;
        hay++;
    }

    return NULL;
}
