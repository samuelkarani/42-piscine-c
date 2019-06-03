/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:27:40 by smbaabu           #+#    #+#             */
/*   Updated: 2018/09/12 20:28:23 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		mark_spot(char *c)
{
	*c = g_full;
	return (0);
}

int		is_square_invalid(char *c)
{
	return (*c == g_obstacle ? 1 : 0);
}

void	print_sq_coordinates(t_square *sq)
{
	ft_putnbr(sq->top_left.h_offset);
	ft_putchar(',');
	ft_putnbr(sq->top_left.w_offset);
	ft_putchar(',');
	ft_putnbr(sq->bot_right.h_offset);
	ft_putchar(',');
	ft_putnbr(sq->bot_right.w_offset);
	ft_putchar('\n');
}

void	update_largest_square(t_square *largest_square, t_square *sq)
{
	largest_square->bot_right.h_offset = sq->bot_right.h_offset;
	largest_square->top_left.h_offset = sq->top_left.h_offset;
	largest_square->bot_right.w_offset = sq->bot_right.w_offset;
	largest_square->top_left.w_offset = sq->top_left.w_offset;
}
