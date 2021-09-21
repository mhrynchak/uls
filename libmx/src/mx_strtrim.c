#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (str) {
        int start = 0;
        int end = mx_strlen(str) - 1;
        char *new_str = NULL;

        for (; mx_isspace(str[start]); ++start);
        for (; mx_isspace(str[end]) && end > start; --end);
        new_str = mx_strnew(end > start ? end - start + 1 : 0);
        mx_strncpy(new_str, str + start, end - start + 1);
        return new_str;
    }
    return NULL;
}

// char *mx_strtrim(const char* str) {
// 	if (!str) return NULL;

// 	int len = mx_strlen(str), beg = 0, end = 0;
// 	int i = len - 1;

// 	while (mx_isspace(str[i])) {
// 		i--;
// 		end++;
// 	}

// 	while (mx_isspace(str[beg])) beg++;

// 	char* new = mx_strnew(len - end - beg);
// 	new = mx_strncpy(new, (str + beg), len - end - beg);
	
// 	if (new) return new;
// 	return NULL;
// }
