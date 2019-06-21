/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:21:47 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/20 13:21:47 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *node;

	if (!(node = (t_btree*)malloc(sizeof(t_btree))))
		return (0);
	node->item = item;
	node->left = 0;
	node->right = 0;
	return (node);
}
