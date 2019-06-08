/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:33:23 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/05 20:33:26 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_two_digits(int a)
{
	int digit1;
	int digit2;

	digit1 = a / 10;
	digit2 = a - digit1 * 10;
	ft_putchar('0' + digit1);
	ft_putchar('0' + digit2);
}

void	print_combo(int a, int b)
{
	print_two_digits(a);
	ft_putchar(' ');
	print_two_digits(b);
}

void	ft_print_comb2(void)
{
	int i;
	int j;

	i = 0;
	while (i++ < 99)
	{
		j = i;
		while (j++ < 99)
		{
			print_combo(i, j);
			if (i < 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
	}
}
