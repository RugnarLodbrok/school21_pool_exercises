/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:53:35 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/07 18:53:38 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap2(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

int		*q_sort_iteration(int *ptr, int i, int *reverse)
{
	if (!*reverse)
	{
		if (*ptr > *(ptr + i))
		{
			ft_swap2(ptr, ptr + i);
			*reverse = !*reverse;
			ptr = ptr + i;
		}
	}
	else
	{
		if (*ptr < *(ptr - i))
		{
			ft_swap2(ptr, ptr - i);
			*reverse = !*reverse;
			ptr = ptr - i;
		}
	}
	return (ptr);
}

void	ft_sort_integer_table(int *tab, int size)
{
	int *p;
	int i;
	int reverse;

	i = size - 1;
	p = tab;
	reverse = 0;
	while (i > 0)
	{
		p = q_sort_iteration(p, i, &reverse);
		i--;
	}
	if (p - tab > 1)
		ft_sort_integer_table(tab, p - tab);
	if (tab + size - p - 1 > 1)
		ft_sort_integer_table(p + 1, tab + size - p - 1);
}
