/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:41:52 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/10 20:41:53 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	int				ended;

	len = 0;
	ended = 0;
	while (size > 1)
	{
		size--;
		*dest = *src;
		if (!*src)
		{
			ended = 1;
			break ;
		}
		dest++;
		src++;
		len++;
	}
	if (size && !ended)
		*dest = 0;
	while (*(src++))
		len++;
	return (len);
}
