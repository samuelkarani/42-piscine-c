/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 16:24:24 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 17:59:52 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *p, *r;

	if (!str || !to_find)
		return 0;
	if (!*to_find)
		return str;
	r = to_find;
	while (*str)
	{
		p = str;
		while (*str && *to_find && *to_find == *str)
		{
			to_find++;
			str++;
		}
		if (!*to_find)
			return p;
		to_find = r;
		str = p + 1;
	}
	return 0;
}

#include <stdio.h>
int main(int argc, char const *argv[])
{
	printf("%s\n", ft_strstr("heeedle", "eedl"));
	printf("%s\n", ft_strstr("heeedle", "op"));
	printf("%s\n", ft_strstr("heeedle", ""));
	return 0;
}
