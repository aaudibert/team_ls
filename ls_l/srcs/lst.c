/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:20:52 by yalaouf           #+#    #+#             */
/*   Updated: 2015/11/25 20:06:58 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_file	*new_lst(t_file *list, char *name)
{
	t_file			*elem;
	struct stat		tmp;

	elem = (t_file*)malloc(sizeof(t_file));
	elem->name = name;
	elem->stats = malloc(sizeof(stat));
	lstat(elem->name, &tmp);
	elem->stats = &tmp;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void	push_lst(t_file **list, t_file *elem)
{
	elem->prev = NULL;
	elem->next = *list;
	if (*list)
		(*list)->prev = elem;
	*list = elem;
}

t_file	*rewind_lst(t_file *list)
{
	while (list->prev != NULL)
		list = list->prev;
	return (list);
}
