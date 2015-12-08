/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:50:14 by aaudiber          #+#    #+#             */
/*   Updated: 2015/12/08 17:28:53 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		file_tl(char **ftab)
{
	int		i;
	t_fl	*prm;
	t_fl	*tmp;

	i = 0;
	prm = malloc(sizeof(t_fl*));
	tmp = malloc(sizeof(t_fl*));
	prm->f = ft_strdup(ftab[i]);
	prm->stat = malloc(sizeof(struct stat));
	lstat(ftab[i], prm->stat);
	prm->prev = NULL;
	prm->next = NULL;
	i++;
	while (ftab[i])
	{
		tmp->f = ft_strdup(ftab[i]);
		tmp->stat = malloc(sizeof(struct stat));
		lstat(ftab[i], tmp->stat);
		tmp->prev = prm;
		prm->next = tmp;
		prm = prm->next;
		free(tmp);
		i++;
	}
	//sort_ftl(prm);
}
