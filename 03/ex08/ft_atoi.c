/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 23:20:24 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/24 23:33:44 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		h_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		h_power(int x, int n)
{
	if (n < 0)
		return (1);
	if (n == 1)
		return (x);
	return (x * h_power(x, n - 1));
}

int ft_atoi(char *str)
{
	char 	*p;
	int 	i;
	char 	c;
	int 	l;
	int 	neg;
	int 	sum;
	
	p = str;
	l = h_strlen(p);
	neg = 0;
	c = *str;
	if (c == '-')
	{
		p++;
		l--;
		neg = 1;
	}
	while (i < l)
	{
		c = str[i];
		int pr = (c - 48) * h_power(10, l - i - 1);
		sum += pr;
		i++;
	}
	return neg ? sum * -1 : sum;
}
