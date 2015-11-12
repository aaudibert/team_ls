/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 17:30:14 by aaudiber          #+#    #+#             */
/*   Updated: 2015/11/12 17:12:14 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int *g_flags;

void		print_dir(t_file *dir)
{
	while (dir != NULL)
	{
		ft_putendl(dir->prev->f_name);
		ft_putendl(dir->f_name);
		dir = dir->next;
	}
}
