/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:57:12 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 16:57:14 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int fstrlen(char *s)
{
	int i = 0;
	for (; s[i]; i++)
		;
	return i;
}

int checkBase(char *base)
{
	for (int i = 0; base[i]; i++)
		if (base[i] == '+' || base[i] == '-')
			return 0;
	for (int i = 0; i < base[i + 1]; i++)
		for (int j = i + 1; j < base[j]; j++)
			if (base[i] >= base[j])
				return 0;
	return 1;
}

int checkInput(char *str, char *base)
{
	for (int i = 0; str[i]; i++)
	{
		int ok = 0;
		for (int j = 0; base[j]; j++)
			if (str[i] == base[j])
				ok = 1;
		if (!ok)
			return 0;
	}
	return 1;
}

int ft_atoi_base(char *str, char *base)
{
	int b, neg, i, j, sum;

	b = fstrlen(base);
	if (!str || !base || b < 2 || !checkBase(base))
		return 0;
	i = 0, neg = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	if (!checkInput(str + i, base))
		return 0;
	sum = 0;
	for (; str[i]; i++)
	{
		sum *= b;
		for (j = 0; base[j]; j++)
			if (str[i] == base[j])
				break ;
		sum += j;
	}
	return sum * neg;
}

#include <stdio.h>
int main()
{
	printf("%d\n", ft_atoi_base("-2147483648", "0123456789"));
	printf("%d\n", ft_atoi_base("-20000000000", "01234567"));
	printf("%d\n", ft_atoi_base("-80000000", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("-10000000000000000000000000000000", "01"));
	printf("%d\n", ft_atoi_base("2147483647", "0123456789"));
	printf("%d\n", ft_atoi_base("20000000000", "01234567"));
	printf("%d\n", ft_atoi_base("80000000", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("10000000000000000000000000000000", "01"));
}