/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 16:20:27 by amohamed          #+#    #+#             */
/*   Updated: 2018/08/26 16:20:32 by amohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_colle_2.h"

char	*rush03(int x, int y)
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
			if ((length == 1 || length == y) && width == 1)
				ft_strcat(str, "A");
			else if ((length == 1 || length == y) && width == x)
				ft_strcat(str, "C");
			else if (length > 1 && length < y && width > 1 && width < x)
				ft_strcat(str, " ");
			else
				ft_strcat(str, "B");
			width++;
		}
		ft_strcat(str, "\n");
		length++;
	}
	return (str);
}
