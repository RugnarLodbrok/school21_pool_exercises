/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 21:22:08 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/07 21:22:10 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int r;
	int v;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	v = ft_recursive_power(nb, power - 1);
	r = v * nb;
	if (v != r / nb)
		return (0);
	return (r);
}
