/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:54:47 by rlechapt          #+#    #+#             */
/*   Updated: 2016/01/13 18:19:48 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void	sort_date(t_file *dir)
{
	char	*tmp;
	t_stat	*st;

	while (dir->next)
	{
		if (dir->stat->st_mtime < dir->next->stat->st_mtime)
		{
			st = dir->stat;
			dir->stat = dir->next->stat;
			dir->next->stat = st;
			tmp = dir->f_name;
			dir->f_name = dir->next->f_name;
			dir->next->f_name = tmp;
			dir = rewind_lst(dir);
		}
		else
			dir = dir->next;
	}
}

void	sort_ftl(t_fl *dir)
{
	char	*tmp;
	t_stat	*tp;

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
	free(tp);
	free(tmp);
	print_ftl(dir);
}

int		swap_dir(t_file *dir)
{
	char	*tmp;
	t_stat	*st;

	st = dir->stat;
	dir->stat = dir->next->stat;
	dir->next->stat = st;
	tmp = dir->f_name;
	dir->f_name = dir->next->f_name;
	dir->next->f_name = tmp;
	return (1);
}

void	sort_dir(t_file *dir)
{
	char	*tmp;
	t_stat	*st;
	t_file	*start;
	int		swapped;

	start = dir;
	if (g_flags[FLAG_T] == 1)
		sort_date(dir);
	else
	{
		swapped = 1;
		while (swapped == 1)
		{
			swapped = 0;
			dir = start;
			while (dir->next)
			{
				if (ft_strcmp(dir->f_name, dir->next->f_name) > 0)
					swapped = swap_dir(dir);
				dir = dir->next;
			}
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
