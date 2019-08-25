/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 00:51:28 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/21 20:40:08 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void inc(char *buf, int i, int n)
{
	if (n < 0)
		return;
	if (buf[i] + 1 > '9')
		return inc(buf, i - 1, n);
	buf[i++]++;
	for (; i < n; i++)
	{
		if (buf[i - 1] + 1 > '9')
			inc(buf, i - 1, n);
		else
			buf[i] = buf[i - 1] + 1;
	}
	return ;
}

int mx(char *buf, int n)
{
	int mx = 0;
	for (int i = 0; i < n - 1; i++)
		if (buf[i] + 1 == buf[i + 1])
			mx++;
	return buf[n - 1] == '9' && mx == n - 1;
}

int check(char *buf, int n)
{
	int i, mx;
	for (i = 0; i < n - 1; i++)
		if (buf[i] >= buf[i + 1])
			return 0;
	return 1;
}

void	ft_print_combn(int n)
{
	char buf[n];

	for (int i = 0; i < n; i++)
		buf[i] = '0' + i;
	while (1)
	{
		if (check(buf, n))
		{
			write(1, buf, n);
			if (!mx(buf, n))
				write(1, ", ", 2);
			else
				break ;
		}
		inc(buf, n - 1, n);
	}
}

int		main(void)
{
	// ft_print_combn(2);
	ft_print_combn(3);
	// ft_print_combn(4);
}
