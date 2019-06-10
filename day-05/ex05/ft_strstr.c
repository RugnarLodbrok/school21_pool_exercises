/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:06:07 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/10 16:06:08 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *haystack;
	char *needle;

	if (!*to_find)
		return (str);
	while (*str++)
	{
		haystack = str - 1;
		needle = to_find;
		while (1)
		{
			if (!*haystack)
				if (!*needle)
					return (str - 1);
				else
					return (0);
			else if (!*needle)
				return (str - 1);
			if (*haystack != *needle)
				break ;
			haystack++;
			needle++;
		}
	}
	return (0);
}
