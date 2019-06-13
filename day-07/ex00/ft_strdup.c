/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:22:14 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/12 13:22:15 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	str_len(char *str)
{
	unsigned int i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char			*ft_strdup(char *src)
{
	char *dst;
	char *ret;

	ret = (char*)malloc((size_t)str_len(src) + 1);
	if (!ret)
		return (ret);
	dst = ret;
	while ((*ret++ = *src++))
		;
	return (dst);
}
