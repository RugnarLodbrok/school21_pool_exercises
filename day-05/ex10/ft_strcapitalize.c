/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:55:42 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/10 17:55:43 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int		is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int		is_alphanum(char c)
{
	return (is_lowercase(c) || is_uppercase(c) || (c >= '0' && c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int		word_start;
	char	*ptr;

	word_start = 1;
	ptr = str;
	while (*ptr)
	{
		if (is_alphanum(*ptr))
		{
			if (word_start && is_lowercase(*ptr))
				*ptr += 'A' - 'a';
			word_start = 0;
		}
		else
			word_start = 1;
		ptr++;
	}
	return (str);
}
