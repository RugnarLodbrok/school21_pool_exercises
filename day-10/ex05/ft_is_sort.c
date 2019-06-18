/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:29:29 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/17 16:29:30 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (!length)
		return (1);
	while (--length)
		if (f(tab[length], tab[length - 1]) < 0)
			return (0);
	return (1);
}
