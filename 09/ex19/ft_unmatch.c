/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 23:02:25 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 23:05:48 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_unmatch(int *tab, int length)
{
	int n = 0;
	for (int i = 0; i < length; i++)
		n ^= tab[i];
	return n;
}

#include <stdio.h>
int main()
{
	int arr1[] = {1, 1, 2, 3, 4, 3, 4};
	int arr2[] = {1, 1, 2, 4, 3, 4, 2, 3, 4};
	printf("%d\n", ft_unmatch(arr1, 7));
	printf("%d\n", ft_unmatch(arr2, 9));
}