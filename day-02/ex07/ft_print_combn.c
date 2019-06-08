/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 19:34:34 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/06 19:34:35 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_put_positive2(int nb, int digits)
{
	int a;
	int b;

	if (!nb)
	{
		if (digits > 0)
		{
			ft_putchar('0');
			ft_put_positive2(nb, digits - 1);
			return ;
		}
		return ;
	}
	a = nb / 10;
	b = nb - a * 10;
	ft_put_positive2(a, digits - 1);
	ft_putchar('0' + b);
}

int		count_bits(int n)
{
	int count;

	count = 0;
	while (n)
	{
		count += n & 1;
		n >>= 1;
	}
	return (count);
}

int		bit_mask_to_number(int n)
{
	int i;
	int v;
	int nn;

	nn = n;
	v = 0;
	i = 0;
	while (n)
	{
		if (n & 1)
		{
			v *= 10;
			v += i;
		}
		n >>= 1;
		i++;
	}
	return (v);
}

void	ft_print_combn(int n)
{
	int		i;
	char	is_first;

	i = -1;
	is_first = 1;
	while (i++ < 1023)
	{
		if (count_bits(i) == n)
		{
			if (is_first)
				is_first = 0;
			else
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			ft_put_positive2(bit_mask_to_number(i), n);
		}
	}
}
