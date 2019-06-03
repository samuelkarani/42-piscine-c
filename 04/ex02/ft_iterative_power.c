/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 11:14:56 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/25 11:27:26 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int n;
	int result;

	n = power;
	result = 1;
	if (n < 0)
		return (0);
	while (n > 0)
	{
		result *= nb;
		n--;
	}
	return (result);
}
