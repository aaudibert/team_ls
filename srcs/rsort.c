/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:12:54 by aaudiber          #+#    #+#             */
/*   Updated: 2016/01/28 17:49:07 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	rsort_date(t_file *dir)
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
			if (dir->stat->st_mtime > dir->next->stat->st_mtime)
				swapped = swap_dir(dir);
			else if (dir->stat->st_mtime == dir->next->stat->st_mtime &&
					ft_strcmp(dir->f_name, dir->next->f_name) < 0)
				swapped = swap_dir(dir);
			dir = dir->next;
		}
	}
}

void	rsort_dir(t_file *dir)
{
	t_file	*start;
	int		swapped;

	start = dir;
	if (g_flags[FLAG_T] == 1)
		rsort_date(dir);
	else
	{
		swapped = 1;
		while (swapped == 1)
		{
			swapped = 0;
			dir = start;
			while (dir->next)
			{
				if (ft_strcmp(dir->f_name, dir->next->f_name) < 0)
					swapped = swap_dir(dir);
				dir = dir->next;
			}
		}
	}
}
