#include "libmx.h"

char *mx_file_to_str(const char *file) {
    char *string = NULL;
    int length = file ? mx_get_file_length(file) : 0;

    if (file && length > 0 && (string = malloc(length + 1))) {
        int stream = open(file, 0);

        read(stream, string, length);
        close(stream);
    }
    return string;
}

// char *mx_file_to_str(const char *filename) {
//     int fd = open(filename, O_RDONLY), byte = 0, size = 0;
//     char *str = NULL;
//     char buff[80];

//     if (fd == -1) return NULL;

//     byte = read(fd, &buff, sizeof(buff));
//     while (byte != 0) {
//         size += byte;
//         byte = read(fd, &buff, sizeof(buff));
//     }
//     close(fd);
//     str = mx_strnew(size);

//     fd = open(filename, O_RDONLY);
//     byte = read(fd, str, size);
//     close(fd);
//     return str;
// }
