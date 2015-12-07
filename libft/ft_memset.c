/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:38:44 by aaudiber          #+#    #+#             */
/*   Updated: 2014/11/12 17:26:00 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void		*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i != len)
	{
		(*((unsigned char*)b + i)) = (unsigned char)c;
		i++;
	}
	return (b);
}
