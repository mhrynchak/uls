#include "libmx.h"

char* mx_strnew(const int size){
    if (size >= 0) {
        char* strnew = malloc(sizeof(char)*(size+1));
        for(int i = 0; i < size; i++)
            strnew[i] = '\0';
        strnew[size] = '\0';
        return  strnew;
    }
    else return NULL;
}

// char *mx_strnew(const int size) {
//     if (size > 0) {
//         char *strnew = malloc(size + 1);

//         for (int i = 0; i <= size; i++)
//             strnew[i] = '\0';

//         return strnew;   
//     }

//     return NULL;
// }
