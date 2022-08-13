/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylassiry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 09:03:18 by ylassiry          #+#    #+#             */
/*   Updated: 2022/08/10 09:05:45 by ylassiry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_min(int x, int y, int z)
{
	int	min;

	if (x < y)
		min = x;
	else
		min = y;
	if (z < min)
		return (z);
	return (min);
}

int	helper(int row, int col, int max_row, int max_col)
{
	int	down;
	int	right;
	int	diag;

	if (row >= max_row || col >= max_col)
		return (0);
	if (g_cache[row][col] == -1)
	{
		down = helper(row + 1, col, max_row, max_col);
		right = helper(row, col + 1, max_row, max_col);
		diag = helper(row + 1, col + 1, max_row, max_col);
		g_cache[row][col] = 0;
		if (g_matrix[row][col] == g_first_line[ft_strlen(g_first_line) - 3])
			g_cache[row][col] = 1 + ft_min(down, right, diag);
	}
	return (g_cache[row][col]);
}

int	maximal_square(int matrix_size, int matrix_col_size)
{
	int	i;
	int	j;

	g_cache = malloc(sizeof(g_cache) * matrix_size);
	i = 0;
	while (i < matrix_size)
	{
		g_cache[i] = malloc(sizeof(int) * matrix_col_size);
		j = 0;
		while (j < matrix_col_size)
		{
			g_cache[i][j] = -1;
			j++;
		}
		i++;
	}
	return (helper(0, 0, matrix_size, matrix_col_size));
}
