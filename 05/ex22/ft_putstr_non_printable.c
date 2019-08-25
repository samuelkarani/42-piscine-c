/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:57:04 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 16:57:08 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void fputchar(char c)
{
	write(1, &c, 1);
}

void print(char c)
{
	if (c < 16)
		fputchar(c < 10 ? c + '0' : c - 10 + 'a');
	else
	{
		print(c / 16);
		print(c % 16);
	}
}

void ft_putstr_non_printable(char *str)
{
	char c;
	for (int i = 0; (c = str[i]); i++)
	{
		if (c > 31 && c < 127)
			write(1, &c, 1);
		else
		{
			write(1, "\\0", 2);
			print(c);
		}
	}
}

int main()
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
}