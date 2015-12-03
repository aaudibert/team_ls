/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 20:29:53 by yalaouf           #+#    #+#             */
/*   Updated: 2015/11/25 20:35:19 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *tree;

	tree = (t_btree *)malloc(sizeof(t_btree));
	if (tree != NULL)
	{
		tree->right = NULL;
		tree->left = NULL;
		tree->item = item;
	}
	return (tree);
}
