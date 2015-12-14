/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:54:47 by rlechapt          #+#    #+#             */
/*   Updated: 2015/12/14 15:28:35 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_date(t_file *dir)
{
	char	*tmp;
	int		i;
	int		j;

	while (dir->next)
	{
		if (dir->date < dir->next->date)
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

void	sort_ftl(t_fl *dir)
{
	char		*tmp;
	struct stat	*tp;

	while (dir->next)
	{
		if (dir->stat->st_mtime < dir->next->stat->st_mtime)
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
	print_ftl(dir);
}

void	sort_dir(t_file *dir)
{
	char	*tmp;
	int		i;

	if (g_flags[FLAG_T] == 1)
		sort_date(dir);
	else
	{
		while (dir->next)
		{
			if (ft_strcmp(dir->f_name, dir->next->f_name) > 0)
			{
				tmp = dir->f_name;
				i = dir->izdir;
				dir->f_name = dir->next->f_name;
				dir->izdir = dir->next->izdir;
				dir->next->f_name = tmp;
				dir->next->izdir = i;
				dir = rewind_lst(dir);
			}
			else
				dir = dir->next;
		}
	}
}

void	sort_params(char **tab)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tab[i + 1])
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
