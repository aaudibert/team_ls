/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 17:15:30 by aaudiber          #+#    #+#             */
/*   Updated: 2015/11/06 16:42:16 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*g_flags;

int		main(int ac, char **av)
{
	int i;

	i = 1;
	g_flags = (int *)malloc(sizeof(int) * 5);
	ft_bzero(g_flags, sizeof(int) * 5);
	if (parser(ac, av) == (ac - 1))
		get_data(".");
	return (0);
}
