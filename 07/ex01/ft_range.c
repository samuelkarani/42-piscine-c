/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 01:08:16 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/30 12:58:03 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*nums;
	int		*p;

	if (min >= max)
		return (NULL);
	nums = (int *)malloc(sizeof(int) * (max - min));
	if (!nums)
		return (0);
	p = nums;
	while (min < max)
		*nums++ = min++;
	return (p);
}
