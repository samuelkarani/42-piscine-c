/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 00:07:40 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/26 15:59:34 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 4096

void	ft_putstr(int fd, char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

int		main(int argc, char **argv)
{
	char	buf[BUFF_SIZE + 1];
	int		fd;
	int		ret;

	if (argc == 1)
		ft_putstr(2, "File name missing.");
	else if (argc > 2)
		ft_putstr(2, "Too many arguments.");
	else
	{
		if ((fd = open(argv[1], O_RDONLY | S_IRUSR)) == -1)
			return (1);
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			buf[ret] = 0;
			ft_putstr(1, buf);
		}
		ft_putstr(1, "\n");
		close(fd);
	}
	return (0);
}
