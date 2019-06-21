/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:26:27 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/19 19:26:29 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAIL_H

# define TAIL_H

void	read_n_display(int fd, int offset);
int		find_tail_offset(int fd, unsigned int n);

#endif
