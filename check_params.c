/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 17:05:49 by psaint-j          #+#    #+#             */
/*   Updated: 2015/11/25 16:20:28 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	check_params(int ac, char **av, t_prm *s, int i)
{
	int				v;
	DIR				*dir;
	struct stat		t;

	s->error = (char **)malloc(sizeof(char*) * (s->e + 1));
	s->file = (char **)malloc(sizeof(char*) * (s->f + 1));
	s->ddir = (char **)malloc(sizeof(char*) * (s->d + 1));
	//s->file[s->f + 1] = NULL;
	//s->error[s->e + 1] = NULL;
	//s->ddir[s->d + 1] = NULL;
	s->f--;
	s->e--;
	s->d--;
	while (av[i])
	{
		dir = opendir(av[i]);
		v = stat(av[i], &t);
		if (dir)
		{
			s->ddir[s->d] = av[i];
			s->d--;
			closedir(dir);
		}
		else if (v != 0)
		{
			s->error[s->e] = av[i];
			s->e--;
		}
		else if ((t.st_mode & S_IFREG))
		{
			s->file[s->f] = av[i];
			s->f--;
		}
		i++;
	}
}
