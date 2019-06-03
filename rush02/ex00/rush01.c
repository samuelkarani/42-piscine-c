/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 16:19:26 by amohamed          #+#    #+#             */
/*   Updated: 2018/08/26 16:20:05 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_colle_2.h"

char	*rush01(int x, int y)
{
	int		width;
	int		length;
	char	*str;

	str = (char *)malloc(sizeof(char) * x * y + (y + 1));
	length = 1;
	while (length <= y)
	{
		width = 1;
		while (width <= x)
		{
			if ((width == x && length == y) || (width == 1 && length == 1))
				ft_strcat(str, "/");
			else if ((width == x && length == 1) || (width == 1 && length == y))
				ft_strcat(str, "\\");
			else if (length > 1 && length < y && width > 1 && width < x)
				ft_strcat(str, " ");
			else
				ft_strcat(str, "*");
			width++;
		}
		ft_strcat(str, "\n");
		length++;
	}
	return (str);
}
