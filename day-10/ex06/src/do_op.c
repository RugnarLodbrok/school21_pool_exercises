/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:36:17 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/17 16:36:18 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "utils.h"

void	*resolve_operator(char *str)
{
	if (!*str)
		return (0);
	if (*(str + 1))
		return (0);
	if (*str == '+')
		return (add);
	if (*str == '-')
		return (sub);
	if (*str == '/')
		return (div);
	if (*str == '*')
		return (mul);
	if (*str == '%')
		return (mod);
	return (0);
}

int		ft_atoi(char *str)
{
	int v;
	int is_positive;

	v = 0;
	is_positive = 0;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		is_positive = -1;
		if (*str == '+')
			is_positive = 1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			break ;
		v *= 10;
		v -= *str - '0';
		str++;
	}
	v *= -(is_positive + !is_positive);
	return (v);
}

int		check_div0(int b, void *f)
{
	if (b == 0)
	{
		if (f == div)
		{
			ft_putstr("Stop : division by zero\n");
			return (0);
		}
		if (f == mod)
		{
			ft_putstr("Stop : modulo by zero\n");
			return (0);
		}
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	int a;
	int b;
	int (*operator)(int, int);

	if (argc != 4)
		return (0);
	operator = resolve_operator(argv[2]);
	if (!operator)
	{
		ft_putstr("0\n");
		return (0);
	}
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (!check_div0(b, operator))
		return (0);
	ft_putnbr(operator(a, b));
	ft_putchar('\n');
	return (0);
}
