/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:54:22 by smbaabu           #+#    #+#             */
/*   Updated: 2018/09/12 21:00:34 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_bsq.h"

int		traverse_square_apply_func(char **map, t_square *sq,
	int (*funcptr)(char*))
{
	int i;
	int j;
	int k;

	i = sq->top_left.h_offset;
	while (i <= sq->bot_right.h_offset)
	{
		j = sq->top_left.w_offset;
		while (j <= sq->bot_right.w_offset)
		{
			if ((k = (*funcptr)(&map[i][j])))
				return (k);
			j++;
		}
		i++;
	}
	return (0);
}

void	traverse(char **map, int x, int y, t_square *largest_square)
{
	int			i;
	int			j;
	int			largest_square_dimension;
	t_square	sq;

	i = x;
	j = y;
	while (i < g_height && j < g_width)
	{
		sq.top_left.h_offset = x;
		sq.top_left.w_offset = y;
		sq.bot_right.h_offset = i;
		sq.bot_right.w_offset = j;
		if (traverse_square_apply_func(map, &sq, is_square_invalid))
			break ;
		if (i - x > largest_square_dimension)
		{
			largest_square_dimension = i - x | j - y;
			update_largest_square(largest_square, &sq);
		}
		i++;
		j++;
	}
}

char	**solve(char **map)
{
	int			i;
	int			j;
	t_square	*largest_square;

	largest_square = (t_square *)malloc(sizeof(t_square));
	i = 0;
	while (i < g_height)
	{
		j = 0;
		while (j < g_width)
		{
			if (is_square_invalid(&map[i][j]) == 0)
				traverse(map, i, j, largest_square);
			j++;
		}
		i++;
	}
	traverse_square_apply_func(map, largest_square, mark_spot);
	free(largest_square);
	return (map);
}
