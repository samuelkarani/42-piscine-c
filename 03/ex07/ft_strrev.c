/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:12:41 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/24 23:40:46 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		h_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strrev(char *str)
{
	int		l;
	int 	temp;
    char	reversed[l];
    int		i;

    l = h_strlen(str);
	i = 0;
    while (i < l)
    {
		temp = str[i];
		str[i] = str[l - i - 1];
		str[l - i - 1] = temp;
		i++;
    }
	return (str);
}
