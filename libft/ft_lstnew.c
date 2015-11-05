/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 11:04:02 by aaudiber          #+#    #+#             */
/*   Updated: 2015/05/11 18:31:40 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *data;

	if ((data = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (!content)
	{
		data->content = NULL;
		data->content_size = 0;
		data->next = NULL;
		return (data);
	}
	data->next = NULL;
	data->content_size = content_size;
	data->content = (void *)content;
	return (data);
}
