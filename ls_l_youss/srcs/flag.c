/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <yalaouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 19:35:27 by yalaouf           #+#    #+#             */
/*   Updated: 2015/11/25 16:52:59 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

//void	ls_a(void)
//{
//	struct dirent	*lecture;
//	DIR				*rep;

//	rep = opendir(".");
//	while ((lecture = readdir(rep)) != NULL)
//		ft_putendl(lecture->d_name);
//	closedir(rep);
//}

//void	ls_1(void)
//{
//	struct dirent	*lecture;
//	DIR				*rep;

//	rep = opendir(".");
//	while ((lecture = readdir(rep)) != NULL)
//		if (ft_strncmp(lecture->d_name, ".", 1) != 0)
//			ft_putendl(lecture->d_name);
//	closedir(rep);
//}

void	ls_l(void)
{
	struct dirent	*lecture;
	DIR				*rep;
	struct stat		stats;
	int				*max_all;

	total_block();
	max_all = max();
	rep = opendir(".");
	while ((lecture = readdir(rep)) != NULL)
	{
		if (ft_strncmp(lecture->d_name, ".", 1) != 0)
		{
			lstat(lecture->d_name, &stats);
			letters(stats, lecture);
			display_link_right(max_all[1], stats);
			ft_putchar(' ');
			affect(stats, lecture);
			display_size_right(max_all[0], stats);
			date(stats);
			ifslnk(stats, lecture);
		}
	}
	closedir(rep);
}
