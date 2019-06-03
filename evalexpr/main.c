/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 15:58:31 by smbaabu           #+#    #+#             */
/*   Updated: 2018/09/08 15:58:33 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int 	i;
char	*substr;
int		ret;
int 	last;
char 	c;

int		eval_expr(char *str);
{
	initialize();
	i = 0;
	while ((c = str[i]))
	{
		if (c == '(')
		{
			push(c);
			last = i;
		}
		else if (c == ')' && peek() == ')')
		{
			substr = (char *)malloc(sizeof(char) * (i - last));
			ret = eval_expr(ft_strncpy(str, substr));
			str = substr(0, last) + atai(ret) + substr(i + 1, end);
		}
	}
}

int     main(int ac, char ** av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
