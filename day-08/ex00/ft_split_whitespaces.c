/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:27:33 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/13 13:27:34 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

unsigned int	count_words(char *str)
{
	unsigned int	n;
	int				got_word;

	n = 0;
	got_word = 0;
	while (*str)
	{
		if (got_word)
		{
			if (is_space(*str))
				got_word = 0;
			str++;
		}
		else
		{
			if (!is_space(*str))
			{
				got_word = 1;
				n++;
			}
			str++;
		}
	}
	return (n);
}

char			*dup_until_whitespace(char **str)
{
	char			*ret;
	char			*ptr;
	unsigned int	i;

	while (is_space(**str))
		(*str)++;
	ptr = *str;
	i = 0;
	while (!is_space(*ptr++))
		i++;
	ret = (char*)malloc(sizeof(char) * (i + 1));
	ptr = ret;
	while (!is_space(**str))
		*ptr++ = *(*str)++;
	*ptr = 0;
	return (ret);
}

char			**ft_split_whitespaces(char *str)
{
	char			**ret;
	char			**ptr;
	unsigned int	n;
	unsigned int	i;

	n = count_words(str);
	ret = malloc(sizeof(char*) * (n + 1));
	i = 0;
	ptr = &str;
	while (i < n)
	{
		*(ret + i) = dup_until_whitespace(ptr);
		i++;
	}
	*(ret + i) = 0;
	return (ret);
}
