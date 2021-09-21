#include "uls.h"

void mx_invalid_flag(char flag) {
    mx_printerr("uls: illegal option -- ");
    mx_printchar(flag);
    mx_printerr("\n" MX_USAGE "\n");
    exit(errno);
}

void mx_invalid_file(char *file) {
    mx_printerr("uls: ");
    mx_printerr(file);
    mx_printerr(MX_INVLD_FILE "\n");
}

void mx_invalid_permisson(char *file) {
    mx_printerr("uls: ");
    mx_printerr(file);
    mx_printerr(MX_INVLD_PERM "\n");
}
