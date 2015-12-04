/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:47:32 by jumiguel          #+#    #+#             */
/*   Updated: 2015/12/04 18:23:32 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_dir(t_file *dir)
{
	char	*tmp;
	int		i;

	while (dir->next)
}

void	sort_dir(t_file *dir)
{
	char	*tmp;
	int		i;

	while (dir->next)
	{
		if (ft_strcmp(dir->f_name, dir->next->f_name) > 0)
		{
			tmp = dir->f_name;
			i = dir->izdir;
			dir->f_name = dir->next->f_name;
			dir->izdir = dir->next->izdir;
			dir->next->f_name = tmp;
			dir->next->izdir = i;
			dir = rewind_lst(dir);
		}
		else
			dir = dir->next;
	}
}
