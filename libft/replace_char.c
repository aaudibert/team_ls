/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 19:46:54 by aaudiber          #+#    #+#             */
/*   Updated: 2016/03/06 19:54:06 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*replace_char(char *s, char o, char r)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[i])
	{
		if (s[i] == o)
			ret[i] = r;
		else
			ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	free(s);
	return (ret);
}
