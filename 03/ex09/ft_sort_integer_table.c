/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:57:22 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 16:57:23 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_sort_integer_table(int *tab, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (tab[j] > tab[j + 1])
			{
				int tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
		}
	}
}

#include <stdlib.h>
#include <stdio.h>
int main(int ac, char **av)
{
	if (ac > 1)
	{
		int arr[ac - 1];
		for (int i = 1; i < ac; i++)
			arr[i - 1] = atoi(av[i]);
		ft_sort_integer_table(arr, ac - 1);
		for (int i = 0; i < ac - 1; i++)
		{
			printf("%d ", arr[i]);
		}
	}
}