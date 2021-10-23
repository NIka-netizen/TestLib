#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    int l = mx_strlen(s);
    
    int i = 0;

    while (s[i] != ' ') {
        mx_swap_char(&s[i], &s[l - 1]);
        i++;
        l--;
    }
}

