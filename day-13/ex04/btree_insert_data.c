/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:37:13 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/20 13:37:14 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void *))
{
	t_btree *node;

	node = *root;
	if (!node)
		*root = btree_create_node(item);
	else if (cmpf(item, node->item) < 0)
		btree_insert_data(&(node->left), item, cmpf);
	else
		btree_insert_data(&(node->right), item, cmpf);
}
