/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:58:47 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/20 13:58:48 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		max2(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		btree_level_count2(t_btree *root)
{
	if (!root)
		return (0);
	return (max2(
		btree_level_count2(root->left),
		btree_level_count2(root->right)) + 1);
}

void	apply_to_level(t_btree *node, t_pair lvl, int *first_flag,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (!node)
		return ;
	if (!lvl.a)
	{
		applyf(node->item, lvl.b, *first_flag);
		*first_flag = 0;
	}
	else
	{
		lvl.a--;
		apply_to_level(node->left, lvl, first_flag, applyf);
		apply_to_level(node->right, lvl, first_flag, applyf);
	}
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		i;
	int		n_levels;
	t_pair	lvl;
	int		first_flag;

	n_levels = btree_level_count2(root);
	i = 0;
	while (i < n_levels)
	{
		lvl.a = i;
		lvl.b = i;
		first_flag = 1;
		apply_to_level(root, lvl, &first_flag, applyf);
		i++;
	}
}
