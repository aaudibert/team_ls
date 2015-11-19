/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recurs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 14:27:26 by aaudiber          #+#    #+#             */
/*   Updated: 2015/11/19 19:31:00 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			*g_flags;

void		ft_recurs(t_file *dir)
{
	print_dir(dir);
	ft_putchar('\n');
	while (dir != NULL)
	{
		while (dir && (ft_strequ(".", dir->f_name) == 1 ||
					ft_strequ("..", dir->f_name) == 1))
			dir = dir->next;
		if (dir)
		{
			if (S_ISDIR(dir->stat->st_mode))
			{
				if (dir->f_name[0] == '.' && g_flags[FLAG_RR])
				ft_putstr(dir->path);
				ft_putendl(" :");
				get_data(ft_strjoin(ft_strjoin(dir->path, dir->f_name), "/"));
			}
			dir = dir->next;
		}
	}
}
