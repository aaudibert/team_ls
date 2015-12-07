/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:38:02 by aaudiber          #+#    #+#             */
/*   Updated: 2015/05/07 21:52:13 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char				*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	size_t			len;
	char			*ret;

	i = 0;
	len = ft_strlen(s) - 1;
	if (!s)
		return (NULL);
	if (s[0] != ' ' && s[0] != '\t' && s[0] != '\n' && s[len] != ' ' &&
			s[len] != '\t' && s[len] != '\n')
		return (ft_strdup(s));
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return ("");
	j = i;
	i = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && i > 0)
		i--;
	ret = (ft_strsub(s, j, i - j + 1));
	return (ret);
}
