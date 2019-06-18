/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 18:12:33 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/15 18:12:33 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*(str + len) != '\0')
	{
		len++;
	}
	return (len);
}

unsigned int	star_count(char *str)
{
	int n;

	n = 0;
	while (*str)
		if (*str++ == '*')
			n++;
	return (n);
}

int				recur(char *s1, char *s2, unsigned int star_len)
{
	unsigned int i;
	unsigned int n;

	n = 0;
	while (1)
	{
		if (*s2 == '*')
		{
			i = 0;
			while (i++ <= star_len)
				n += recur(s1 + i - 1, s2 + 1, star_len - i + 1);
			return (n);
		}
		if (!*s1)
		{
			if (!*s2)
				n++;
			return (n);
		}
		if (!*s2)
			return (n);
		if (*s1++ != *s2++)
			return (n);
	}
}

int				nmatch(char *s1, char *s2)
{
	return (recur(s1, s2, ft_strlen(s1) - ft_strlen(s2) + star_count(s2)));
}
