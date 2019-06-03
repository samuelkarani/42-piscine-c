/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:09:58 by smbaabu           #+#    #+#             */
/*   Updated: 2018/09/03 23:08:30 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		(*ft_operator(char c))(int, int)
{
	if (c == '+')
		return (&ft_add);
	else if (c == '-')
		return (&ft_sub);
	else if (c == '*')
		return (&ft_mul);
	else if (c == '/')
		return (&ft_div);
	else if (c == '%')
		return (&ft_mod);
	else
		return (NULL);
}

int		main(int argc, char **argv)
{
	int		b;
	int		(*f)(int, int);
	int		res;

	if (argc != 4)
		return (0);
	b = ft_atoi(argv[3]);
	if ((f = ft_operator(argv[2][0])) != NULL)
	{
		if (b == 0)
		{
			if (argv[2][0] == '/')
				return (ft_putstr("Stop : division by zero\n"));
			if (argv[2][0] == '%')
				return (ft_putstr("Stop : modulo by zero\n"));
		}
		res = (*f)(ft_atoi(argv[1]), b);
		ft_putnbr(res);
	}
	else
		ft_putnbr(0);
	ft_putchar('\n');
	return (0);
}
