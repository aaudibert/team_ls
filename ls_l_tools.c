/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_l_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:05:18 by yalaouf           #+#    #+#             */
/*   Updated: 2016/01/11 17:39:07 by psaint-j         ###   ########.fr       */
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
	char			*tmp;

	total = 0;
	if ((rep = opendir(ft_strjoin(dir->path, dir->f_name))) != NULL)
	{
	while ((lecture = readdir(rep)) != NULL)
	{
		if (ft_strncmp(lecture->d_name, ".", 1) != 0)
		{
			tmp = ft_strjoin(dir->path,lecture->d_name);
			if (lstat(ft_strjoin(dir->path,lecture->d_name), &stats) != -1)
			total = total + stats.st_blocks;
			free(tmp);
		}
	}
	closedir(rep);
	ft_putstr_space("total", 1);
	ft_putnbr(total);
	ft_putchar('\n');
	}
}

void	affect(struct stat stats)
{
	struct passwd	*uid;
	struct group	*gid;

	uid = getpwuid(stats.st_uid);
	gid = getgrgid(stats.st_gid);
	if (uid != NULL)
	ft_putstr_space(uid->pw_name, 2);
	if (gid != NULL)
	ft_putstr_space(gid->gr_name, 2);
}

void	ifslnk(struct stat stats, struct dirent *lecture, t_file *dir)
{
	char		*link;

	if (S_ISLNK(stats.st_mode))
	{
		link = malloc(stats.st_size + 1);
		ft_putstr_space(lecture->d_name, 1);
		ft_putstr_space("->", 1);
		if (readlink(ft_strjoin(dir->path,lecture->d_name), link, stats.st_mode + 1) != -1)
		ft_putendl(link);
	}
	else
		ft_putendl(lecture->d_name);
}
