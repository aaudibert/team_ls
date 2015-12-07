/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:48:32 by aaudiber          #+#    #+#             */
/*   Updated: 2014/11/27 20:02:28 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	b;

	b = c;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != b && s[i] != '\0')
		i++;
	if (s[i] == b)
		return ((char*)s + i);
	return (NULL);
}
