#include "libmx.h"

void mx_del_intarr(int **arr, int num) {
    if (!arr) return;
    for (int i = 0; i < num; i++) {
        free(arr[i]);
    }
    free(arr);
}
