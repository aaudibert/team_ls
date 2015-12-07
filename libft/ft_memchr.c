/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:43:56 by aaudiber          #+#    #+#             */
/*   Updated: 2014/11/27 12:48:20 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void		*ft_memchr(const void *s, int c, size_t n)
{
	if (!s)
		return (NULL);
	while (n != 0)
	{
		if (*((unsigned char*)s++) == (unsigned char)c)
			return ((void*)--s);
		n--;
	}
	return (NULL);
}
