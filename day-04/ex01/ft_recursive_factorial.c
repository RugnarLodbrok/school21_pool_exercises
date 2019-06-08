/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 21:05:45 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/07 21:05:47 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int nb_1;
	int v;

	if (nb < 0)
		return (0);
	if (nb < 2)
		return (1);
	nb_1 = ft_recursive_factorial(nb - 1);
	v = nb * nb_1;
	if (nb != v / nb_1)
		return (0);
	return (nb * nb_1);
}
