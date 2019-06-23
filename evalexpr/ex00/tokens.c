/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:27:23 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/23 13:27:24 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "str_utils.h"

char	*skip_par_block(char *str)
{
	int n;

	n = 0;
	while (*str)
	{
		if (*str == '(')
			n++;
		if (*str == ')')
			n--;
		str++;
		if (!n)
			break ;
	}
	return (str);
}

char	*get_token(char **str)
{
	char *ret;
	char *ptr;

	skip_spaces(str);
	ptr = *str;
	if (!ptr)
		return (0);
	ptr = *str;
	if (*ptr == '(')
		ptr = skip_par_block(ptr);
	else
		skip_non_spaces(&ptr);
	ret = malloc(sizeof(char) * (ptr - *str + 1));
	ft_strlcpy(ret, *str, (ptr - *str + 1));
	*str = ptr;
	return (ret);
}
