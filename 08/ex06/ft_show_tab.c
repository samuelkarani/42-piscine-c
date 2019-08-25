/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 20:27:30 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 20:39:23 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_stock_par.h"

void ft_show_tab(struct s_stock_par *par)
{
	struct s_stock_par c;
	size_t i = 0;
	while (1)
	{
		c = par[i];
		if (!c.str)
			break ;
		if (i > 0)
			printf("\n");
		printf("%s\n%d\n", c.str, c.size_param);
		for (size_t j = 0; c.tab[j]; j++)
			printf("%s\n", c.tab[j]);
		i++;
	}
}

int main(int ac, char **av)
{
	ft_show_tab(ft_param_to_tab(ac, av));
}