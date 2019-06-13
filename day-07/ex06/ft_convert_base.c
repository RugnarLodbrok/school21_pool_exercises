/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:14:00 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/12 21:14:01 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			validate_base(char *base)
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

int			count_digits(long int nbr, int basen)
{
	int i;

	i = 0;
	if (nbr < 0)
		i++;
	while (nbr)
	{
		i++;
		nbr /= basen;
	}
	if (!i)
		return (1);
	return (i);
}

int			parse_positive(char *str, char *base, int basen)
{
	char	*ptr;
	int		i;
	int		v;

	v = 0;
	while (*str)
	{
		i = 0;
		ptr = base;
		while (*ptr)
		{
			if (*str == *ptr)
				break ;
			i++;
			ptr++;
		}
		if (i >= basen)
			break ;
		v *= basen;
		v -= i;
		str++;
	}
	return (v);
}

long int	ft_atoi_base(char *str, char *base)
{
	int		basen;
	int		v;
	int		is_positive;

	basen = validate_base(base);
	if (!basen)
		return (0);
	is_positive = 0;
	if (*str == '+' || *str == '-')
	{
		is_positive = -1;
		if (*str == '+')
			is_positive = 1;
		str++;
	}
	v = parse_positive(str, base, basen);
	v *= -(is_positive + !is_positive);
	return (v);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			basen;
	int			n;
	char		*ret;
	long int	nb;

	nb = ft_atoi_base(nbr, base_from);
	basen = validate_base(base_to);
	if (!basen)
		return (0);
	n = count_digits(nb, basen);
	ret = malloc(sizeof(char) * (n + 1));
	if (!ret)
		return (0);
	ret[0] = '-';
	if (nb < 0)
		nb *= -1;
	if (!nb)
		ret[0] = '0';
	ret[n] = 0;
	while (n-- && (nb % basen))
	{
		ret[n] = *(base_to + (nb % basen));
		nb /= basen;
	}
	return (ret);
}
