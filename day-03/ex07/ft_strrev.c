/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 18:15:19 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/06 18:15:21 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strlen2(char *str)
{
	int len;

	len = 0;
	while (*(str + len) != '\0')
	{
		len++;
	}
	return (len);
}

void	ft_swapc(char *a, char *b)
{
	char c;

	c = *a;
	*a = *b;
	*b = c;
}

char	*ft_strrev(char *str)
{
	int		len;
	int		i;

	len = ft_strlen2(str);
	i = 0;
	while (i < len / 2)
	{
		ft_swapc(str + i, str + len - i - 1);
		i++;
	}
	return (str);
}
