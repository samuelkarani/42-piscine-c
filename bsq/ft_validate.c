/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 21:20:29 by smbaabu           #+#    #+#             */
/*   Updated: 2018/09/12 21:20:33 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

#include <stdio.h>

int		get_width(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

int		get_height(char *str)
{
	return (ft_atoi(str));
}

int		validate_chars(char *str)
{
	int		i;
	char	c;

	i = 0;
	while ((c = str[i]))
	{
		if (!(c == g_obstacle || c == g_empty || c == '\n'))
			return (-1);
		i++;
	}
	return (0);
}

int		check_width(char *str)
{
	int i;
	int w;
	int h;

	i = 0;
	h = 0;
	while (str[i] && h < g_height)
	{
		if ((w = get_width(&str[i])) != g_width)
		{
			if (i + w + 1 >= BUFSIZE)
				g_prev++;
			else
			{
				if (g_prev <= 0)
					return (-1);
			}
		}
		i = w + i + 1;
		h++;
	}
	return (0);
}

int		is_valid(char *buf)
{
	int i;

	i = 0;
	if (validate_chars(buf) == -1)
	{
		return (-1);
	}
	if (check_width(buf) == -1)
	{
		return (-1);
	}
	return (0);
}
