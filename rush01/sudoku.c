/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:45:30 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/10 11:43:31 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

# define GRN  "\x1B[32m"
# define RED  "\x1B[31m"
# define YEL  "\x1B[33m"
# define RST  "\x1B[0m"

# define N 9

void print_board(int board[N][N], int ii, int jj)
{
    int m, n, o, a, b;
    o = N / 3;
    m = (ii / o + 1) * o;
    n = (jj / o + 1) * o;
    a = m - o, b = n - o;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
            if (i == ii && j == jj)
                printf(RED "%d " RST, board[i][j]);
            else if (ii != -1 && i >= a && i < m && j >= b && j < n)
                printf(YEL "%d " RST, board[i][j]);
            else if (j == jj || i == ii)
                printf(GRN "%d " RST, board[i][j]);
            else
                printf("%d ", board[i][j]);
        }
		printf("\n");
	}
}

int check(int board[N][N], int nums[N], int i, int j)
{
    int m, n, o, A[N], idx;
    o = N / 3;
    m = (i / o + 1) * o;
    n = (j / o + 1) * o;
    memset(A, 0, sizeof(int) * N);
    for (int a = m - o; a < m; a++)
        for (int b = n - o; b < n; b++)
            if (board[a][b])
                A[board[a][b] - 1]++;
    for (int a = 0; a < N; a++)
        if (a != i && board[a][j])
            A[board[a][j] - 1]++;
    for (int a = 0; a < N; a++)
        if (a != j && board[i][a])
            A[board[i][a] - 1]++;
    idx = 0;
    for (int a = 0; a < N; a++)
        if (!A[a])
            nums[idx++] = a + 1;
    return idx;
}

typedef struct  s_node
{
    int i;
    int j;
}               t_node;

t_node  get_next(int board[N][N], int i, int j)
{
    for (; i < N; i++)
    {
        for (; j < N; j++)
        {
            if (!board[i][j])
                return (t_node){i, j};
        }
        j = 0;
    }
    return (t_node){-1, -1};
}

int sudoku(int board[N][N], int i, int j)
{
    int nums[N], m;
    t_node res = get_next(board, i, j);
    if (res.i == -1)
    {
        print_board(board, -1, -1);
        return 1;
    }
    i = res.i, j = res.j;
    m = check(board, nums, i, j);
    for (int k = 0; k < m; k++)
    {
        board[i][j] = nums[k];
        if (sudoku(board, i, j))
            return 1;
        else
            board[i][j] = 0;
    }
    return 0;
}

int main()
{
    int board[9][9] = {
        {9,0,0,0,7,0,0,0,0},
        {2,0,0,0,9,0,0,5,3},
        {0,6,0,0,1,2,4,0,0},
        {8,4,0,0,0,1,0,9,0},
        {5,0,0,0,0,0,8,0,0},
        {0,3,1,0,0,4,0,0,0},
        {0,0,3,7,0,0,6,8,0},
        {0,9,0,0,5,0,7,4,1},
        {4,7,0,0,0,0,0,0,0}
    };
	 int board2[9][9] ={{ 0, 0, 4,   0, 0, 0,   0, 6, 7 },
                        { 3, 0, 0,   4, 7, 0,   0, 0, 5 },
                        { 1, 5, 0,   8, 2, 0,   0, 0, 3 },

                        { 0, 0, 6,   0, 0, 0,   0, 3, 1 },
                        { 8, 0, 2,   1, 0, 5,   6, 0, 4 },
                        { 4, 1, 0,   0, 0, 0,   9, 0, 0 },

                        { 7, 0, 0,   0, 8, 0,   0, 4, 6 },
                        { 6, 0, 0,   0, 1, 2,   0, 0, 0 },
                        { 9, 3, 0,   0, 0, 0,   7, 1, 0 } };
    sudoku(board, 0, 0);
	printf("\n");
    sudoku(board2, 0, 0);
}