/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrigo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 13:01:09 by rfrigo            #+#    #+#             */
/*   Updated: 2018/09/12 21:21:43 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_bsq.h"

char	**read_map(char *str)
{
	char	**map;
	char	*line;
	int		i;
	int		j;

	map = malloc(sizeof(char *) * (g_height + 1));
	i = 0;
	while (i < g_height)
	{
		j = 0;
		line = malloc(sizeof(char) * (g_width + 1));
		while (*str && *str != '\n')
		{
			line[j] = *str;
			j++;
			str++;
		}
		line[j] = '\0';
		map[i] = line;
		str++;
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	free_map(char **map)
{
	int		i;
	char	*ptr;

	i = 0;
	while (i < g_height)
	{
		ptr = map[i];
		free(ptr);
		i++;
	}
	free(map);
}

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_height)
	{
		j = 0;
		while (j < g_width)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
