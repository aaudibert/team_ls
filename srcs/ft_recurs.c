/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recurs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 14:27:26 by aaudiber          #+#    #+#             */
/*   Updated: 2016/04/26 19:21:46 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			*g_flags;

void		rec_print(t_file *dir)
{
	char *s;
	char *new;

	if (g_rec == 1)
		ft_putchar('\n');
	if (g_rec == 0)
		g_rec++;
	s = ft_strjoin(dir->path, dir->f_name);
	ft_putstr(s);
	ft_putchar('/');
	new = ft_strjoin(s, "/");
	ft_putendl(":");
	get_data(new);
	free(s);
	free(new);
}

void		ft_recurs(t_file *dir)
{
	print_dir(dir, 0);
	while (dir != NULL)
	{
		while (dir && (ft_strequ(".", dir->f_name) == 1 ||
					ft_strequ("..", dir->f_name) == 1))
			dir = dir->next;
		if (dir && STAT)
		{
			if (opt_a(dir) && S_ISDIR(dir->stat->st_mode))
				rec_print(dir);
			dir = dir->next;
		}
		else if (!STAT)
			dir = dir->next;
	}
}
