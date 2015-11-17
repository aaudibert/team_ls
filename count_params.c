/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 16:43:56 by psaint-j          #+#    #+#             */
/*   Updated: 2015/11/17 17:04:37 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>


void	count_params(int ac, char **av, t_prm *s, int i)
{
	int				v;
	DIR				*dir;
	struct stat		t;

	s->d = 0;
	s->f = 0;
	s->e = 0;
	while (av[i])
	{
		dir = opendir(av[i]);
		v = stat(av[i], &t);
		if (dir)
			s->d++;
		if (v != 0)
		{
			s->e++;
		}
		else if ((t.st_mode & S_IFREG))
			s->f++;
		i++;
	}
}


int		main(int ac, char **av)
{
	count_params(ac, av,t_pr, 1);
	return (0);
}
