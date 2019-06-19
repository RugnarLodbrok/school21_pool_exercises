/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:51:31 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/18 14:51:31 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *a;
	t_list *b;

	a = *begin_list;
	if (!a)
		return ;
	while (a)
	{
		b = a->next;
		free(a);
		a = b;
	}
	*begin_list = 0;
}
