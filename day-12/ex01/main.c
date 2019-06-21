/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:28:32 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/19 13:28:32 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int		ft_strlen(char const *str)
{
	int len;

	len = 0;
	while (*(str + len) != '\0')
	{
		len++;
	}
	return (len);
}

void	display_error(char const *fn, char *msg)
{
	write(2, "cat: ", 5);
	write(2, fn, ft_strlen(fn));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

void	read_n_display(int fd, char const *fn)
{
	int		n;
	char	buff[4096];

	while (1)
	{
		n = read(fd, buff, 4096);
		if (n < 0)
		{
			display_error(fn, "Is a directory");
			return ;
		}
		if (n)
			write(1, buff, n);
		else
			break ;
	}
}

int		main(int argc, char const *argv[])
{
	int fd;
	int i;

	i = 1;
	if (argc == 1)
		read_n_display(0, "");
	while (i < argc)
	{
		fd = open(argv[i++], O_RDONLY);
		if (fd < 0)
		{
			if (errno == 2)
				display_error(argv[i - 1], "No such file or directory");
			else if (errno == 13)
				display_error(argv[i - 1], "Permission denied");
			return (1);
		}
		read_n_display(fd, argv[i - 1]);
		if (close(fd))
			return (1);
	}
	if (errno)
		return (1);
	return (0);
}
