/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 18:57:48 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/18 17:28:02 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_arr(char **array)
{
	int i;

	i = 0;
	if (!array)
		return (1);
	while (array[i])
	{
		ft_putendl(array[i]);
		i++;
	}
	return (0);
}
