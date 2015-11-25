/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 14:23:50 by yalaouf           #+#    #+#             */
/*   Updated: 2015/06/02 20:18:46 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void ft_putstr_fd(char const *s, int fd)
{
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s = (s + 1);
	}
}
