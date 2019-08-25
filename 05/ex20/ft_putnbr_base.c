/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 21:52:37 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/22 23:49:36 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int abs(int n)
{
	return n < 0 ? -n : n;
}

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

void helper(int nbr, char *base, int b)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		if (abs(nbr / b))
			helper(abs(nbr / b), base, b);
		helper(abs(nbr % b), base, b);
	}
	else if (nbr < b)
		write(1, &base[nbr], 1);
	else
	{
		helper(nbr / b, base, b);
		helper(nbr % b, base, b);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int b = fstrlen(base);
	if (!base ||  b < 2 || !checkBase(base))
		return ;
	helper(nbr, base, b);
}

#include <stdio.h>
int main()
{
	ft_putnbr_base(-2147483648, "0123456789"); printf("\n");
	ft_putnbr_base(-2147483648, "01");printf("\n");
	ft_putnbr_base(-2147483648, "0123456789ABCDEF");printf("\n");
	ft_putnbr_base(-2147483648, "01234567");printf("\n");
	ft_putnbr_base(2147483647, "0123456789"); printf("\n");
	ft_putnbr_base(2147483647, "01");printf("\n");
	ft_putnbr_base(2147483647, "0123456789ABCDEF");printf("\n");
	ft_putnbr_base(2147483647, "01234567");
}
