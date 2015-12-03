/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 17:31:39 by yalaouf           #+#    #+#             */
/*   Updated: 2015/06/02 20:14:41 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	count_digits(int n)
{
	size_t count;

	count = 1;
	while (n /= 10)
		count++;
	return (count);
}

char		*ft_itoa(int n)
{
	char			*s;
	size_t			len;
	unsigned int	nbr;

	len = count_digits(n);
	nbr = n;
	if (n < 0)
	{
		nbr = -n;
		len++;
	}
	if (!(s = ft_strnew(len)))
		return (NULL);
	s[--len] = nbr % 10 + 48;
	while (nbr /= 10)
		s[--len] = nbr % 10 + 48;
	if (n < 0)
		s[0] = '-';
	return (s);
}
