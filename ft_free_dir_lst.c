/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dir_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:17:02 by aaudiber          #+#    #+#             */
/*   Updated: 2016/01/14 19:11:58 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		del_link(t_file *dir)
{
	free(dir->stat);
	free(dir);
}

void		free_dir_fl(t_fl *dir)
{
	t_fl *tmp;

	while (dir)
	{
		tmp = dir->next;
		free(dir->stat);
		free(dir->f);
		dir = tmp;
	}
}

void		ft_free_dir_lst(t_file *dir)
{
	t_file *tmp;

	while (dir)
	{
		tmp = dir->next;
		del_link(dir);
		dir = tmp;
	}
}
