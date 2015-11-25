/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 17:30:13 by yalaouf           #+#    #+#             */
/*   Updated: 2015/06/02 20:14:30 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int ft_atoi(const char *str)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (*str && ft_isspace((int)*str))
		str++;
	if (*str && *str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str && *str == '+')
		str++;
	while (*str && ft_isdigit((int)*str))
	{
		if ((nbr > (9223372036854775807 - (*str - '0')) / 10) && (sign == -1))
			return (0);
		if ((nbr > (9223372036854775806 - (*str - '0')) / 10) && (sign == 1))
			return (-1);
		nbr = nbr * 10 + *str++ - '0';
	}
	return ((int)(sign * nbr));
}
