/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 21:52:37 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/28 23:24:15 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_putchar(char c);

unsigned int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int		ft_repeated(char *s)
{
	int				p;
	unsigned int	i;
	unsigned int	j;

	p = -1;
	i = 0;
	while (i < ft_strlen(s))
	{
		j = i + 1;
		while (j < ft_strlen(s))
		{
			if (s[i] == s[j])
			{
				p = i;
				break ;
			}
			j++;
		}
		if (p != -1)
			break ;
		i++;
	}
	return (p);
}

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

int		is_valid(char *base)
{
	char *neg;
	char *pos;

	neg = "-";
	pos = "+";
	if (!*base || *base == '1')
		return (0);
	if (ft_strstr(base, pos) || ft_strstr(base, neg))
		return (0);
	if (ft_repeated(base) == -1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		j;
	char	*ans;
	int		l;

	i = 11;
	ans = "000000000000";
	j = 0;
	l = ft_strlen(base);
	if (is_valid(base))
	{
		if (*base == '-')
		{
			ans[j] = '-';
			j++;
			base++;
		}
		while (nbr > 0)
		{
			ans[i] = base[nbr % l];
			nbr /= l;
			i--;
		}
		printf("%s", ans);
	}
}
