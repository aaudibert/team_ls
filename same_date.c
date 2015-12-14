/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_date.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 18:27:58 by psaint-j          #+#    #+#             */
/*   Updated: 2015/12/14 18:40:33 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define T stat->st_mtime

void		sort_same_date(t_fl *dir)
{
	char		*tmp;
	struct stat *tp;

	while (dir->next)
	{
		if (dir->T == dir->next->T && ft_strcmp(dir->f, dir->f) > 0)
		{
			tmp = dir->f;
			tp = dir->stat;
			dir->f = dir->next->f;
			dir->stat = dir->next->stat;
			dir->next->f = tmp;
			dir->next->stat = tp;
			while (dir->prev != NULL)
				dir = dir->prev;
		}
		else
			dir = dir->next;
	}
	while (dir->prev != NULL)
		dir = dir->prev;
}

void		sort_same_dir(t_file *dir)
{
	char		*tmp;
	int			i;
	int			j;

	while (dir->next)
	{
		if (dir->date == dir->next->date && ft_strcmp(dir->f_name,
					dir->f_name) > 0)
		{
			tmp = dir->f_name;
			i = dir->izdir;
			j = dir->date;
			dir->f_name = dir->next->f_name;
			dir->izdir = dir->next->izdir;
			dir->date = dir->next->date;
			dir->next->f_name = tmp;
			dir->next->izdir = i;
			dir->next->date = j;
			dir = rewind_lst(dir);
		}
		else
			dir = dir->next;
	}
}
