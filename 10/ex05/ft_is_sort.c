/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 15:58:28 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 23:49:47 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f) (int, int))
{
	int i, n;

	i = 0, n = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) <= 0)
			n++;
		i++;
	}
	if (n == i)
		return 1;
	i = 0, n = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) >= 0)
			n++;
		i++;
	}
	if (n == i)
		return 1;
	return 0;
}

int cmp(int a, int b)
{
	if (a < b)
		return -1;
	if (a == b)
		return 0;
	return 1;
}

#include <stdio.h>
int main() {
	int arr1[] = {1, 2, 4, 4, 7};
	int arr2[] = {4, 3, 0, -1, -20};
	int arr3[] = {3, 3, -1, 0, -20};
	printf("%d\n", ft_is_sort(arr1, 5, &cmp));
	printf("%d\n", ft_is_sort(arr2, 5, &cmp));
	printf("%d\n", ft_is_sort(arr3, 5, &cmp));
}
