/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 19:45:33 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/18 19:45:34 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opp.h"
#include "ft_usage.h"
#include "utils.h"
#include "ops.h"
#include "ft_opp.h"

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

int		ft_usage(int a, int b)
{
	b++;
	a = 0;
	ft_putstr("error : only [ ");
	while (a < 5)
	{
		ft_putstr(g_opptab[a].literal);
		ft_putstr(" ");
		a++;
	}
	ft_putstr("] are accepted.\n");
	return (0);
}

void	*resolve_operator(char *str)
{
	int		i;
	void	*f;

	f = 0;
	i = 0;
	while (i < 6)
	{
		if (!ft_strcmp(g_opptab[i].literal, str))
			f = g_opptab[i].f;
		else if (!ft_strcmp(g_opptab[i].literal, "") && !f)
			f = g_opptab[i].f;
		i++;
	}
	return (f);
}
