/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrigo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:55:41 by rfrigo            #+#    #+#             */
/*   Updated: 2018/09/12 20:55:47 by rfrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bsq.h"

int		read_first_line(char *str)
{
	int i;

	g_height = ft_atoi(str);
	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	g_empty = str[i++];
	g_obstacle = str[i++];
	g_full = str[i++];
	g_width = get_width(&str[++i]);
	return (i);
}

void	initialize(char **str, char **temp, int *i)
{
	*str = NULL;
	*temp = NULL;
	*i = 0;
}

void	*free_and_null(char **str)
{
	if (str)
		free(str);
	return (NULL);
}
