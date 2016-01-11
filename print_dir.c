/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 17:30:14 by aaudiber          #+#    #+#             */
/*   Updated: 2016/01/11 17:02:49 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int *g_flags;

void		print_ftl(t_fl *dir)
{
	if (g_flags[FLAG_R] != 1)
	{
		while (dir != NULL)
		{
			ft_putendl(dir->f);
			dir = dir->next;
		}
	}
	else
	{
		while (dir->next != NULL)
			dir = dir->next;
		while (dir != NULL)
		{
			ft_putendl(dir->f);
			dir = dir->prev;
		}
	}
}

void		print_dir(t_file *dir)
{
	if (g_flags[FLAG_L] == 1)
		ls_l(dir);
	else if (g_flags[FLAG_R] != 1)
	{
		while (dir != NULL)
		{
			if (opt_a(dir))
				ft_putendl(dir->f_name);
			dir = dir->next;
		}
	}
	else
	{
		while (dir->next != NULL)
			dir = dir->next;
		while (dir != NULL)
		{
			if (opt_a(dir))
				ft_putendl(dir->f_name);
			dir = dir->prev;
		}
	}
}
