#include "../inc/uls.h"

void mx_parse_input(int argc, char **argv, t_ls *ls) {
    int i = 1, res = 0;

    ls->curr_year = mx_get_curr_year();
    if (mx_get_char_index(argv[i], '-') == 0 && mx_strlen(argv[i]) > 1) {
        mx_add_flags(ls, argv[i]);
        i++;
    }
    for (; i < argc; i++) {
        res = mx_is_valid_file(argv[i]);
        if (res != ENOENT && res != ENOTDIR) {
            mx_push_back(&(ls->dirs), argv[i]);
        } else if (res == ENOENT){
            mx_push_back(&(ls->non_existent), argv[i]);
        } else if (res == ENOTDIR) {
            mx_push_back(&(ls->files), argv[i]);
        }
    }
    ls->cmp_func = ls->flags[f_r] ? &mx_cmp_r : &mx_cmp;
    ls->separator = ls->flags[f_1] || !isatty(1) ? "\n" : "  ";

    if (mx_is_empty(ls->dirs) && mx_is_empty(ls->non_existent) && mx_is_empty(ls->files)) {
        mx_push_back(&(ls->dirs), mx_strdup("./"));
    } else {
        mx_sort_list(ls->dirs, ls->cmp_func);
        mx_sort_list(ls->non_existent, ls->cmp_func);
        mx_sort_list(ls->files, ls->cmp_func);
    }
}
