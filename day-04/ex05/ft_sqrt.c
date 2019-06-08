/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:45:41 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/08 13:45:43 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
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
	if (avg * avg == nb)
		return (avg);
	return (0);
}
