/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 19:09:19 by yalaouf           #+#    #+#             */
/*   Updated: 2015/11/25 20:44:59 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (s && *s != '\0')
	{
		if (s && *s != c && *s != '\0')
			count++;
		while (s && *s != c && *s != '\0')
			s++;
		s++;
	}
	return (count);
}

static size_t	ft_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char		**ft_tab_alloc(size_t count)
{
	char	**dst;

	dst = (char**)ft_memalloc(sizeof(char*) * (count + 1));
	if (dst == NULL)
		return (NULL);
	dst[0] = NULL;
	return (dst);
}

static void		ft_split(char **dst, char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	*word;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		len = ft_len(s, c);
		if (len != 0)
		{
			word = ft_strsub(s, 0, len);
			dst[i] = word;
			i++;
		}
		s += len;
		while (*s == c && *s != '\0')
			s++;
	}
	dst[i] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dst;
	size_t	count;

	if (s == NULL)
		return (NULL);
	count = ft_count(s, c);
	dst = ft_tab_alloc(count);
	if (dst == NULL)
		return (NULL);
	ft_split(dst, s, c);
	return (dst);
}
