/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:43:09 by aaudiber          #+#    #+#             */
/*   Updated: 2015/05/11 18:12:11 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src2;
	unsigned char	*dst2;

	i = 0;
	if (!dst || !src)
		return (NULL);
	src2 = (unsigned char*)src;
	dst2 = (unsigned char*)dst;
	while (i != n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}
