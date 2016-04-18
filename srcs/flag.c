/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <yalaouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 19:35:27 by yalaouf           #+#    #+#             */
/*   Updated: 2016/04/18 19:34:28 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		print_ischr(t_file *dir, t_align *max_all)
{
	ft_putnbr(major(dir->stat->st_rdev));
	ft_putstr(", ");
	if (/*conditions espace*/)
	ft_putnbr(minor(dir->stat->st_rdev));
	ft_putchar(' ');
}

int			no_perm(t_file *dir)
{
	while (dir != NULL)
	{
		if (opt_a(dir) && dir->stat->st_mode & S_IRUSR)
			return (1);
		dir = dir->next;
	}
	return (0);
}

void		err_l(char *s)
{
	ft_putstr("ls: ");
	ft_putstr(s);
	ft_putstr(": ");
	perror("");
}

void		ls_l(t_file *dir, int i, t_stat *st)
{
	t_align *max_all;

	if (i == 0)
		total_block(dir);
	max_all = max(dir, i, st);
	while (dir != NULL)
	{
		if (i == 1 || (opt_a(dir) && st->st_mode & S_IXUSR))
		{
			letters(*(dir->stat));
			display_link_right(dir, max_all);
			if (S_ISCHR(dir->stat->st_mode) || S_ISBLK(dir->stat->st_mode))
				print_ischr(dir, max_all);
			else
				display_size_right(max_all->size, *(dir->stat));
			date(dir, *(dir->stat));
		}
		else if (opt_a(dir))
			err_l(dir->f_name);
		dir = dir->next;
	}
	free(max_all);
}
