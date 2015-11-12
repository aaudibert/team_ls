/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 17:30:14 by aaudiber          #+#    #+#             */
/*   Updated: 2015/11/12 20:43:11 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int *g_flags;

void		print_dir(t_file *dir)
{
	if (g_flags[FLAG_R] != 1)
	{
		while (dir != NULL)
		{
			if (opt_a(dir))
				ft_putendl(dir->f_name);
			dir = dir->next;
		}
	}
	/*else
	{
		reverse
	}*/
}
