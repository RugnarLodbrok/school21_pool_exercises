/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:39:51 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/10 19:39:52 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen4(char *str)
{
	unsigned int len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				i;
	char			*p;
	unsigned int	len;
	unsigned int	len2;

	len = ft_strlen4(dest);
	len2 = ft_strlen4(src);
	if (size <= len)
		return (size + ft_strlen4(src));
	i = size - len;
	p = dest + len;
	while (*src && i-- > 1)
		*(p++) = *(src++);
	*p = 0;
	return (len + len2);
}
