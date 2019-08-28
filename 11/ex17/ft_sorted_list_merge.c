/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 23:54:58 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/26 13:49:59 by smbaabu          ###   ########.fr       */
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
			if ((*cmp)(list->data, elem->data) > 0)
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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
	int (*cmp)())
{
	if (*begin_list1)
	{
		while (begin_list2)
		{
			ft_sorted_list_insert(begin_list1, begin_list2->data, cmp);
			begin_list2 = begin_list2->next;
		}
	}
	else
		*begin_list1 = begin_list2;
}
