#include "../inc/libmx.h""

int mx_list_size(t_list *list) {
	if (!list) {
		return 0;
	}

	int i = 0;
	while (list != NULL) {
		i++;
		list = list->next;
	}

	return i;
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

	int i = 1, 
	o = 4,
	h = 0; 
	void *d = &i, 
	*f = &o,
	*u = &h;

	mx_push_back(&l, d);
	mx_push_back(&l, d); 
	mx_push_back(&l, f); 

	int m;
	m = mx_list_size(l);
	printf("%d\n", m);

	return 0;
}
