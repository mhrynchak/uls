#include "uls.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~GETTERS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

char *mx_get_curr_year() {
    time_t time_now = time(&time_now);
    return mx_strndup(ctime(&time_now) + YR_OFFST, YR_LEN);
}

// char *mx_get_path(char *bin) {
//     char *res = NULL;
//     if (bin[0] == '/') {
//         res = mx_strnew(100);
//         readlink("/proc/self/exe", res, 100);
//     }
//     return res;
// }

int mx_get_block_size(char *path, uint8_t *flags) {
    DIR *dirp = opendir(path);
    t_dirent *dir = NULL;
    t_stat file_st;
    int size = 0;

    if (dirp == NULL) return 0;
    while ((dir = readdir(dirp)) != NULL) {
        if (mx_is_flag_valid(dir->d_name, flags)) {
            char full_path[PATH_MAX];
            mx_strcpy(full_path, path);
            if (full_path[mx_strlen(full_path) - 1] != '/') {
                mx_strcat(full_path, "/");
            }
            mx_strcat(full_path, dir->d_name);
            stat(full_path, &file_st);
            size += file_st.st_blocks;
        }
    }
    closedir(dirp);
    return size;
}

char mx_get_file_type(t_stat *file_st) {
    switch (file_st->st_mode & S_IFMT) {
        case S_IFBLK:
            return 'b';
        case S_IFCHR:
            return 'c';
        case S_IFDIR:
            return 'd';
        case S_IFLNK:
            return 'l';
        case S_IFSOCK:
            return 's';
        case S_IFIFO:
            return 'p';
        case S_IFREG:
            return '-';
        default:
            return '-';
    }
}

char *mx_get_permissions(t_stat *file_st) {
    const char *permissions = "rwxrwxrwx";
    mode_t mode = file_st->st_mode;
    size_t mode_count = 9;
    char *res = mx_strnew(mode_count);

    for (size_t i = 0; i < mode_count; i++) {
        res[i] = (mode & (1 << (8 - i))) ? permissions[i] : '-';
    }
    return res;
}

uint16_t mx_get_link_num(t_stat *file_st) {
    return file_st->st_nlink;
}

char *mx_get_owner(t_stat *file_st) {
    t_passwd *pw = (t_passwd *) malloc(sizeof(t_passwd));
    pw = getpwuid(file_st->st_uid);
    if (pw == NULL) {
        return mx_itoa(file_st->st_uid);
    }
    return pw->pw_name;
}

char *mx_get_group(t_stat *file_st) {
    t_group *gr = (t_group *) malloc(sizeof(t_group));
    gr = getgrgid(file_st->st_gid);
    if (gr == NULL) {
        return mx_itoa(file_st->st_gid);
    }
    return gr->gr_name;
}

int mx_get_size(t_stat *file_st) {
    return file_st->st_size;
}

char *mx_get_time(t_timespec time_spec, char *curr_year) {
    char *file_time = ctime((time_t *)&time_spec);
    char *res = mx_strndup(file_time + MNTH_DAY_OFFST, MNTH_DAY_LEN);

    if (mx_strcmp(curr_year, file_time + YR_OFFST) > 0) {
        mx_strncat(res, file_time + YR_OFFST, YR_LEN);
        return res;
    }
    mx_strncat(res, file_time + HR_OFFST, HR_LEN);
    return res;
}

char *mx_get_full_time(t_timespec time_spec) {
    return mx_strndup(ctime((time_t *)&time_spec) + MNTH_DAY_OFFST, FULL_TIME_LEN);
}

int mx_get_serial_num(char *path, char *dir) {
    char full_path[PATH_MAX] = "";
    t_stat file_st;

    mx_strcpy(full_path, path);
    mx_strcat(full_path, dir);

    stat(full_path, &file_st);

    return file_st.st_ino;
}

// char *get_rdev(dev_t st_rdev) {
//     char *str1 = mx_itoa(((st_rdev >> 8) & 0xfff) | ((unsigned int) (st_rdev >> 31) & ~0xfff));
//     char *str2 = mx_itoa((st_rdev & 0xff) | ((unsigned int) (st_rdev >> 12) & ~0xff));
//     char *tmp = mx_strjoin(str1, ". ");
//     char *str = mx_strjoin(tmp, str2);
//     mx_strdel(&str1);
//     mx_strdel(&str2);
//     mx_strdel(&tmp);
//     return str;
// }

char *mx_get_size_h(off_t st_size, uint8_t *flags) {
    if (flags[f_h]) {
        char *str = NULL;
        char *tmp = NULL;
        if (st_size < 1000) {
            str = mx_strjoin(mx_itoa(st_size), "B");
            return str;
        }
        else if (st_size >= 1000 && st_size < 1000000) {
            tmp = mx_double_to_str((double)st_size / BIBYTE);
            str = mx_strjoin(tmp, "K");
            mx_strdel(&tmp);
            return str;
        }
        else if (st_size >= 1000000 && st_size < 1000000000) {
            tmp = mx_double_to_str((double)st_size / BIBYTE / BIBYTE);
            str = mx_strjoin(tmp, "M");
            mx_strdel(&tmp);
            return str;
        }
        else if (st_size >= 1000000000 && st_size < 1000000000000) {
            tmp = mx_double_to_str((double)st_size / BIBYTE / BIBYTE / BIBYTE);
            str = mx_strjoin(tmp, "G");
            mx_strdel(&tmp);
            return str;
        }
    }
    return mx_itoa(st_size);
}
