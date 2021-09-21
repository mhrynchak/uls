#include "libmx.h"

int mx_atoi(const char *str) {
	int i = 0, n = 0, s =1, r = 0;
	for (; (str[i] != '\0' && mx_isspace(str[i]) == 1); i++)
	    ;
    if (str[i] == '-') {
        s = -s;
        i++;
    }
    if (str[i] == '+')
        i++;
    for (; mx_isdigit(str[i]) ; i++, r++)
        n = 10 * n + (str[i] - '0');
    if (r > 19 && s == 1)
    	return -1;
    if (r > 19 && s == -1)
    	return 0;
    return n * s;
}
