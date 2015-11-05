/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:43:42 by aaudiber          #+#    #+#             */
/*   Updated: 2014/11/12 17:27:15 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp;

	if (!dst || !src)
		return (NULL);
	temp = (unsigned char*)malloc(sizeof(unsigned char*) * len);
	ft_memcpy(temp, src, len);
	ft_memcpy(dst, temp, len);
	free(temp);
	return (dst);
}
