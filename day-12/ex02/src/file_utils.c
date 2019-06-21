/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:58:54 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/20 17:58:57 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "utils.h"

void	display_error(char const *fn, char *msg)
{
	write(2, "tail: ", 6);
	if (fn)
	{
		write(2, fn, ft_strlen(fn));
		write(2, ": ", 2);
	}
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

int		get_fd(char const *fn)
{
	int fd;

	if (!fn)
		return (0);
	fd = open(fn, O_RDONLY);
	if (fd < 0)
	{
		if (errno == 2)
			display_error(fn, "No such file or directory");
		else if (errno == 13)
			display_error(fn, "Permission denied");
		else
			display_error(fn, "Unknown error");
	}
	return (fd);
}

int		get_fd_len(int fd, char const *fn)
{
	int		len;
	int		n;
	char	buff[256];

	len = 0;
	while (1)
	{
		n = read(fd, buff, 256);
		if (n < 0)
		{
			display_error(fn, "Is a directory");
			return (-1);
		}
		if (n)
			len += n;
		else
			break ;
	}
	return (len);
}
