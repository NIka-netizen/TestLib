#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
	int j = 0;
	int k;

	if (str == NULL || sub == NULL)
		return -2;
	for (int i = 0; i < mx_strlen(str); i++) {
		if (str[i] == sub[j]) {
			k = i;
			while (str[k] == sub[j]) {
				if (j == mx_strlen(sub) - 1)
					return i;
				k++;
				j++;
			}
			j = 0;
		}
	}
	return -1;
}

