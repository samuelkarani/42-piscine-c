/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:43:53 by smbaabu           #+#    #+#             */
/*   Updated: 2018/09/05 14:33:38 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*list;
	t_list	*prev;
	t_list	*next;

	list = *begin_list;
	prev = NULL;
	while (list)
	{
		next = list->next;
		list->next = prev;
		prev = list;
		list = next;
	}
	*begin_list = prev;
}
