/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 19:12:15 by aaudiber          #+#    #+#             */
/*   Updated: 2016/02/16 17:21:09 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_word_count(char const *s, char c)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			ret++;
		i++;
	}
	return (ret);
}

char			*ft_strndup(char const *s, int start, int len)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * len);
	ret[len] = 0;
	while (i < len)
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	return (ret);
}

int				len_c(char const *s, char c, int start)
{
	int i;

	i = 0;
	while (s[start] != '\0' && s[start] != c)
	{
		start++;
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		wc;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	wc = ft_word_count(s, c);
	if ((ret = (char**)malloc(sizeof(char*) * (wc + 1))) == NULL)
		return (NULL);
	ret[wc] = 0;
	wc = -1;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		ret[++wc] = ft_strndup(s, i, len_c(s, c, i));
		i += len_c(s, c, i);
	}
	return (ret);
}
