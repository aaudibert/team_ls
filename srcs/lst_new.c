/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 12:06:53 by aaudiber          #+#    #+#             */
/*   Updated: 2016/04/26 18:32:17 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_file		*lst_new(char *f_name, char *path, int file)
{
	t_file		*new_link;
	char		*s;

	new_link = (t_file*)malloc(sizeof(t_file));
	new_link->path = path;
	s = ft_strjoin(path, f_name);
	if (file == 1 && ft_strcmp(path, "./") != 0)
		new_link->f_name = ft_strdup(s);
	else
		new_link->f_name = ft_strdup(f_name);
	new_link->stat = malloc(sizeof(t_stat));
	if (lstat(s, new_link->stat))
		;
	else
		new_link->stat = NULL;
	free(s);
	new_link->prev = NULL;
	new_link->next = NULL;
	return (new_link);
}
