/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:47:56 by aaudiber          #+#    #+#             */
/*   Updated: 2014/11/15 13:59:09 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != 0 && j < n)
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = 0;
	return (s1);
}
