/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:09:58 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/26 00:20:36 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_opp.h"

int		(*ft_apply_op(char *str))(int, int)
{
	int i;

	i = 0;
	while (i < N - 1)
	{
		if (ft_strcmp(str, g_opptab[i].sign) == 0)
			return (g_opptab[i].op);
		i++;
	}
	return (g_opptab[N - 1].op);
}

int		ft_usage(int a, int b)
{
	(void)a;
	(void)b;
	return 0;
}

int		main(int argc, char **argv)
{
	int		b;
	int		(*f)(int, int);

	if (argc != 4)
		return (0);
	b = ft_atoi(argv[3]);
	f = ft_apply_op(argv[2]);
	if (b == 0)
	{
		if (ft_strcmp(argv[2], "/") == 0)
			return (ft_putstr("Stop : division by zero\n"));
		if (ft_strcmp(argv[2], "%") == 0)
			return (ft_putstr("Stop : modulo by zero\n"));
	}
	if (f == ft_usage)
		ft_putstr("error : only [ + - * / % ] are accepted.");
	else
		ft_putnbr((*f)(ft_atoi(argv[1]), b));
	ft_putchar('\n');
	return (0);
}
