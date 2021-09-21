#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int i = 0;

    for (; src[i] && i < len; dst[i] = src[i], ++i);
    for (; i < len; dst[i] = '\0', ++i);
    return dst;
}

// char *mx_strncpy(char *dst, const char *src, int len)
// {
// 	char* start = dst;

//         for (int i = 0; i < len; i++) {
//                 *dst = *src;
//                 dst++;
//                 src++;
// 	}

//         *dst = '\0';
//         return start;
// }
