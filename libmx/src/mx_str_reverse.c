#include "libmx.h"

void mx_str_reverse(char *s) {
	if (s) 
		for (int i = 0, n = mx_strlen(s); i < n / 2; i++)
			mx_swap_char(&s[i], &s[n-i-1]);
}

// void mx_str_reverse(char *str) {
//     int beg = 0, end = mx_strlen(str) - 1;

//     while (beg < end) {
//         mx_swap_char((char *) (str + beg), (char *) (str + end));
//         beg++;
//         end--;
//     }
// }
