/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 17:39:23 by yalaouf           #+#    #+#             */
/*   Updated: 2015/11/25 20:44:07 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strnew(size_t size)
{
	void *str;

	str = (void *)ft_memalloc(size + 1);
	if (str == NULL)
		return ((char *)NULL);
	else
		return ((char *)str);
}
