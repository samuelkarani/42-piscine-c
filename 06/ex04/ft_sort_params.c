/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:39:28 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/30 00:23:46 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	swap(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int		main(int argc, char *argv[])
{
	int it;

	it = 1;
	while (it < argc - 1)
	{
		if (ft_strcmp(argv[it], argv[it + 1]) > 0)
		{
			swap(&argv[it], &argv[it + 1]);
			it = 1;
		}
		else
			it++;
	}
	it = 1;
	while (it < argc)
	{
		ft_putstr(argv[it]);
		ft_putchar('\n');
		it++;
	}
	return (0);
}
