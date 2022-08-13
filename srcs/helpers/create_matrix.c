/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylassiry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:58:02 by ylassiry          #+#    #+#             */
/*   Updated: 2022/08/10 19:58:05 by ylassiry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	create_matrix(int line_count, int *j)
{
	if (line_count == 1)
		g_matrix = malloc(sizeof(char *) * count_lines(g_first_line));
	else
	{
		g_matrix[*j] = ft_strdup(g_line);
		++*j;
	}
}
