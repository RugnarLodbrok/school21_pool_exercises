/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 21:16:21 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/10 21:16:23 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c);

int		is_pr2(char c)
{
	return (c >= 32 && c <= 126);
}

int		validate_base(char *base)
{
	char	*ptr;
	int		i;
	int		vals[95];

	ptr = base;
	i = -1;
	while (i++ < 95)
		vals[i] = 0;
	i = 0;
	while (*ptr)
	{
		if (!is_pr2(*ptr))
			return (0);
		if (*ptr == '+' || *ptr == '-')
			return (0);
		if (vals[(*ptr) - 32])
			return (0);
		vals[(*ptr) - 32] = 1;
		i++;
		ptr++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_put_negative_base(int nb, char *base, int basen)
{
	int a;
	int b;

	if (!nb)
		return ;
	a = nb / basen;
	b = nb % basen;
	ft_put_negative_base(a, base, basen);
	ft_putchar(*(base - b));
}

void	ft_putnbr_base(int nbr, char *base)
{
	int basen;

	basen = validate_base(base);
	if (!basen)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_put_negative_base(nbr, base, basen);
	}
	else
		ft_put_negative_base(-nbr, base, basen);
}
