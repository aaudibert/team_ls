/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 17:37:39 by yalaouf           #+#    #+#             */
/*   Updated: 2015/11/25 20:42:43 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		n;
	int		i;
	char	*dst;

	if (s1 == NULL && s2 == NULL)
		return ((char *)NULL);
	if (s1 == NULL && s2)
		return (ft_strdup(s2));
	if (s1 && s2 == NULL)
		return (ft_strdup(s1));
	i = 0;
	len = ft_strlen(s1);
	n = len + ft_strlen(s2) + 1;
	if (!(dst = ft_strnew(n)))
		return (NULL);
	while (i < n)
	{
		if (i < len)
			dst[i] = s1[i];
		else
			dst[i] = s2[i - len];
		i++;
	}
	return (dst);
}
