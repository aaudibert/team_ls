/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 17:15:30 by aaudiber          #+#    #+#             */
/*   Updated: 2015/12/07 18:00:57 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*g_flags;

void		one_path(char *path)
{
	if (path[ft_strlen(path) - 1] == '/')
		get_data(path);
	else
		get_data(ft_strjoin(path, "/"));
}

void		to_prm(char **paths)
{
	int f;

	f = 0;
	if (paths[1])
	{
		while (paths[f])
		{
			ft_putstr(paths[f]);
			ft_putendl(" :");
			if (paths[f][ft_strlen(paths[f]) - 1] == '/')
				get_data(paths[f]);
			else
				get_data(ft_strjoin(paths[f], "/"));
			f++;
		}
	}
	else
		one_path(paths[f]);
}

int			main(int ac, char **av)
{
	int		f;
	char	**paths;

	g_flags = (int *)malloc(sizeof(int) * 5);
	ft_bzero(g_flags, sizeof(int) * 5);
	f = 0;
	if (ac > 1)
	{
		f = parser(ac, av);
		paths = (char **)malloc(sizeof(char *) * (f + 1));
		if (ac - f == 1)
			get_data("./");
		else
		{
			paths = checks(av, f + 1);
			if (paths)
				to_prm(paths);
		}
	}
	else
		get_data("./");
	return (0);
}
