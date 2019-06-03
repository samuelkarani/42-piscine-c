/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:05:47 by smbaabu           #+#    #+#             */
/*   Updated: 2018/09/12 21:03:36 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "ft_bsq.h"

static int	g_counter;
static int	g_ret;

char	*read_copy(char **str, char **temp, int i)
{
	if (*str)
	{
		*temp = *str;
		*str = (char *)malloc(sizeof(char) * g_ret + i + 1);
		ft_strcpy(*str, *temp);
		free(*temp);
		*temp = NULL;
	}
	else
		*str = (char *)malloc(sizeof(char) * g_ret + 1);
	return (*str);
}

char	*read_parse(int fd)
{
	char	buf[BUFSIZE + 1];
	char	*str;
	char	*temp;
	int		i;
	int		k;

	initialize(&str, &temp, &i);
	while ((g_ret = read(fd, buf, BUFSIZE)))
	{
		buf[g_ret] = 0;
		if (g_counter++ == 0)
			k = read_first_line(buf);
		if (is_valid(&buf[k]) == -1)
			return (NULL);
		str = read_copy(&str, &temp, i);
		ft_strcat(str, &buf[k]);
		i += g_ret;
	}
	str[i] = 0;
	return (str);
}

char	*read_parse_wrapper(char *filename)
{
	int		fd;
	char	*str;

	if ((fd = open(filename, O_RDWR | S_IRUSR | S_IWUSR)) == -1)
		return (NULL);
	if ((str = read_parse(fd)) == NULL)
		return (NULL);
	if (close(fd) == -1)
		return (NULL);
	return (str);
}

void	execute(char **str)
{
	char **map;

	map = read_map(*str);
	solve(map);
	print_map(map);
	free(*str);
	free_map(map);
	g_counter = 0;
	g_prev = 0;
}

int		main(int ac, char **av)
{
	int		i;
	char	*str;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if ((str = read_parse_wrapper(av[i])) == NULL)
				ft_putstr("map error\n");
			else
				execute(&str);
			i++;
		}
	}
	else
	{
		if ((str = read_parse(0)) == NULL)
			ft_putstr("map error\n");
		else
			execute(&str);
	}
	return (0);
}
