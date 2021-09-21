#include "libmx.h"

int mx_list_size(t_list *list) {
    t_list *tmp = list;
    int size = 0;
    while (tmp){
        tmp = tmp->next;
        size++;
    }
    return size;
}
