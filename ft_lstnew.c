/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:27:39 by jngoma            #+#    #+#             */
/*   Updated: 2017/07/21 13:46:24 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = NULL;
	if (content != NULL)
	{
		if (!(list = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		list->content = (void *)malloc(content_size);
		list->content = ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
		list->next = NULL;
	}
	else
	{
		if (!(list = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		list->content = NULL;
		list->content_size = 0;
		list->next = NULL;
	}
	return (list);
}
