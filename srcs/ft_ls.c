/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 17:15:30 by aaudiber          #+#    #+#             */
/*   Updated: 2016/04/28 16:25:17 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		*g_flags;

void		one_path(char *path)
{
	char *s;

	s = ft_strjoin(path, "/");
	if (path[ft_strlen(path) - 1] == '/')
		get_data(path);
	else
		get_data(s);
	free(s);
}

void		to_prm(char **paths)
{
	int		f;
	char	*s;

	f = 0;
	s = NULL;
	if (paths[1])
	{
		while (paths[f])
		{
			ft_putstr(paths[f]);
			ft_putendl(":");
			s = ft_strjoin(paths[f], "/");
			if (paths[f][ft_strlen(paths[f]) - 1] == '/')
				get_data(paths[f]);
			else
				get_data(s);
			f++;
			if (paths[f])
				ft_putchar('\n');
		}
	}
	else
		one_path(paths[f]);
	free(s);
	free(g_flags);
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
			{
				to_prm(paths);
				ft_free_tab(paths);
			}
		}
	}
	else
		get_data("./");
	return (0);
}
