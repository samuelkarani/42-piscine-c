/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 12:08:29 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/28 20:23:39 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int match2(char *s1, char *s2)
{
	if (!*s2)
		return 1;
	if (*s1 && *s1 == *s2)
		return match2(s1 + 1, s2 + 1);
	if (*s2 == '*')
	{
		if (s2[1] && s2[1] != '*' && !(s1 = strchr(s1, s2[1])))
			return 0;
		return match2(s1, s2 + 1);
	}
	return 0;
}

int match(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return 1;
	if (*s1 && *s1 == *s2)
		return match(s1 + 1, s2 + 1);
	if (*s2 == '*')
		return !*s1
			? match(s1, s2 + 1)
			: match(s1 + 1, s2) || match(s1, s2 + 1);
	return 0;
}

int main() {
	printf("%d should be 1\n", match("main.c", "*"));
	printf("%d should be 1\n", match("main.c", "***************"));
	printf("%d should be 1\n", match("main.c", "*.c"));
	printf("%d should be 0\n", match("main.c", "*.k"));
	printf("%d should be 1\n", match("main.c", "main*"));
	printf("%d should be 0\n", match("main.c", "maim*"));
	printf("%d should be 1\n", match("main.c", "*ai*"));
	printf("%d should be 0\n", match("majin.c", "*ai*"));
	printf("%d should be 1\n", match("main.c", "*a*i*"));
	printf("%d should be 1\n", match("main.c", "*a*c*"));
	printf("%d should be 0\n", match("main.c", "*a*m*"));
	printf("%d should be 1\n", match("", "*"));
	printf("%d should be 1\n", match("", "**"));
	printf("%d should be 1\n", match("abcbd", "*b*"));
	printf("%d should be 1\n", match("abc", "a**"));
}