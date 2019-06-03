#include <stdio.h>

char	**ft_split_whitespaces(char *str);
int		main(void)
{
	char **res;
	for (res = ft_split_whitespaces("asdf qwerty zxcv"); *res != 0; res++)
		printf("'%s',", *res);
	return (0);
}
