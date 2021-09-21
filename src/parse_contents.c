#include "../inc/uls.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PARSING~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void mx_add_flags(t_ls *ls, char *flags) {
    for (int i = 1; flags[i]; i++) {
        switch(flags[i]) {
            case '1':
                if (ls->flags[f_l]) {
                    ls->flags[f_l] = 0;
                }
                ls->flags[f_1] = 1;
                break;
            case 'A':
                if (!ls->flags[f_a]) {
                    ls->flags[f_A] = 1;
                }
                break;
            case 'S':
                ls->flags[f_S] = 1;
                break;
            case 'T':
                ls->flags[f_T] = 1;
                break;
            case 'a':
                if (ls->flags[f_A]) {
                    ls->flags[f_A] = 0;
                }
                ls->flags[f_a] = 1;
                break;
            case 'c':
                ls->flags[f_c] = 1;
                break;
            case 'g':
                ls->flags[f_g] = 1;
                break;
            case 'o':
                ls->flags[f_o] = 1;
                break;
            case 'h':
                ls->flags[f_h] = 1;
                break;
            case 'i':
                ls->flags[f_i] = 1;
                break;
            case 'l':
                if (ls->flags[f_1]) {
                    ls->flags[f_1] = 0;
                }
                ls->flags[f_l] = 1;
                break;
            case 'r':
                ls->flags[f_r] = 1;
                break;
            case 't':
                ls->flags[f_t] = 1;
                break;
            case 'u':
                ls->flags[f_u] = 1;
                break;
            default:
                mx_invalid_flag(flags[i]);
        }
    }
}

void mx_parse_contents(char *path, t_ls *ls) {
    DIR *dirp = opendir(path);
    t_dirent *dir = NULL;
    t_obj *objs = NULL;

    if (dirp == NULL) return;
    while ((dir = readdir(dirp)) != NULL) {
        if (mx_is_flag_valid(dir->d_name, ls->flags)) {
            mx_push_back(&ls->contents, mx_strndup(dir->d_name, dir->d_namlen));
            if (dir->d_namlen > ls->namlen) {
                ls->namlen = dir->d_namlen;
            }
            ls->obj_num++;
        }
    }
    closedir(dirp);

    if (ls->curr_dir[mx_strlen(ls->curr_dir) - 1] != '/') {
        mx_strcat(ls->curr_dir, "/");
    }

    if (ls->flags[f_l] || ls->flags[f_g] || ls->flags[f_o]) {
        objs = mx_init_objs(ls);
        mx_print_files_long(ls->flags, objs);
        mx_clean_objs(&objs);
    } else {
        mx_sort_list(ls->contents, ls->cmp_func);
        mx_print_files(ls);
    }
}

t_obj *mx_init_objs(t_ls *ls) {
    t_obj *objs = (t_obj *) malloc(sizeof(t_obj) * (ls->obj_num + 1));

    for (int i = 0; !mx_is_empty(ls->contents); i++) {
        objs[i] = mx_new_obj(ls, ls->contents->data);
        mx_pop_front(&ls->contents);
    }
    objs[ls->obj_num].d_name = NULL;

    if (ls->flags[f_S]) {
        if (ls->flags[f_r]) {
            sortobjs(objs, ls->obj_num, sizeof(t_obj), cmp_size_r);
        } else {
            sortobjs(objs, ls->obj_num, sizeof(t_obj), cmp_size);
        }
        return objs;
    }

    if (ls->flags[f_t] || ls->flags[f_c] || ls->flags[f_u]) {
        if (ls->flags[f_r]) {
            sortobjs(objs, ls->obj_num, sizeof(t_obj), cmp_time_r);
        } else {
            sortobjs(objs, ls->obj_num, sizeof(t_obj), cmp_time);
        }
        return objs;
    }

    if (ls->flags[f_r]) {
        sortobjs(objs, ls->obj_num, sizeof(t_obj), cmp_ascii_r);
    } else {
        sortobjs(objs, ls->obj_num, sizeof(t_obj), cmp_ascii);
    }

    ls->obj_num = 0;
    return objs;
}

t_obj mx_new_obj(t_ls *ls, char *file) {
    t_stat *file_st = (t_stat *) malloc(sizeof(t_stat));
    t_obj obj;
    char full_path[PATH_MAX] = "";

    mx_strcpy(full_path, ls->curr_dir);
    mx_strcat(full_path, file);
    stat(full_path, file_st);

    obj.d_name = mx_strdup(file);
    obj.serial_num = mx_get_serial_num(ls->curr_dir, obj.d_name);
    obj.file_type = mx_get_file_type(file_st);
    obj.permissions = mx_strdup(mx_get_permissions(file_st));
    obj.links = mx_get_link_num(file_st);
    obj.owner = mx_strdup(mx_get_owner(file_st));
    obj.group = mx_strdup(mx_get_group(file_st));
    obj.size = mx_get_size(file_st);
    obj.size_h = mx_strdup(mx_get_size_h(file_st->st_size, ls->flags));
    // obj.size_h = objs[i].file_type == 'c' ? get_rdev(file_st->st_rdev) : mx_get_size_h(file_st->st_size, ls->flags);
    if (ls->flags[f_T]) {
        obj.time = mx_get_full_time(file_st->st_mtimespec);
    } else {
        obj.time = mx_get_time(file_st->st_mtimespec, ls->curr_year);
        obj.time_sec = file_st->st_mtimespec;
    }
    if (ls->flags[f_c]) {
        if (ls->flags[f_T]) {
            obj.time = mx_get_full_time(file_st->st_ctimespec);
        } else {
            obj.time = mx_get_time(file_st->st_ctimespec, ls->curr_year);
        }
        obj.time_sec = file_st->st_ctimespec;
    }
    if (ls->flags[f_u]) {
        if (ls->flags[f_T]) {
            obj.time = mx_get_full_time(file_st->st_atimespec);
        } else {
            obj.time = mx_get_time(file_st->st_atimespec, ls->curr_year);
        }
        obj.time_sec = file_st->st_atimespec;
    }

    return obj;
}
