/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <yalaouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 19:35:27 by yalaouf           #+#    #+#             */
/*   Updated: 2016/01/11 17:44:06 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_l(t_file *dir)
{
	struct dirent	*lecture;
	DIR				*rep;
	t_stat			*stats;
	unsigned int	*max_all;
	char			*tmp;

	total_block(dir);
	max_all = max(dir);
	stats = malloc(sizeof(t_stat));
	if ((rep = opendir(ft_strjoin(dir->path, dir->f_name))) != NULL)
	{
		while ((lecture = readdir(rep)) != NULL)
		{
			if (ft_strncmp(lecture->d_name, ".", 1) != 0)
			{
				tmp = ft_strjoin(dir->path,lecture->d_name);
				if (lstat(tmp, stats) != -1)
				{
					letters(*stats);
					display_link_right(max_all[1], *stats);
					ft_putchar(' ');
					affect(*stats);
					display_size_right(max_all[0], *stats);
					date(*stats);
					ifslnk(*stats, lecture, dir);
				}
				free(tmp);
				//implémenter les major/minor pour les device nodes
			}
		}
		closedir(rep);
		free(stats);
	}
}
