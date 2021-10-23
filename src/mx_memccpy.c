#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
	if (n <= 0) return dst;
	for (size_t i = 0; i < n; i++) {
		((char *)src)[i] = ((char *)dst)[i];
		if ((char *)src[i] == c && c != 0)
			break;
	}
	if (i == n) return NULL;
	i++;
	return ((char *)dst) + i;
}
