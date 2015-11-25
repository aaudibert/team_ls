/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recurs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 14:27:26 by aaudiber          #+#    #+#             */
/*   Updated: 2015/11/25 15:44:47 by aaudiber         ###   ########.fr       */
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
			if (opt_a(dir))
			{
				if (dir->izdir == 1)
				{
					ft_putendl(dir->f_name);
					ft_putstr(ft_strjoin(ft_strjoin(dir->path, dir->f_name), "/"));
					ft_putendl(" :");
					get_data(ft_strjoin(ft_strjoin(dir->path, dir->f_name), "/"));
				}
			}
			dir = dir->next;
		}
	}
}
