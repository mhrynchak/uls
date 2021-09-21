#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    char *res = NULL;
    
    if (!str || !sub) return -2;

    res = mx_strstr(str, sub);
    if (res) return res - str;
    
    return -1;
}
