/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 18:18:39 by yalaouf           #+#    #+#             */
/*   Updated: 2015/11/24 16:50:24 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*max(t_file *dir)
{
	DIR				*rep;
	struct dirent	*lecture;
	static unsigned int		*max_all = 0;
	struct stat		stats;

	max_all = malloc(200);
	rep = opendir(ft_strjoin(dir->path, dir->f_name));
	while ((lecture = readdir(rep)) != NULL)
	{
		if (ft_strncmp(lecture->d_name, ".", 1) != 0)
		{
			stat(lecture->d_name, &stats);
			if (stats.st_size > max_all[0])
				max_all[0] = stats.st_size;
			if (stats.st_nlink > max_all[1])
				max_all[1] = stats.st_nlink;
		}
	}
	closedir(rep);
	return (max_all);
}

void	display_size_right(int max_size, struct stat stats)
{
	int		max_length;
	int		actual_length;
	int		space_nbr;

	(unsigned int)max_length = ft_intlen(max_size);
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

void	display_link_right(int max_link, struct stat stats)
{
	int		max_length;
	int		actual_length;
	int		space_nbr;

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

void	date(struct stat stats)
{
	char	**date;
	char	**date_f;

	date = ft_strsplit(ctime(&stats.st_mtime), ' ');
	ft_putchar(' ');
	ft_putstr_space(date[1], 1);
	display_date_right(date);
	ft_putchar(' ');
	date_f = ft_strsplit(date[3], ':');
	ft_putstr(date_f[0]);
	ft_putchar(':');
	ft_putstr_space(date_f[1], 1);
}
