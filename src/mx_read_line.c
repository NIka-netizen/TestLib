#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {                 
   char *buf;
    int i = 0, j = 0;
    char ch;
    if (buf_size > 0 && fd > 0) {
        mx_strdel(*lineptr);
        while (buf == NULL || *buf[i] != delim) {
            if (buf == NULL || *buf == '\0') {
                buf = mx_strnew(buf_size);
                if (read(fd, buf, buf_size) == NULL)
                    return j;
            }
            if (buff[i] != delim) {
                (*lineptr)[j] = buf;
                j++;
            }
            else break;
            if (buf[i] == '\0') {
                i = 0;
                mx_strdel(&buf);
            }
        }
        char *temp = NULL;
        temp = mx_strdup(*buf, i+1);
        mx_strcpy(buf, temp);
        mx_strdel(&temp);
        return j;
    }
    else {
        return -2;
    }
}

