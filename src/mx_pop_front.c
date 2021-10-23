#include "../inc/libmx.h"

void mx_pop_front(t_list **list) {
	if (!*list)
		return;

	t_list *temp;

	temp = (*list)->next;
	free(*list);
	*list = temp;
}

void mx_push_back(t_list **list, void *data) {
	if (!*list) {
        *list = mx_create_node(data);
        return;
    }
    else {
    	t_list *temp = *list;
    	while (temp -> next) 
        	temp = temp -> next;
    	temp -> next = mx_create_node(data);
    }
}

int main()
{
	t_list *l = NULL;
	int i = 1, o = 4; void *d = &i, *f = &o;
	mx_push_back(&l, d); 
	printf("%p\n", l->data); 
	mx_push_back(&l, f); 
	/*l = l->next;
	printf("%p\n", l->data); */

	mx_pop_front(&l);

	if (l == NULL)
		printf("%s\n", "null");

	printf("%p\n", l->data); 

	return 0;
}
