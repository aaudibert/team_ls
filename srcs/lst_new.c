/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 12:06:53 by aaudiber          #+#    #+#             */
/*   Updated: 2016/05/01 19:18:10 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_file		*lst_new(char *f_name, char *path, int file)
{
	t_file		*new_link;
	char		*s;

	new_link = (t_file*)malloc(sizeof(t_file));
	new_link->stat = malloc(sizeof(t_stat));
	new_link->path = path;
	if (file == 2)
		s = ft_strjoin(f_name, "/.");
	else
		s = ft_strjoin(path, f_name);
	if (file == 1 && ft_strcmp(path, "./") != 0)
		new_link->f_name = ft_strdup(s);
	else
		new_link->f_name = ft_strdup(f_name);
	if (lstat(s, new_link->stat) == 0)
		new_link->err = 0;
	else
		new_link->err = errno;
	free(s);
	new_link->prev = NULL;
	new_link->next = NULL;
	return (new_link);
}
