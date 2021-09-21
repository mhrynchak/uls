#include "../inc/uls.h"

void mx_clean_obj(t_obj obj) {
    mx_strdel(&obj.d_name);
    mx_strdel(&obj.permissions);
    mx_strdel(&obj.owner);
    mx_strdel(&obj.group);
    mx_strdel(&obj.size_h);
    mx_strdel(&obj.time);
}

void mx_clean_objs(t_obj **objs) {
    for (int i = 0; objs[i]; i++) {
        mx_clean_obj(*objs[i]);
        objs[i] = NULL;
    }
}
