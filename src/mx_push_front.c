#include "../inc/libmx.h"

void mx_push_front(t_list **list, void *data) {
	if (!*list) {
        *list = mx_create_node(data);
        return;
    }
    t_list *temp = mx_create_node(data);
    temp -> next = *list;
    *list = temp;
}

int main()
{
	t_list *l = NULL;
	int i = 1, o = 4; void *d = &i, *f = &o;
	mx_push_front(&l, d);

	printf("%p\n", l->data);

	mx_push_front(&l, f);

	printf("%p\n", l->data);

	return 0;
}
