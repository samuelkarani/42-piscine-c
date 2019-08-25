/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:56:26 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 18:17:18 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_words_tables(char **tab)
{
	for (size_t i = 0; tab[i]; i++)
	{
		for (size_t j = 0; tab[i][j]; j++)
			write(1, &tab[i][j], 1);
		write(1, "\n", 1);
	}
}

int main(int ac, char **av)
{
	if (ac > 1)
		ft_print_words_tables(av + 1);
}
