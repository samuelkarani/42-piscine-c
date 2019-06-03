/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 22:52:18 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/28 18:52:48 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alpha(char c)
{
	return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}

int		is_alpha_numeric(char c)
{
	return (c >= 65 && c <= 90) || (c >= 97 && c <= 122)
	|| (c >= '0' && c <= '9');
}

int		is_upper(char c)
{
	return (c >= 65 && c <= 90);
}

int		is_lower(char c)
{
	return (c >= 97 && c <= 122);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (is_lower(*str))
		*str -= 32;
	i = 1;
	while (str[i] != '\0')
	{
		if (is_alpha(str[i]))
			if (is_alpha_numeric(str[i - 1]) && is_upper(str[i]))
				str[i] += 32;
		if (!is_alpha_numeric(str[i - 1]) && is_lower(str[i]))
			str[i] -= 32;
		i++;
	}
	return (str);
}
