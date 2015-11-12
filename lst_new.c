/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 12:06:53 by aaudiber          #+#    #+#             */
/*   Updated: 2015/11/12 16:26:33 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*lst_new(char *f_name, char *path)
{
	t_file *new_link;

	new_link = (t_file*)malloc(sizeof(t_file));
	new_link->path = path;
	new_link->f_name = f_name;
	new_link->stat = malloc(sizeof(stat));
	lstat(path, new_link->stat);
	new_link->prev = NULL;
	new_link->next = NULL;
	return (new_link);
}
