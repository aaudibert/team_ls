/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 18:18:39 by yalaouf           #+#    #+#             */
/*   Updated: 2016/03/22 17:50:02 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_align				*max(t_file *dir)
{
	t_align	*max_all;
	max_all = (t_align*)malloc(sizeof(t_align));
	max_all->link = 0;
	max_all->usr = 0;
	max_all->grp = 0;
	max_all->size = 0;
	while (dir != NULL)
	{
		if (opt_a(dir) && dir->stat->st_mode & S_IRUSR)
			set_max(dir, max_all);
		dir = dir->next;
	}
	return (max_all);
}

void				display_size_right(int max_size, t_stat stats)
{
	int actual_length;
	int space_nbr;

	actual_length = ft_intlen(stats.st_size);
	space_nbr = max_size - actual_length;
	if (max_size == actual_length)
		ft_putnbr(stats.st_size);
	else if (max_size > actual_length)
	{
		while (space_nbr--)
			ft_putchar(' ');
		ft_putnbr(stats.st_size);
	}
}

void				display_link_right(int max_link, t_stat stats)
{
	int actual_length;
	int space_nbr;

	actual_length = ft_intlen(stats.st_nlink);
	space_nbr = max_link - actual_length;
	if (max_link == actual_length)
	{
		ft_putstr("  ");
		ft_putnbr(stats.st_nlink);
	}
	else if (max_link > actual_length)
	{
		while (space_nbr--)
			ft_putchar(' ');
		ft_putstr("  ");
		ft_putnbr(stats.st_nlink);
	}
}

void				date(t_stat stats)
{
	char	**date;
	char	**date_f;
	time_t	t;

	date = ft_strsplit(ctime(&stats.st_mtime), ' ');
	ft_putchar(' ');
	ft_putstr_space(date[1], 1);
	display_date_right(date);
	ft_putchar(' ');
	date_f = ft_strsplit(date[3], ':');
	if (time(&t) - stats.st_mtime > 15778800 || stats.st_mtime > t )
	{
		ft_putchar(' ');
		ft_putstr(date[4]);
	}
	else
	{
		ft_putstr(date_f[0]);
		ft_putchar(':');
		ft_putstr_space(date_f[1], 1);
	}
	ft_free_tab(date);
	ft_free_tab(date_f);
}
