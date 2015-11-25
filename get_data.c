/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 15:29:30 by aaudiber          #+#    #+#             */
/*   Updated: 2015/11/25 16:03:40 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		data_proc(t_file *dir)
{
	sort_dir(dir);
	if (g_flags[FLAG_RR] != 1)
		print_dir(dir);
	else if (g_flags[FLAG_RR] == 1 && g_flags[FLAG_R] == 1)
	{
		while (dir->next != NULL)
			dir = dir->next;
		ft_rrecurs(dir);
	}
	else
		ft_recurs(dir);
}

void		get_data(char *path)
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
		return ;
	}
	while (dir->next->next != NULL)
		dir = dir->next;
	dir->next = NULL;
	dir = rewind_lst(dir);
	data_proc(dir);
}
