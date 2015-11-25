/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 20:49:20 by yalaouf           #+#    #+#             */
/*   Updated: 2015/06/02 20:21:37 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	tmp;

	length = 0;
	while (str[length] != '\0')
		length++;
	i = -1;
	while (++i < length--)
	{
		tmp = str[i];
		str[i] = str[length];
		str[length] = tmp;
	}
	return (str);
}
