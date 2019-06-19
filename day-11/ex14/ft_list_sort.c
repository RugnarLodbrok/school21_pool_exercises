/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 20:57:56 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/18 20:57:57 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
int		ft_list_size(t_list *begin_list)
{
	int len;

	len = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		len++;
	}
	return (len);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list			*prev;
	t_list			*ptr;
	unsigned int	size;

	if (!*begin_list)
		return ;
	ptr = *begin_list;
	prev = 0;
	size = ft_list_size(ptr);
	while (size--)
	{
		i = 0;
		while (i < size)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
				ft_swap(tab + i, tab + i + 1);
			++i;
			prev = ptr;
			ptr = ptr->next;
		}
	}
}
*/