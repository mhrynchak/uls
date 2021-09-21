#include "libmx.h"

int mx_bubble_sort(int *arr, int size) {
    int swp = 0;
    
    for (int i = 1; i < size; i++) {
	for (int j = 1; j <= size - i; j++) {
                if (arr[j-1] > arr[j]) {
                        mx_swap_int(&(arr)[j], &(arr)[j-1]);
                        swp++;
	        }
        }
    }
    return swp;
}
