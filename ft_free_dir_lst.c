/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dir_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:17:02 by aaudiber          #+#    #+#             */
/*   Updated: 2016/01/27 20:25:54 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		del_struct(t_prm s)
{
	free(s.ddir);
	free(s.file);
	free(s.error);
}

void		del_link(t_file *dir)
{
	free(dir->stat);
	free(dir->f_name);
	free(dir);
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
