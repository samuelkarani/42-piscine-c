/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:03:10 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/24 22:06:41 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

static int N;

int check_diagonal(int board[N][N], int i, int j)
{
	int a = i, b = j;
	while (--a >= 0 && --b >= 0)
		if (board[a][b])
			return 0;
	a = i, b = j;
	while (--a >= 0 && ++b < N)
		if (board[a][b])
			return 0;
	a = i, b = j;
	while (++a < N && --b >= 0)
		if (board[a][b])
			return 0;
	a = i, b = j;
	while (++a < N && ++b <  N)
		if (board[a][b])
			return 0;
	return 1;
}

void print_result(int board[N])
{
	int i = -1;
	while (++i < N)
		printf("%d", board[i]);
	printf("\n");
}

void print_board(int board[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}
	printf("\n");
}

int helper(int board[N][N], int res[N], int col[N], int i)
{
	if (i == N)
	{
		print_result(res);
		// print_board(board);
		return 1;
	}
	int n = 0;
	for (int j = 0; j < N; j++)
	{
		if (!col[j] && check_diagonal(board, i, j))
		{
			board[i][j] = 1;
			col[j] = 1;
			res[i] = j + 1;
			n += helper(board, res, col, i + 1);
			board[i][j] = 0;
			col[j] = 0;
			res[i] = 0;
		}
	}
	return n;
}

int	ft_eight_queens_puzzle(void)
{
	int board[N][N], i, col[N], res[N];
	i = -1;
	while (++i < N)
		memset(board[i], 0, sizeof(int) * N);
	memset(col, 0, sizeof(int) * N);
	return helper(board, res, col, 0);
}

int main()
{
	N = 8;
	printf("%d\n", ft_eight_queens_puzzle());
}