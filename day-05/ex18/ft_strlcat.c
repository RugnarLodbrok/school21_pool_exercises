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

unsigned int	ft_strlcpy2(char *dest, char *src, unsigned int n)
{
	char			*dst;
	unsigned int	len;

	dst = dest;
	len = 0;
	while (n)
	{
		if (!(*src))
			break ;
		*(dst++) = *(src++);
		n--;
		len++;
	}
	while (*(src++))
		len++;
	*(dst++) = 0;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*ptr;
	unsigned int	len;

	ptr = dest;
	len = 0;
	while (*ptr)
	{
		ptr++;
		len++;
	}
	return (len + ft_strlcpy2(ptr, src, size - len - 1));
}
