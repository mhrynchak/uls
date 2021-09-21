#include "uls.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~VALIDATION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int mx_is_valid_file(char *file) {
    DIR *dirp = opendir(file);
    if(dirp) {
        closedir(dirp);
        return SUCCESS;
    }
    if (errno == ENOENT) {
        return ENOENT;
    } else if (errno == EACCES) {
        return EACCES;
    } else if (errno == ENOTDIR) {
        return ENOTDIR;
    }
    return SUCCESS;
}

//bool mx_valid_existence(char *path) {
//    DIR *dirp = opendir(path);
//
//    if (dirp == NULL) {
//        return false;
//    } else {
//        closedir(dirp);
//    }
//    return true;
//}
//bool mx_valid_permission(char *file) {
//    char full_path[PATH_MAX] = "", *perms = NULL, file_type;
//    t_stat file_st;
//
//    mx_strcpy(full_path, file);
//    if (file[mx_strlen(file) - 1] != '/') {
//        mx_strcat(full_path, "/");
//    }
//
//    stat(full_path, &file_st);
//    perms = mx_get_permissions(&file_st);
//    file_type = mx_get_file_type(&file_st);
//
//    if(perms[0] != 'r' && file_type == 'd') {
//        return false;
//    }
//    return true;
//}

bool mx_is_flag_valid(char *file, uint8_t *flags) {
    if (file[0] == '.' && !flags[f_A] && !flags[f_a]) {
        return false;
    }
    if (!mx_strcmp(file, ".") || !mx_strcmp(file, "..")) {
        if (flags[f_A] || !flags[f_a]) {
            return false;
        }
    }
    return true;
}
