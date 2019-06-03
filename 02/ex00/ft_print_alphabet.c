/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:45:01 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/23 12:02:41 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c);

void	ft_print_alphabet(void)
{
	int base;
	int last;
	int i;

	base = 97;
	last = 122;
	i = base;
	while (i <= last)
	{
		ft_putchar(i);
		i++;
	}
}
