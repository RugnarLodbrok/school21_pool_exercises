/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:49:28 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/18 13:49:29 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

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
