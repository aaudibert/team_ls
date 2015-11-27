/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 17:05:49 by psaint-j          #+#    #+#             */
/*   Updated: 2015/11/27 14:38:29 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		prm_new(t_prm *s)
{
	if (s->e)
		s->error = (char **)malloc(sizeof(char *) * (s->e + 1));
	else
		s->error = NULL;
	if (s->f)
		s->file = (char **)malloc(sizeof(char *) * (s->f + 1));
	else
		s->file = NULL;
	if (s->d)
		s->ddir = (char **)malloc(sizeof(char *) * (s->d + 1));
	else
		s->ddir = NULL;
	s->f--;
	s->d--;
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
			s->ddir[s->d] = paths[i];
			s->d--;
			closedir(dir);
		}
		else if (v != 0)
			s->error[s->e] = errfunc(s, paths[i]);
		else if ((t.st_mode & S_IFREG))
		{
			s->file[s->f] = paths[i];
			s->f--;
		}
		i++;
	}
	return (s);
}
