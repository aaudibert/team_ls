/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 17:15:30 by aaudiber          #+#    #+#             */
/*   Updated: 2016/04/30 18:23:59 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		*g_flags;

void		one_path(t_file *path)
{
	char *s;

	s = ft_strjoin(path->path, "/");
	if (path->path[ft_strlen(path->path) - 1] == '/')
		get_data(path->path);
	else
		get_data(s);
	free(s);
}

void		to_prm(t_file *paths)
{
	char	*s;

	s = NULL;
	if (paths->next)
	{
		while (paths != NULL)
		{
			ft_putstr(paths->path);
			ft_putendl(":");
			s = ft_strjoin(paths->path, "/");
			if (paths->path[ft_strlen(paths->path) - 1] == '/')
				get_data(paths->path);
			else
				get_data(s);
			paths = paths->next;
			if (paths)
				ft_putchar('\n');
		}
	}
	else
		one_path(paths);
	free(s);
	free(g_flags);
}

int			main(int ac, char **av)
{
	int		f;
	t_file	*paths;

	g_flags = (int *)malloc(sizeof(int) * 6);
	ft_bzero(g_flags, sizeof(int) * 5);
	f = 0;
	if (ac > 1)
	{
		f = parser(ac, av);
		if (ac - f == 1)
			get_data("./");
		else
		{
			paths = checks(av, f + 1);
			if (paths)
			{
				to_prm(paths);
				ft_free_dir_lst(paths);
			}
		}
	}
	else
		get_data("./");
	return (0);
}
