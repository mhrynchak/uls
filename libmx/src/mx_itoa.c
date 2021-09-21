#include "libmx.h"

char *mx_itoa(int number) {
    char *str = mx_strnew(11);
    bool isNegative = false;
    int tmp = number, i = 0;

    if (number == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    if (number < 0) {
        if (number == INT_MIN) return "-2147483648";
        isNegative = true;
        number = -number;
    }

    while (number) {
        tmp = number % 10;
        str[i++] = (tmp > 9)? (tmp - 10) + 'a' : tmp + '0';
        number /= 10;
    }

    if (isNegative) str[i++] = '-';

    str[i] = '\0';

    mx_str_reverse(str);
    return str;
}
