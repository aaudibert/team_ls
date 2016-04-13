/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 19:31:48 by aaudiber          #+#    #+#             */
/*   Updated: 2016/04/13 18:00:50 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		set_max(t_file *dir, t_align *max_all)
{
	char	*tusr;
	char	*tgrp;

	if (getpwuid(dir->stat->st_uid))
		tusr = getpwuid(dir->stat->st_uid)->pw_name;
	else
		tusr = ft_itoa(dir->stat->st_uid);
	if (getgrgid(dir->stat->st_gid))
		tgrp = getgrgid(dir->stat->st_gid)->gr_name;
	else
	tgrp = ft_itoa(dir->stat->st_uid);
	if (ft_intlen(dir->stat->st_nlink) > max_all->link)
		max_all->link = ft_intlen(dir->stat->st_nlink);
	if (tusr && (int)ft_strlen(tusr) > max_all->usr)
		max_all->usr = ft_strlen(tusr);
	if (tgrp != NULL && (int)ft_strlen(tgrp) > max_all->grp)
		max_all->grp = ft_strlen(tgrp);
	if (ft_intlen(dir->stat->st_size) > max_all->size)
		max_all->size = ft_intlen(dir->stat->st_size);
}