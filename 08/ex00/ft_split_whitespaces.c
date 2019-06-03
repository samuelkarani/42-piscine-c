/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 22:15:26 by smbaabu           #+#    #+#             */
/*   Updated: 2018/09/02 23:35:15 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int		is_space(char c)
{
	return (c == '\n' || c == '\t' || c == ' ');
}

int		get_len_spaces(char *str)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = i;
		while (str[j] && !is_space(str[j]))
			j++;
		if (j > i)
		{
			i = j;
			k++;
		}
		i++;
	}
	return (k);
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
	res = (char **)malloc(sizeof(char *) * (get_len_spaces(str) + 1));
	while (str[i])
	{
		j = i;
		while (str[j] && !is_space(str[j]))
			j++;
		if (j > i)
		{
			s = ft_strncpy(malloc(sizeof(char) * j - i + 1), &str[i], j - i);
			res[k++] = s;
			i = j;
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}
