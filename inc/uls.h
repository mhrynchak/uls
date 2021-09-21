#pragma once
#include "structs.h"
#include <dirent.h>
#include <sys/ioctl.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>

enum flag {
    f_1,            //force output to be one entry per line
    f_A,            //list all entries except for . and ...
    f_S,            //sort files by size
    f_T,            //display complete time information for the file
    f_a,            //include hidden directory entries
    f_c,            //use time when file status was last changed for sorting
    f_g,            //list in long format, but omit the owner id.
    f_o,            //list in long format, but omit the group id.
    f_h,            //use unit suffixes
    f_i,            //print the file's serial number
    f_l,            //list in long format
    f_r,            //reverse the order of the sort
    f_t,            //sort by time modified
    f_u,            //use time of last access of the file for sorting
};

//base functions
void mx_parse_input(int argc, char **argv, t_ls *ls);
void mx_run(t_ls *ls);

//utils
void mx_add_flags(t_ls *ls, char *flags);
void mx_parse_contents(char *path, t_ls *ls);

//cmp functions
bool mx_cmp(void *data1, void *data2);
bool mx_cmp_r(void *data1, void *data2);
int cmp_ascii(const void *data1, const void *data2);
int cmp_ascii_r(const void *data1, const void *data2);
int cmp_size(const void *data1, const void *data2);
int cmp_size_r(const void *data1, const void *data2);
int cmp_time(const void *data1, const void *data2);
int cmp_time_r(const void *data1, const void *data2);

//printing
void mx_print_files(t_ls *ls);
void mx_print_files_long(uint8_t *flags, t_obj *objs);
void mx_print_file_long(uint8_t *flags, t_obj obj);
void mx_print_file(t_ls *ls, char *file);

//validators
int mx_is_valid_file(char *file);
bool mx_is_flag_valid(char *file, uint8_t *flags);

//getters
int mx_get_block_size(char *path, uint8_t *flags);
char mx_get_file_type(t_stat *file_st);
char *mx_get_permissions(t_stat *file_st);
uint16_t mx_get_link_num(t_stat *file_st);
char *mx_get_owner(t_stat *file_st);
char *mx_get_group(t_stat *file_st);
int mx_get_size(t_stat *file_st);
char *mx_get_time(t_timespec time_sec, char *curr_year);
char *mx_get_full_time(t_timespec time_sec);
char *mx_get_curr_year();
int mx_get_serial_num(char *path, char *dir);
t_obj *mx_init_objs(t_ls *ls);
t_obj mx_new_obj(t_ls *ls, char *file);
void sortobjs(void *arr, size_t size, size_t bytes,
             int (*cmp)(const void *, const void *));
char *mx_double_to_str(double n);
char *mx_get_size_h(off_t st_size, uint8_t *flags);
char *get_rdev(dev_t st_rdev);

//error handling
void mx_invalid_flag(char flag);
void mx_invalid_file(char *file);
void mx_invalid_permisson(char *file);

//cleaning pack
void mx_clean_obj(t_obj obj);
void mx_clean_objs(t_obj **objs);
