/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:37:58 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/07 18:38:02 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int v;
	int is_negative;

	v = 0;
	is_negative = 0;
	while (*str)
	{
		if (*str == '-' && !is_negative)
		{
			is_negative = 1;
			str++;
			continue ;
		}
		if (*str < '0' || *str > '9')
			break ;
		v *= 10;
		v -= *str - '0';
		str++;
	}
	if (!is_negative)
		v *= -1;
	return (v);
}
