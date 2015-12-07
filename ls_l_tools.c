/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_l_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:05:18 by yalaouf           #+#    #+#             */
/*   Updated: 2015/11/23 17:05:21 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putstr_space(char *str, int nbr_sp)
{
	ft_putstr(str);
	while (nbr_sp--)
		ft_putchar(' ');
}

void	display_date_right(char **tab)
{
	if (ft_strlen(tab[2]) == 1)
	{
		ft_putchar(' ');
		ft_putstr(tab[2]);
	}
	else
		ft_putstr(tab[2]);
}

void	total_block(t_file *dir)
{
	DIR				*rep;
	struct dirent	*lecture;
	int				total;
	struct stat		stats;

	total = 0;
	rep = opendir(ft_strjoin(dir->path, dir->f_name));
	while ((lecture = readdir(rep)) != NULL)
	{
		if (ft_strncmp(lecture->d_name, ".", 1) != 0)
		{
			lstat(lecture->d_name, &stats);
			total = total + stats.st_blocks;
		}
	}
	ft_putstr_space("total", 1);
	ft_putnbr(total);
	ft_putchar('\n');
}

void	affect(struct stat stats)
{
	struct passwd	*uid;
	struct group	*gid;

	uid = getpwuid(stats.st_uid);
	gid = getgrgid(stats.st_gid);
	ft_putstr_space(uid->pw_name, 2);
	ft_putstr_space(gid->gr_name, 2);
}

void	ifslnk(struct stat stats, struct dirent *lecture)
{
	char		*link;

	if (S_ISLNK(stats.st_mode))
	{
		link = malloc(stats.st_size + 1);
		readlink(lecture->d_name, link, stats.st_mode + 1);
		ft_putstr_space(lecture->d_name, 1);
		ft_putstr_space("->", 1);
		ft_putendl(link);
	}
	else
		ft_putendl(lecture->d_name);
}
