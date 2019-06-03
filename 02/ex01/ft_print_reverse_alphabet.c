/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:04:37 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/23 23:19:32 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c);

void	ft_print_reverse_alphabet(void)
{
	int base;
	int first;
	int i;

	base = 122;
	first = 97;
	i = base;
	while (i >= first)
	{
		ft_putchar(i);
		i--;
	}
}
