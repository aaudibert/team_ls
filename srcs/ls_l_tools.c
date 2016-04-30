/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_l_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:05:18 by yalaouf           #+#    #+#             */
/*   Updated: 2016/04/30 18:48:56 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_putstr_space(char *str, int nbr_sp)
{
	if (str)
		ft_putstr(str);
	while (nbr_sp--)
		ft_putchar(' ');
}

void	total_block(t_file *dir, t_stat *st)
{
	int total;
	int i;

	total = 0;
	i = 0;
	if (!no_permx(dir, st) || !no_perm(dir))
		return ;
	while (dir != NULL)
	{
		if (opt_a(dir))
		{
			total = total + dir->stat->st_blocks;
			i++;
		}
		dir = dir->next;
	}
	if (i != 0)
	{
		ft_putstr_space("total", 1);
		ft_putnbr(total);
	}
	ft_putchar('\n');
}

void	affect(t_stat stats, t_align *max_all)
{
	struct passwd	*uid;
	struct group	*gid;

	ft_putchar(' ');
	uid = getpwuid(stats.st_uid);
	gid = getgrgid(stats.st_gid);
	if (uid != NULL)
		ft_putstr_space(uid->pw_name, (max_all->usr -
				ft_strlen(uid->pw_name) + 2));
	else if (uid == NULL)
	{
		ft_putstr_space(NULL, (max_all->usr - ft_intlen(stats.st_uid)));
		ft_putnbr(stats.st_uid);
		ft_putstr("  ");
	}
	if (gid != NULL)
		ft_putstr_space(gid->gr_name, (max_all->grp -
					ft_strlen(gid->gr_name) + 2));
	else
	{
		ft_putnbr(stats.st_uid);
		ft_putstr_space(NULL, (max_all->grp - ft_intlen(stats.st_uid) + 2));
	}
}

void	print_fname(t_file *dir)
{
	if (g_flags[FLAG_GG] == 1)
	{
		if (S_ISDIR(dir->stat->st_mode))
			ft_putendl_color(dir->f_name, BCYAN);
		else if (dir->stat->st_mode & S_IXUSR)
			ft_putendl_color(dir->f_name, RED);
		else
			ft_putendl(dir->f_name);
	}
	else
		ft_putendl(dir->f_name);
}

void	ifslnk(t_stat stats, t_file *dir, int file)
{
	char *link;
	char *tmp;

	if (S_ISLNK(stats.st_mode))
	{
		link = (char *)malloc(sizeof(char) * (stats.st_mode + 1));
		if (file == 1)
			tmp = ft_strdup(dir->f_name);
		else
			tmp = ft_strjoin(dir->path, dir->f_name);
		if (g_flags[FLAG_GG] == 1)
			ft_putstr_color(dir->f_name, MAGENTA);
		else
			ft_putstr(dir->f_name);
		ft_putstr(" -> ");
		if (readlink(tmp, link, stats.st_mode + 1) != -1)
		{
			link[stats.st_mode + 1] = 0;
			ft_putendl(link);
		}
		free(link);
		free(tmp);
	}
	else
		print_fname(dir);
}
