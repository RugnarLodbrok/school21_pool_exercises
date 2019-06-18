/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:17:45 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/17 16:17:46 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_any(char **tab, int(*f)(char*));

int inc(int n)
{
	return n+1;
}

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

int main()
{
	int i;
	char* a[5] = {"", "2", "b", "abc", "213"};
	a[4] = 0;
	printf("%d\n", ft_any(a, ft_strlen));
	return 0;
}
