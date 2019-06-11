/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:23:10 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/10 18:23:11 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (!(is_lower(*str) || is_upper(*str)))
			return (0);
		str++;
	}
	return (1);
}
