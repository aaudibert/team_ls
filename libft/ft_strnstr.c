/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:49:47 by aaudiber          #+#    #+#             */
/*   Updated: 2015/05/02 20:32:27 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (s2[j] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0' && i < (int)n)
	{
		if (s1[i] == s2[j])
		{
			j = 0;
			while (s2[j] == s1[i + j] && s2[j] != '\0' && n - (j + i) > 0)
				j++;
			if (s2[j] == '\0')
				return ((char*)s1 + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
