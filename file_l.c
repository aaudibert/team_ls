/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:34:25 by aaudiber          #+#    #+#             */
/*   Updated: 2016/01/26 19:13:37 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_path(char *s)
{
	int		i;
	int		j;
	char	*ret;
;

	i = ft_strlen(s);
	j = 0;
	while (s[i] != '/' && i >= 0)
		i--;
	i++;
	if (i > 0)
	{
		ret = (char *)malloc(sizeof(char) * i + 1);
		while (j < i)
		{
			ret[j] = s[j];
			j++;
		}
		ret[j] = '\0';
	}
	else
		ret = "./";
	return (ret);
}

t_file		*file_l(char **file)
{
	int		i;
	t_file	*dir;

	i = 0;
	dir = lst_new(NULL, ".");
	while (file[i])
	{
		lst_push(lst_new(file[i], get_path(file[i])), &dir);
		i++;
	}
	while (dir->next->next != NULL)
		dir = dir->next;
	dir->next = NULL;
	dir = rewind_lst(dir);
	free(file);
	return (dir);
}
