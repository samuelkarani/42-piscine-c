/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:48:35 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/25 15:02:39 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		h_sqrt(int nb)
{
	int square;
	int i;

	i = 0;
	while ((square = i * i) <= nb)
	{
		if (square == nb)
			return (i);
		i++;
	}
	return (i == nb ? i - 1 : i);
}

int		h_is_divisible(int n, int i, int lim)
{
	if (i > lim)
		return (1);
	if (n % i == 0)
		return (0);
	return (h_is_divisible(n, i + 1, lim));
}

int		ft_is_prime(int nb)
{
	if (nb <= 1)
		return (0);
	return (h_is_divisible(nb, 2, h_sqrt(nb)));
}
