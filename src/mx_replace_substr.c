#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
	int i, j = 0;
	char arr = mx_strnew(mx_strlen(str) - (mx_count_substr(str, sub) * mx_strlen(sub)) + mx_strlen(replace));
	if (str || sub || replace || mx_strlen(str) <= mx_strlen(sub)) {
		while (*str != '\0') {
			if (*str == *sub) {
				if (mx_strncmp(str, sub, mx_strlen(sub)) == 0) {
					i = 0;
					while (replace[i] != '\0') {
						arr[j] = replace[i];
						i++;
						j++;
					}
					str = str + mx_strlen(sub) - 1;
				}
				else {
					arr[j] = *str;
					j++;
				}
			}
			else {
				arr[j] = *str;
				j++;
			}
			str++;
		}
		return arr;
	}
	else {
		return NULL;
	}
}
