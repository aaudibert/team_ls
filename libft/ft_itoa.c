/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 17:23:31 by aaudiber          #+#    #+#             */
/*   Updated: 2014/11/28 14:27:15 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_intlen(int n)
{
	int i;
	int len;

	len = 1;
	i = 10;
	while (i <= n && i <= 1000000000)
	{
		len++;
		i = i * 10;
	}
	return (len);
}

static int		ft_intlenneg(int n)
{
	int i;
	int len;

	len = 1;
	i = -10;
	while (i >= n && i >= -1000000000)
	{
		i = i * 10;
		len++;
	}
	return (len + 1);
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		len;

	if (n == -2147483648)
		return (ret = "-2147483648");
	if (n >= 0)
		len = ft_intlen(n);
	if (n < 0)
		len = ft_intlenneg(n);
	if ((ret = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	len--;
	if (n < 0)
	{
		ret[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{
		ret[len] = ((n % 10) + 48);
		n = n / 10;
		len--;
	}
	ret[len] = (n + 48);
	return (ret);
}
