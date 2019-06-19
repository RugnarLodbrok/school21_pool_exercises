/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:05:57 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/18 15:05:58 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	if (!begin_list)
		return (0);
	while (nbr--)
	{
		if (!begin_list->next)
			return (0);
		begin_list = begin_list->next;
	}
	return (begin_list);
}
