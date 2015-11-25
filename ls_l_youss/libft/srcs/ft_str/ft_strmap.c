/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 17:38:21 by yalaouf           #+#    #+#             */
/*   Updated: 2015/06/02 20:20:34 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	int		i;
	char	*str;

	if (s == NULL)
		return (NULL);
	if (f == NULL)
		return (ft_strdup(s));
	len = ft_strlen(s);
	str = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		str[i] = (*f)(s[i]);
		i++;
	}
	return (str);
}
