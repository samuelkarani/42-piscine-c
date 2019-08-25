/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:37:46 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/22 20:03:23 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int n = size - 1, srcsize;
	for (srcsize = 0; src[srcsize]; srcsize++)
		;
	while (n-- > 0 && *src)
		*dest++ = *src++;
	*dest = 0;
	return srcsize;
}

#include <string.h>
#include <stdio.h>
int main()
{
	char dst[20]; int d;
	d = ft_strlcpy(dst, "abc", 4);
	printf("%d %s\n", d, dst);
	d = strlcpy(dst, "abc", 4);
	printf("%d %s\n", d, dst);

	d = ft_strlcpy(dst, "abc", 3);
	printf("%d %s\n", d, dst);
	d = strlcpy(dst, "abc", 3);
	printf("%d %s\n", d, dst);
}