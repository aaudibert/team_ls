/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 17:05:49 by psaint-j          #+#    #+#             */
/*   Updated: 2016/04/29 15:39:28 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		prm_new(t_prm *s)
{
	if (s->e > 0)
	{
		s->error = (char **)malloc(sizeof(char *) * (s->e + 1));
		s->error[s->e] = NULL;
	}
	else
		s->error = 0;
	if (s->f > 0)
	{
		s->file = (char **)malloc(sizeof(char *) * (s->f + 1));
		s->file[s->f] = NULL;
	}
	else
		s->file = 0;
	if (s->d > 0)
	{
		s->ddir = (char **)malloc(sizeof(char *) * (s->d + 1));
		s->ddir[s->d] = NULL;
	}
	else
		s->ddir = 0;
}

t_prm		*check_params(char **paths, t_prm *s, int i)
{
	struct stat		t;

	prm_new(s);
	while (paths[i])
	{
		if (lstat(paths[i], &t) != 0)
			s->error[--s->e] = paths[i];
		else if ((t.st_mode & S_IFREG) || (S_ISLNK(t.st_mode) &&
					paths[i][ft_strlen(paths[i])] == '/' &&
					g_flags[FLAG_L] == 1))
			s->file[--s->f] = paths[i];
		else if (S_ISDIR(t.st_mode))
			s->ddir[--s->d] = paths[i];
		i++;
	}
	return (s);
}
