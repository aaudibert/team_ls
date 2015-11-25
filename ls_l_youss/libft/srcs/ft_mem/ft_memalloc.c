/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 17:31:51 by yalaouf           #+#    #+#             */
/*   Updated: 2015/06/02 20:16:35 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void *ft_memalloc(size_t size)
{
	char *str;

	if (size == 0)
		return (NULL);
	str = (char *)malloc(sizeof(*str) * size);
	if (!str)
		return (NULL);
	ft_memset(str, 0, size);
	return ((void *)str);
}
