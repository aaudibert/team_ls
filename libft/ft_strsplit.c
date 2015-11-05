/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 19:12:15 by aaudiber          #+#    #+#             */
/*   Updated: 2015/03/12 17:42:51 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_strgetndup(char **s, char c)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while ((*s)[i] != c && (*s)[i] != '\0')
	{
		i++;
	}
	if ((ret = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	while (i > 0)
	{
		ret[j] = **s;
		(*s)++;
		j++;
		i--;
	}
	return (ret);
}

static void		ft_skipc(const char **s, char c)
{
	while (**s == c)
		(*s)++;
}

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
	while (s != '\0')
	{
		ft_skipc(&s, c);
		if (*s == '\0')
			break ;
		ret[i] = ft_strgetndup((char**)&s, c);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
