/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 23:50:24 by smbaabu           #+#    #+#             */
/*   Updated: 2018/09/04 23:51:16 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	insert(t_list **begin_list, t_list *elem, t_list *prev, t_list *list)
{
	if (prev)
		prev->next = elem;
	else
		*begin_list = elem;
	elem->next = list;
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *elem;
	t_list *list;
	t_list *prev;

	elem = ft_create_elem(data);
	list = *begin_list;
	prev = NULL;
	if (list)
		while (list)
		{
			if ((*cmp)(list->data, elem->data) >= 0)
			{
				insert(begin_list, elem, prev, list);
				break ;
			}
			else if ((*cmp)(list->data, elem->data) < 0 && list->next == NULL)
			{
				list->next = elem;
				break ;
			}
			prev = list;
			list = list->next;
		}
	else
		*begin_list = elem;
}
