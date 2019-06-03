/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 13:05:36 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/25 15:44:59 by smbaabu          ###   ########.fr       */
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

int		h_is_prime(int nb)
{
	if (nb <= 1)
		return (0);
	return (h_is_divisible(nb, 2, h_sqrt(nb)));
}

int		ft_find_next_prime(int nb)
{
	while (1)
	{
		if (h_is_prime(nb))
			return (nb);
		nb++;
	}
}
