/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recurs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 14:27:26 by aaudiber          #+#    #+#             */
/*   Updated: 2015/11/17 15:23:32 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_recurs(t_file *dir)
{
	print_list(dir);
	ft_putchar('\n');
	while (dir != NULL)
	{
		while (dir && (ft_strequ(".", dir->f_name) == 1 ||
					ft_strequ("..", dir->f_name) == 1))
			dir = dir->next;
		if (dir)
		{
			if (S_ISDIR(dir->stat->st_mode))
			{
				ft_putstr(dir->path);
				ft_putendl(" :");
				get_data(dir->path);
			}
			dir = dir->next;
		}
	}
}
