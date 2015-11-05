/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 20:52:45 by aaudiber          #+#    #+#             */
/*   Updated: 2015/05/11 21:02:27 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *top;
	t_list *new;

	if (!(new = f(lst)))
		return (NULL);
	top = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = f(lst)))
			return (NULL);
		lst = lst->next;
		new = new->next;
	}
	return (top);
}
