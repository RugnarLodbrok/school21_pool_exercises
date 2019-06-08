/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:29:50 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/06 13:29:52 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include "ex00/ft_print_alphabet.h"
#include "ex01/ft_print_reverse_alphabet.h"
#include "ex02/ft_print_numbers.h"
#include "ex03/ft_is_negative.h"
#include "ex04/ft_print_comb.h"
#include "ex05/ft_print_comb2.h"
#include "ex06/ft_putnbr.h"
#include "ex07/ft_print_combn.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


int	main()
{
	ft_print_alphabet();
	ft_putchar('\n');
	ft_print_reverse_alphabet();
	ft_putchar('\n');
	ft_print_numbers();
	ft_putchar('\n');
	ft_is_negative(1);
	ft_putchar('\n');
	ft_print_comb();
	ft_putchar('\n');
	ft_print_comb2();
	ft_putchar('\n');
	ft_putnbr(-2147483648);
	ft_putchar('\n');
	ft_print_combn(3);
	return 0;
}
