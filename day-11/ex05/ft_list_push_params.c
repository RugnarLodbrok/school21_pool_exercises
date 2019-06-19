/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:42:41 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/18 14:42:41 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *e;

	e = ft_create_elem(data);
	e->next = *begin_list;
	*begin_list = e;
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*l;

	l = 0;
	if (ac < 2)
		return (l);
	ac--;
	av++;
	while (ac--)
		ft_list_push_front(&l, *av++);
	return (l);
}
