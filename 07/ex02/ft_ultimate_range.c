/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 01:49:01 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/30 13:48:15 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		*nums;
	int		ret;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	nums = (int *)malloc(sizeof(int) * (max - min));
	if (!nums)
		return (0);
	*range = nums;
	ret = max - min;
	while (min < max)
		*nums++ = min++;
	return (ret);
}
