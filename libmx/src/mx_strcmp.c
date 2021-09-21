#include "libmx.h"

int mx_strcmp(const char *s1, const char *s2) {
    for (;*s1 == *s2; ++s1, ++s2)
        if (*s1 == '\0')
            return 0;
    return (unsigned char) *s1 - (unsigned char) *s2;
}

// int mx_strcmp(const char* s1, const char* s2) {
//         if (!s1 || !s2)
//                 return -1;
//         while (*s1 && *s1 == *s2) {
//                 s1++;
//                 s2++;
//         }
//         return (int)(*s1) - (int)(*s2);
// }
