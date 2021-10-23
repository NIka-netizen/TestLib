#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
	int i = 0;
    if (str && sub) {
        int l = mx_strlen(sub);
        while (*str) {
            if (*str == '\0')
                return -1;
			if (*str == *sub) {
				if(mx_strncmp(str, sub, n) == 0) return i;
			}
			i++;
            str++;
        }
    }
	else return -2;
}
