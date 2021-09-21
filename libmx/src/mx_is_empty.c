#include "libmx.h"

bool mx_is_empty(t_list *list) {
    if (list == NULL) {
        return true;
    }
    return list->data == NULL;
}
