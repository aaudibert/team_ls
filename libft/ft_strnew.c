/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:20:35 by aaudiber          #+#    #+#             */
/*   Updated: 2014/11/28 13:07:38 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	char	*str;

	if ((str = (char*)malloc(sizeof(char*) * size + 1)) == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
