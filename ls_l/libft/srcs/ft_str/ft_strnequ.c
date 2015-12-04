/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 17:39:12 by yalaouf           #+#    #+#             */
/*   Updated: 2015/11/25 20:43:58 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		eq;

	eq = (ft_strncmp(s1, s2, n) == 0 ? 1 : 0);
	return (eq);
}