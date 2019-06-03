/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 15:50:03 by smbaabu           #+#    #+#             */
/*   Updated: 2018/08/25 23:40:14 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N 4

int		ft_putchar(char c);

int		print_queens(int board[])
{
	int i;

	i = 0;
	while (i < N)
	{
		ft_putchar(board[i]);
		i++;
	}
	ft_putchar('\n');
	return (1);
}

int		h_abs(int a)
{
	return (a < 0 ? a * -1 : a);
}

int		is_safe(int board[], int r, int c)
{
	int qc;
	int qr;
	int i;

	i = 0;
	while (i < N)
	{
		qr = board[i];
		qc = i + 1;
		if (qr == r || qc == c || h_abs(qr - r) == h_abs(qc - c))
			return (0);
		i++;
	}
	return (1);
}

int		solver(int board[], int r)
{
	int c;

	if (r == N)
		return (print_queens(board));
	c = 0;
	while (c < N)
	{
		if (is_safe(board, r + 1, c + 1))
		{
			board[r] = c;
			if (solver(board, r + 1))
				return (1);
			board[r] = 0;
		}
		c++;
	}
	return (0);
}

void	ft_eight_queens_puzzle_2(void)
{
	int board[N];

	solver(board, 0);
}
