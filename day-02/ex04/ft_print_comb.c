/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:49:20 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/05 18:49:22 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_put_comma(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_digits(int a, int b, int c)
{
	ft_putchar('0' + a);
	ft_putchar('0' + b);
	ft_putchar('0' + c);
}

void	ft_print_comb(void)
{
	int		i;
	int		j;
	int		k;
	int		n;
	char	is_first;

	n = 10;
	is_first = 1;
	i = 0;
	while (i++ < n)
	{
		j = i;
		while (j++ < n)
		{
			k = j;
			while (k++ < n)
			{
				if (is_first)
					is_first = 0;
				else
					ft_put_comma();
				ft_print_digits(i - 1, j - 1, k - 1);
			}
		}
	}
}
