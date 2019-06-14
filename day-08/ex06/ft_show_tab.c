/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:06:41 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/14 13:06:42 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (1)
	{
		c = *(str + i);
		if (!c)
			break ;
		ft_putchar(c);
		i++;
	}
}

void	ft_print_words_tables(char **tab)
{
	while (*tab)
	{
		ft_putstr(*tab);
		tab++;
		ft_putchar('\n');
	}
}

void	ft_put_positive(int nb)
{
	int a;
	int b;

	if (!nb)
		return ;
	a = nb / 10;
	b = nb - a * 10;
	ft_put_positive(a);
	ft_putchar('0' + b);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(-2);
		ft_putnbr(147483648);
		return ;
	}
	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		ft_put_positive(-nb);
		return ;
	}
	ft_put_positive(nb);
}

void	ft_show_tab(struct s_stock_par *par)
{
	char **word;

	while (par->str)
	{
		ft_putstr(par->str);
		ft_putchar('\n');
		ft_putnbr(par->size_param);
		ft_putchar('\n');
		word = par->tab;
		ft_print_words_tables(word);
		par++;
	}
}
