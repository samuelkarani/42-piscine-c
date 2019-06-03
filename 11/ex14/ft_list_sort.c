/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 00:03:37 by smbaabu           #+#    #+#             */
/*   Updated: 2018/09/05 18:04:17 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap(void **a, void **b)
{
	void *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *list_i;
	t_list *list_j;

	if (*begin_list)
	{
		list_i = *begin_list;
		while (list_i->next)
		{
			list_j = *begin_list;
			while (list_j->next)
			{
				if ((*cmp)(list_j->data, list_j->next->data) > 0)
					ft_swap(&(list_j->data), &(list_j->next->data));
				list_j = list_j->next;
			}
			list_i = list_i->next;
		}
	}
}
