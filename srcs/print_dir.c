/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 17:30:14 by aaudiber          #+#    #+#             */
/*   Updated: 2016/04/12 19:47:07 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int *g_flags;

void		col_print(t_file *dir, int file, t_stat *st)
{
	if (file == 1 || st->st_mode & S_IXUSR)
	{
		if (file == 0 && S_ISDIR(dir->stat->st_mode))
			ft_putendl_color(dir->f_name, CYAN);
		else if (file == 0 && dir->stat->st_mode & S_IXUSR &&
				S_ISREG(dir->stat->st_mode))
			ft_putendl_color(dir->f_name, RED);
		else
			ft_putendl(dir->f_name);
	}
	else
	{
		ft_putstr("ls: ");
		ft_putjoin(dir->f_name, ": Permission denied");
	}
}

void		print_dir(t_file *dir, int file)
{
	t_stat *st;

	st = (t_stat *)malloc(sizeof(t_stat));
	g_rec = 1;
	lstat(dir->path, st);
	if (g_flags[FLAG_L] == 1 && file == 0)
		ls_l(dir, 0, st);
	else
	{
		while (dir != NULL)
		{
			if (opt_a(dir))
				col_print(dir, file, st);
			dir = dir->next;
		}
	}
	free(st);
}
