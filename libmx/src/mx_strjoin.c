#include "libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    if (s1 && s2){
            char* tmp = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
            tmp =  mx_strcpy(tmp,s1);
            return tmp ? mx_strcat(tmp,s2) : NULL;
    }
    else if (s1 == NULL && s2 != NULL)
            return mx_strdup(s2);
    else if (s2 == NULL && s1 != NULL)
            return mx_strdup(s1);
    else
        return NULL;
}

// char *mx_strjoin(char const *s1, char const *s2) {
//     if (!s1)
//         return mx_strdup(s2);
//     else if(!s2)
//         return mx_strdup(s1);

//     char *res = mx_strnew(mx_strlen(s1) + mx_strlen(s2));

//     if(!res)
//         return NULL;

//     mx_strcat(res, s1);
//     mx_strcat(res, s2);

//     if (res)
//         return res;

//     return NULL;
// }
