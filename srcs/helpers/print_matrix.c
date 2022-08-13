/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylassiry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 09:49:28 by ylassiry          #+#    #+#             */
/*   Updated: 2022/08/10 09:49:31 by ylassiry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	get_max_square_index(int *max_row, int *max_col, int *max, int rows)
{
	int	cols;
	int	i;
	int	j;

	cols = ft_strlen(g_matrix[0]);
	maximal_square(rows, cols);
	*max = g_cache[0][0];
	*max_row = 0;
	*max_col = 0;
	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
		{
			if (*max < g_cache[i][j])
			{
				*max_row = i;
				*max_col = j;
				*max = g_cache[i][j];
			}
		}
	}
}

void	fill_square(int max_row, int max_col, int max)
{
	int		i;
	int		j;
	char	square_shape;

	square_shape = g_first_line[ft_strlen(g_first_line) - 1];
	i = max_row;
	while (i < max_row + max)
	{
		j = max_col;
		while (j < max_col + max)
		{
			g_matrix[i][j] = square_shape;
			j++;
		}
		i++;
	}
}

void	print_matrix(void)
{
	int	max_row;
	int	max_col;
	int	max;
	int	i;
	int	rows;

	rows = count_lines(g_first_line);
	get_max_square_index(&max_row, &max_col, &max, rows);
	fill_square(max_row, max_col, max);
	i = 0;
	while (i < rows)
	{
		ft_putstr(g_matrix[i]);
		i++;
		ft_putstr("\n");
	}
	free(g_matrix);
	free(g_cache);
	free(g_first_line);
}
