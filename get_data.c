/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 15:29:30 by aaudiber          #+#    #+#             */
/*   Updated: 2015/11/06 17:22:24 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_data(char *path)
{
	DIR			*rep;
	t_dirent	*fr;
	t_file		*dir;

	rep = opendir(path);
	if (rep != NULL)
	{
		while ((fr = readdir(rep)) != NULL)
			lst_push(lst_new(ft_strdup(fr->d_name), path), &dir);
		closedir(rep);
	}
	else
		perror("");
}
