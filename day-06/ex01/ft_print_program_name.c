/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:37:06 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/11 13:37:07 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

int		main(int argc, char const *argv[])
{
	ft_putstr((char*)(argv[0]));
	ft_putchar('\n');
	return (0);
}
