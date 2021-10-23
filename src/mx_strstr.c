#include "../inc/libmx.h"

char* mx_strstr(const char* s1, const char* s2) {
    int m, j = 0, i = 0;

    while (i < mx_strlen(s1)) {
        if (mx_strchr((char*)s1, s2[0])) {
            m = i;
            while (s1[m] == s2[j]) {
                if (j == mx_strlen(s2) - 1) return (char*)&s1[i];
                m++;
                j++;
            }
            j = 0;
        }
        i++;
    }
    return NULL;
}
