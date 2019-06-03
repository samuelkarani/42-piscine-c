/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 01:35:01 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/28 17:24:50 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alpha(char c)
{
	return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}

int		h_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int		ft_str_is_alpha(char *str)
{
	int l;
	int i;

	i = 0;
	l = h_strlen(str);
	while (is_alpha(str[i]))
	{
		i++;
	}
	return (l == i ? 1 : 0);
}
