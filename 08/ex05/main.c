/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:48:38 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 20:27:53 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <stdio.h>

int main(int ac, char *av[])
{
	t_stock_par *res, c;

	res = ft_param_to_tab(ac, av);
	for (size_t i = 0; i < ac; i++)
	{
		c = res[i];
		printf("%2d %10s %p = %p %10s %p ", c.size_param, c.str, c.str, av[i], c.copy, c.copy);
		for (size_t j = 0; c.tab[j]; j++)
			printf("%8s ", c.tab[j]);
		printf("\n");
	}
	if (res[ac].str)
		printf("no null terminator");
	return 0;
}