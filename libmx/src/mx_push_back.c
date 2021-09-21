#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *node = mx_create_node(data);
    t_list *tmp = *list;
    if (*list == NULL) {
        *list = node;
    }
    else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = node;
    }
}
