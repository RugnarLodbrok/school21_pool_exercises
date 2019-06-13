/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 18:24:07 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/12 18:24:08 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

unsigned int	str_len03(char *str)
{
	unsigned int i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

char			*ft_concat_params(int argc, char **argv)
{
	char			*ret;
	char			*ptr;
	char			*arg;
	unsigned int	len;
	int				i;

	len = 0;
	i = 0;
	while (i++ < argc - 1)
		len += str_len03(*(argv + i)) + 1;
	ret = (char*)malloc(len);
	if (!ret)
		return (ret);
	i = 0;
	ptr = ret;
	while (i++ < argc - 1)
	{
		arg = *(argv + i);
		while ((*ptr++ = *arg++))
			;
		*(ptr - 1) = '\n';
	}
	*(ptr - 1) = 0;
	return (ret);
}
