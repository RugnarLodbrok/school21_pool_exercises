/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:13:02 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/20 17:13:03 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "tail.h"
#include "file_utils.h"
#include "utils.h"

int		tail_c2_minus_loop(int fd, int buff_size, int skip_remaining)
{
	char	buff[buff_size];
	int		n;
	int		n_last;

	n = 0;
	while (1)
	{
		n_last = n;
		n = read(fd, buff, buff_size);
		if (n < 0)
			return (-1);
		if (!n)
			break ;
		if (skip_remaining > n)
			skip_remaining -= n;
		else
		{
			write(1, buff + skip_remaining, n - skip_remaining);
			skip_remaining = 0;
		}
	}
	return (0);
}

void	tail_c2_minus(int buff_size, const char *fn, int c)
{
	int		fd;

	if ((fd = get_fd(fn)) < 0)
		return ;
	if (!c)
		return ;
	if (tail_c2_minus_loop(fd, buff_size, c) < 0)
		return ;
	if (fd)
		close(fd);
}

void	tail_c2_plus(const char *fn, int c)
{
	char	buff[c];
	int		fd;
	int		n;
	int		n_last;

	n = 0;
	if ((fd = get_fd(fn)) < 0)
		return ;
	if (!c)
		return ;
	while (1)
	{
		n_last = n;
		n = read(fd, buff, c);
		if (n < 0)
			return ;
		if (!n)
			break ;
	}
	write(1, buff + n_last, c - n_last);
	write(1, buff, n_last);
	if (fd)
		close(fd);
}

void	tail_c2(const char *fn, int c)
{
	int buff_size;
	int chunk_step;

	chunk_step = 4096;
	buff_size = (ABS(c) / chunk_step + 1) * chunk_step;
	if (c < 0)
		tail_c2_minus(buff_size, fn, -c - 1);
	else
		tail_c2_plus(fn, c);
}
