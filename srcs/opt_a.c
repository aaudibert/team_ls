/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 20:31:05 by aaudiber          #+#    #+#             */
/*   Updated: 2016/05/01 19:40:29 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		*g_flags;

int		opt_a(t_file *dir)
{
	if (g_flags[FLAG_AA] == 1 && ft_strcmp(dir->f_name, ".") &&
				ft_strcmp(dir->f_name, ".."))
		return (1);
	else if (g_flags[FLAG_A] == 1 && dir->f_name[0] == '.')
		return (1);
	else if (dir->f_name[0] != '.')
		return (1);
	return (0);
}
