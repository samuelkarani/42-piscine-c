/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 12:58:35 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/22 19:58:06 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dstsize, srcsize, left;

	dstsize = 0;
	while (*dest)
	{
		dest++;
		dstsize++;
	}
	for (srcsize = 0; src[srcsize]; srcsize++)
		;
	if (size <= dstsize)
		return srcsize + size;
	left = size - dstsize - 1;
	while (left-- > 0)
		*dest++ = *src++;
	*dest = 0;
	return srcsize + dstsize;
}

#include <stdio.h>
#include <string.h>
int main()
{
	char buf1[20] = "abc";
	char buf2[20] = "abc";
	int d;
	d = ft_strlcat(buf1, "def", 7);
	printf("%d %s\n", d, buf1);
	d = strlcat(buf2, "def", 7);
	printf("%d %s\n", d, buf2);

	strcpy(buf1, "abc");
	strcpy(buf2, "abc");
	d = ft_strlcat(buf1, "def", 6);
	printf("%d %s\n", d, buf1);
	d = strlcat(buf2, "def", 6);
	printf("%d %s\n", d, buf2);

	strcpy(buf1, "abc");
	strcpy(buf2, "abc");
	d = ft_strlcat(buf1, "def", 2);
	printf("%d %s\n", d, buf1);
	d = strlcat(buf2, "def", 2);
	printf("%d %s\n", d, buf2);
}
