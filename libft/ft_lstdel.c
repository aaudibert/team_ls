/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 18:33:01 by aaudiber          #+#    #+#             */
/*   Updated: 2015/05/11 21:04:30 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	tmp = *alst;
	if (!alst)
		return ;
	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		*alst = (*alst)->next;
		free(*alst);
	}
	tmp = NULL;
}
