#include "uls.h"

static t_ls *init_ls() {
    t_ls *ls = (t_ls *) malloc(sizeof(t_ls));
    ls->curr_year = NULL;
    ls->curr_dir = "./";
    ls->separator = NULL;
    ls->dirs = NULL;
    ls->non_existent = NULL;
    ls->files = NULL;
    ls->contents = NULL;
    ls->cmp_func = NULL;
    ls->namlen = 0;
    ls->obj_num = 0;
    for (int i = 0; i < 14; i++) ls->flags[i] = 0;
    return ls;
}

int main (int argc, char **argv) {
    t_ls *ls = init_ls();

    mx_parse_input(argc, argv, ls);
    mx_run(ls);
    return 0;
}
