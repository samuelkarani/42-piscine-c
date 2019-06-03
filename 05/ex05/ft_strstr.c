/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 16:24:24 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/27 20:24:14 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	c;
	char	d;
	int		i;
	int		j;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while ((c = str[i]) != '\0')
	{
		j = 0;
		while ((d = to_find[j]) == c && d != '\0')
		{
			i++;
			j++;
			c = str[i];
		}
		if (d == '\0')
			return (&str[i - j]);
		i++;
	}
	return (0);
}
