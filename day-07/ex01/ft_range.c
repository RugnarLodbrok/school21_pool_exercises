/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:55:48 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/12 13:55:49 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *a;
	int *ptr;

	a = (int*)malloc((max - min) * sizeof(int));
	ptr = a;
	if (a)
	{
		while (min < max)
		{
			*ptr = min;
			ptr++;
			min++;
		}
	}
	return (a);
}
