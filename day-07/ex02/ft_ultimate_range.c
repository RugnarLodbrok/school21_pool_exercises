/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 18:05:33 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/12 18:05:34 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range2(int min, int max)
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

int	ft_ultimate_range(int **range, int min, int max)
{
	*range = ft_range2(min, max);
	if (!*range)
		return (0);
	return (max - min);
}
