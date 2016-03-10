/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 17:30:14 by aaudiber          #+#    #+#             */
/*   Updated: 2016/03/10 19:48:19 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int *g_flags;

void		print_dir(t_file *dir, int file)
{
	if (g_flags[FLAG_L] == 1 && file == 0)
		ls_l(dir, 0);
	else
	{
		while (dir != NULL)
		{
			if (opt_a(dir) && file == 0 && S_ISDIR(dir->stat->st_mode))
				ft_putendl_color(dir->f_name, CYAN);
			else if (opt_a(dir) && file == 0 && dir->stat->st_mode & S_IXUSR)
				ft_putendl_color(dir->f_name, RED);
			else if (opt_a(dir) || file == 1)
				ft_putendl(dir->f_name);
			dir = dir->next;
		}
	}
}
