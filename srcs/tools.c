/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 18:18:39 by yalaouf           #+#    #+#             */
/*   Updated: 2016/03/14 22:06:30 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void				set_align(t_align *mx)
{
	max_all->rights = 0;
	max_all->link = 0;
	max_all->usr = 0;
	max_all->grp = 0;
	max_all->size = 0;
	max_all->date = 0;
}

t_align				*max(t_file *dir)
{
	t_align	*max_all;
	char	*tusr;
	char	*tgrp;

	if (getpwuid(dir->stat->st_uid))
		tusr = getpwuid(dir->stat->st_uid)->pw_name;
	if (getgrgid(dir->stat->st_gid))
		tgrp = getpgrgid(dir->stat->st_gid)->gr_name;
	max_all = (t_align*)malloc(sizeof(t_align));
	while (dir != NULL)
	{
		if (opt_a(dir))
		{
			/*if (max_all->rights || verif @ || verif +)
				max_all->rights = 1;*/
			if (dir->stat->st_nlink > max_all->link)
				max_all->link = dir->stat->st_nlink;
			if (ft_strlen(tusr) > max_all->usr)
				max_all->usr = ft_strlen(tusr);
			if (ft_strlen(tgrp) > max_all->grp)
				max_all->grp = ft_strlen(tgrp);
			if (dir->stat->st_size > max_all->size)
				max_all->size = dir->stat->st_size;
			//date
		}
		dir = dir->next;
	}
	return (max_all);
}

void				display_size_right(int max_size, t_stat stats)
{
	int max_length;
	int actual_length;
	int space_nbr;

	max_length = ft_intlen(max_size);
	actual_length = ft_intlen(stats.st_size);
	space_nbr = max_length - actual_length;
	if (max_length == actual_length)
		ft_putnbr(stats.st_size);
	else if (max_length > actual_length)
	{
		while (space_nbr--)
			ft_putchar(' ');
		ft_putnbr(stats.st_size);
	}
}

void				display_link_right(int max_link, t_stat stats)
{
	int max_length;
	int actual_length;
	int space_nbr;

	max_length = ft_intlen(max_link);
	actual_length = ft_intlen(stats.st_nlink);
	space_nbr = max_length - actual_length;
	if (max_length == actual_length)
	{
		ft_putstr("  ");
		ft_putnbr(stats.st_nlink);
	}
	else if (max_length > actual_length)
	{
		while (space_nbr--)
			ft_putchar(' ');
		ft_putnbr(stats.st_nlink);
	}
}

void				date(t_stat stats)
{
	char **date;
	char **date_f;

	date = ft_strsplit(ctime(&stats.st_mtime), ' ');
	ft_putchar(' ');
	ft_putstr_space(date[1], 1);
	display_date_right(date);
	ft_putchar(' ');
	date_f = ft_strsplit(date[3], ':');
	ft_putstr(date_f[0]);
	ft_putchar(':');
	ft_putstr_space(date_f[1], 1);
	ft_free_tab(date);
	ft_free_tab(date_f);
}
