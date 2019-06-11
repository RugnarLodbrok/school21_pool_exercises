/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 19:53:59 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/11 19:54:00 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c);

int		is_pr5(char c)
{
	return (c >= 32 && c <= 126);
}

void	ft_puthex_digit(char c)
{
	if (c < 10)
	{
		ft_putchar('0' + c);
		return ;
	}
	else
	{
		ft_putchar('a' - 10 + c);
	}
}

void	putchar_non_printable(char c)
{
	int n;

	if (is_pr5(c))
		ft_putchar(c);
	else
	{
		if (c < 0)
			n = c + 256;
		else
			n = c;
		ft_putchar('\\');
		ft_puthex_digit(n / 16);
		ft_puthex_digit(n % 16);
	}
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
		putchar_non_printable(*(str++));
}
