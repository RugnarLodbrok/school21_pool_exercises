/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:03:34 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/18 14:03:35 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *e;

	if (*begin_list)
	{
		e = *begin_list;
		while (e->next)
			e = e->next;
		e->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}
