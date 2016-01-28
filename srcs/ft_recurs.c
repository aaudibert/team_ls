/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recurs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 14:27:26 by aaudiber          #+#    #+#             */
/*   Updated: 2016/01/28 20:30:06 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			*g_flags;

void		rec_print(t_file *dir)
{
	char *s;

	s = ft_strjoin(dir->path, dir->f_name);
	s = ft_strjoin(s, "/");
	ft_putstr(s);
	ft_putendl(":");
	get_data(s);
	free(s);
}

void		ft_recurs(t_file *dir)
{
	print_dir(dir, 0);
	ft_putchar('\n');
	while (dir != NULL)
	{
		while (dir && (ft_strequ(".", dir->f_name) == 1 ||
					ft_strequ("..", dir->f_name) == 1))
			dir = dir->next;
		if (dir)
		{
			if (opt_a(dir) && S_ISDIR(dir->stat->st_mode))
					rec_print(dir);
			dir = dir->next;
		}
	}
}
