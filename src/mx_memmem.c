#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
	char *big2 = (char *) big;
	char *little2 = (char *) little;

	if (big_len >= little_len && big_len > 0 && little_len > 0) {
		while (*big2) {
			if (*big2 == *little2)
				if (mxstrncmp(big2, little2, little_len) == 0) return ((char*)big2);
			++big2;	
		}
	}
	return NULL;
}
