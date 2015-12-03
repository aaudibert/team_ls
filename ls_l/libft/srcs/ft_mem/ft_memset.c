/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 17:09:28 by yalaouf           #+#    #+#             */
/*   Updated: 2015/11/25 20:39:22 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *s;

	if (len == 0)
		return (b);
	s = (unsigned char *)b;
	while (len--)
	{
		*s = (unsigned char)c;
		if (len)
			s++;
	}
	return (b);
}
