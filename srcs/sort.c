/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:54:47 by rlechapt          #+#    #+#             */
/*   Updated: 2016/03/23 17:24:34 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

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

void	sort_date(t_file *dir)
{
	t_file	*start;
	int		swapped;

	start = dir;
	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		dir = start;
		while (dir->next)
		{
			if (dir->stat->TIME < dir->next->stat->TIME)
				swapped = swap_dir(dir);
			else if (dir->stat->TIME == dir->next->stat->TIME &&
					ft_strcmp(dir->f_name, dir->next->f_name) > 0)
				swapped = swap_dir(dir);
			dir = dir->next;
		}
	}
}

void	sort_dir(t_file *dir)
{
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
