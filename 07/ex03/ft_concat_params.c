/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 03:40:40 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/30 21:57:03 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strlen_ultimate(char **strs)
{
	int i;

	i = 0;
	while (strs)
	{
		i += ft_strlen(*strs) + 1;
		strs++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*p;

	p = dest;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (p);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*str;
	char	*p;
	int		i;
	int		l;

	i = 0;
	l = ft_strlen_ultimate(argv);
	str = (char *)malloc(sizeof(char) * l + 1);
	p = str;
	while (i < argc)
	{
		if (argv[i])
		{
			if (i > 0)
				*p++ = '\n';
			ft_strcpy(p, argv[i]);
			p += ft_strlen(argv[i]);
		}
		i++;
	}
	*p = '\0';
	return (str);
}
