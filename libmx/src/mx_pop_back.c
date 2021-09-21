#include "libmx.h"

void mx_pop_back(t_list **list) {
    t_list *tmp, *ptr;
    if (list == NULL || *list == NULL) {
        return;
    }
    else if ((*list)->next == NULL) {
        ptr = *list;
        *list = NULL;
        free(ptr);
    }
    else {
        ptr = *list;
        while (ptr->next) {
            tmp = ptr;
            ptr = ptr->next;
        }
        tmp->next = NULL;
        free(ptr);
    }
}
