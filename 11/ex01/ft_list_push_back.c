/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:21:54 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/26 00:27:43 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*p;

	if (*begin_list)
	{
		p = *begin_list;
		while (p->next)
			p = p->next;
		p->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}
