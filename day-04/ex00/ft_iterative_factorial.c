/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 20:51:11 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/07 20:51:12 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int r;
	int v;

	r = 1;
	if (nb < 0)
		return (0);
	while (nb > 1)
	{
		v = r * nb;
		if (r > v / nb)
			return (0);
		r = v;
		nb--;
	}
	return (r);
}
