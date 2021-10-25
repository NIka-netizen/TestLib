#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    int m = 0, i = 0, f = 0;

    if (c == ' ') {
        while (str[i] != '\0') {
            if (str[i] == c && str[i + 1] == '\0') break;
            if (str[i] != ' ' && str[i + 1] == ' ') m++;
            i++;
        }
    }
    else if (c != ' ') {
        while (str[i] != '\0') {
            if (str[i] == ' ' && str[i + 1] != ' ') m++;
            if (str[i] == c) f = m;
            i++;
        } 
        m = f + 1;
        if (str[0] == ' ') m = f;  
    }
    return m;
}

