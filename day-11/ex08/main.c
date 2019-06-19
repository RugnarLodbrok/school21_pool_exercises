#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list);

t_list	*ft_create_elem(void *data)
{
	t_list *e;

	e = malloc(sizeof(t_list));
	if (e)
	{
		e->data = data;
		e->next = NULL;
	}
	return (e);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *e;

	e = ft_create_elem(data);
	e->next = *begin_list;
	*begin_list = e;
}

void print_ll(t_list *ll)
{
	while (ll)
	{
		printf("[%s]->", ll->data);
		ll = ll->next;
	}
}

int main(int argc, char const *argv[])
{
	t_list *ll;

	ll = 0;
	ft_list_push_front(&ll, "1");
	ft_list_push_front(&ll, "2");
	ft_list_push_front(&ll, "3");
	ft_list_push_front(&ll, "4");
	ft_list_push_front(&ll, "5");
	print_ll(ll);
	printf("\n");
	ft_list_reverse(&ll);
	print_ll(ll);
	printf("\n");

	return 0;
}