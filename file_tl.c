/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:50:14 by aaudiber          #+#    #+#             */
/*   Updated: 2015/12/11 19:14:54 by psaint-j         ###   ########.fr       */
/*   Updated: 2015/12/10 19:57:21 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		file_tl(char **ftab)
{
	int		i;
	t_fl	*prm;
	t_fl	*tmp;

	i = 0;
	prm = malloc(sizeof(t_fl));
	prm = malloc(sizeof(t_fl*));
	prm->f = ft_strdup(ftab[i]);
	prm->stat = malloc(sizeof(struct stat));
	lstat(ftab[i], prm->stat);
	prm->prev = NULL;
	ft_putendl(prm->f);
	i++;
	while (ftab[i])
	{
		tmp = malloc(sizeof(t_fl));
		tmp->f = ft_strdup(ftab[i]);
		tmp->stat = malloc(sizeof(struct stat));
		lstat(ftab[i], tmp->stat);
		ft_putendl(tmp->f);
		//tmp = malloc(sizeof(t_fl*));
		//tmp->stat = malloc(sizeof(struct stat));
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
		//free(tmp);
	sort_ftl(prm);
//	ft_putendl("HERE");
}
