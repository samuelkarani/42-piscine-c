/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 23:20:24 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 17:44:28 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_space(char c)
{
	return c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r';
}

int		ft_atoi(char *str)
{
	int i;
	int neg;
	int sum;

	sum = 0;
	neg = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum *= 10;
		sum += str[i] - '0';
		i++;
	}
	return sum * neg;
}

#include <stdio.h>
int main(int ac, char **av) {
	for (int i = 1; av[i]; i++)
		printf("%d\n", ft_atoi(av[i]));
}
