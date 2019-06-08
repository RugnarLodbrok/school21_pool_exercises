/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:32:13 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/08 19:32:14 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_state(char *state, int size)
{
	int i;

	i = 0;
	while (i++ < size)
	{
		ft_putchar('1' + *(state + i - 1));
	}
	ft_putchar('\n');
}

int		check_diagonals(char *state, int size)
{
	int i;
	int j;
	int diagonal1;
	int diagonal2;

	i = 0;
	diagonal1 = 0;
	diagonal2 = 0;
	while (i < size)
	{
		j = *(state + i);
		if (diagonal1 & (1 << (i + j)))
			return (1);
		diagonal1 |= (1 << (i + j));
		if (diagonal2 & (1 << (i - j + 7)))
			return (1);
		diagonal2 |= (1 << (i - j + 7));
		++i;
	}
	return (0);
}

int		check_horizontal(char *state, int size)
{
	int i;
	int one_queen_mask;
	int mask;

	i = 0;
	mask = 0;
	while (i < size)
	{
		one_queen_mask = 1 << *(state + i);
		if (one_queen_mask & mask)
			return (1);
		mask |= one_queen_mask;
		++i;
	}
	return (0);
}

void	place_n_queens(char *state, int size, int *counter)
{
	int i;

	if (size == 8)
		print_state(state, size);
	else
	{
		i = 0;
		while (i < 8)
		{
			*(state + size) = i;
			if (!check_horizontal(state, size + 1))
				if (!check_diagonals(state, size + 1))
					place_n_queens(state, size + 1, counter);
			i++;
		}
	}
}

void	ft_eight_queens_puzzle_2(void)
{
	char	state[8];
	int		counter;

	counter = 0;
	place_n_queens(state, 0, &counter);
}
