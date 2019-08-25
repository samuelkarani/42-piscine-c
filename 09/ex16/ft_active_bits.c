/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 22:38:18 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 22:38:22 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int ft_active_bits(int value)
{
    int n = 0;
    while (value)
    {
        value &= (value - 1);
		n++;
    }
    return n;
}

#include <stdio.h>
int main(int argc, char const *argv[])
{
	printf("%d\n", ft_active_bits(7));
	printf("%d\n", ft_active_bits(0));
	printf("%d\n", ft_active_bits(1));
	printf("%d\n", ft_active_bits(15));
	printf("%d\n", ft_active_bits(1024));
	printf("%d\n", ft_active_bits(1023));
	return 0;
}
