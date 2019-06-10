/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:41:52 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/10 20:41:53 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char			*dst;
	unsigned int	len;

	dst = dest;
	len = 0;
	while (--size)
	{
		if (!(*src))
			break ;
		*(dst++) = *(src++);
		len++;
	}
	while (*(src++))
		len++;
	*(dst++) = 0;
	return (len);
}
