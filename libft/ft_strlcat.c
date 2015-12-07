/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 14:47:54 by aaudiber          #+#    #+#             */
/*   Updated: 2014/11/12 17:52:20 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t lend;
	size_t lens;

	i = 0;
	lend = (ft_strlen(dst));
	lens = (ft_strlen(src));
	if (lend > size)
		return (lens + size);
	while (src[i] != '\0' && lend + i + 1 < size)
	{
		dst[lend + i] = src[i];
		i++;
	}
	dst[lend + i] = '\0';
	return (lend + lens);
}
