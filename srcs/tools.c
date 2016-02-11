/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 18:18:39 by yalaouf           #+#    #+#             */
/*   Updated: 2016/02/04 14:52:07 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int					ft_intlen(int nbr)
{
	int	len;

	len = 0;
	while (len > 9)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

unsigned int		*max(t_file *dir)
{
	static unsigned int *max_all = 0;

	max_all = malloc(200);
	while (dir != NULL)
	{
		if (opt_a(dir))
		{
			if (dir->stat->st_size > max_all[0])
				max_all[0] = dir->stat->st_size;
			if (dir->stat->st_nlink > max_all[1])
				max_all[1] = dir->stat->st_nlink;
		}
		dir = dir->next;
	}
	return (max_all);
}

void				display_size_right(int max_size, struct stat stats)
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

void				display_link_right(int max_link, struct stat stats)
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

void				date(struct stat stats)
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
