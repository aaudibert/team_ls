/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 15:47:09 by yalaouf           #+#    #+#             */
/*   Updated: 2015/06/02 20:19:19 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char *ft_strchr(const char *s, int c)
{
	char *tmp;

	tmp = (char *)s;
	while (*tmp != c && *tmp)
		tmp++;
	if (*tmp != c)
		return (NULL);
	return (tmp);
}