/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 12:10:37 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/28 20:23:16 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int nmatch(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return 1;
	if (*s1 && *s1 == *s2)
		return nmatch(s1 + 1, s2 + 1);
	if (*s2 == '*')
		return !*s1
			? nmatch(s1, s2 + 1)
			: nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1);
	return 0;
}

int main() {
	printf("%d should be 2\n", nmatch("abcbd", "*b*"));
	printf("%d should be 3\n", nmatch("abc", "a**"));
	printf("%d should be 1\n", nmatch("abc", "a*"));
	printf("%d should be 10\n", nmatch("abc", "***"));
}