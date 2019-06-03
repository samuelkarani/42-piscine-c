/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrigo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:57:46 by rfrigo            #+#    #+#             */
/*   Updated: 2018/09/12 21:00:34 by rfrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	traverse_square_apply_func_optimized(char **map, \
		t_square *sq, int (*funcptr)(char*))
{
	int i;
	int j;
	int k;

	i = 0;
	j = sq->bot_right.w_offset;
	while (i <= sq->bot_right.h_offset)
	{
		if ((k = (*funcptr)(&map[i][j])))
			return (k);
		i++;
	}
	j = 0;
	i = sq->bot_right.h_offset;
	while (j <= sq->bot_right.w_offset)
	{
		if ((k = (*funcptr)(&map[i][j])))
			return (k);
		j++;
	}
	return (0);
}
