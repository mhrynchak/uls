#include "libmx.h"

void mx_swap_int(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
