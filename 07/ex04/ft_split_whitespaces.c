/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:15:08 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/30 21:46:03 by smbaabu          ###   ########.fr       */
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

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char *p;

	p = dest;
	while (n)
	{
		if (*src != '\0')
			*dest++ = *src++;
		else
			*dest++ = '\0';
		n--;
	}
	return (p);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		k;
	char	*s;
	char	**res;

	i = 0;
	k = 0;
	res = (char **)malloc(sizeof(char *));
	while (str[i])
	{
		j = i;
		while (str[j] && (str[j] == '\n' || str[j] == '\t' || str[j] == ' '))
			j++;
		if (j > i)
		{
			s = malloc(sizeof(char) * j - i + 1);
			s = ft_strncpy(s, &str[i], j - i);
			i = j + 1;
			res[k++] = s;
			res = (char **)realloc(res, sizeof(char *) * k + 1);
		}
		else
			i++;
	}
	return (res);
}
