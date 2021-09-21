#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long dec = 0;
    int tmp, len = mx_strlen(hex) - 1;

    for(int i = 0; hex[i]; i++, len--) {
        if(mx_isdigit(hex[i]))
            tmp = hex[i] - 48;
        else if(mx_islower(hex[i]))
            tmp = hex[i] - 97 + 10;
        else if(mx_isupper(hex[i]))
            tmp = hex[i] - 65 + 10;
        dec += tmp * mx_pow(16, len);
    }

    return dec;
}
