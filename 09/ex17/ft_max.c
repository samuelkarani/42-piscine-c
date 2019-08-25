/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 22:38:29 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 22:38:31 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_max(int *tab, int length)
{
	int mx = -2147483648;
	for (int i = 0; i < length; i++)
		if (tab[i] > mx)
			mx = tab[i];
	return mx;
}

#include <stdio.h>
int main(int argc, char const *argv[])
{
	int arr[] = {3, 1, 4, 2};
	printf("%d\n", ft_max(arr, 4));
	return 0;
}
