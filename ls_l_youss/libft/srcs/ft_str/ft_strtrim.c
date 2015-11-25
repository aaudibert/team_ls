/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 17:40:23 by yalaouf           #+#    #+#             */
/*   Updated: 2015/06/02 20:22:10 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char *ft_strtrim(char const *s)
{
	char	*final;
	int		len;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	len = ft_strlen((char *)s);
	final = ft_strnew(len + 1);
	if (!final)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	while (i < len)
		final[j++] = s[i++];
	final[j] = '\0';
	return (final);
}
