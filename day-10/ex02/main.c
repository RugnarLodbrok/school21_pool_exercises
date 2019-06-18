/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:08:13 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/17 16:08:14 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int *ft_map(int *tab, int length, int(*f)(int));

int inc(int n)
{
	return n+1;
}

int main()
{
	int i;
	int a[4] = {0, 5, 2, -2};
	int *b;
	b = ft_map(a, 4, inc);

	for(i =0; i < 4; ++i)
	{
		printf("%d\n", b[i]);
	}
	return 0;
}