#include "libmx.h"

int mx_strcmp_ignore_case(const char *s1, const char *s2) {
    int i = 0;
    char c1, c2;
    for ( ; s1[i] != '\0' && s2[i] != '\0'; i++) {
        c1 = mx_tolower(s1[i]);
        c2 = mx_tolower(s2[i]);
        if(c1 != c2) break;
    }
    return c1 - c2;
}

// int mx_strcmp_ignore_case(const char *s1, const char *s2) {
//     for (;mx_tolower(*s1) == mx_tolower(*s2); ++s1, ++s2)
//         if (*s1 == '\0')
//             return 0;
//     return mx_tolower(*s1) - mx_tolower(*s2);
// }
