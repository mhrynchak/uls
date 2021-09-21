#pragma once

#if defined(__APPLE__)
#include <malloc/malloc.h>
#define mx_malloc_size(x) malloc_size(x)
#elif defined(_WIN64) || defined(_WIN32)
#include <malloc.h>
#define mx_malloc_size(x) _msize(x)
#elif defined(__linux__)
#include <malloc.h>
#define mx_malloc_size(x) malloc_usable_size(x)
#endif

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MX_MIN(x, y, type) (((type)x) < ((type)y) ? (x) : (y))
#define MX_MAX(x, y, type) (((type)x) > ((type)y) ? (x) : (y))

typedef struct s_list {
    void *data;
    struct s_list *next;
}              t_list;

//Utils pack
void mx_printchar(char c);
void mx_printstr(const char *s);
void mx_print_strarr(char **arr, const char *delim);
void mx_printint(int n);
int64_t mx_get_file_length(const char *filename);
char *mx_nbr_to_hex(unsigned long nbr);
unsigned long mx_hex_to_nbr(const char *hex);
int mx_bubble_sort(int *arr, int size);
int mx_quicksort(int *arr, int left, int right);
char *mx_itoa(int number);
void mx_print_unicode(wchar_t c);
double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);
short mx_intlen(int a);
void mx_foreach(const int *arr, int size, void(*f)(int));
int mx_binary_search(char **arr, int size, const char *s, int *count);
void mx_swap(void *restrict v1, void *restrict v2, size_t size);
void mx_printerr(const char *s);
void mx_swap_int(int *a, int *b);
int mx_atoi(const char *str);
bool mx_isalpha(int c);
bool mx_isdigit(int c);
bool mx_islower(int c);
bool mx_isupper(int c);
bool mx_isspace(char c);
int mx_tolower(int c);

//Strings pack
int mx_strlen(const char *s);
void mx_swap_char(char* s1, char* s2);
char *mx_strcpy(char* dst, const char* src);
int mx_strcmp(const char* s1, const char* s2);
int mx_strcmp_ignore_case(const char *s1, const char *s2);
char* mx_strcat(char* s1, const char* s2);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);
char *mx_strjoin(char const *s1, char const *s2);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
void mx_del_intarr(int **arr, int num);
char *mx_file_to_str(const char *filename);
int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd);
char *mx_strncpy(char *dst, const char *src, int len);
void mx_str_reverse(char *str);
char *mx_strndup(const char *str, size_t len);
char *mx_strstr(const char *s1, const char *s2);
int mx_count_words(const char *str, char delimeter);
int mx_count_substr(const char *str, const char *sub);
int mx_get_char_index(const char *str, char c);
int mx_get_substr_index(const char *str, const char *sub);
char *mx_strtrim(const char* str);
char *mx_del_extra_spaces(const char *str);
char **mx_strsplit(char const *s, char c);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);
char *mx_strchr(const char *s, int c);
int mx_strncmp(const char* s1, const char* s2, int n);
char *mx_strncat(char *restrict s1, const char *restrict s2, int n);
char *mx_double_to_str(double n);

//Memory pack
void *mx_memset(void *b, int c, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_realloc(void *ptr, size_t size);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);

//List pack
t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_front(t_list **list);
void mx_pop_back(t_list **list);
int mx_list_size(t_list *list);
bool mx_is_empty(t_list *list);
t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void*b));
// void mx_push_index(t_list **list, void *data, int index);
// void mx_pop_index(t_list **list, int index);
// void mx_clear_list(t_list **list);
// void mx_foreach_list(t_list *list, void(*f)(t_list *node));
// void mx_del_node_if(t_list **list, void *del_data, bool (*cmp)(void *a, void *b));
