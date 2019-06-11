/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:04:59 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/10 19:05:00 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy2(char *dest, char *src)
{
	int i;

	i = 0;
	while ((dest[i] = src[i]))
		i++;
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	char *ptr;

	ptr = dest;
	while (*ptr)
		ptr++;
	ft_strcpy2(ptr, src);
	return (dest);
}
