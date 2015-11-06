/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 15:29:30 by aaudiber          #+#    #+#             */
/*   Updated: 2015/11/06 19:35:07 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_data(char *path)
{
	DIR			*rep;
	t_dirent	*fr;
	t_file		*dir;

	dir = NULL;
	rep = opendir(path);
	ft_putendl("get data");
	if (rep != NULL)
	{
		ft_putendl("gd dbt while");
		while ((fr = readdir(rep)) != NULL)
			lst_push(lst_new(ft_strdup(fr->d_name), path), &dir);
		ft_putendl("post data");
		closedir(rep);
		ft_putendl("fin while");
	}
	else
		perror("");
	ft_putendl("fin data");
	print_dir(dir);
}
