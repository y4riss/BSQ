/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylassiry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:26:44 by ylassiry          #+#    #+#             */
/*   Updated: 2022/08/09 22:26:53 by ylassiry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	count_lines(char *line)
{
	int	r;

	r = 0;
	while (*(line + 3))
	{
		r = (r * 10) + (*line - 48);
		line++;
	}
	return (r);
}

int	check_first_line(char *line)
{
	int	s;
	int	i;

	s = ft_strlen(line);
	if (s < 4)
		return (0);
	if (line[0] == '0' && s == 4)
		return (0);
	if ((line[s - 1] == line[s - 2] || line[s - 1] == line[s - 3]
			|| line[s - 2] == line[s - 3]))
		return (0);
	if (line[s - 1] < 32 || line[s - 2] < 32 || line[s - 3] < 32)
		return (0);
	i = 0;
	while (i < s - 3)
	{
		if (!(line[i] >= '0' && line[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	valid_line(char *line, int initial_length)
{
	int	length;
	int	i;
	int	k;

	i = 0;
	length = ft_strlen(line);
	k = ft_strlen(g_first_line);
	if (length != initial_length || length == 0)
		return (0);
	while (line[i])
	{
		if (line[i] != g_first_line[k - 2] && line[i] != g_first_line[k - 3])
			return (0);
		i++;
	}
	return (1);
}

int	check_lines(char *line, int line_count, int *initial_length)
{
	if (line_count == 1)
	{
		if (!check_first_line(line))
			return (0);
		g_first_line = ft_strdup(line);
		return (1);
	}
	if (line_count == 2)
	{
		*initial_length = ft_strlen(line);
		return (valid_line(line,*initial_length));
	}
	else
		return (valid_line(line,*initial_length));
	return (1);
}
