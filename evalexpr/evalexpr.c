/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 15:58:31 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/27 23:57:55 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int abs(n)
{
	return n < 0 ? -n : n;
}

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int ft_strcpy(char *dest, char *src, int nul)
{
	int i = 0;
	while (*src)
	{
		*dest++ = *src++;
		i++;
	}
	if (nul)
		*dest = 0;
	return i;
}

char *strsub(char *s, int len)
{
	char *res = malloc((len + 1) * sizeof(char));
	for (int i = 0; i < len; i++)
		res[i] = s[i];
	res[len] = 0;
	return res;
}

int		ft_atoi(char *str, int *off)
{
	int i;
	int neg;
	int sum;

	sum = 0;
	neg = 1;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg = -1;
	for (; str[i] >= '0' && str[i] <= '9'; i++)
		sum = sum * 10 + str[i] - '0';
	*off = i;
	return (sum * neg);
}

char *ft_itoa(int n)
{
	char *str;
	int k, neg, i;

	k = n;
	i = 1;
	while (k /= 10)
		i++;
	i += neg = n < 0;
	str = malloc((i + 1) * sizeof(char));
	str[i] = 0;
	if (!n)
		str[--i] = '0';
	for (; n; n /= 10)
		str[--i] = abs(n % 10) + '0';
	if (neg)
		str[0] = '-';
	return str;
}

int solve(int a, int b, char op)
{
	if (op == '%')
		return a % b;
	else if (op == '/')
		return a / b;
	else if (op == '*')
		return a * b;
	else if (op == '+')
		return a + b;
	else if (op == '-')
		return a - b;
	return 0;
}

int prec(char op, int n)
{
	return (n == 0 && (op == '%' || op == '*' || op == '/'))
	|| (n == 1 && (op == '+' || op == '-'));
}

int eval_expr(char *str)
{
	char *r;
	int i, v, s, a, b, op, off;

	i = 0;
	while (str[i])
	{
		if (str[i] == '(')
		{
			s = i;
			v = 1;
			while (v)
			{
				i++;
				if (str[i] == '(')
					v++;
				if (str[i] == ')')
					v--;
			}
			r = strsub(str + s + 1, i - s - 1);
			v = eval_expr(r);
			r = ft_itoa(v);
			s += ft_strcpy(str + s, r, 0);
			ft_strcpy(str + s, str + i + 1, 1);
			i = s;
		}
		else
			i++;
	}
	for (int n = 0; n < 2; n++)
	{
		i = 0;
		while (str[i])
		{
			if (prec(str[i], n) && str[i + 1] == ' ')
			{
				op = str[i++];
				b = ft_atoi(str + i, &off);
				i += off;
				v = solve(a, b, op);
				r = ft_itoa(v);
				s += ft_strcpy(str + s, r, 0);
				ft_strcpy(str + s, str + i, 1);
				i = 0;
			}
			else if (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
			{
				s = i;
				a = ft_atoi(str + i, &off);
				i += off;
			}
			else
				i++;
		}
	}
	return v;
}

int	main(int ac, char ** av)
{
	if (ac == 2)
		printf("%d\n", eval_expr(av[1]));
	return 0;
}
