/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 15:29:30 by aaudiber          #+#    #+#             */
/*   Updated: 2016/04/12 19:45:29 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		data_proc(t_file *dir)
{
	dir->next = NULL;
	dir = rewind_lst(dir);
	if (g_flags[FLAG_R] == 1)
		rsort_dir(dir);
	else
		sort_dir(dir);
	if (g_flags[FLAG_RR] != 1)
		print_dir(dir, 0);
	else
		ft_recurs(dir);
	ft_free_dir_lst(dir);
}

void		ft_error(char *path)
{
	char	*s;

	s = get_name(path);
	ft_putstr("ls: ");
	ft_putstr(s);
	ft_putstr(": ");
	perror("");
}

void		get_data(char *path)
{
	DIR			*rep;
	t_dirent	*fr;
	t_file		*dir;
	char		*tmp;

	rep = opendir(path);
	dir = lst_new(path, path, 0);
	if (rep != NULL)
	{
		while ((fr = readdir(rep)) != NULL)
		{
			tmp = ft_strdup(fr->d_name);
			lst_push(lst_new(tmp, path, 0), &dir);
			free(tmp);
		}
		closedir(rep);
	}
	else
	{
		ft_error(path);
		return ;
	}
	while (dir->next->next != NULL)
		dir = dir->next;
	data_proc(dir);
}
