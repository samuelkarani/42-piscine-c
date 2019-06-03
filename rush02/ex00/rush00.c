/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 16:19:11 by amohamed          #+#    #+#             */
/*   Updated: 2018/08/26 16:19:16 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_colle_2.h"

int		g_width;
int		g_length;
char	*g_str;

char	*rush00(int x, int y)
{
	g_str = (char *)malloc(sizeof(char) * x * y + (y + 1));
	g_length = 1;
	while (g_length <= y)
	{
		g_width = 1;
		while (g_width <= x)
		{
			if ((g_length == 1 || g_length == y) && g_width == 1)
				ft_strcat(g_str, "o");
			else if ((g_length == 1 || g_length == y) && g_width == x)
				ft_strcat(g_str, "o");
			else if (g_length > 1 && g_length < y && g_width > 1 && g_width < x)
				ft_strcat(g_str, " ");
			else if ((g_width == 1 || g_width == x) && (g_length > 1 ||
				g_length < y))
				ft_strcat(g_str, "|");
			else
				ft_strcat(g_str, "-");
			g_width++;
		}
		ft_strcat(g_str, "\n");
		g_length++;
	}
	return (g_str);
}
