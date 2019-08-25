/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 22:15:26 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 20:28:19 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

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
	res[len] = 0;
	for (int i = 0; i < len; i++)
		res[i] = s[i];
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
