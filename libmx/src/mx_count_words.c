#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int words = 0;

    if (str) {
        while (*str) {
            for (; *str && *str == c; ++str);
            if (*str && *str != c) {
                for (; *str && *str != c; ++str);
                ++words;
            }
        }
    }
    return str ? words : -1;
}

// int mx_count_words(const char *str, char delimiter)
// {
// 	int count = 0;
// 	int i = 0;

// 	while (str[i] != '\0') {
// 		if (str[i] != delimiter) count++;
// 		while (str[i] != delimiter && str[i] != '\0') i++;
// 		if (str[i] == delimiter) i++;
// 	}

// 	return count;
// }

