/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 23:50:38 by yalaouf           #+#    #+#             */
/*   Updated: 2015/06/02 20:15:59 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!(alst && new))
		return ;
	if (*alst)
		new->next = *alst;
	*alst = new;
}