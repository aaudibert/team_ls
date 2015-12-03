/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 20:42:38 by yalaouf           #+#    #+#             */
/*   Updated: 2015/11/25 20:35:06 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	btree_apply_suffix(t_btree *root, void (*apply)(void *))
{
	if (root->left != NULL)
		btree_apply_suffix(root->left, apply);
	if (root->right != NULL)
		btree_apply_suffix(root->right, apply);
	if (root->item != NULL)
		apply(root->item);
}
