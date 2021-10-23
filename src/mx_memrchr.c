#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
	char *str = (char *)s;

	for (size_t i = n; i > 0; i--; str--) {
		if (*str == c)
			return &str[i];
	}
	return NULL;
}
