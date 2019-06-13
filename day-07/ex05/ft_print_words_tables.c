/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 20:21:26 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/12 20:21:27 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (1)
	{
		c = *(str + i);
		if (c == '\0')
			break ;
		ft_putchar(c);
		i++;
	}
}

void	ft_print_words_tables(char **tab)
{
	while (*tab)
	{
		ft_putstr(*tab++);
		ft_putchar('\n');
	}
}
