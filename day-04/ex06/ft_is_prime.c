/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:11:28 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/08 15:11:30 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	int_sqrt(int nb)
{
	int r;
	int div;
	int avg;

	if (nb < 1)
		return (0);
	r = 1;
	while (1)
	{
		div = nb / r;
		avg = (r + div) / 2;
		if (avg == r || div == avg)
			break ;
		r = avg;
	}
	if (r > div)
		return (div);
	return (r);
}

int	is_divisible(int a, int b)
{
	return (a == (a / b * b));
}

int	ft_is_prime(int nb)
{
	int i;
	int sq;

	sq = int_sqrt(nb);
	if (nb < 2)
		return (0);
	i = 1;
	while (++i <= sq)
	{
		if (is_divisible(nb, i))
			return (0);
	}
	return (1);
}
