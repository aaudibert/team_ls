/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <yalaouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 19:35:27 by yalaouf           #+#    #+#             */
/*   Updated: 2016/01/27 16:46:19 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_ischr(t_file *dir)
{
	ft_putnbr(major(dir->stat->st_rdev));
	ft_putstr(", ");
	ft_putnbr(minor(dir->stat->st_rdev));
	ft_putchar(' ');
}

void	ls_l(t_file *dir, int i)
{
	unsigned int	*max_all;

	if (i == 0)
		total_block(dir);
	max_all = max(dir);
	while (dir != NULL)
	{
		if (opt_a(dir))
		{
			letters(*(dir->stat));
			display_link_right(max_all[1], *(dir->stat));
			ft_putchar(' ');
			affect(*(dir->stat));
			if (S_ISCHR(dir->stat->st_mode) || S_ISBLK(dir->stat->st_mode))
				print_ischr(dir);
			else
				display_size_right(max_all[0], *(dir->stat));
			date(*(dir->stat));
			ifslnk(*(dir->stat), dir, i);
		}
		dir = dir->next;
	}
	free(max_all);
}
