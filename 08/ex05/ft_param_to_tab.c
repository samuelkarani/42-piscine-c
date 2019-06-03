/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 23:30:03 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/31 23:31:40 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char *p;

	p = dest;
	while (n)
	{
		if (*src != '\0')
			*dest++ = *src++;
		else
			*dest++ = '\0';
		n--;
	}
	return (p);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int i;
	int l;
	char **args_split;
	char *s;
	t_stock_par last;
	t_stock_par args_struct[ac + 1];

	args_split = ft_split_whitespaces(args_split);
	i = 0;
	while ((s = args_split[i]) != NULL)
	{
		l = ft_strlen(s);
		t_stock_par item;
		item.size_param = l;
		item.str = s;
		item.copy = ft_strncpy((char *)malloc(sizeof(char) * (l + 1)), s, l);
		item.tab = args_split;
		i++;
	}
	last.str = NULL;
	args_struct[i] = last;
	return &args_struct;
}
