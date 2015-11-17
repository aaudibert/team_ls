/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 17:05:49 by psaint-j          #+#    #+#             */
/*   Updated: 2015/11/17 16:56:13 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>


char		**check_params(int ac, char **av, int i)
{
	int				v;
	DIR				*dir;
	struct stat		t;
	t_prm s;

	s->d;
	while (av[i])
	{
		dir = opendir(av[i]);
		v = stat(av[i], &t);
		if (dir)
			printf("%s\tDIR\n", av[i]);
		if (v != 0)
		{
			printf("%s\tERROR\n", av[i]);
		}
		else if ((t.st_mode & S_IFREG))
			printf("%s\tFILE\n", av[i]);
		i++;
	}
	return (true_path);
}


int		main(int ac, char **av)
{
	check_params(ac, av, 1);
	return (0);
}
