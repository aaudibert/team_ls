/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:14:33 by psaint-j          #+#    #+#             */
/*   Updated: 2015/12/14 17:20:56 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fl		*init_file_tl(char **ftab)
{
	int		i;
	t_fl	*prm;

	i = 0;
	prm = malloc(sizeof(t_fl));
	prm->f = ft_strdup(ftab[i]);
	prm->stat = malloc(sizeof(struct stat));
	lstat(ftab[i], prm->stat);
	prm->prev = NULL;
	return (prm);
}

void		file_tl(char **ftab)
{
	int		i;
	t_fl	*prm;
	t_fl	*tmp;

	i = 1;
	prm = init_file_tl(ftab);
	while (ftab[i])
	{
		tmp = malloc(sizeof(t_fl));
		tmp->f = ft_strdup(ftab[i]);
		tmp->stat = malloc(sizeof(struct stat));
		lstat(ftab[i], tmp->stat);
		lstat(ftab[i], tmp->stat);
		tmp->f = ft_strdup(ftab[i]);
		tmp->prev = prm;
		tmp->next = NULL;
		prm->next = tmp;
		prm = prm->next;
		tmp = tmp->next;
		i++;
	}
	prm->next = NULL;
	while (prm->prev != NULL)
		prm = prm->prev;
	sort_ftl(prm);
}
