/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 17:30:14 by aaudiber          #+#    #+#             */
/*   Updated: 2016/01/27 16:41:30 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int *g_flags;

void		print_dir(t_file *dir, int file)
{
	if (g_flags[FLAG_L] == 1)
		ls_l(dir, 0);
	else
	{
		while (dir != NULL)
		{
			if (opt_a(dir) && file == 0)
				ft_putendl(dir->f_name);
			else if (file == 1 && ft_strcmp("./", dir->path) != 0)
			{
				ft_putstr(dir->path);
				ft_putendl(dir->f_name);
			}
			else
				ft_putendl(dir->f_name);
			dir = dir->next;
		}
	}
}
