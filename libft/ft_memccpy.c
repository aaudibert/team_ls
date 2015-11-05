/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:43:29 by aaudiber          #+#    #+#             */
/*   Updated: 2014/11/12 17:27:03 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;
	unsigned char	*d2;

	i = 0;
	s2 = (unsigned char*)src;
	d2 = (unsigned char*)dst;
	if (!s2 || !d2)
		return (NULL);
	while (i < n)
	{
		d2[i] = s2[i];
		if (s2[i++] == (unsigned char)c)
			return (dst + i);
	}
	return (NULL);
}
