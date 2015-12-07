/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:25:26 by aaudiber          #+#    #+#             */
/*   Updated: 2014/11/28 13:06:22 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void *ret;

	if ((ret = (void*)malloc(sizeof(void*) * size + 1)) == NULL)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
