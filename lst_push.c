/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 14:25:02 by aaudiber          #+#    #+#             */
/*   Updated: 2014/12/17 21:05:56 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		lst_push(t_file *elem, t_file **lst)
{
	elem->prev = NULL;
	elem->next = *lst;
	if (*lst)
		(*lst)->prev = elem;
	*lst = elem;
}
