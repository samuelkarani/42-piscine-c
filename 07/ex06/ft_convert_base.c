/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:56:31 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 18:47:47 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int abs(int n)
{
	return n < 0 ? -n : n;
}

int fatoi(char *nbr, char *base)
{
	int sum, md, b, neg, j;

	neg = 1;
	if (*nbr == '+' || *nbr == '-')
		if (*nbr++ == '-')
			neg = -1;
	b = ft_strlen(base);
	sum = 0;
	for (int i = 0; nbr[i]; i++)
	{
		sum *= b;
		for (j = 0; base[j]; j++)
			if (base[j] == nbr[i])
				break ;
		sum += j;
	}
	return sum * neg;
}

char *fitoa(int nb, char *base)
{
	char *res;
	int b, md, n, k, neg;

	neg = 0;
	if (nb < 0)
		neg = 1;
	b = ft_strlen(base);
	n = 1; k = nb;
	while (k /= b)
		n++;
	n += neg;
	res = malloc((n + 1) * sizeof(char));
	res[n] = 0;
	for (; nb; nb /= b)
		res[--n] = base[abs(nb % b)];
	if (neg)
		res[0] = '-';
	return res;
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	return fitoa(fatoi(nbr, base_from), base_to);
}

int main()
{
	printf("%s\n", ft_convert_base("-2147483648", "0123456789", "0123456789ABCDEF"));
	printf("%s\n", ft_convert_base("2147483647", "0123456789", "0123456789ABCDEF"));
	printf("%s\n", ft_convert_base("-20000000000", "01234567", "01"));
	printf("%s\n", ft_convert_base("-80000000", "0123456789ABCDEF", "01234567"));
	printf("%s\n", ft_convert_base("-10000000000000000000000000000000", "01", "0123456789"));
	printf("%s\n", ft_convert_base("2147483647", "0123456789", "0123456789"));
	printf("%s\n", ft_convert_base("20000000000", "01234567", "01"));
	printf("%s\n", ft_convert_base("80000000", "0123456789ABCDEF", "01234567"));
	printf("%s\n", ft_convert_base("10000000000000000000000000000000", "01", "0123456789ABCDEF"));
}
