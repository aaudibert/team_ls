/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_perm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 20:58:39 by aaudiber          #+#    #+#             */
/*   Updated: 2016/04/27 21:03:22 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			no_permx(t_file *dir)
{
	while (dir != NULL)
	{
		if (opt_a(dir) && dir->stat->st_mode & S_IXUSR)
			return (1);
		dir = dir->next;
	}
	return (0);
}

int			no_perm(t_file *dir)
{
	while (dir != NULL)
	{
		if (opt_a(dir) && dir->stat->st_mode & S_IXUSR)
			return (1);
		dir = dir->next;
	}
	return (0);
}
