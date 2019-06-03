/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:59:27 by smbaabu           #+#    #+#             */
/*   Updated: 2018/09/04 15:43:21 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	t_list	*p;
	t_list	*elem;

	list = ft_create_elem(av[--ac]);
	p = list;
	while (--ac >= 0)
	{
		elem = ft_create_elem(av[ac]);
		list->next = elem;
		list = elem;
	}
	return (p);
}
