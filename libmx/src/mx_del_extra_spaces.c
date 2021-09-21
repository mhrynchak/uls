#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    int i = 0, j = 0;
    char *res = NULL, *mem = NULL;

    if (str) {
        mem = mx_strnew(mx_strlen(str));
        while (str[i]) {
            if (!(mx_isspace(str[i]))) {
                mem[j] = str[i];
                j++;
            }
            if (!(mx_isspace(str[i])) && mx_isspace(str[i + 1])) {
                mem[j] = ' ';
                j++;
            }
        i++;
        }
        res = mx_strtrim(mem);
        mx_strdel(&mem);
        return res;
    }
    return NULL;
}

// char *mx_del_extra_spaces(const char *str) {
//     char *cut = NULL;
//     char *res;
//     int len = 0, spaces = 0;

//     if (!str) return NULL;
//     cut = mx_strtrim(str);

//     for (int i = 0; cut[i]; i++) {
//         if(mx_isspace(cut[i]))
//             spaces++;
//         while(mx_isspace(cut[i]))
//             i++;
//         len++;
//     }

//     res = mx_strnew(spaces + len);

//     for (int i = 0, j = 0; cut[i]; j++) {
//         res[j] = cut[i];

//         if(!mx_isspace(cut[i]))
//             i++;

//         else {
//             while(mx_isspace(cut[i]))
//             i++;
//         }
//     }

//     mx_strdel(&cut);

//     if(res)
//         return res;
//     return NULL;
// }
