/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 18:18:39 by yalaouf           #+#    #+#             */
/*   Updated: 2016/04/30 18:43:45 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_align				*max(t_file *dir, int file, t_stat *st)
{
	t_align	*max_all;

	max_all = (t_align*)malloc(sizeof(t_align));
	max_all->link = 0;
	max_all->usr = 0;
	max_all->grp = 0;
	max_all->size = 0;
	max_all->minor = 0;
	max_all->major = 0;
	while (dir != NULL)
	{
		if (file == 1 || (opt_a(dir) && st->st_mode & S_IXUSR))
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

void				display_link_right(t_file *dir, t_align *mx)
{
	int actual_length;
	int space_nbr;

	actual_length = ft_intlen(dir->stat->st_nlink);
	space_nbr = mx->link - actual_length;
	if (mx->link == actual_length)
	{
		ft_putstr("  ");
		ft_putnbr(dir->stat->st_nlink);
	}
	else if (mx->link > actual_length)
	{
		while (space_nbr--)
			ft_putchar(' ');
		ft_putstr("  ");
		ft_putnbr(dir->stat->st_nlink);
	}
	affect(*(dir->stat), mx);
}

void				display_date_right(char **tab)
{
	if (ft_strlen(tab[2]) == 1)
	{
		ft_putchar(' ');
		ft_putstr(tab[2]);
	}
	else
		ft_putstr(tab[2]);
}

void				date(t_file *dir, t_stat stats, int file)
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
	if (time(&t) - stats.st_mtime > 15778800 || stats.st_mtime > t)
	{
		ft_putchar(' ');
		print_length(date[4], 4);
		ft_putchar(' ');
	}
	else
	{
		ft_putstr(date_f[0]);
		ft_putchar(':');
		ft_putstr_space(date_f[1], 1);
	}
	ft_free_tab(date);
	ft_free_tab(date_f);
	ifslnk(*(dir->stat), dir, file);
}
