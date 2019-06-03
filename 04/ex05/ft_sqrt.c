/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:10:59 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/25 12:57:13 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int n;
	int mid;
	int square;

	n = 1;
	mid = nb / 2;
	if (nb == 1)
		return (1);
	while (n <= mid)
	{
		square = n * n;
		if (square == nb)
			return (n);
		if (square > nb)
			return (0);
		n++;
	}
	return (0);
}
