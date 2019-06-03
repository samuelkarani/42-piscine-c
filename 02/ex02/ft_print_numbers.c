/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:12:48 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/23 13:15:17 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c);

void	ft_print_alphabet(void)
{
	int base;
	int last;
	int i;

	base = 48;
	last = 57;
	i = base;
	while (i <= last)
	{
		ft_putchar(i);
		i++;
	}
}
