#pragma once
#include "libmx.h"

#define MX_FLAGS "ASTacghilortu1"
#define MX_USAGE "usage: uls [-" MX_FLAGS "] [file ...]"
#define MX_INVLD_FILE ": No such file or directory"
#define MX_INVLD_PERM ": Permission denied"

#define HR_LEN 5
#define MNTH_DAY_LEN 7
#define YR_LEN 4
#define FULL_TIME_LEN 20

#define HR_OFFST 11
#define MNTH_DAY_OFFST 4
#define YR_OFFST 20

#define BIBYTE 1024

#define SUCCESS 1

typedef struct dirent t_dirent;
typedef struct stat t_stat;

typedef struct passwd t_passwd;
typedef struct group t_group;
typedef struct timespec t_timespec;

typedef struct s_ls {
    char *curr_year;
    char *curr_dir;
    char *separator;
    bool (*cmp_func)(void *, void *);
    uint8_t flags[17];
    uint8_t obj_num;
    uint8_t namlen;
    t_list *dirs;
    t_list *non_existent;
    t_list *files;
    t_list *contents;
}              t_ls;

typedef struct s_obj {
    int serial_num;
    char *d_name;
    char file_type;
    char *permissions;
    uint16_t links;
    char *owner;
    char *group;
    int size;
    char *size_h;
    char *time;
    t_timespec time_sec;
}              t_obj;
