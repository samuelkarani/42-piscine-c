/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 12:58:35 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/28 20:37:56 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	h_strlen(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char	*s;
	char	*d;
	int		n;
	int		dlen;

	d = dest;
	s = src;
	n = size;
	while (*d != '\0' && n-- != 0)
		d++;
	dlen = d - dest;
	n = size - dlen;
	if (n == 0)
		return (dlen + h_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
