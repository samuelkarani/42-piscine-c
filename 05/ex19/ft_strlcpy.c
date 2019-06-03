/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:37:46 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/28 21:51:58 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	h_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int l;

	l = h_strlen(src);
	i = 0;
	if (l + 1 < size)
	{
		while (i < l + 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else if (size != 0)
	{
		while (i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (l);
}
