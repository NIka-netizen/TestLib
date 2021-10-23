#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim)  {
    if (arr && delim)  {
        while (arr[i])  {
            if (i  !=  0)  mx_printstr(delim);
            mx_printstr(arr[i]);
            i++;
        }
        mx_printstr("\n");
    }
}
