/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 10:17:28 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/25 10:49:41 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int result;
	int n;

	n = nb;
	result = 1;
	if (n < 0)
		return (0);
	if (n == 0)
		return (1);
	if (n >= 13)
		return (0);
	while (n > 1)
	{
		result *= n;
		n--;
	}
	return (result);
}
