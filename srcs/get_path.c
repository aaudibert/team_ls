/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:34:25 by aaudiber          #+#    #+#             */
/*   Updated: 2016/01/28 20:49:04 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char		*get_file(char *s)
{
	int		i;
	int		j;
	char	*ret;

	i = ft_strlen(s);
	j = 0;
	while (s[i] != '/' && i >= 0)
		i--;
	i++;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	while (s[i] != '\0')
	{
		ret[j] = s[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char		*get_path(char *s)
{
	int		i;
	int		j;
	char	*ret;

	i = ft_strlen(s);
	j = 0;
	while (s[i] != '/' && i >= 0)
		i--;
	i++;
	if (i > 0)
	{
		ret = (char *)malloc(sizeof(char) * i + 1);
		while (j < i)
		{
			ret[j] = s[j];
			j++;
		}
		ret[j] = '\0';
	}
	else
		ret = "./";
	return (ret);
}
