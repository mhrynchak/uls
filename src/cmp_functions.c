#include "uls.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CMP_FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

bool mx_cmp(void *data1, void *data2)  {
    int res = mx_strcmp((char *)data1, (char *)data2);

    if (res >= 0) {
        return true;
    }
    return false;
}

bool mx_cmp_r(void *data1, void *data2)  {
    int res = mx_strcmp((char *)data2, (char *)data1);

    if (res >= 0) {
        return true;
    }
    return false;
}

int cmp_ascii(const void *data1, const void *data2) {
    const t_obj *obj1 = data1;
    const t_obj *obj2 = data2;
    char *str1 = mx_strdup(obj1->d_name);
    char *str2 = mx_strdup(obj2->d_name);
    int res = 0;

    res = mx_strcmp(str1, str2);

    mx_strdel(&str1);
    mx_strdel(&str2);
    return res;
}

int cmp_ascii_r(const void *data1, const void *data2) {
    const t_obj *obj1 = data1;
    const t_obj *obj2 = data2;
    char *str1 = mx_strdup(obj1->d_name);
    char *str2 = mx_strdup(obj2->d_name);
    int res = 0;

    res = mx_strcmp(str2, str1);

    mx_strdel(&str1);
    mx_strdel(&str2);
    return res;
}

int cmp_size(const void *data1, const void *data2) {
    const t_obj *obj1 = data2;
    const t_obj *obj2 = data1;

    if (obj1->size != obj2->size) {
        return obj1->size - obj2->size;
    }
    return mx_strcmp(obj1->d_name, obj2->d_name);
}

int cmp_size_r(const void *data1, const void *data2) {
    const t_obj *obj1 = data1;
    const t_obj *obj2 = data2;

    if (obj1->size != obj2->size) {
        return obj1->size - obj2->size;
    }
    return mx_strcmp(obj1->d_name, obj2->d_name);
}

int cmp_time(const void *data1, const void *data2) {
    const t_obj *f1 = data2;
    const t_obj *f2 = data1;

    if (f1->time_sec.tv_sec != f2->time_sec.tv_sec) {
        return f1->time_sec.tv_sec - f2->time_sec.tv_sec;
    }
    if (f1->time_sec.tv_nsec != f2->time_sec.tv_nsec) {
        return f1->time_sec.tv_nsec - f2->time_sec.tv_nsec;
    }
    return mx_strcmp(f2->d_name, f1->d_name);
}

int cmp_time_r(const void *data1, const void *data2) {
    const t_obj *f1 = data1;
    const t_obj *f2 = data2;

    if (f1->time_sec.tv_sec != f2->time_sec.tv_sec) {
        return f1->time_sec.tv_sec - f2->time_sec.tv_sec;
    }
    if (f1->time_sec.tv_nsec != f2->time_sec.tv_nsec) {
        return f1->time_sec.tv_nsec - f2->time_sec.tv_nsec;
    }
    return mx_strcmp(f2->d_name, f1->d_name);
}
