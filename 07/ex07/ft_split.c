/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:57:13 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 19:03:40 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int isSep(char c, char *charset)
{
	for (int j = 0; charset[j]; j++)
		if (c == charset[j])
			return 1;
	return 0;
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

char **ft_split(char *str, char *charset)
{
	char **res;
	int n, idx, start;

	n = 1;
	for (int i = 0; str[i]; i++)
		if (isSep(str[i], charset))
			n++;
	res = malloc((n + 1) * sizeof(char *));
	start = 0, idx = 0;
	for (int i = 0; str[i]; i++)
	{
		if (!isSep(str[i], charset) && i > 0 && isSep(str[i - 1], charset))
			start = i;
		if (isSep(str[i], charset) && i > 0 && !isSep(str[i - 1], charset))
			res[idx++] = strsub(str + start, i - start);
		else if (!str[i + 1] && !isSep(str[i], charset))
			res[idx++] = strsub(str + start, i - start + 1);
	}
	res[idx] = 0;
	return (res);
}

#include <stdio.h>
int main(int ac, char **av)
{
	if (ac == 3)
	{
		char **sarr = ft_split(av[1], av[2]);
		for (int i = 0; sarr[i]; i++)
			printf("%s\n", sarr[i]);
	}
}
