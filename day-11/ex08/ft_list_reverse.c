/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:19:34 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/18 15:19:35 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *a;
	t_list *b;
	t_list *c;

	a = *begin_list;
	c = 0;
	while (a)
	{
		b = c;
		c = a;
		a = c->next;
		c->next = b;
	}
	*begin_list = c;
}
