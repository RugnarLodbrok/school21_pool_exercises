/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:12:50 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/10 19:12:52 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy2(char *dest, char *src, unsigned int n)
{
	char *dst;

	dst = dest;
	while (n)
	{
		if (!(*src))
			break ;
		*(dst++) = *(src++);
		n--;
	}
	*(dst++) = 0;
	while (n)
	{
		*(dst++) = 0;
		n--;
	}
	return (dest);
}

char	*ft_strncat(char *dest, char *src, int nb)
{
	char *ptr;

	ptr = dest;
	while (*ptr)
		ptr++;
	ft_strncpy2(ptr, src, nb);
	return (dest);
}
