#include "../inc/libmx.h"

int mx_get_char_index(const char *str, char c) {
    int i;
    if (str == NULL) return -2;
    else {
        while (str[i]) {
                if (str[i] == c) return i;
                i++;
        }
        return -1;
    }
}
