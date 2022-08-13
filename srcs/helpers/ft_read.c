/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylassiry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:58:15 by ylassiry          #+#    #+#             */
/*   Updated: 2022/08/10 19:58:18 by ylassiry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_read(int fd, int *line_count, int i, int j)
{
	int	initial_length;

	while (read(fd, g_buff, 1))
	{
		if (g_buff[0] != '\n')
			g_line[i++] = g_buff[0];
		else
		{
			g_line[i] = 0;
			i = 0;
			*line_count = *line_count + 1;
			if (!check_lines(g_line, *line_count, &initial_length))
				return (0);
			create_matrix(*line_count, &j);
			if (fd == 0 && count_lines(g_first_line) == *line_count - 1)
				break ;
		}
	}
	return (1);
}
