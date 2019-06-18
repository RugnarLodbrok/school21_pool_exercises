/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:08:35 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/17 16:08:36 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *ret;

	ret = malloc(sizeof(int) * length);
	i = -1;
	if (ret)
		while (++i < length)
			ret[i] = f(tab[i]);
	return (ret);
}
