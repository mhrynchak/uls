#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    int result = 0;

    if (s1 != s2) {
        const uint8_t *us1 = s1;
        const uint8_t *us2 = s2;
        const uint8_t *end = us1 + n;

        for (; !result && us1 != end; result = *us1++ - *us2++);
    }
    return result;
}

// int mx_memcmp(const void *s1, const void *s2, size_t n) {
//     char *cs1 = (char *) s1;
//     char *cs2 = (char *) s2;

//     for (size_t i = 0; i < n; i++) {
//         if (*cs1 != *cs2) break;
//         cs1++;
//         cs2++;
//     }

//     return (int)(*cs1) - (int)(*cs2);
// }
