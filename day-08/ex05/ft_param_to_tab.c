/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:14:28 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/13 15:14:29 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

char				**ft_split_whitespaces(char *str);

int					ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*(str + len) != '\0')
	{
		len++;
	}
	return (len);
}

char				*ft_strdup(char *src)
{
	char *dst;
	char *ret;

	ret = (char*)malloc((size_t)ft_strlen(src) + 1);
	if (!ret)
		return (ret);
	dst = ret;
	while ((*ret++ = *src++))
		;
	return (dst);
}

int					ft_strcmp(char *s1, char *s2)
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

char				*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while ((dest[i] = src[i]))
		i++;
	return (dest);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int			i;
	t_stock_par	*box;
	t_stock_par	*ret;

	i = 0;
	ret = (struct s_stock_par*)malloc(sizeof(struct s_stock_par) * (ac + 1));
	while (i < ac)
	{
		box = ret + i;
		box->size_param = ft_strlen(av[i]);
		box->str = av[i];
		box->copy = ft_strdup(av[i]);
		box->tab = ft_split_whitespaces(av[i]);
		i++;
	}
	ret[i].str = 0;
	return (ret);
}
