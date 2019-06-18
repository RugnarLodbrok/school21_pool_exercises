/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 19:09:08 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/18 19:09:09 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_sort_wordtab(char **tab)
{
	unsigned int i;
	unsigned int size;

	size = 0;
	while (tab[size])
		size++;
	while (size--)
	{
		i = 0;
		while (i < size)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
				ft_swap(tab + i, tab + i + 1);
			++i;
		}
	}
}
