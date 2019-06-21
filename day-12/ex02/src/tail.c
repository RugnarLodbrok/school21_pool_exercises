/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:25:07 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/19 19:25:09 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "utils.h"
#include "file_utils.h"

void	read_n_display(int fd, int offset)
{
	int		n;
	char	buff[4096];

	while (1)
	{
		n = read(fd, buff, 4096);
		if (n < 0)
			return ;
		if (n)
		{
			if (offset >= n)
			{
				offset -= n;
				continue ;
			}
			write(1, buff + offset, n - offset);
		}
		else
			break ;
	}
}

int		find_tail_offset_inner(int fd, char *buff, unsigned int n, int *lbr)
{
	int				chunk;
	int				n_bytes;
	int				i;

	chunk = 0;
	while (1)
	{
		n_bytes = read(fd, buff, 4096);
		if (n_bytes < 0)
			return (-1);
		if (n_bytes)
		{
			i = 0;
			while (i < n_bytes)
				if (buff[i++] == '\n')
					push((i - 1) + chunk * 4096, lbr, n + 1);
		}
		else
			break ;
		chunk++;
	}
	return (i);
}

int		find_tail_offset(int fd, unsigned int n)
{
	int				lbr[n + 1];
	char			buff[4096];
	int				i;

	i = 0;
	while ((unsigned)i < n)
		lbr[i++] = -1;
	i = find_tail_offset_inner(fd, buff, n, lbr);
	if (i < 0)
		return (-1);
	if (buff[i - 1] == '\n')
		return (lbr[n] + 1);
	return (lbr[n - 1] + 1);
}
