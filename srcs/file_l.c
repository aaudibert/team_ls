/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:59:12 by aaudiber          #+#    #+#             */
/*   Updated: 2016/05/01 19:28:38 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_file		*file_l(char **file)
{
	int		i;
	t_file	*dir;

	i = 0;
	dir = lst_new(get_file(file[0]), get_path(file[0]), 1);
	while (file[i])
	{
		if (file[i][0] == '.' && file[i][1] == '/')
			lst_push(lst_new(file[i], "./", 0), &dir);
		else
			lst_push(lst_new(get_file(file[i]), get_path(file[i]), 1), &dir);
		i++;
	}
	while (dir->next->next != NULL)
		dir = dir->next;
	dir->next = NULL;
	dir = rewind_lst(dir);
	free(file);
	return (dir);
}

t_file		*dir_l(char **file)
{
	int		i;
	t_file	*dir;

	i = 0;
	dir = lst_new(get_file(file[0]), get_path(file[0]), 1);
	while (file[i])
	{
		lst_push(lst_new(file[i], file[i], 2), &dir);
		i++;
	}
	while (dir->next->next != NULL)
		dir = dir->next;
	dir->next = NULL;
	dir = rewind_lst(dir);
	free(file);
	return (dir);
}
