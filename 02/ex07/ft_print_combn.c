/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 00:51:28 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/24 00:57:07 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char* ft_itoa(int val, int base){
	
	static char buf[32] = {0};
	
	int i = 30;
	
	for(; val && i ; --i, val /= base)
	
		buf[i] = "0123456789abcdef"[val % base];
	
	return &buf[i+1];
	
}

int		power(int x, int y)
{
    if (y == 0)
        return 1;
    return (x * power(x, y - 1));
}

int		all_increasing(int n, int max_size)
{
	int i;
	char snum[max_size];

	snum = ft_itoa(n, snum);
	i = max_size - 1;
	while (i >= 0 && max_size > 1)
	{
		if (snum[i-1] > snum[i])
		{
			return 0;
		}
		i--;
	}
	return 1;
}

void	ft_print_combn(int n)
{
	int i;
	int max;

	i = 0;
	max = power(10, n);
	while (i < max)
	{
		if (all_increasing(i, n))
		{
			printf('%c, ', i + 48);
		}
		i++;
	}
}

int		main(void)
{
	int i;

	i = 1;
	while (i < 10)
	{
		ft_print_combn(i);
		i++;
	}
}
