/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_date.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 18:27:58 by psaint-j          #+#    #+#             */
/*   Updated: 2016/01/14 17:19:36 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define T stat->st_mtime

void		sort_same_date(t_fl *dir)
{
	char		*tmp;
	struct stat *tp;

	while (dir->next)
	{
		if (dir->T == dir->next->T && ft_strcmp(dir->f, dir->next->f) > 0)
		{
			tmp = dir->f;
			tp = dir->stat;
			dir->f = dir->next->f;
			dir->stat = dir->next->stat;
			dir->next->f = tmp;
			dir->next->stat = tp;
			while (dir->prev != NULL)
				dir = dir->prev;
		}
		else
			dir = dir->next;
	}
	while (dir->prev != NULL)
		dir = dir->prev;
}
