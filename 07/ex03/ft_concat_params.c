/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 03:40:40 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 15:08:58 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*res;
	int		i, j, l, idx;

	i = 0, l = 0;
	while (i < argc)
		l += ft_strlen(argv[i++]);
	res = (char *)malloc(sizeof(char) * l + argc);
	i = 0, idx = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			res[idx++] = argv[i][j++];
		res[idx++] = '\n';
		i++;
	}
	res[idx] = 0;
	return (res);
}

#include <stdio.h>
int main(int ac, char **av)
{
	printf("%s", ft_concat_params(ac - 1, av + 1));
}
