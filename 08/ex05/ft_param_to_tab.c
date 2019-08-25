/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 23:30:03 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 20:28:24 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char *s, *r;
	s = r = malloc((ft_strlen(src) + 1) * sizeof(char));
	while (*src)
		*s++ = *src++;
	*s = 0;
	return r;
}

t_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par *arr = malloc((ac + 1) * sizeof(t_stock_par));
	arr[ac].str = 0;
	for (size_t i = 0; i < ac; i++)
		arr[i] = (t_stock_par){ft_strlen(av[i]), av[i], ft_strdup(av[i]), ft_split_whitespaces(av[i])};
	return arr;
}
