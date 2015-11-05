/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:48:44 by aaudiber          #+#    #+#             */
/*   Updated: 2014/11/27 20:03:00 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	b;

	b = c;
	i = ft_strlen((char*)s);
	if (!s)
		return (NULL);
	while (s[i] != b && i > 0)
		--i;
	if (s[i] == b)
		return ((char*)s + i);
	return (NULL);
}
