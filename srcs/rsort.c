/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:12:54 by aaudiber          #+#    #+#             */
/*   Updated: 2016/04/25 18:56:29 by aaudiber         ###   ########.fr       */
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
			if (dir->stat->TIME > dir->next->stat->TIME)
				swapped = swap_dir(dir);
			else if (dir->stat->TIME == dir->next->stat->TIME &&
					dir->stat->NTIME > dir->next->stat->NTIME)
				swapped = swap_dir(dir);
			else if (dir->stat->TIME == dir->next->stat->TIME &&
					dir->stat->NTIME == dir->next->stat->NTIME &&
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
