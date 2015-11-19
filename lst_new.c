/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 12:06:53 by aaudiber          #+#    #+#             */
/*   Updated: 2015/11/19 19:29:23 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*lst_new(char *f_name, char *path)
{
	t_file		*new_link;
	struct stat	tmp;

	new_link = (t_file*)malloc(sizeof(t_file));
	new_link->path = path;
	new_link->f_name = f_name;
	new_link->stat = malloc(sizeof(stat));
	lstat(f_name, &tmp);
	new_link->stat = &tmp;
	new_link->prev = NULL;
	new_link->next = NULL;
	if (S_ISDIR(new_link->stat->st_mode))
		ft_putendl("DIRECTORY");
	return (new_link);
}
