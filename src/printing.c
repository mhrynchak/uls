#include "uls.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PRINTING~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void mx_print_files_long(uint8_t *flags, t_obj *objs) {
    for (int i = 0; objs[i].d_name; i++) {
        mx_print_file_long(flags, objs[i]);
    }
}

void mx_print_file_long(uint8_t *flags, t_obj obj) {
    if (flags[f_i]) {
        mx_printint(obj.serial_num);
        mx_printchar(' ');
    }
    mx_printchar(obj.file_type);
    mx_printstr(obj.permissions);
    mx_printstr("  ");
    mx_printint(obj.links);
    if (!flags[f_g]) {
        mx_printstr("\t");
        mx_printstr(obj.owner);
    }
    if (!flags[f_o]) {
        mx_printstr("  ");
        mx_printstr(obj.group);
    }
    mx_printstr("  ");
    mx_printstr(obj.size_h);
    mx_printstr("\t");
    mx_printstr(obj.time);
    mx_printstr(" ");
    mx_printstr(obj.d_name);
    mx_printchar('\n');
}

void mx_print_files(t_ls *ls) {
    for (int i = 0; ls->contents; i++){
        mx_print_file(ls, ls->contents->data);
        mx_pop_front(&ls->contents);
    }
    if (!ls->flags[f_1]) {
        mx_printchar('\n');
    }
}

void mx_print_file(t_ls *ls, char *file) {
    if (ls->flags[f_i]) {
        int serial_num = mx_get_serial_num(ls->curr_dir, file);
        mx_printint(serial_num);
        mx_printchar(' ');
    }
    mx_printstr(file);
    mx_printstr(ls->separator);
}

//void mx_print_files(t_ls *ls) {
//    struct winsize window;
//    ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
//    mx_sort_list(ls->contents, ls->cmp_func);
//
//    if (((ls->namlen + 2) * ls->obj_num - 2) <= window.ws_col || isatty(1) == 0 || ls->flags[f_1]) {
//        one_line_output(ls);
//    } else {
//        multiple_line_output(ls, window);
//    }
//}
//
//void one_line_output(t_ls *ls) {
//    for (int i = 0; ls->contents; i++){
//        if (ls->flags[f_i]) {
//            int serial_num = mx_get_serial_num(ls->curr_dir, ls->contents->data);
//            mx_printint(serial_num);
//            mx_printchar(' ');
//        }
//        mx_printstr(ls->contents->data);
//        if (i != ls->obj_num - 1 && isatty(1) && !ls->flags[f_1])
//            mx_printstr("  ");
//        else
//            mx_printchar('\n');
//        mx_pop_front(&ls->contents);
//    }
//}
//
//void multiple_line_output(t_ls *ls, struct winsize window) {
//    int len_of_cell = window.ws_col / (ls->namlen + 2);
//    int height = ls->obj_num / len_of_cell;
//    int serial_num = 0;
//
//    if (ls->obj_num % len_of_cell != 0) {
//        height++;
//    }
//
//    for (int i = 0; i < height; i++) {
//        for (int j = i; j < ls->obj_num; j += height) {
//            if (ls->flags[f_i]) {
//                serial_num = mx_get_serial_num(ls->curr_dir, ls->contents->data);
//                mx_printint(serial_num);
//                mx_printchar(' ');
//            }
//            int k = (ls->namlen + mx_intlen(serial_num) + 4) - mx_strlen(ls->contents->data) - mx_intlen(serial_num);
//            for (int l = 0; l < k; l++) {
//                mx_printchar(' ');
//            }
//            mx_pop_front(&ls->contents);
//        }
//        mx_printchar('\n');
//    }
//}
