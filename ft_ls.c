/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 17:15:30 by aaudiber          #+#    #+#             */
/*   Updated: 2015/11/27 13:51:20 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*g_flags;

void		to_prm(char **paths)
{
	int f;

	f = 0;
	while (paths[f])
	{
		ft_putstr(paths[f]);
		ft_putendl(" :");
		get_data(paths[f]);
		f++;
		if (paths[f])
			ft_putchar('\n');
	}
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
			to_prm(paths);
		}
	}
	else
		get_data("./");
	return (0);
}
