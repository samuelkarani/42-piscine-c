/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:41:46 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/28 16:02:20 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		get_height(int n)
{
	int i;
	int sum;

	i = 3;
	sum = 0;
	while (n)
	{
		sum += i;
		i++;
		n--;
	}
	return (sum);
}

int		get_width(int n)
{
	int sum;
	int x;
	int u;
	int i;
	int s;

	sum = 7;
	x = 3;
	u = 0;
	i = 0;
	s = 3;
	while (i < n - 1)
	{
		if (u == 2)
		{
			x++;
			u = 0;
		}
		sum += (x + s) * 2;
		u++;
		i++;
		s++;
	}
	return (sum);
}

void	sastantua(int size)
{
	int i;
	int j;
	int h;
	int w;
	int m;
	int magic_line;
	int offset;
	int offset_inc;
	int x;
	int u;
	int n;

	i = 0;
	j = 0;
	h = get_height(size);
	w = get_width(size);
	m = w / 2;
	magic_line = 3;
	offset = 0;
	offset_inc = 2;
	x = 3;
	u = 0;
	n = 1;
	while (i < h)
	{
		j = 0;
		if (i == magic_line)
		{
			if (u == 2)
			{
				u = 0;
				offset_inc++;
			}
			u++;
			x++;
			magic_line = i + x;
			offset += offset_inc;
			if (u == 2)
				n += 2;
		}
		while (j < w)
		{
			if (magic_line == h)
			{
				if (i >= h - n)
					if (j >= m - n / 2 && j <= m + n / 2)
					{
						if (n > 3 && i == h - n / 2 - 1 && j == m + n / 2 - 1)
							ft_putchar('$');
						else
							ft_putchar('|');
						j++;
						continue;
					}
			}
			if (j == m - i - 1 - offset)
				ft_putchar('/');
			else if (j == m + i + 1 + offset)
				ft_putchar(92);
			else if (j > m - i - 1 - offset && j < m + i + 1 + offset)
				ft_putchar('*');
			else
				ft_putchar(' ');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

int		main(void)
{
	sastantua(7);
}
