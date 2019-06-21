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

void	read_n_display(int fd)
{
	int		n;
	char	*buff[256];

	while (1)
	{
		n = read(fd, buff, 256);
		if (n)
			write(1, buff, n);
		else
			break ;
	}
}

int		main(int argc, char const *argv[])
{
	int fd;

	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	else if (argc < 2)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	read_n_display(fd);
	if (close(fd))
		return (1);
	return (0);
}
