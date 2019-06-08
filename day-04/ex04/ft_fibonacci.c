/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 21:28:50 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/07 21:28:52 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int f_1;
	int r;

	if (index < 0)
		return (-1);
	if (!(index >> 1))
		return (index);
	f_1 = ft_fibonacci(index - 1);
	r = f_1 + ft_fibonacci(index - 2);
	if (r < f_1)
		return (0);
	return (r);
}
