#include "uls.h"

void mx_run(t_ls *ls) {
    uint8_t dirs_size = mx_list_size(ls->dirs);
    uint8_t files_size = mx_list_size(ls->files);
    uint8_t no_exist_size = mx_list_size(ls->non_existent);
    bool multiple_dirs = dirs_size + files_size + no_exist_size > 1;
    uint8_t res = 0;

    while (!mx_is_empty(ls->non_existent)) {
        mx_invalid_file(ls->non_existent->data);
        mx_pop_front(&(ls->non_existent));
    }

    while (!mx_is_empty(ls->files)) {
        if (ls->flags[f_l]) {
            t_obj obj = mx_new_obj(ls, ls->files->data);
            mx_print_file_long(ls->flags, obj);
            mx_clean_obj(obj);
        } else {
            mx_print_file(ls, ls->files->data);
        }
        mx_pop_front(&(ls->files));
    }

    if (!ls->flags[f_1] && files_size && !ls->flags[f_l]) {
        mx_printchar('\n');
    }
    if (files_size && (dirs_size || no_exist_size)) {
        mx_printchar('\n');
    }

    while (!mx_is_empty(ls->dirs)) {
        res = mx_is_valid_file(ls->dirs->data);
        ls->curr_dir = mx_strdup(ls->dirs->data);

        if (res == SUCCESS || res == EACCES) {
            if (multiple_dirs) {
                mx_printstr(ls->dirs->data);
                mx_printstr(":\n");
            }
        }

        if (res == SUCCESS) {
            if (ls->flags[f_l] || ls->flags[f_g] || ls->flags[f_o]) {
                mx_printstr("total ");
                mx_printint(mx_get_block_size(ls->dirs->data, ls->flags));
                mx_printchar('\n');
            }
            mx_parse_contents(ls->dirs->data, ls);
        } else if (res == ENOTDIR) {
            mx_printstr(ls->dirs->data);
            mx_printstr(ls->separator);
        } else if (res == EACCES) {
            mx_invalid_permisson(ls->dirs->data);
        }

        mx_pop_front(&(ls->dirs));
        if (multiple_dirs && ls->dirs) {
            mx_printchar('\n');
        }
        mx_strdel(&ls->curr_dir);
    }
}
