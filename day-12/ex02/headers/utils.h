/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:47:58 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/19 17:47:59 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H

# define MIN_INT32	-2147483648
# define ABS(x)		(x < 0 ? ((x == MIN_INT32) ? 0 : -x) : x)

int		ft_strlen(char const *str);
void	push(int n, int buff[], int size);
int		ft_atoi2(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif
