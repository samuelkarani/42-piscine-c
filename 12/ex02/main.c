/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:39:15 by smbaabu           #+#    #+#             */
/*   Updated: 2018/09/06 19:59:24 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

char	g_buf[BUFF_SIZE + 1];

int		ft_read_stdin(void)
{
	char	g_buf[BUFF_SIZE + 1];
	int		i;
	int		ret;

	i = 1;
	while ((ret = read(STDIN, g_buf, BUFF_SIZE)))
	{
		g_buf[ret] = '\0';
		ft_putstr(STDOUT, g_buf);
	}
	return (ret);
}

int		get_lines(int fd)
{
	int ret;
	int sum;
	int i;

	sum = 0;
	while ((ret = read(fd, g_buf, BUFF_SIZE)))
	{
		i = 0;
		while (i < ret)
		{
			if (g_buf[i] == '\n')
				sum++;
			i++;
		}
	}
	if (!(g_buf[i - 1] == '\n'))
		sum++;
	if (lseek(fd, 0, SEEK_SET) == -1)
		return (-1);
	return (sum);
}

int		ft_read(int fd)
{
	int 	sum;
	int		i;
	int		ret;
	int 	l;
	int 	ok;

	if (fd == -1)
		return (1);
	if ((sum = get_lines(fd)) == -1)
		return (-1);
	l = 0;
	ok = 0;
	while ((ret = read(fd, g_buf, BUFF_SIZE)))
	{
		i = 0;
		while (!ok && i < ret)
		{
			if (g_buf[i] == '\n')
				l++;
			if (sum - l <= DEFAULT_LINES)
			{
				ok = 1;
				break;
			}
			i++;
		}
		if (ok)
		{
			g_buf[ret] = '\0';
			while (g_buf[i] != '\n')
				i++;
			ft_putstr(STDOUT, &g_buf[i + 1]);
		}
	}
	if (fd > 2 && close(fd) == -1)
		return (1);
	return (ret);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	int		flag;
	int		offset;
	int		whence;

	flag = 0;
	offset = 0;
	whence = SEEK_END;
	if (argc == 1)
		ft_read_stdin();
	else
	{
		i = 1;
		while (i < argc)
		{
			if (argv[i][0] == '-' && argv[i][1] == 'c')
				flag = 1;
			else if (flag)
			{
				offset = ft_atoi_wacky(argv[i]);
				whence = offset < 0 ? SEEK_SET : SEEK_END;
				flag = 0;
			}
			else
			{
				fd = open(argv[i], O_RDONLY | S_IRUSR);
				if (offset != 0)
					if (lseek(fd, offset, whence) == -1)
						return (-1);
				if ((offset != 0 && argc > 4) || (offset == 0 && argc > 2))
					print_file_name(argv[i]);
				ft_read(fd);
			}
			i++;
		}
	}
	return (0);
}
