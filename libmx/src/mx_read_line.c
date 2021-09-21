#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    *lineptr = mx_strnew(buf_size);
    int byte, i = 0;
    char buff;
    
    if (fd == -1) return -2;

    byte = read(fd, &buff, sizeof(buff));
    if (byte == 0) return -1;

    while (byte != 0 && buff != delim) {
        (*lineptr)[i]  = buff;
        byte = read(fd, &buff, sizeof(buff));
        if (byte == 0) return -1;
        i++;
    }
    return i;
}

// int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
//     size_t len = 0;
//     size_t t_size = 0;
//     int i, j;
//     int byte = 0;
//     int count = 0;
//     int eof = 0;
//     char *buf = NULL;
//     char *bufend = NULL;
//     static char *tail;
  
//     if (read(fd, NULL, 0) < 0) {
//         *lineptr = mx_realloc(*lineptr, 0);
//         return -2;
//     }
    
//     mx_strdel(lineptr);
//     *lineptr = mx_strnew(0);
//     buf = mx_strnew(buf_size);
//     bufend = mx_strnew(buf_size);

    
//     while ((eof = read(fd, buf, buf_size)) > 0) {
//         len++;
//         if (tail) {
//             t_size = (size_t)mx_strlen(tail);
//             buf = mx_realloc(buf, buf_size + t_size);
//             buf = mx_strjoin(tail, buf);
//             mx_strdel(&tail);
//             if ((byte = mx_get_char_index(buf, delim)) < 0) {
//                 *lineptr = mx_realloc(*lineptr, buf_size + t_size);
//                 *lineptr = mx_strcat(*lineptr, buf);
//                 count = buf_size + t_size;   
//             }
//             else {
//                 count = byte;
//                 bufend = mx_strncpy(bufend, buf, byte);
//                 *lineptr = mx_realloc(*lineptr, byte + 1);
//                 *lineptr = mx_strcat(*lineptr, bufend);
//                 tail = mx_strnew(buf_size + t_size - byte - 1);
//                 for (i = 0, j = byte + 1; j < (int) (buf_size + t_size); j++, i++) {
//                     tail[i] = buf[j];
//                 }
//                 break;
//             }        
//             mx_strdel(&buf);
//             buf = mx_strnew(buf_size);
//         }
//         else if (buf_size == 1) {
//             if (buf[0] != delim) {
//                 *lineptr = mx_realloc(*lineptr, t_size + len - 1);
//                 *lineptr = mx_strjoin(*lineptr, buf);
//             }
//             else {
//                 byte = count;
//                 len--;
//                 break;

//             }
//         } 
//         else {
//             if ((byte = mx_get_char_index(buf, delim)) < 0) {
//                 *lineptr = mx_realloc(*lineptr, buf_size * len + 1);
//                 *lineptr = mx_strcat(*lineptr, buf);
//             }
//             else {
//                 *lineptr = mx_realloc(*lineptr, buf_size * len + byte);
//                 bufend = mx_strncpy(bufend, buf, byte); 
//                 *lineptr = mx_strcat(*lineptr, bufend);
//                     tail = mx_strnew(buf_size - byte - 1);
//                     for (i = 0, j = byte + 1; j < (int)buf_size; j++, i++) {
//                         tail[i] = buf[j];
//                     }
//                 break;
//             }
//         }
//     }
//     if (eof == 0) free (tail);
//     if (buf) free(buf);
//     if (bufend) free(bufend);

//     if (!lineptr)
//         return -2;
//     if (len == 0 && byte <=0)
//         return -1;    
   
//     return (len - 1) * buf_size + byte;
// }
