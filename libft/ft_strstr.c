/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:49:38 by aaudiber          #+#    #+#             */
/*   Updated: 2014/11/08 12:05:24 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int k;

	i = 0;
	k = ft_strlen((char*)s2);
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[0])
		{
			if (ft_strncmp(s1 + i, s2, k) == 0)
				return ((char*)s1 + i);
		}
		i++;
	}
	return (NULL);
}
