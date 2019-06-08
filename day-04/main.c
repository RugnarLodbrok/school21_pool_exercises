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
#include <stdio.h>
#include "ex00/ft_iterative_factorial.h"
#include "ex01/ft_recursive_factorial.h"
#include "ex02/ft_iterative_power.h"
#include "ex03/ft_recursive_power.h"
#include "ex04/ft_fibonacci.h"
#include "ex05/ft_sqrt.h"
#include "ex06/ft_is_prime.h"
#include "ex07/ft_find_next_prime.h"
#include "ex08/ft_eight_queens_puzzle.h"
//#include "ex09/ft_eight_queens_puzzle_2.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main()
{
	printf("valid: %d, error: %d\n", ft_iterative_factorial(12), ft_iterative_factorial(13));
	printf("valid: %d, error: %d\n", ft_recursive_factorial(12), ft_recursive_factorial(13));
	printf("valid: %d, error: %d\n", ft_iterative_power(2, 30), ft_iterative_power(2, 31));
	printf("valid: %d, error: %d\n", ft_recursive_power(2, 30), ft_recursive_power(2, 31));
	printf("fibonacci: %d, %d, %d, %d, %d, %d\n", ft_fibonacci(0), ft_fibonacci(1), ft_fibonacci(2), ft_fibonacci(3), ft_fibonacci(4), ft_fibonacci(5));
	//printf("fibonacci: %d, %d, %d\n", ft_fibonacci(-1), ft_fibonacci(47), ft_fibonacci(10));

	int i = -2;
	while (i ++ < 50)
		printf("sqrt(%d) = %d;\tft_is_prime(%d) = %d\n", i, ft_sqrt(i), i, ft_is_prime(i));

	//i = 1000000000;
	i = 100;
	printf("next prime for %d is %d\n", i, ft_find_next_prime(i));

	int queens_counter;
	queens_counter = ft_eight_queens_puzzle();
	printf("%d\n", queens_counter);

//	ft_eight_queens_puzzle_2();	
	return 0;
}
