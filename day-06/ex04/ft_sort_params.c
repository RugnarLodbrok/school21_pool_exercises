/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:55:50 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/11 13:55:50 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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
		write(1, &c, 1);
		i++;
	}
}

void	ft_swap(char **a, char **b)
{
	char *c;

	c = *a;
	*a = *b;
	*b = c;
}

int		ft_strcmp(char *s1, char *s2)
{
	while (1)
	{
		if (*s1 - *s2)
			return (*s1 - *s2);
		if (!(*s1 && *s2))
			break ;
		s1++;
		s2++;
	}
	return (0);
}

void	sort(char *items[], int size)
{
	int i;

	while (size--)
	{
		i = 0;
		printf("size: %d\n", size);
		while (i < size)
		{
			if (ft_strcmp(items[i], items[i + 1]) > 0)
				ft_swap(items + i, items + i + 1);
			++i;
		}
	}
}

int		main(int argc, char const *argv[])
{
	int		i;
	char	*items[argc - 1];

	i = 1;
	while (i < argc)
	{
		items[i - 1] = (char*)(argv[i]);
		++i;
	}
	sort(items, argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		ft_putstr((char*)(items[i]));
		ft_putstr("\n");
		i++;
	}
	return (0);
}
