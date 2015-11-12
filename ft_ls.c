/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 17:15:30 by aaudiber          #+#    #+#             */
/*   Updated: 2015/11/12 16:08:49 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*g_flags;

int		main(int ac, char **av)
{
	int		f;
	char	**paths;

	f = 0;
	if (ac > 1)
	{
		g_flags = (int *)malloc(sizeof(int) * 5);
		paths = (char **)malloc(sizeof(char *) * (f + 1));
		ft_bzero(g_flags, sizeof(int) * 5);
		f = parser(ac, av);
	}
	else 
		get_data("./");
	/*else
	{
		paths = check_params(f + 1, av);
		paths = sort_params(paths);
	}*/
	return (0);
}
