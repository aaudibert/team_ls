/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 16:43:56 by psaint-j          #+#    #+#             */
/*   Updated: 2015/11/25 16:27:33 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>


t_prm	*count_params(int ac, char **av, t_prm *s, int i)
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
	return (s);
}

void ft_printab(char **env)
{
	int		i;

	i = 0;
	if (env != NULL)
	{
		while (env[i])
		{
			ft_putendl(env[i]);
			i++;
		}
	}
	else
		return;
}


int		main(int ac, char **av)
{
	t_prm	s;
	char	**avv;

	avv = av;
	count_params(ac, avv, &s, 1);
	check_params(ac, avv, &s, 1);
	//printf("File : %d\n", s.f);
	//printf("errorr : %d\n", s.e);
	//printf("Dir : %d\n", s.d);
	ft_putendl("\033[31m--TAB ERROR--");
	ft_printab(s.error);
	ft_putendl("\033[32m--TAB FILE--");
	ft_printab(s.file);
	ft_putendl("\033[35m--TAB DIR--");
	ft_printab(s.ddir);
	return (0);
}
