/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 17:15:30 by aaudiber          #+#    #+#             */
/*   Updated: 2015/11/24 17:47:20 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*g_flags;

int		main(int ac, char **av)
{
	int		f;
	char	**paths;

	g_flags = (int *)malloc(sizeof(int) * 5);
	ft_bzero(g_flags, sizeof(int) * 5);
	f = 0;
	if (ac > 1)
	{
		paths = (char **)malloc(sizeof(char *) * (f + 1));
		f = parser(ac, av);
	/*	paths = check_params(f + 1, av);
		paths = sort_params(paths);
		get_data(paths);*/
	}
	else 
		get_data("./");
	return (0);
}
