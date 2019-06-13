/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 22:29:57 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/12 22:29:58 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				is_space07(char c, char *charset)
{
	while (*charset)
		if (*charset++ == c)
			return (1);
	return (0);
}

unsigned int	count_words07(char *str, char *charset)
{
	unsigned int	n;
	int				got_word;

	n = 0;
	got_word = 0;
	while (*str)
	{
		if (got_word)
		{
			if (is_space07(*str, charset))
				got_word = 0;
			str++;
		}
		else
		{
			if (!is_space07(*str, charset))
			{
				got_word = 1;
				n++;
			}
			str++;
		}
	}
	return (n);
}

char			*dup_until_whitespace07(char **str, char *charset)
{
	char			*ret;
	char			*ptr;
	unsigned int	i;

	while (is_space07(**str, charset))
		(*str)++;
	ptr = *str;
	i = 0;
	while (!is_space07(*ptr++, charset))
		i++;
	ret = (char*)malloc(sizeof(char) * (i + 1));
	ptr = ret;
	while (!is_space07(**str, charset))
		*ptr++ = *(*str)++;
	*ptr = 0;
	return (ret);
}

char			**ft_split(char *str, char *charset)
{
	char			**ret;
	char			**ptr;
	unsigned int	n;
	unsigned int	i;

	n = count_words07(str, charset);
	ret = malloc(sizeof(char*) * (n + 1));
	i = 0;
	ptr = &str;
	while (i < n)
	{
		*(ret + i) = dup_until_whitespace07(ptr, charset);
		i++;
	}
	*(ret + i) = 0;
	return (ret);
}
