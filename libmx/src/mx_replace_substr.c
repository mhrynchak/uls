#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub,
                        const char *replace) {
    if (str && sub && replace) {
        int len1 = mx_strlen(sub);
        int len2 = mx_strlen(replace);
        int cnt = mx_count_substr(str, sub);

        if (cnt > 0) {
            char *result = mx_strnew(mx_strlen(str) + (len2 - len1) * cnt);

            for (int i = 0; *str; )
                if (*str == *sub && mx_strncmp(str, sub, len1) == 0) {
                    mx_strncpy(result + i, replace, len2);
                    str += len1;
                    i += len2;
                }
                else
                    result[i++] = *str++;
            return result;
        }
    }
    return str && sub && replace ? mx_strdup(str) : NULL;
}

// char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
//     int reslen = 0;
//     char *res = NULL;
//     int sub_index = 0, j = 0, i = 0;

//     if (!sub || !(*sub) || !str || !(*str) || !replace || !(*replace)) return NULL;

//     reslen = mx_strlen(str) - mx_count_substr(str, sub) * (mx_strlen(sub) - mx_strlen(replace));
//     res = mx_strnew(reslen);

//     while ((sub_index = mx_get_substr_index(str, sub)) >= 0) {
//         for (j = 0; j < sub_index; ++j, ++i) // copy all bofore entry 
//             res[i] = str[j];

//         for (j = 0; j < mx_strlen(replace); ++j, ++i) // copy replace to res
//             res[i] = replace[j];

//         str += sub_index + mx_strlen(sub); // 
//     }

//     for (; *str && i < reslen; ++i)
//         res[i] = *str;

//     return res;
// }
