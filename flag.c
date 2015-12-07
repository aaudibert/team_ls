/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <yalaouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 19:35:27 by yalaouf           #+#    #+#             */
/*   Updated: 2015/11/26 19:47:33 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_l(t_file *dir)
{
	struct dirent	*lecture;
	DIR				*rep;
	struct stat		stats;
	int				*max_all;

	total_block(dir);
	max_all = max(dir);
	rep = opendir(ft_strjoin(dir->path, dir->f_name));
	while ((lecture = readdir(rep)) != NULL)
	{
		if (ft_strncmp(lecture->d_name, ".", 1) != 0)
		{
			lstat(lecture->d_name, &stats);
			letters(stats);
			display_link_right(max_all[1], stats);
			ft_putchar(' ');
			affect(stats);
			display_size_right(max_all[0], stats);
			date(stats);
			ifslnk(stats, lecture);
			//implémenter les major/minor pour les device nodes
		}
	}
	closedir(rep);
}
