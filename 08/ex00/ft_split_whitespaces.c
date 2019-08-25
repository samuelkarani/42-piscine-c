/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 22:15:26 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 19:23:31 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int isSep(char c)
{
	return c == '\t' || c == ' ' || c == '\n';
}

int size(char *s)
{
	int n = 1;
	for (int i = 0; s[i]; i++)
		if (isSep(s[i]))
			n++;
	return n;
}

char *strsub(char *s, int len)
{
	char *res = malloc((len + 1) * sizeof(char));
	int i = 0;
	for (; i < len; i++)
		res[i] = s[i];
	res[i] = 0;
	return res;
}

char	**ft_split_whitespaces(char *str)
{
	int		idx, start;
	char	**res;

	res = malloc((size(str) + 1) * sizeof(char *));
	start = 0, idx = 0;
	for (int i = 0; str[i]; i++)
	{
		if (!isSep(str[i]) && i > 0 && isSep(str[i - 1]))
			start = i;
		if (isSep(str[i]) && i > 0 && !isSep(str[i - 1]))
			res[idx++] = strsub(str + start, i - start);
		else if (!str[i + 1] && !isSep(str[i]))
			res[idx++] = strsub(str + start, i - start + 1);
	}
	res[idx] = 0;
	return (res);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char **sarr = ft_split_whitespaces(av[1]);
		for (int i = 0; sarr[i]; i++)
			printf("%s\n", sarr[i]);
	}
}