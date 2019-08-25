/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 22:38:34 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 23:00:30 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int fstrlen(char *s)
{
	int i = 0;
	while (s[i++])
		;
	return i;
}

char *ft_join(char **tab, char *sep)
{
	char *res;
	int i, l;

	for (l = 0, i = 0; tab[i]; i++)
		l += fstrlen(tab[i]);
	res = malloc((l + fstrlen(sep) * (i - 1) + 1) * sizeof(char));
	for (l = 0, i = 0; tab[i]; i++)
	{
		for (int j = 0; tab[i][j]; j++)
			res[l++] = tab[i][j];
		if (tab[i + 1])
			for (int j = 0; sep[j]; j++)
				res[l++] = sep[j];
	}
	res[l] = 0;
	return res;
}

#include <stdio.h>
int main(int ac, char **av) {
	printf("%s\n", ft_join(av, "|-|"));
}