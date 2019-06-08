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
#include "ex00/ft_ft.h"
#include "ex01/ft_ultimate_ft.h"
#include "ex02/ft_swap.h"
#include "ex03/ft_div_mod.h"
#include "ex04/ft_ultimate_div_mod.h"
#include "ex05/ft_putstr.h"
#include "ex06/ft_strlen.h"
#include "ex07/ft_strrev.h"
#include "ex08/ft_atoi.h"
#include "ex09/ft_sort_integer_table.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


int	main()
{
	int a;

	a = 0;
	ft_ft(&a);
	printf("a: %d\n", a);

	int b;
	int* pt1;
	void* pt2;
	void* pt3;
	void* pt4;
	void* pt5;
	void* pt6;
	void* pt7;
	void* pt8;
	void* pt9;

	pt9 = &pt8;
	pt8 = &pt7;
	pt7 = &pt6;
	pt6 = &pt5;
	pt5 = &pt4;
	pt4 = &pt3;
	pt3 = &pt2;
	pt2 = &pt1;
	pt1 = &a;
	a = 0;

	ft_ultimate_ft(pt9);
	printf("a: %d\n", a);

	b = 2;
	a = 1;
	ft_swap(&a, &b);
	printf("a, b: %d, %d\n", a, b);

	int c;
	int d;
	int div;
	int mod;

	c = 1;
	d = 2;
	ft_div_mod(c, d, &div, &mod);
	printf("div, mod: %d, %d\n", div, mod);

	ft_ultimate_div_mod(&c, &d);
	printf("div, mod: %d, %d\n", c, d);

	ft_putstr("hello world");
	ft_putchar('\n');

	ft_putchar(ft_strlen("ds") + '0');
	ft_putchar('\n');

	char str[3];
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	ft_putstr(ft_strrev(str));
	ft_putchar('\n');

	printf("atoi: %d\n", ft_atoi("+432tgr"));

	int int_array[10] = {4, 1, 9, 3, 6, 0, 8, 2, 5, 7};
	ft_sort_integer_table(int_array, 10);
	int i = -1;
	while (i++ < 9)
		printf("%d", int_array[i]);
	printf("\n");

	return 0;
}
