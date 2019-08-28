/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 23:54:04 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/26 13:40:28 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

int		ft_get_size(t_list *begin_list)
{
	int		i;
	t_list	*list;

	i = 0;
	list = begin_list;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void	ft_swap(void **a, void **b)
{
	void *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*list;

	list = begin_list;
	while (list && nbr > 0)
	{
		list = list->next;
		nbr--;
	}
	return (nbr == 0 ? list : NULL);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		l;
	t_list	*list;

	l = ft_get_size(begin_list) - 1;
	list = begin_list;
	i = 0;
	while (i < l)
	{
		ft_swap(&((ft_list_at(list, i))->data), &((ft_list_at(list, l))->data));
		i++;
		l--;
	}
}
