/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 12:06:53 by aaudiber          #+#    #+#             */
/*   Updated: 2016/01/11 17:31:06 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*lst_new(char *f_name, char *path)
{
	t_file		*new_link;
	char		*s;

	new_link = (t_file*)malloc(sizeof(t_file));
	new_link->path = path;
	new_link->f_name = f_name;
	new_link->stat = malloc(sizeof(t_stat));
	s = ft_strjoin(new_link->path, new_link->f_name);
	lstat(s, new_link->stat);
	free(s);
	new_link->date = new_link->stat->st_mtime;
	new_link->prev = NULL;
	new_link->next = NULL;
	if (S_ISDIR(new_link->stat->st_mode))
		new_link->izdir = 1;
	else
		new_link->izdir = 0;
	return (new_link);
}
