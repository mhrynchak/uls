#include "libmx.h"

// char *mx_strstr(const char *s1, const char *s2) {
// 	int n = mx_strlen(s2);
// 	const char *start;
// 	start = s1;

// 	if (!s1) return NULL;
// 	else if (!s2) return (char *)s1;

// 	while (start) {
// 		if (!mx_strncmp(start, s2, n))
// 			return (char *) start;
//         start = mx_strchr(start + 1, s2[0]);
// 	}

// 	return NULL;
// }

char *mx_strstr(const char *haystack, const char *needle) {
    int len1 = mx_strlen(haystack);
    int len2 = mx_strlen(needle);

    if (len2 == 0)
        return (char *)haystack;
    if (len1 >= len2)
        for (; (haystack = mx_strchr(haystack, *needle)); ++haystack)
            if (mx_strncmp(haystack, needle, len2) == 0)
                return (char *)haystack;
    return NULL;
}
