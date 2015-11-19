/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 15:29:30 by aaudiber          #+#    #+#             */
/*   Updated: 2015/11/19 19:29:03 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*get_data(char *path)
{
	DIR			*rep;
	t_dirent	*fr;
	t_file		*dir;

	rep = opendir(path);
	dir = lst_new(NULL, path);
	if (rep != NULL)
	{
		while ((fr = readdir(rep)) != NULL)
			lst_push(lst_new(ft_strdup(fr->d_name), path), &dir);
		closedir(rep);
	}
	else
	{
		perror("");
		return (0);
	}
	while (dir->next->next != NULL)
		dir = dir->next;
	dir->next = NULL;
	dir = rewind_lst(dir);
//	print_dir(dir);
	ft_recurs(dir);
//	sort_dir(dir);
	return (dir);
}
