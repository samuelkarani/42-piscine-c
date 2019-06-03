/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 23:04:48 by smbaabu           #+#    #+#             */
/*   Updated: 2018/09/06 23:04:51 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

int		is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

void	print_file_name(char *filename)
{
	static int print_num;

	if (print_num == 0)
		ft_putstr(STDOUT, "==> ");
	else
		ft_putstr(STDOUT, "\n==> ");
	ft_putstr(STDOUT, filename);
	ft_putstr(STDOUT, " <==\n");
	print_num++;
}

int		ft_atoi_wacky(char *str)
{
	int i;
	int pos;
	int sum;

	sum = 0;
	pos = 0;
	i = 0;
	while (is_space(str[i]))
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			pos = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum *= 10;
		sum += str[i] - '0';
		i++;
	}
	return (pos ? -(sum) : sum);
}

void	ft_putstr(int fd, char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}