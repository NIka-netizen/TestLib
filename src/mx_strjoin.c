#include "../inc/libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
	char *s3;

	if (!s1 && !s2)
		return NULL;
	if (!s1)
		return (mx_strdup(s2));
	if (!s2)
		return (mx_strdup(s1));
	if (!(s3 = mx_strnew(mx_strlen(s1) + mx_strlen(s2))))
		return NULL;
	s3 = mx_strdup(s1);
	mx_strcat(s3, s2);

	return s3;
	return NULL;
}
