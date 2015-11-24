/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:54:47 by rlechapt          #+#    #+#             */
/*   Updated: 2015/11/24 17:44:44 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_dir(t_file *dir)
{
	char	*tmp;
	while (dir->next)
	{
		if (ft_strcmp(dir->f_name, dir->next->f_name) > 0)
		{
			tmp = dir->f_name;
			dir->f_name = dir->next->f_name;
			dir->next->f_name = tmp;
			dir = rewind_lst(dir);
		}
		else
			dir = dir->next;
	}
}

void	sort_params(char **tab)
{
	int	i;
	char *tmp;

	i = 0;
	while (tab[i + 1])
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
