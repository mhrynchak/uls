#include "libmx.h"

static void swap(int *i1, int *i2, int *count) {
    int tmp = *i1;
    *i1 = *i2;
    *i2 = tmp;
    ++*count;
}

int mx_quicksort(int *arr, int l, int r) {
    int count = 0;
    int pivot;
    int left = l;
    int right = r;

    if (!arr)
        return -1;
    
    pivot = arr[r];

    for (right -= 1; left < right; swap(&arr[left++], &arr[right--], &count)) {
        for (; arr[left] <= pivot && left < r; ++left);
        for (; arr[right] > pivot; --right);
        if (left >= right)
            break;
    }
    if (arr[left] > pivot)
        swap(&arr[left], &arr[r], &count);
        
    if (right > l)
        count += mx_quicksort(arr, l, right);
    if (left + 1 < r)
        count += mx_quicksort(arr, left + 1, r);
    return count;
}

// static char **cycle(char **arr, int**all,  char *pivot, int *count) {
//     while ((*all)[0] <= (*all)[1]) {
//         while (mx_strlen(arr[(*all)[0]]) < mx_strlen(pivot))
//             (*all)[0]++;
//         while (mx_strlen(arr[(*all)[1]]) > mx_strlen(pivot))
//             (*all)[1]--;
//         if ((*all)[0] <= (*all)[1]) {
//             if (mx_strlen(arr[(*all)[1]]) != mx_strlen(arr[(*all)[0]])) {
//                 char *temp = arr[(*all)[0]];
//                 arr[(*all)[0]] = arr[(*all)[1]];
//                 arr[(*all)[1]] = temp;
//                 (*count)++;
//             }
//             (*all)[1]--;
//             (*all)[0]++;
//         }
//     }
//     return arr;
// }
// int mx_quicksort(char **arr, int left, int right){
//     int count = 0;
//     int *all = malloc(sizeof(int) * 2);
//     char *pivot;
//     if (left < right) {
//         all[0] = left;
//         all[1] = right;
//         pivot = arr[(all[0] + all[1]) / 2];
//         arr = cycle(arr, &all, pivot, &count);
//         count += mx_quicksort(arr, left, all[1]);
//         count += mx_quicksort(arr, all[0], right);
//     }
//     return count;
// }
