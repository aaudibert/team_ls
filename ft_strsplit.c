/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:26:49 by aaudiber          #+#    #+#             */
/*   Updated: 2016/01/28 15:44:49 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		word_count(char *s, char c)
{
	int i;
	int wc;

	i = 0;
	wc = 0;
	while (s[i] != '\0')
	{
		if (s[i + 1] == c || s[i + 1] == '\0')
			wc++;
		i++;
	}
	return (wc);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;
	int		w;

	i = 0;
	j = 0;
	w = 0;
	if ((ret = (char **)malloc(sizeof(char *) * word_count(s, c) + 1)) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			ret[w][j] = s[i];
			i++;
			j++;
		}
		j = 0;
		w++;
	}
	ret[w] = '\0';
	return (ret);
}
