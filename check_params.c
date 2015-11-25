/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 17:05:49 by psaint-j          #+#    #+#             */
/*   Updated: 2015/11/25 17:13:30 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		prm_new(t_prm * s)
{
	s->error = (char **)malloc(sizeof(char*) * (s->e + 1));
	s->file = (char **)malloc(sizeof(char*) * (s->f + 1));
	s->ddir = (char **)malloc(sizeof(char*) * (s->d + 1));
	s->f--;
	s->e--;
	s->d--;
	return (s);
}

t_prm		*check_params(char **paths, t_prm *s, int i)
{
	int				v;
	DIR				*dir;
	struct stat		t;

	prm_new(s);
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
	return (s);
}
