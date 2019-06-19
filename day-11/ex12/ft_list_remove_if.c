/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:41:33 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/18 18:41:34 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*ptr;
	t_list	*prev;
	t_list	*for_delete;

	prev = 0;
	for_delete = 0;
	ptr = *begin_list;
	while (ptr)
	{
		if (!cmp(ptr->data, data_ref))
		{
			if (!prev)
				*begin_list = ptr->next;
			else
				prev->next = ptr->next;
			for_delete = ptr;
			ptr = ptr->next;
			free(for_delete);
		}
		else
		{
			prev = ptr;
			ptr = ptr->next;
		}
	}
}
