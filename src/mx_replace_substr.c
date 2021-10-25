#include "../inc/libmx.h"

int mx_index(const char *str, const char *subi, int count) {
	int j = 0;
	int k;

	if (str == NULL || subi == NULL)
		return -2;
	for (int i = 0; i < mx_strlen(str); i++) {
		if (str[i] == subi[j]) {
			k = i;
			while (str[k] == subi[j]) {
				if (j == mx_strlen(subi) - 1 && count == 0)
					return i;
				k++;
				j++;
			}
			count--;
			j = 0;
		}
	}
	return -1;
}

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
	char *news = NULL;
	int j = 0;
	int count = 0;
	int mult = mx_count_substr(str, sub);

	news =  mx_strnew(mx_strlen(str) - mx_strlen(sub) * mult + mx_strlen(replace) * mult);
	if (news == NULL || str == NULL || sub == NULL || replace == NULL)
		return NULL;
	for (int i = 0; i < mx_strlen(str); i++) {
		if (i == mx_index(str, sub, count)) {
			mx_strcpy(&news[j], replace);
			i = i + mx_strlen(sub);
			j = j + mx_strlen(replace);
			count++;
		}
		news[j] = str[i];
		j++;
	}
	return news;
}

