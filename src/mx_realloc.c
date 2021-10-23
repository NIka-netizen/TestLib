#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size)
{
    void *c = NULL;

    if (ptr == NULL) {
        return NULL;
    }
    
    if (malloc_size(ptr) > size) {
        c = (void *)malloc(malloc_size(ptr));
        size = len;
    }
    else c = (void *)malloc(size);

    mx_memcpy(c, ptr, malloc_size(ptr));
    free(ptr);
    ptr = NULL;
    return c;
}
