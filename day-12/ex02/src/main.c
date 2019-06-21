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

#include <unistd.h>
#include <errno.h>
#include "tail.h"
#include "tail2.h"
#include "utils.h"
#include "file_utils.h"

void	tail(char const *fn)
{
	int fd;
	int offset;

	if (!fn)
	{
		display_error("", "NOT IMPLEMENTED");
		errno = 1;
		return ;
	}
	if ((fd = get_fd(fn)) < 0)
		return ;
	offset = find_tail_offset(fd, 3);
	if (offset < 0)
		return ;
	if (close(fd))
		display_error(fn, "Can't close file");
	fd = get_fd(fn);
	if (!fd)
		return ;
	read_n_display(fd, offset);
	if (fd)
		if (close(fd))
			display_error(fn, "Can't close file");
}

void	print_header(char *fn)
{
	write(1, "==> ", 4);
	write(1, fn, ft_strlen(fn));
	write(1, " <==\n", 5);
}

int		parse_options(int *ac, char ***av, int *opts)
{
	(*av)++;
	(*ac)--;
	if (!*ac)
	{
		*opts = 0;
		return (0);
	}
	if (***av == '-')
	{
		if (*ac < 2)
			*opts = -1;
		else if (!ft_strcmp(*(*av)++, "-c"))
		{
			*ac -= 2;
			*opts = 1;
			return (ft_atoi2(*(*av)++));
		}
		else
			*opts = -1;
	}
	return (0);
}

void	ft_tail(int argc, char **argv, int c, int opts)
{
	int need_header;
	int first;

	first = 0;
	need_header = (argc > 1);
	while (argc--)
	{
		if (first++)
			write(1, "\n", 1);
		if (need_header)
			print_header(*argv);
		if (opts > 0)
			tail_c2(*argv++, c);
		else
			tail(*argv++);
	}
}

int		main(int argc, char **argv)
{
	int			c;
	int			opts;
	char		*empty_string;

	empty_string = 0;
	c = parse_options(&argc, &argv, &opts);
	if (opts < 0)
	{
		write(2, "invalid option syntax\n", 22);
		return (1);
	}
	if (!argc)
		ft_tail(1, &empty_string, c, opts);
	else
		ft_tail(argc, argv, c, opts);
	if (errno)
		return (1);
	return (0);
}
