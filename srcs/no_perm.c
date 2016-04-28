/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_perm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 20:58:39 by aaudiber          #+#    #+#             */
/*   Updated: 2016/04/28 21:10:21 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			no_permx(t_file *dir, t_stat *st)
{
	while (dir != NULL)
	{
		if (opt_a(dir) && st->st_mode & S_IXUSR)
			return (1);
		dir = dir->next;
	}
	return (0);
}

int			no_perm(t_file *dir)
{
	while (dir != NULL)
	{
		if (opt_a(dir) && !ERR)
			return (1);
		dir = dir->next;
	}
	return (0);
}
