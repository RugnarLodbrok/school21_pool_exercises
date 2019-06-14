/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:14:39 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/13 15:14:40 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
struct s_stock_par	*ft_param_to_tab(int ac, char **av);

int main(int argc, char *argv[])
{
	struct s_stock_par *arr;

	arr = ft_param_to_tab(argc, argv);
	printf("%s\n", "OK");
	return 0;
}
