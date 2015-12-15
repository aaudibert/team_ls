/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 17:05:49 by psaint-j          #+#    #+#             */
/*   Updated: 2015/12/15 12:42:20 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		prm_new(t_prm *s)
{
	if (s->e > 0)
	{
		s->error = (char **)malloc(sizeof(char *) * (s->e + 1));
		s->error[s->e] = NULL;
	}
	else
		s->error = NULL;
	if (s->f > 0)
	{
		s->file = (char **)malloc(sizeof(char *) * (s->f + 1));
		s->file[s->f] = NULL;
	}
	else
		s->file = NULL;
	if (s->d > 0)
	{
		s->ddir = (char **)malloc(sizeof(char *) * s->d + 1);
		s->ddir[s->d] = NULL;
	}
	else
		s->ddir = NULL;
}

char		*errfunc(t_prm *s, char *path)
{
	s->e--;
	return (path);
}

t_prm		*check_params(char **paths, t_prm *s, int i)
{
	int				v;
	DIR				*dir;
	struct stat		t;

	prm_new(s);
	while (paths[i])
	{
		dir = opendir(paths[i]);
		v = stat(paths[i], &t);
		if (dir)
		{
			s->d--;
			s->ddir[s->d] = paths[i];
			closedir(dir);
		}
		else if (v != 0)
			s->error[s->e] = errfunc(s, paths[i]);
		else if ((t.st_mode & S_IFREG))
		{
			s->f--;
			s->file[s->f] = paths[i];
		}
		i++;
	}
	return (s);
}
