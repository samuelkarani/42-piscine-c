/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:57:09 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/26 16:41:26 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 4096
#define STDIN 0
#define STDOUT 1
#define STDERR 2

int fstrcmp(char *a, char *b)
{
	while (*a && *b && *a == *b)
	{
		a++;
		b++;
	}
	return *a - *b;
}

void	ft_putstr(int fd, char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

int		ft_read(int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		i;
	int		ret;

	i = 1;
	if (fd == -1)
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putstr(STDOUT, buf);
	}
	if (fd > 2 && close(fd) == -1)
		return (1);
	return (ret);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;

	if (argc == 1)
		ft_read(STDIN);
	else
	{
		i = 1;
		while (i < argc)
		{
			if (!fstrcmp(argv[i], "-"))
				fd = STDIN;
			else
				fd = open(argv[i], O_RDONLY | S_IRUSR);
			ft_read(fd);
			i++;
		}
	}
	return (0);
}
