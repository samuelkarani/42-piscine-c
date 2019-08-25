/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:56:59 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 16:57:00 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int fstrlen(char *s)
{
	int i = 0;
	for (; s[i]; i++)
		;
	return i;
}

void fputstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void hex(char s)
{
	if (s < 16)
	{
		char c = s < 10 ? s + '0' : s - 10 + 'a';
		write(1, &c , 1);
	}
	else
	{
		hex(s / 16);
		hex(s % 16);
	}
}

void print(char c)
{
	if (c < 16)
		fputstr("0");
	hex(c);
}

void *ft_print_memory(void *addr, unsigned int size)
{
	char buf[9];
	buf[8] = 0;
	int n, v;
	char c;

	for (int i = 0; i < size; i += 16)
	{
		n = i;
		for (int j = 7; j >= 0; j--)
		{
			v = n % 16;
			buf[j] = v < 10 ? v + '0' : v - 10 + 'a';
			n /= 16;
		}
		fputstr(buf);
		fputstr(": ");
		for (int j = 0; j < 16; j += 2)
		{
			print(((char *)addr + i)[j]);
			print(((char *)addr + i)[j + 1]);
			fputstr(" ");
		}
		for (int j = 0; j < 16; j++)
		{
			c = ((char *)addr + i)[j];
			if (c > 31 && c < 127)
				write(1, &c, 1);
			else
				write(1, ".", 1);
		}
		fputstr("\n");
	}
	return addr;
}

int main()
{
	char *str = "Salut les aminches c'est cool show mem on fait de truc terrible\1\2";
	ft_print_memory(str, fstrlen(str));
	ft_print_memory(str, 0);
}